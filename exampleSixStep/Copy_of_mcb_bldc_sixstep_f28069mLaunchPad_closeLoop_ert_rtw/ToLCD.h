/*
 * File: ToLCD.h
 *
 * Code generated for Simulink model 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop'.
 *
 * Model version                  : 7.128
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu May 29 08:25:00 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ToLCD_h_
#define RTW_HEADER_ToLCD_h_
#ifndef Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_COMMON_INCLUDES_
#define Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Gpio.h"
#include "DSP28xx_SciUtil.h"
#include "F2806x_Examples.h"
#include "IQmathLib.h"
#include "MW_SPI.h"
#endif
      /* Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_COMMON_INCLUDES_ */

/* Block signals for system '<Root>/ToLCD' */
typedef struct {
  real32_T dataLogging_Speed;          /* '<S200>/dataLogging_Speed' */
  real32_T DataStoreRead;              /* '<S200>/Data Store Read' */
  uint16_T convertTo_uint16[2];        /* '<S203>/convertTo_uint16' */
  uint16_T dataWidth;                  /* '<S200>/dataWidth' */
  uint16_T SCI_Tx_Data[3];             /* '<S200>/mergeDataOut' */
  uint16_T SCI_Tx_Iteration;           /* '<S200>/mergeInteration' */
  uint16_T indexVector;                /* '<S201>/indexVector' */
  uint16_T add;                        /* '<S201>/add' */
  uint16_T Data[2];                    /* '<S202>/Data' */
  uint16_T Data_f[2];                  /* '<S204>/Data' */
  uint16_T Data_fw[2];                 /* '<S205>/Data' */
  int16_T convertTo_sfix16_En12[2];    /* '<S203>/convertTo_sfix16_En12' */
  int16_T whileIterator;               /* '<S201>/whileIterator' */
  uint16_T Output;                     /* '<S206>/Output' */
  uint16_T FixPtSum1;                  /* '<S207>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S208>/FixPt Switch' */
} rtB_ToLCD_Copy_of_mcb_bldc_sixs;

/* Block states (default storage) for system '<Root>/ToLCD' */
typedef struct {
  uint16_T add_DWORK1;                 /* '<S201>/add' */
  uint16_T Output_DSTATE;              /* '<S206>/Output' */
} rtDW_ToLCD_Copy_of_mcb_bldc_six;

extern void Copy_of_mcb_bldc_ToLCD_Init(rtB_ToLCD_Copy_of_mcb_bldc_sixs *localB);
extern void Copy_of_mcb_bldc_sixs_ToLCD(const real32_T *rtd_idcSCI_B, const
  real32_T *rtd_speedSCI_B, rtB_ToLCD_Copy_of_mcb_bldc_sixs *localB,
  rtDW_ToLCD_Copy_of_mcb_bldc_six *localDW);

#endif                                 /* RTW_HEADER_ToLCD_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
