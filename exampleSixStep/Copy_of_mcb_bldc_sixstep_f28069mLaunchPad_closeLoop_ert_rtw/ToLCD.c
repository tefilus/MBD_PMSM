/*
 * File: ToLCD.c
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

#include "ToLCD.h"
#include "rtwtypes.h"
#include "Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_private.h"

/* System initialize for atomic system: '<Root>/ToLCD' */
void Copy_of_mcb_bldc_ToLCD_Init(rtB_ToLCD_Copy_of_mcb_bldc_sixs *localB)
{
  /* Start for Width: '<S200>/dataWidth' */
  localB->dataWidth = 2U;
}

/* Output and update for atomic system: '<Root>/ToLCD' */
void Copy_of_mcb_bldc_sixs_ToLCD(const real32_T *rtd_idcSCI_B, const real32_T
  *rtd_speedSCI_B, rtB_ToLCD_Copy_of_mcb_bldc_sixs *localB,
  rtDW_ToLCD_Copy_of_mcb_bldc_six *localDW)
{
  int16_T s201_iter;
  uint16_T Data;

  /* UnitDelay: '<S206>/Output' */
  localB->Output = localDW->Output_DSTATE;

  /* DataStoreRead: '<S200>/dataLogging_Speed' */
  localB->dataLogging_Speed = *rtd_speedSCI_B;

  /* DataStoreRead: '<S200>/Data Store Read' */
  localB->DataStoreRead = *rtd_idcSCI_B;

  /* DataTypeConversion: '<S203>/convertTo_sfix16_En12' */
  localB->convertTo_sfix16_En12[0] = (int16_T)(localB->dataLogging_Speed *
    4096.0F);
  localB->convertTo_sfix16_En12[1] = (int16_T)(localB->DataStoreRead * 4096.0F);

  /* DataTypeConversion: '<S203>/convertTo_uint16' incorporates:
   *  DataTypeConversion: '<S203>/convertTo_sfix16_En12'
   */
  localB->convertTo_uint16[0] = (uint16_T)localB->convertTo_sfix16_En12[0];
  localB->convertTo_uint16[1] = (uint16_T)localB->convertTo_sfix16_En12[1];

  /* If: '<S200>/indexCondition' incorporates:
   *  UnitDelay: '<S206>/Output'
   */
  if (localB->Output == 0U) {
    /* Outputs for IfAction SubSystem: '<S200>/Start' incorporates:
     *  ActionPort: '<S205>/Action Port'
     */
    /* Merge: '<S200>/mergeDataOut' incorporates:
     *  Constant: '<S205>/End'
     *  SignalConversion generated from: '<S205>/Data_out'
     */
    localB->SCI_Tx_Data[0] = 21331U;

    /* SignalConversion generated from: '<S205>/Data' */
    Data = localB->convertTo_uint16[0];

    /* End of Outputs for SubSystem: '<S200>/Start' */
    localB->Data_fw[0] = Data;

    /* Outputs for IfAction SubSystem: '<S200>/Start' incorporates:
     *  ActionPort: '<S205>/Action Port'
     */
    /* Merge: '<S200>/mergeDataOut' incorporates:
     *  SignalConversion generated from: '<S205>/Data_out'
     */
    localB->SCI_Tx_Data[1] = Data;

    /* SignalConversion generated from: '<S205>/Data' */
    Data = localB->convertTo_uint16[1];

    /* End of Outputs for SubSystem: '<S200>/Start' */
    localB->Data_fw[1] = Data;

    /* Outputs for IfAction SubSystem: '<S200>/Start' incorporates:
     *  ActionPort: '<S205>/Action Port'
     */
    /* Merge: '<S200>/mergeDataOut' incorporates:
     *  SignalConversion generated from: '<S205>/Data_out'
     */
    localB->SCI_Tx_Data[2] = Data;

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
    Data = localB->convertTo_uint16[0];

    /* End of Outputs for SubSystem: '<S200>/End' */
    localB->Data_f[0] = Data;

    /* Outputs for IfAction SubSystem: '<S200>/End' incorporates:
     *  ActionPort: '<S204>/Action Port'
     */
    /* Merge: '<S200>/mergeDataOut' incorporates:
     *  SignalConversion generated from: '<S204>/Data_out'
     */
    localB->SCI_Tx_Data[0] = Data;

    /* SignalConversion generated from: '<S204>/Data' */
    Data = localB->convertTo_uint16[1];

    /* End of Outputs for SubSystem: '<S200>/End' */
    localB->Data_f[1] = Data;

    /* Outputs for IfAction SubSystem: '<S200>/End' incorporates:
     *  ActionPort: '<S204>/Action Port'
     */
    /* Merge: '<S200>/mergeDataOut' incorporates:
     *  Constant: '<S204>/Start'
     *  SignalConversion generated from: '<S204>/Data_out'
     */
    localB->SCI_Tx_Data[1] = Data;
    localB->SCI_Tx_Data[2] = 17733U;

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
    Data = localB->convertTo_uint16[0];

    /* End of Outputs for SubSystem: '<S200>/Data' */
    localB->Data[0] = Data;

    /* Outputs for IfAction SubSystem: '<S200>/Data' incorporates:
     *  ActionPort: '<S202>/Action Port'
     */
    /* Merge: '<S200>/mergeDataOut' incorporates:
     *  SignalConversion generated from: '<S202>/Data_out'
     */
    localB->SCI_Tx_Data[0] = Data;

    /* SignalConversion generated from: '<S202>/Data' */
    Data = localB->convertTo_uint16[1];

    /* End of Outputs for SubSystem: '<S200>/Data' */
    localB->Data[1] = Data;

    /* Outputs for IfAction SubSystem: '<S200>/Data' incorporates:
     *  ActionPort: '<S202>/Action Port'
     */
    /* Merge: '<S200>/mergeDataOut' incorporates:
     *  Constant: '<S202>/Start'
     *  SignalConversion generated from: '<S202>/Data_out'
     */
    localB->SCI_Tx_Data[1] = Data;
    localB->SCI_Tx_Data[2] = 0U;

    /* Merge: '<S200>/mergeInteration' incorporates:
     *  SignalConversion generated from: '<S202>/Data_width'
     */
    localB->SCI_Tx_Iteration = localB->dataWidth;

    /* End of Outputs for SubSystem: '<S200>/Data' */
  }

  /* End of If: '<S200>/indexCondition' */

  /* Outputs for Iterator SubSystem: '<S6>/SCI_Tx_codegen' incorporates:
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

  /* End of Outputs for SubSystem: '<S6>/SCI_Tx_codegen' */

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
