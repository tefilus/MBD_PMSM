/*
 * File: ToLCD.h
 *
 * Code generated for Simulink model 'sixstep_f28069mLaunchPad_closeLoop'.
 *
 * Model version                  : 7.154
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Jul 13 00:02:47 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ToLCD_h_
#define RTW_HEADER_ToLCD_h_
#ifndef sixstep_f28069mLaunchPad_closeLoop_COMMON_INCLUDES_
#define sixstep_f28069mLaunchPad_closeLoop_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Gpio.h"
#include "DSP28xx_SciUtil.h"
#include "F2806x_Examples.h"
#include "IQmathLib.h"
#include "MW_SPI.h"
#endif                 /* sixstep_f28069mLaunchPad_closeLoop_COMMON_INCLUDES_ */

/* Block signals for system '<Root>/ToLCD' */
typedef struct {
  real32_T dataLogging_Speed;          /* '<S203>/dataLogging_Speed' */
  real32_T dataLogging_Idc;            /* '<S203>/dataLogging_Idc' */
  uint16_T convertTo_uint16[2];        /* '<S205>/convertTo_uint16' */
  uint16_T dataWidth;                  /* '<S203>/dataWidth' */
  uint16_T SCI_Tx_Data[3];             /* '<S203>/mergeDataOut' */
  uint16_T SCI_Tx_Iteration;           /* '<S203>/mergeInteration' */
  uint16_T Data[2];                    /* '<S204>/Data' */
  uint16_T Data_f[2];                  /* '<S206>/Data' */
  uint16_T Data_fw[2];                 /* '<S207>/Data' */
  uint16_T indexVector;                /* '<S202>/indexVector' */
  uint16_T add;                        /* '<S202>/add' */
  int16_T convertTo_sfix16_En12[2];    /* '<S205>/convertTo_sfix16_En12' */
  int16_T whileIterator;               /* '<S202>/whileIterator' */
  uint16_T Output;                     /* '<S208>/Output' */
  uint16_T FixPtSum1;                  /* '<S209>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S210>/FixPt Switch' */
} rtB_ToLCD_sixstep_f28069mLaunch;

/* Block states (default storage) for system '<Root>/ToLCD' */
typedef struct {
  uint16_T add_DWORK1;                 /* '<S202>/add' */
  uint16_T Output_DSTATE;              /* '<S208>/Output' */
} rtDW_ToLCD_sixstep_f28069mLaunc;

extern void sixstep_f28069mL_ToLCD_Init(rtB_ToLCD_sixstep_f28069mLaunch *localB);
extern void sixstep_f28069mLaunch_ToLCD(const real32_T *rtd_idcSCI_B, const
  real32_T *rtd_speedSCI_B, rtB_ToLCD_sixstep_f28069mLaunch *localB,
  rtDW_ToLCD_sixstep_f28069mLaunc *localDW);

#endif                                 /* RTW_HEADER_ToLCD_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
