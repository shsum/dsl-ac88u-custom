/***************************************************************************
*    Copyright (c) 2000-2013 Broadcom                             
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
*       BCM6838                          
*       SLIC = Silicon Labs Si32392      
*       R1 = 600 ohms
*       R2 = 0 ohms
*       C1 = 0 nano Farads 
*       DLP = -4dB
*       ELP = -2dB
*       HWDACgain = 0dB
*       HW_impedance = 680 ohms
*       Protection resistor = 10 ohms
*       Ringing frequency = 20 hertz
*       Ringing amplitude = 45Vrms
*
*    Flexicalc Version: 3.8
*
****************************************************************************/

#ifndef FLEXICALC_NEW_ZEALAND_32392_H
#define FLEXICALC_NEW_ZEALAND_32392_H

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************
** Flexicalc Values Structure                                              **
****************************************************************************/

#if !VRG_COUNTRY_CFG_NEW_ZEALAND
#define flexicalcNEW_ZEALANDArchive32392 ((const APM6838_FLEXICALC_CFG*) NULL)
#else
const APM6838_FLEXICALC_CFG flexicalcNEW_ZEALANDArchive32392[] =
{
{
   0x32392,          /* Slic type: Si32392 */
   45,               /* Ring Voltage (RMS) */
   -4,               /* DLP - Decode Level Point (receive loss) in dB */
   -2,               /* ELP - Encode Level Point (transmitt loss) in dB */
   0x0007,           /* eq_rx_shft */
   0x000A,           /* eq_tx_shft */
   0,                /* eq_imp_resp */

   /*
   ** Y-filter Coefficients
   */
   1,                /* yfltr_en */
   {  /* IIR 2 Filter Coefficients */
      0x16860,   /* Y IIR2 filter b0 */
      0x28E0B,   /* Y IIR2 filter b1 */
      0x16860,   /* Y IIR2 filter b2 */
      0x4A22B,   /* Y IIR2 filter a1 */
      0xDFB13    /* Y IIR2 filter a2 */
   },
   0x66,             /* y_iir2_filter_shift */
   {  /* Fir Filter Coefficients */
      0x9FEF8,   /* YFIR1_VAL */
      0x2F770,   /* YFIR2_VAL */
      0xFF386,   /* YFIR3_VAL */
      0x11671,   /* YFIR4_VAL */
      0x3246E,   /* YFIR5_VAL */
      0xD15AB,   /* YFIR6_VAL */
      0x0E445,   /* YFIR7_VAL */
      0xF6E13,   /* YFIR8_VAL */
      0xDD845,   /* YFIR9_VAL */
      0x1808A,   /* YFIR10_VAL */
      0xFC64B,   /* YFIR11_VAL */
      0xFBF49,   /* YFIR12_VAL */
      0x1B688,   /* YFIR13_VAL */
      0xF1B38,   /* YFIR14_VAL */
      0x00411,   /* YFIR15_VAL */
      0x03351,   /* YFIR16_VAL */
      0xF2D25,   /* YFIR17_VAL */
      0x06D68    /* YFIR18_VAL */
   },
   0x05,               /* y_fir_filter_shift */
   0x7FFFF,            /* yfltr_gain */
   {0x9C48A},          /* y_iir1_filter[1] */
   0x76,               /* y_iir1_filter_shift */

   /* Hybrid Balance Coefficients */
   5,                  /* hybal_shft */
   {0xCB14, 0x149F, 0xFCAB, 0xBD1A, 0x2977},    /* hybal_audio_fir[5] */
   {0x0000, 0x0000, 0x0000, 0x0000, 0x0000},    /* hybal_pm_fir[5] */
   1,                  /* hybal_en */

   {  /* Rx Equalization Coefficents */
      0x7E98, 0xFDF3, 0xFDE9, 0xFDC3, 0xFDE9, 0xFE03, 0xFE1F, 0xFE3C,
      0xFE66, 0xFE88, 0xFEA8, 0xFECD, 0xFEF0, 0xFF0E, 0xFF32, 0xFF4F,
      0xFF66, 0xFF7C, 0xFF94, 0xFFA1, 0xFFA8, 0xFFB5, 0xFFBE, 0xFFC0,
      0xFFC4, 0xFFC9, 0xFFC8, 0xFFC8, 0xFFCE, 0xFFCE, 0xFFCD, 0xFFD3,
      0xFFD9, 0xFFDB, 0xFFE1, 0xFFE7, 0xFFEA, 0xFFEF, 0xFFF6, 0xFFF9,
      0xFFFB, 0x0004, 0x0004, 0x0003, 0x0003, 0x0003, 0x0002, 0x0002,
      0x0002, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001,
      0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
   },

   {  /* Tx Equalization Coefficents */
      0x7F29, 0xFEEF, 0xFEE2, 0xFEBA, 0xFED5, 0xFEE0, 0xFEF4, 0xFF09,
      0xFF1C, 0xFF32, 0xFF46, 0xFF5C, 0xFF70, 0xFF81, 0xFF95, 0xFFA2,
      0xFFB2, 0xFFBB, 0xFFC7, 0xFFCE, 0xFFD2, 0xFFD7, 0xFFD9, 0xFFDC,
      0xFFDC, 0xFFDF, 0xFFE0, 0xFFE2, 0xFFE3, 0xFFE5, 0xFFE7, 0xFFE8,
      0xFFEB, 0xFFED, 0xFFF0, 0xFFF2, 0xFFF5, 0xFFF8, 0xFFFA, 0xFFFD,
      0xFFFD, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0001, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
   },

   0x0003,           /* cic_int_shft */
   0x0004,           /* cic_dec_shft */
   0x48D5,           /* asrc_int_scale */
   0x1438,           /* asrc_dec_scale */
   0,                /* vtx_pg */
   0,                /* vrx_pg */
   0,                /* hpf_en */
   3,                /* hybal_smpl_offset */

}
};
#endif

#ifdef __cplusplus
}
#endif

#endif  /* FLEXICALC_NEW_ZEALAND_32392_H */
