/*
 * File: ToLCD.c
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

#include "ToLCD.h"
#include "rtwtypes.h"
#include "sixstep_f28069mLaunchPad_closeLoop_private.h"

/* System initialize for atomic system: '<Root>/ToLCD' */
void sixstep_f28069mL_ToLCD_Init(rtB_ToLCD_sixstep_f28069mLaunch *localB)
{
  /* Start for Width: '<S203>/dataWidth' */
  localB->dataWidth = 2U;
}

/* Output and update for atomic system: '<Root>/ToLCD' */
void sixstep_f28069mLaunch_ToLCD(const real32_T *rtd_idcSCI_B, const real32_T
  *rtd_speedSCI_B, rtB_ToLCD_sixstep_f28069mLaunch *localB,
  rtDW_ToLCD_sixstep_f28069mLaunc *localDW)
{
  int16_T s202_iter;
  uint16_T Data;

  /* UnitDelay: '<S208>/Output' */
  localB->Output = localDW->Output_DSTATE;

  /* DataStoreRead: '<S203>/dataLogging_Speed' */
  localB->dataLogging_Speed = *rtd_speedSCI_B;

  /* DataStoreRead: '<S203>/dataLogging_Idc' */
  localB->dataLogging_Idc = *rtd_idcSCI_B;

  /* DataTypeConversion: '<S205>/convertTo_sfix16_En12' */
  localB->convertTo_sfix16_En12[0] = (int16_T)(localB->dataLogging_Speed *
    4096.0F);
  localB->convertTo_sfix16_En12[1] = (int16_T)(localB->dataLogging_Idc * 4096.0F);

  /* DataTypeConversion: '<S205>/convertTo_uint16' incorporates:
   *  DataTypeConversion: '<S205>/convertTo_sfix16_En12'
   */
  localB->convertTo_uint16[0] = (uint16_T)localB->convertTo_sfix16_En12[0];
  localB->convertTo_uint16[1] = (uint16_T)localB->convertTo_sfix16_En12[1];

  /* If: '<S203>/indexCondition' incorporates:
   *  UnitDelay: '<S208>/Output'
   */
  if (localB->Output == 0U) {
    /* Outputs for IfAction SubSystem: '<S203>/Start' incorporates:
     *  ActionPort: '<S207>/Action Port'
     */
    /* Merge: '<S203>/mergeDataOut' incorporates:
     *  Constant: '<S207>/End'
     *  SignalConversion generated from: '<S207>/Data_out'
     */
    localB->SCI_Tx_Data[0] = 21331U;

    /* SignalConversion generated from: '<S207>/Data' */
    Data = localB->convertTo_uint16[0];

    /* End of Outputs for SubSystem: '<S203>/Start' */
    localB->Data_fw[0] = Data;

    /* Outputs for IfAction SubSystem: '<S203>/Start' incorporates:
     *  ActionPort: '<S207>/Action Port'
     */
    /* Merge: '<S203>/mergeDataOut' incorporates:
     *  SignalConversion generated from: '<S207>/Data_out'
     */
    localB->SCI_Tx_Data[1] = Data;

    /* SignalConversion generated from: '<S207>/Data' */
    Data = localB->convertTo_uint16[1];

    /* End of Outputs for SubSystem: '<S203>/Start' */
    localB->Data_fw[1] = Data;

    /* Outputs for IfAction SubSystem: '<S203>/Start' incorporates:
     *  ActionPort: '<S207>/Action Port'
     */
    /* Merge: '<S203>/mergeDataOut' incorporates:
     *  SignalConversion generated from: '<S207>/Data_out'
     */
    localB->SCI_Tx_Data[2] = Data;

    /* Merge: '<S203>/mergeInteration' incorporates:
     *  Bias: '<S207>/Bias'
     */
    localB->SCI_Tx_Iteration = localB->dataWidth + 1U;

    /* End of Outputs for SubSystem: '<S203>/Start' */
  } else if (localB->Output == 2U) {
    /* Outputs for IfAction SubSystem: '<S203>/End' incorporates:
     *  ActionPort: '<S206>/Action Port'
     */
    /* SignalConversion generated from: '<S206>/Data' */
    Data = localB->convertTo_uint16[0];

    /* End of Outputs for SubSystem: '<S203>/End' */
    localB->Data_f[0] = Data;

    /* Outputs for IfAction SubSystem: '<S203>/End' incorporates:
     *  ActionPort: '<S206>/Action Port'
     */
    /* Merge: '<S203>/mergeDataOut' incorporates:
     *  SignalConversion generated from: '<S206>/Data_out'
     */
    localB->SCI_Tx_Data[0] = Data;

    /* SignalConversion generated from: '<S206>/Data' */
    Data = localB->convertTo_uint16[1];

    /* End of Outputs for SubSystem: '<S203>/End' */
    localB->Data_f[1] = Data;

    /* Outputs for IfAction SubSystem: '<S203>/End' incorporates:
     *  ActionPort: '<S206>/Action Port'
     */
    /* Merge: '<S203>/mergeDataOut' incorporates:
     *  Constant: '<S206>/Start'
     *  SignalConversion generated from: '<S206>/Data_out'
     */
    localB->SCI_Tx_Data[1] = Data;
    localB->SCI_Tx_Data[2] = 17733U;

    /* Merge: '<S203>/mergeInteration' incorporates:
     *  Bias: '<S206>/Bias'
     */
    localB->SCI_Tx_Iteration = localB->dataWidth + 1U;

    /* End of Outputs for SubSystem: '<S203>/End' */
  } else {
    /* Outputs for IfAction SubSystem: '<S203>/Data' incorporates:
     *  ActionPort: '<S204>/Action Port'
     */
    /* SignalConversion generated from: '<S204>/Data' */
    Data = localB->convertTo_uint16[0];

    /* End of Outputs for SubSystem: '<S203>/Data' */
    localB->Data[0] = Data;

    /* Outputs for IfAction SubSystem: '<S203>/Data' incorporates:
     *  ActionPort: '<S204>/Action Port'
     */
    /* Merge: '<S203>/mergeDataOut' incorporates:
     *  SignalConversion generated from: '<S204>/Data_out'
     */
    localB->SCI_Tx_Data[0] = Data;

    /* SignalConversion generated from: '<S204>/Data' */
    Data = localB->convertTo_uint16[1];

    /* End of Outputs for SubSystem: '<S203>/Data' */
    localB->Data[1] = Data;

    /* Outputs for IfAction SubSystem: '<S203>/Data' incorporates:
     *  ActionPort: '<S204>/Action Port'
     */
    /* Merge: '<S203>/mergeDataOut' incorporates:
     *  Constant: '<S204>/Start'
     *  SignalConversion generated from: '<S204>/Data_out'
     */
    localB->SCI_Tx_Data[1] = Data;
    localB->SCI_Tx_Data[2] = MAX_uint16_T;

    /* Merge: '<S203>/mergeInteration' incorporates:
     *  SignalConversion generated from: '<S204>/Data_width'
     */
    localB->SCI_Tx_Iteration = localB->dataWidth;

    /* End of Outputs for SubSystem: '<S203>/Data' */
  }

  /* End of If: '<S203>/indexCondition' */

  /* Outputs for Iterator SubSystem: '<S6>/SCITransmit' incorporates:
   *  WhileIterator: '<S202>/whileIterator'
   */
  s202_iter = 1;
  do {
    localB->whileIterator = s202_iter;
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
    s202_iter++;
  } while (localB->add != 0U);

  /* End of Outputs for SubSystem: '<S6>/SCITransmit' */

  /* Sum: '<S209>/FixPt Sum1' incorporates:
   *  Constant: '<S209>/FixPt Constant'
   *  UnitDelay: '<S208>/Output'
   */
  localB->FixPtSum1 = (localB->Output + 1U) & 255U;

  /* Switch: '<S210>/FixPt Switch' incorporates:
   *  Sum: '<S209>/FixPt Sum1'
   */
  if (localB->FixPtSum1 > 3U) {
    /* Switch: '<S210>/FixPt Switch' incorporates:
     *  Constant: '<S210>/Constant'
     */
    localB->FixPtSwitch = 0U;
  } else {
    /* Switch: '<S210>/FixPt Switch' */
    localB->FixPtSwitch = localB->FixPtSum1;
  }

  /* End of Switch: '<S210>/FixPt Switch' */

  /* Update for UnitDelay: '<S208>/Output' incorporates:
   *  Switch: '<S210>/FixPt Switch'
   */
  localDW->Output_DSTATE = localB->FixPtSwitch;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
