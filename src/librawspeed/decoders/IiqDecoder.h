/*
    RawSpeed - RAW file decoder.

    Copyright (C) 2009-2014 Klaus Post
    Copyright (C) 2014 Pedro Côrte-Real

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

#pragma once

#include "common/RawImage.h"
#include "decoders/AbstractTiffDecoder.h"
#include "io/Buffer.h"
#include "tiff/TiffIFD.h"
#include <cstdint>
#include <utility>
#include <vector>

namespace rawspeed {

class Buffer;
class ByteStream;
class CameraMetaData;
struct PhaseOneStrip;

class IiqDecoder final : public AbstractTiffDecoder {
  struct IiqOffset {
    uint32_t n;
    uint32_t offset;

    IiqOffset() = default;
    IiqOffset(uint32_t block, uint32_t offset_) : n(block), offset(offset_) {}
  };

  static std::vector<PhaseOneStrip>
  computeSripes(Buffer raw_data, std::vector<IiqOffset> offsets,
                uint32_t height);

public:
  static bool isAppropriateDecoder(Buffer file);
  static bool isAppropriateDecoder(const TiffRootIFD* rootIFD, Buffer file);

  IiqDecoder(TiffRootIFDOwner&& rootIFD, Buffer file)
      : AbstractTiffDecoder(std::move(rootIFD), file) {}

  RawImage decodeRawInternal() override;
  void checkSupportInternal(const CameraMetaData* meta) override;
  void decodeMetaDataInternal(const CameraMetaData* meta) override;

private:
  [[nodiscard]] int getDecoderVersion() const override { return 0; }
  uint32_t black_level = 0;
  void CorrectPhaseOneC(ByteStream meta_data, uint32_t split_row,
                        uint32_t split_col) const;
  void CorrectQuadrantMultipliersCombined(ByteStream data, uint32_t split_row,
                                          uint32_t split_col) const;
  enum class IiqCorr;
  void PhaseOneFlatField(ByteStream data, IiqCorr corr) const;
  void correctSensorDefects(ByteStream data) const;
  void correctBadColumn(uint16_t col) const;
  void handleBadPixel(uint16_t col, uint16_t row) const;
};

} // namespace rawspeed
