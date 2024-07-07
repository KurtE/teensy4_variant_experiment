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

#include "imxrt.h"
#include "math.h"
#include <stdbool.h>
#include <stdio.h>
#include "core_pins.h"

//=============================================================================
// Main Pin mapping table
//=============================================================================
const struct digital_pin_bitband_and_config_table_struct digital_pin_to_info_PGM[] = {
    {&CORE_PIN0_PORTREG, &CORE_PIN0_CONFIG, &CORE_PIN0_PADCONFIG, CORE_PIN0_BITMASK},
    {&CORE_PIN1_PORTREG, &CORE_PIN1_CONFIG, &CORE_PIN1_PADCONFIG, CORE_PIN1_BITMASK},
    {&CORE_PIN2_PORTREG, &CORE_PIN2_CONFIG, &CORE_PIN2_PADCONFIG, CORE_PIN2_BITMASK},
    {&CORE_PIN3_PORTREG, &CORE_PIN3_CONFIG, &CORE_PIN3_PADCONFIG, CORE_PIN3_BITMASK},
    {&CORE_PIN4_PORTREG, &CORE_PIN4_CONFIG, &CORE_PIN4_PADCONFIG, CORE_PIN4_BITMASK},
    {&CORE_PIN5_PORTREG, &CORE_PIN5_CONFIG, &CORE_PIN5_PADCONFIG, CORE_PIN5_BITMASK},
    {&CORE_PIN6_PORTREG, &CORE_PIN6_CONFIG, &CORE_PIN6_PADCONFIG, CORE_PIN6_BITMASK},
    {&CORE_PIN7_PORTREG, &CORE_PIN7_CONFIG, &CORE_PIN7_PADCONFIG, CORE_PIN7_BITMASK},
    {&CORE_PIN8_PORTREG, &CORE_PIN8_CONFIG, &CORE_PIN8_PADCONFIG, CORE_PIN8_BITMASK},
    {&CORE_PIN9_PORTREG, &CORE_PIN9_CONFIG, &CORE_PIN9_PADCONFIG, CORE_PIN9_BITMASK},
    {&CORE_PIN10_PORTREG, &CORE_PIN10_CONFIG, &CORE_PIN10_PADCONFIG, CORE_PIN10_BITMASK},
    {&CORE_PIN11_PORTREG, &CORE_PIN11_CONFIG, &CORE_PIN11_PADCONFIG, CORE_PIN11_BITMASK},
    {&CORE_PIN12_PORTREG, &CORE_PIN12_CONFIG, &CORE_PIN12_PADCONFIG, CORE_PIN12_BITMASK},
    {&CORE_PIN13_PORTREG, &CORE_PIN13_CONFIG, &CORE_PIN13_PADCONFIG, CORE_PIN13_BITMASK},
    {&CORE_PIN14_PORTREG, &CORE_PIN14_CONFIG, &CORE_PIN14_PADCONFIG, CORE_PIN14_BITMASK},
    {&CORE_PIN15_PORTREG, &CORE_PIN15_CONFIG, &CORE_PIN15_PADCONFIG, CORE_PIN15_BITMASK},
    {&CORE_PIN16_PORTREG, &CORE_PIN16_CONFIG, &CORE_PIN16_PADCONFIG, CORE_PIN16_BITMASK},
    {&CORE_PIN17_PORTREG, &CORE_PIN17_CONFIG, &CORE_PIN17_PADCONFIG, CORE_PIN17_BITMASK},
    {&CORE_PIN18_PORTREG, &CORE_PIN18_CONFIG, &CORE_PIN18_PADCONFIG, CORE_PIN18_BITMASK},
    {&CORE_PIN19_PORTREG, &CORE_PIN19_CONFIG, &CORE_PIN19_PADCONFIG, CORE_PIN19_BITMASK},
    {&CORE_PIN20_PORTREG, &CORE_PIN20_CONFIG, &CORE_PIN20_PADCONFIG, CORE_PIN20_BITMASK},
    {&CORE_PIN21_PORTREG, &CORE_PIN21_CONFIG, &CORE_PIN21_PADCONFIG, CORE_PIN21_BITMASK},
    {&CORE_PIN22_PORTREG, &CORE_PIN22_CONFIG, &CORE_PIN22_PADCONFIG, CORE_PIN22_BITMASK},
    {&CORE_PIN23_PORTREG, &CORE_PIN23_CONFIG, &CORE_PIN23_PADCONFIG, CORE_PIN23_BITMASK},
    {&CORE_PIN24_PORTREG, &CORE_PIN24_CONFIG, &CORE_PIN24_PADCONFIG, CORE_PIN24_BITMASK},
    {&CORE_PIN25_PORTREG, &CORE_PIN25_CONFIG, &CORE_PIN25_PADCONFIG, CORE_PIN25_BITMASK},
    {&CORE_PIN26_PORTREG, &CORE_PIN26_CONFIG, &CORE_PIN26_PADCONFIG, CORE_PIN26_BITMASK},
    {&CORE_PIN27_PORTREG, &CORE_PIN27_CONFIG, &CORE_PIN27_PADCONFIG, CORE_PIN27_BITMASK},
    {&CORE_PIN28_PORTREG, &CORE_PIN28_CONFIG, &CORE_PIN28_PADCONFIG, CORE_PIN28_BITMASK},
    {&CORE_PIN29_PORTREG, &CORE_PIN29_CONFIG, &CORE_PIN29_PADCONFIG, CORE_PIN29_BITMASK},
    {&CORE_PIN30_PORTREG, &CORE_PIN30_CONFIG, &CORE_PIN30_PADCONFIG, CORE_PIN30_BITMASK},
    {&CORE_PIN31_PORTREG, &CORE_PIN31_CONFIG, &CORE_PIN31_PADCONFIG, CORE_PIN31_BITMASK},
    {&CORE_PIN32_PORTREG, &CORE_PIN32_CONFIG, &CORE_PIN32_PADCONFIG, CORE_PIN32_BITMASK},
    {&CORE_PIN33_PORTREG, &CORE_PIN33_CONFIG, &CORE_PIN33_PADCONFIG, CORE_PIN33_BITMASK},
    {&CORE_PIN34_PORTREG, &CORE_PIN34_CONFIG, &CORE_PIN34_PADCONFIG, CORE_PIN34_BITMASK},
    {&CORE_PIN35_PORTREG, &CORE_PIN35_CONFIG, &CORE_PIN35_PADCONFIG, CORE_PIN35_BITMASK},
    {&CORE_PIN36_PORTREG, &CORE_PIN36_CONFIG, &CORE_PIN36_PADCONFIG, CORE_PIN36_BITMASK},
    {&CORE_PIN37_PORTREG, &CORE_PIN37_CONFIG, &CORE_PIN37_PADCONFIG, CORE_PIN37_BITMASK},
    {&CORE_PIN38_PORTREG, &CORE_PIN38_CONFIG, &CORE_PIN38_PADCONFIG, CORE_PIN38_BITMASK},
    {&CORE_PIN39_PORTREG, &CORE_PIN39_CONFIG, &CORE_PIN39_PADCONFIG, CORE_PIN39_BITMASK},
    {&CORE_PIN40_PORTREG, &CORE_PIN40_CONFIG, &CORE_PIN40_PADCONFIG, CORE_PIN40_BITMASK},
    {&CORE_PIN41_PORTREG, &CORE_PIN41_CONFIG, &CORE_PIN41_PADCONFIG, CORE_PIN41_BITMASK},
    {&CORE_PIN42_PORTREG, &CORE_PIN42_CONFIG, &CORE_PIN42_PADCONFIG, CORE_PIN42_BITMASK},
    {&CORE_PIN43_PORTREG, &CORE_PIN43_CONFIG, &CORE_PIN43_PADCONFIG, CORE_PIN43_BITMASK},
    {&CORE_PIN44_PORTREG, &CORE_PIN44_CONFIG, &CORE_PIN44_PADCONFIG, CORE_PIN44_BITMASK},
    {&CORE_PIN45_PORTREG, &CORE_PIN45_CONFIG, &CORE_PIN45_PADCONFIG, CORE_PIN45_BITMASK},
    {&CORE_PIN46_PORTREG, &CORE_PIN46_CONFIG, &CORE_PIN46_PADCONFIG, CORE_PIN46_BITMASK},
    {&CORE_PIN47_PORTREG, &CORE_PIN47_CONFIG, &CORE_PIN47_PADCONFIG, CORE_PIN47_BITMASK},
    {&CORE_PIN48_PORTREG, &CORE_PIN48_CONFIG, &CORE_PIN48_PADCONFIG, CORE_PIN48_BITMASK},
    {&CORE_PIN49_PORTREG, &CORE_PIN49_CONFIG, &CORE_PIN49_PADCONFIG, CORE_PIN49_BITMASK},
    {&CORE_PIN50_PORTREG, &CORE_PIN50_CONFIG, &CORE_PIN50_PADCONFIG, CORE_PIN50_BITMASK},
    {&CORE_PIN51_PORTREG, &CORE_PIN51_CONFIG, &CORE_PIN51_PADCONFIG, CORE_PIN51_BITMASK},
    {&CORE_PIN52_PORTREG, &CORE_PIN52_CONFIG, &CORE_PIN52_PADCONFIG, CORE_PIN52_BITMASK},
    {&CORE_PIN53_PORTREG, &CORE_PIN53_CONFIG, &CORE_PIN53_PADCONFIG, CORE_PIN53_BITMASK},
    {&CORE_PIN54_PORTREG, &CORE_PIN54_CONFIG, &CORE_PIN54_PADCONFIG, CORE_PIN54_BITMASK},
    {&CORE_PIN55_PORTREG, &CORE_PIN55_CONFIG, &CORE_PIN55_PADCONFIG, CORE_PIN55_BITMASK},
    {&CORE_PIN56_PORTREG, &CORE_PIN56_CONFIG, &CORE_PIN56_PADCONFIG, CORE_PIN56_BITMASK},
    {&CORE_PIN57_PORTREG, &CORE_PIN57_CONFIG, &CORE_PIN57_PADCONFIG, CORE_PIN57_BITMASK},
    {&CORE_PIN58_PORTREG, &CORE_PIN58_CONFIG, &CORE_PIN58_PADCONFIG, CORE_PIN58_BITMASK},
    {&CORE_PIN59_PORTREG, &CORE_PIN59_CONFIG, &CORE_PIN59_PADCONFIG, CORE_PIN59_BITMASK},
    {&CORE_PIN60_PORTREG, &CORE_PIN60_CONFIG, &CORE_PIN60_PADCONFIG, CORE_PIN60_BITMASK},
    {&CORE_PIN61_PORTREG, &CORE_PIN61_CONFIG, &CORE_PIN61_PADCONFIG, CORE_PIN61_BITMASK},
    {&CORE_PIN62_PORTREG, &CORE_PIN62_CONFIG, &CORE_PIN62_PADCONFIG, CORE_PIN62_BITMASK},
    {&CORE_PIN63_PORTREG, &CORE_PIN63_CONFIG, &CORE_PIN63_PADCONFIG, CORE_PIN63_BITMASK},   
};

//=============================================================================
// PWM table - Note I left things that should be removed if real board
//=============================================================================
#define M(a, b) ((((a) - 1) << 4) | (b))

struct pwm_pin_info_struct {
	uint8_t type;    // 0=no pwm, 1=flexpwm, 2=quad
	uint8_t module;  // 0-3, 0-3
	uint8_t channel; // 0=X, 1=A, 2=B
	uint8_t muxval;  //
};


const struct pwm_pin_info_struct pwm_pin_info[] = {
	{1, M(1, 1), 0, 4},  // FlexPWM1_1_X   0  // AD_B0_03
	{1, M(1, 0), 0, 4},  // FlexPWM1_0_X   1  // AD_B0_02
	{1, M(4, 2), 1, 1},  // FlexPWM4_2_A   2  // EMC_04
	{1, M(4, 2), 2, 1},  // FlexPWM4_2_B   3  // EMC_05
	{1, M(2, 0), 1, 1},  // FlexPWM2_0_A   4  // EMC_06
	{1, M(2, 1), 1, 1},  // FlexPWM2_1_A   5  // EMC_08
	{1, M(2, 2), 1, 2},  // FlexPWM2_2_A   6  // B0_10
	{1, M(1, 3), 2, 6},  // FlexPWM1_3_B   7  // B1_01
	{1, M(1, 3), 1, 6},  // FlexPWM1_3_A   8  // B1_00
	{1, M(2, 2), 2, 2},  // FlexPWM2_2_B   9  // B0_11
	{2, M(1, 0), 0, 1},  // QuadTimer1_0  10  // B0_00
	{2, M(1, 2), 0, 1},  // QuadTimer1_2  11  // B0_02
	{2, M(1, 1), 0, 1},  // QuadTimer1_1  12  // B0_01
	{2, M(2, 0), 0, 1},  // QuadTimer2_0  13  // B0_03
	{2, M(3, 2), 0, 1},  // QuadTimer3_2  14  // AD_B1_02
	{2, M(3, 3), 0, 1},  // QuadTimer3_3  15  // AD_B1_03
	{0, M(1, 0), 0, 0},
	{0, M(1, 0), 0, 0},
	{2, M(3, 1), 0, 1},  // QuadTimer3_1  18  // AD_B1_01
	{2, M(3, 0), 0, 1},  // QuadTimer3_0  19  // AD_B1_00
	{0, M(1, 0), 0, 0},
	{0, M(1, 0), 0, 0},
	{1, M(4, 0), 1, 1},  // FlexPWM4_0_A  22  // AD_B1_08
	{1, M(4, 1), 1, 1},  // FlexPWM4_1_A  23  // AD_B1_09
	{1, M(1, 2), 0, 4},  // FlexPWM1_2_X  24  // AD_B0_12
	{1, M(1, 3), 0, 4},  // FlexPWM1_3_X  25  // AD_B0_13
	{0, M(1, 0), 0, 0},
	{0, M(1, 0), 0, 0},
	{1, M(3, 1), 2, 1},  // FlexPWM3_1_B  28  // EMC_32
	{1, M(3, 1), 1, 1},  // FlexPWM3_1_A  29  // EMC_31
	{0, M(1, 0), 0, 0},
	{0, M(1, 0), 0, 0},
	{0, M(1, 0), 0, 0},
	{1, M(2, 0), 2, 1},  // FlexPWM2_0_B  33  // EMC_07
// These are the MICROMOD ones
	{1, M(1, 1), 2, 1},  // FlexPWM1_1_B  34  // SD_B0_03
	{1, M(1, 1), 1, 1},  // FlexPWM1_1_A  35  // SD_B0_02
	{1, M(1, 0), 2, 1},  // FlexPWM1_0_B  36  // SD_B0_01
	{1, M(1, 0), 1, 1},  // FlexPWM1_0_A  37  // SD_B0_00
	{1, M(1, 2), 1, 1},  // FlexPWM1_2_A  38  // SD_B0_04
	{1, M(1, 2), 2, 1},  // FlexPWM1_2_B  39  // SD_B0_05
	{2, M(2, 1), 0, 1},  // QuadTimer2_1  40  // B0_04
	{2, M(2, 2), 0, 1},  // QuadTimer2_2  41  // B0_05
	{0, M(1, 0), 0, 0},  // duplicate QuadTimer3_0
	{0, M(1, 0), 0, 0},  // duplicate QuadTimer3_1
	{0, M(1, 0), 0, 0},  // duplicate QuadTimer3_2
	{2, M(4, 0), 0, 1},  // QuadTimer4_0  45  // B0_09
// Our added ones
	{0, M(1, 0), 0, 0},  // 46
	{0, M(1, 0), 0, 0},
	{0, M(1, 0), 0, 0},
	{1, M(2, 3), 1, 6},  // FLEXPWM2_PWMA03 49  // B1_02    
	{1, M(2, 3), 2, 6},  // FLEXPWM2_PWMB03 50  // B1_03    
	{0, M(1, 0), 0, 0},
	{0, M(1, 0), 0, 0},
	{0, M(1, 0), 0, 0},
	{0, M(1, 0), 0, 0},
	{2, M(1, 3), 0, 1},  // QuadTimer1_3  55  // B1_08
	{2, M(2, 3), 0, 1},  // QuadTimer2_3  56  // B1_09
	{2, M(3, 3), 0, 1},  // QuadTimer3_3  57  // B1_10
	{2, M(4, 3), 0, 1},  // QuadTimer4_3  58  // B1_11
	{0, M(1, 0), 0, 0},
	{0, M(1, 0), 0, 0},
	{1, M(4, 2), 1, 1},  // FlexPWM4_2_A  61  // B1_14
	{1, M(4, 3), 1, 1},  // FlexPWM4_3_A  62  // B1_15
};


//=============================================================================
// SDRAM
//=============================================================================

#include <smalloc.h>

#ifdef __cplusplus
extern "C" {
#endif

struct smalloc_pool sdram_smalloc_pool;

#ifdef __cplusplus
}
#endif

// default = 166MHz
#define SDRAM_CLOCK 133
// default base address
#define SDRAM_BASE 0x80000000
// default SDRAM size (in MBs)
#define SDRAM_SIZE 32
// Dev board with no capacitor on pin EMC_39
#define SDRAM_USEDQS 1

uint8_t _size = 0;
    
unsigned int ns_to_clocks(float ns, float freq)
{
    float clocks = ceilf(ns * 1.0e-9f * freq);
    if (clocks < 1.0f) return 1;
    return (unsigned int)clocks;
}

void configure_sdram_pins()
{
	// initialize pins
    IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_00 = 0x0110F9;   //SEMC_D0
                                                /* Slew Rate Field: Fast Slew Rate
                                                 Drive Strength Field: R0/7
                                                 Speed Field: max(200MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Enabled */
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_01 = 0x0110F9;   //SEMC_D0
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_02 = 0x0110F9;   //SEMC_D1
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_03 = 0x0110F9;   //SEMC_D2
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_04 = 0x0110F9;   //SEMC_D3
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_05 = 0x0110F9;   //SEMC_D4
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_06 = 0x0110F9;   //SEMC_D5
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_07 = 0x0110F9;   //SEMC_D6
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_08 = 0x0110F9;   //SEMC_DMO
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_09 = 0x0110F9;   //SEMC_A0 // edited
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_10 = 0x0110F9;   //SEMC_A1
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_11 = 0x0110F9;   //SEMC_A2
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_12 = 0x0110F9;   //SEMC_A3
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_13 = 0x0110F9;   //SEMC_A4
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_14 = 0x0110F9;   //SEMC_A5
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_15 = 0x0110F9;   //SEMC_A6
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_16 = 0x0110F9;   //SEMC_A7
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_17 = 0x0110F9;   //SEMC_A8
    
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_18 = 0x0110F9;   //SEMC_A9
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_19 = 0x0110F9;   //SEMC_A11
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_20 = 0x0110F9;   //SEMC_A12
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_21 = 0x0110F9;   //SEMC_BA0
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_22 = 0x0110F9;   //SEMC_BA1
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_23 = 0x0110F9;   //SEMC_A10
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_24 = 0x0110F9;   //SEMC_CAS
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_25 = 0x0110F9;   //SEMC_RAS
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_26 = 0x0110F9;   //SEMC_CLK
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_27 = 0x0110F9;   //SEMC_CKE
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_28 = 0x0110F9;   //SEMC_WE
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_29 = 0x0110F9;   //SEMC_CS0
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_30 = 0x0110F9;   //SEMC_D8
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_31 = 0x0110F9;   //SEMC_D9
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_32 = 0x0110F9;   //SEMC_D10
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_33 = 0x0110F9;   //SEMC_D11
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_34 = 0x0110F9;   //SEMC_D12
    
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_35 = 0x0110F9;   //SEMC_D13
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_36 = 0x0110F9;   //SEMC_D14
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_37 = 0x0110F9;   //SEMC_D15
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_38 = 0x0110F9;   //SEMC_DM1
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_39 = 0x0110F9;   //SEMC_DQS
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_40 = 0x0110F9;   //SEMC_MD0
	IOMUXC_SW_PAD_CTL_PAD_GPIO_EMC_41 = 0x0110F9;   //SEMC_MD1

// configure pins
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_00 = 0x10;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_01 = 0x10;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_02 = 0x10;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_03 = 0x10;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_04 = 0x10;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_05 = 0x10;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_06 = 0x10;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_07 = 0x10;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_08 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_09 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_10 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_11 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_12 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_13 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_14 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_15 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_16 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_17 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_18 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_19 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_20 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_21 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_22 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_23 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_24 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_25 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_26 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_27 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_28 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_29 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_30 = 0x10;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_31 = 0x10;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_32 = 0x10;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_33 = 0x10;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_34 = 0x10;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_35 = 0x10;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_36 = 0x10;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_37 = 0x10;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_38 = 0;
  IOMUXC_SW_MUX_CTL_PAD_GPIO_EMC_39 = 0x10;

}

bool IPCommandComplete()
{
    /* Poll status bit till command is done*/
    while (!(SEMC_INTR & 0x1))
    {
    };

    /* Clear status bit */
    SEMC_INTR |= 0x1;

    /* Check error status */
    if (SEMC_INTR & 0x2)
    {
        SEMC_INTR |= 0x2;
        return false;
    }

    return true;
}


bool SendIPCommand(uint32_t address, uint16_t command, uint32_t write, uint32_t *read)
{
    uint32_t cmdMode;
    bool readCmd = 0;
    bool writeCmd = 0;

    /* Clear status bit */
    SEMC_INTR |= 0x1U;
    /* Set address. */
    SEMC_IPCR0= address;

    /* Check command mode. */
    cmdMode = command & 0xFU;

    readCmd = (cmdMode == 0x08);    /*  SDRAM memory read. */
    writeCmd = (cmdMode == 0x09) || (cmdMode == 0x0a);  /* SDRAM memory write, SDRAM MODE SET */

    if (writeCmd)
    {
        /* Set data. */
        SEMC_IPTXDAT = write;
    }

    /* Set command code. */
    SEMC_IPCMD = command | (((uint32_t)(((uint32_t)(0xA55A)) << 16)) & 0xFFFF0000U);
    
    /* Wait for command done. */
    bool result = IPCommandComplete();

    if (result != true)
    {
        return result;
    }

    if (readCmd)
    {
        /* Get the read data */
        *read = SEMC_IPRXDAT;
    }

    return true;
}

bool  check_fixed_pattern(uint32_t pattern)
{
	volatile uint32_t *p;
    uint32_t *memory_begin, *memory_end;
    memory_begin = (uint32_t *)(0x80000000);
	memory_end = (uint32_t *)(0x80000000 + _size * 1048576);
    
	//Serial.printf("testing with fixed pattern %08X\n", pattern);
	for (p = memory_begin; p < memory_end; p++) {
		*p = pattern;
	}
	arm_dcache_flush_delete((void *)memory_begin,
		(uint32_t)memory_end - (uint32_t)memory_begin);
	for (p = memory_begin; p < memory_end; p++) {
		uint32_t actual = *p;
		if (actual != pattern) return false;
	}
	return true;
}

bool begin(uint8_t external_sdram_size, uint8_t clock, uint8_t useDQS)
{
    _size = external_sdram_size;
    uint8_t _clock = 0;
    
    if(clock > 221 || clock < 133) return false;
    
    switch(clock) {
        case 133:
            _clock = 5;
            break;
        case 166:
            _clock = 4;
            break;
        case 221:
            _clock = 3;
            break;
        case 198:
            _clock = 2;
            break;
        default:
            _clock = 4;
            break;
    }
            
    const unsigned int clockdiv = _clock;
    //Serial.printf("Clock set at: %d\n", clockdiv);
        
    /* Experimental note (see https://forum.pjrc.com/index.php?threads/call-to-arms-teensy-sdram-true.73898/post-335619):
    *  if you want to try 198 MHz overclock
    *  const unsigned int clockdiv = 2; // PLL2_PFD2 / 2 = 396 / 2 = 198 MHz
    */
    if(clockdiv == 2) {
        CCM_CBCDR = (CCM_CBCDR & ~(CCM_CBCDR_SEMC_PODF(7) | CCM_CBCDR_SEMC_ALT_CLK_SEL)) |
        CCM_CBCDR_SEMC_CLK_SEL | CCM_CBCDR_SEMC_PODF(clockdiv-1);  
    /* If it doesn't work, maybe try soldering a 5pF or 10pF capacitor at C29 
    */
    } else {
    // use PLL3 PFD1 664.62 divided by 4 or 5, for 166 or 133 MHz
    // 5 = 133mhz
    // 4 = 166mhz - SDRAM rated,  see post #60
    // 3 = 221mhz
        CCM_CBCDR = (CCM_CBCDR & ~(CCM_CBCDR_SEMC_PODF(7))) |
            CCM_CBCDR_SEMC_CLK_SEL | CCM_CBCDR_SEMC_ALT_CLK_SEL |
            CCM_CBCDR_SEMC_PODF(clockdiv-1);
    }
    
    delayMicroseconds(1);
    const float freq = 664.62e6 / (float)clockdiv;
    CCM_CCGR3 |= CCM_CCGR3_SEMC(CCM_CCGR_ON);
    
    // software reset
    SEMC_BR0 = 0;
    SEMC_BR1 = 0;
    SEMC_BR2 = 0;
    SEMC_BR3 = 0;
    SEMC_BR4 = 0;
    SEMC_BR5 = 0;
    SEMC_BR6 = 0;
    SEMC_BR7 = 0;
    SEMC_BR8 = 0;
    SEMC_MCR = SEMC_MCR_SWRST;
	uint32_t timeout = micros();
	while (SEMC_MCR & SEMC_MCR_SWRST)
	{
		if (micros() - timeout > 1500)
		{
			return false;
		}
	}
    configure_sdram_pins();

    if(useDQS == 1) {
        SEMC_MCR |= SEMC_MCR_MDIS | SEMC_MCR_CTO(0xFF) | SEMC_MCR_BTO(0x1F) | SEMC_MCR_DQSMD;
    } else  { // enable SEMC_MCR_DQSMD (EMC_39
        SEMC_MCR |= SEMC_MCR_MDIS | SEMC_MCR_CTO(0xFF) | SEMC_MCR_BTO(0x1F);
    }

    // TODO: reference manual page 1364 says "Recommend to set BMCR0 with 0x0 for
    // applications that require restrict sequence of transactions", same on BMCR1
    SEMC_BMCR0 = SEMC_BMCR0_WQOS(5) | SEMC_BMCR0_WAGE(8) |
        SEMC_BMCR0_WSH(0x40) | SEMC_BMCR0_WRWS(0x10);
    SEMC_BMCR1 = SEMC_BMCR1_WQOS(5) | SEMC_BMCR1_WAGE(8) |
        SEMC_BMCR1_WPH(0x60) | SEMC_BMCR1_WRWS(0x24) | SEMC_BMCR1_WBR(0x40);

    SEMC_MCR &= ~SEMC_MCR_MDIS;

    // configure SDRAM parameters
    SEMC_BR0 = SDRAM_BASE | SEMC_BR_MS(13 /*13 = 32 Mbyte*/) | SEMC_BR_VLD;
    SEMC_SDRAMCR0 = SEMC_SDRAMCR0_CL(3) |
        SEMC_SDRAMCR0_COL(3) |  // 3 = 9 bit column
        SEMC_SDRAMCR0_BL(3) |   // 3 = 8 word burst length
        SEMC_SDRAMCR0_PS;       // use 16 bit data
    SEMC_SDRAMCR1 =
        SEMC_SDRAMCR1_ACT2PRE((ns_to_clocks(42, freq)-1)) | // tRAS: ACTIVE to PRECHARGE
        SEMC_SDRAMCR1_CKEOFF((ns_to_clocks(42, freq)-1)) |  // self refresh
        SEMC_SDRAMCR1_WRC((ns_to_clocks(12, freq)-1)) |     // tWR: WRITE recovery
        SEMC_SDRAMCR1_RFRC((ns_to_clocks(67, freq)-1)) |    // tRFC or tXSR: REFRESH recovery
        SEMC_SDRAMCR1_ACT2RW((ns_to_clocks(18, freq)-1)) |  // tRCD: ACTIVE to READ/WRITE
        SEMC_SDRAMCR1_PRE2ACT((ns_to_clocks(18, freq)-1));  // tRP: PRECHARGE to ACTIVE/REFRESH
    SEMC_SDRAMCR2 = 0; // TODO... page 1425
    SEMC_SDRAMCR3 = 0; // TODO...page 1426
    SEMC_SDRAMCR2 =
        SEMC_SDRAMCR2_SRRC((ns_to_clocks(67, freq) - 1)) |
        SEMC_SDRAMCR2_REF2REF(ns_to_clocks(60, freq)) |           /* No Minus one to keep with RM */
        SEMC_SDRAMCR2_ACT2ACT(ns_to_clocks(60, freq)) | /* No Minus one to keep with RM */
        SEMC_SDRAMCR2_ITO(0);  //sdk has: idle = config->tIdleTimeout_Ns / config->tPrescalePeriod_Ns


    uint32_t prescaleperiod = 160 * (1000000000 / freq);
    uint16_t prescale = prescaleperiod / 16 / (1000000000 / freq);

    if (prescale > 256)
    {
        //Serial.println("Invalid Timer Setting");
        while(1){}
    }

    uint16_t refresh = (64 * 1000000 / 8192)/ prescaleperiod;
    uint16_t urgentRef = refresh;
    //uint16_t idle = 0 / prescaleperiod;
    
    SEMC_SDRAMCR3 = SEMC_SDRAMCR3_REBL((1 - 1)) |
                     /* N * 16 * 1s / clkSrc_Hz = config->tPrescalePeriod_Ns */
                     SEMC_SDRAMCR3_PRESCALE(prescale) | SEMC_SDRAMCR3_RT(refresh) | SEMC_SDRAMCR3_UT(urgentRef);

    SEMC_IPCR1 = 2; // IP commadns, data is 16 bits wide
    SEMC_IPCR2 = 0;

    //  send IP commands to initialize SDRAM chip:
    //  precharge all
    //  auto refresh (NXP SDK sends this twice, why?)
    //  mode set
    bool result_cmd = SendIPCommand(SDRAM_BASE, 0x0f, 0, NULL);  //Prechargeall
    if (result_cmd != true)
    {
        return result_cmd;
    }
    result_cmd = SendIPCommand(SDRAM_BASE, 0x0c, 0, NULL);        //AutoRefresh
    if (result_cmd != true)
    {
        return result_cmd;
    }
    result_cmd = SendIPCommand(SDRAM_BASE, 0x0c, 0, NULL);         //AutoRefresh
    if (result_cmd != true)
    {
        return result_cmd;
    }
    /* Mode setting value. */
    uint16_t mode = (uint16_t)3| (uint16_t)(3 << 4);
    result_cmd = SendIPCommand(SDRAM_BASE, 0x0a, mode, NULL);       //Modeset
    if (result_cmd != true)
    {
        return result_cmd;
    }
    // enable refresh
    SEMC_SDRAMCR3 |= SEMC_SDRAMCR3_REN;

    if(result_cmd == false) return false;
    
    sm_set_pool(&sdram_smalloc_pool, (void *)SDRAM_BASE, external_sdram_size * 1024 *1024, 1, NULL);

    if(!check_fixed_pattern(0x5A698421))
        return false;


    return true; // hopefully SDRAM now working at 80000000 to 81FFFFFF
}

void startup_middle_hook(void)
{
    begin(SDRAM_SIZE, SDRAM_CLOCK, SDRAM_USEDQS);

}

#include <stdlib.h>
#include "wiring.h"
#define IS_SDRAM(addr) (((uint32_t)addr >> 28) == 8)

void *sdram_malloc(size_t size)
{
    void *ptr = sm_malloc_pool(&sdram_smalloc_pool, size);
    if (ptr) return ptr;
    return malloc(size);
}

void sdram_free(void *ptr)
{
    if (IS_SDRAM(ptr)) {
        sm_free_pool(&sdram_smalloc_pool, ptr);
        return;
    }
    free(ptr);
}

void *sdram_calloc(size_t nmemb, size_t size)
{
    // Note: It is assumed that the pool was created with do_zero set to true
    void *ptr = sm_malloc_pool(&sdram_smalloc_pool, nmemb*size);
    if (ptr) return ptr;
    return calloc(nmemb, size);
}

void *sdram_realloc(void *ptr, size_t size)
{
    if (IS_SDRAM(ptr)) {
        return sm_realloc_pool(&sdram_smalloc_pool, ptr, size);
    }
    return realloc(ptr, size);
}

