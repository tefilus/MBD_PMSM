/*
 * File: Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_types.h
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

#ifndef RTW_HEADER_Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_types_h_
#define RTW_HEADER_Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_types_h_
#include "rtwtypes.h"
#include "MW_c2000SPI.h"

/* Custom Type definition for MATLABSystem: '<S133>/SPI Master Transfer' */
#include "MW_c2000SPI.h"
#ifndef struct_tag_RL3bf5VyBoZJTCiPpDuhAE
#define struct_tag_RL3bf5VyBoZJTCiPpDuhAE

struct tag_RL3bf5VyBoZJTCiPpDuhAE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_SPI_HANDLE;
};

#endif                                 /* struct_tag_RL3bf5VyBoZJTCiPpDuhAE */

#ifndef typedef_codertarget_tic2000_blocks_SPIM
#define typedef_codertarget_tic2000_blocks_SPIM

typedef struct tag_RL3bf5VyBoZJTCiPpDuhAE codertarget_tic2000_blocks_SPIM;

#endif                             /* typedef_codertarget_tic2000_blocks_SPIM */

/* Forward declaration for rtModel */
typedef struct tag_RTM_Copy_of_mcb_bldc_sixste RT_MODEL_Copy_of_mcb_bldc_sixst;

#endif
   /* RTW_HEADER_Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
