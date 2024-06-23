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
	{7,  15, 1, &IOMUXC_XBAR1_IN15_SELECT_INPUT, 0x1},
	{8,  14, 1, &IOMUXC_XBAR1_IN14_SELECT_INPUT, 0x1},
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
	{68,  24, 1, &IOMUXC_XBAR1_IN24_SELECT_INPUT, 0x1},
	{69,  25, 1, &IOMUXC_XBAR1_IN25_SELECT_INPUT, 0x0},

};

extern const uint8_t PROGMEM count_pin_to_xbar_info  = sizeof(pin_to_xbar_info)/sizeof(pin_to_xbar_info[0]);

//-----------------------------------------------------------------------------
