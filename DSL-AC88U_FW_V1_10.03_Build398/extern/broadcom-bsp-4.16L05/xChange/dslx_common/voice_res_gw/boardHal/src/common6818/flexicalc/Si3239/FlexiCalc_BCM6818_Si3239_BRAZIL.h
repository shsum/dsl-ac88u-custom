/***************************************************************************
*    Copyright (c) 2000-2011 Broadcom                             
*                                                                           
*    This program is the proprietary software of Broadcom and/or
*    its licensors, and may only be used, duplicated, modified or           
*    distributed pursuant to the terms and conditions of a separate, written
*    license agreement executed between you and Broadcom (an Authorized     
*    License).  Except as set forth in an Authorized License, Broadcom      
*    grants no license (express or implied), right to use, or waiver of any 
*    kind with respect to the Software, and Broadcom expressly reserves all 
*    rights in and to the Software and all intellectual property rights     
*    therein.  IF YOU HAVE NO AUTHORIZED LICENSE, THEN YOU HAVE NO RIGHT TO 
*    USE THIS SOFTWARE IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY BROADCOM   
*    AND DISCONTINUE ALL USE OF THE SOFTWARE.                               
*                                                                           
*                                                                           
*    Except as expressly set forth in the Authorized License,               
*                                                                           
*    1.     This program, including its structure, sequence and             
*    organization, constitutes the valuable trade secrets of Broadcom, and  
*    you shall use all reasonable efforts to protect the confidentiality    
*    thereof, and to use this information only in connection with your use  
*    of Broadcom integrated circuit products.                               
*                                                                           
*    2.     TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED
*    AS IS AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES,              
*    REPRESENTATIONS OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR  
*    OTHERWISE, WITH RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY        
*    DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY,    
*    NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES,    
*    ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR         
*    CORRESPONDENCE TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING OUT  
*    OF USE OR PERFORMANCE OF THE SOFTWARE.                                 
*                                                                           
*    3.     TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL       
*    BROADCOM OR ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL, 
*    SPECIAL, INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR IN
*    ANY WAY RELATING TO YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN  
*    IF BROADCOM HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES; OR    
*    (ii) ANY AMOUNT IN EXCESS OF THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE 
*    ITSELF OR U.S. $1, WHICHEVER IS GREATER. THESE LIMITATIONS SHALL APPLY 
*    NOTWITHSTANDING ANY FAILURE OF ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.
*
****************************************************************************
*
*    Filename: FlexiCalc.h
*
****************************************************************************
*    Description:
*
*    FlexiCalc output constants for the following inputs:
*
*       BCM6818                          
*       SLIC = Silicon Labs Si3239       
*       R1 = 270 ohms
*       R2 = 750 ohms
*       C1 = 150 nano Farads 
*       DLP = -11dB
*       ELP = -4dB
*       HWDACgain = 0dB
*       HW_impedance = 680 ohms
*       Protection resistor = 10 ohms
*       Ringing frequency = 25 hertz
*       Ringing amplitude = 45Vrms
*
*    Flexicalc Version: 3.3
*
****************************************************************************/

#ifndef FLEXICALC_BRAZIL_3239_H
#define FLEXICALC_BRAZIL_3239_H

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************
** Flexicalc Values Structure                                              **
****************************************************************************/

#if !VRG_COUNTRY_CFG_BRAZIL
#define flexicalcBRAZILArchive3239 ((const APM6818_FLEXICALC_CFG*) NULL)
#else
const APM6818_FLEXICALC_CFG flexicalcBRAZILArchive3239[] =
{
{
   0x3239,           /* Slic type: Si3239 */
   45,               /* Ring Voltage (RMS) */
   -11,               /* DLP - Decode Level Point (receive loss) in dB */
   -4,               /* ELP - Encode Level Point (transmitt loss) in dB */
   0x0007,           /* eq_rx_shft */
   0x000B,               /* eq_tx_shft */
   0,               /* eq_imp_resp */

   /*
   ** Y-filter Coefficients
   */
   1,               /* yfltr_en */
   {  /* IIR 2 Filter Coefficients */
      0x04966,   /* Y IIR2 filter b0 */
      0x061FA,   /* Y IIR2 filter b1 */
      0x04966,   /* Y IIR2 filter b2 */
      0x4E1DC,   /* Y IIR2 filter a1 */
      0xE28AB    /* Y IIR2 filter a2 */
   },
   0x77,               /* y_iir2_filter_shift */
   {  /* Fir Filter Coefficients */
      0x23150,   /* YFIR1_VAL */
      0xBBCC9,   /* YFIR2_VAL */
      0x14243,   /* YFIR3_VAL */
      0x18C0E,   /* YFIR4_VAL */
      0xFCB04,   /* YFIR5_VAL */
      0xEE86C,   /* YFIR6_VAL */
      0xF9396,   /* YFIR7_VAL */
      0x08DBA,   /* YFIR8_VAL */
      0x09F3C,   /* YFIR9_VAL */
      0xFEB76,   /* YFIR10_VAL */
      0xF7948,   /* YFIR11_VAL */
      0xFD1EB,   /* YFIR12_VAL */
      0x06969,   /* YFIR13_VAL */
      0x06516,   /* YFIR14_VAL */
      0xFC988,   /* YFIR15_VAL */
      0xF923B,   /* YFIR16_VAL */
      0x07DFD,   /* YFIR17_VAL */
      0xFC18B    /* YFIR18_VAL */
   },
   0x06,               /* y_fir_filter_shift */
   0x7FFFF,               /* yfltr_gain */
   {0x49421},          /* y_iir1_filter[1] */
   0xA6,               /* y_iir1_filter_shift */

   /* Hybrid Balance Coefficients */
   7,               /* hybal_shft */
   {0x3C72, 0xA126, 0x5FD0, 0x8329, 0x4BFB},    /* hybal_audio_fir[5] */
   {0x0000, 0x0000, 0x0000, 0x0000, 0x0000},    /* hybal_pm_fir[5] */
   1,               /* hybal_en */

   {  /* Rx Equalization Coefficents */
      0x560E, 0xD5FE, 0x07FD, 0xFA6B, 0x01B1, 0xFE20, 0x0053, 0xFEE3,
      0x0004, 0xFF33, 0xFFEB, 0xFF6E, 0xFFE9, 0xFF93, 0xFFF0, 0xFFB1,
      0xFFF6, 0xFFC5, 0xFFFF, 0xFFD2, 0xFFFD, 0xFFE0, 0x0003, 0xFFE0,
      0xFFFD, 0xFFE8, 0xFFFC, 0xFFE9, 0xFFFF, 0xFFED, 0xFFFA, 0xFFF0,
      0xFFFD, 0xFFED, 0x0000, 0xFFF1, 0xFFFF, 0xFFF7, 0x0003, 0xFFF8,
      0x0004, 0x0000, 0x0001, 0x0000, 0x0001, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
   },

   {  /* Tx Equalization Coefficents */
      0x4226, 0xFA95, 0x00DD, 0xFE16, 0xFFD0, 0xFF67, 0xFFCF, 0xFF9C,
      0xFFD0, 0xFFB5, 0xFFD4, 0xFFC7, 0xFFDE, 0xFFD6, 0xFFE9, 0xFFE0,
      0xFFF2, 0xFFE9, 0xFFF7, 0xFFEE, 0xFFF8, 0xFFF4, 0xFFFB, 0xFFF5,
      0xFFFB, 0xFFF7, 0xFFF8, 0xFFF7, 0xFFFA, 0xFFF8, 0xFFFB, 0xFFF9,
      0xFFFC, 0xFFF9, 0xFFFE, 0xFFFB, 0xFFFE, 0xFFFD, 0x0000, 0xFFFE,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
   },

   0x0004,               /* cic_int_shft */
   0x0004,               /* cic_dec_shft */
   0x5F7B,           /* asrc_int_scale */
   0x0A44,           /* asrc_dec_scale */
   1,               /* vtx_pg */
   1,               /* vrx_pg */
   0,               /* hpf_en */
   6,               /* hybal_smpl_offset */

}
};
#endif

#ifdef __cplusplus
}
#endif

#endif  /* FLEXICALC_BRAZIL_3239_H */
