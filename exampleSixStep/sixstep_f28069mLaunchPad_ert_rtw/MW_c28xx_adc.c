#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Examples.h"
#include "F2806x_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "sixstep_f28069mLaunchPad.h"
#include "sixstep_f28069mLaunchPad_private.h"

void config_ADC_SOC6_SOC7(void)
{
  EALLOW;
  AdcRegs.ADCCTL2.bit.CLKDIV2EN = 1U;  /* Set ADC clock division */
  AdcRegs.ADCCTL2.bit.CLKDIV4EN = 0U;  /* Set ADC clock division */
  AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 0U;
                                 /* Set ADCNONOVERLAP contorl bit to  Allowed */
  AdcRegs.ADCSAMPLEMODE.bit.SIMULEN6 = 1U;
                                /* Simultaneous sample mode set for SOC6_SOC7.*/
  AdcRegs.ADCSOC6CTL.bit.CHSEL = 0U;
                             /* Set SOC6 channel select to ADCINA0 and ADCINB0*/
  AdcRegs.ADCSOC6CTL.bit.TRIGSEL = 0U;
  AdcRegs.ADCSOC6CTL.bit.ACQPS = (uint16_T)6.0;
                                /* Set SOC6 S/H Window to 7.0 ADC Clock Cycles*/
  AdcRegs.ADCINTSOCSEL1.bit.SOC6 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdcRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcRegs.ADCCTL1.bit.ADCREFSEL = 0U ; /* Set Reference Voltage*/
  AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcRegs.SOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADC_SOC4(void)
{
  EALLOW;
  AdcRegs.ADCCTL2.bit.CLKDIV2EN = 1U;  /* Set ADC clock division */
  AdcRegs.ADCCTL2.bit.CLKDIV4EN = 0U;  /* Set ADC clock division */
  AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 0U;
                                 /* Set ADCNONOVERLAP contorl bit to  Allowed */
  AdcRegs.ADCSAMPLEMODE.bit.SIMULEN4 = 0U;/* Single sample mode set for SOC4.*/
  AdcRegs.ADCSOC4CTL.bit.CHSEL = 1U;   /* Set SOC4 channel select to ADCINA1*/
  AdcRegs.ADCSOC4CTL.bit.TRIGSEL = 0U;
  AdcRegs.ADCSOC4CTL.bit.ACQPS = (uint16_T)6.0;
                                /* Set SOC4 S/H Window to 7.0 ADC Clock Cycles*/
  AdcRegs.ADCINTSOCSEL1.bit.SOC4 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdcRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcRegs.ADCCTL1.bit.ADCREFSEL = 0U ; /* Set Reference Voltage*/
  AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcRegs.SOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADC_SOC0(void)
{
  EALLOW;
  AdcRegs.ADCCTL2.bit.CLKDIV2EN = 1U;  /* Set ADC clock division */
  AdcRegs.ADCCTL2.bit.CLKDIV4EN = 0U;  /* Set ADC clock division */
  AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 0U;
                                 /* Set ADCNONOVERLAP contorl bit to  Allowed */
  AdcRegs.ADCSAMPLEMODE.bit.SIMULEN0 = 0U;/* Single sample mode set for SOC0.*/
  AdcRegs.ADCSOC0CTL.bit.CHSEL = 1U;   /* Set SOC0 channel select to ADCINA1*/
  AdcRegs.ADCSOC0CTL.bit.TRIGSEL = 5U;
  AdcRegs.ADCSOC0CTL.bit.ACQPS = (uint16_T)6.0;
                                /* Set SOC0 S/H Window to 7.0 ADC Clock Cycles*/
  AdcRegs.INTSEL1N2.bit.INT1E = 1U;    /* Enabled/Disable ADCINT1 interrupt*/
  AdcRegs.INTSEL1N2.bit.INT1SEL = 0U;  /* Setup EOC0 to trigger ADCINT1*/
  AdcRegs.INTSEL1N2.bit.INT1CONT = 1U;
                                     /* Enable/Disable ADCINT1 Continuous mode*/
  AdcRegs.ADCINTSOCSEL1.bit.SOC0 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdcRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcRegs.ADCCTL1.bit.ADCREFSEL = 0U ; /* Set Reference Voltage*/
  AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcRegs.SOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}

void config_ADC_SOC2_SOC3(void)
{
  EALLOW;
  AdcRegs.ADCCTL2.bit.CLKDIV2EN = 1U;  /* Set ADC clock division */
  AdcRegs.ADCCTL2.bit.CLKDIV4EN = 0U;  /* Set ADC clock division */
  AdcRegs.ADCCTL2.bit.ADCNONOVERLAP = 0U;
                                 /* Set ADCNONOVERLAP contorl bit to  Allowed */
  AdcRegs.ADCSAMPLEMODE.bit.SIMULEN2 = 1U;
                                /* Simultaneous sample mode set for SOC2_SOC3.*/
  AdcRegs.ADCSOC2CTL.bit.CHSEL = 0U;
                             /* Set SOC2 channel select to ADCINA0 and ADCINB0*/
  AdcRegs.ADCSOC2CTL.bit.TRIGSEL = 5U;
  AdcRegs.ADCSOC2CTL.bit.ACQPS = (uint16_T)6.0;
                                /* Set SOC2 S/H Window to 7.0 ADC Clock Cycles*/
  AdcRegs.ADCINTSOCSEL1.bit.SOC2 = 0U;
                                   /* SOCx No ADCINT Interrupt Trigger Select.*/
  AdcRegs.ADCOFFTRIM.bit.OFFTRIM = (uint16_T)AdcRegs.ADCOFFTRIM.bit.OFFTRIM;/* Set Offset Error Correctino Value*/
  AdcRegs.ADCCTL1.bit.ADCREFSEL = 0U ; /* Set Reference Voltage*/
  AdcRegs.ADCCTL1.bit.INTPULSEPOS = 1U;
                                /* Late interrupt pulse trips AdcResults latch*/
  AdcRegs.SOCPRICTL.bit.SOCPRIORITY = 0U;/* All in round robin mode SOC Priority*/
  EDIS;
}
