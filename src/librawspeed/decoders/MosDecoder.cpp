/*
    RawSpeed - RAW file decoder.

    Copyright (C) 2009-2014 Klaus Post
    Copyright (C) 2014-2015 Pedro Côrte-Real

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#include "decoders/MosDecoder.h"
#include "adt/Casts.h"
#include "adt/Point.h"
#include "common/Common.h"
#include "common/RawImage.h"
#include "decoders/AbstractTiffDecoder.h"
#include "decoders/IiqDecoder.h"
#include "decoders/RawDecoder.h"
#include "decoders/RawDecoderException.h"
#include "decompressors/UncompressedDecompressor.h"
#include "io/Buffer.h"
#include "io/ByteStream.h"
#include "io/Endianness.h"
#include "parsers/TiffParserException.h"
#include "tiff/TiffEntry.h"
#include "tiff/TiffIFD.h"
#include "tiff/TiffTag.h"
#include <array>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <istream>
#include <memory>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>

namespace rawspeed {

class CameraMetaData;

bool MosDecoder::isAppropriateDecoder(const TiffRootIFD* rootIFD, Buffer file) {
  try {
    const auto id = rootIFD->getID();
    const std::string& make = id.make;

    // This is messy. see https://github.com/darktable-org/rawspeed/issues/116
    // Old Leafs are MOS, new ones are IIQ. Use IIQ's magic to differentiate.
    return make == "Leaf" && !IiqDecoder::isAppropriateDecoder(file);
  } catch (const TiffParserException&) {
    // Last ditch effort to identify Leaf cameras that don't have a Tiff Make
    // set
    const TiffEntry* softwareIFD =
        rootIFD->getEntryRecursive(TiffTag::SOFTWARE);
    if (!softwareIFD)
      return false;

    const std::string software = trimSpaces(softwareIFD->getString());
    return software == "Camera Library";
  }
}

MosDecoder::MosDecoder(TiffRootIFDOwner&& rootIFD, Buffer file)
    : AbstractTiffDecoder(std::move(rootIFD), file) {
  if (mRootIFD->getEntryRecursive(TiffTag::MAKE)) {
    auto id = mRootIFD->getID();
    make = id.make;
    model = id.model;
  } else {
    const TiffEntry* xmp = mRootIFD->getEntryRecursive(TiffTag::XMP);
    if (!xmp)
      ThrowRDE("Couldn't find the XMP");

    assert(xmp != nullptr);
    std::string xmpText = xmp->getString();
    make = getXMPTag(xmpText, "Make");
    model = getXMPTag(xmpText, "Model");
  }
}

std::string MosDecoder::getXMPTag(std::string_view xmp, std::string_view tag) {
  std::string::size_type start = xmp.find("<tiff:" + std::string(tag) + ">");
  std::string::size_type end = xmp.find("</tiff:" + std::string(tag) + ">");
  if (start == std::string::npos || end == std::string::npos || end <= start)
    ThrowRDE("Couldn't find tag '%s' in the XMP", tag.data());
  auto startlen = implicit_cast<int>(tag.size() + 7);
  return std::string(xmp.substr(start + startlen, end - start - startlen));
}

RawImage MosDecoder::decodeRawInternal() {
  uint32_t off = 0;

  const TiffIFD* raw = nullptr;

  if (mRootIFD->hasEntryRecursive(TiffTag::TILEOFFSETS)) {
    raw = mRootIFD->getIFDWithTag(TiffTag::TILEOFFSETS);
    off = raw->getEntry(TiffTag::TILEOFFSETS)->getU32();
  } else {
    raw = mRootIFD->getIFDWithTag(TiffTag::CFAPATTERN);
    off = raw->getEntry(TiffTag::STRIPOFFSETS)->getU32();
  }

  uint32_t width = raw->getEntry(TiffTag::IMAGEWIDTH)->getU32();
  uint32_t height = raw->getEntry(TiffTag::IMAGELENGTH)->getU32();

  // FIXME: could be wrong. max "active pixels" - "80 MP"
  if (width == 0 || height == 0 || width > 10328 || height > 7760)
    ThrowRDE("Unexpected image dimensions found: (%u; %u)", width, height);

  mRaw->dim = iPoint2D(width, height);

  const ByteStream bs(DataBuffer(mFile.getSubView(off), Endianness::little));
  if (bs.getRemainSize() == 0)
    ThrowRDE("Input buffer is empty");

  if (int compression = raw->getEntry(TiffTag::COMPRESSION)->getU32();
      1 == compression) {
    const Endianness endianness =
        getTiffByteOrder(ByteStream(DataBuffer(mFile, Endianness::little)), 0);
    UncompressedDecompressor u(
        bs, mRaw, iRectangle2D({0, 0}, iPoint2D(width, height)), 2 * width, 16,
        endianness == Endianness::big ? BitOrder::MSB : BitOrder::LSB);
    mRaw->createData();
    u.readUncompressedRaw();
  } else if (99 == compression || 7 == compression) {
    ThrowRDE("Leaf LJpeg not yet supported");
    // LJpegPlain l(mFile, mRaw);
    // l.startDecoder(off, mFile.getSize()-off, 0, 0);
  } else
    ThrowRDE("Unsupported compression: %d", compression);

  return mRaw;
}

void MosDecoder::checkSupportInternal(const CameraMetaData* meta) {
  RawDecoder::checkCameraSupported(meta, make, model, "");
}

void MosDecoder::decodeMetaDataInternal(const CameraMetaData* meta) {
  RawDecoder::setMetaData(meta, make, model, "", 0);

  // Fetch the white balance (see dcraw.c parse_mos for more metadata that can
  // be gotten)
  if (mRootIFD->hasEntryRecursive(TiffTag::LEAFMETADATA)) {
    ByteStream bs =
        mRootIFD->getEntryRecursive(TiffTag::LEAFMETADATA)->getData();

    // We need at least a couple of bytes:
    // "NeutObj_neutrals" + 28 bytes binary + 4x uint as strings + 3x space + \0
    const uint32_t minSize = 16 + 28 + 4 + 3 + 1;

    // dcraw does actual parsing, since we just want one field we bruteforce it
    while (bs.getRemainSize() > minSize) {
      if (bs.skipPrefix("NeutObj_neutrals", 16)) {
        bs.skipBytes(28);
        // check for nulltermination of string inside bounds
        if (!memchr(bs.peekData(bs.getRemainSize()), 0, bs.getRemainSize()))
          break;
        std::array<uint32_t, 4> tmp = {{}};
        const std::string tmpString(bs.peekString());
        std::istringstream iss(tmpString);
        iss >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3];
        if (!iss.fail() && tmp[0] > 0 && tmp[1] > 0 && tmp[2] > 0 &&
            tmp[3] > 0) {
          mRaw->metadata.wbCoeffs[0] =
              static_cast<float>(tmp[0]) / implicit_cast<float>(tmp[1]);
          mRaw->metadata.wbCoeffs[1] =
              static_cast<float>(tmp[0]) / implicit_cast<float>(tmp[2]);
          mRaw->metadata.wbCoeffs[2] =
              static_cast<float>(tmp[0]) / implicit_cast<float>(tmp[3]);
        }
        break;
      }
      bs.skipBytes(1);
    }
  }
}

} // namespace rawspeed
