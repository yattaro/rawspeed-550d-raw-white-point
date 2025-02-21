/*
    RawSpeed - RAW file decoder.

    Copyright (C) 2009-2014 Klaus Post
    Copyright (C) 2017 Axel Waggershauser
    Copyright (C) 2023 Roman Lebedev

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
#include "io/BitPumpMSB32.h"
#include "io/Buffer.h"
#include "io/ByteStream.h"
#include <cstdint>

namespace rawspeed {

class HasselbladDecompressor final {
public:
  struct PerComponentRecipe {
    const PrefixCodeDecoder<>& ht;
    const uint16_t initPred;
  };

private:
  const RawImage mRaw;

  const PerComponentRecipe& rec;

  const ByteStream input;

  static int getBits(BitPumpMSB32& bs, int len);

public:
  HasselbladDecompressor(RawImage mRaw, const PerComponentRecipe& rec,
                         ByteStream input);

  [[nodiscard]] ByteStream::size_type decompress();
};

} // namespace rawspeed
