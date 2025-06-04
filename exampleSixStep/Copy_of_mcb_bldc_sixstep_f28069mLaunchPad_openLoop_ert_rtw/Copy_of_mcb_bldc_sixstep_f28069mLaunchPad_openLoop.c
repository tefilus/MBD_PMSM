/*
 * File: Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_openLoop.c
 *
 * Code generated for Simulink model 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_openLoop'.
 *
 * Model version                  : 7.22
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat May 17 15:22:53 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_openLoop.h"
#include "Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_openLoop_private.h"
#include "rtwtypes.h"
#include <math.h>
#include <string.h>

/* Block signals (default storage) */
BlockIO_Copy_of_mcb_bldc_sixste Copy_of_mcb_bldc_sixstep_f280_B;

/* Block states (default storage) */
D_Work_Copy_of_mcb_bldc_sixstep Copy_of_mcb_bldc_sixstep__DWork;

/* Real-time model */
static RT_MODEL_Copy_of_mcb_bldc_sixst Copy_of_mcb_bldc_sixstep_f28_M_;
RT_MODEL_Copy_of_mcb_bldc_sixst *const Copy_of_mcb_bldc_sixstep_f28_M =
  &Copy_of_mcb_bldc_sixstep_f28_M_;
static void rate_monotonic_scheduler(void);

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcInitFlag = 0;

#endif

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_openLoop_SetEventsForThisBaseStep
  (boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Copy_of_mcb_bldc_sixstep_f28_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Copy_of_mcb_bldc_sixstep_f28_M->Timing.TaskCounters.TID[1])++;
  if ((Copy_of_mcb_bldc_sixstep_f28_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.5s, 0.0s] */
    Copy_of_mcb_bldc_sixstep_f28_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_openLoop_step0(void) /* Sample time: [0.1s, 0.0s] */
{
  {                                    /* Sample time: [0.1s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (c280xgpio_di): '<S4>/CW//CCW_GPIO7' */
  {
    Copy_of_mcb_bldc_sixstep_f280_B.CWCCW_GPIO7 = GpioDataRegs.GPADAT.bit.GPIO7;
  }

  /* DataStoreWrite: '<S4>/Data Store Write1' */
  Copy_of_mcb_bldc_sixstep__DWork.readTorqueSign =
    Copy_of_mcb_bldc_sixstep_f280_B.CWCCW_GPIO7;

  /* S-Function (c280xgpio_di): '<S4>/ON//OFF_GPIO6' */
  {
    Copy_of_mcb_bldc_sixstep_f280_B.ONOFF_GPIO6 = GpioDataRegs.GPADAT.bit.GPIO6;
  }

  /* DataStoreWrite: '<S4>/Data Store Write' */
  Copy_of_mcb_bldc_sixstep__DWork.Enable =
    Copy_of_mcb_bldc_sixstep_f280_B.ONOFF_GPIO6;
}

/* Model step function for TID1 */
void Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_openLoop_step1(void) /* Sample time: [0.5s, 0.0s] */
{
  /* S-Function (c280xgpio_do): '<S1>/Digital Output' incorporates:
   *  Constant: '<S1>/Constant'
   */
  {
    GpioDataRegs.GPBTOGGLE.bit.GPIO39 = (uint16_T)((1.0) != 0);
  }
}

/* Model initialize function */
void Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_openLoop_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Copy_of_mcb_bldc_sixstep_f28_M, 0,
                sizeof(RT_MODEL_Copy_of_mcb_bldc_sixst));

  /* block I/O */
  (void) memset(((void *) &Copy_of_mcb_bldc_sixstep_f280_B), 0,
                sizeof(BlockIO_Copy_of_mcb_bldc_sixste));

  {
    int16_T i;
    for (i = 0; i < 6; i++) {
      Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion1[i] = 0.0F;
    }

    Copy_of_mcb_bldc_sixstep_f280_B.Merge = 0.0;
    Copy_of_mcb_bldc_sixstep_f280_B.Sign = 0.0;
    Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion = 0.0F;
    Copy_of_mcb_bldc_sixstep_f280_B.DTC = 0.0F;
    Copy_of_mcb_bldc_sixstep_f280_B.Product = 0.0F;
    Copy_of_mcb_bldc_sixstep_f280_B.DTC_m = 0.0F;
    Copy_of_mcb_bldc_sixstep_f280_B.SpeedGain = 0.0F;
    Copy_of_mcb_bldc_sixstep_f280_B.Product_c = 0.0F;
    Copy_of_mcb_bldc_sixstep_f280_B.UnitDelay = 0.0F;
    Copy_of_mcb_bldc_sixstep_f280_B.Product1 = 0.0F;
    Copy_of_mcb_bldc_sixstep_f280_B.Add1 = 0.0F;
    Copy_of_mcb_bldc_sixstep_f280_B.Switch = 0.0F;
    Copy_of_mcb_bldc_sixstep_f280_B.Merge_m = 0.0F;
    Copy_of_mcb_bldc_sixstep_f280_B.Numberofpolepairs = 0.0F;
    Copy_of_mcb_bldc_sixstep_f280_B.Floor = 0.0F;
    Copy_of_mcb_bldc_sixstep_f280_B.Add = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&Copy_of_mcb_bldc_sixstep__DWork, 0,
                sizeof(D_Work_Copy_of_mcb_bldc_sixstep));
  Copy_of_mcb_bldc_sixstep__DWork.desiredSpeed = 0.0;
  Copy_of_mcb_bldc_sixstep__DWork.UnitDelay_DSTATE = 0.0F;

  /* Start for S-Function (c280xgpio_di): '<S4>/CW//CCW_GPIO7' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFF3FFFU;
  GpioCtrlRegs.GPADIR.all &= 0xFFFFFF7FU;
  EDIS;

  /* Start for S-Function (c280xgpio_di): '<S4>/ON//OFF_GPIO6' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFCFFFU;
  GpioCtrlRegs.GPADIR.all &= 0xFFFFFFBFU;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<S1>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 0xFFFF3FFFU;
  GpioCtrlRegs.GPBDIR.all |= 0x80U;
  EDIS;

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S71>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Current Control'
   */

  /* System initialize for function-call system: '<Root>/Current Control' */
  {
    int16_T i;

    /* Start for S-Function (c280xgpio_do): '<S9>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all &= 0xF3FFFFFFU;
    GpioCtrlRegs.GPADIR.all |= 0x2000U;
    EDIS;

    /* Start for S-Function (c2802xadc): '<S11>/Read POT' */
    if (MW_adcInitFlag == 0U) {
      InitAdc();
      MW_adcInitFlag = 1U;
    }

    config_ADC_SOC1 ();

    /* Start for S-Function (c280xqep): '<S11>/eQEP' */
    config_QEP_eQEP1((uint32_T)65535U,(uint32_T)0, (uint32_T)0, (uint32_T)0,
                     (uint16_T)0, (uint16_T)448, (uint16_T)8232, (uint16_T)32768,
                     (uint16_T)119,(uint16_T)0);

    /* Start for S-Function (c2802xpwm): '<S9>/ePWM4' */

    /*** Initialize ePWM1 modules ***/
    {
      /*  // Time Base Control Register
         EPwm1Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
         EPwm1Regs.TBCTL.bit.SYNCOSEL             = 1U;          // Sync Output Select

         EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

         EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          // Phase Load Enable
         EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          // Phase Direction Bit
         EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
         EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
       */
      EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x12U;

      /*-- Setup Time-Base (TB) Submodule --*/
      EPwm1Regs.TBPRD = 2250U;         // Time Base Period Register

      /* // Time-Base Phase Register
         EPwm1Regs.TBPHS.half.TBPHS               = 0U;         // Phase offset register
       */
      EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

      // Time Base Counter Register
      EPwm1Regs.TBCTR = 0x0000U;       /* Clear counter*/

      /*-- Setup Counter_Compare (CC) Submodule --*/
      /*	// Counter Compare Control Register

         EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
         EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
         EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
         EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
       */
      EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x5FU) | 0x0U;
      EPwm1Regs.CMPA.half.CMPA = 1126U;// Counter Compare A Register
      EPwm1Regs.CMPB = 1126U;          // Counter Compare B Register

      /*-- Setup Action-Qualifier (AQ) Submodule --*/
      EPwm1Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
      EPwm1Regs.AQCTLB.all = 2304U;
                               // Action Qualifier Control Register For Output B

      /*	// Action Qualifier Software Force Register
         EPwm1Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
       */
      EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0U) | 0x0U;

      /*	// Action Qualifier Continuous S/W Force Register
         EPwm1Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
         EPwm1Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
       */
      EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xFU) | 0x0U;

      /*-- Setup Dead-Band Generator (DB) Submodule --*/
      /*	// Dead-Band Generator Control Register
         EPwm1Regs.DBCTL.bit.OUT_MODE             = 0U;          // Dead Band Output Mode Control
         EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
         EPwm1Regs.DBCTL.bit.POLSEL               = 0;          // Polarity Select Control
         EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
       */
      EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x803FU) | 0x0U;
      EPwm1Regs.DBRED = 0U;
                         // Dead-Band Generator Rising Edge Delay Count Register
      EPwm1Regs.DBFED = 0U;
                        // Dead-Band Generator Falling Edge Delay Count Register

      /*-- Setup Event-Trigger (ET) Submodule --*/
      /*	// Event Trigger Selection and Pre-Scale Register
         EPwm1Regs.ETSEL.bit.SOCAEN               = 1U;          // Start of Conversion A Enable
         EPwm1Regs.ETSEL.bit.SOCASEL              = 1U;          // Start of Conversion A Select
         EPwm1Regs.ETPS.bit.SOCAPRD               = 1U;          // EPWM1SOCA Period Select
         EPwm1Regs.ETSEL.bit.SOCBEN               = 1U;          // Start of Conversion B Enable
         EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion B Select
         EPwm1Regs.ETPS.bit.SOCBPRD               = 1U;          // EPWM1SOCB Period Select
         EPwm1Regs.ETSEL.bit.INTEN                = 0U;          // EPWM1INTn Enable
         EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          // EPWM1INTn Select
         EPwm1Regs.ETPS.bit.INTPRD                = 1U;          // EPWM1INTn Period Select
       */
      EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF0FU) | 0x9901U;
      EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x3303U) | 0x1101U;

      /*-- Setup PWM-Chopper (PC) Submodule --*/
      /*	// PWM Chopper Control Register
         EPwm1Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
         EPwm1Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
         EPwm1Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
         EPwm1Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
       */
      EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FFU) | 0x0U;

      /*-- Set up Trip-Zone (TZ) Submodule --*/
      EALLOW;
      EPwm1Regs.TZSEL.all = 0U;        // Trip Zone Select Register

      /*	// Trip Zone Control Register
         EPwm1Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1A
         EPwm1Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1B
         EPwm1Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM1A action on DCAEVT1
         EPwm1Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM1A action on DCAEVT2
         EPwm1Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM1B action on DCBEVT1
         EPwm1Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM1B action on DCBEVT2
       */
      EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

      /*	// Trip Zone Enable Interrupt Register
         EPwm1Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
         EPwm1Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
         EPwm1Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
         EPwm1Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
         EPwm1Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
         EPwm1Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
       */
      EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7EU) | 0x0U;

      /*	// Digital Compare A Control Register
         EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
         EPwm1Regs.DCACTL.bit.EVT1SOCE            = 0U;          // DCAEVT1 SOC Enable
         EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
         EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
         EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
         EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
       */
      EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x0U;

      /*	// Digital Compare B Control Register
         EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
         EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
         EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
         EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
         EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
         EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
       */
      EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30FU) | 0x0U;

      /*	// Digital Compare Trip Select Register
         EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

         EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          // Digital Compare A Low COMP Input Select
         EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
         EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          // Digital Compare B Low COMP Input Select
       */
      EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

      /*	// Trip Zone Digital Comparator Select Register
         EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
         EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
         EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
         EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
       */
      EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

      /*	// Digital Compare Filter Control Register
         EPwm1Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
         EPwm1Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
         EPwm1Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
         EPwm1Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
       */
      EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3FU) | 0x10U;
      EPwm1Regs.DCFOFFSET = 0U;        // Digital Compare Filter Offset Register
      EPwm1Regs.DCFWINDOW = 0U;        // Digital Compare Filter Window Register

      /*	// Digital Compare Capture Control Register
         EPwm1Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
       */
      EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

      /*	// HRPWM Configuration Register
         EPwm1Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
         EPwm1Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
       */
      EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0U) | 0x0U;
      EDIS;
    }

    /* Start for S-Function (c2802xpwm): '<S9>/ePWM5' */

    /*** Initialize ePWM2 modules ***/
    {
      /*  // Time Base Control Register
         EPwm2Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
         EPwm2Regs.TBCTL.bit.SYNCOSEL             = 0U;          // Sync Output Select

         EPwm2Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

         EPwm2Regs.TBCTL.bit.PHSEN                = 1U;          // Phase Load Enable
         EPwm2Regs.TBCTL.bit.PHSDIR               = 1U;          // Phase Direction Bit
         EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
         EPwm2Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
       */
      EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;

      /*-- Setup Time-Base (TB) Submodule --*/
      EPwm2Regs.TBPRD = 2250U;         // Time Base Period Register

      /* // Time-Base Phase Register
         EPwm2Regs.TBPHS.half.TBPHS               = 0U;         // Phase offset register
       */
      EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

      // Time Base Counter Register
      EPwm2Regs.TBCTR = 0x0000U;       /* Clear counter*/

      /*-- Setup Counter_Compare (CC) Submodule --*/
      /*	// Counter Compare Control Register

         EPwm2Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
         EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
         EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
         EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
       */
      EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x5FU) | 0x0U;
      EPwm2Regs.CMPA.half.CMPA = 1126U;// Counter Compare A Register
      EPwm2Regs.CMPB = 1126U;          // Counter Compare B Register

      /*-- Setup Action-Qualifier (AQ) Submodule --*/
      EPwm2Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
      EPwm2Regs.AQCTLB.all = 2304U;
                               // Action Qualifier Control Register For Output B

      /*	// Action Qualifier Software Force Register
         EPwm2Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
       */
      EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0U) | 0x0U;

      /*	// Action Qualifier Continuous S/W Force Register
         EPwm2Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
         EPwm2Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
       */
      EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xFU) | 0x0U;

      /*-- Setup Dead-Band Generator (DB) Submodule --*/
      /*	// Dead-Band Generator Control Register
         EPwm2Regs.DBCTL.bit.OUT_MODE             = 0U;          // Dead Band Output Mode Control
         EPwm2Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
         EPwm2Regs.DBCTL.bit.POLSEL               = 0;          // Polarity Select Control
         EPwm2Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
       */
      EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x803FU) | 0x0U;
      EPwm2Regs.DBRED = 0U;
                         // Dead-Band Generator Rising Edge Delay Count Register
      EPwm2Regs.DBFED = 0U;
                        // Dead-Band Generator Falling Edge Delay Count Register

      /*-- Setup Event-Trigger (ET) Submodule --*/
      /*	// Event Trigger Selection and Pre-Scale Register
         EPwm2Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
         EPwm2Regs.ETSEL.bit.SOCASEL              = 0U;          // Start of Conversion A Select
         EPwm2Regs.ETPS.bit.SOCAPRD               = 1U;          // EPWM2SOCA Period Select
         EPwm2Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
         EPwm2Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion B Select
         EPwm2Regs.ETPS.bit.SOCBPRD               = 1U;          // EPWM2SOCB Period Select
         EPwm2Regs.ETSEL.bit.INTEN                = 0U;          // EPWM2INTn Enable
         EPwm2Regs.ETSEL.bit.INTSEL               = 1U;          // EPWM2INTn Select
         EPwm2Regs.ETPS.bit.INTPRD                = 1U;          // EPWM2INTn Period Select
       */
      EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF0FU) | 0x1001U;
      EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x3303U) | 0x1101U;

      /*-- Setup PWM-Chopper (PC) Submodule --*/
      /*	// PWM Chopper Control Register
         EPwm2Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
         EPwm2Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
         EPwm2Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
         EPwm2Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
       */
      EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FFU) | 0x0U;

      /*-- Set up Trip-Zone (TZ) Submodule --*/
      EALLOW;
      EPwm2Regs.TZSEL.all = 0U;        // Trip Zone Select Register

      /*	// Trip Zone Control Register
         EPwm2Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM2A
         EPwm2Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM2B
         EPwm2Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM2A action on DCAEVT1
         EPwm2Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM2A action on DCAEVT2
         EPwm2Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM2B action on DCBEVT1
         EPwm2Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM2B action on DCBEVT2
       */
      EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

      /*	// Trip Zone Enable Interrupt Register
         EPwm2Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
         EPwm2Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
         EPwm2Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
         EPwm2Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
         EPwm2Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
         EPwm2Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
       */
      EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x7EU) | 0x0U;

      /*	// Digital Compare A Control Register
         EPwm2Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
         EPwm2Regs.DCACTL.bit.EVT1SOCE            = 1U;          // DCAEVT1 SOC Enable
         EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
         EPwm2Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
         EPwm2Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
         EPwm2Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
       */
      EPwm2Regs.DCACTL.all = (EPwm2Regs.DCACTL.all & ~0x30FU) | 0x4U;

      /*	// Digital Compare B Control Register
         EPwm2Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
         EPwm2Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
         EPwm2Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
         EPwm2Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
         EPwm2Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
         EPwm2Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
       */
      EPwm2Regs.DCBCTL.all = (EPwm2Regs.DCBCTL.all & ~0x30FU) | 0x0U;

      /*	// Digital Compare Trip Select Register
         EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

         EPwm2Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          // Digital Compare A Low COMP Input Select
         EPwm2Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
         EPwm2Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          // Digital Compare B Low COMP Input Select
       */
      EPwm2Regs.DCTRIPSEL.all = (EPwm2Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

      /*	// Trip Zone Digital Comparator Select Register
         EPwm2Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
         EPwm2Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
         EPwm2Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
         EPwm2Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
       */
      EPwm2Regs.TZDCSEL.all = (EPwm2Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

      /*	// Digital Compare Filter Control Register
         EPwm2Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
         EPwm2Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
         EPwm2Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
         EPwm2Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
       */
      EPwm2Regs.DCFCTL.all = (EPwm2Regs.DCFCTL.all & ~0x3FU) | 0x10U;
      EPwm2Regs.DCFOFFSET = 0U;        // Digital Compare Filter Offset Register
      EPwm2Regs.DCFWINDOW = 0U;        // Digital Compare Filter Window Register

      /*	// Digital Compare Capture Control Register
         EPwm2Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
       */
      EPwm2Regs.DCCAPCTL.all = (EPwm2Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

      /*	// HRPWM Configuration Register
         EPwm2Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
         EPwm2Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
       */
      EPwm2Regs.HRCNFG.all = (EPwm2Regs.HRCNFG.all & ~0xA0U) | 0x0U;
      EDIS;
    }

    /* Start for S-Function (c2802xpwm): '<S9>/ePWM6' */

    /*** Initialize ePWM3 modules ***/
    {
      /*  // Time Base Control Register
         EPwm3Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
         EPwm3Regs.TBCTL.bit.SYNCOSEL             = 3U;          // Sync Output Select

         EPwm3Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

         EPwm3Regs.TBCTL.bit.PHSEN                = 1U;          // Phase Load Enable
         EPwm3Regs.TBCTL.bit.PHSDIR               = 1U;          // Phase Direction Bit
         EPwm3Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
         EPwm3Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
       */
      EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FFFU) | 0x2036U;

      /*-- Setup Time-Base (TB) Submodule --*/
      EPwm3Regs.TBPRD = 2250U;         // Time Base Period Register

      /* // Time-Base Phase Register
         EPwm3Regs.TBPHS.half.TBPHS               = 0U;         // Phase offset register
       */
      EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

      // Time Base Counter Register
      EPwm3Regs.TBCTR = 0x0000U;       /* Clear counter*/

      /*-- Setup Counter_Compare (CC) Submodule --*/
      /*	// Counter Compare Control Register

         EPwm3Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
         EPwm3Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
         EPwm3Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
         EPwm3Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
       */
      EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x5FU) | 0x0U;
      EPwm3Regs.CMPA.half.CMPA = 1126U;// Counter Compare A Register
      EPwm3Regs.CMPB = 1126U;          // Counter Compare B Register

      /*-- Setup Action-Qualifier (AQ) Submodule --*/
      EPwm3Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
      EPwm3Regs.AQCTLB.all = 2304U;
                               // Action Qualifier Control Register For Output B

      /*	// Action Qualifier Software Force Register
         EPwm3Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
       */
      EPwm3Regs.AQSFRC.all = (EPwm3Regs.AQSFRC.all & ~0xC0U) | 0x0U;

      /*	// Action Qualifier Continuous S/W Force Register
         EPwm3Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
         EPwm3Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
       */
      EPwm3Regs.AQCSFRC.all = (EPwm3Regs.AQCSFRC.all & ~0xFU) | 0x0U;

      /*-- Setup Dead-Band Generator (DB) Submodule --*/
      /*	// Dead-Band Generator Control Register
         EPwm3Regs.DBCTL.bit.OUT_MODE             = 0U;          // Dead Band Output Mode Control
         EPwm3Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
         EPwm3Regs.DBCTL.bit.POLSEL               = 0;          // Polarity Select Control
         EPwm3Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
       */
      EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x803FU) | 0x0U;
      EPwm3Regs.DBRED = 0U;
                         // Dead-Band Generator Rising Edge Delay Count Register
      EPwm3Regs.DBFED = 0U;
                        // Dead-Band Generator Falling Edge Delay Count Register

      /*-- Setup Event-Trigger (ET) Submodule --*/
      /*	// Event Trigger Selection and Pre-Scale Register
         EPwm3Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
         EPwm3Regs.ETSEL.bit.SOCASEL              = 0U;          // Start of Conversion A Select
         EPwm3Regs.ETPS.bit.SOCAPRD               = 1U;          // EPWM3SOCA Period Select
         EPwm3Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
         EPwm3Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion B Select
         EPwm3Regs.ETPS.bit.SOCBPRD               = 1U;          // EPWM3SOCB Period Select
         EPwm3Regs.ETSEL.bit.INTEN                = 0U;          // EPWM3INTn Enable
         EPwm3Regs.ETSEL.bit.INTSEL               = 1U;          // EPWM3INTn Select
         EPwm3Regs.ETPS.bit.INTPRD                = 1U;          // EPWM3INTn Period Select
       */
      EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF0FU) | 0x1001U;
      EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x3303U) | 0x1101U;

      /*-- Setup PWM-Chopper (PC) Submodule --*/
      /*	// PWM Chopper Control Register
         EPwm3Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
         EPwm3Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
         EPwm3Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
         EPwm3Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
       */
      EPwm3Regs.PCCTL.all = (EPwm3Regs.PCCTL.all & ~0x7FFU) | 0x0U;

      /*-- Set up Trip-Zone (TZ) Submodule --*/
      EALLOW;
      EPwm3Regs.TZSEL.all = 0U;        // Trip Zone Select Register

      /*	// Trip Zone Control Register
         EPwm3Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM3A
         EPwm3Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM3B
         EPwm3Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM3A action on DCAEVT1
         EPwm3Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM3A action on DCAEVT2
         EPwm3Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM3B action on DCBEVT1
         EPwm3Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM3B action on DCBEVT2
       */
      EPwm3Regs.TZCTL.all = (EPwm3Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

      /*	// Trip Zone Enable Interrupt Register
         EPwm3Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
         EPwm3Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
         EPwm3Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
         EPwm3Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
         EPwm3Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
         EPwm3Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
       */
      EPwm3Regs.TZEINT.all = (EPwm3Regs.TZEINT.all & ~0x7EU) | 0x0U;

      /*	// Digital Compare A Control Register
         EPwm3Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
         EPwm3Regs.DCACTL.bit.EVT1SOCE            = 1U;          // DCAEVT1 SOC Enable
         EPwm3Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
         EPwm3Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
         EPwm3Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
         EPwm3Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
       */
      EPwm3Regs.DCACTL.all = (EPwm3Regs.DCACTL.all & ~0x30FU) | 0x4U;

      /*	// Digital Compare B Control Register
         EPwm3Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
         EPwm3Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
         EPwm3Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
         EPwm3Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
         EPwm3Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
         EPwm3Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
       */
      EPwm3Regs.DCBCTL.all = (EPwm3Regs.DCBCTL.all & ~0x30FU) | 0x0U;

      /*	// Digital Compare Trip Select Register
         EPwm3Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

         EPwm3Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          // Digital Compare A Low COMP Input Select
         EPwm3Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
         EPwm3Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          // Digital Compare B Low COMP Input Select
       */
      EPwm3Regs.DCTRIPSEL.all = (EPwm3Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

      /*	// Trip Zone Digital Comparator Select Register
         EPwm3Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
         EPwm3Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
         EPwm3Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
         EPwm3Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
       */
      EPwm3Regs.TZDCSEL.all = (EPwm3Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

      /*	// Digital Compare Filter Control Register
         EPwm3Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
         EPwm3Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
         EPwm3Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
         EPwm3Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
       */
      EPwm3Regs.DCFCTL.all = (EPwm3Regs.DCFCTL.all & ~0x3FU) | 0x10U;
      EPwm3Regs.DCFOFFSET = 0U;        // Digital Compare Filter Offset Register
      EPwm3Regs.DCFWINDOW = 0U;        // Digital Compare Filter Window Register

      /*	// Digital Compare Capture Control Register
         EPwm3Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
       */
      EPwm3Regs.DCCAPCTL.all = (EPwm3Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

      /*	// HRPWM Configuration Register
         EPwm3Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
         EPwm3Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
       */
      EPwm3Regs.HRCNFG.all = (EPwm3Regs.HRCNFG.all & ~0xA0U) | 0x0U;
      EDIS;
    }

    /* SystemInitialize for Merge: '<S5>/Merge' */
    Copy_of_mcb_bldc_sixstep_f280_B.Merge = 0.0;

    /* SystemInitialize for IfAction SubSystem: '<S5>/Pos_Commutation' */
    for (i = 0; i < 6; i++) {
      /* SystemInitialize for Merge: '<S19>/Merge' */
      Copy_of_mcb_bldc_sixstep_f280_B.Merge_n[i] = false;
    }

    /* End of SystemInitialize for SubSystem: '<S5>/Pos_Commutation' */

    /* SystemInitialize for IfAction SubSystem: '<S8>/QEP Feedback' */
    /* InitializeConditions for Delay: '<S46>/Delay' */
    Copy_of_mcb_bldc_sixstep__DWork.CircBufIdx = 0U;

    /* End of SystemInitialize for SubSystem: '<S8>/QEP Feedback' */
  }

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S71>/Hardware Interrupt' */
}

/* Model terminate function */
void Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_openLoop_terminate(void)
{
  /* (no terminate code required) */
}

void Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_openLoop_configure_interrupts
  (void)
{
  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(32,&ADCINT1,0);
  HWI_TIC28x_EnableIRQ(32);
}

/* Hardware Interrupt Block: '<S71>/Hardware Interrupt' */
interrupt void ADCINT1(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S71>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Current Control' */
      {
        uint32_T duty;
        int16_T DataTypeConversion1;
        int16_T i;
        uint16_T minV_tmp;
        uint16_T u0;

        /* DataStoreRead: '<S9>/Enable' */
        Copy_of_mcb_bldc_sixstep_f280_B.Enable =
          Copy_of_mcb_bldc_sixstep__DWork.Enable;

        /* S-Function (c280xgpio_do): '<S9>/Digital Output' */
        {
          if (Copy_of_mcb_bldc_sixstep_f280_B.Enable) {
            GpioDataRegs.GPASET.bit.GPIO13 = 1U;
          } else {
            GpioDataRegs.GPACLEAR.bit.GPIO13 = 1U;
          }
        }

        /* S-Function (c2802xadc): '<S11>/Read POT' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          Copy_of_mcb_bldc_sixstep_f280_B.ReadPOT = (AdcResult.ADCRESULT1);
        }

        /* Gain: '<S5>/Gain' */
        Copy_of_mcb_bldc_sixstep_f280_B.Gain = (uint32_T)
          Copy_of_mcb_bldc_sixstep_f280_B.ReadPOT << 15U;

        /* Saturate: '<S5>/Pot_limit' incorporates:
         *  Gain: '<S5>/Gain'
         */
        duty = Copy_of_mcb_bldc_sixstep_f280_B.Gain;
        if ((int32_T)duty <= 120795955L) {
          /* Saturate: '<S5>/Pot_limit' */
          Copy_of_mcb_bldc_sixstep_f280_B.Pot_limit = duty;
        } else {
          /* Saturate: '<S5>/Pot_limit' */
          Copy_of_mcb_bldc_sixstep_f280_B.Pot_limit = 120795955UL;
        }

        /* End of Saturate: '<S5>/Pot_limit' */

        /* S-Function (c280xqep): '<S11>/eQEP' */
        {
          Copy_of_mcb_bldc_sixstep_f280_B.eQEP_o1 = EQep1Regs.QPOSCNT;/*eQEP Position Counter*/
          Copy_of_mcb_bldc_sixstep_f280_B.eQEP_o2 = EQep1Regs.QPOSILAT;
          /* The position-counter value is latched into this register on an IEL*/
        }

        /* Outputs for IfAction SubSystem: '<S8>/QEP Feedback' incorporates:
         *  ActionPort: '<S41>/Action Port'
         */
        /* Outputs for IfAction SubSystem: '<S45>/PositionNoReset' incorporates:
         *  ActionPort: '<S59>/Action Port'
         */
        /* If: '<S8>/If' incorporates:
         *  Constant: '<S41>/IndexOffset'
         *  Constant: '<S49>/Filter_Constant'
         *  Constant: '<S49>/One'
         *  Constant: '<S64>/Constant'
         *  Constant: '<S65>/Constant'
         *  DataTypeConversion: '<S62>/DTC'
         *  DataTypeConversion: '<S67>/DTC'
         *  Delay: '<S46>/Delay'
         *  Gain: '<S46>/PositionToCount'
         *  Gain: '<S46>/SpeedGain'
         *  Gain: '<S57>/Number of pole pairs'
         *  If: '<S45>/If1'
         *  If: '<S52>/If'
         *  Merge: '<S45>/Merge'
         *  MinMax: '<S59>/MinMax'
         *  Product: '<S45>/Product'
         *  Product: '<S49>/Product'
         *  Product: '<S49>/Product1'
         *  Rounding: '<S53>/Floor'
         *  Sum: '<S46>/SpeedCount'
         *  Sum: '<S49>/Add1'
         *  Sum: '<S53>/Add'
         *  Sum: '<S59>/Sum3'
         *  Sum: '<S59>/Sum7'
         *  Switch: '<S51>/Switch'
         *  UnitDelay: '<S49>/Unit Delay'
         * */
        Copy_of_mcb_bldc_sixstep_f280_B.Sum3 =
          Copy_of_mcb_bldc_sixstep_f280_B.eQEP_o1 -
          Copy_of_mcb_bldc_sixstep_f280_B.eQEP_o2;
        Copy_of_mcb_bldc_sixstep_f280_B.Sum7 =
          Copy_of_mcb_bldc_sixstep_f280_B.Sum3 + 10000U;
        u0 = Copy_of_mcb_bldc_sixstep_f280_B.Sum3;
        minV_tmp = Copy_of_mcb_bldc_sixstep_f280_B.Sum7;
        if (u0 <= minV_tmp) {
          minV_tmp = u0;
        }

        Copy_of_mcb_bldc_sixstep_f280_B.Merge_k = minV_tmp;

        /* End of Outputs for SubSystem: '<S45>/PositionNoReset' */
        Copy_of_mcb_bldc_sixstep_f280_B.DTC =
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_k;
        Copy_of_mcb_bldc_sixstep_f280_B.Product =
          Copy_of_mcb_bldc_sixstep_f280_B.DTC * 0.0001F;
        Copy_of_mcb_bldc_sixstep_f280_B.PositionToCount = (uint32_T)
          (4.2949673E+9F * Copy_of_mcb_bldc_sixstep_f280_B.Product);
        Copy_of_mcb_bldc_sixstep_f280_B.Delay =
          Copy_of_mcb_bldc_sixstep__DWork.Delay_DSTATE[Copy_of_mcb_bldc_sixstep__DWork.CircBufIdx];
        Copy_of_mcb_bldc_sixstep_f280_B.SpeedCount = (int32_T)
          Copy_of_mcb_bldc_sixstep_f280_B.PositionToCount - (int32_T)
          Copy_of_mcb_bldc_sixstep_f280_B.Delay;
        Copy_of_mcb_bldc_sixstep_f280_B.DTC_m = (real32_T)
          Copy_of_mcb_bldc_sixstep_f280_B.SpeedCount;
        Copy_of_mcb_bldc_sixstep_f280_B.SpeedGain = 2.70785794E-9F *
          Copy_of_mcb_bldc_sixstep_f280_B.DTC_m;
        Copy_of_mcb_bldc_sixstep_f280_B.Product_c =
          Copy_of_mcb_bldc_sixstep_f280_B.SpeedGain * 0.01F;
        Copy_of_mcb_bldc_sixstep_f280_B.UnitDelay =
          Copy_of_mcb_bldc_sixstep__DWork.UnitDelay_DSTATE;
        Copy_of_mcb_bldc_sixstep_f280_B.Product1 = 0.99F *
          Copy_of_mcb_bldc_sixstep_f280_B.UnitDelay;
        Copy_of_mcb_bldc_sixstep_f280_B.Add1 =
          Copy_of_mcb_bldc_sixstep_f280_B.Product_c +
          Copy_of_mcb_bldc_sixstep_f280_B.Product1;
        Copy_of_mcb_bldc_sixstep_f280_B.Switch = 0.1995F;
        if (Copy_of_mcb_bldc_sixstep_f280_B.Product <= 0.1995F) {
          /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem' incorporates:
           *  ActionPort: '<S54>/Action Port'
           */
          /* Merge: '<S52>/Merge' incorporates:
           *  Constant: '<S54>/Constant'
           *  Sum: '<S54>/Add'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_m =
            (Copy_of_mcb_bldc_sixstep_f280_B.Product + 1.0F) - 0.1995F;

          /* End of Outputs for SubSystem: '<S52>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S55>/Action Port'
           */
          /* Merge: '<S52>/Merge' incorporates:
           *  Sum: '<S55>/Add'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_m =
            Copy_of_mcb_bldc_sixstep_f280_B.Product - 0.1995F;

          /* End of Outputs for SubSystem: '<S52>/If Action Subsystem1' */
        }

        Copy_of_mcb_bldc_sixstep_f280_B.Numberofpolepairs = 5.0F *
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_m;
        Copy_of_mcb_bldc_sixstep_f280_B.Floor = (real32_T)floor
          (Copy_of_mcb_bldc_sixstep_f280_B.Numberofpolepairs);
        Copy_of_mcb_bldc_sixstep_f280_B.Add =
          Copy_of_mcb_bldc_sixstep_f280_B.Numberofpolepairs -
          Copy_of_mcb_bldc_sixstep_f280_B.Floor;
        Copy_of_mcb_bldc_sixstep__DWork.Delay_DSTATE[Copy_of_mcb_bldc_sixstep__DWork.CircBufIdx]
          = Copy_of_mcb_bldc_sixstep_f280_B.PositionToCount;
        if (Copy_of_mcb_bldc_sixstep__DWork.CircBufIdx < 19U) {
          Copy_of_mcb_bldc_sixstep__DWork.CircBufIdx++;
        } else {
          Copy_of_mcb_bldc_sixstep__DWork.CircBufIdx = 0U;
        }

        Copy_of_mcb_bldc_sixstep__DWork.UnitDelay_DSTATE =
          Copy_of_mcb_bldc_sixstep_f280_B.Add1;

        /* End of If: '<S8>/If' */
        /* End of Outputs for SubSystem: '<S8>/QEP Feedback' */

        /* DataStoreRead: '<S5>/Data Store Read' */
        Copy_of_mcb_bldc_sixstep_f280_B.DataStoreRead =
          Copy_of_mcb_bldc_sixstep__DWork.readTorqueSign;

        /* If: '<S5>/If1' */
        if (!Copy_of_mcb_bldc_sixstep_f280_B.DataStoreRead) {
          /* Outputs for IfAction SubSystem: '<S5>/Clockwise' incorporates:
           *  ActionPort: '<S12>/Action Port'
           */
          /* Merge: '<S5>/Merge' incorporates:
           *  Constant: '<S12>/Clockwise'
           *  SignalConversion generated from: '<S12>/CW'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge = 1.0;

          /* End of Outputs for SubSystem: '<S5>/Clockwise' */
        } else {
          /* Outputs for IfAction SubSystem: '<S5>/Counter_Clockwise' incorporates:
           *  ActionPort: '<S13>/Action Port'
           */
          /* Merge: '<S5>/Merge' incorporates:
           *  Constant: '<S13>/Counter_Clockwise'
           *  SignalConversion generated from: '<S13>/CCW'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge = -1.0;

          /* End of Outputs for SubSystem: '<S5>/Counter_Clockwise' */
        }

        /* End of If: '<S5>/If1' */

        /* Signum: '<S5>/Sign' */
        i = (int16_T)Copy_of_mcb_bldc_sixstep_f280_B.Merge;
        if (i < 0) {
          /* Signum: '<S5>/Sign' */
          Copy_of_mcb_bldc_sixstep_f280_B.Sign = -1.0;
        } else {
          /* Signum: '<S5>/Sign' */
          Copy_of_mcb_bldc_sixstep_f280_B.Sign = (i > 0);
        }

        /* End of Signum: '<S5>/Sign' */

        /* Outputs for IfAction SubSystem: '<S5>/Pos_Commutation' incorporates:
         *  ActionPort: '<S14>/Action Port'
         */
        /* Outputs for IfAction SubSystem: '<S15>/Position' incorporates:
         *  ActionPort: '<S17>/Action Port'
         */
        /* If: '<S5>/If' incorporates:
         *  ArithShift: '<S31>/Shift Arithmetic'
         *  ArithShift: '<S31>/Shift Arithmetic1'
         *  DataTypeConversion: '<S31>/Data Type Conversion'
         *  DataTypeConversion: '<S31>/Data Type Conversion1'
         *  DataTypeConversion: '<S31>/Data Type Conversion2'
         *  If: '<S15>/If'
         *  If: '<S18>/Range Check'
         *  If: '<S19>/If'
         *  If: '<S21>/If'
         *  Logic: '<S31>/AND'
         *  Logic: '<S31>/AND1'
         *  Logic: '<S31>/AND2'
         *  Merge: '<S15>/Merge'
         *  Merge: '<S18>/Merge'
         *  S-Function (sfix_bitop): '<S31>/Bitwise AND1'
         *  S-Function (sfix_bitop): '<S31>/Bitwise AND2'
         *  S-Function (sfix_bitop): '<S31>/Bitwise AND3'
         */
        if ((Copy_of_mcb_bldc_sixstep_f280_B.Add > 0.0833F) &&
            (Copy_of_mcb_bldc_sixstep_f280_B.Add <= 0.25F)) {
          /* Outputs for IfAction SubSystem: '<S21>/Enabled Subsystem' incorporates:
           *  ActionPort: '<S22>/Action Port'
           */
          /* SignalConversion generated from: '<S22>/Out1' incorporates:
           *  Constant: '<S22>/Constant'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_j = 2U;

          /* End of Outputs for SubSystem: '<S21>/Enabled Subsystem' */
        } else if ((Copy_of_mcb_bldc_sixstep_f280_B.Add > 0.25F) &&
                   (Copy_of_mcb_bldc_sixstep_f280_B.Add <= 0.4167F)) {
          /* Outputs for IfAction SubSystem: '<S21>/Enabled Subsystem1' incorporates:
           *  ActionPort: '<S23>/Action Port'
           */
          /* SignalConversion generated from: '<S23>/Out1' incorporates:
           *  Constant: '<S23>/Constant'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_j = 3U;

          /* End of Outputs for SubSystem: '<S21>/Enabled Subsystem1' */
        } else if ((Copy_of_mcb_bldc_sixstep_f280_B.Add > 0.4167F) &&
                   (Copy_of_mcb_bldc_sixstep_f280_B.Add <= 0.5833F)) {
          /* Outputs for IfAction SubSystem: '<S21>/Enabled Subsystem2' incorporates:
           *  ActionPort: '<S24>/Action Port'
           */
          /* SignalConversion generated from: '<S24>/Out1' incorporates:
           *  Constant: '<S24>/Constant'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_j = 4U;

          /* End of Outputs for SubSystem: '<S21>/Enabled Subsystem2' */
        } else if ((Copy_of_mcb_bldc_sixstep_f280_B.Add > 0.5833F) &&
                   (Copy_of_mcb_bldc_sixstep_f280_B.Add <= 0.75F)) {
          /* Outputs for IfAction SubSystem: '<S21>/Enabled Subsystem3' incorporates:
           *  ActionPort: '<S25>/Action Port'
           */
          /* SignalConversion generated from: '<S25>/Out1' incorporates:
           *  Constant: '<S25>/Constant'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_j = 5U;

          /* End of Outputs for SubSystem: '<S21>/Enabled Subsystem3' */
        } else if ((Copy_of_mcb_bldc_sixstep_f280_B.Add > 0.75F) &&
                   (Copy_of_mcb_bldc_sixstep_f280_B.Add <= 0.9167F)) {
          /* Outputs for IfAction SubSystem: '<S21>/Enabled Subsystem4' incorporates:
           *  ActionPort: '<S26>/Action Port'
           */
          /* SignalConversion generated from: '<S26>/Out1' incorporates:
           *  Constant: '<S26>/Constant'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_j = 6U;

          /* End of Outputs for SubSystem: '<S21>/Enabled Subsystem4' */
        } else {
          /* Outputs for IfAction SubSystem: '<S21>/Enabled Subsystem6' incorporates:
           *  ActionPort: '<S28>/Action Port'
           */
          /* Outputs for IfAction SubSystem: '<S21>/Enabled Subsystem5' incorporates:
           *  ActionPort: '<S27>/Action Port'
           */
          /* SignalConversion generated from: '<S27>/Out1' incorporates:
           *  SignalConversion generated from: '<S28>/Out1'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_j = (uint16_T)
            ((Copy_of_mcb_bldc_sixstep_f280_B.Add > 0.9167F) ||
             (Copy_of_mcb_bldc_sixstep_f280_B.Add <= 0.0833F));

          /* End of Outputs for SubSystem: '<S21>/Enabled Subsystem5' */
          /* End of Outputs for SubSystem: '<S21>/Enabled Subsystem6' */
        }

        /* End of Outputs for SubSystem: '<S15>/Position' */

        /* Outputs for IfAction SubSystem: '<S18>/Bit Extract' incorporates:
         *  ActionPort: '<S29>/Action Port'
         */
        Copy_of_mcb_bldc_sixstep_f280_B.ShiftArithmetic =
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_j >> 2U;
        Copy_of_mcb_bldc_sixstep_f280_B.A =
          Copy_of_mcb_bldc_sixstep_f280_B.ShiftArithmetic;
        Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion_i =
          (Copy_of_mcb_bldc_sixstep_f280_B.A != 0U);
        Copy_of_mcb_bldc_sixstep_f280_B.Merge_f[0] =
          Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion_i;
        Copy_of_mcb_bldc_sixstep_f280_B.ShiftArithmetic1 =
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_j >> 1U;
        Copy_of_mcb_bldc_sixstep_f280_B.B =
          Copy_of_mcb_bldc_sixstep_f280_B.ShiftArithmetic1 & 1U;
        Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion1_k =
          (Copy_of_mcb_bldc_sixstep_f280_B.B != 0U);
        Copy_of_mcb_bldc_sixstep_f280_B.Merge_f[1] =
          Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion1_k;
        Copy_of_mcb_bldc_sixstep_f280_B.C =
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_j & 1U;
        Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion2 =
          (Copy_of_mcb_bldc_sixstep_f280_B.C != 0U);
        Copy_of_mcb_bldc_sixstep_f280_B.Merge_f[2] =
          Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion2;

        /* End of Outputs for SubSystem: '<S18>/Bit Extract' */
        if (Copy_of_mcb_bldc_sixstep_f280_B.Sign > 0.0) {
          /* Outputs for IfAction SubSystem: '<S19>/positive' incorporates:
           *  ActionPort: '<S33>/Action Port'
           */
          /* CombinatorialLogic: '<S33>/SA1' incorporates:
           *  CombinatorialLogic: '<S33>/SA2'
           *  CombinatorialLogic: '<S33>/SB1'
           *  CombinatorialLogic: '<S33>/SB2'
           *  CombinatorialLogic: '<S33>/SC1'
           *  CombinatorialLogic: '<S33>/SC2'
           *  Merge: '<S19>/Merge'
           */
          minV_tmp = Copy_of_mcb_bldc_sixstep_f280_B.Merge_f[0U];
          minV_tmp = (minV_tmp << 1) + Copy_of_mcb_bldc_sixstep_f280_B.Merge_f
            [1U];
          minV_tmp = (minV_tmp << 1) + Copy_of_mcb_bldc_sixstep_f280_B.Merge_f
            [2U];
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_n[0] =
            Copy_of_mcb_bldc_sixstep_ConstP.pooled8[minV_tmp];

          /* CombinatorialLogic: '<S33>/SA2' incorporates:
           *  Merge: '<S19>/Merge'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_n[1] =
            Copy_of_mcb_bldc_sixstep_ConstP.pooled7[minV_tmp];

          /* CombinatorialLogic: '<S33>/SB1' incorporates:
           *  Merge: '<S19>/Merge'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_n[2] =
            Copy_of_mcb_bldc_sixstep_ConstP.pooled10[minV_tmp];

          /* CombinatorialLogic: '<S33>/SB2' incorporates:
           *  Merge: '<S19>/Merge'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_n[3] =
            Copy_of_mcb_bldc_sixstep_ConstP.pooled9[minV_tmp];

          /* CombinatorialLogic: '<S33>/SC1' incorporates:
           *  Merge: '<S19>/Merge'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_n[4] =
            Copy_of_mcb_bldc_sixstep_ConstP.pooled12[minV_tmp];

          /* CombinatorialLogic: '<S33>/SC2' incorporates:
           *  Merge: '<S19>/Merge'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_n[5] =
            Copy_of_mcb_bldc_sixstep_ConstP.pooled11[minV_tmp];

          /* End of Outputs for SubSystem: '<S19>/positive' */
        } else {
          /* Outputs for IfAction SubSystem: '<S19>/negative' incorporates:
           *  ActionPort: '<S32>/Action Port'
           */
          /* CombinatorialLogic: '<S32>/SA1' incorporates:
           *  CombinatorialLogic: '<S32>/SA2'
           *  CombinatorialLogic: '<S32>/SB1'
           *  CombinatorialLogic: '<S32>/SB2'
           *  CombinatorialLogic: '<S32>/SC1'
           *  CombinatorialLogic: '<S32>/SC2'
           *  Merge: '<S19>/Merge'
           */
          minV_tmp = Copy_of_mcb_bldc_sixstep_f280_B.Merge_f[0U];
          minV_tmp = (minV_tmp << 1) + Copy_of_mcb_bldc_sixstep_f280_B.Merge_f
            [1U];
          minV_tmp = (minV_tmp << 1) + Copy_of_mcb_bldc_sixstep_f280_B.Merge_f
            [2U];
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_n[0] =
            Copy_of_mcb_bldc_sixstep_ConstP.pooled7[minV_tmp];

          /* CombinatorialLogic: '<S32>/SA2' incorporates:
           *  Merge: '<S19>/Merge'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_n[1] =
            Copy_of_mcb_bldc_sixstep_ConstP.pooled8[minV_tmp];

          /* CombinatorialLogic: '<S32>/SB1' incorporates:
           *  Merge: '<S19>/Merge'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_n[2] =
            Copy_of_mcb_bldc_sixstep_ConstP.pooled9[minV_tmp];

          /* CombinatorialLogic: '<S32>/SB2' incorporates:
           *  Merge: '<S19>/Merge'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_n[3] =
            Copy_of_mcb_bldc_sixstep_ConstP.pooled10[minV_tmp];

          /* CombinatorialLogic: '<S32>/SC1' incorporates:
           *  Merge: '<S19>/Merge'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_n[4] =
            Copy_of_mcb_bldc_sixstep_ConstP.pooled11[minV_tmp];

          /* CombinatorialLogic: '<S32>/SC2' incorporates:
           *  Merge: '<S19>/Merge'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.Merge_n[5] =
            Copy_of_mcb_bldc_sixstep_ConstP.pooled12[minV_tmp];

          /* End of Outputs for SubSystem: '<S19>/negative' */
        }

        /* End of If: '<S5>/If' */
        /* End of Outputs for SubSystem: '<S5>/Pos_Commutation' */
        for (i = 0; i < 6; i++) {
          /* Switch: '<S9>/Switch1' */
          if (Copy_of_mcb_bldc_sixstep_f280_B.Enable) {
            /* DataTypeConversion: '<S5>/Data Type Conversion1' */
            DataTypeConversion1 = (int16_T)
              Copy_of_mcb_bldc_sixstep_f280_B.Merge_n[i];
            Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion1[i] =
              DataTypeConversion1;

            /* Product: '<S5>/Product' incorporates:
             *  Saturate: '<S5>/Pot_limit'
             */
            duty = (uint32_T)((real32_T)
                              Copy_of_mcb_bldc_sixstep_f280_B.Pot_limit *
                              7.4505806E-9F * (real32_T)DataTypeConversion1 *
                              1.34217728E+8F);
            Copy_of_mcb_bldc_sixstep_f280_B.duty[i] = duty;

            /* Gain: '<S9>/Scale_to_PWM_Counter_PRD' incorporates:
             *  Product: '<S5>/Product'
             */
            u0 = (uint16_T)((1125ULL * duty) >> 26U);
            Copy_of_mcb_bldc_sixstep_f280_B.Scale_to_PWM_Counter_PRD[i] = u0;

            /* Switch: '<S9>/Switch1' */
            Copy_of_mcb_bldc_sixstep_f280_B.Switch1[i] = u0;
          } else {
            /* Switch: '<S9>/Switch1' */
            Copy_of_mcb_bldc_sixstep_f280_B.Switch1[i] = 0U;
          }

          /* End of Switch: '<S9>/Switch1' */
        }

        /* S-Function (c2802xpwm): '<S9>/ePWM4' */

        /*-- Update CMPA value for ePWM1 --*/
        {
          EPwm1Regs.CMPA.half.CMPA = (uint16_T)
            (Copy_of_mcb_bldc_sixstep_f280_B.Switch1[0]);
        }

        /*-- Update CMPB value for ePWM1 --*/
        {
          EPwm1Regs.CMPB = (uint16_T)(Copy_of_mcb_bldc_sixstep_f280_B.Switch1[1]);
        }

        /* S-Function (c2802xpwm): '<S9>/ePWM5' */

        /*-- Update CMPA value for ePWM2 --*/
        {
          EPwm2Regs.CMPA.half.CMPA = (uint16_T)
            (Copy_of_mcb_bldc_sixstep_f280_B.Switch1[2]);
        }

        /*-- Update CMPB value for ePWM2 --*/
        {
          EPwm2Regs.CMPB = (uint16_T)(Copy_of_mcb_bldc_sixstep_f280_B.Switch1[3]);
        }

        /* S-Function (c2802xpwm): '<S9>/ePWM6' */

        /*-- Update CMPA value for ePWM3 --*/
        {
          EPwm3Regs.CMPA.half.CMPA = (uint16_T)
            (Copy_of_mcb_bldc_sixstep_f280_B.Switch1[4]);
        }

        /*-- Update CMPB value for ePWM3 --*/
        {
          EPwm3Regs.CMPB = (uint16_T)(Copy_of_mcb_bldc_sixstep_f280_B.Switch1[5]);
        }

        /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
         *  Saturate: '<S5>/Pot_limit'
         */
        Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion = (real32_T)
          Copy_of_mcb_bldc_sixstep_f280_B.Pot_limit * 7.4505806E-9F;

        /* UnitDelay: '<S34>/Output' */
        Copy_of_mcb_bldc_sixstep_f280_B.Output =
          Copy_of_mcb_bldc_sixstep__DWork.Output_DSTATE;

        /* DataTypeConversion: '<S36>/Data Type Conversion' */
        Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion_l[0] = (int16_T)
          (Copy_of_mcb_bldc_sixstep_f280_B.Add1 * 4096.0F);
        Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion_l[1] = (int16_T)
          (Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion * 4096.0F);

        /* DataTypeConversion: '<S36>/Data Type Conversion1' incorporates:
         *  DataTypeConversion: '<S36>/Data Type Conversion'
         */
        Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion1_d[0] = (uint16_T)
          Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion_l[0];
        Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion1_d[1] = (uint16_T)
          Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion_l[1];

        /* If: '<S7>/If' */
        if (Copy_of_mcb_bldc_sixstep_f280_B.Output == 0U) {
          /* Outputs for IfAction SubSystem: '<S7>/Start' incorporates:
           *  ActionPort: '<S38>/Action Port'
           */
          /* Merge: '<S7>/Merge' incorporates:
           *  Constant: '<S38>/End'
           *  SignalConversion generated from: '<S38>/Data_out'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.SCI_Tx_Data[0] = 21331U;

          /* SignalConversion generated from: '<S38>/Data' */
          u0 = Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion1_d[0];

          /* End of Outputs for SubSystem: '<S7>/Start' */
          Copy_of_mcb_bldc_sixstep_f280_B.Data_fw[0] = u0;

          /* Outputs for IfAction SubSystem: '<S7>/Start' incorporates:
           *  ActionPort: '<S38>/Action Port'
           */
          /* Merge: '<S7>/Merge' incorporates:
           *  SignalConversion generated from: '<S38>/Data_out'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.SCI_Tx_Data[1] = u0;

          /* SignalConversion generated from: '<S38>/Data' */
          u0 = Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion1_d[1];

          /* End of Outputs for SubSystem: '<S7>/Start' */
          Copy_of_mcb_bldc_sixstep_f280_B.Data_fw[1] = u0;

          /* Outputs for IfAction SubSystem: '<S7>/Start' incorporates:
           *  ActionPort: '<S38>/Action Port'
           */
          /* Merge: '<S7>/Merge' incorporates:
           *  SignalConversion generated from: '<S38>/Data_out'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.SCI_Tx_Data[2] = u0;

          /* Merge: '<S7>/Merge1' incorporates:
           *  Bias: '<S38>/Bias'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.SCI_Tx_Iteration =
            Copy_of_mcb_bldc_sixstep_ConstB.Width + 1U;

          /* End of Outputs for SubSystem: '<S7>/Start' */
        } else if (Copy_of_mcb_bldc_sixstep_f280_B.Output == 599U) {
          /* Outputs for IfAction SubSystem: '<S7>/End' incorporates:
           *  ActionPort: '<S37>/Action Port'
           */
          /* SignalConversion generated from: '<S37>/Data' */
          u0 = Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion1_d[0];

          /* End of Outputs for SubSystem: '<S7>/End' */
          Copy_of_mcb_bldc_sixstep_f280_B.Data_f[0] = u0;

          /* Outputs for IfAction SubSystem: '<S7>/End' incorporates:
           *  ActionPort: '<S37>/Action Port'
           */
          /* Merge: '<S7>/Merge' incorporates:
           *  SignalConversion generated from: '<S37>/Data_out'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.SCI_Tx_Data[0] = u0;

          /* SignalConversion generated from: '<S37>/Data' */
          u0 = Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion1_d[1];

          /* End of Outputs for SubSystem: '<S7>/End' */
          Copy_of_mcb_bldc_sixstep_f280_B.Data_f[1] = u0;

          /* Outputs for IfAction SubSystem: '<S7>/End' incorporates:
           *  ActionPort: '<S37>/Action Port'
           */
          /* Merge: '<S7>/Merge' incorporates:
           *  Constant: '<S37>/Start'
           *  SignalConversion generated from: '<S37>/Data_out'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.SCI_Tx_Data[1] = u0;
          Copy_of_mcb_bldc_sixstep_f280_B.SCI_Tx_Data[2] = 17733U;

          /* Merge: '<S7>/Merge1' incorporates:
           *  Bias: '<S37>/Bias'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.SCI_Tx_Iteration =
            Copy_of_mcb_bldc_sixstep_ConstB.Width + 1U;

          /* End of Outputs for SubSystem: '<S7>/End' */
        } else {
          /* Outputs for IfAction SubSystem: '<S7>/Data' incorporates:
           *  ActionPort: '<S35>/Action Port'
           */
          /* SignalConversion generated from: '<S35>/Data' */
          u0 = Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion1_d[0];

          /* End of Outputs for SubSystem: '<S7>/Data' */
          Copy_of_mcb_bldc_sixstep_f280_B.Data[0] = u0;

          /* Outputs for IfAction SubSystem: '<S7>/Data' incorporates:
           *  ActionPort: '<S35>/Action Port'
           */
          /* Merge: '<S7>/Merge' incorporates:
           *  SignalConversion generated from: '<S35>/Data_out'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.SCI_Tx_Data[0] = u0;

          /* SignalConversion generated from: '<S35>/Data' */
          u0 = Copy_of_mcb_bldc_sixstep_f280_B.DataTypeConversion1_d[1];

          /* End of Outputs for SubSystem: '<S7>/Data' */
          Copy_of_mcb_bldc_sixstep_f280_B.Data[1] = u0;

          /* Outputs for IfAction SubSystem: '<S7>/Data' incorporates:
           *  ActionPort: '<S35>/Action Port'
           */
          /* Merge: '<S7>/Merge' incorporates:
           *  Constant: '<S35>/Start'
           *  SignalConversion generated from: '<S35>/Data_out'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.SCI_Tx_Data[1] = u0;
          Copy_of_mcb_bldc_sixstep_f280_B.SCI_Tx_Data[2] = 0U;

          /* Merge: '<S7>/Merge1' incorporates:
           *  SignalConversion generated from: '<S35>/Data_width'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.SCI_Tx_Iteration =
            Copy_of_mcb_bldc_sixstep_ConstB.Width;

          /* End of Outputs for SubSystem: '<S7>/Data' */
        }

        /* End of If: '<S7>/If' */

        /* Outputs for Iterator SubSystem: '<S10>/CodeGeneration' incorporates:
         *  WhileIterator: '<S68>/While Iterator'
         */
        i = 1;
        do {
          Copy_of_mcb_bldc_sixstep_f280_B.WhileIterator = i;
          Copy_of_mcb_bldc_sixstep_f280_B.IndexVector =
            Copy_of_mcb_bldc_sixstep_f280_B.SCI_Tx_Data[Copy_of_mcb_bldc_sixstep_f280_B.WhileIterator
            - 1];

          {
            if (checkSCITransmitInProgressA != 1U) {
              checkSCITransmitInProgressA = 1U;
              int16_T errFlgHeader = NOERROR;
              int16_T errFlgData = NOERROR;
              int16_T errFlgTail = NOERROR;
              errFlgData = scia_xmit((unsigned char*)
                &Copy_of_mcb_bldc_sixstep_f280_B.IndexVector, 2, 2);
              checkSCITransmitInProgressA = 0U;
            }
          }

          Copy_of_mcb_bldc_sixstep_f280_B.Add_n =
            Copy_of_mcb_bldc_sixstep_f280_B.SCI_Tx_Iteration - (uint16_T)
            Copy_of_mcb_bldc_sixstep_f280_B.WhileIterator;
          i++;
        } while (Copy_of_mcb_bldc_sixstep_f280_B.Add_n != 0U);

        /* End of Outputs for SubSystem: '<S10>/CodeGeneration' */

        /* Sum: '<S39>/FixPt Sum1' incorporates:
         *  Constant: '<S39>/FixPt Constant'
         */
        Copy_of_mcb_bldc_sixstep_f280_B.FixPtSum1 =
          Copy_of_mcb_bldc_sixstep_f280_B.Output + 1U;

        /* Switch: '<S40>/FixPt Switch' */
        if (Copy_of_mcb_bldc_sixstep_f280_B.FixPtSum1 > 599U) {
          /* Switch: '<S40>/FixPt Switch' incorporates:
           *  Constant: '<S40>/Constant'
           */
          Copy_of_mcb_bldc_sixstep_f280_B.FixPtSwitch = 0U;
        } else {
          /* Switch: '<S40>/FixPt Switch' */
          Copy_of_mcb_bldc_sixstep_f280_B.FixPtSwitch =
            Copy_of_mcb_bldc_sixstep_f280_B.FixPtSum1;
        }

        /* End of Switch: '<S40>/FixPt Switch' */

        /* Update for UnitDelay: '<S34>/Output' */
        Copy_of_mcb_bldc_sixstep__DWork.Output_DSTATE =
          Copy_of_mcb_bldc_sixstep_f280_B.FixPtSwitch;
      }

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S71>/Hardware Interrupt' */
    }
  }

  /* Clear occurred EOC event event */
  AdcRegs.ADCINTFLGCLR.bit.ADCINT1= 1;

  /* Clear occurred Overflow event event */
  AdcRegs.ADCINTOVFCLR.bit.ADCINT1= 1;
  HWI_TIC28x_AcknowledgeIrq(32);
}

void Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_openLoop_unconfigure_interrupts
  (void)
{
  HWI_TIC28x_DisableIRQ(32);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
