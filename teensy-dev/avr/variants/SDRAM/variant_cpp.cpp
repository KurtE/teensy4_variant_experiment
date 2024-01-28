/* Teensyduino Core Library
 * http://www.pjrc.com/teensy/
 * Copyright (c) 2018 PJRC.COM, LLC.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * 1. The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * 2. If the Software is incorporated into a build system that allows
 * selection among a list of target devices, then similar target
 * devices manufactured by PJRC.COM must be included in the list of
 * target devices and selectable in the same manner.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "HardwareSerial.h"
#include "core_pins.h"
#include "Arduino.h"

//-----------------------------------------------------------------------------
// First override the XBAR Table
//-----------------------------------------------------------------------------
extern const pin_to_xbar_info_t PROGMEM pin_to_xbar_info[] = {
	{0,  17, 1, &IOMUXC_XBAR1_IN17_SELECT_INPUT, 0x1},
	{1,  16, 1, nullptr, 0},
	{2,   6, 3, &IOMUXC_XBAR1_IN06_SELECT_INPUT, 0x0},
	{3,   7, 3, &IOMUXC_XBAR1_IN07_SELECT_INPUT, 0x0},
	{4,   8, 3, &IOMUXC_XBAR1_IN08_SELECT_INPUT, 0x0},
	{5,  17, 3, &IOMUXC_XBAR1_IN17_SELECT_INPUT, 0x0},
	{7,  15, 1, nullptr, 0 },
	{8,  14, 1, nullptr, 0},
	{30, 23, 1, &IOMUXC_XBAR1_IN23_SELECT_INPUT, 0x0},
	{31, 22, 1, &IOMUXC_XBAR1_IN22_SELECT_INPUT, 0x0},
	{32, 10, 1, nullptr, 0},
	{33,  9, 3, &IOMUXC_XBAR1_IN09_SELECT_INPUT, 0x0},
	{34,  7, 3, &IOMUXC_XBAR1_IN07_SELECT_INPUT, 0x1},
	{35,  6, 3, &IOMUXC_XBAR1_IN06_SELECT_INPUT, 0x1},
	{36,  5, 3, &IOMUXC_XBAR1_IN05_SELECT_INPUT, 0x1},
	{37,  4, 3, &IOMUXC_XBAR1_IN04_SELECT_INPUT, 0x1},
	{38,  8, 3, &IOMUXC_XBAR1_IN08_SELECT_INPUT, 0x1},
	{39,  9, 3, &IOMUXC_XBAR1_IN09_SELECT_INPUT, 0x1},
	// Added ones here
	{46,  10, 1, nullptr, 0x0},
	{47,  12, 1, nullptr, 0x0},
	{48,  13, 1, nullptr, 0x0},
	{49,  16, 1, nullptr, 0x0},
	{50,  17, 1, nullptr, 0x0},
	{63,  11, 1, nullptr, 0x0},

};

extern const uint8_t PROGMEM count_pin_to_xbar_info  = sizeof(pin_to_xbar_info)/sizeof(pin_to_xbar_info[0]);

//-----------------------------------------------------------------------------
// Next FlexIO - requires updated library
//-----------------------------------------------------------------------------
// SO far can not include library, so duplicate structure here:
typedef struct {
	const uint8_t  io_pin;
	const uint8_t  flex_pin;
	const uint8_t  io_pin_mux;
} FLEXIO_t4_Pins_t;

extern "C" {
	extern const FLEXIO_t4_Pins_t flexio_t4_pins_flexio1[];
	extern const FLEXIO_t4_Pins_t flexio_t4_pins_flexio2[];
	extern const FLEXIO_t4_Pins_t flexio_t4_pins_flexio3[];

	extern const uint8_t flexio_t4_pins_cnt_flexio1;
	extern const uint8_t flexio_t4_pins_cnt_flexio2;
	extern const uint8_t flexio_t4_pins_cnt_flexio3;
}


extern const FLEXIO_t4_Pins_t flexio_t4_pins_flexio1[] = {
	{2, 4, 0x14}, {3, 5, 0x14}, {4, 6, 0x14}, {5, 8, 0x14}, {33, 7, 0x14}};
extern const uint8_t flexio_t4_pins_cnt_flexio1 = sizeof(flexio_t4_pins_flexio1) / sizeof(flexio_t4_pins_flexio1[0]);

extern const FLEXIO_t4_Pins_t flexio_t4_pins_flexio2[] = {
	{6, 10, 0x14}, {7, 17, 0x14}, {8, 16, 0x14}, {9, 11, 0x14}, {10, 0, 0x14}, {11, 2, 0x14}, {12, 1, 0x14}, {13, 3, 0x14}, 
	{32, 12, 0x14}, {40, 4, 0x14}, {41, 5, 0x14}, {42, 6, 0x14}, {43, 7, 0x14}, {44, 8, 0x14}, {45, 9, 0x14},
	// added
	{46, 12, 0x14}, {47, 14, 0x14}, {48, 15, 0x14}, {63, 13, 0x14},
	{49, 18, 0x14}, {50, 19, 0x14}, {51, 20, 0x14}, {52, 21, 0x14}, {53, 22, 0x14}, {54, 23, 0x14}, {55, 24, 0x14}, {56, 25, 0x14}, 
	{57, 26, 0x14}, {58, 27, 0x14}, {59, 28, 0x14}, {60, 29, 0x14}, {61, 30, 0x14}, {62, 31, 0x14}
};
extern const uint8_t flexio_t4_pins_cnt_flexio2 = sizeof(flexio_t4_pins_flexio2) / sizeof(flexio_t4_pins_flexio2[0]);

extern const FLEXIO_t4_Pins_t flexio_t4_pins_flexio3[]  = {

	{7, 17, 0x19}, {8, 16, 0x19}, {14, 2, 0x19}, {15, 3, 0x19}, {16, 7, 0x19}, {17, 6, 0x19}, {18, 1, 0x19}, {19, 0, 0x19}, {20, 10, 0x19},
	{21, 11, 0x19}, {22, 8, 0x19}, {23, 9, 0x19}, {26, 14, 0x19}, {27, 15, 0x19},
	// added
	{49, 18, 0x19}, {50, 19, 0x19}, {51, 20, 0x19}, {52, 21, 0x19}, {53, 22, 0x19}, {54, 23, 0x19}, {55, 24, 0x19}, {56, 25, 0x19}, 
	{57, 26, 0x19}, {58, 27, 0x19}, {59, 28, 0x19}, {60, 29, 0x19}, {61, 30, 0x19}, {62, 31, 0x19}

};
extern const uint8_t flexio_t4_pins_cnt_flexio3 = sizeof(flexio_t4_pins_flexio3) / sizeof(flexio_t4_pins_flexio3[0]);

