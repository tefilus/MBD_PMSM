/*
 * File: mcb_bldc_sixstep_f28069mLaunchPad_closeLoop.c
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

#include "mcb_bldc_sixstep_f28069mLaunchPad_closeLoop.h"
#include "mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_private.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "To_LCD.h"
#include <string.h>

/* Block signals (default storage) */
BlockIO_mcb_bldc_sixstep_f28069 mcb_bldc_sixstep_f28069mLaunc_B;

/* Block states (default storage) */
D_Work_mcb_bldc_sixstep_f28069m mcb_bldc_sixstep_f28069mL_DWork;

/* Real-time model */
static RT_MODEL_mcb_bldc_sixstep_f2806 mcb_bldc_sixstep_f28069mLaun_M_;
RT_MODEL_mcb_bldc_sixstep_f2806 *const mcb_bldc_sixstep_f28069mLaun_M =
  &mcb_bldc_sixstep_f28069mLaun_M_;
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
void mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_SetEventsForThisBaseStep
  (boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(mcb_bldc_sixstep_f28069mLaun_M, 1));
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
  (mcb_bldc_sixstep_f28069mLaun_M->Timing.TaskCounters.TID[1])++;
  if ((mcb_bldc_sixstep_f28069mLaun_M->Timing.TaskCounters.TID[1]) > 199) {/* Sample time: [0.1s, 0.0s] */
    mcb_bldc_sixstep_f28069mLaun_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* System initialize for function-call system: '<Root>/Current Control' */
void mcb_bld_CurrentControl_Init(void)
{
  /* Start for S-Function (c280xqep): '<S16>/eQEP' */
  config_QEP_eQEP1((uint32_T)65535U,(uint32_T)0, (uint32_T)0, (uint32_T)0,
                   (uint16_T)0, (uint16_T)448, (uint16_T)8232, (uint16_T)32768,
                   (uint16_T)119,(uint16_T)0);

  /* Start for S-Function (c2802xadc): '<S16>/speedRef_ADC' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_SOC15 ();

  /* Start for S-Function (c2802xadc): '<S16>/IA//IB Measurement' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_SOC0_SOC1 ();

  /* Start for S-Function (c2802xadc): '<S16>/IC Measurement' */
  if (MW_adcInitFlag == 0U) {
    InitAdc();
    MW_adcInitFlag = 1U;
  }

  config_ADC_SOC2 ();

  /* Start for S-Function (c280xgpio_do): '<S11>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPBMUX2.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPBDIR.all |= 0x40000U;
  EDIS;

  /* Start for Constant: '<S17>/Kp1' */
  mcb_bldc_sixstep_f28069mLaunc_B.Kp1 = 0.0F;

  /* Start for S-Function (c2802xpwm): '<S11>/ePWM4' */

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
    EPwm1Regs.TBPRD = 2250U;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm1Regs.TBPHS.half.TBPHS               = 0U;         // Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x5FU) | 0x0U;
    EPwm1Regs.CMPA.half.CMPA = 1126U;  // Counter Compare A Register
    EPwm1Regs.CMPB = 1126U;            // Counter Compare B Register

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
    EPwm1Regs.DBRED = 0U;// Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED = 0U;
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 1U;          // Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASEL              = 1U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCAPRD               = 1U;          // EPWM1SOCA Period Select
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion B Select
       EPwm1Regs.ETPS.bit.SOCBPRD               = 1U;          // EPWM1SOCB Period Select
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          // EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          // EPWM1INTn Select
       EPwm1Regs.ETPS.bit.INTPRD                = 1U;          // EPWM1INTn Period Select
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF0FU) | 0x1901U;
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
    EPwm1Regs.TZSEL.all = 0U;          // Trip Zone Select Register

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
    EPwm1Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

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

  /* Start for S-Function (c2802xpwm): '<S11>/ePWM5' */

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
    EPwm2Regs.TBPRD = 2250U;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm2Regs.TBPHS.half.TBPHS               = 0U;         // Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm2Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm2Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x5FU) | 0x0U;
    EPwm2Regs.CMPA.half.CMPA = 1126U;  // Counter Compare A Register
    EPwm2Regs.CMPB = 1126U;            // Counter Compare B Register

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
    EPwm2Regs.DBRED = 0U;// Dead-Band Generator Rising Edge Delay Count Register
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
    EPwm2Regs.TZSEL.all = 0U;          // Trip Zone Select Register

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
    EPwm2Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm2Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

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

  /* Start for S-Function (c2802xpwm): '<S11>/ePWM6' */

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
    EPwm3Regs.TBPRD = 2250U;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm3Regs.TBPHS.half.TBPHS               = 0U;         // Phase offset register
     */
    EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm3Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm3Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm3Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm3Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm3Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x5FU) | 0x0U;
    EPwm3Regs.CMPA.half.CMPA = 1126U;  // Counter Compare A Register
    EPwm3Regs.CMPB = 1126U;            // Counter Compare B Register

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
    EPwm3Regs.DBRED = 0U;// Dead-Band Generator Rising Edge Delay Count Register
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
    EPwm3Regs.TZSEL.all = 0U;          // Trip Zone Select Register

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
    EPwm3Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm3Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

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

  /* InitializeConditions for DiscreteIntegrator: '<S53>/Integrator' */
  mcb_bldc_sixstep_f28069mL_DWork.Integrator_DSTATE = 0.0F;
  mcb_bldc_sixstep_f28069mL_DWork.Integrator_PrevResetState = 0;

  /* SystemInitialize for Merge: '<S127>/Merge1' */
  mcb_bldc_sixstep_f28069mLaunc_B.Merge1 = 0.0;

  /* SystemInitialize for Atomic SubSystem: '<S15>/QEP Feedback' */
  /* InitializeConditions for Delay: '<S104>/Delay' */
  mcb_bldc_sixstep_f28069mL_DWork.CircBufIdx = 0U;

  /* End of SystemInitialize for SubSystem: '<S15>/QEP Feedback' */
}

/* System reset for function-call system: '<Root>/Current Control' */
void mcb_bl_CurrentControl_Reset(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S53>/Integrator' */
  mcb_bldc_sixstep_f28069mL_DWork.Integrator_DSTATE =
    mcb_bldc_sixstep_f28069mLaunc_B.Kp1;
  mcb_bldc_sixstep_f28069mL_DWork.Integrator_PrevResetState = 0;

  /* SystemReset for Atomic SubSystem: '<S15>/QEP Feedback' */
  /* InitializeConditions for Delay: '<S104>/Delay' */
  mcb_bldc_sixstep_f28069mL_DWork.CircBufIdx = 0U;

  /* End of SystemReset for SubSystem: '<S15>/QEP Feedback' */
}

/* Output and update for function-call system: '<Root>/Current Control' */
#pragma CODE_SECTION (mcb_bldc_six_CurrentControl, "ramfuncs")

void mcb_bldc_six_CurrentControl(void)
{
  real_T cu;
  int32_T Q17perunitconversion;
  real32_T DataTypeConversion1;
  int16_T DataTypeConversion1_o;
  int16_T i;
  uint16_T minV_tmp;
  uint16_T u0;

  /* S-Function (c280xqep): '<S16>/eQEP' */
  {
    mcb_bldc_sixstep_f28069mLaunc_B.eQEP_o1 = EQep1Regs.QPOSCNT;/*eQEP Position Counter*/
    mcb_bldc_sixstep_f28069mLaunc_B.eQEP_o2 = EQep1Regs.QPOSILAT;
         /* The position-counter value is latched into this register on an IEL*/
  }

  /* Outputs for Atomic SubSystem: '<S15>/QEP Feedback' */
  /* Outputs for IfAction SubSystem: '<S103>/PositionNoReset' incorporates:
   *  ActionPort: '<S117>/Action Port'
   */
  /* If: '<S103>/If1' incorporates:
   *  Constant: '<S122>/Constant'
   *  Merge: '<S103>/Merge'
   *  MinMax: '<S117>/MinMax'
   *  Sum: '<S117>/Sum3'
   *  Sum: '<S117>/Sum7'
   */
  mcb_bldc_sixstep_f28069mLaunc_B.Sum3 = mcb_bldc_sixstep_f28069mLaunc_B.eQEP_o1
    - mcb_bldc_sixstep_f28069mLaunc_B.eQEP_o2;
  mcb_bldc_sixstep_f28069mLaunc_B.Sum7 = mcb_bldc_sixstep_f28069mLaunc_B.Sum3 +
    10000U;
  u0 = mcb_bldc_sixstep_f28069mLaunc_B.Sum3;
  minV_tmp = mcb_bldc_sixstep_f28069mLaunc_B.Sum7;
  if (u0 <= minV_tmp) {
    minV_tmp = u0;
  }

  mcb_bldc_sixstep_f28069mLaunc_B.Merge_g = minV_tmp;

  /* End of If: '<S103>/If1' */
  /* End of Outputs for SubSystem: '<S103>/PositionNoReset' */

  /* DataTypeConversion: '<S120>/DTC' */
  mcb_bldc_sixstep_f28069mLaunc_B.DTC = mcb_bldc_sixstep_f28069mLaunc_B.Merge_g;

  /* Product: '<S103>/Product' incorporates:
   *  Constant: '<S123>/Constant'
   */
  mcb_bldc_sixstep_f28069mLaunc_B.Product = mcb_bldc_sixstep_f28069mLaunc_B.DTC *
    0.0001F;

  /* Gain: '<S104>/PositionToCount' */
  mcb_bldc_sixstep_f28069mLaunc_B.PositionToCount = (uint32_T)(4.2949673E+9F *
    mcb_bldc_sixstep_f28069mLaunc_B.Product);

  /* Delay: '<S104>/Delay' */
  mcb_bldc_sixstep_f28069mLaunc_B.Delay =
    mcb_bldc_sixstep_f28069mL_DWork.Delay_DSTATE[mcb_bldc_sixstep_f28069mL_DWork.CircBufIdx];

  /* Sum: '<S104>/SpeedCount' */
  mcb_bldc_sixstep_f28069mLaunc_B.SpeedCount = (int32_T)
    mcb_bldc_sixstep_f28069mLaunc_B.PositionToCount - (int32_T)
    mcb_bldc_sixstep_f28069mLaunc_B.Delay;

  /* DataTypeConversion: '<S125>/DTC' */
  mcb_bldc_sixstep_f28069mLaunc_B.DTC_a = (real32_T)
    mcb_bldc_sixstep_f28069mLaunc_B.SpeedCount;

  /* Gain: '<S104>/SpeedGain' */
  mcb_bldc_sixstep_f28069mLaunc_B.SpeedGain = 2.70785794E-9F *
    mcb_bldc_sixstep_f28069mLaunc_B.DTC_a;

  /* Product: '<S107>/Product' incorporates:
   *  Constant: '<S107>/Filter_Constant'
   */
  mcb_bldc_sixstep_f28069mLaunc_B.Product_g =
    mcb_bldc_sixstep_f28069mLaunc_B.SpeedGain * 0.01F;

  /* UnitDelay: '<S107>/Unit Delay' */
  mcb_bldc_sixstep_f28069mLaunc_B.UnitDelay =
    mcb_bldc_sixstep_f28069mL_DWork.UnitDelay_DSTATE;

  /* Product: '<S107>/Product1' incorporates:
   *  Constant: '<S107>/One'
   */
  mcb_bldc_sixstep_f28069mLaunc_B.Product1 = 0.99F *
    mcb_bldc_sixstep_f28069mLaunc_B.UnitDelay;

  /* Sum: '<S107>/Add1' */
  mcb_bldc_sixstep_f28069mLaunc_B.Add1 =
    mcb_bldc_sixstep_f28069mLaunc_B.Product_g +
    mcb_bldc_sixstep_f28069mLaunc_B.Product1;

  /* Switch: '<S109>/Switch' incorporates:
   *  Constant: '<S98>/IndexOffset'
   */
  mcb_bldc_sixstep_f28069mLaunc_B.Switch_f = 0.1995F;

  /* If: '<S110>/If' */
  if (mcb_bldc_sixstep_f28069mLaunc_B.Product <= 0.1995F) {
    /* Outputs for IfAction SubSystem: '<S110>/If Action Subsystem' incorporates:
     *  ActionPort: '<S112>/Action Port'
     */
    /* Merge: '<S110>/Merge' incorporates:
     *  Constant: '<S112>/Constant'
     *  Sum: '<S112>/Add'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge =
      (mcb_bldc_sixstep_f28069mLaunc_B.Product + 1.0F) - 0.1995F;

    /* End of Outputs for SubSystem: '<S110>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S110>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S113>/Action Port'
     */
    /* Merge: '<S110>/Merge' incorporates:
     *  Sum: '<S113>/Add'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge =
      mcb_bldc_sixstep_f28069mLaunc_B.Product - 0.1995F;

    /* End of Outputs for SubSystem: '<S110>/If Action Subsystem1' */
  }

  /* End of If: '<S110>/If' */

  /* Gain: '<S115>/Number of pole pairs' */
  mcb_bldc_sixstep_f28069mLaunc_B.Numberofpolepairs = 5.0F *
    mcb_bldc_sixstep_f28069mLaunc_B.Merge;

  /* Rounding: '<S111>/Floor' */
  mcb_bldc_sixstep_f28069mLaunc_B.Floor = (real32_T)floor
    (mcb_bldc_sixstep_f28069mLaunc_B.Numberofpolepairs);

  /* Sum: '<S111>/Add' */
  mcb_bldc_sixstep_f28069mLaunc_B.Add =
    mcb_bldc_sixstep_f28069mLaunc_B.Numberofpolepairs -
    mcb_bldc_sixstep_f28069mLaunc_B.Floor;

  /* Update for Delay: '<S104>/Delay' */
  mcb_bldc_sixstep_f28069mL_DWork.Delay_DSTATE[mcb_bldc_sixstep_f28069mL_DWork.CircBufIdx]
    = mcb_bldc_sixstep_f28069mLaunc_B.PositionToCount;
  if (mcb_bldc_sixstep_f28069mL_DWork.CircBufIdx < 19U) {
    mcb_bldc_sixstep_f28069mL_DWork.CircBufIdx++;
  } else {
    mcb_bldc_sixstep_f28069mL_DWork.CircBufIdx = 0U;
  }

  /* End of Update for Delay: '<S104>/Delay' */

  /* Update for UnitDelay: '<S107>/Unit Delay' */
  mcb_bldc_sixstep_f28069mL_DWork.UnitDelay_DSTATE =
    mcb_bldc_sixstep_f28069mLaunc_B.Add1;

  /* End of Outputs for SubSystem: '<S15>/QEP Feedback' */

  /* DataStoreWrite: '<S2>/Data Store Write' */
  mcb_bldc_sixstep_f28069mL_DWork.speedSCI_B =
    mcb_bldc_sixstep_f28069mLaunc_B.Add1;

  /* DataStoreRead: '<S127>/Data Store Read' */
  mcb_bldc_sixstep_f28069mLaunc_B.DataStoreRead_e =
    mcb_bldc_sixstep_f28069mL_DWork.readTorqueSign;

  /* If: '<S127>/If1' */
  if (!mcb_bldc_sixstep_f28069mLaunc_B.DataStoreRead_e) {
    /* Outputs for IfAction SubSystem: '<S127>/Clockwise' incorporates:
     *  ActionPort: '<S128>/Action Port'
     */
    /* Merge: '<S127>/Merge1' incorporates:
     *  Constant: '<S128>/Clockwise'
     *  SignalConversion generated from: '<S128>/CW'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge1 = 1.0;

    /* End of Outputs for SubSystem: '<S127>/Clockwise' */
  } else {
    /* Outputs for IfAction SubSystem: '<S127>/Counter_Clockwise' incorporates:
     *  ActionPort: '<S129>/Action Port'
     */
    /* Merge: '<S127>/Merge1' incorporates:
     *  Constant: '<S129>/Counter_Clockwise'
     *  SignalConversion generated from: '<S129>/CCW'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge1 = -1.0;

    /* End of Outputs for SubSystem: '<S127>/Counter_Clockwise' */
  }

  /* End of If: '<S127>/If1' */

  /* Signum: '<S127>/Sign' */
  i = (int16_T)mcb_bldc_sixstep_f28069mLaunc_B.Merge1;
  if (i < 0) {
    /* Signum: '<S127>/Sign' */
    mcb_bldc_sixstep_f28069mLaunc_B.Sign = -1.0;
  } else {
    /* Signum: '<S127>/Sign' */
    mcb_bldc_sixstep_f28069mLaunc_B.Sign = (i > 0);
  }

  /* End of Signum: '<S127>/Sign' */

  /* S-Function (c2802xadc): '<S16>/speedRef_ADC' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_bldc_sixstep_f28069mLaunc_B.speedRef_ADC = (AdcResult.ADCRESULT15);
  }

  /* Switch: '<S126>/ADCThreshold' */
  if (mcb_bldc_sixstep_f28069mLaunc_B.speedRef_ADC > 44U) {
    /* Sum: '<S126>/Sum' incorporates:
     *  Constant: '<S126>/Constant'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Sum = (real_T)
      mcb_bldc_sixstep_f28069mLaunc_B.speedRef_ADC - 44.0;

    /* Switch: '<S126>/ADCThreshold' */
    mcb_bldc_sixstep_f28069mLaunc_B.ADCThreshold =
      mcb_bldc_sixstep_f28069mLaunc_B.Sum;
  } else {
    /* Switch: '<S126>/ADCThreshold' incorporates:
     *  Constant: '<S126>/LowerThreshold'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.ADCThreshold = 0.0;
  }

  /* End of Switch: '<S126>/ADCThreshold' */

  /* Gain: '<S126>/toPU' */
  mcb_bldc_sixstep_f28069mLaunc_B.toPU = (real32_T)(0.000244140625 *
    mcb_bldc_sixstep_f28069mLaunc_B.ADCThreshold);

  /* Product: '<S126>/conductSpeed' */
  mcb_bldc_sixstep_f28069mLaunc_B.conductSpeed = (real32_T)
    (mcb_bldc_sixstep_f28069mLaunc_B.Sign * mcb_bldc_sixstep_f28069mLaunc_B.toPU);

  /* DataStoreWrite: '<S16>/desiredSpeedPU' */
  mcb_bldc_sixstep_f28069mL_DWork.desiredSpeed =
    mcb_bldc_sixstep_f28069mLaunc_B.conductSpeed;

  /* S-Function (c2802xadc): '<S16>/IA//IB Measurement' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_bldc_sixstep_f28069mLaunc_B.IAIBMeasurement_p[0] = (AdcResult.ADCRESULT0);
    mcb_bldc_sixstep_f28069mLaunc_B.IAIBMeasurement_p[1] = (AdcResult.ADCRESULT1);
  }

  /* S-Function (c2802xadc): '<S16>/IC Measurement' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_bldc_sixstep_f28069mLaunc_B.ICMeasurement_l = (AdcResult.ADCRESULT2);
  }

  /* DataStoreRead: '<S11>/Enable' */
  mcb_bldc_sixstep_f28069mLaunc_B.Enable =
    mcb_bldc_sixstep_f28069mL_DWork.Enable;

  /* S-Function (c280xgpio_do): '<S11>/Digital Output' */
  {
    if (mcb_bldc_sixstep_f28069mLaunc_B.Enable) {
      GpioDataRegs.GPBSET.bit.GPIO50 = 1U;
    } else {
      GpioDataRegs.GPBCLEAR.bit.GPIO50 = 1U;
    }
  }

  /* Abs: '<S12>/Abs' */
  mcb_bldc_sixstep_f28069mLaunc_B.Idc_ref = fabsf
    (mcb_bldc_sixstep_f28069mLaunc_B.RT2);

  /* DataStoreRead: '<S97>/Data Store Read' */
  mcb_bldc_sixstep_f28069mLaunc_B.DataStoreRead_i =
    mcb_bldc_sixstep_f28069mL_DWork.IaOffset;

  /* DataStoreRead: '<S97>/Data Store Read1' */
  mcb_bldc_sixstep_f28069mLaunc_B.DataStoreRead1 =
    mcb_bldc_sixstep_f28069mL_DWork.IbOffset;

  /* DataStoreRead: '<S97>/Data Store Read2' */
  mcb_bldc_sixstep_f28069mLaunc_B.DataStoreRead2 =
    mcb_bldc_sixstep_f28069mL_DWork.IcOffset;

  /* DataTypeConversion: '<S97>/Data Type Conversion' */
  mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion_b[0] =
    mcb_bldc_sixstep_f28069mLaunc_B.IAIBMeasurement_p[0];
  mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion_b[1] =
    mcb_bldc_sixstep_f28069mLaunc_B.IAIBMeasurement_p[1];
  mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion_b[2] =
    mcb_bldc_sixstep_f28069mLaunc_B.ICMeasurement_l;

  /* Sum: '<S97>/Add' */
  mcb_bldc_sixstep_f28069mLaunc_B.Add_g[0] =
    mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion_b[0] -
    mcb_bldc_sixstep_f28069mLaunc_B.DataStoreRead_i;
  mcb_bldc_sixstep_f28069mLaunc_B.Add_g[1] =
    mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion_b[1] -
    mcb_bldc_sixstep_f28069mLaunc_B.DataStoreRead1;
  mcb_bldc_sixstep_f28069mLaunc_B.Add_g[2] =
    mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion_b[2] -
    mcb_bldc_sixstep_f28069mLaunc_B.DataStoreRead2;

  /* ArithShift: '<S97>/Q17 per unit conversion' incorporates:
   *  Sum: '<S97>/Add'
   */
  Q17perunitconversion = mcb_bldc_sixstep_f28069mLaunc_B.Add_g[0] << 6U;
  mcb_bldc_sixstep_f28069mLaunc_B.Q17perunitconversion[0] = Q17perunitconversion;

  /* DataTypeConversion: '<S97>/Data Type Conversion1' incorporates:
   *  ArithShift: '<S97>/Q17 per unit conversion'
   */
  DataTypeConversion1 = (real32_T)Q17perunitconversion * 7.62939453E-6F;
  mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion1[0] = DataTypeConversion1;

  /* Switch: '<S99>/Switch' incorporates:
   *  Constant: '<S99>/Constant'
   */
  if (DataTypeConversion1 > 0.0F) {
    cu = 0.0;
  } else {
    cu = DataTypeConversion1;
  }

  /* Switch: '<S99>/Switch' */
  mcb_bldc_sixstep_f28069mLaunc_B.cu[0] = cu;

  /* DataTypeConversion: '<S99>/Data Type Conversion' */
  mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion[0] = (real32_T)cu;

  /* ArithShift: '<S97>/Q17 per unit conversion' incorporates:
   *  Sum: '<S97>/Add'
   */
  Q17perunitconversion = mcb_bldc_sixstep_f28069mLaunc_B.Add_g[1] << 6U;
  mcb_bldc_sixstep_f28069mLaunc_B.Q17perunitconversion[1] = Q17perunitconversion;

  /* DataTypeConversion: '<S97>/Data Type Conversion1' incorporates:
   *  ArithShift: '<S97>/Q17 per unit conversion'
   */
  DataTypeConversion1 = (real32_T)Q17perunitconversion * 7.62939453E-6F;
  mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion1[1] = DataTypeConversion1;

  /* Switch: '<S99>/Switch' incorporates:
   *  Constant: '<S99>/Constant'
   */
  if (DataTypeConversion1 > 0.0F) {
    cu = 0.0;
  } else {
    cu = DataTypeConversion1;
  }

  /* Switch: '<S99>/Switch' */
  mcb_bldc_sixstep_f28069mLaunc_B.cu[1] = cu;

  /* DataTypeConversion: '<S99>/Data Type Conversion' */
  mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion[1] = (real32_T)cu;

  /* ArithShift: '<S97>/Q17 per unit conversion' incorporates:
   *  Sum: '<S97>/Add'
   */
  Q17perunitconversion = mcb_bldc_sixstep_f28069mLaunc_B.Add_g[2] << 6U;
  mcb_bldc_sixstep_f28069mLaunc_B.Q17perunitconversion[2] = Q17perunitconversion;

  /* DataTypeConversion: '<S97>/Data Type Conversion1' incorporates:
   *  ArithShift: '<S97>/Q17 per unit conversion'
   */
  DataTypeConversion1 = (real32_T)Q17perunitconversion * 7.62939453E-6F;
  mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion1[2] = DataTypeConversion1;

  /* Switch: '<S99>/Switch' incorporates:
   *  Constant: '<S99>/Constant'
   */
  if (DataTypeConversion1 > 0.0F) {
    cu = 0.0;
  } else {
    cu = DataTypeConversion1;
  }

  /* Switch: '<S99>/Switch' */
  mcb_bldc_sixstep_f28069mLaunc_B.cu[2] = cu;

  /* DataTypeConversion: '<S99>/Data Type Conversion' */
  mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion[2] = (real32_T)cu;

  /* Sum: '<S97>/Sum' */
  mcb_bldc_sixstep_f28069mLaunc_B.Sum_o =
    (mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion[0] +
     mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion[1]) +
    mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion[2];

  /* UnaryMinus: '<S97>/Unary Minus' */
  mcb_bldc_sixstep_f28069mLaunc_B.IDC = -mcb_bldc_sixstep_f28069mLaunc_B.Sum_o;

  /* Sum: '<S17>/Sum' */
  mcb_bldc_sixstep_f28069mLaunc_B.Sum_c =
    mcb_bldc_sixstep_f28069mLaunc_B.Idc_ref -
    mcb_bldc_sixstep_f28069mLaunc_B.IDC;

  /* Product: '<S58>/PProd Out' incorporates:
   *  Constant: '<S17>/Kp'
   */
  mcb_bldc_sixstep_f28069mLaunc_B.PProdOut =
    mcb_bldc_sixstep_f28069mLaunc_B.Sum_c * 1.16146636F;

  /* DataStoreRead: '<S17>/Data Store Read1' */
  mcb_bldc_sixstep_f28069mLaunc_B.DataStoreRead1_l =
    mcb_bldc_sixstep_f28069mL_DWork.Enable;

  /* Logic: '<S17>/Logical Operator' */
  mcb_bldc_sixstep_f28069mLaunc_B.LogicalOperator =
    !mcb_bldc_sixstep_f28069mLaunc_B.DataStoreRead1_l;

  /* Constant: '<S17>/Kp1' */
  mcb_bldc_sixstep_f28069mLaunc_B.Kp1 = 0.0F;

  /* DiscreteIntegrator: '<S53>/Integrator' */
  if (mcb_bldc_sixstep_f28069mLaunc_B.LogicalOperator ||
      (mcb_bldc_sixstep_f28069mL_DWork.Integrator_PrevResetState != 0)) {
    mcb_bldc_sixstep_f28069mL_DWork.Integrator_DSTATE = 0.0F;
  }

  /* DiscreteIntegrator: '<S53>/Integrator' */
  mcb_bldc_sixstep_f28069mLaunc_B.Integrator =
    mcb_bldc_sixstep_f28069mL_DWork.Integrator_DSTATE;

  /* Sum: '<S62>/Sum' */
  mcb_bldc_sixstep_f28069mLaunc_B.Sum_e =
    mcb_bldc_sixstep_f28069mLaunc_B.PProdOut +
    mcb_bldc_sixstep_f28069mLaunc_B.Integrator;

  /* Signum: '<S12>/Sign' */
  DataTypeConversion1 = mcb_bldc_sixstep_f28069mLaunc_B.RT2;
  if (rtIsNaNF(DataTypeConversion1)) {
    /* Signum: '<S12>/Sign' */
    mcb_bldc_sixstep_f28069mLaunc_B.Sign_b = (rtNaNF);
  } else if (DataTypeConversion1 < 0.0F) {
    /* Signum: '<S12>/Sign' */
    mcb_bldc_sixstep_f28069mLaunc_B.Sign_b = -1.0F;
  } else {
    /* Signum: '<S12>/Sign' */
    mcb_bldc_sixstep_f28069mLaunc_B.Sign_b = (DataTypeConversion1 > 0.0F);
  }

  /* End of Signum: '<S12>/Sign' */

  /* Outputs for IfAction SubSystem: '<S70>/Position' incorporates:
   *  ActionPort: '<S72>/Action Port'
   */
  /* If: '<S70>/If' incorporates:
   *  If: '<S76>/If'
   */
  if ((mcb_bldc_sixstep_f28069mLaunc_B.Add > 0.0833F) &&
      (mcb_bldc_sixstep_f28069mLaunc_B.Add <= 0.25F)) {
    /* Outputs for IfAction SubSystem: '<S76>/Enabled Subsystem' incorporates:
     *  ActionPort: '<S77>/Action Port'
     */
    /* Merge: '<S70>/Merge' incorporates:
     *  Constant: '<S77>/Constant'
     *  SignalConversion generated from: '<S77>/Out1'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_e = 2U;

    /* End of Outputs for SubSystem: '<S76>/Enabled Subsystem' */
  } else if ((mcb_bldc_sixstep_f28069mLaunc_B.Add > 0.25F) &&
             (mcb_bldc_sixstep_f28069mLaunc_B.Add <= 0.4167F)) {
    /* Outputs for IfAction SubSystem: '<S76>/Enabled Subsystem1' incorporates:
     *  ActionPort: '<S78>/Action Port'
     */
    /* Merge: '<S70>/Merge' incorporates:
     *  Constant: '<S78>/Constant'
     *  SignalConversion generated from: '<S78>/Out1'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_e = 3U;

    /* End of Outputs for SubSystem: '<S76>/Enabled Subsystem1' */
  } else if ((mcb_bldc_sixstep_f28069mLaunc_B.Add > 0.4167F) &&
             (mcb_bldc_sixstep_f28069mLaunc_B.Add <= 0.5833F)) {
    /* Outputs for IfAction SubSystem: '<S76>/Enabled Subsystem2' incorporates:
     *  ActionPort: '<S79>/Action Port'
     */
    /* Merge: '<S70>/Merge' incorporates:
     *  Constant: '<S79>/Constant'
     *  SignalConversion generated from: '<S79>/Out1'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_e = 4U;

    /* End of Outputs for SubSystem: '<S76>/Enabled Subsystem2' */
  } else if ((mcb_bldc_sixstep_f28069mLaunc_B.Add > 0.5833F) &&
             (mcb_bldc_sixstep_f28069mLaunc_B.Add <= 0.75F)) {
    /* Outputs for IfAction SubSystem: '<S76>/Enabled Subsystem3' incorporates:
     *  ActionPort: '<S80>/Action Port'
     */
    /* Merge: '<S70>/Merge' incorporates:
     *  Constant: '<S80>/Constant'
     *  SignalConversion generated from: '<S80>/Out1'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_e = 5U;

    /* End of Outputs for SubSystem: '<S76>/Enabled Subsystem3' */
  } else if ((mcb_bldc_sixstep_f28069mLaunc_B.Add > 0.75F) &&
             (mcb_bldc_sixstep_f28069mLaunc_B.Add <= 0.9167F)) {
    /* Outputs for IfAction SubSystem: '<S76>/Enabled Subsystem4' incorporates:
     *  ActionPort: '<S81>/Action Port'
     */
    /* Merge: '<S70>/Merge' incorporates:
     *  Constant: '<S81>/Constant'
     *  SignalConversion generated from: '<S81>/Out1'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_e = 6U;

    /* End of Outputs for SubSystem: '<S76>/Enabled Subsystem4' */
  } else {
    /* Outputs for IfAction SubSystem: '<S76>/Enabled Subsystem6' incorporates:
     *  ActionPort: '<S83>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S76>/Enabled Subsystem5' incorporates:
     *  ActionPort: '<S82>/Action Port'
     */
    /* Merge: '<S70>/Merge' incorporates:
     *  SignalConversion generated from: '<S82>/Out1'
     *  SignalConversion generated from: '<S83>/Out1'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_e = (uint16_T)
      ((mcb_bldc_sixstep_f28069mLaunc_B.Add > 0.9167F) ||
       (mcb_bldc_sixstep_f28069mLaunc_B.Add <= 0.0833F));

    /* End of Outputs for SubSystem: '<S76>/Enabled Subsystem5' */
    /* End of Outputs for SubSystem: '<S76>/Enabled Subsystem6' */
  }

  /* End of If: '<S70>/If' */
  /* End of Outputs for SubSystem: '<S70>/Position' */

  /* Outputs for IfAction SubSystem: '<S73>/Bit Extract' incorporates:
   *  ActionPort: '<S84>/Action Port'
   */
  /* If: '<S73>/Range Check' incorporates:
   *  ArithShift: '<S86>/Shift Arithmetic'
   *  ArithShift: '<S86>/Shift Arithmetic1'
   *  DataTypeConversion: '<S86>/Data Type Conversion'
   *  DataTypeConversion: '<S86>/Data Type Conversion1'
   *  DataTypeConversion: '<S86>/Data Type Conversion2'
   *  Logic: '<S86>/AND'
   *  Logic: '<S86>/AND1'
   *  Logic: '<S86>/AND2'
   *  Merge: '<S70>/Merge'
   *  Merge: '<S73>/Merge'
   *  S-Function (sfix_bitop): '<S86>/Bitwise AND1'
   *  S-Function (sfix_bitop): '<S86>/Bitwise AND2'
   *  S-Function (sfix_bitop): '<S86>/Bitwise AND3'
   */
  mcb_bldc_sixstep_f28069mLaunc_B.ShiftArithmetic =
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_e >> 2U;
  mcb_bldc_sixstep_f28069mLaunc_B.A =
    mcb_bldc_sixstep_f28069mLaunc_B.ShiftArithmetic;
  mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion_j =
    (mcb_bldc_sixstep_f28069mLaunc_B.A != 0U);
  mcb_bldc_sixstep_f28069mLaunc_B.Merge_n[0] =
    mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion_j;
  mcb_bldc_sixstep_f28069mLaunc_B.ShiftArithmetic1 =
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_e >> 1U;
  mcb_bldc_sixstep_f28069mLaunc_B.B =
    mcb_bldc_sixstep_f28069mLaunc_B.ShiftArithmetic1 & 1U;
  mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion1_d =
    (mcb_bldc_sixstep_f28069mLaunc_B.B != 0U);
  mcb_bldc_sixstep_f28069mLaunc_B.Merge_n[1] =
    mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion1_d;
  mcb_bldc_sixstep_f28069mLaunc_B.C = mcb_bldc_sixstep_f28069mLaunc_B.Merge_e &
    1U;
  mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion2 =
    (mcb_bldc_sixstep_f28069mLaunc_B.C != 0U);
  mcb_bldc_sixstep_f28069mLaunc_B.Merge_n[2] =
    mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion2;

  /* End of Outputs for SubSystem: '<S73>/Bit Extract' */

  /* If: '<S74>/If' */
  if (mcb_bldc_sixstep_f28069mLaunc_B.Sign_b > 0.0F) {
    /* Outputs for IfAction SubSystem: '<S74>/positive' incorporates:
     *  ActionPort: '<S88>/Action Port'
     */
    /* CombinatorialLogic: '<S88>/SA1' incorporates:
     *  CombinatorialLogic: '<S88>/SA2'
     *  CombinatorialLogic: '<S88>/SB1'
     *  CombinatorialLogic: '<S88>/SB2'
     *  CombinatorialLogic: '<S88>/SC1'
     *  CombinatorialLogic: '<S88>/SC2'
     *  Merge: '<S74>/Merge'
     */
    minV_tmp = mcb_bldc_sixstep_f28069mLaunc_B.Merge_n[0U];
    minV_tmp = (minV_tmp << 1) + mcb_bldc_sixstep_f28069mLaunc_B.Merge_n[1U];
    minV_tmp = (minV_tmp << 1) + mcb_bldc_sixstep_f28069mLaunc_B.Merge_n[2U];
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_k[0] =
      mcb_bldc_sixstep_f28069m_ConstP.pooled14[minV_tmp];

    /* CombinatorialLogic: '<S88>/SA2' incorporates:
     *  Merge: '<S74>/Merge'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_k[1] =
      mcb_bldc_sixstep_f28069m_ConstP.pooled13[minV_tmp];

    /* CombinatorialLogic: '<S88>/SB1' incorporates:
     *  Merge: '<S74>/Merge'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_k[2] =
      mcb_bldc_sixstep_f28069m_ConstP.pooled16[minV_tmp];

    /* CombinatorialLogic: '<S88>/SB2' incorporates:
     *  Merge: '<S74>/Merge'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_k[3] =
      mcb_bldc_sixstep_f28069m_ConstP.pooled15[minV_tmp];

    /* CombinatorialLogic: '<S88>/SC1' incorporates:
     *  Merge: '<S74>/Merge'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_k[4] =
      mcb_bldc_sixstep_f28069m_ConstP.pooled18[minV_tmp];

    /* CombinatorialLogic: '<S88>/SC2' incorporates:
     *  Merge: '<S74>/Merge'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_k[5] =
      mcb_bldc_sixstep_f28069m_ConstP.pooled17[minV_tmp];

    /* End of Outputs for SubSystem: '<S74>/positive' */
  } else {
    /* Outputs for IfAction SubSystem: '<S74>/negative' incorporates:
     *  ActionPort: '<S87>/Action Port'
     */
    /* CombinatorialLogic: '<S87>/SA1' incorporates:
     *  CombinatorialLogic: '<S87>/SA2'
     *  CombinatorialLogic: '<S87>/SB1'
     *  CombinatorialLogic: '<S87>/SB2'
     *  CombinatorialLogic: '<S87>/SC1'
     *  CombinatorialLogic: '<S87>/SC2'
     *  Merge: '<S74>/Merge'
     */
    minV_tmp = mcb_bldc_sixstep_f28069mLaunc_B.Merge_n[0U];
    minV_tmp = (minV_tmp << 1) + mcb_bldc_sixstep_f28069mLaunc_B.Merge_n[1U];
    minV_tmp = (minV_tmp << 1) + mcb_bldc_sixstep_f28069mLaunc_B.Merge_n[2U];
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_k[0] =
      mcb_bldc_sixstep_f28069m_ConstP.pooled13[minV_tmp];

    /* CombinatorialLogic: '<S87>/SA2' incorporates:
     *  Merge: '<S74>/Merge'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_k[1] =
      mcb_bldc_sixstep_f28069m_ConstP.pooled14[minV_tmp];

    /* CombinatorialLogic: '<S87>/SB1' incorporates:
     *  Merge: '<S74>/Merge'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_k[2] =
      mcb_bldc_sixstep_f28069m_ConstP.pooled15[minV_tmp];

    /* CombinatorialLogic: '<S87>/SB2' incorporates:
     *  Merge: '<S74>/Merge'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_k[3] =
      mcb_bldc_sixstep_f28069m_ConstP.pooled16[minV_tmp];

    /* CombinatorialLogic: '<S87>/SC1' incorporates:
     *  Merge: '<S74>/Merge'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_k[4] =
      mcb_bldc_sixstep_f28069m_ConstP.pooled17[minV_tmp];

    /* CombinatorialLogic: '<S87>/SC2' incorporates:
     *  Merge: '<S74>/Merge'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Merge_k[5] =
      mcb_bldc_sixstep_f28069m_ConstP.pooled18[minV_tmp];

    /* End of Outputs for SubSystem: '<S74>/negative' */
  }

  /* End of If: '<S74>/If' */

  /* Switch: '<S11>/Switch1' */
  if (mcb_bldc_sixstep_f28069mLaunc_B.Enable) {
    /* Saturate: '<S60>/Saturation' */
    DataTypeConversion1 = mcb_bldc_sixstep_f28069mLaunc_B.Sum_e;
    if (DataTypeConversion1 > 1.0F) {
      /* Saturate: '<S60>/Saturation' */
      mcb_bldc_sixstep_f28069mLaunc_B.Saturation = 1.0F;
    } else if (DataTypeConversion1 < 0.0F) {
      /* Saturate: '<S60>/Saturation' */
      mcb_bldc_sixstep_f28069mLaunc_B.Saturation = 0.0F;
    } else {
      /* Saturate: '<S60>/Saturation' */
      mcb_bldc_sixstep_f28069mLaunc_B.Saturation = DataTypeConversion1;
    }

    /* End of Saturate: '<S60>/Saturation' */
    for (i = 0; i < 6; i++) {
      /* DataTypeConversion: '<S12>/Data Type Conversion1' */
      DataTypeConversion1_o = (int16_T)mcb_bldc_sixstep_f28069mLaunc_B.Merge_k[i];
      mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion1_o[i] =
        DataTypeConversion1_o;

      /* Product: '<S12>/Product' */
      DataTypeConversion1 = mcb_bldc_sixstep_f28069mLaunc_B.Saturation *
        (real32_T)DataTypeConversion1_o;
      mcb_bldc_sixstep_f28069mLaunc_B.duty[i] = DataTypeConversion1;

      /* Gain: '<S11>/Scale_to_PWM_Counter_PRD' */
      u0 = (uint16_T)(2250.0F * DataTypeConversion1);
      mcb_bldc_sixstep_f28069mLaunc_B.Scale_to_PWM_Counter_PRD[i] = u0;

      /* Switch: '<S11>/Switch1' */
      mcb_bldc_sixstep_f28069mLaunc_B.Switch1[i] = u0;
    }
  } else {
    /* Switch: '<S11>/Switch1' */
    for (i = 0; i < 6; i++) {
      mcb_bldc_sixstep_f28069mLaunc_B.Switch1[i] = 0U;
    }
  }

  /* End of Switch: '<S11>/Switch1' */

  /* S-Function (c2802xpwm): '<S11>/ePWM4' */

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.half.CMPA = (uint16_T)
      (mcb_bldc_sixstep_f28069mLaunc_B.Switch1[0]);
  }

  /*-- Update CMPB value for ePWM1 --*/
  {
    EPwm1Regs.CMPB = (uint16_T)(mcb_bldc_sixstep_f28069mLaunc_B.Switch1[1]);
  }

  /* S-Function (c2802xpwm): '<S11>/ePWM5' */

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.half.CMPA = (uint16_T)
      (mcb_bldc_sixstep_f28069mLaunc_B.Switch1[2]);
  }

  /*-- Update CMPB value for ePWM2 --*/
  {
    EPwm2Regs.CMPB = (uint16_T)(mcb_bldc_sixstep_f28069mLaunc_B.Switch1[3]);
  }

  /* S-Function (c2802xpwm): '<S11>/ePWM6' */

  /*-- Update CMPA value for ePWM3 --*/
  {
    EPwm3Regs.CMPA.half.CMPA = (uint16_T)
      (mcb_bldc_sixstep_f28069mLaunc_B.Switch1[4]);
  }

  /*-- Update CMPB value for ePWM3 --*/
  {
    EPwm3Regs.CMPB = (uint16_T)(mcb_bldc_sixstep_f28069mLaunc_B.Switch1[5]);
  }

  /* UnitDelay: '<S89>/Output' */
  mcb_bldc_sixstep_f28069mLaunc_B.Output =
    mcb_bldc_sixstep_f28069mL_DWork.Output_DSTATE;

  /* DataTypeConversion: '<S91>/Data Type Conversion' */
  mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion_l[0] = (int16_T)
    (mcb_bldc_sixstep_f28069mLaunc_B.Add1 * 4096.0F);
  mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion_l[1] = (int16_T)
    (mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion[0] * 4096.0F);
  mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion_l[2] = (int16_T)
    (mcb_bldc_sixstep_f28069mLaunc_B.IDC * 4096.0F);

  /* DataTypeConversion: '<S91>/Data Type Conversion3' incorporates:
   *  DataTypeConversion: '<S91>/Data Type Conversion'
   */
  mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion3[0] = (uint16_T)
    mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion_l[0];
  mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion3[1] = (uint16_T)
    mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion_l[1];
  mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion3[2] = (uint16_T)
    mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion_l[2];

  /* If: '<S13>/If' */
  if (mcb_bldc_sixstep_f28069mLaunc_B.Output == 0U) {
    /* Outputs for IfAction SubSystem: '<S13>/Start' incorporates:
     *  ActionPort: '<S93>/Action Port'
     */
    /* Merge: '<S13>/Merge' incorporates:
     *  Constant: '<S93>/End'
     *  SignalConversion generated from: '<S93>/Data_out'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.SCI_Tx_Data[0] = 21331U;

    /* SignalConversion generated from: '<S93>/Data' */
    u0 = mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion3[0];

    /* End of Outputs for SubSystem: '<S13>/Start' */
    mcb_bldc_sixstep_f28069mLaunc_B.Data_fw[0] = u0;

    /* Outputs for IfAction SubSystem: '<S13>/Start' incorporates:
     *  ActionPort: '<S93>/Action Port'
     */
    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S93>/Data_out'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.SCI_Tx_Data[1] = u0;

    /* SignalConversion generated from: '<S93>/Data' */
    u0 = mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion3[1];

    /* End of Outputs for SubSystem: '<S13>/Start' */
    mcb_bldc_sixstep_f28069mLaunc_B.Data_fw[1] = u0;

    /* Outputs for IfAction SubSystem: '<S13>/Start' incorporates:
     *  ActionPort: '<S93>/Action Port'
     */
    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S93>/Data_out'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.SCI_Tx_Data[2] = u0;

    /* SignalConversion generated from: '<S93>/Data' */
    u0 = mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion3[2];

    /* End of Outputs for SubSystem: '<S13>/Start' */
    mcb_bldc_sixstep_f28069mLaunc_B.Data_fw[2] = u0;

    /* Outputs for IfAction SubSystem: '<S13>/Start' incorporates:
     *  ActionPort: '<S93>/Action Port'
     */
    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S93>/Data_out'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.SCI_Tx_Data[3] = u0;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Bias: '<S93>/Bias'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.SCI_Tx_Iteration =
      mcb_bldc_sixstep_f28069m_ConstB.Width + 1U;

    /* End of Outputs for SubSystem: '<S13>/Start' */
  } else if (mcb_bldc_sixstep_f28069mLaunc_B.Output == 599U) {
    /* Outputs for IfAction SubSystem: '<S13>/End' incorporates:
     *  ActionPort: '<S92>/Action Port'
     */
    /* SignalConversion generated from: '<S92>/Data' */
    u0 = mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion3[0];

    /* End of Outputs for SubSystem: '<S13>/End' */
    mcb_bldc_sixstep_f28069mLaunc_B.Data_f[0] = u0;

    /* Outputs for IfAction SubSystem: '<S13>/End' incorporates:
     *  ActionPort: '<S92>/Action Port'
     */
    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S92>/Data_out'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.SCI_Tx_Data[0] = u0;

    /* SignalConversion generated from: '<S92>/Data' */
    u0 = mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion3[1];

    /* End of Outputs for SubSystem: '<S13>/End' */
    mcb_bldc_sixstep_f28069mLaunc_B.Data_f[1] = u0;

    /* Outputs for IfAction SubSystem: '<S13>/End' incorporates:
     *  ActionPort: '<S92>/Action Port'
     */
    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S92>/Data_out'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.SCI_Tx_Data[1] = u0;

    /* SignalConversion generated from: '<S92>/Data' */
    u0 = mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion3[2];

    /* End of Outputs for SubSystem: '<S13>/End' */
    mcb_bldc_sixstep_f28069mLaunc_B.Data_f[2] = u0;

    /* Outputs for IfAction SubSystem: '<S13>/End' incorporates:
     *  ActionPort: '<S92>/Action Port'
     */
    /* Merge: '<S13>/Merge' incorporates:
     *  Constant: '<S92>/Start'
     *  SignalConversion generated from: '<S92>/Data_out'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.SCI_Tx_Data[2] = u0;
    mcb_bldc_sixstep_f28069mLaunc_B.SCI_Tx_Data[3] = 17733U;

    /* Merge: '<S13>/Merge1' incorporates:
     *  Bias: '<S92>/Bias'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.SCI_Tx_Iteration =
      mcb_bldc_sixstep_f28069m_ConstB.Width + 1U;

    /* End of Outputs for SubSystem: '<S13>/End' */
  } else {
    /* Outputs for IfAction SubSystem: '<S13>/Data' incorporates:
     *  ActionPort: '<S90>/Action Port'
     */
    /* SignalConversion generated from: '<S90>/Data' */
    u0 = mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion3[0];

    /* End of Outputs for SubSystem: '<S13>/Data' */
    mcb_bldc_sixstep_f28069mLaunc_B.Data[0] = u0;

    /* Outputs for IfAction SubSystem: '<S13>/Data' incorporates:
     *  ActionPort: '<S90>/Action Port'
     */
    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S90>/Data_out'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.SCI_Tx_Data[0] = u0;

    /* SignalConversion generated from: '<S90>/Data' */
    u0 = mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion3[1];

    /* End of Outputs for SubSystem: '<S13>/Data' */
    mcb_bldc_sixstep_f28069mLaunc_B.Data[1] = u0;

    /* Outputs for IfAction SubSystem: '<S13>/Data' incorporates:
     *  ActionPort: '<S90>/Action Port'
     */
    /* Merge: '<S13>/Merge' incorporates:
     *  SignalConversion generated from: '<S90>/Data_out'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.SCI_Tx_Data[1] = u0;

    /* SignalConversion generated from: '<S90>/Data' */
    u0 = mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion3[2];

    /* End of Outputs for SubSystem: '<S13>/Data' */
    mcb_bldc_sixstep_f28069mLaunc_B.Data[2] = u0;

    /* Outputs for IfAction SubSystem: '<S13>/Data' incorporates:
     *  ActionPort: '<S90>/Action Port'
     */
    /* Merge: '<S13>/Merge' incorporates:
     *  Constant: '<S90>/Start'
     *  SignalConversion generated from: '<S90>/Data_out'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.SCI_Tx_Data[2] = u0;
    mcb_bldc_sixstep_f28069mLaunc_B.SCI_Tx_Data[3] = 0U;

    /* Merge: '<S13>/Merge1' incorporates:
     *  SignalConversion generated from: '<S90>/Data_width'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.SCI_Tx_Iteration =
      mcb_bldc_sixstep_f28069m_ConstB.Width;

    /* End of Outputs for SubSystem: '<S13>/Data' */
  }

  /* End of If: '<S13>/If' */

  /* Outputs for Iterator SubSystem: '<S14>/CodeGeneration' incorporates:
   *  WhileIterator: '<S96>/While Iterator'
   */
  i = 1;
  do {
    mcb_bldc_sixstep_f28069mLaunc_B.WhileIterator = i;
    mcb_bldc_sixstep_f28069mLaunc_B.IndexVector =
      mcb_bldc_sixstep_f28069mLaunc_B.SCI_Tx_Data[mcb_bldc_sixstep_f28069mLaunc_B.WhileIterator
      - 1];

    {
      if (checkSCITransmitInProgressA != 1U) {
        checkSCITransmitInProgressA = 1U;
        int16_T errFlgHeader = NOERROR;
        int16_T errFlgData = NOERROR;
        int16_T errFlgTail = NOERROR;
        errFlgData = scia_xmit((unsigned char*)
          &mcb_bldc_sixstep_f28069mLaunc_B.IndexVector, 2, 2);
        checkSCITransmitInProgressA = 0U;
      }
    }

    mcb_bldc_sixstep_f28069mLaunc_B.Add_gl =
      mcb_bldc_sixstep_f28069mLaunc_B.SCI_Tx_Iteration - (uint16_T)
      mcb_bldc_sixstep_f28069mLaunc_B.WhileIterator;
    i++;
  } while (mcb_bldc_sixstep_f28069mLaunc_B.Add_gl != 0U);

  /* End of Outputs for SubSystem: '<S14>/CodeGeneration' */

  /* DeadZone: '<S46>/DeadZone' */
  if (mcb_bldc_sixstep_f28069mLaunc_B.Sum_e > 1.0F) {
    /* DeadZone: '<S46>/DeadZone' */
    mcb_bldc_sixstep_f28069mLaunc_B.DeadZone =
      mcb_bldc_sixstep_f28069mLaunc_B.Sum_e - 1.0F;
  } else if (mcb_bldc_sixstep_f28069mLaunc_B.Sum_e >= 0.0F) {
    /* DeadZone: '<S46>/DeadZone' */
    mcb_bldc_sixstep_f28069mLaunc_B.DeadZone = 0.0F;
  } else {
    /* DeadZone: '<S46>/DeadZone' */
    mcb_bldc_sixstep_f28069mLaunc_B.DeadZone =
      mcb_bldc_sixstep_f28069mLaunc_B.Sum_e;
  }

  /* End of DeadZone: '<S46>/DeadZone' */

  /* RelationalOperator: '<S44>/Relational Operator' incorporates:
   *  Constant: '<S44>/Clamping_zero'
   */
  mcb_bldc_sixstep_f28069mLaunc_B.RelationalOperator =
    (mcb_bldc_sixstep_f28069mLaunc_B.DeadZone != 0.0F);

  /* RelationalOperator: '<S44>/fix for DT propagation issue' incorporates:
   *  Constant: '<S44>/Clamping_zero'
   */
  mcb_bldc_sixstep_f28069mLaunc_B.fixforDTpropagationissue =
    (mcb_bldc_sixstep_f28069mLaunc_B.DeadZone > 0.0F);

  /* Switch: '<S44>/Switch1' */
  if (mcb_bldc_sixstep_f28069mLaunc_B.fixforDTpropagationissue) {
    /* Switch: '<S44>/Switch1' incorporates:
     *  Constant: '<S44>/Constant'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Switch1_b = 1;
  } else {
    /* Switch: '<S44>/Switch1' incorporates:
     *  Constant: '<S44>/Constant2'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Switch1_b = -1;
  }

  /* End of Switch: '<S44>/Switch1' */

  /* Product: '<S50>/IProd Out' incorporates:
   *  Constant: '<S17>/Ki'
   */
  mcb_bldc_sixstep_f28069mLaunc_B.IProdOut =
    mcb_bldc_sixstep_f28069mLaunc_B.Sum_c * 0.0F;

  /* RelationalOperator: '<S44>/fix for DT propagation issue1' */
  mcb_bldc_sixstep_f28069mLaunc_B.fixforDTpropagationissue1 = false;

  /* Switch: '<S44>/Switch2' incorporates:
   *  Constant: '<S44>/Constant4'
   */
  mcb_bldc_sixstep_f28069mLaunc_B.Switch2 = -1;

  /* RelationalOperator: '<S44>/Equal1' incorporates:
   *  Switch: '<S44>/Switch1'
   *  Switch: '<S44>/Switch2'
   */
  mcb_bldc_sixstep_f28069mLaunc_B.Equal1 =
    (mcb_bldc_sixstep_f28069mLaunc_B.Switch1_b == -1);

  /* Logic: '<S44>/AND3' */
  mcb_bldc_sixstep_f28069mLaunc_B.AND3 =
    (mcb_bldc_sixstep_f28069mLaunc_B.RelationalOperator &&
     mcb_bldc_sixstep_f28069mLaunc_B.Equal1);

  /* Switch: '<S44>/Switch' */
  if (mcb_bldc_sixstep_f28069mLaunc_B.AND3) {
    /* Switch: '<S44>/Switch' incorporates:
     *  Constant: '<S44>/Constant1'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Switch = 0.0F;
  } else {
    /* Switch: '<S44>/Switch' */
    mcb_bldc_sixstep_f28069mLaunc_B.Switch =
      mcb_bldc_sixstep_f28069mLaunc_B.IProdOut;
  }

  /* End of Switch: '<S44>/Switch' */

  /* Sum: '<S94>/FixPt Sum1' incorporates:
   *  Constant: '<S94>/FixPt Constant'
   */
  mcb_bldc_sixstep_f28069mLaunc_B.FixPtSum1 =
    mcb_bldc_sixstep_f28069mLaunc_B.Output + 1U;

  /* Switch: '<S95>/FixPt Switch' */
  if (mcb_bldc_sixstep_f28069mLaunc_B.FixPtSum1 > 599U) {
    /* Switch: '<S95>/FixPt Switch' incorporates:
     *  Constant: '<S95>/Constant'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.FixPtSwitch = 0U;
  } else {
    /* Switch: '<S95>/FixPt Switch' */
    mcb_bldc_sixstep_f28069mLaunc_B.FixPtSwitch =
      mcb_bldc_sixstep_f28069mLaunc_B.FixPtSum1;
  }

  /* End of Switch: '<S95>/FixPt Switch' */

  /* Update for DiscreteIntegrator: '<S53>/Integrator' */
  mcb_bldc_sixstep_f28069mL_DWork.Integrator_DSTATE +=
    mcb_bldc_sixstep_f28069mLaunc_B.Switch;
  mcb_bldc_sixstep_f28069mL_DWork.Integrator_PrevResetState = (int16_T)
    mcb_bldc_sixstep_f28069mLaunc_B.LogicalOperator;

  /* Update for UnitDelay: '<S89>/Output' */
  mcb_bldc_sixstep_f28069mL_DWork.Output_DSTATE =
    mcb_bldc_sixstep_f28069mLaunc_B.FixPtSwitch;
}

/* System initialize for atomic system: */
void mcb__SPIMasterTransfer_Init(rtDW_SPIMasterTransfer_mcb_bldc *localDW)
{
  uint32_T SPIPinsLoc;

  /* Start for MATLABSystem: '<S133>/SPI Master Transfer' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1L;
  SPIPinsLoc = MW_UNDEFINED_VALUE;
  localDW->obj.MW_SPI_HANDLE = MW_SPI_Open(0UL, SPIPinsLoc, SPIPinsLoc,
    SPIPinsLoc, MW_UNDEFINED_VALUE, true, 0U);
  MW_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 16U, MW_SPI_MODE_0,
                   MW_SPI_MOST_SIGNIFICANT_BIT_FIRST);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void mcb_bldc__SPIMasterTransfer(uint16_T rtu_0, rtB_SPIMasterTransfer_mcb_bldc_
  *localB, rtDW_SPIMasterTransfer_mcb_bldc *localDW)
{
  uint16_T rdDataRaw;
  uint16_T status;

  /* MATLABSystem: '<S133>/SPI Master Transfer' */
  MW_SPI_SetSlaveSelect(localDW->obj.MW_SPI_HANDLE, 0U, true);
  status = MW_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 16U, MW_SPI_MODE_0,
    MW_SPI_MOST_SIGNIFICANT_BIT_FIRST);
  if (status == 0U) {
    MW_SPI_MasterWriteRead_8bits(localDW->obj.MW_SPI_HANDLE, &rtu_0, &rdDataRaw,
      1UL);
  }

  /* MATLABSystem: '<S133>/SPI Master Transfer' */
  localB->SPIMasterTransfer = rdDataRaw;
}

/* Termination for atomic system: */
void mcb__SPIMasterTransfer_Term(rtDW_SPIMasterTransfer_mcb_bldc *localDW)
{
  uint32_T SPIPinsLoc;

  /* Terminate for MATLABSystem: '<S133>/SPI Master Transfer' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1L) && localDW->obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, MW_UNDEFINED_VALUE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S133>/SPI Master Transfer' */
}

/* System initialize for atomic system: '<Root>/Speed Control' */
void mcb_bldc__SpeedControl_Init(rtB_SpeedControl_mcb_bldc_sixst *localB,
  rtDW_SpeedControl_mcb_bldc_sixs *localDW)
{
  /* Start for Constant: '<S143>/Ki2' */
  localB->Ki2 = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S180>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
  localDW->Integrator_PrevResetState = 0;
}

/* Output and update for atomic system: '<Root>/Speed Control' */
void mcb_bldc_sixst_SpeedControl(real32_T rtu_Speed_Ref_PU, real32_T
  rtu_Speed_Meas_PU, const boolean_T *rtd_Enable,
  rtB_SpeedControl_mcb_bldc_sixst *localB, rtDW_SpeedControl_mcb_bldc_sixs
  *localDW)
{
  real32_T u0;

  /* DataStoreRead: '<S143>/Data Store Read2' */
  localB->DataStoreRead2 = *rtd_Enable;

  /* DataStoreRead: '<S144>/Data Store Read1' */
  localB->DataStoreRead1 = *rtd_Enable;

  /* Switch: '<S144>/Switch' */
  if (localB->DataStoreRead1) {
    /* Switch: '<S144>/Switch' */
    localB->Switch = rtu_Speed_Ref_PU;
  } else {
    /* Switch: '<S144>/Switch' */
    localB->Switch = rtu_Speed_Meas_PU;
  }

  /* End of Switch: '<S144>/Switch' */

  /* Product: '<S199>/Product' incorporates:
   *  Constant: '<S199>/Filter_Constant'
   */
  localB->Product = localB->Switch * 0.1F;

  /* UnitDelay: '<S199>/Unit Delay' */
  localB->UnitDelay = localDW->UnitDelay_DSTATE;

  /* Product: '<S199>/Product1' incorporates:
   *  Constant: '<S199>/One'
   */
  localB->Product1 = 0.9F * localB->UnitDelay;

  /* Sum: '<S199>/Add1' */
  localB->Add1 = localB->Product + localB->Product1;

  /* Sum: '<S143>/Sum' */
  localB->Sum = localB->Add1 - rtu_Speed_Meas_PU;

  /* Product: '<S185>/PProd Out' incorporates:
   *  Constant: '<S143>/Kp1'
   */
  localB->PProdOut = localB->Sum * 2.70955873F;

  /* Logic: '<S143>/Logical Operator' */
  localB->LogicalOperator = !localB->DataStoreRead2;

  /* Constant: '<S143>/Ki2' */
  localB->Ki2 = 0.0F;

  /* DiscreteIntegrator: '<S180>/Integrator' */
  if (localB->LogicalOperator || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = 0.0F;
  }

  /* DiscreteIntegrator: '<S180>/Integrator' */
  localB->Integrator = localDW->Integrator_DSTATE;

  /* Sum: '<S189>/Sum' */
  localB->Sum_j = localB->PProdOut + localB->Integrator;

  /* DeadZone: '<S173>/DeadZone' */
  if (localB->Sum_j > 1.0F) {
    /* DeadZone: '<S173>/DeadZone' */
    localB->DeadZone = localB->Sum_j - 1.0F;
  } else if (localB->Sum_j >= -1.0F) {
    /* DeadZone: '<S173>/DeadZone' */
    localB->DeadZone = 0.0F;
  } else {
    /* DeadZone: '<S173>/DeadZone' */
    localB->DeadZone = localB->Sum_j - -1.0F;
  }

  /* End of DeadZone: '<S173>/DeadZone' */

  /* RelationalOperator: '<S171>/Relational Operator' incorporates:
   *  Constant: '<S171>/Clamping_zero'
   */
  localB->RelationalOperator = (localB->DeadZone != 0.0F);

  /* RelationalOperator: '<S171>/fix for DT propagation issue' incorporates:
   *  Constant: '<S171>/Clamping_zero'
   */
  localB->fixforDTpropagationissue = (localB->DeadZone > 0.0F);

  /* Switch: '<S171>/Switch1' */
  if (localB->fixforDTpropagationissue) {
    /* Switch: '<S171>/Switch1' incorporates:
     *  Constant: '<S171>/Constant'
     */
    localB->Switch1 = 1;
  } else {
    /* Switch: '<S171>/Switch1' incorporates:
     *  Constant: '<S171>/Constant2'
     */
    localB->Switch1 = -1;
  }

  /* End of Switch: '<S171>/Switch1' */

  /* Product: '<S177>/IProd Out' incorporates:
   *  Constant: '<S143>/Ki1'
   */
  localB->IProdOut = localB->Sum * 0.0197651051F;

  /* RelationalOperator: '<S171>/fix for DT propagation issue1' incorporates:
   *  Constant: '<S171>/Clamping_zero'
   */
  localB->fixforDTpropagationissue1 = (localB->IProdOut > 0.0F);

  /* Switch: '<S171>/Switch2' */
  if (localB->fixforDTpropagationissue1) {
    /* Switch: '<S171>/Switch2' incorporates:
     *  Constant: '<S171>/Constant3'
     */
    localB->Switch2 = 1;
  } else {
    /* Switch: '<S171>/Switch2' incorporates:
     *  Constant: '<S171>/Constant4'
     */
    localB->Switch2 = -1;
  }

  /* End of Switch: '<S171>/Switch2' */

  /* RelationalOperator: '<S171>/Equal1' incorporates:
   *  Switch: '<S171>/Switch1'
   *  Switch: '<S171>/Switch2'
   */
  localB->Equal1 = (localB->Switch1 == localB->Switch2);

  /* Logic: '<S171>/AND3' */
  localB->AND3 = (localB->RelationalOperator && localB->Equal1);

  /* Switch: '<S171>/Switch' */
  if (localB->AND3) {
    /* Switch: '<S171>/Switch' incorporates:
     *  Constant: '<S171>/Constant1'
     */
    localB->Switch_a = 0.0F;
  } else {
    /* Switch: '<S171>/Switch' */
    localB->Switch_a = localB->IProdOut;
  }

  /* End of Switch: '<S171>/Switch' */

  /* Saturate: '<S187>/Saturation' */
  u0 = localB->Sum_j;
  if (u0 > 1.0F) {
    /* Saturate: '<S187>/Saturation' */
    localB->Saturation = 1.0F;
  } else if (u0 < -1.0F) {
    /* Saturate: '<S187>/Saturation' */
    localB->Saturation = -1.0F;
  } else {
    /* Saturate: '<S187>/Saturation' */
    localB->Saturation = u0;
  }

  /* End of Saturate: '<S187>/Saturation' */

  /* Update for UnitDelay: '<S199>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->Add1;

  /* Update for DiscreteIntegrator: '<S180>/Integrator' */
  localDW->Integrator_DSTATE += localB->Switch_a;
  localDW->Integrator_PrevResetState = (int16_T)localB->LogicalOperator;
}

/* Model step function for TID0 */
void mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_step0(void) /* Sample time: [0.0005s, 0.0s] */
{
  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* DataStoreRead: '<Root>/Data Store Read' */
  mcb_bldc_sixstep_f28069mLaunc_B.DataStoreRead =
    mcb_bldc_sixstep_f28069mL_DWork.desiredSpeed;

  /* RateTransition: '<Root>/RT1' */
  mcb_bldc_sixstep_f28069mL_DWork.RT1_semaphoreTaken =
    mcb_bldc_sixstep_f28069mL_DWork.RT1_ActiveBufIdx;

  /* RateTransition: '<Root>/RT1' */
  mcb_bldc_sixstep_f28069mLaunc_B.RT1 =
    mcb_bldc_sixstep_f28069mL_DWork.RT1_Buffer[mcb_bldc_sixstep_f28069mL_DWork.RT1_semaphoreTaken];

  /* RateTransition: '<Root>/RT6' */
  mcb_bldc_sixstep_f28069mLaunc_B.RT6 =
    mcb_bldc_sixstep_f28069mLaunc_B.DataStoreRead;

  /* Outputs for Atomic SubSystem: '<Root>/Speed Control' */
  mcb_bldc_sixst_SpeedControl(mcb_bldc_sixstep_f28069mLaunc_B.RT6,
    mcb_bldc_sixstep_f28069mLaunc_B.RT1, &mcb_bldc_sixstep_f28069mL_DWork.Enable,
    &mcb_bldc_sixstep_f28069mLaunc_B.SpeedControl,
    &mcb_bldc_sixstep_f28069mL_DWork.SpeedControl);

  /* End of Outputs for SubSystem: '<Root>/Speed Control' */

  /* RateTransition: '<Root>/RT2' */
  mcb_bldc_sixstep_f28069mL_DWork.RT2_Buffer[mcb_bldc_sixstep_f28069mL_DWork.RT2_ActiveBufIdx
    == 0] = mcb_bldc_sixstep_f28069mLaunc_B.SpeedControl.Saturation;
  mcb_bldc_sixstep_f28069mL_DWork.RT2_ActiveBufIdx =
    (mcb_bldc_sixstep_f28069mL_DWork.RT2_ActiveBufIdx == 0);
}

/* Model step function for TID1 */
void mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_step1(void) /* Sample time: [0.1s, 0.0s] */
{
  /* S-Function (c280xgpio_di): '<S7>/ON//OFF_GPIO6' */
  {
    mcb_bldc_sixstep_f28069mLaunc_B.ONOFF_GPIO6 = GpioDataRegs.GPADAT.bit.GPIO6;
  }

  /* DataStoreWrite: '<S7>/Data Store Write' */
  mcb_bldc_sixstep_f28069mL_DWork.Enable =
    mcb_bldc_sixstep_f28069mLaunc_B.ONOFF_GPIO6;

  /* RateTransition: '<Root>/RT3' */
  mcb_bldc_sixstep_f28069mL_DWork.RT3_semaphoreTaken =
    mcb_bldc_sixstep_f28069mL_DWork.RT3_ActiveBufIdx;

  /* RateTransition: '<Root>/RT3' */
  mcb_bldc_sixstep_f28069mLaunc_B.RT3 =
    mcb_bldc_sixstep_f28069mL_DWork.RT3_Buffer[mcb_bldc_sixstep_f28069mL_DWork.RT3_semaphoreTaken];

  /* Abs: '<S7>/Abs' */
  mcb_bldc_sixstep_f28069mLaunc_B.Abs = fabsf
    (mcb_bldc_sixstep_f28069mLaunc_B.RT3);

  /* If: '<S7>/If' */
  if (mcb_bldc_sixstep_f28069mLaunc_B.Abs < 0.04F) {
    /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem' incorporates:
     *  ActionPort: '<S209>/Action Port'
     */
    /* S-Function (c280xgpio_di): '<S209>/CW//CCW_GPIO7' */
    {
      mcb_bldc_sixstep_f28069mLaunc_B.CWCCW_GPIO7 =
        GpioDataRegs.GPADAT.bit.GPIO7;
    }

    /* DataStoreWrite: '<S209>/Data Store Write1' */
    mcb_bldc_sixstep_f28069mL_DWork.readTorqueSign =
      mcb_bldc_sixstep_f28069mLaunc_B.CWCCW_GPIO7;

    /* End of Outputs for SubSystem: '<S7>/If Action Subsystem' */
  }

  /* End of If: '<S7>/If' */

  /* Outputs for Atomic SubSystem: '<Root>/To_LCD' */
  mcb_bldc_sixstep_f28_To_LCD(&mcb_bldc_sixstep_f28069mL_DWork.speedSCI_B,
    &mcb_bldc_sixstep_f28069mLaunc_B.To_LCD,
    &mcb_bldc_sixstep_f28069mL_DWork.To_LCD);

  /* End of Outputs for SubSystem: '<Root>/To_LCD' */

  /* DiscretePulseGenerator: '<S6>/Pulse Generator' */
  mcb_bldc_sixstep_f28069mLaunc_B.PulseGenerator =
    ((mcb_bldc_sixstep_f28069mL_DWork.clockTickCounter < 1L) &&
     (mcb_bldc_sixstep_f28069mL_DWork.clockTickCounter >= 0L));

  /* DiscretePulseGenerator: '<S6>/Pulse Generator' */
  if (mcb_bldc_sixstep_f28069mL_DWork.clockTickCounter >= 1L) {
    mcb_bldc_sixstep_f28069mL_DWork.clockTickCounter = 0L;
  } else {
    mcb_bldc_sixstep_f28069mL_DWork.clockTickCounter++;
  }

  /* S-Function (c280xgpio_do): '<S6>/Digital Output' */
  {
    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = (uint16_T)
      (mcb_bldc_sixstep_f28069mLaunc_B.PulseGenerator != 0);
  }

  /* Logic: '<S6>/NOT' */
  mcb_bldc_sixstep_f28069mLaunc_B.NOT =
    !(mcb_bldc_sixstep_f28069mLaunc_B.PulseGenerator != 0.0);

  /* S-Function (c280xgpio_do): '<S6>/Digital Output1' */
  {
    GpioDataRegs.GPBTOGGLE.bit.GPIO39 = (uint16_T)
      (mcb_bldc_sixstep_f28069mLaunc_B.NOT != 0);
  }
}

/* Model initialize function */
void mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)mcb_bldc_sixstep_f28069mLaun_M, 0,
                sizeof(RT_MODEL_mcb_bldc_sixstep_f2806));

  /* block I/O */
  (void) memset(((void *) &mcb_bldc_sixstep_f28069mLaunc_B), 0,
                sizeof(BlockIO_mcb_bldc_sixstep_f28069));

  {
    int16_T i;
    for (i = 0; i < 6; i++) {
      mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion1_o[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      mcb_bldc_sixstep_f28069mLaunc_B.duty[i] = 0.0F;
    }

    mcb_bldc_sixstep_f28069mLaunc_B.PulseGenerator = 0.0;
    mcb_bldc_sixstep_f28069mLaunc_B.Merge1 = 0.0;
    mcb_bldc_sixstep_f28069mLaunc_B.Sign = 0.0;
    mcb_bldc_sixstep_f28069mLaunc_B.ADCThreshold = 0.0;
    mcb_bldc_sixstep_f28069mLaunc_B.cu[0] = 0.0;
    mcb_bldc_sixstep_f28069mLaunc_B.cu[1] = 0.0;
    mcb_bldc_sixstep_f28069mLaunc_B.cu[2] = 0.0;
    mcb_bldc_sixstep_f28069mLaunc_B.Sum = 0.0;
    mcb_bldc_sixstep_f28069mLaunc_B.DataStoreRead = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.RT1 = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.RT6 = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.RT3 = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Abs = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.RT2 = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.toPU = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.conductSpeed = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Idc_ref = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion1[0] = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion1[1] = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion1[2] = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion[0] = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion[1] = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.DataTypeConversion[2] = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Sum_o = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.IDC = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Sum_c = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.PProdOut = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Kp1 = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Integrator = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Sum_e = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Sign_b = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.DeadZone = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.IProdOut = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Switch = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.DTC = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Product = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.DTC_a = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.SpeedGain = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Product_g = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.UnitDelay = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Product1 = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Add1 = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Switch_f = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Merge = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Numberofpolepairs = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Floor = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Add = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.Saturation = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.To_LCD.dataLogging_Speed = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.SpeedControl.Switch = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.SpeedControl.Product = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.SpeedControl.UnitDelay = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.SpeedControl.Product1 = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.SpeedControl.Add1 = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.SpeedControl.Sum = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.SpeedControl.PProdOut = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.SpeedControl.Ki2 = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.SpeedControl.Integrator = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.SpeedControl.Sum_j = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.SpeedControl.DeadZone = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.SpeedControl.IProdOut = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.SpeedControl.Switch_a = 0.0F;
    mcb_bldc_sixstep_f28069mLaunc_B.SpeedControl.Saturation = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&mcb_bldc_sixstep_f28069mL_DWork, 0,
                sizeof(D_Work_mcb_bldc_sixstep_f28069m));
  mcb_bldc_sixstep_f28069mL_DWork.Sum_DWORK1 = 0.0;
  mcb_bldc_sixstep_f28069mL_DWork.Integrator_DSTATE = 0.0F;
  mcb_bldc_sixstep_f28069mL_DWork.UnitDelay_DSTATE = 0.0F;
  mcb_bldc_sixstep_f28069mL_DWork.RT1_Buffer[0] = 0.0F;
  mcb_bldc_sixstep_f28069mL_DWork.RT1_Buffer[1] = 0.0F;
  mcb_bldc_sixstep_f28069mL_DWork.RT2_Buffer[0] = 0.0F;
  mcb_bldc_sixstep_f28069mL_DWork.RT2_Buffer[1] = 0.0F;
  mcb_bldc_sixstep_f28069mL_DWork.desiredSpeed = 0.0F;
  mcb_bldc_sixstep_f28069mL_DWork.RT3_Buffer[0] = 0.0F;
  mcb_bldc_sixstep_f28069mL_DWork.RT3_Buffer[1] = 0.0F;
  mcb_bldc_sixstep_f28069mL_DWork.speedSCI_B = 0.0F;
  mcb_bldc_sixstep_f28069mL_DWork.SpeedControl.UnitDelay_DSTATE = 0.0F;
  mcb_bldc_sixstep_f28069mL_DWork.SpeedControl.Integrator_DSTATE = 0.0F;

  {
    uint16_T s135_iter;

    /* Start for S-Function (c280xgpio_di): '<S7>/ON//OFF_GPIO6' */
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all &= 0xFFFFCFFFU;
    GpioCtrlRegs.GPADIR.all &= 0xFFFFFFBFU;
    EDIS;

    /* Start for S-Function (c280xgpio_do): '<S6>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCFU;
    GpioCtrlRegs.GPBDIR.all |= 0x4U;
    EDIS;

    /* Start for S-Function (c280xgpio_do): '<S6>/Digital Output1' */
    EALLOW;
    GpioCtrlRegs.GPBMUX1.all &= 0xFFFF3FFFU;
    GpioCtrlRegs.GPBDIR.all |= 0x80U;
    EDIS;

    /* Start for DataStoreMemory: '<Root>/g_IaOffset' */
    mcb_bldc_sixstep_f28069mL_DWork.IaOffset = 3309U;

    /* Start for DataStoreMemory: '<Root>/g_IbOffset' */
    mcb_bldc_sixstep_f28069mL_DWork.IbOffset = 3304U;

    /* Start for DataStoreMemory: '<Root>/g_IcOffset' */
    mcb_bldc_sixstep_f28069mL_DWork.IcOffset = 3304U;

    /* InitializeConditions for DiscretePulseGenerator: '<S6>/Pulse Generator' */
    mcb_bldc_sixstep_f28069mL_DWork.clockTickCounter = 0L;

    /* SystemInitialize for IfAction SubSystem: '<S7>/If Action Subsystem' */
    /* Start for S-Function (c280xgpio_di): '<S209>/CW//CCW_GPIO7' */
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all &= 0xFFFF3FFFU;
    GpioCtrlRegs.GPADIR.all &= 0xFFFFFF7FU;
    EDIS;

    /* End of SystemInitialize for SubSystem: '<S7>/If Action Subsystem' */

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S10>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Current Control'
     */
    mcb_bld_CurrentControl_Init();

    /* SystemInitialize for Atomic SubSystem: '<Root>/Speed Control' */
    mcb_bldc__SpeedControl_Init(&mcb_bldc_sixstep_f28069mLaunc_B.SpeedControl,
      &mcb_bldc_sixstep_f28069mL_DWork.SpeedControl);

    /* End of SystemInitialize for SubSystem: '<Root>/Speed Control' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/To_LCD' */
    mcb_bldc_sixste_To_LCD_Init(&mcb_bldc_sixstep_f28069mLaunc_B.To_LCD);

    /* End of SystemInitialize for SubSystem: '<Root>/To_LCD' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Start for S-Function (c280xgpio_do): '<S133>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPBMUX2.all &= 0xFFFFFFCFU;
    GpioCtrlRegs.GPBDIR.all |= 0x40000U;
    EDIS;

    /* SystemInitialize for Enabled SubSystem: '<S131>/Calculate ADC Offset ' */
    /* SystemInitialize for Iterator SubSystem: '<S132>/For Iterator Subsystem' */
    /* Start for S-Function (c2802xadc): '<S135>/IA//IB Measurement' */
    if (MW_adcInitFlag == 0U) {
      InitAdc();
      MW_adcInitFlag = 1U;
    }

    config_ADC_SOC4_SOC5 ();

    /* Start for S-Function (c2802xadc): '<S135>/IC Measurement' */
    if (MW_adcInitFlag == 0U) {
      InitAdc();
      MW_adcInitFlag = 1U;
    }

    config_ADC_SOC3 ();

    /* End of SystemInitialize for SubSystem: '<S132>/For Iterator Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S131>/Calculate ADC Offset ' */
    mcb__SPIMasterTransfer_Init
      (&mcb_bldc_sixstep_f28069mL_DWork.SPIMasterTransfer);
    mcb__SPIMasterTransfer_Init
      (&mcb_bldc_sixstep_f28069mL_DWork.SPIMasterTransfer1);

    /* End of SystemInitialize for SubSystem: '<Root>/Hardware Init' */

    /* Outputs for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Constant: '<S3>/6PWM_Mode' */
    mcb_bldc__SPIMasterTransfer(14870U,
      &mcb_bldc_sixstep_f28069mLaunc_B.SPIMasterTransfer,
      &mcb_bldc_sixstep_f28069mL_DWork.SPIMasterTransfer);

    /* Constant: '<S3>/ADC_Gain_Setting' */
    mcb_bldc__SPIMasterTransfer(20522U,
      &mcb_bldc_sixstep_f28069mLaunc_B.SPIMasterTransfer1,
      &mcb_bldc_sixstep_f28069mL_DWork.SPIMasterTransfer1);

    /* S-Function (c280xgpio_do): '<S133>/Digital Output' incorporates:
     *  Constant: '<S133>/DRV830x_Enable'
     */
    {
      if ((1U)) {
        GpioDataRegs.GPBSET.bit.GPIO50 = 1U;
      } else {
        GpioDataRegs.GPBCLEAR.bit.GPIO50 = 1U;
      }
    }

    /* Outputs for Enabled SubSystem: '<S131>/Calculate ADC Offset ' incorporates:
     *  EnablePort: '<S132>/Enable'
     */
    /* Outputs for Iterator SubSystem: '<S132>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S135>/For Iterator'
     */
    for (s135_iter = 1U; s135_iter < 17U; s135_iter++) {
      /* Outputs for Iterator SubSystem: '<S132>/For Iterator Subsystem' incorporates:
       *  ForIterator: '<S135>/For Iterator'
       */
      mcb_bldc_sixstep_f28069mLaunc_B.ForIterator = s135_iter;

      /* S-Function (c2802xadc): '<S135>/IA//IB Measurement' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        AdcRegs.ADCSOCFRC1.bit.SOC4 = 1U;

        /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

        asm(" RPT #70|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

        float wait_index;
        for (wait_index= 11; wait_index > 0; wait_index--)
          __mnop();

#endif

        mcb_bldc_sixstep_f28069mLaunc_B.IAIBMeasurement[0] =
          (AdcResult.ADCRESULT4);
        mcb_bldc_sixstep_f28069mLaunc_B.IAIBMeasurement[1] =
          (AdcResult.ADCRESULT5);
      }

      /* S-Function (c2802xadc): '<S135>/IC Measurement' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        AdcRegs.ADCSOCFRC1.bit.SOC3 = 1U;

        /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

        asm(" RPT #44|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

        float wait_index;
        for (wait_index= 7; wait_index > 0; wait_index--)
          __mnop();

#endif

        mcb_bldc_sixstep_f28069mLaunc_B.ICMeasurement = (AdcResult.ADCRESULT3);
      }

      /* If: '<S135>/If' */
      if (mcb_bldc_sixstep_f28069mLaunc_B.ForIterator > 8U) {
        /* Outputs for IfAction SubSystem: '<S135>/If Action Subsystem' incorporates:
         *  ActionPort: '<S142>/Action Port'
         */
        /* Memory: '<S142>/Memory' */
        mcb_bldc_sixstep_f28069mLaunc_B.Memory =
          mcb_bldc_sixstep_f28069mL_DWork.Memory_PreviousInput;

        /* Sum: '<S142>/Sum' */
        mcb_bldc_sixstep_f28069mLaunc_B.Sum_eu =
          mcb_bldc_sixstep_f28069mLaunc_B.IAIBMeasurement[0] +
          mcb_bldc_sixstep_f28069mLaunc_B.Memory;

        /* Memory: '<S142>/Memory1' */
        mcb_bldc_sixstep_f28069mLaunc_B.Memory1 =
          mcb_bldc_sixstep_f28069mL_DWork.Memory1_PreviousInput;

        /* Sum: '<S142>/Sum1' */
        mcb_bldc_sixstep_f28069mLaunc_B.Sum1 =
          mcb_bldc_sixstep_f28069mLaunc_B.IAIBMeasurement[1] +
          mcb_bldc_sixstep_f28069mLaunc_B.Memory1;

        /* Memory: '<S142>/Memory2' */
        mcb_bldc_sixstep_f28069mLaunc_B.Memory2 =
          mcb_bldc_sixstep_f28069mL_DWork.Memory2_PreviousInput;

        /* Sum: '<S142>/Sum2' */
        mcb_bldc_sixstep_f28069mLaunc_B.Sum2 =
          mcb_bldc_sixstep_f28069mLaunc_B.ICMeasurement +
          mcb_bldc_sixstep_f28069mLaunc_B.Memory2;

        /* Update for Memory: '<S142>/Memory' */
        mcb_bldc_sixstep_f28069mL_DWork.Memory_PreviousInput =
          mcb_bldc_sixstep_f28069mLaunc_B.Sum_eu;

        /* Update for Memory: '<S142>/Memory1' */
        mcb_bldc_sixstep_f28069mL_DWork.Memory1_PreviousInput =
          mcb_bldc_sixstep_f28069mLaunc_B.Sum1;

        /* Update for Memory: '<S142>/Memory2' */
        mcb_bldc_sixstep_f28069mL_DWork.Memory2_PreviousInput =
          mcb_bldc_sixstep_f28069mLaunc_B.Sum2;

        /* End of Outputs for SubSystem: '<S135>/If Action Subsystem' */
      }

      /* End of If: '<S135>/If' */
    }

    /* End of Outputs for SubSystem: '<S132>/For Iterator Subsystem' */

    /* Product: '<S132>/Divide' incorporates:
     *  Constant: '<S132>/Constant'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Divide = (uint16_T)((real_T)
      mcb_bldc_sixstep_f28069mLaunc_B.Sum_eu / 8.0);

    /* If: '<S132>/If' incorporates:
     *  Constant: '<S132>/Constant1'
     *  Constant: '<S132>/Constant2'
     */
    if ((mcb_bldc_sixstep_f28069mLaunc_B.Divide > 2500U) &&
        (mcb_bldc_sixstep_f28069mLaunc_B.Divide < 3500U)) {
      /* Outputs for IfAction SubSystem: '<S132>/If Action Subsystem' incorporates:
       *  ActionPort: '<S136>/Action Port'
       */
      /* DataStoreWrite: '<S136>/Data Store Write1' */
      mcb_bldc_sixstep_f28069mL_DWork.IaOffset =
        mcb_bldc_sixstep_f28069mLaunc_B.Divide;

      /* End of Outputs for SubSystem: '<S132>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S132>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S137>/Action Port'
       */
      /* DataStoreWrite: '<S137>/Data Store Write1' incorporates:
       *  Constant: '<S137>/Constant'
       */
      mcb_bldc_sixstep_f28069mL_DWork.IaOffset = 3309U;

      /* End of Outputs for SubSystem: '<S132>/If Action Subsystem1' */
    }

    /* End of If: '<S132>/If' */

    /* Product: '<S132>/Divide1' incorporates:
     *  Constant: '<S132>/Constant'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Divide1 = (uint16_T)((real_T)
      mcb_bldc_sixstep_f28069mLaunc_B.Sum1 / 8.0);

    /* If: '<S132>/If1' incorporates:
     *  Constant: '<S132>/Constant1'
     *  Constant: '<S132>/Constant2'
     */
    if ((mcb_bldc_sixstep_f28069mLaunc_B.Divide1 > 2500U) &&
        (mcb_bldc_sixstep_f28069mLaunc_B.Divide1 < 3500U)) {
      /* Outputs for IfAction SubSystem: '<S132>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S138>/Action Port'
       */
      /* DataStoreWrite: '<S138>/Data Store Write2' */
      mcb_bldc_sixstep_f28069mL_DWork.IbOffset =
        mcb_bldc_sixstep_f28069mLaunc_B.Divide1;

      /* End of Outputs for SubSystem: '<S132>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S132>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S139>/Action Port'
       */
      /* DataStoreWrite: '<S139>/Data Store Write2' incorporates:
       *  Constant: '<S139>/Constant1'
       */
      mcb_bldc_sixstep_f28069mL_DWork.IbOffset = 3304U;

      /* End of Outputs for SubSystem: '<S132>/If Action Subsystem3' */
    }

    /* End of If: '<S132>/If1' */

    /* Product: '<S132>/Divide2' incorporates:
     *  Constant: '<S132>/Constant'
     */
    mcb_bldc_sixstep_f28069mLaunc_B.Divide2 = (uint16_T)((real_T)
      mcb_bldc_sixstep_f28069mLaunc_B.Sum2 / 8.0);

    /* If: '<S132>/If2' incorporates:
     *  Constant: '<S132>/Constant1'
     *  Constant: '<S132>/Constant2'
     */
    if ((mcb_bldc_sixstep_f28069mLaunc_B.Divide2 > 2500U) &&
        (mcb_bldc_sixstep_f28069mLaunc_B.Divide2 < 3500U)) {
      /* Outputs for IfAction SubSystem: '<S132>/If Action Subsystem4' incorporates:
       *  ActionPort: '<S140>/Action Port'
       */
      /* DataStoreWrite: '<S140>/Data Store Write2' */
      mcb_bldc_sixstep_f28069mL_DWork.IcOffset =
        mcb_bldc_sixstep_f28069mLaunc_B.Divide2;

      /* End of Outputs for SubSystem: '<S132>/If Action Subsystem4' */
    } else {
      /* Outputs for IfAction SubSystem: '<S132>/If Action Subsystem5' incorporates:
       *  ActionPort: '<S141>/Action Port'
       */
      /* DataStoreWrite: '<S141>/Data Store Write2' incorporates:
       *  Constant: '<S141>/Constant1'
       */
      mcb_bldc_sixstep_f28069mL_DWork.IcOffset = 3020U;

      /* End of Outputs for SubSystem: '<S132>/If Action Subsystem5' */
    }

    /* End of If: '<S132>/If2' */
    /* End of Outputs for SubSystem: '<S131>/Calculate ADC Offset ' */

    /* Logic: '<S131>/NOT' */
    mcb_bldc_sixstep_f28069mLaunc_B.NOT_d = false;

    /* Outputs for Enabled SubSystem: '<S131>/Default ADC Offset' incorporates:
     *  EnablePort: '<S134>/Enable'
     */
    if (mcb_bldc_sixstep_f28069mLaunc_B.NOT_d) {
      /* DataStoreWrite: '<S134>/Data Store Write1' incorporates:
       *  Constant: '<S134>/Constant'
       */
      mcb_bldc_sixstep_f28069mL_DWork.IaOffset = 3309U;

      /* DataStoreWrite: '<S134>/Data Store Write2' incorporates:
       *  Constant: '<S134>/Constant1'
       */
      mcb_bldc_sixstep_f28069mL_DWork.IbOffset = 3304U;

      /* DataStoreWrite: '<S134>/Data Store Write3' incorporates:
       *  Constant: '<S134>/Constant2'
       */
      mcb_bldc_sixstep_f28069mL_DWork.IcOffset = 3020U;
    }

    /* End of Outputs for SubSystem: '<S131>/Default ADC Offset' */
    /* End of Outputs for SubSystem: '<Root>/Hardware Init' */
  }
}

/* Model terminate function */
void mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Hardware Init' */
  mcb__SPIMasterTransfer_Term(&mcb_bldc_sixstep_f28069mL_DWork.SPIMasterTransfer);
  mcb__SPIMasterTransfer_Term
    (&mcb_bldc_sixstep_f28069mL_DWork.SPIMasterTransfer1);

  /* End of Terminate for SubSystem: '<Root>/Hardware Init' */
}

void mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_configure_interrupts(void)
{
  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(32,&ADCINT1,0);
  HWI_TIC28x_EnableIRQ(32);
}

/* Hardware Interrupt Block: '<S10>/Hardware Interrupt' */
interrupt void ADCINT1(void)
{
  volatile unsigned int PIEIER1_stack_save = PieCtrlRegs.PIEIER1.all;
  PieCtrlRegs.PIEIER1.all &= ~65;
                              /*disable group1 lower/equal priority interrupts*/
  asm(" RPT #5 || NOP");               /*wait 5 cycles        */
  IFR &= ~1;      /*eventually disable lower/equal priority pending interrupts*/
  PieCtrlRegs.PIEACK.all = 1;
                   /*ACK to allow other interrupts from the same group to fire*/
  IER |= 1;
  EINT;

  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* RateTransition: '<Root>/RT2' */
      mcb_bldc_sixstep_f28069mLaunc_B.RT2 =
        mcb_bldc_sixstep_f28069mL_DWork.RT2_Buffer[mcb_bldc_sixstep_f28069mL_DWork.RT2_ActiveBufIdx];

      /* S-Function (HardwareInterrupt_sfun): '<S10>/Hardware Interrupt' */
      mcb_bldc_six_CurrentControl();

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S10>/Hardware Interrupt' */

      /* RateTransition: '<Root>/RT1' */
      mcb_bldc_sixstep_f28069mL_DWork.RT1_Buffer[mcb_bldc_sixstep_f28069mL_DWork.RT1_semaphoreTaken
        == 0] = mcb_bldc_sixstep_f28069mLaunc_B.Add1;
      mcb_bldc_sixstep_f28069mL_DWork.RT1_ActiveBufIdx =
        (mcb_bldc_sixstep_f28069mL_DWork.RT1_semaphoreTaken == 0);

      /* RateTransition: '<Root>/RT3' */
      mcb_bldc_sixstep_f28069mL_DWork.RT3_Buffer[mcb_bldc_sixstep_f28069mL_DWork.RT3_semaphoreTaken
        == 0] = mcb_bldc_sixstep_f28069mLaunc_B.Add1;
      mcb_bldc_sixstep_f28069mL_DWork.RT3_ActiveBufIdx =
        (mcb_bldc_sixstep_f28069mL_DWork.RT3_semaphoreTaken == 0);
    }
  }

  /* Clear occurred EOC event event */
  AdcRegs.ADCINTFLGCLR.bit.ADCINT1= 1;

  /* Clear occurred Overflow event event */
  AdcRegs.ADCINTOVFCLR.bit.ADCINT1= 1;
  DINT;
  /* disable global interrupts during context switch, CPU will enable global interrupts after exiting ISR */
  PieCtrlRegs.PIEIER1.all = PIEIER1_stack_save;
                                   /*restore PIEIER register that was modified*/
  HWI_TIC28x_AcknowledgeIrq(32);
}

void mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_unconfigure_interrupts (void)
{
  HWI_TIC28x_DisableIRQ(32);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
