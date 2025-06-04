/*
 * File: To_LCD.h
 *
 * Code generated for Simulink model 'mcb_bldc_sixstep_f28069mLaunchPad_closeLoop'.
 *
 * Model version                  : 7.91
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed May 21 10:53:04 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_To_LCD_h_
#define RTW_HEADER_To_LCD_h_
#ifndef mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_COMMON_INCLUDES_
#define mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Gpio.h"
#include "DSP28xx_SciUtil.h"
#include "F2806x_Examples.h"
#include "IQmathLib.h"
#include "MW_SPI.h"
#endif        /* mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_COMMON_INCLUDES_ */

/* Block signals for system '<Root>/To_LCD' */
typedef struct {
  real32_T dataLogging_Speed;          /* '<S200>/dataLogging_Speed' */
  uint16_T convertTo_uint16;           /* '<S203>/convertTo_uint16' */
  uint16_T dataWidth;                  /* '<S200>/dataWidth' */
  uint16_T SCI_Tx_Data[2];             /* '<S200>/mergeDataOut' */
  uint16_T SCI_Tx_Iteration;           /* '<S200>/mergeInteration' */
  uint16_T indexVector;                /* '<S201>/indexVector' */
  uint16_T add;                        /* '<S201>/add' */
  uint16_T Data;                       /* '<S202>/Data' */
  uint16_T Data_f;                     /* '<S204>/Data' */
  uint16_T Data_fw;                    /* '<S205>/Data' */
  int16_T convertTo_sfix16_En12;       /* '<S203>/convertTo_sfix16_En12' */
  int16_T whileIterator;               /* '<S201>/whileIterator' */
  uint16_T Output;                     /* '<S206>/Output' */
  uint16_T FixPtSum1;                  /* '<S207>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S208>/FixPt Switch' */
} rtB_To_LCD_mcb_bldc_sixstep_f28;

/* Block states (default storage) for system '<Root>/To_LCD' */
typedef struct {
  uint16_T add_DWORK1;                 /* '<S201>/add' */
  uint16_T Output_DSTATE;              /* '<S206>/Output' */
} rtDW_To_LCD_mcb_bldc_sixstep_f2;

extern void mcb_bldc_sixste_To_LCD_Init(rtB_To_LCD_mcb_bldc_sixstep_f28 *localB);
extern void mcb_bldc_sixstep_f28_To_LCD(const real32_T *rtd_speedSCI_B,
  rtB_To_LCD_mcb_bldc_sixstep_f28 *localB, rtDW_To_LCD_mcb_bldc_sixstep_f2
  *localDW);

#endif                                 /* RTW_HEADER_To_LCD_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
