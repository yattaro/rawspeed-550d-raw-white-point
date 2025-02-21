/*
    RawSpeed - RAW file decoder.

    Copyright (C) 2017 Roman Lebedev

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

#include <cstdint>
#include <tuple>

namespace rawspeed_test {

template <typename T> struct intPair {
  T first;
  T second;
};

using ushort16Type = intPair<uint16_t>;
using ushort16TType = std::tuple<ushort16Type, bool>;
static const ushort16Type ushort16Values[] = {
    {0x01cd, 0xcd01}, {0x024e, 0x4e02}, {0x0726, 0x2607}, {0x07e3, 0xe307},
    {0x0857, 0x5708}, {0x0a0c, 0x0c0a}, {0x0a3c, 0x3c0a}, {0x0a5a, 0x5a0a},
    {0x0aac, 0xac0a}, {0x0bbb, 0xbb0b}, {0x0cf3, 0xf30c}, {0x0d13, 0x130d},
    {0x0d6f, 0x6f0d}, {0x0d7f, 0x7f0d}, {0x0ed6, 0xd60e}, {0x0f8c, 0x8c0f},
    {0x0f9f, 0x9f0f}, {0x103c, 0x3c10}, {0x10bc, 0xbc10}, {0x11c1, 0xc111},
    {0x1351, 0x5113}, {0x148a, 0x8a14}, {0x15a4, 0xa415}, {0x17f6, 0xf617},
    {0x1886, 0x8618}, {0x19b8, 0xb819}, {0x19e8, 0xe819}, {0x1a5e, 0x5e1a},
    {0x1b26, 0x261b}, {0x1c84, 0x841c}, {0x1c97, 0x971c}, {0x1f0b, 0x0b1f},
    {0x1f69, 0x691f}, {0x1f9c, 0x9c1f}, {0x2170, 0x7021}, {0x21a2, 0xa221},
    {0x230c, 0x0c23}, {0x233f, 0x3f23}, {0x2382, 0x8223}, {0x240e, 0x0e24},
    {0x24ae, 0xae24}, {0x2686, 0x8626}, {0x26cc, 0xcc26}, {0x276a, 0x6a27},
    {0x29f1, 0xf129}, {0x2a34, 0x342a}, {0x2a37, 0x372a}, {0x2b05, 0x052b},
    {0x2b80, 0x802b}, {0x2e02, 0x022e}, {0x2f35, 0x352f}, {0x301e, 0x1e30},
    {0x3081, 0x8130}, {0x3395, 0x9533}, {0x342f, 0x2f34}, {0x34f4, 0xf434},
    {0x3644, 0x4436}, {0x37f7, 0xf737}, {0x38e0, 0xe038}, {0x3bac, 0xac3b},
    {0x3c1d, 0x1d3c}, {0x3c31, 0x313c}, {0x3cef, 0xef3c}, {0x3d99, 0x993d},
    {0x3e11, 0x113e}, {0x3e90, 0x903e}, {0x3e9f, 0x9f3e}, {0x3fe1, 0xe13f},
    {0x40a6, 0xa640}, {0x41b1, 0xb141}, {0x44bc, 0xbc44}, {0x456f, 0x6f45},
    {0x49cb, 0xcb49}, {0x4a07, 0x074a}, {0x4a20, 0x204a}, {0x4b76, 0x764b},
    {0x4d71, 0x714d}, {0x4e50, 0x504e}, {0x4e8d, 0x8d4e}, {0x4eda, 0xda4e},
    {0x5089, 0x8950}, {0x5125, 0x2551}, {0x5177, 0x7751}, {0x5416, 0x1654},
    {0x5438, 0x3854}, {0x5490, 0x9054}, {0x5596, 0x9655}, {0x5599, 0x9955},
    {0x569b, 0x9b56}, {0x57ef, 0xef57}, {0x584c, 0x4c58}, {0x59a0, 0xa059},
    {0x5ba9, 0xa95b}, {0x5be3, 0xe35b}, {0x5c2c, 0x2c5c}, {0x5c83, 0x835c},
    {0x5db2, 0xb25d}, {0x5dc9, 0xc95d}, {0x5e11, 0x115e}, {0x5f65, 0x655f},
    {0x6043, 0x4360}, {0x60d7, 0xd760}, {0x65eb, 0xeb65}, {0x6635, 0x3566},
    {0x666c, 0x6c66}, {0x6735, 0x3567}, {0x6a99, 0x996a}, {0x6b31, 0x316b},
    {0x6bb4, 0xb46b}, {0x6dd4, 0xd46d}, {0x6e40, 0x406e}, {0x7117, 0x1771},
    {0x711d, 0x1d71}, {0x7134, 0x3471}, {0x713c, 0x3c71}, {0x7162, 0x6271},
    {0x7602, 0x0276}, {0x76c5, 0xc576}, {0x78ab, 0xab78}, {0x793f, 0x3f79},
    {0x7945, 0x4579}, {0x7955, 0x5579}, {0x7c1d, 0x1d7c}, {0x7e01, 0x017e},
    {0x7e74, 0x747e}, {0x7f95, 0x957f}, {0x7fa8, 0xa87f}, {0x7fbd, 0xbd7f},
    {0x8123, 0x2381}, {0x816d, 0x6d81}, {0x82b1, 0xb182}, {0x847c, 0x7c84},
    {0x8555, 0x5585}, {0x8626, 0x2686}, {0x8641, 0x4186}, {0x86e9, 0xe986},
    {0x87ec, 0xec87}, {0x8860, 0x6088}, {0x8884, 0x8488}, {0x88ea, 0xea88},
    {0x89bc, 0xbc89}, {0x8a42, 0x428a}, {0x8b55, 0x558b}, {0x8dde, 0xde8d},
    {0x8df1, 0xf18d}, {0x8e2f, 0x2f8e}, {0x8f3b, 0x3b8f}, {0x91ed, 0xed91},
    {0x9265, 0x6592}, {0x9287, 0x8792}, {0x9407, 0x0794}, {0x96c6, 0xc696},
    {0x975d, 0x5d97}, {0x987d, 0x7d98}, {0x9918, 0x1899}, {0x9935, 0x3599},
    {0x9969, 0x6999}, {0x9a4a, 0x4a9a}, {0xa04f, 0x4fa0}, {0xa06a, 0x6aa0},
    {0xa258, 0x58a2}, {0xa357, 0x57a3}, {0xa88a, 0x8aa8}, {0xaa27, 0x27aa},
    {0xac3d, 0x3dac}, {0xada1, 0xa1ad}, {0xaf2c, 0x2caf}, {0xaf6e, 0x6eaf},
    {0xb0a3, 0xa3b0}, {0xb0ec, 0xecb0}, {0xb34a, 0x4ab3}, {0xb4d3, 0xd3b4},
    {0xb632, 0x32b6}, {0xb7ec, 0xecb7}, {0xb91d, 0x1db9}, {0xb9f6, 0xf6b9},
    {0xba9b, 0x9bba}, {0xbab6, 0xb6ba}, {0xbc3c, 0x3cbc}, {0xbdc5, 0xc5bd},
    {0xbff8, 0xf8bf}, {0xc04f, 0x4fc0}, {0xc06b, 0x6bc0}, {0xc189, 0x89c1},
    {0xc2e3, 0xe3c2}, {0xc2fb, 0xfbc2}, {0xc344, 0x44c3}, {0xc380, 0x80c3},
    {0xc3d8, 0xd8c3}, {0xc3fe, 0xfec3}, {0xc431, 0x31c4}, {0xc584, 0x84c5},
    {0xc67e, 0x7ec6}, {0xc683, 0x83c6}, {0xc7a1, 0xa1c7}, {0xc8db, 0xdbc8},
    {0xca27, 0x27ca}, {0xca43, 0x43ca}, {0xcc59, 0x59cc}, {0xcd3a, 0x3acd},
    {0xcee1, 0xe1ce}, {0xd05c, 0x5cd0}, {0xd149, 0x49d1}, {0xd1cd, 0xcdd1},
    {0xd1d6, 0xd6d1}, {0xd280, 0x80d2}, {0xd3fd, 0xfdd3}, {0xd4a3, 0xa3d4},
    {0xd532, 0x32d5}, {0xd61c, 0x1cd6}, {0xd6ff, 0xffd6}, {0xd703, 0x03d7},
    {0xd844, 0x44d8}, {0xd8b7, 0xb7d8}, {0xdd71, 0x71dd}, {0xdeca, 0xcade},
    {0xdfff, 0xffdf}, {0xe069, 0x69e0}, {0xe0b5, 0xb5e0}, {0xe12c, 0x2ce1},
    {0xe1f9, 0xf9e1}, {0xe3da, 0xdae3}, {0xe489, 0x89e4}, {0xe564, 0x64e5},
    {0xe61e, 0x1ee6}, {0xe73a, 0x3ae7}, {0xe7c9, 0xc9e7}, {0xe86a, 0x6ae8},
    {0xe8b4, 0xb4e8}, {0xe8c0, 0xc0e8}, {0xe932, 0x32e9}, {0xe94c, 0x4ce9},
    {0xe985, 0x85e9}, {0xebe0, 0xe0eb}, {0xed8f, 0x8fed}, {0xedea, 0xeaed},
    {0xeee1, 0xe1ee}, {0xf09f, 0x9ff0}, {0xf136, 0x36f1}, {0xf18a, 0x8af1},
    {0xf26d, 0x6df2}, {0xf2b6, 0xb6f2}, {0xf345, 0x45f3}, {0xf34b, 0x4bf3},
    {0xf461, 0x61f4}, {0xf57d, 0x7df5}, {0xf640, 0x40f6}, {0xf6cc, 0xccf6},
    {0xf78b, 0x8bf7}, {0xf7fa, 0xfaf7}, {0xf80a, 0x0af8}, {0xf85a, 0x5af8},
    {0xf9d1, 0xd1f9}, {0xfbbf, 0xbffb}, {0xfd7d, 0x7dfd}, {0xffd4, 0xd4ff},
};

using uint32Type = intPair<uint32_t>;
using uint32TType = std::tuple<uint32Type, bool>;
static const uint32Type uint32Values[] = {
    {0x017c2230, 0x30227c01}, {0x03b26f3a, 0x3a6fb203},
    {0x03e67a66, 0x667ae603}, {0x073bac8d, 0x8dac3b07},
    {0x083548ff, 0xff483508}, {0x086d9c35, 0x359c6d08},
    {0x0a0c7e14, 0x147e0c0a}, {0x0a43bd7f, 0x7fbd430a},
    {0x0a4aa774, 0x74a74a0a}, {0x0a4ca277, 0x77a24c0a},
    {0x0a4f5e46, 0x465e4f0a}, {0x0a56b2bd, 0xbdb2560a},
    {0x0a585294, 0x9452580a}, {0x0a7b114f, 0x4f117b0a},
    {0x0ad63f3f, 0x3f3fd60a}, {0x0afd75ae, 0xae75fd0a},
    {0x0b50fb02, 0x02fb500b}, {0x0bd9cbb9, 0xb9cbd90b},
    {0x0e12d601, 0x01d6120e}, {0x0ed6c038, 0x38c0d60e},
    {0x0f02fa25, 0x25fa020f}, {0x0f80c62f, 0x2fc6800f},
    {0x0f9bbe2a, 0x2abe9b0f}, {0x14b2b4f5, 0xf5b4b214},
    {0x1523f71d, 0x1df72315}, {0x15684694, 0x94466815},
    {0x194b997a, 0x7a994b19}, {0x1af3979e, 0x9e97f31a},
    {0x1bfd7894, 0x9478fd1b}, {0x1c9611ae, 0xae11961c},
    {0x1cd1785f, 0x5f78d11c}, {0x1d3ee80d, 0x0de83e1d},
    {0x1da86c0b, 0x0b6ca81d}, {0x1fae3cb9, 0xb93cae1f},
    {0x20df5efe, 0xfe5edf20}, {0x210997be, 0xbe970921},
    {0x21cd7ae3, 0xe37acd21}, {0x21fb9775, 0x7597fb21},
    {0x22dc2cd5, 0xd52cdc22}, {0x23e9e0a8, 0xa8e0e923},
    {0x24e8669f, 0x9f66e824}, {0x282699c0, 0xc0992628},
    {0x28e94546, 0x4645e928}, {0x2948ef2a, 0x2aef4829},
    {0x2c9f2f17, 0x172f9f2c}, {0x2db88075, 0x7580b82d},
    {0x30042359, 0x59230430}, {0x30a2f205, 0x05f2a230},
    {0x31c7ee2b, 0x2beec731}, {0x329655bf, 0xbf559632},
    {0x33304931, 0x31493033}, {0x34cccad7, 0xd7cacc34},
    {0x357c34b2, 0xb2347c35}, {0x35a818d0, 0xd018a835},
    {0x36f5c876, 0x76c8f536}, {0x37b630b6, 0xb630b637},
    {0x37e5826d, 0x6d82e537}, {0x383af2f6, 0xf6f23a38},
    {0x38471a89, 0x891a4738}, {0x38904dc6, 0xc64d9038},
    {0x389b69ea, 0xea699b38}, {0x390a6483, 0x83640a39},
    {0x390fa869, 0x69a80f39}, {0x39f85247, 0x4752f839},
    {0x3b80e806, 0x06e8803b}, {0x3b92c347, 0x47c3923b},
    {0x3be3cde2, 0xe2cde33b}, {0x3e7dadc2, 0xc2ad7d3e},
    {0x40ac7fd8, 0xd87fac40}, {0x41245c52, 0x525c2441},
    {0x412eb2a8, 0xa8b22e41}, {0x4147f184, 0x84f14741},
    {0x41c70f0b, 0x0b0fc741}, {0x431d514a, 0x4a511d43},
    {0x43a90da7, 0xa70da943}, {0x44096ae3, 0xe36a0944},
    {0x463bd3fc, 0xfcd33b46}, {0x46ab0a92, 0x920aab46},
    {0x4a0e73c2, 0xc2730e4a}, {0x4c3b01ce, 0xce013b4c},
    {0x4d693eb5, 0xb53e694d}, {0x4d7feb28, 0x28eb7f4d},
    {0x4da2bb30, 0x30bba24d}, {0x5092108b, 0x8b109250},
    {0x5096b0c1, 0xc1b09650}, {0x50fe72cd, 0xcd72fe50},
    {0x5224ad0b, 0x0bad2452}, {0x5270dbcb, 0xcbdb7052},
    {0x52e82320, 0x2023e852}, {0x5315201d, 0x1d201553},
    {0x531ae986, 0x86e91a53}, {0x53343945, 0x45393453},
    {0x544b3903, 0x03394b54}, {0x545de210, 0x10e25d54},
    {0x55905815, 0x15589055}, {0x55f983c0, 0xc083f955},
    {0x560bfbad, 0xadfb0b56}, {0x5753da1f, 0x1fda5357},
    {0x58b49a62, 0x629ab458}, {0x59c6f3ca, 0xcaf3c659},
    {0x59ee2efe, 0xfe2eee59}, {0x5bcf7914, 0x1479cf5b},
    {0x5c52d99e, 0x9ed9525c}, {0x5da3f634, 0x34f6a35d},
    {0x5e10e9bc, 0xbce9105e}, {0x60607a86, 0x867a6060},
    {0x612cd5d4, 0xd4d52c61}, {0x62aacaa7, 0xa7caaa62},
    {0x660ccfa8, 0xa8cf0c66}, {0x67f47060, 0x6070f467},
    {0x698b6c45, 0x456c8b69}, {0x6aef7c64, 0x647cef6a},
    {0x6b453152, 0x5231456b}, {0x6b94bb91, 0x91bb946b},
    {0x6bc47aac, 0xac7ac46b}, {0x6bceed6e, 0x6eedce6b},
    {0x6c694728, 0x2847696c}, {0x6d778b40, 0x408b776d},
    {0x6ded96da, 0xda96ed6d}, {0x6f79de03, 0x03de796f},
    {0x71f6a1d0, 0xd0a1f671}, {0x73f9b3c0, 0xc0b3f973},
    {0x74815816, 0x16588174}, {0x753f575d, 0x5d573f75},
    {0x757b6137, 0x37617b75}, {0x77fd0a83, 0x830afd77},
    {0x785b9401, 0x01945b78}, {0x787089a8, 0xa8897078},
    {0x79be0e43, 0x430ebe79}, {0x7b917413, 0x1374917b},
    {0x7bf18b58, 0x588bf17b}, {0x7dcdb302, 0x02b3cd7d},
    {0x82ec5a87, 0x875aec82}, {0x83926954, 0x54699283},
    {0x857a6ad5, 0xd56a7a85}, {0x85a0799d, 0x9d79a085},
    {0x879db719, 0x19b79d87}, {0x8820a4a1, 0xa1a42088},
    {0x88b74b21, 0x214bb788}, {0x8974811d, 0x1d817489},
    {0x8aeb269c, 0x9c26eb8a}, {0x8b42f405, 0x05f4428b},
    {0x8d506ac8, 0xc86a508d}, {0x8dcbfb6a, 0x6afbcb8d},
    {0x8e647efa, 0xfa7e648e}, {0x8ec93b70, 0x703bc98e},
    {0x9118764d, 0x4d761891}, {0x92475d45, 0x455d4792},
    {0x93437ae3, 0xe37a4393}, {0x94b20e98, 0x980eb294},
    {0x954d0227, 0x27024d95}, {0x95dc8a43, 0x438adc95},
    {0x9655fb2a, 0x2afb5596}, {0x96c5b4fa, 0xfab4c596},
    {0x96f487ed, 0xed87f496}, {0x982fe648, 0x48e62f98},
    {0x98930651, 0x51069398}, {0x9ada9dc0, 0xc09dda9a},
    {0x9b8c6319, 0x19638c9b}, {0x9e657cec, 0xec7c659e},
    {0x9ec3dbb1, 0xb1dbc39e}, {0xa3083a73, 0x733a08a3},
    {0xa32487a6, 0xa68724a3}, {0xa40da0bf, 0xbfa00da4},
    {0xa4233c3b, 0x3b3c23a4}, {0xa7646a93, 0x936a64a7},
    {0xa8568730, 0x308756a8}, {0xa9b030f2, 0xf230b0a9},
    {0xa9f660c1, 0xc160f6a9}, {0xab0119a2, 0xa21901ab},
    {0xac91d6c2, 0xc2d691ac}, {0xacb789d7, 0xd789b7ac},
    {0xade3879f, 0x9f87e3ad}, {0xaf086606, 0x066608af},
    {0xb14ef437, 0x37f44eb1}, {0xb1cb60b9, 0xb960cbb1},
    {0xb48fe4a6, 0xa6e48fb4}, {0xb6799f4d, 0x4d9f79b6},
    {0xb71d495a, 0x5a491db7}, {0xb77fe5eb, 0xebe57fb7},
    {0xb79a6598, 0x98659ab7}, {0xb7c37103, 0x0371c3b7},
    {0xb80c8b41, 0x418b0cb8}, {0xb9590146, 0x460159b9},
    {0xb95ecaf9, 0xf9ca5eb9}, {0xbab967d8, 0xd867b9ba},
    {0xbbbf70d9, 0xd970bfbb}, {0xbbcfa479, 0x79a4cfbb},
    {0xbca2cfcc, 0xcccfa2bc}, {0xbcf738f5, 0xf538f7bc},
    {0xbd96a958, 0x58a996bd}, {0xbddab31d, 0x1db3dabd},
    {0xbe132bc8, 0xc82b13be}, {0xbfd7af81, 0x81afd7bf},
    {0xbff480a9, 0xa980f4bf}, {0xc24b8277, 0x77824bc2},
    {0xc3072fb8, 0xb82f07c3}, {0xc4483055, 0x553048c4},
    {0xc5fd7c36, 0x367cfdc5}, {0xc6525163, 0x635152c6},
    {0xc68ce3f9, 0xf9e38cc6}, {0xc6c38770, 0x7087c3c6},
    {0xc7572f65, 0x652f57c7}, {0xc7a4f3b0, 0xb0f3a4c7},
    {0xc7d8ab0f, 0x0fabd8c7}, {0xc8caa3f0, 0xf0a3cac8},
    {0xca132aaf, 0xaf2a13ca}, {0xca693620, 0x203669ca},
    {0xcb26d1f9, 0xf9d126cb}, {0xcc6624e8, 0xe82466cc},
    {0xccf295dd, 0xdd95f2cc}, {0xcd0ed03c, 0x3cd00ecd},
    {0xce6396a5, 0xa59663ce}, {0xcef2dcdc, 0xdcdcf2ce},
    {0xd0666c0f, 0x0f6c66d0}, {0xd0a8ef77, 0x77efa8d0},
    {0xd0e18005, 0x0580e1d0}, {0xd1131227, 0x271213d1},
    {0xd1539fad, 0xad9f53d1}, {0xd2c5e71a, 0x1ae7c5d2},
    {0xd3206255, 0x556220d3}, {0xd4afdc18, 0x18dcafd4},
    {0xd4c15245, 0x4552c1d4}, {0xd5724944, 0x444972d5},
    {0xd89e31b1, 0xb1319ed8}, {0xdad8f6d4, 0xd4f6d8da},
    {0xdb9ce5e0, 0xe0e59cdb}, {0xdd0121ad, 0xad2101dd},
    {0xdd4f57f2, 0xf2574fdd}, {0xde8e0c28, 0x280c8ede},
    {0xe1f064ff, 0xff64f0e1}, {0xe3d26afe, 0xfe6ad2e3},
    {0xe72a08a7, 0xa7082ae7}, {0xe922073f, 0x3f0722e9},
    {0xeb6927a8, 0xa82769eb}, {0xebab7af8, 0xf87aabeb},
    {0xedbda9d8, 0xd8a9bded}, {0xedc2a9bc, 0xbca9c2ed},
    {0xede3584a, 0x4a58e3ed}, {0xf0d51878, 0x7818d5f0},
    {0xf3787c22, 0x227c78f3}, {0xf59dc09f, 0x9fc09df5},
    {0xf60b1c66, 0x661c0bf6}, {0xf610e365, 0x65e310f6},
    {0xf6322ad1, 0xd12a32f6}, {0xf8bda761, 0x61a7bdf8},
    {0xf8e6c9b6, 0xb6c9e6f8}, {0xf9630954, 0x540963f9},
    {0xfac766ba, 0xba66c7fa}, {0xfb1b54ea, 0xea541bfb},
    {0xfcb7e7d9, 0xd9e7b7fc}, {0xfccf71b3, 0xb371cffc},
    {0xfcfcb475, 0x75b4fcfc}, {0xfd77d7ae, 0xaed777fd},
    {0xfdb0eefe, 0xfeeeb0fd}, {0xff3ebb92, 0x92bb3eff},
};

using uint64Type = intPair<uint64_t>;
using uint64TType = std::tuple<uint64Type, bool>;
static const uint64Type uint64Values[] = {
    {0x01a4f185910d9936, 0x36990d9185f1a401},
    {0x030d4fdc9f4011b5, 0xb511409fdc4f0d03},
    {0x034e6547a3d92e80, 0x802ed9a347654e03},
    {0x0394651ebf164685, 0x854616bf1e659403},
    {0x03dd4b0f9fc1ca71, 0x71cac19f0f4bdd03},
    {0x03e9d20de39c5216, 0x16529ce30dd2e903},
    {0x05ca6deedc38af4d, 0x4daf38dcee6dca05},
    {0x061f91b0303314c5, 0xc5143330b0911f06},
    {0x062b940f39764ae7, 0xe74a76390f942b06},
    {0x0799815f9f363603, 0x0336369f5f819907},
    {0x08188686d111449f, 0x9f4411d186861808},
    {0x09d030d4db9ac970, 0x70c99adbd430d009},
    {0x0a827ba534d1d59e, 0x9ed5d134a57b820a},
    {0x0aa45120668481ef, 0xef8184662051a40a},
    {0x0ab4f0f468892ece, 0xce2e8968f4f0b40a},
    {0x0abbbbad7c590d31, 0x310d597cadbbbb0a},
    {0x0abe2e66d9ea4544, 0x4445ead9662ebe0a},
    {0x0ad4d44b5bf40237, 0x3702f45b4bd4d40a},
    {0x0af7e02fcc3e02be, 0xbe023ecc2fe0f70a},
    {0x0e4ff7b88d440627, 0x2706448db8f74f0e},
    {0x0f69c1be2bb832ad, 0xad32b82bbec1690f},
    {0x10016a95e40bf44b, 0x4bf40be4956a0110},
    {0x1039cea9e9a83f0c, 0x0c3fa8e9a9ce3910},
    {0x10beb91781ab0ce9, 0xe90cab8117b9be10},
    {0x112d5dd48c03087f, 0x7f08038cd45d2d11},
    {0x1189e054cb2482d2, 0xd28224cb54e08911},
    {0x11f9318d04b95e6a, 0x6a5eb9048d31f911},
    {0x13509dc1f31494d0, 0xd09414f3c19d5013},
    {0x1459afd791a7e268, 0x68e2a791d7af5914},
    {0x175f335b1017ea4d, 0x4dea17105b335f17},
    {0x17691949526ca9e6, 0xe6a96c5249196917},
    {0x18e124ec2093f320, 0x20f39320ec24e118},
    {0x18ff1397e7e6986c, 0x6c98e6e79713ff18},
    {0x1bbf3f4f5a577c52, 0x527c575a4f3fbf1b},
    {0x1c9e1b8fa60b87e9, 0xe9870ba68f1b9e1c},
    {0x1d7c915583bfbc78, 0x78bcbf8355917c1d},
    {0x1e99cdb0b48d9980, 0x80998db4b0cd991e},
    {0x1ea5c01b8f8b7816, 0x16788b8f1bc0a51e},
    {0x1f6107b4548a673d, 0x3d678a54b407611f},
    {0x20c50d08c7a6684f, 0x4f68a6c7080dc520},
    {0x21392da064c68572, 0x7285c664a02d3921},
    {0x2156f617524a061f, 0x1f064a5217f65621},
    {0x21cb064a80b51ba5, 0xa51bb5804a06cb21},
    {0x22fb2a22d8c2a0b0, 0xb0a0c2d8222afb22},
    {0x24fa5c234ee38825, 0x2588e34e235cfa24},
    {0x2566ca0de3330fad, 0xad0f33e30dca6625},
    {0x262151de31842542, 0x42258431de512126},
    {0x27b8f319a1286b16, 0x166b28a119f3b827},
    {0x2809a2238c21b256, 0x56b2218c23a20928},
    {0x281ffcb764b36097, 0x9760b364b7fc1f28},
    {0x294b39df178cfc8f, 0x8ffc8c17df394b29},
    {0x2ab9ff5fef04c11b, 0x1bc104ef5fffb92a},
    {0x2de95889ee1d7cd9, 0xd97c1dee8958e92d},
    {0x2ec9e30e8b2c9476, 0x76942c8b0ee3c92e},
    {0x30138061f3afea92, 0x92eaaff361801330},
    {0x3027b57c55016086, 0x866001557cb52730},
    {0x3086abfc090e4a6b, 0x6b4a0e09fcab8630},
    {0x309c614a4bac1694, 0x9416ac4b4a619c30},
    {0x3313cb7e5c394f77, 0x774f395c7ecb1333},
    {0x3365363758f35f17, 0x175ff35837366533},
    {0x3399a7d4f02dde1f, 0x1fde2df0d4a79933},
    {0x34951ad3ae5d377e, 0x7e375daed31a9534},
    {0x356aa6f7bdff1fe6, 0xe61fffbdf7a66a35},
    {0x3664912267c29f8e, 0x8e9fc26722916436},
    {0x368411576e9172c7, 0xc772916e57118436},
    {0x36ed7c9df3a3239f, 0x9f23a3f39d7ced36},
    {0x3801a8e5e7ea73f5, 0xf573eae7e5a80138},
    {0x3a8864f4923d3694, 0x94363d92f464883a},
    {0x3ad7fff2f55cdec4, 0xc4de5cf5f2ffd73a},
    {0x3b23fd0271a906c7, 0xc706a97102fd233b},
    {0x3bb711498749f9e3, 0xe3f949874911b73b},
    {0x3bffc35ce2ec236a, 0x6a23ece25cc3ff3b},
    {0x3dcf6b55f48ec31e, 0x1ec38ef4556bcf3d},
    {0x3f31b3fe732ce6d6, 0xd6e62c73feb3313f},
    {0x401f685d6cb0a81a, 0x1aa8b06c5d681f40},
    {0x407c780b3d4649d5, 0xd549463d0b787c40},
    {0x40b1c2c975f040f9, 0xf940f075c9c2b140},
    {0x4133e1fbe7d0aacf, 0xcfaad0e7fbe13341},
    {0x435ebefc10138f3c, 0x3c8f1310fcbe5e43},
    {0x43b6a5d764f3c692, 0x92c6f364d7a5b643},
    {0x445698823bd49d53, 0x539dd43b82985644},
    {0x490bf9bee1d4ade2, 0xe2add4e1bef90b49},
    {0x4e8e78c6df14c97b, 0x7bc914dfc6788e4e},
    {0x4ea96ddb55e85773, 0x7357e855db6da94e},
    {0x4f4acba83590dc66, 0x66dc9035a8cb4a4f},
    {0x4fb7494da864de4c, 0x4cde64a84d49b74f},
    {0x4fce70ded4f83547, 0x4735f8d4de70ce4f},
    {0x516bcc4cada8ef72, 0x72efa8ad4ccc6b51},
    {0x5170b4536616aecf, 0xcfae166653b47051},
    {0x51d4a5524239fa22, 0x22fa394252a5d451},
    {0x534b039d23592020, 0x202059239d034b53},
    {0x54a013b5eff937fe, 0xfe37f9efb513a054},
    {0x564374747f5e9320, 0x20935e7f74744356},
    {0x59f6257c4db99297, 0x9792b94d7c25f659},
    {0x5b12226b7a7923f5, 0xf523797a6b22125b},
    {0x5c645a3be8826925, 0x256982e83b5a645c},
    {0x5e25a5b75eaa8c14, 0x148caa5eb7a5255e},
    {0x5e65baefbaa0be2e, 0x2ebea0baefba655e},
    {0x5e7139ab7cb8941d, 0x1d94b87cab39715e},
    {0x5f58c6ed964a233e, 0x3e234a96edc6585f},
    {0x6191c8a34b25a307, 0x07a3254ba3c89161},
    {0x628653515914237d, 0x7d23145951538662},
    {0x632d4b1c0e4b2bb9, 0xb92b4b0e1c4b2d63},
    {0x635cee4d9e9a6577, 0x77659a9e4dee5c63},
    {0x63622d88676f121e, 0x1e126f67882d6263},
    {0x6488ed06874bd952, 0x52d94b8706ed8864},
    {0x64bc3f236c19adcf, 0xcfad196c233fbc64},
    {0x6530377ab7f2b733, 0x33b7f2b77a373065},
    {0x659f41fc7754836e, 0x6e835477fc419f65},
    {0x65aca81f1137b061, 0x61b037111fa8ac65},
    {0x65f5429ab2cf2abd, 0xbd2acfb29a42f565},
    {0x66b93c7aefba4763, 0x6347baef7a3cb966},
    {0x690d9cb2484801cc, 0xcc014848b29c0d69},
    {0x6943c26898b294e0, 0xe094b29868c24369},
    {0x69e10b813696470b, 0x0b479636810be169},
    {0x6ac87e6ff2526d31, 0x316d52f26f7ec86a},
    {0x70d8c7b4205eaddd, 0xddad5e20b4c7d870},
    {0x717193d6a6f1bc60, 0x60bcf1a6d6937171},
    {0x721312134a9909ca, 0xca09994a13121372},
    {0x725968e20260763c, 0x3c766002e2685972},
    {0x7280418cd340ed7d, 0x7ded40d38c418072},
    {0x7308f61a392c80b5, 0xb5802c391af60873},
    {0x73d47a554321a570, 0x70a52143557ad473},
    {0x744f93d8ff4c5bf6, 0xf65b4cffd8934f74},
    {0x7461a306465e21bc, 0xbc215e4606a36174},
    {0x754d57934c4babc0, 0xc0ab4b4c93574d75},
    {0x762c38e1f7601fc3, 0xc31f60f7e1382c76},
    {0x766d79e3448049b0, 0xb0498044e3796d76},
    {0x76d0892bb81e870e, 0x0e871eb82b89d076},
    {0x76ea263020f68db5, 0xb58df6203026ea76},
    {0x77290b31f3932d28, 0x282d93f3310b2977},
    {0x7879068099a8621d, 0x1d62a89980067978},
    {0x79b7faadcbcd0349, 0x4903cdcbadfab779},
    {0x7aa9ac4bef789b39, 0x399b78ef4baca97a},
    {0x7ae44b36f053ffcd, 0xcdff53f0364be47a},
    {0x7b825441cabc1f0d, 0x0d1fbcca4154827b},
    {0x7bf70945622778dd, 0xdd7827624509f77b},
    {0x7df834b00e227255, 0x5572220eb034f87d},
    {0x7f264136067c698f, 0x8f697c063641267f},
    {0x7fab0c5dc52772f8, 0xf87227c55d0cab7f},
    {0x8346e40cb537d8da, 0xdad837b50ce44683},
    {0x84d903ade1d56a57, 0x576ad5e1ad03d984},
    {0x84ec0390c64b56c1, 0xc1564bc69003ec84},
    {0x86ce4376b9aebbd6, 0xd6bbaeb97643ce86},
    {0x883d8810953e1fa7, 0xa71f3e9510883d88},
    {0x894f7e35bea2b771, 0x71b7a2be357e4f89},
    {0x8975c06401449774, 0x7497440164c07589},
    {0x8a18edc9fb01ff90, 0x90ff01fbc9ed188a},
    {0x8a3dec4bbf6bda6d, 0x6dda6bbf4bec3d8a},
    {0x8bb395de4a1f9b86, 0x869b1f4ade95b38b},
    {0x8c0d60ee5fff18da, 0xda18ff5fee600d8c},
    {0x8c550cf7622902a6, 0xa6022962f70c558c},
    {0x8cc8194debe66f75, 0x756fe6eb4d19c88c},
    {0x8e1b92c42361a254, 0x54a26123c4921b8e},
    {0x8f8de52345ee3d21, 0x213dee4523e58d8f},
    {0x8fbffecb6270af6b, 0x6baf7062cbfebf8f},
    {0x90ea0823b62e880f, 0x0f882eb62308ea90},
    {0x92662f468962f29c, 0x9cf26289462f6692},
    {0x926901d0f7ed1fce, 0xce1fedf7d0016992},
    {0x9315e749fe28a515, 0x15a528fe49e71593},
    {0x939606f40438d640, 0x40d63804f4069693},
    {0x948f46956357b440, 0x40b4576395468f94},
    {0x9536c301a0bdec91, 0x91ecbda001c33695},
    {0x95f0294242e26fad, 0xad6fe2424229f095},
    {0x970313f37c9ce0fa, 0xfae09c7cf3130397},
    {0x989228fc85ded9c1, 0xc1d9de85fc289298},
    {0x998163bda5fcf0ae, 0xaef0fca5bd638199},
    {0x9caac79b53bb8417, 0x1784bb539bc7aa9c},
    {0x9d323942c1beade1, 0xe1adbec14239329d},
    {0x9e7c9a16e12250f3, 0xf35022e1169a7c9e},
    {0x9ebf7dbead11d95c, 0x5cd911adbe7dbf9e},
    {0x9fababe0e0b6c8b0, 0xb0c8b6e0e0abab9f},
    {0x9ff1a9c69196e082, 0x82e09691c6a9f19f},
    {0xa007730aaa876cb7, 0xb76c87aa0a7307a0},
    {0xa2cb459b5ab592f8, 0xf892b55a9b45cba2},
    {0xa2f73480fb85402e, 0x2e4085fb8034f7a2},
    {0xa30d1a453b6b77e5, 0xe5776b3b451a0da3},
    {0xa401d416f27f6784, 0x84677ff216d401a4},
    {0xa429308776e2b253, 0x53b2e276873029a4},
    {0xa4d803a7d07f2b2f, 0x2f2b7fd0a703d8a4},
    {0xa54d53b018fc21c8, 0xc821fc18b0534da5},
    {0xa63d56580a2a72c7, 0xc7722a0a58563da6},
    {0xaad06a347609e497, 0x97e40976346ad0aa},
    {0xab06de977342760d, 0x0d76427397de06ab},
    {0xab3bb77752b628a0, 0xa028b65277b73bab},
    {0xacdf898a38b460a7, 0xa760b4388a89dfac},
    {0xade7cc5f5fe5a0c8, 0xc8a0e55f5fcce7ad},
    {0xb14b0d504edb3f8c, 0x8c3fdb4e500d4bb1},
    {0xb232f7ee5c528f45, 0x458f525ceef732b2},
    {0xb29637a20e7e3f81, 0x813f7e0ea23796b2},
    {0xb38c6e3cdf9ba152, 0x52a19bdf3c6e8cb3},
    {0xb3c4acd895f12b75, 0x752bf195d8acc4b3},
    {0xb45dd693e679afcd, 0xcdaf79e693d65db4},
    {0xb5bd1db701b042b0, 0xb042b001b71dbdb5},
    {0xb7ffb94cbaea0ef6, 0xf60eeaba4cb9ffb7},
    {0xb8ddd9a40f4efbdf, 0xdffb4e0fa4d9ddb8},
    {0xb926e8b8305fec2e, 0x2eec5f30b8e826b9},
    {0xbdcfe40f78253b24, 0x243b25780fe4cfbd},
    {0xbe40f3bcf40bf171, 0x71f10bf4bcf340be},
    {0xbf4e2a36e2d46283, 0x8362d4e2362a4ebf},
    {0xbf9e21521b9b43c2, 0xc2439b1b52219ebf},
    {0xbfcc7ced3487e368, 0x68e38734ed7cccbf},
    {0xc0133885bd296b9a, 0x9a6b29bd853813c0},
    {0xc0197e36b07e7145, 0x45717eb0367e19c0},
    {0xc19ed11ea3cffb6c, 0x6cfbcfa31ed19ec1},
    {0xc1ed5cc50cef774a, 0x4a77ef0cc55cedc1},
    {0xc27efde16bdde140, 0x40e1dd6be1fd7ec2},
    {0xc2aa6b042ee4cded, 0xedcde42e046baac2},
    {0xc2e3eba06e144f23, 0x234f146ea0ebe3c2},
    {0xc30d5d2b67b158c0, 0xc058b1672b5d0dc3},
    {0xc456ce9b1532239a, 0x9a2332159bce56c4},
    {0xc92318a13cc869ed, 0xed69c83ca11823c9},
    {0xcd03c29b85ac0f51, 0x510fac859bc203cd},
    {0xcd4935b4d1f19823, 0x2398f1d1b43549cd},
    {0xcd6a0bcc1ddc68bc, 0xbc68dc1dcc0b6acd},
    {0xd3df6eae2cb71b0f, 0x0f1bb72cae6edfd3},
    {0xd959c11f9b6e1786, 0x86176e9b1fc159d9},
    {0xd9b6129539584836, 0x364858399512b6d9},
    {0xdaead34f9651d94d, 0x4dd951964fd3eada},
    {0xdba30f72797dae40, 0x40ae7d79720fa3db},
    {0xdd26cf916d9ed027, 0x27d09e6d91cf26dd},
    {0xdd49602f244ab833, 0x33b84a242f6049dd},
    {0xdd6f6fc311660caf, 0xaf0c6611c36f6fdd},
    {0xdf71698f5ff67735, 0x3577f65f8f6971df},
    {0xdfef90e381731cc2, 0xc21c7381e390efdf},
    {0xe076fbdea35a9215, 0x15925aa3defb76e0},
    {0xe0c44511b6717d8e, 0x8e7d71b61145c4e0},
    {0xe14f9d6f913cb3d9, 0xd9b33c916f9d4fe1},
    {0xe39f9f95fd7e0707, 0x07077efd959f9fe3},
    {0xe45f2c9e27dc3a11, 0x113adc279e2c5fe4},
    {0xe55bae3a898e9e19, 0x199e8e893aae5be5},
    {0xe6cdf556fca755e8, 0xe855a7fc56f5cde6},
    {0xe6dd5a9baa49d3aa, 0xaad349aa9b5adde6},
    {0xe98fe0160a8ce894, 0x94e88c0a16e08fe9},
    {0xe9dd4fb7fd255204, 0x045225fdb74fdde9},
    {0xeaf1abf8bb2fa6c3, 0xc3a62fbbf8abf1ea},
    {0xebab04ef72681416, 0x16146872ef04abeb},
    {0xebdcbbd249fe49ed, 0xed49fe49d2bbdceb},
    {0xecac354fc5677c11, 0x117c67c54f35acec},
    {0xee76789b082ef12c, 0x2cf12e089b7876ee},
    {0xeebc2d1760e11cb6, 0xb61ce160172dbcee},
    {0xeed834dc595bd60b, 0x0bd65b59dc34d8ee},
    {0xef7b81db37575495, 0x95545737db817bef},
    {0xef9482206a4a5a75, 0x755a4a6a208294ef},
    {0xf11261a29cda20a4, 0xa420da9ca26112f1},
    {0xf1779ea083d21789, 0x8917d283a09e77f1},
    {0xf266952c773053dc, 0xdc5330772c9566f2},
    {0xf41c9d6e916f2551, 0x51256f916e9d1cf4},
    {0xf4a478e553d71be6, 0xe61bd753e578a4f4},
    {0xf4b123aabaa79823, 0x2398a7baaa23b1f4},
    {0xf66b6522552d7936, 0x36792d5522656bf6},
    {0xf89456378f4817a1, 0xa117488f375694f8},
    {0xf97d21e5ea0470ef, 0xef7004eae5217df9},
    {0xf9c8bddb1667ee10, 0x10ee6716dbbdc8f9},
    {0xfb4ee3defb5f3a2b, 0x2b3a5ffbdee34efb},
    {0xfe7280e85ee3f665, 0x65f6e35ee88072fe},
};

} // namespace rawspeed_test
