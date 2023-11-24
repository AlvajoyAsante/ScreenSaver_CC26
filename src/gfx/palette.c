unsigned char palette[512] =
{
    0x00, 0x00, /*   0: rgb(  0,   0,   0) */
    0x10, 0x7c, /*   1: rgb(255,   0, 132) */
    0x15, 0x00, /*   2: rgb(  0,   0, 173) */
    0x1f, 0x00, /*   3: rgb(  0,   0, 255) */
    0x56, 0x01, /*   4: rgb(  0,  81, 181) */
    0xdf, 0x01, /*   5: rgb(  0, 113, 255) */
    0x40, 0x03, /*   6: rgb(  0, 210,   0) */
    0x87, 0x03, /*   7: rgb(  0, 227,  58) */
    0xe0, 0x03, /*   8: rgb(  0, 251,   0) */
    0xff, 0x83, /*   9: rgb(  0, 255, 255) */
    0x43, 0x04, /*  10: rgb(  8,  16,  25) */
    0x43, 0x84, /*  11: rgb(  8,  20,  25) */
    0x64, 0x04, /*  12: rgb(  8,  24,  33) */
    0x64, 0x84, /*  13: rgb(  8,  28,  33) */
    0x85, 0x04, /*  14: rgb(  8,  32,  41) */
    0x85, 0x84, /*  15: rgb(  8,  36,  41) */
    0x86, 0x84, /*  16: rgb(  8,  36,  49) */
    0xa6, 0x04, /*  17: rgb(  8,  40,  49) */
    0xa7, 0x88, /*  18: rgb( 16,  45,  58) */
    0xc8, 0x08, /*  19: rgb( 16,  49,  66) */
    0xc8, 0x88, /*  20: rgb( 16,  53,  66) */
    0xe9, 0x08, /*  21: rgb( 16,  57,  74) */
    0xea, 0x88, /*  22: rgb( 16,  61,  82) */
    0x0b, 0x09, /*  23: rgb( 16,  65,  90) */
    0x0b, 0x89, /*  24: rgb( 16,  69,  90) */
    0x18, 0x0c, /*  25: rgb( 25,   0, 197) */
    0x0b, 0x8d, /*  26: rgb( 25,  69,  90) */
    0x2c, 0x0d, /*  27: rgb( 25,  73,  99) */
    0x2d, 0x8d, /*  28: rgb( 25,  77, 107) */
    0x4d, 0x0d, /*  29: rgb( 25,  81, 107) */
    0x4e, 0x8d, /*  30: rgb( 25,  85, 115) */
    0x6f, 0x0d, /*  31: rgb( 25,  89, 123) */
    0x1c, 0x0e, /*  32: rgb( 25, 130, 230) */
    0x83, 0x10, /*  33: rgb( 33,  32,  25) */
    0x84, 0x10, /*  34: rgb( 33,  32,  33) */
    0x84, 0x90, /*  35: rgb( 33,  36,  33) */
    0xc5, 0x10, /*  36: rgb( 33,  49,  41) */
    0xe7, 0x10, /*  37: rgb( 33,  57,  58) */
    0x09, 0x11, /*  38: rgb( 33,  65,  74) */
    0x2c, 0x91, /*  39: rgb( 33,  77,  99) */
    0x4d, 0x91, /*  40: rgb( 33,  85, 107) */
    0x4e, 0x91, /*  41: rgb( 33,  85, 115) */
    0x6f, 0x11, /*  42: rgb( 33,  89, 123) */
    0x6f, 0x91, /*  43: rgb( 33,  93, 123) */
    0x70, 0x91, /*  44: rgb( 33,  93, 132) */
    0x90, 0x11, /*  45: rgb( 33,  97, 132) */
    0x91, 0x91, /*  46: rgb( 33, 101, 140) */
    0xb2, 0x11, /*  47: rgb( 33, 105, 148) */
    0xb2, 0x91, /*  48: rgb( 33, 109, 148) */
    0xd3, 0x11, /*  49: rgb( 33, 113, 156) */
    0x2a, 0x95, /*  50: rgb( 41,  77,  82) */
    0x90, 0x15, /*  51: rgb( 41,  97, 132) */
    0x90, 0x95, /*  52: rgb( 41, 101, 132) */
    0xd3, 0x95, /*  53: rgb( 41, 117, 156) */
    0xc4, 0x18, /*  54: rgb( 49,  49,  33) */
    0xc6, 0x18, /*  55: rgb( 49,  49,  49) */
    0x05, 0x19, /*  56: rgb( 49,  65,  41) */
    0x29, 0x19, /*  57: rgb( 49,  73,  74) */
    0x6d, 0x99, /*  58: rgb( 49,  93, 107) */
    0xf4, 0x99, /*  59: rgb( 49, 125, 165) */
    0xe5, 0x1c, /*  60: rgb( 58,  57,  41) */
    0x06, 0x9d, /*  61: rgb( 58,  69,  49) */
    0x25, 0x1d, /*  62: rgb( 58,  73,  41) */
    0xaf, 0x9d, /*  63: rgb( 58, 109, 123) */
    0x14, 0x1e, /*  64: rgb( 58, 130, 165) */
    0xe6, 0xa0, /*  65: rgb( 66,  61,  49) */
    0x08, 0x21, /*  66: rgb( 66,  65,  66) */
    0x08, 0xa1, /*  67: rgb( 66,  69,  66) */
    0x26, 0xa1, /*  68: rgb( 66,  77,  49) */
    0x46, 0xa1, /*  69: rgb( 66,  85,  49) */
    0x4a, 0xa1, /*  70: rgb( 66,  85,  82) */
    0x6c, 0xa1, /*  71: rgb( 66,  93,  99) */
    0x90, 0x21, /*  72: rgb( 66,  97, 132) */
    0x8d, 0xa1, /*  73: rgb( 66, 101, 107) */
    0x35, 0x22, /*  74: rgb( 66, 138, 173) */
    0x28, 0x24, /*  75: rgb( 74,   8,  66) */
    0xa6, 0x24, /*  76: rgb( 74,  40,  49) */
    0x06, 0x25, /*  77: rgb( 74,  65,  49) */
    0x0d, 0x25, /*  78: rgb( 74,  65, 107) */
    0x27, 0x25, /*  79: rgb( 74,  73,  58) */
    0x2a, 0x25, /*  80: rgb( 74,  73,  82) */
    0x87, 0x25, /*  81: rgb( 74,  97,  58) */
    0xcd, 0xa5, /*  82: rgb( 74, 117, 107) */
    0xf1, 0x25, /*  83: rgb( 74, 121, 140) */
    0x7f, 0x26, /*  84: rgb( 74, 154, 255) */
    0xe9, 0x28, /*  85: rgb( 82,  57,  74) */
    0x27, 0xa9, /*  86: rgb( 82,  77,  58) */
    0x4a, 0xa9, /*  87: rgb( 82,  85,  82) */
    0x6a, 0x29, /*  88: rgb( 82,  89,  82) */
    0x87, 0x29, /*  89: rgb( 82,  97,  58) */
    0xa7, 0xa9, /*  90: rgb( 82, 109,  58) */
    0x04, 0x2a, /*  91: rgb( 82, 130,  33) */
    0x48, 0xad, /*  92: rgb( 90,  85,  66) */
    0xe8, 0x2d, /*  93: rgb( 90, 121,  66) */
    0x32, 0x2e, /*  94: rgb( 90, 138, 148) */
    0x68, 0xb1, /*  95: rgb( 99,  93,  66) */
    0x8c, 0x31, /*  96: rgb( 99,  97,  99) */
    0x89, 0xb1, /*  97: rgb( 99, 101,  74) */
    0x8c, 0xb1, /*  98: rgb( 99, 101,  99) */
    0xc8, 0x31, /*  99: rgb( 99, 113,  66) */
    0x17, 0x32, /* 100: rgb( 99, 130, 189) */
    0x96, 0x32, /* 101: rgb( 99, 162, 181) */
    0x69, 0xb5, /* 102: rgb(107,  93,  74) */
    0xcd, 0x35, /* 103: rgb(107, 113, 107) */
    0x4a, 0x36, /* 104: rgb(107, 146,  82) */
    0x52, 0xb6, /* 105: rgb(107, 150, 148) */
    0xaa, 0x39, /* 106: rgb(115, 105,  82) */
    0xcb, 0x39, /* 107: rgb(115, 113,  90) */
    0xce, 0xb9, /* 108: rgb(115, 117, 115) */
    0xea, 0x39, /* 109: rgb(115, 121,  82) */
    0xea, 0xb9, /* 110: rgb(115, 125,  82) */
    0x0a, 0x3a, /* 111: rgb(115, 130,  82) */
    0x0e, 0x3a, /* 112: rgb(115, 130, 115) */
    0x2a, 0x3a, /* 113: rgb(115, 138,  82) */
    0x05, 0x3b, /* 114: rgb(115, 194,  41) */
    0x3c, 0x3e, /* 115: rgb(123, 138, 230) */
    0x6a, 0x3e, /* 116: rgb(123, 154,  82) */
    0x8a, 0xbe, /* 117: rgb(123, 166,  82) */
    0xbd, 0x3e, /* 118: rgb(123, 170, 239) */
    0x19, 0xbf, /* 119: rgb(123, 198, 206) */
    0x3e, 0x3f, /* 120: rgb(123, 202, 247) */
    0xcb, 0x41, /* 121: rgb(132, 113,  90) */
    0x96, 0xc2, /* 122: rgb(132, 166, 181) */
    0x63, 0xc4, /* 123: rgb(140,  28,  25) */
    0xec, 0xc5, /* 124: rgb(140, 125,  99) */
    0x0c, 0x46, /* 125: rgb(140, 130,  99) */
    0x2c, 0xc6, /* 126: rgb(140, 142,  99) */
    0x30, 0xc6, /* 127: rgb(140, 142, 132) */
    0x8c, 0x46, /* 128: rgb(140, 162,  99) */
    0xb2, 0x46, /* 129: rgb(140, 170, 148) */
    0xac, 0xc6, /* 130: rgb(140, 174,  99) */
    0x00, 0x48, /* 131: rgb(148,   0,   0) */
    0x84, 0x48, /* 132: rgb(148,  32,  33) */
    0x52, 0x49, /* 133: rgb(148,  81, 148) */
    0x63, 0x49, /* 134: rgb(148,  89,  25) */
    0x0d, 0xca, /* 135: rgb(148, 134, 107) */
    0x40, 0x4a, /* 136: rgb(148, 146,   0) */
    0x4c, 0xca, /* 137: rgb(148, 150,  99) */
    0xec, 0xca, /* 138: rgb(148, 190,  99) */
    0xe0, 0x4d, /* 139: rgb(156, 121,   0) */
    0x73, 0xce, /* 140: rgb(156, 158, 156) */
    0xad, 0x4e, /* 141: rgb(156, 170, 107) */
    0xab, 0x4f, /* 142: rgb(156, 235,  90) */
    0xf3, 0x4f, /* 143: rgb(156, 251, 156) */
    0xc6, 0xd0, /* 144: rgb(165,  53,  49) */
    0xe7, 0xd0, /* 145: rgb(165,  61,  58) */
    0x2d, 0xd2, /* 146: rgb(165, 142, 107) */
    0x6d, 0xd2, /* 147: rgb(165, 158, 107) */
    0xd4, 0xd2, /* 148: rgb(165, 182, 165) */
    0x0d, 0xd3, /* 149: rgb(165, 198, 107) */
    0x08, 0xd5, /* 150: rgb(173,  69,  66) */
    0x29, 0xd5, /* 151: rgb(173,  77,  74) */
    0x4e, 0xd6, /* 152: rgb(173, 150, 115) */
    0x71, 0xd6, /* 153: rgb(173, 158, 140) */
    0x7e, 0xd7, /* 154: rgb(173, 223, 247) */
    0x00, 0x58, /* 155: rgb(181,   0,   0) */
    0x8f, 0x5a, /* 156: rgb(181, 162, 123) */
    0xa6, 0x5a, /* 157: rgb(181, 170,  49) */
    0xb2, 0x5a, /* 158: rgb(181, 170, 148) */
    0xaf, 0xda, /* 159: rgb(181, 174, 123) */
    0xd5, 0x5a, /* 160: rgb(181, 178, 173) */
    0xf0, 0xda, /* 161: rgb(181, 190, 132) */
    0x2f, 0xdb, /* 162: rgb(181, 206, 123) */
    0x00, 0x5c, /* 163: rgb(189,   0,   0) */
    0x80, 0x5c, /* 164: rgb(189,  32,   0) */
    0x29, 0x5d, /* 165: rgb(189,  73,  74) */
    0x5a, 0x5d, /* 166: rgb(189,  81, 214) */
    0x60, 0x5d, /* 167: rgb(189,  89,   0) */
    0x6a, 0x5d, /* 168: rgb(189,  89,  82) */
    0x80, 0x5d, /* 169: rgb(189,  97,   0) */
    0xd7, 0x5d, /* 170: rgb(189, 113, 189) */
    0xe5, 0x5d, /* 171: rgb(189, 121,  41) */
    0xd7, 0xde, /* 172: rgb(189, 182, 189) */
    0xe0, 0x5e, /* 173: rgb(189, 186,   0) */
    0xf0, 0x5e, /* 174: rgb(189, 186, 132) */
    0xf7, 0x5e, /* 175: rgb(189, 186, 189) */
    0xf7, 0xde, /* 176: rgb(189, 190, 189) */
    0xb1, 0x62, /* 177: rgb(197, 170, 140) */
    0xb1, 0xe2, /* 178: rgb(197, 174, 140) */
    0xd2, 0x62, /* 179: rgb(197, 178, 148) */
    0x17, 0x63, /* 180: rgb(197, 194, 189) */
    0x04, 0x64, /* 181: rgb(206,   0,  33) */
    0xa0, 0x64, /* 182: rgb(206,  40,   0) */
    0x8c, 0x65, /* 183: rgb(206,  97,  99) */
    0x51, 0x66, /* 184: rgb(206, 146, 140) */
    0x80, 0x66, /* 185: rgb(206, 162,   0) */
    0xd4, 0xe6, /* 186: rgb(206, 182, 165) */
    0x05, 0x67, /* 187: rgb(206, 194,  41) */
    0x11, 0xe7, /* 188: rgb(206, 198, 140) */
    0x51, 0xe7, /* 189: rgb(206, 215, 140) */
    0x79, 0x67, /* 190: rgb(206, 219, 206) */
    0x07, 0x6a, /* 191: rgb(214, 130,  58) */
    0x4a, 0x6a, /* 192: rgb(214, 146,  82) */
    0xd1, 0x6a, /* 193: rgb(214, 178, 140) */
    0xf4, 0x6a, /* 194: rgb(214, 186, 165) */
    0x36, 0x6b, /* 195: rgb(214, 202, 181) */
    0x92, 0xeb, /* 196: rgb(214, 231, 148) */
    0x08, 0x6c, /* 197: rgb(222,   0,  66) */
    0x04, 0x6e, /* 198: rgb(222, 130,  33) */
    0x10, 0x6e, /* 199: rgb(222, 130, 132) */
    0x88, 0x6e, /* 200: rgb(222, 162,  66) */
    0x90, 0x6e, /* 201: rgb(222, 162, 132) */
    0x94, 0xee, /* 202: rgb(222, 166, 165) */
    0xec, 0xee, /* 203: rgb(222, 190,  99) */
    0xf2, 0xee, /* 204: rgb(222, 190, 148) */
    0xf4, 0xee, /* 205: rgb(222, 190, 165) */
    0x12, 0xef, /* 206: rgb(222, 198, 148) */
    0x36, 0xef, /* 207: rgb(222, 206, 181) */
    0x73, 0x6f, /* 208: rgb(222, 219, 156) */
    0x68, 0xef, /* 209: rgb(222, 223,  66) */
    0x96, 0x6f, /* 210: rgb(222, 227, 181) */
    0xf1, 0xef, /* 211: rgb(222, 255, 140) */
    0x60, 0x70, /* 212: rgb(230,  24,   0) */
    0x29, 0xf1, /* 213: rgb(230,  77,  74) */
    0xcc, 0xf1, /* 214: rgb(230, 117,  99) */
    0x4b, 0x72, /* 215: rgb(230, 146,  90) */
    0xae, 0xf2, /* 216: rgb(230, 174, 115) */
    0xf6, 0x72, /* 217: rgb(230, 186, 181) */
    0x34, 0x73, /* 218: rgb(230, 202, 165) */
    0x48, 0x73, /* 219: rgb(230, 210,  66) */
    0x18, 0xf7, /* 220: rgb(239, 198, 197) */
    0x4e, 0x77, /* 221: rgb(239, 210, 115) */
    0x56, 0x77, /* 222: rgb(239, 210, 181) */
    0x58, 0xf7, /* 223: rgb(239, 215, 197) */
    0x99, 0x77, /* 224: rgb(239, 227, 206) */
    0x94, 0xf7, /* 225: rgb(239, 231, 165) */
    0x9b, 0xf7, /* 226: rgb(239, 231, 222) */
    0xfb, 0xf7, /* 227: rgb(239, 255, 222) */
    0xa4, 0x78, /* 228: rgb(247,  40,  33) */
    0x44, 0x7a, /* 229: rgb(247, 146,  33) */
    0xaf, 0xfa, /* 230: rgb(247, 174, 123) */
    0x27, 0xfb, /* 231: rgb(247, 206,  58) */
    0x31, 0xfb, /* 232: rgb(247, 206, 140) */
    0x40, 0xfb, /* 233: rgb(247, 215,   0) */
    0x50, 0xfb, /* 234: rgb(247, 215, 132) */
    0x75, 0x7b, /* 235: rgb(247, 219, 173) */
    0x97, 0x7b, /* 236: rgb(247, 227, 189) */
    0xc2, 0x7b, /* 237: rgb(247, 243,  16) */
    0xde, 0xfb, /* 238: rgb(247, 247, 247) */
    0x00, 0x7c, /* 239: rgb(255,   0,   0) */
    0x8a, 0x7c, /* 240: rgb(255,  32,  82) */
    0x35, 0x7d, /* 241: rgb(255,  73, 173) */
    0xa0, 0x7d, /* 242: rgb(255, 105,   0) */
    0xe4, 0xfd, /* 243: rgb(255, 125,  33) */
    0xca, 0xfe, /* 244: rgb(255, 182,  82) */
    0xb8, 0x7f, /* 245: rgb(255, 235, 197) */
    0xda, 0x7f, /* 246: rgb(255, 243, 214) */
    0xc9, 0xff, /* 247: rgb(255, 247,  74) */
    0xf2, 0x7f, /* 248: rgb(255, 251, 148) */
    0xf7, 0x7f, /* 249: rgb(255, 251, 189) */
    0xfa, 0x7f, /* 250: rgb(255, 251, 214) */
    0xfb, 0x7f, /* 251: rgb(255, 251, 222) */
    0xfc, 0x7f, /* 252: rgb(255, 251, 230) */
    0xff, 0x7f, /* 253: rgb(255, 251, 255) */
    0xfd, 0xff, /* 254: rgb(255, 255, 239) */
    0xff, 0xff, /* 255: rgb(255, 255, 255) */
};
