/*
    RawSpeed - RAW file decoder.

    Copyright (C) 2009-2014 Klaus Post
    Copyright (C) 2014 Pedro Côrte-Real
    Copyright (C) 2018 Roman Lebedev

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

#include "codes/PrefixCodeDecoder.h"
#include "common/RawImage.h"
#include "decompressors/AbstractDecompressor.h"
#include "io/BitPumpJPEG.h"
#include "io/ByteStream.h"
#include <array>
#include <cstdint>

namespace rawspeed {

class CrwDecompressor final : public AbstractDecompressor {
  using crw_hts = std::array<PrefixCodeDecoder<>, 2>;

  RawImage mRaw;
  crw_hts mHuff;
  const bool lowbits;

  ByteStream lowbitInput;
  ByteStream rawInput;

public:
  CrwDecompressor(RawImage img, uint32_t dec_table_, bool lowbits_,
                  ByteStream rawData);

  void decompress();

private:
  static PrefixCodeDecoder<> makeDecoder(const uint8_t* ncpl,
                                         const uint8_t* values);
  static crw_hts initHuffTables(uint32_t table);

  inline static void decodeBlock(std::array<int16_t, 64>* diffBuf,
                                 const crw_hts& mHuff, BitPumpJPEG& bs);
};

} // namespace rawspeed
