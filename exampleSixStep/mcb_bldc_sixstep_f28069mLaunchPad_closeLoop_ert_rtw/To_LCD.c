/*
 * File: To_LCD.c
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

#include "To_LCD.h"
#include "rtwtypes.h"
#include "mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_private.h"

/* System initialize for atomic system: '<Root>/To_LCD' */
void mcb_bldc_sixste_To_LCD_Init(rtB_To_LCD_mcb_bldc_sixstep_f28 *localB)
{
  /* Start for Width: '<S200>/dataWidth' */
  localB->dataWidth = 1U;
}

/* Output and update for atomic system: '<Root>/To_LCD' */
void mcb_bldc_sixstep_f28_To_LCD(const real32_T *rtd_speedSCI_B,
  rtB_To_LCD_mcb_bldc_sixstep_f28 *localB, rtDW_To_LCD_mcb_bldc_sixstep_f2
  *localDW)
{
  int16_T s201_iter;

  /* UnitDelay: '<S206>/Output' */
  localB->Output = localDW->Output_DSTATE;

  /* DataStoreRead: '<S200>/dataLogging_Speed' */
  localB->dataLogging_Speed = *rtd_speedSCI_B;

  /* DataTypeConversion: '<S203>/convertTo_sfix16_En12' */
  localB->convertTo_sfix16_En12 = (int16_T)(localB->dataLogging_Speed * 4096.0F);

  /* DataTypeConversion: '<S203>/convertTo_uint16' incorporates:
   *  DataTypeConversion: '<S203>/convertTo_sfix16_En12'
   */
  localB->convertTo_uint16 = (uint16_T)localB->convertTo_sfix16_En12;

  /* If: '<S200>/indexCondition' incorporates:
   *  UnitDelay: '<S206>/Output'
   */
  if (localB->Output == 0U) {
    /* Outputs for IfAction SubSystem: '<S200>/Start' incorporates:
     *  ActionPort: '<S205>/Action Port'
     */
    /* SignalConversion generated from: '<S205>/Data' */
    localB->Data_fw = localB->convertTo_uint16;

    /* Merge: '<S200>/mergeDataOut' incorporates:
     *  Constant: '<S205>/End'
     *  SignalConversion generated from: '<S205>/Data_out'
     */
    localB->SCI_Tx_Data[0] = 21331U;
    localB->SCI_Tx_Data[1] = localB->Data_fw;

    /* Merge: '<S200>/mergeInteration' incorporates:
     *  Bias: '<S205>/Bias'
     */
    localB->SCI_Tx_Iteration = localB->dataWidth + 1U;

    /* End of Outputs for SubSystem: '<S200>/Start' */
  } else if (localB->Output == 2U) {
    /* Outputs for IfAction SubSystem: '<S200>/End' incorporates:
     *  ActionPort: '<S204>/Action Port'
     */
    /* SignalConversion generated from: '<S204>/Data' */
    localB->Data_f = localB->convertTo_uint16;

    /* Merge: '<S200>/mergeDataOut' incorporates:
     *  Constant: '<S204>/Start'
     *  SignalConversion generated from: '<S204>/Data_out'
     */
    localB->SCI_Tx_Data[0] = localB->Data_f;
    localB->SCI_Tx_Data[1] = 17733U;

    /* Merge: '<S200>/mergeInteration' incorporates:
     *  Bias: '<S204>/Bias'
     */
    localB->SCI_Tx_Iteration = localB->dataWidth + 1U;

    /* End of Outputs for SubSystem: '<S200>/End' */
  } else {
    /* Outputs for IfAction SubSystem: '<S200>/Data' incorporates:
     *  ActionPort: '<S202>/Action Port'
     */
    /* SignalConversion generated from: '<S202>/Data' */
    localB->Data = localB->convertTo_uint16;

    /* Merge: '<S200>/mergeDataOut' incorporates:
     *  Constant: '<S202>/Start'
     *  SignalConversion generated from: '<S202>/Data_out'
     */
    localB->SCI_Tx_Data[0] = localB->Data;
    localB->SCI_Tx_Data[1] = 0U;

    /* Merge: '<S200>/mergeInteration' incorporates:
     *  SignalConversion generated from: '<S202>/Data_width'
     */
    localB->SCI_Tx_Iteration = localB->dataWidth;

    /* End of Outputs for SubSystem: '<S200>/Data' */
  }

  /* End of If: '<S200>/indexCondition' */

  /* Outputs for Iterator SubSystem: '<S5>/SCI_Tx_codegen' incorporates:
   *  WhileIterator: '<S201>/whileIterator'
   */
  s201_iter = 1;
  do {
    localB->whileIterator = s201_iter;
    localB->indexVector = localB->SCI_Tx_Data[localB->whileIterator - 1];

    {
      if (checkSCITransmitInProgressB != 1U) {
        checkSCITransmitInProgressB = 1U;
        int16_T errFlgHeader = NOERROR;
        int16_T errFlgData = NOERROR;
        int16_T errFlgTail = NOERROR;
        errFlgData = scib_xmit((unsigned char*)&localB->indexVector, 2, 2);
        checkSCITransmitInProgressB = 0U;
      }
    }

    localB->add = localB->SCI_Tx_Iteration - (uint16_T)localB->whileIterator;
    s201_iter++;
  } while (localB->add != 0U);

  /* End of Outputs for SubSystem: '<S5>/SCI_Tx_codegen' */

  /* Sum: '<S207>/FixPt Sum1' incorporates:
   *  Constant: '<S207>/FixPt Constant'
   *  UnitDelay: '<S206>/Output'
   */
  localB->FixPtSum1 = (localB->Output + 1U) & 255U;

  /* Switch: '<S208>/FixPt Switch' incorporates:
   *  Sum: '<S207>/FixPt Sum1'
   */
  if (localB->FixPtSum1 > 3U) {
    /* Switch: '<S208>/FixPt Switch' incorporates:
     *  Constant: '<S208>/Constant'
     */
    localB->FixPtSwitch = 0U;
  } else {
    /* Switch: '<S208>/FixPt Switch' */
    localB->FixPtSwitch = localB->FixPtSum1;
  }

  /* End of Switch: '<S208>/FixPt Switch' */

  /* Update for UnitDelay: '<S206>/Output' incorporates:
   *  Switch: '<S208>/FixPt Switch'
   */
  localDW->Output_DSTATE = localB->FixPtSwitch;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
