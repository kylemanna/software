//----------------------------------------------------------------------------
//      _____
//     *     *
//    *____   *____
//   * *===*   *==*
//  *___*===*___**  AVNET
//       *======*
//        *====*
//----------------------------------------------------------------------------
//
// This design is the property of Avnet.  Publication of this
// design is not authorized without written consent from Avnet.
//
// Please direct any questions to the PicoZed community support forum:
//    http://www.picozed.org/forum
//
// Product information is available at:
//    http://www.picozed.org/product/picozed
//
// Disclaimer:
//    Avnet, Inc. makes no warranty for the use of this code or design.
//    This code is provided  "As Is". Avnet, Inc assumes no responsibility for
//    any errors, which may appear in this code, nor does it make a commitment
//    to update the information contained herein. Avnet, Inc specifically
//    disclaims any implied warranties of fitness for a particular purpose.
//                     Copyright(c) 2013 Avnet, Inc.
//                             All rights reserved.
//
//----------------------------------------------------------------------------
//
// Create Date:         Jun 24, 2013
// Design Name:         PicoZed FMC2 FMC Loopback Test
// Module Name:         platform.h
// Project Name:        PicoZed FMC2 FMC Loopback Test
// Target Devices:      Xilinx Zynq-7000
// Hardware Boards:     PicoZed, PicoZed FMC2 Carrier
//
// Tool versions:       Xilinx Vivado 2015.2
//
// Description:         Programmable logic hardware platform definitions file.
//
// Dependencies:
//
// Revision:            Jun 24, 2013: 1.00 Initial version
//
//----------------------------------------------------------------------------


#ifndef PLATFORM_H_
#define PLATFORM_H_

/*
 * Define the AXI locations for all the PL GPIO blocks used for the FMC
 * loopback tests.  These come from xparameters.h in the standalone BSP or
 * from the AXI address defined in XPS and these may need to get updated
 * everytime this test gets ported to a new platform.
 */
#define FMC1_LPC_SE_HIGH_DEVICE_ADDRESS    0x41200000
#define FMC1_LPC_SE_LOW_DEVICE_ADDRESS     0x41210000
//#define FMC2_LPC_SE_HIGH_DEVICE_ADDRESS    0x41300000
//#define FMC2_LPC_SE_LOW_DEVICE_ADDRESS     0x41300000

#define CONFIG_DEFAULT_MMAP_MIN_ADDR   4096

#endif // PLATFORM_H_