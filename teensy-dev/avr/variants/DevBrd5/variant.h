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

// Tell most of the system for now you are a MICROMOD
//#define ARDUINO_TEENSY_MICROMOD
#include "smalloc.h"

#ifdef __cplusplus
extern "C" {
#endif

void *sdram_malloc(size_t size);
void sdram_free(void *ptr);
void *sdram_calloc(size_t nmemb, size_t size);
void *sdram_realloc(void *ptr, size_t size);

#ifdef __cplusplus
}
#endif


#define CORE_NUM_TOTAL_PINS    	69
#define CORE_NUM_DIGITAL    	69
#define CORE_NUM_INTERRUPT    	69
#define CORE_NUM_ANALOG        14
#define CORE_NUM_PWM        30

#define CORE_PIN0_BIT        3
#define CORE_PIN1_BIT        2
#define CORE_PIN2_BIT        4
#define CORE_PIN3_BIT        5
#define CORE_PIN4_BIT        6
#define CORE_PIN5_BIT        8
#define CORE_PIN6_BIT        10
#define CORE_PIN7_BIT        17
#define CORE_PIN8_BIT        16
#define CORE_PIN9_BIT        11
#define CORE_PIN10_BIT        0
#define CORE_PIN11_BIT        2
#define CORE_PIN12_BIT        1
#define CORE_PIN13_BIT        3
#define CORE_PIN14_BIT        18
#define CORE_PIN15_BIT        19
#define CORE_PIN16_BIT        23
#define CORE_PIN17_BIT        22
#define CORE_PIN18_BIT        17
#define CORE_PIN19_BIT        16
#define CORE_PIN20_BIT        26
#define CORE_PIN21_BIT        27
#define CORE_PIN22_BIT        24
#define CORE_PIN23_BIT        25
#define CORE_PIN24_BIT        12
#define CORE_PIN25_BIT        13
#define CORE_PIN26_BIT        30
#define CORE_PIN27_BIT        31
#define CORE_PIN28_BIT        18
#define CORE_PIN29_BIT        31
#define CORE_PIN30_BIT        23
#define CORE_PIN31_BIT        22
#define CORE_PIN32_BIT        12
#define CORE_PIN33_BIT        7
#define CORE_PIN34_BIT        15
#define CORE_PIN35_BIT        14
#define CORE_PIN36_BIT        13
#define CORE_PIN37_BIT        12
#define CORE_PIN38_BIT        16
#define CORE_PIN39_BIT        17
#define CORE_PIN40_BIT        4
#define CORE_PIN41_BIT        5
#define CORE_PIN42_BIT        6
#define CORE_PIN43_BIT        7
#define CORE_PIN44_BIT        8
#define CORE_PIN45_BIT        9

#define CORE_PIN0_BITMASK    (1<<(CORE_PIN0_BIT))
#define CORE_PIN1_BITMASK    (1<<(CORE_PIN1_BIT))
#define CORE_PIN2_BITMASK    (1<<(CORE_PIN2_BIT))
#define CORE_PIN3_BITMASK    (1<<(CORE_PIN3_BIT))
#define CORE_PIN4_BITMASK    (1<<(CORE_PIN4_BIT))
#define CORE_PIN5_BITMASK    (1<<(CORE_PIN5_BIT))
#define CORE_PIN6_BITMASK    (1<<(CORE_PIN6_BIT))
#define CORE_PIN7_BITMASK    (1<<(CORE_PIN7_BIT))
#define CORE_PIN8_BITMASK    (1<<(CORE_PIN8_BIT))
#define CORE_PIN9_BITMASK    (1<<(CORE_PIN9_BIT))
#define CORE_PIN10_BITMASK    (1<<(CORE_PIN10_BIT))
#define CORE_PIN11_BITMASK    (1<<(CORE_PIN11_BIT))
#define CORE_PIN12_BITMASK    (1<<(CORE_PIN12_BIT))
#define CORE_PIN13_BITMASK    (1<<(CORE_PIN13_BIT))
#define CORE_PIN14_BITMASK    (1<<(CORE_PIN14_BIT))
#define CORE_PIN15_BITMASK    (1<<(CORE_PIN15_BIT))
#define CORE_PIN16_BITMASK    (1<<(CORE_PIN16_BIT))
#define CORE_PIN17_BITMASK    (1<<(CORE_PIN17_BIT))
#define CORE_PIN18_BITMASK    (1<<(CORE_PIN18_BIT))
#define CORE_PIN19_BITMASK    (1<<(CORE_PIN19_BIT))
#define CORE_PIN20_BITMASK    (1<<(CORE_PIN20_BIT))
#define CORE_PIN21_BITMASK    (1<<(CORE_PIN21_BIT))
#define CORE_PIN22_BITMASK    (1<<(CORE_PIN22_BIT))
#define CORE_PIN23_BITMASK    (1<<(CORE_PIN23_BIT))
#define CORE_PIN24_BITMASK    (1<<(CORE_PIN24_BIT))
#define CORE_PIN25_BITMASK    (1<<(CORE_PIN25_BIT))
#define CORE_PIN26_BITMASK    (1<<(CORE_PIN26_BIT))
#define CORE_PIN27_BITMASK    (1<<(CORE_PIN27_BIT))
#define CORE_PIN28_BITMASK    (1<<(CORE_PIN28_BIT))
#define CORE_PIN29_BITMASK    (1<<(CORE_PIN29_BIT))
#define CORE_PIN30_BITMASK    (1<<(CORE_PIN30_BIT))
#define CORE_PIN31_BITMASK    (1<<(CORE_PIN31_BIT))
#define CORE_PIN32_BITMASK    (1<<(CORE_PIN32_BIT))
#define CORE_PIN33_BITMASK    (1<<(CORE_PIN33_BIT))
#define CORE_PIN34_BITMASK    (1<<(CORE_PIN34_BIT))
#define CORE_PIN35_BITMASK    (1<<(CORE_PIN35_BIT))
#define CORE_PIN36_BITMASK    (1<<(CORE_PIN36_BIT))
#define CORE_PIN37_BITMASK    (1<<(CORE_PIN37_BIT))
#define CORE_PIN38_BITMASK    (1<<(CORE_PIN38_BIT))
#define CORE_PIN39_BITMASK    (1<<(CORE_PIN39_BIT))
#define CORE_PIN40_BITMASK    (1<<(CORE_PIN40_BIT))
#define CORE_PIN41_BITMASK    (1<<(CORE_PIN41_BIT))
#define CORE_PIN42_BITMASK    (1<<(CORE_PIN42_BIT))
#define CORE_PIN43_BITMASK    (1<<(CORE_PIN43_BIT))
#define CORE_PIN44_BITMASK    (1<<(CORE_PIN44_BIT))
#define CORE_PIN45_BITMASK    (1<<(CORE_PIN45_BIT))


// Fast GPIO
#define CORE_PIN0_PORTREG    GPIO6_DR
#define CORE_PIN1_PORTREG    GPIO6_DR
#define CORE_PIN2_PORTREG    GPIO9_DR
#define CORE_PIN3_PORTREG    GPIO9_DR
#define CORE_PIN4_PORTREG    GPIO9_DR
#define CORE_PIN5_PORTREG    GPIO9_DR
#define CORE_PIN6_PORTREG    GPIO7_DR
#define CORE_PIN7_PORTREG    GPIO7_DR
#define CORE_PIN8_PORTREG    GPIO7_DR
#define CORE_PIN9_PORTREG    GPIO7_DR
#define CORE_PIN10_PORTREG    GPIO7_DR
#define CORE_PIN11_PORTREG    GPIO7_DR
#define CORE_PIN12_PORTREG    GPIO7_DR
#define CORE_PIN13_PORTREG    GPIO7_DR
#define CORE_PIN14_PORTREG    GPIO6_DR
#define CORE_PIN15_PORTREG    GPIO6_DR
#define CORE_PIN16_PORTREG    GPIO6_DR
#define CORE_PIN17_PORTREG    GPIO6_DR
#define CORE_PIN18_PORTREG    GPIO6_DR
#define CORE_PIN19_PORTREG    GPIO6_DR
#define CORE_PIN20_PORTREG    GPIO6_DR
#define CORE_PIN21_PORTREG    GPIO6_DR
#define CORE_PIN22_PORTREG    GPIO6_DR
#define CORE_PIN23_PORTREG    GPIO6_DR
#define CORE_PIN24_PORTREG    GPIO6_DR
#define CORE_PIN25_PORTREG    GPIO6_DR
#define CORE_PIN26_PORTREG    GPIO6_DR
#define CORE_PIN27_PORTREG    GPIO6_DR
#define CORE_PIN28_PORTREG    GPIO8_DR
#define CORE_PIN29_PORTREG    GPIO9_DR
#define CORE_PIN30_PORTREG    GPIO8_DR
#define CORE_PIN31_PORTREG    GPIO8_DR
#define CORE_PIN32_PORTREG    GPIO7_DR
#define CORE_PIN33_PORTREG    GPIO9_DR
#define CORE_PIN34_PORTREG    GPIO8_DR
#define CORE_PIN35_PORTREG    GPIO8_DR
#define CORE_PIN36_PORTREG    GPIO8_DR
#define CORE_PIN37_PORTREG    GPIO8_DR
#define CORE_PIN38_PORTREG    GPIO8_DR
#define CORE_PIN39_PORTREG    GPIO8_DR
#define CORE_PIN40_PORTREG    GPIO7_DR
#define CORE_PIN41_PORTREG    GPIO7_DR
#define CORE_PIN42_PORTREG    GPIO7_DR
#define CORE_PIN43_PORTREG    GPIO7_DR
#define CORE_PIN44_PORTREG    GPIO7_DR
#define CORE_PIN45_PORTREG    GPIO7_DR

#define CORE_PIN0_PORTSET    GPIO6_DR_SET
#define CORE_PIN1_PORTSET    GPIO6_DR_SET
#define CORE_PIN2_PORTSET    GPIO9_DR_SET
#define CORE_PIN3_PORTSET    GPIO9_DR_SET
#define CORE_PIN4_PORTSET    GPIO9_DR_SET
#define CORE_PIN5_PORTSET    GPIO9_DR_SET
#define CORE_PIN6_PORTSET    GPIO7_DR_SET
#define CORE_PIN7_PORTSET    GPIO7_DR_SET
#define CORE_PIN8_PORTSET    GPIO7_DR_SET
#define CORE_PIN9_PORTSET    GPIO7_DR_SET
#define CORE_PIN10_PORTSET    GPIO7_DR_SET
#define CORE_PIN11_PORTSET    GPIO7_DR_SET
#define CORE_PIN12_PORTSET    GPIO7_DR_SET
#define CORE_PIN13_PORTSET    GPIO7_DR_SET
#define CORE_PIN14_PORTSET    GPIO6_DR_SET
#define CORE_PIN15_PORTSET    GPIO6_DR_SET
#define CORE_PIN16_PORTSET    GPIO6_DR_SET
#define CORE_PIN17_PORTSET    GPIO6_DR_SET
#define CORE_PIN18_PORTSET    GPIO6_DR_SET
#define CORE_PIN19_PORTSET    GPIO6_DR_SET
#define CORE_PIN20_PORTSET    GPIO6_DR_SET
#define CORE_PIN21_PORTSET    GPIO6_DR_SET
#define CORE_PIN22_PORTSET    GPIO6_DR_SET
#define CORE_PIN23_PORTSET    GPIO6_DR_SET
#define CORE_PIN24_PORTSET    GPIO6_DR_SET
#define CORE_PIN25_PORTSET    GPIO6_DR_SET
#define CORE_PIN26_PORTSET    GPIO6_DR_SET
#define CORE_PIN27_PORTSET    GPIO6_DR_SET
#define CORE_PIN28_PORTSET    GPIO8_DR_SET
#define CORE_PIN29_PORTSET    GPIO9_DR_SET
#define CORE_PIN30_PORTSET    GPIO8_DR_SET
#define CORE_PIN31_PORTSET    GPIO8_DR_SET
#define CORE_PIN32_PORTSET    GPIO7_DR_SET
#define CORE_PIN33_PORTSET    GPIO9_DR_SET
#define CORE_PIN34_PORTSET    GPIO8_DR_SET
#define CORE_PIN35_PORTSET    GPIO8_DR_SET
#define CORE_PIN36_PORTSET    GPIO8_DR_SET
#define CORE_PIN37_PORTSET    GPIO8_DR_SET
#define CORE_PIN38_PORTSET    GPIO8_DR_SET
#define CORE_PIN39_PORTSET    GPIO8_DR_SET
#define CORE_PIN40_PORTSET    GPIO7_DR_SET
#define CORE_PIN41_PORTSET    GPIO7_DR_SET
#define CORE_PIN42_PORTSET    GPIO7_DR_SET
#define CORE_PIN43_PORTSET    GPIO7_DR_SET
#define CORE_PIN44_PORTSET    GPIO7_DR_SET
#define CORE_PIN45_PORTSET    GPIO7_DR_SET

#define CORE_PIN0_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN1_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN2_PORTCLEAR    GPIO9_DR_CLEAR
#define CORE_PIN3_PORTCLEAR    GPIO9_DR_CLEAR
#define CORE_PIN4_PORTCLEAR    GPIO9_DR_CLEAR
#define CORE_PIN5_PORTCLEAR    GPIO9_DR_CLEAR
#define CORE_PIN6_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN7_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN8_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN9_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN10_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN11_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN12_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN13_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN14_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN15_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN16_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN17_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN18_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN19_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN20_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN21_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN22_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN23_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN24_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN25_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN26_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN27_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN28_PORTCLEAR    GPIO8_DR_CLEAR
#define CORE_PIN29_PORTCLEAR    GPIO9_DR_CLEAR
#define CORE_PIN30_PORTCLEAR    GPIO8_DR_CLEAR
#define CORE_PIN31_PORTCLEAR    GPIO8_DR_CLEAR
#define CORE_PIN32_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN33_PORTCLEAR    GPIO9_DR_CLEAR
#define CORE_PIN34_PORTCLEAR    GPIO8_DR_CLEAR
#define CORE_PIN35_PORTCLEAR    GPIO8_DR_CLEAR
#define CORE_PIN36_PORTCLEAR    GPIO8_DR_CLEAR
#define CORE_PIN37_PORTCLEAR    GPIO8_DR_CLEAR
#define CORE_PIN38_PORTCLEAR    GPIO8_DR_CLEAR
#define CORE_PIN39_PORTCLEAR    GPIO8_DR_CLEAR
#define CORE_PIN40_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN41_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN42_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN43_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN44_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN45_PORTCLEAR    GPIO7_DR_CLEAR

#define CORE_PIN0_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN1_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN2_PORTTOGGLE    GPIO9_DR_TOGGLE
#define CORE_PIN3_PORTTOGGLE    GPIO9_DR_TOGGLE
#define CORE_PIN4_PORTTOGGLE    GPIO9_DR_TOGGLE
#define CORE_PIN5_PORTTOGGLE    GPIO9_DR_TOGGLE
#define CORE_PIN6_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN7_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN8_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN9_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN10_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN11_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN12_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN13_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN14_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN15_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN16_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN17_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN18_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN19_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN20_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN21_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN22_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN23_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN24_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN25_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN26_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN27_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN28_PORTTOGGLE    GPIO8_DR_TOGGLE
#define CORE_PIN29_PORTTOGGLE    GPIO9_DR_TOGGLE
#define CORE_PIN30_PORTTOGGLE    GPIO8_DR_TOGGLE
#define CORE_PIN31_PORTTOGGLE    GPIO8_DR_TOGGLE
#define CORE_PIN32_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN33_PORTTOGGLE    GPIO9_DR_TOGGLE
#define CORE_PIN34_PORTTOGGLE    GPIO8_DR_TOGGLE
#define CORE_PIN35_PORTTOGGLE    GPIO8_DR_TOGGLE
#define CORE_PIN36_PORTTOGGLE    GPIO8_DR_TOGGLE
#define CORE_PIN37_PORTTOGGLE    GPIO8_DR_TOGGLE
#define CORE_PIN38_PORTTOGGLE    GPIO8_DR_TOGGLE
#define CORE_PIN39_PORTTOGGLE    GPIO8_DR_TOGGLE
#define CORE_PIN40_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN41_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN42_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN43_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN44_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN45_PORTTOGGLE    GPIO7_DR_TOGGLE


#define CORE_PIN0_DDRREG    GPIO6_GDIR
#define CORE_PIN1_DDRREG    GPIO6_GDIR
#define CORE_PIN2_DDRREG    GPIO9_GDIR
#define CORE_PIN3_DDRREG    GPIO9_GDIR
#define CORE_PIN4_DDRREG    GPIO9_GDIR
#define CORE_PIN5_DDRREG    GPIO9_GDIR
#define CORE_PIN6_DDRREG    GPIO7_GDIR
#define CORE_PIN7_DDRREG    GPIO7_GDIR
#define CORE_PIN8_DDRREG    GPIO7_GDIR
#define CORE_PIN9_DDRREG    GPIO7_GDIR
#define CORE_PIN10_DDRREG    GPIO7_GDIR
#define CORE_PIN11_DDRREG    GPIO7_GDIR
#define CORE_PIN12_DDRREG    GPIO7_GDIR
#define CORE_PIN13_DDRREG    GPIO7_GDIR
#define CORE_PIN14_DDRREG    GPIO6_GDIR
#define CORE_PIN15_DDRREG    GPIO6_GDIR
#define CORE_PIN16_DDRREG    GPIO6_GDIR
#define CORE_PIN17_DDRREG    GPIO6_GDIR
#define CORE_PIN18_DDRREG    GPIO6_GDIR
#define CORE_PIN19_DDRREG    GPIO6_GDIR
#define CORE_PIN20_DDRREG    GPIO6_GDIR
#define CORE_PIN21_DDRREG    GPIO6_GDIR
#define CORE_PIN22_DDRREG    GPIO6_GDIR
#define CORE_PIN23_DDRREG    GPIO6_GDIR
#define CORE_PIN24_DDRREG    GPIO6_GDIR
#define CORE_PIN25_DDRREG    GPIO6_GDIR
#define CORE_PIN26_DDRREG    GPIO6_GDIR
#define CORE_PIN27_DDRREG    GPIO6_GDIR
#define CORE_PIN28_DDRREG    GPIO8_GDIR
#define CORE_PIN29_DDRREG    GPIO9_GDIR
#define CORE_PIN30_DDRREG    GPIO8_GDIR
#define CORE_PIN31_DDRREG    GPIO8_GDIR
#define CORE_PIN32_DDRREG    GPIO7_GDIR
#define CORE_PIN33_DDRREG    GPIO9_GDIR
#define CORE_PIN34_DDRREG    GPIO8_GDIR
#define CORE_PIN35_DDRREG    GPIO8_GDIR
#define CORE_PIN36_DDRREG    GPIO8_GDIR
#define CORE_PIN37_DDRREG    GPIO8_GDIR
#define CORE_PIN38_DDRREG    GPIO8_GDIR
#define CORE_PIN39_DDRREG    GPIO8_GDIR
#define CORE_PIN40_DDRREG    GPIO7_GDIR
#define CORE_PIN41_DDRREG    GPIO7_GDIR
#define CORE_PIN42_DDRREG    GPIO7_GDIR
#define CORE_PIN43_DDRREG    GPIO7_GDIR
#define CORE_PIN44_DDRREG    GPIO7_GDIR
#define CORE_PIN45_DDRREG    GPIO7_GDIR

#define CORE_PIN0_PINREG    GPIO6_PSR
#define CORE_PIN1_PINREG    GPIO6_PSR
#define CORE_PIN2_PINREG    GPIO9_PSR
#define CORE_PIN3_PINREG    GPIO9_PSR
#define CORE_PIN4_PINREG    GPIO9_PSR
#define CORE_PIN5_PINREG    GPIO9_PSR
#define CORE_PIN6_PINREG    GPIO7_PSR
#define CORE_PIN7_PINREG    GPIO7_PSR
#define CORE_PIN8_PINREG    GPIO7_PSR
#define CORE_PIN9_PINREG    GPIO7_PSR
#define CORE_PIN10_PINREG    GPIO7_PSR
#define CORE_PIN11_PINREG    GPIO7_PSR
#define CORE_PIN12_PINREG    GPIO7_PSR
#define CORE_PIN13_PINREG    GPIO7_PSR
#define CORE_PIN14_PINREG    GPIO6_PSR
#define CORE_PIN15_PINREG    GPIO6_PSR
#define CORE_PIN16_PINREG    GPIO6_PSR
#define CORE_PIN17_PINREG    GPIO6_PSR
#define CORE_PIN18_PINREG    GPIO6_PSR
#define CORE_PIN19_PINREG    GPIO6_PSR
#define CORE_PIN20_PINREG    GPIO6_PSR
#define CORE_PIN21_PINREG    GPIO6_PSR
#define CORE_PIN22_PINREG    GPIO6_PSR
#define CORE_PIN23_PINREG    GPIO6_PSR
#define CORE_PIN24_PINREG    GPIO6_PSR
#define CORE_PIN25_PINREG    GPIO6_PSR
#define CORE_PIN26_PINREG    GPIO6_PSR
#define CORE_PIN27_PINREG    GPIO6_PSR
#define CORE_PIN28_PINREG    GPIO8_PSR
#define CORE_PIN29_PINREG    GPIO9_PSR
#define CORE_PIN30_PINREG    GPIO8_PSR
#define CORE_PIN31_PINREG    GPIO8_PSR
#define CORE_PIN32_PINREG    GPIO7_PSR
#define CORE_PIN33_PINREG    GPIO9_PSR
#define CORE_PIN34_PINREG    GPIO8_PSR
#define CORE_PIN35_PINREG    GPIO8_PSR
#define CORE_PIN36_PINREG    GPIO8_PSR
#define CORE_PIN37_PINREG    GPIO8_PSR
#define CORE_PIN38_PINREG    GPIO8_PSR
#define CORE_PIN39_PINREG    GPIO8_PSR
#define CORE_PIN40_PINREG    GPIO7_PSR
#define CORE_PIN41_PINREG    GPIO7_PSR
#define CORE_PIN42_PINREG    GPIO7_PSR
#define CORE_PIN43_PINREG    GPIO7_PSR
#define CORE_PIN44_PINREG    GPIO7_PSR
#define CORE_PIN45_PINREG    GPIO7_PSR



// mux config registers control which peripheral uses the pin
#define CORE_PIN0_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_03
#define CORE_PIN1_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_02
#define CORE_PIN2_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_04
#define CORE_PIN3_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_05
#define CORE_PIN4_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_06
#define CORE_PIN5_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_08
#define CORE_PIN6_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_10
#define CORE_PIN7_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B1_01
#define CORE_PIN8_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B1_00
#define CORE_PIN9_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_11
#define CORE_PIN10_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_00
#define CORE_PIN11_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_02
#define CORE_PIN12_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_01
#define CORE_PIN13_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_03
#define CORE_PIN14_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_02
#define CORE_PIN15_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_03
#define CORE_PIN16_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_07
#define CORE_PIN17_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_06
#define CORE_PIN18_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_01
#define CORE_PIN19_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_00
#define CORE_PIN20_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_10
#define CORE_PIN21_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_11
#define CORE_PIN22_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_08
#define CORE_PIN23_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_09
#define CORE_PIN24_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_12
#define CORE_PIN25_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_13
#define CORE_PIN26_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_14
#define CORE_PIN27_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_15
#define CORE_PIN28_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_32
#define CORE_PIN29_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_31
#define CORE_PIN30_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_37
#define CORE_PIN31_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_36
#define CORE_PIN32_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_12
#define CORE_PIN33_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_07
#define CORE_PIN34_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_03
#define CORE_PIN35_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_02
#define CORE_PIN36_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_01
#define CORE_PIN37_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_00
#define CORE_PIN38_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_04
#define CORE_PIN39_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_SD_B0_05
#define CORE_PIN40_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_04
#define CORE_PIN41_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_05
#define CORE_PIN42_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_06
#define CORE_PIN43_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_07
#define CORE_PIN44_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_08
#define CORE_PIN45_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_09

// pad config registers control pullup/pulldown/keeper, drive strength, etc
#define CORE_PIN0_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_03
#define CORE_PIN1_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_02
#define CORE_PIN2_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_04
#define CORE_PIN3_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_05
#define CORE_PIN4_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_06
#define CORE_PIN5_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_08
#define CORE_PIN6_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_10
#define CORE_PIN7_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B1_01
#define CORE_PIN8_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B1_00
#define CORE_PIN9_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_11
#define CORE_PIN10_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_00
#define CORE_PIN11_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_02
#define CORE_PIN12_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_01
#define CORE_PIN13_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_03
#define CORE_PIN14_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_02
#define CORE_PIN15_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_03
#define CORE_PIN16_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_07
#define CORE_PIN17_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_06
#define CORE_PIN18_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_01
#define CORE_PIN19_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_00
#define CORE_PIN20_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_10
#define CORE_PIN21_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_11
#define CORE_PIN22_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_08
#define CORE_PIN23_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_09
#define CORE_PIN24_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_12
#define CORE_PIN25_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_13
#define CORE_PIN26_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_14
#define CORE_PIN27_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_15
#define CORE_PIN28_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_32
#define CORE_PIN29_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_31
#define CORE_PIN30_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_37
#define CORE_PIN31_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_36
#define CORE_PIN32_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_12
#define CORE_PIN33_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_07
#define CORE_PIN34_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_03
#define CORE_PIN35_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_02
#define CORE_PIN36_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_01
#define CORE_PIN37_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_00
#define CORE_PIN38_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_04
#define CORE_PIN39_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_SD_B0_05
#define CORE_PIN40_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_04
#define CORE_PIN41_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_05
#define CORE_PIN42_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_06
#define CORE_PIN43_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_07
#define CORE_PIN44_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_08
#define CORE_PIN45_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_09

#define CORE_LED0_PIN        13

#define CORE_ADC0_PIN        14
#define CORE_ADC1_PIN        15
#define CORE_ADC2_PIN        16
#define CORE_ADC3_PIN        17
#define CORE_ADC4_PIN        18
#define CORE_ADC5_PIN        19
#define CORE_ADC6_PIN        20
#define CORE_ADC7_PIN        21
#define CORE_ADC8_PIN        22
#define CORE_ADC9_PIN        23

#define CORE_RXD0_PIN        0
#define CORE_TXD0_PIN        1
#define CORE_RXD1_PIN        7
#define CORE_TXD1_PIN        8
#define CORE_RXD2_PIN        15
#define CORE_TXD2_PIN        14
#define CORE_RXD3_PIN        16
#define CORE_TXD3_PIN        17
#define CORE_RXD4_PIN        21
#define CORE_TXD4_PIN        20
#define CORE_RXD5_PIN        25
#define CORE_TXD5_PIN        24
#define CORE_RXD6_PIN        28
#define CORE_TXD6_PIN        29

#define CORE_INT0_PIN        0
#define CORE_INT1_PIN        1
#define CORE_INT2_PIN        2
#define CORE_INT3_PIN        3
#define CORE_INT4_PIN        4
#define CORE_INT5_PIN        5
#define CORE_INT6_PIN        6
#define CORE_INT7_PIN        7
#define CORE_INT8_PIN        8
#define CORE_INT9_PIN        9
#define CORE_INT10_PIN        10
#define CORE_INT11_PIN        11
#define CORE_INT12_PIN        12
#define CORE_INT13_PIN        13
#define CORE_INT14_PIN        14
#define CORE_INT15_PIN        15
#define CORE_INT16_PIN        16
#define CORE_INT17_PIN        17
#define CORE_INT18_PIN        18
#define CORE_INT19_PIN        19
#define CORE_INT20_PIN        20
#define CORE_INT21_PIN        21
#define CORE_INT22_PIN        22
#define CORE_INT23_PIN        23
#define CORE_INT24_PIN        24
#define CORE_INT25_PIN        25
#define CORE_INT26_PIN        26
#define CORE_INT27_PIN        27
#define CORE_INT28_PIN        28
#define CORE_INT29_PIN        29
#define CORE_INT30_PIN        30
#define CORE_INT31_PIN        31
#define CORE_INT32_PIN        32
#define CORE_INT33_PIN        33
#define CORE_INT34_PIN        34
#define CORE_INT35_PIN        35
#define CORE_INT36_PIN        36
#define CORE_INT37_PIN        37
#define CORE_INT38_PIN        38
#define CORE_INT39_PIN        39
#define CORE_INT40_PIN        40
#define CORE_INT41_PIN        41
#define CORE_INT42_PIN        42
#define CORE_INT43_PIN        43
#define CORE_INT44_PIN        44
#define CORE_INT45_PIN        45

///////////////////////
#define CORE_PIN46_BIT        12
#define CORE_PIN47_BIT        14
#define CORE_PIN48_BIT        15
#define CORE_PIN49_BIT        18
#define CORE_PIN50_BIT        19
#define CORE_PIN51_BIT        20
#define CORE_PIN52_BIT        21
#define CORE_PIN53_BIT        22
#define CORE_PIN54_BIT        23
#define CORE_PIN55_BIT        24
#define CORE_PIN56_BIT        25
#define CORE_PIN57_BIT        26
#define CORE_PIN58_BIT        27
#define CORE_PIN59_BIT        28
#define CORE_PIN60_BIT        29
#define CORE_PIN61_BIT        30
#define CORE_PIN62_BIT        31
#define CORE_PIN63_BIT        13
#define CORE_PIN64_BIT		  20
#define CORE_PIN65_BIT		  21
#define CORE_PIN66_BIT		  28
#define CORE_PIN67_BIT		  29
#define CORE_PIN68_BIT		  14
#define CORE_PIN69_BIT		  15


#define CORE_PIN46_BITMASK    (1<<(CORE_PIN46_BIT))
#define CORE_PIN47_BITMASK    (1<<(CORE_PIN47_BIT))
#define CORE_PIN48_BITMASK    (1<<(CORE_PIN48_BIT))
#define CORE_PIN49_BITMASK    (1<<(CORE_PIN49_BIT))
#define CORE_PIN50_BITMASK    (1<<(CORE_PIN50_BIT))
#define CORE_PIN51_BITMASK    (1<<(CORE_PIN51_BIT))
#define CORE_PIN52_BITMASK    (1<<(CORE_PIN52_BIT))
#define CORE_PIN53_BITMASK    (1<<(CORE_PIN53_BIT))
#define CORE_PIN54_BITMASK    (1<<(CORE_PIN54_BIT))
#define CORE_PIN55_BITMASK    (1<<(CORE_PIN55_BIT))
#define CORE_PIN56_BITMASK    (1<<(CORE_PIN56_BIT))
#define CORE_PIN57_BITMASK    (1<<(CORE_PIN57_BIT))
#define CORE_PIN58_BITMASK    (1<<(CORE_PIN58_BIT))
#define CORE_PIN59_BITMASK    (1<<(CORE_PIN59_BIT))
#define CORE_PIN60_BITMASK    (1<<(CORE_PIN60_BIT))
#define CORE_PIN61_BITMASK    (1<<(CORE_PIN61_BIT))
#define CORE_PIN62_BITMASK    (1<<(CORE_PIN62_BIT))
#define CORE_PIN63_BITMASK    (1<<(CORE_PIN63_BIT))
#define CORE_PIN64_BITMASK    (1<<(CORE_PIN64_BIT))
#define CORE_PIN65_BITMASK    (1<<(CORE_PIN65_BIT))
#define CORE_PIN66_BITMASK    (1<<(CORE_PIN66_BIT))
#define CORE_PIN67_BITMASK    (1<<(CORE_PIN67_BIT))
#define CORE_PIN68_BITMASK    (1<<(CORE_PIN68_BIT))
#define CORE_PIN69_BITMASK    (1<<(CORE_PIN69_BIT))

#define CORE_PIN46_PORTREG    GPIO7_DR
#define CORE_PIN47_PORTREG    GPIO7_DR
#define CORE_PIN48_PORTREG    GPIO7_DR
#define CORE_PIN49_PORTREG    GPIO7_DR
#define CORE_PIN50_PORTREG    GPIO7_DR
#define CORE_PIN51_PORTREG    GPIO7_DR
#define CORE_PIN52_PORTREG    GPIO7_DR
#define CORE_PIN53_PORTREG    GPIO7_DR
#define CORE_PIN54_PORTREG    GPIO7_DR
#define CORE_PIN55_PORTREG    GPIO7_DR
#define CORE_PIN56_PORTREG    GPIO7_DR
#define CORE_PIN57_PORTREG    GPIO7_DR
#define CORE_PIN58_PORTREG    GPIO7_DR
#define CORE_PIN59_PORTREG    GPIO7_DR
#define CORE_PIN60_PORTREG    GPIO7_DR
#define CORE_PIN61_PORTREG    GPIO7_DR
#define CORE_PIN62_PORTREG    GPIO7_DR
#define CORE_PIN63_PORTREG    GPIO7_DR
#define CORE_PIN64_PORTREG    GPIO6_DR
#define CORE_PIN65_PORTREG    GPIO6_DR
#define CORE_PIN66_PORTREG    GPIO6_DR
#define CORE_PIN67_PORTREG    GPIO6_DR
#define CORE_PIN68_PORTREG    GPIO6_DR
#define CORE_PIN69_PORTREG    GPIO6_DR

#define CORE_PIN46_PORTSET    GPIO7_DR_SET
#define CORE_PIN47_PORTSET    GPIO7_DR_SET
#define CORE_PIN48_PORTSET    GPIO7_DR_SET
#define CORE_PIN49_PORTSET    GPIO7_DR_SET
#define CORE_PIN50_PORTSET    GPIO7_DR_SET
#define CORE_PIN51_PORTSET    GPIO7_DR_SET
#define CORE_PIN52_PORTSET    GPIO7_DR_SET
#define CORE_PIN53_PORTSET    GPIO7_DR_SET
#define CORE_PIN54_PORTSET    GPIO7_DR_SET
#define CORE_PIN55_PORTSET    GPIO7_DR_SET
#define CORE_PIN56_PORTSET    GPIO7_DR_SET
#define CORE_PIN57_PORTSET    GPIO7_DR_SET
#define CORE_PIN58_PORTSET    GPIO7_DR_SET
#define CORE_PIN59_PORTSET    GPIO7_DR_SET
#define CORE_PIN60_PORTSET    GPIO7_DR_SET
#define CORE_PIN61_PORTSET    GPIO7_DR_SET
#define CORE_PIN62_PORTSET    GPIO7_DR_SET
#define CORE_PIN63_PORTSET    GPIO7_DR_SET
#define CORE_PIN64_PORTSET    GPIO6_DR_SET
#define CORE_PIN65_PORTSET    GPIO6_DR_SET
#define CORE_PIN66_PORTSET    GPIO6_DR_SET
#define CORE_PIN67_PORTSET    GPIO6_DR_SET
#define CORE_PIN68_PORTSET    GPIO6_DR_SET
#define CORE_PIN69_PORTSET    GPIO6_DR_SET


#define CORE_PIN46_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN47_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN48_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN49_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN50_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN51_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN52_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN53_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN54_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN55_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN56_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN57_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN58_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN59_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN60_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN61_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN62_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN63_PORTCLEAR    GPIO7_DR_CLEAR
#define CORE_PIN64_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN65_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN66_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN67_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN68_PORTCLEAR    GPIO6_DR_CLEAR
#define CORE_PIN69_PORTCLEAR    GPIO6_DR_CLEAR

#define CORE_PIN46_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN47_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN48_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN49_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN50_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN51_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN52_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN53_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN54_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN55_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN56_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN57_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN58_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN59_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN60_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN61_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN62_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN63_PORTTOGGLE    GPIO7_DR_TOGGLE
#define CORE_PIN64_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN65_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN66_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN67_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN68_PORTTOGGLE    GPIO6_DR_TOGGLE
#define CORE_PIN69_PORTTOGGLE    GPIO6_DR_TOGGLE

#define CORE_PIN46_DDRREG    GPIO7_GDIR
#define CORE_PIN47_DDRREG    GPIO7_GDIR
#define CORE_PIN48_DDRREG    GPIO7_GDIR
#define CORE_PIN49_DDRREG    GPIO7_GDIR
#define CORE_PIN50_DDRREG    GPIO7_GDIR
#define CORE_PIN51_DDRREG    GPIO7_GDIR
#define CORE_PIN52_DDRREG    GPIO7_GDIR
#define CORE_PIN53_DDRREG    GPIO7_GDIR
#define CORE_PIN54_DDRREG    GPIO7_GDIR
#define CORE_PIN55_DDRREG    GPIO7_GDIR
#define CORE_PIN56_DDRREG    GPIO7_GDIR
#define CORE_PIN57_DDRREG    GPIO7_GDIR
#define CORE_PIN58_DDRREG    GPIO7_GDIR
#define CORE_PIN59_DDRREG    GPIO7_GDIR
#define CORE_PIN60_DDRREG    GPIO7_GDIR
#define CORE_PIN61_DDRREG    GPIO7_GDIR
#define CORE_PIN62_DDRREG    GPIO7_GDIR
#define CORE_PIN63_DDRREG    GPIO7_GDIR
#define CORE_PIN64_DDRREG    GPIO6_GDIR
#define CORE_PIN65_DDRREG    GPIO6_GDIR
#define CORE_PIN66_DDRREG    GPIO6_GDIR
#define CORE_PIN67_DDRREG    GPIO6_GDIR
#define CORE_PIN68_DDRREG    GPIO6_GDIR
#define CORE_PIN69_DDRREG    GPIO6_GDIR

#define CORE_PIN46_PINREG    GPIO7_PSR
#define CORE_PIN47_PINREG    GPIO7_PSR
#define CORE_PIN48_PINREG    GPIO7_PSR
#define CORE_PIN49_PINREG    GPIO7_PSR
#define CORE_PIN50_PINREG    GPIO7_PSR
#define CORE_PIN51_PINREG    GPIO7_PSR
#define CORE_PIN52_PINREG    GPIO7_PSR
#define CORE_PIN53_PINREG    GPIO7_PSR
#define CORE_PIN54_PINREG    GPIO7_PSR
#define CORE_PIN55_PINREG    GPIO7_PSR
#define CORE_PIN56_PINREG    GPIO7_PSR
#define CORE_PIN57_PINREG    GPIO7_PSR
#define CORE_PIN58_PINREG    GPIO7_PSR
#define CORE_PIN59_PINREG    GPIO7_PSR
#define CORE_PIN60_PINREG    GPIO7_PSR
#define CORE_PIN61_PINREG    GPIO7_PSR
#define CORE_PIN62_PINREG    GPIO7_PSR
#define CORE_PIN63_PINREG    GPIO7_PSR
#define CORE_PIN64_PINREG    GPIO6_PSR
#define CORE_PIN65_PINREG    GPIO6_PSR
#define CORE_PIN66_PINREG    GPIO6_PSR
#define CORE_PIN67_PINREG    GPIO6_PSR
#define CORE_PIN68_PINREG    GPIO6_PSR
#define CORE_PIN69_PINREG    GPIO6_PSR

#define CORE_PIN46_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_12
#define CORE_PIN47_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_14
#define CORE_PIN48_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_15
#define CORE_PIN49_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B1_02
#define CORE_PIN50_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B1_03
#define CORE_PIN51_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B1_04
#define CORE_PIN52_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B1_05
#define CORE_PIN53_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B1_06
#define CORE_PIN54_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B1_07
#define CORE_PIN55_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B1_08
#define CORE_PIN56_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B1_09
#define CORE_PIN57_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B1_10
#define CORE_PIN58_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B1_11
#define CORE_PIN59_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B1_12
#define CORE_PIN60_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B1_13
#define CORE_PIN61_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B1_14
#define CORE_PIN62_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B1_15
#define CORE_PIN63_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_13
#define CORE_PIN64_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_04
#define CORE_PIN65_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_05
#define CORE_PIN66_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_12
#define CORE_PIN67_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B1_13
#define CORE_PIN68_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_14
#define CORE_PIN69_CONFIG    IOMUXC_SW_MUX_CTL_PAD_GPIO_AD_B0_15

#define CORE_PIN46_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_12
#define CORE_PIN47_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_14
#define CORE_PIN48_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_15
#define CORE_PIN49_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B1_02
#define CORE_PIN50_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B1_03
#define CORE_PIN51_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B1_04
#define CORE_PIN52_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B1_05
#define CORE_PIN53_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B1_06
#define CORE_PIN54_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B1_07
#define CORE_PIN55_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B1_08
#define CORE_PIN56_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B1_09
#define CORE_PIN57_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B1_10
#define CORE_PIN58_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B1_11
#define CORE_PIN59_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B1_12
#define CORE_PIN60_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B1_13
#define CORE_PIN61_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B1_14
#define CORE_PIN62_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B1_15
#define CORE_PIN63_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_13
#define CORE_PIN64_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_04
#define CORE_PIN65_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_05
#define CORE_PIN66_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_12
#define CORE_PIN67_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B1_13
#define CORE_PIN68_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_14
#define CORE_PIN69_PADCONFIG    IOMUXC_SW_PAD_CTL_PAD_GPIO_AD_B0_15

#define CORE_INT46_PIN        46
#define CORE_INT47_PIN        47
#define CORE_INT48_PIN        48
#define CORE_INT49_PIN        49
#define CORE_INT50_PIN        50
#define CORE_INT51_PIN        51
#define CORE_INT52_PIN        52
#define CORE_INT53_PIN        53
#define CORE_INT54_PIN        54
#define CORE_INT55_PIN        55
#define CORE_INT56_PIN        56
#define CORE_INT57_PIN        57
#define CORE_INT58_PIN        58
#define CORE_INT59_PIN        59
#define CORE_INT60_PIN        60
#define CORE_INT61_PIN        61
#define CORE_INT62_PIN        62
#define CORE_INT63_PIN        63
#define CORE_INT64_PIN    	  64
#define CORE_INT65_PIN    	  65
#define CORE_INT66_PIN    	  66
#define CORE_INT67_PIN    	  67
#define CORE_INT68_PIN    	  68
#define CORE_INT69_PIN    	  69

////////////////////////
#define CORE_INT_EVERY_PIN    1

#define DIGITAL_FAST_USE_DIGITAL_PIN_TO_INFO_PGM
