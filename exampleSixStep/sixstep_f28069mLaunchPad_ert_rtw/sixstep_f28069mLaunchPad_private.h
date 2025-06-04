/*
 * File: sixstep_f28069mLaunchPad_private.h
 *
 * Code generated for Simulink model 'sixstep_f28069mLaunchPad'.
 *
 * Model version                  : 7.73
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed May 28 09:45:44 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_sixstep_f28069mLaunchPad_private_h_
#define RTW_HEADER_sixstep_f28069mLaunchPad_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "sixstep_f28069mLaunchPad.h"
#include "sixstep_f28069mLaunchPad_types.h"

void config_QEP_eQEP1(uint32_T pcmaximumvalue, uint32_T pcInitialvalue, uint32_T
                      unittimerperiod, uint32_T comparevalue, uint16_T
                      watchdogtimer, uint16_T qdecctl, uint16_T qepctl, uint16_T
                      qposctl, uint16_T qcapctl, uint16_T qeint);

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFFFU) ) || ( SCHAR_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */
void InitAdc (void);
void config_ADC_SOC0 (void);
void config_ADC_SOC2_SOC3 (void);
void config_ADC_SOC6_SOC7 (void);
void config_ADC_SOC4 (void);
extern uint16_T MW_adcInitFlag;
extern void sixstep_f28069mLau_Position(real32_T rtu_Position, uint16_T
  *rty_Sector);
extern void sixstep_f28069mL_BitExtract(uint16_T rtu_Sector, boolean_T
  rty_HallVector[3], rtB_BitExtract_sixstep_f28069mL *localB);
extern void sixstep_f28069_HallValueof1(real32_T *rty_position);
extern void sixstep_f28069_HallValueof2(real32_T *rty_position);
extern void sixstep_f28069_HallValueof3(real32_T *rty_position);
extern void sixstep_f28069_HallValueof4(real32_T *rty_position);
extern void sixstep_f28069_HallValueof5(real32_T *rty_position);
extern void sixstep_f28069_HallValueof7(real32_T *rty_position);
extern void sixs_SPIMasterTransfer_Init(rtDW_SPIMasterTransfer_sixstep_ *localDW);
extern void sixstep_f_SPIMasterTransfer(uint16_T rtu_0,
  rtB_SPIMasterTransfer_sixstep_f *localB, rtDW_SPIMasterTransfer_sixstep_
  *localDW);
extern void sixstep_f_SpeedControl_Init(rtB_SpeedControl_sixstep_f28069 *localB,
  rtDW_SpeedControl_sixstep_f2806 *localDW);
extern void sixstep_f28069_SpeedControl(real32_T rtu_Speed_Ref_PU, real32_T
  rtu_Speed_Meas_PU, const boolean_T *rtd_Enable,
  rtB_SpeedControl_sixstep_f28069 *localB, rtDW_SpeedControl_sixstep_f2806
  *localDW);
extern void sixstep_CurrentControl_Init(void);
extern void sixste_CurrentControl_Reset(void);

#pragma CODE_SECTION (sixstep_f280_CurrentControl, "ramfuncs")

extern void sixstep_f280_CurrentControl(void);
extern void sixs_SPIMasterTransfer_Term(rtDW_SPIMasterTransfer_sixstep_ *localDW);

#endif                      /* RTW_HEADER_sixstep_f28069mLaunchPad_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
