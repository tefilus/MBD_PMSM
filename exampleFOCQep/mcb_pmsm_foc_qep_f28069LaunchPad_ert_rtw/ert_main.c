/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_qep_f28069LaunchPad'.
 *
 * Model version                  : 8.18
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Jun  6 13:19:49 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "mcb_pmsm_foc_qep_f28069LaunchPad.h"
#include "rtwtypes.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[2] = { 0, 0 };

boolean_T need2runFlags[2] = { 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[2];

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.
   */
  mcb_pmsm_foc_qep_f28069LaunchPad_SetEventsForThisBaseStep(eventFlags);
  enableTimer0Interrupt();
  mcb_pmsm_foc_qep_f28069LaunchPad_step0();

  /* Get model outputs here */
  disableTimer0Interrupt();
  isRateRunning[0]--;
  if (eventFlags[1]) {
    if (need2runFlags[1]++) {
      IsrOverrun = 1;
      need2runFlags[1]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[1]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[1]++;
    enableTimer0Interrupt();

    /* Step the model for subrate "1" */
    switch (1)
    {
     case 1 :
      mcb_pmsm_foc_qep_f28069LaunchPad_step1();

      /* Get model outputs here */
      break;

     default :
      break;
    }

    disableTimer0Interrupt();
    need2runFlags[1]--;
    isRateRunning[1]--;
  }
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.0005;
  float systemClock = 90;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  HWI_TIC28x_EnablePeripheralInterrupt();
  c2000_flash_init();
  init_board();

#if defined(MW_EXEC_PROFILER_ON) || (defined(MW_EXTMODE_RUNNING) && !defined(XCP_TIMESTAMP_BASED_ON_SIMULATION_TIME))

  hardwareTimer1Init();

#endif

  ;
  bootloaderInit();
  rtmSetErrorStatus(mcb_pmsm_foc_qep_f28069Launc_M, 0);
  mcb_pmsm_foc_qep_f28069LaunchPad_configure_interrupts();
  mcb_pmsm_foc_qep_f28069LaunchPad_initialize();
  globalInterruptDisable();
  configureTimer0(modelBaseRate, systemClock);
  runModel = rtmGetErrorStatus(mcb_pmsm_foc_qep_f28069Launc_M) == (NULL);
  enableTimer0Interrupt();
  config_ePWM_TBSync();
  globalInterruptEnable();
  while (runModel) {
    stopRequested = !(rtmGetErrorStatus(mcb_pmsm_foc_qep_f28069Launc_M) == (NULL));
  }

  /* Terminate model */
  mcb_pmsm_foc_qep_f28069LaunchPad_terminate();
  mcb_pmsm_foc_qep_f28069LaunchPad_unconfigure_interrupts();
  HWI_TIC28x_DisablePeripheralInterrupt();
  globalInterruptDisable();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
