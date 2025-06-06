/*
 * File: Current_private.h
 *
 * Code generated for Simulink model 'Current'.
 *
 * Model version                  : 6.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Mar 17 10:12:56 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Current_private_h_
#define RTW_HEADER_Current_private_h_
#include "rtwtypes.h"
#include "Current.h"
#include "Current_types.h"
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
extern void Current_CurrentControl_Init(DW_CurrentControl_Current_T *localDW);
extern void Current_CurrentControl(const int32_T rtu_Idq_ref_PU[2], const
  uint16_T rtu_Feedbacks_sim[4], int32_T rty_DutyCycles[3], int32_T
  *rty_Speed_fb, const ConstB_CurrentControl_Current_T *localC,
  DW_CurrentControl_Current_T *localDW);

#endif                                 /* RTW_HEADER_Current_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
