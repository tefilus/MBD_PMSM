/*
 * File: mcb_bldc_sixstep_f28069mLaunchPad_button.h
 *
 * Code generated for Simulink model 'mcb_bldc_sixstep_f28069mLaunchPad_button'.
 *
 * Model version                  : 7.75
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat May 17 16:39:17 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_mcb_bldc_sixstep_f28069mLaunchPad_button_h_
#define RTW_HEADER_mcb_bldc_sixstep_f28069mLaunchPad_button_h_
#ifndef mcb_bldc_sixstep_f28069mLaunchPad_button_COMMON_INCLUDES_
#define mcb_bldc_sixstep_f28069mLaunchPad_button_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Gpio.h"
#include "DSP28xx_SciUtil.h"
#include "F2806x_Examples.h"
#include "IQmathLib.h"
#include "MW_SPI.h"
#endif           /* mcb_bldc_sixstep_f28069mLaunchPad_button_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "mcb_bldc_sixstep_f28069mLaunchPad_button_types.h"
#include "To_LCD.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <string.h>
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define mcb_bldc_sixstep_f28069mLaunchPad_button_M (mcb_bldc_sixstep_f28069mLaun_M)

extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals for system '<S133>/SPI Master Transfer' */
typedef struct {
  uint16_T SPIMasterTransfer;          /* '<S133>/SPI Master Transfer' */
} rtB_SPIMasterTransfer_mcb_bldc_;

/* Block states (default storage) for system '<S133>/SPI Master Transfer' */
typedef struct {
  codertarget_tic2000_blocks_SPIM obj; /* '<S133>/SPI Master Transfer' */
  boolean_T objisempty;                /* '<S133>/SPI Master Transfer' */
} rtDW_SPIMasterTransfer_mcb_bldc;

/* Block signals for system '<Root>/Speed Control' */
typedef struct {
  real32_T Switch;                     /* '<S144>/Switch' */
  real32_T Product;                    /* '<S199>/Product' */
  real32_T UnitDelay;                  /* '<S199>/Unit Delay' */
  real32_T Product1;                   /* '<S199>/Product1' */
  real32_T Add1;                       /* '<S199>/Add1' */
  real32_T Sum;                        /* '<S143>/Sum' */
  real32_T PProdOut;                   /* '<S185>/PProd Out' */
  real32_T Ki2;                        /* '<S143>/Ki2' */
  real32_T Integrator;                 /* '<S180>/Integrator' */
  real32_T Sum_j;                      /* '<S189>/Sum' */
  real32_T DeadZone;                   /* '<S173>/DeadZone' */
  real32_T IProdOut;                   /* '<S177>/IProd Out' */
  real32_T Switch_a;                   /* '<S171>/Switch' */
  real32_T Saturation;                 /* '<S187>/Saturation' */
  int16_T Switch1;                     /* '<S171>/Switch1' */
  int16_T Switch2;                     /* '<S171>/Switch2' */
  boolean_T DataStoreRead2;            /* '<S143>/Data Store Read2' */
  boolean_T DataStoreRead1;            /* '<S144>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S143>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S171>/Relational Operator' */
  boolean_T fixforDTpropagationissue;/* '<S171>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                    /* '<S171>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S171>/Equal1' */
  boolean_T AND3;                      /* '<S171>/AND3' */
} rtB_SpeedControl_mcb_bldc_sixst;

/* Block states (default storage) for system '<Root>/Speed Control' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S199>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S180>/Integrator' */
  int16_T Integrator_PrevResetState;   /* '<S180>/Integrator' */
} rtDW_SpeedControl_mcb_bldc_sixs;

/* Block signals (default storage) */
typedef struct {
  real_T PulseGenerator;               /* '<S6>/Pulse Generator' */
  real_T Merge1;                       /* '<S127>/Merge1' */
  real_T Sign;                         /* '<S127>/Sign' */
  real_T ADCThreshold;                 /* '<S126>/ADCThreshold' */
  real_T cu[3];                        /* '<S99>/Switch' */
  real_T Sum;                          /* '<S126>/Sum' */
  uint32_T PositionToCount;            /* '<S104>/PositionToCount' */
  uint32_T Delay;                      /* '<S104>/Delay' */
  real32_T DataStoreRead;              /* '<Root>/Data Store Read' */
  real32_T RT1;                        /* '<Root>/RT1' */
  real32_T RT6;                        /* '<Root>/RT6' */
  real32_T RT2;                        /* '<Root>/RT2' */
  real32_T toPU;                       /* '<S126>/toPU' */
  real32_T conductSpeed;               /* '<S126>/conductSpeed' */
  real32_T Idc_ref;                    /* '<S13>/Abs' */
  real32_T DataTypeConversion1[3];     /* '<S97>/Data Type Conversion1' */
  real32_T DataTypeConversion[3];      /* '<S99>/Data Type Conversion' */
  real32_T Sum_o;                      /* '<S97>/Sum' */
  real32_T IDC;                        /* '<S97>/Unary Minus' */
  real32_T Sum_c;                      /* '<S18>/Sum' */
  real32_T PProdOut;                   /* '<S59>/PProd Out' */
  real32_T Kp1;                        /* '<S18>/Kp1' */
  real32_T Integrator;                 /* '<S54>/Integrator' */
  real32_T Sum_e;                      /* '<S63>/Sum' */
  real32_T Sign_b;                     /* '<S13>/Sign' */
  real32_T DeadZone;                   /* '<S47>/DeadZone' */
  real32_T IProdOut;                   /* '<S51>/IProd Out' */
  real32_T Switch;                     /* '<S45>/Switch' */
  real32_T DTC;                        /* '<S120>/DTC' */
  real32_T Product;                    /* '<S103>/Product' */
  real32_T DTC_a;                      /* '<S125>/DTC' */
  real32_T SpeedGain;                  /* '<S104>/SpeedGain' */
  real32_T Product_g;                  /* '<S107>/Product' */
  real32_T UnitDelay;                  /* '<S107>/Unit Delay' */
  real32_T Product1;                   /* '<S107>/Product1' */
  real32_T Add1;                       /* '<S107>/Add1' */
  real32_T Switch_f;                   /* '<S109>/Switch' */
  real32_T Merge;                      /* '<S110>/Merge' */
  real32_T Numberofpolepairs;          /* '<S115>/Number of pole pairs' */
  real32_T Floor;                      /* '<S111>/Floor' */
  real32_T Add;                        /* '<S111>/Add' */
  real32_T DataTypeConversion1_o[6];   /* '<S13>/Data Type Conversion1' */
  real32_T Saturation;                 /* '<S61>/Saturation' */
  real32_T duty[6];                    /* '<S13>/Product' */
  int32_T DataTypeConversion_b[3];     /* '<S97>/Data Type Conversion' */
  int32_T Add_g[3];                    /* '<S97>/Add' */
  int32_T Q17perunitconversion[3];     /* '<S97>/Q17 per unit conversion' */
  int32_T SpeedCount;                  /* '<S104>/SpeedCount' */
  uint16_T Divide;                     /* '<S132>/Divide' */
  uint16_T Divide1;                    /* '<S132>/Divide1' */
  uint16_T Divide2;                    /* '<S132>/Divide2' */
  uint16_T ForIterator;                /* '<S135>/For Iterator' */
  uint16_T IAIBMeasurement[2];         /* '<S135>/IA//IB Measurement' */
  uint16_T ICMeasurement;              /* '<S135>/IC Measurement' */
  uint16_T Memory;                     /* '<S142>/Memory' */
  uint16_T Sum_eu;                     /* '<S142>/Sum' */
  uint16_T Memory1;                    /* '<S142>/Memory1' */
  uint16_T Sum1;                       /* '<S142>/Sum1' */
  uint16_T Memory2;                    /* '<S142>/Memory2' */
  uint16_T Sum2;                       /* '<S142>/Sum2' */
  uint16_T eQEP_o1;                    /* '<S16>/eQEP' */
  uint16_T eQEP_o2;                    /* '<S16>/eQEP' */
  uint16_T speedRef_ADC;               /* '<S16>/speedRef_ADC' */
  uint16_T IAIBMeasurement_p[2];       /* '<S16>/IA//IB Measurement' */
  uint16_T ICMeasurement_l;            /* '<S16>/IC Measurement' */
  uint16_T DataStoreRead_i;            /* '<S97>/Data Store Read' */
  uint16_T DataStoreRead1;             /* '<S97>/Data Store Read1' */
  uint16_T DataStoreRead2;             /* '<S97>/Data Store Read2' */
  uint16_T Switch1[6];                 /* '<S11>/Switch1' */
  uint16_T Output;                     /* '<S90>/Output' */
  uint16_T DataTypeConversion3[3];     /* '<S92>/Data Type Conversion3' */
  uint16_T SCI_Tx_Data[4];             /* '<S14>/Merge' */
  uint16_T SCI_Tx_Iteration;           /* '<S14>/Merge1' */
  uint16_T FixPtSum1;                  /* '<S95>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S96>/FixPt Switch' */
  uint16_T Merge_g;                    /* '<S103>/Merge' */
  uint16_T Sum3;                       /* '<S117>/Sum3' */
  uint16_T Sum7;                       /* '<S117>/Sum7' */
  uint16_T Data[3];                    /* '<S91>/Data' */
  uint16_T Data_f[3];                  /* '<S93>/Data' */
  uint16_T Data_fw[3];                 /* '<S94>/Data' */
  uint16_T IndexVector;                /* '<S17>/Index Vector' */
  uint16_T Add_gl;                     /* '<S17>/Add' */
  uint16_T Scale_to_PWM_Counter_PRD[6];/* '<S11>/Scale_to_PWM_Counter_PRD' */
  int16_T DataTypeConversion_l[3];     /* '<S92>/Data Type Conversion' */
  int16_T WhileIterator;               /* '<S17>/While Iterator' */
  uint16_T Merge_e;                    /* '<S71>/Merge' */
  uint16_T ShiftArithmetic;            /* '<S87>/Shift Arithmetic' */
  uint16_T A;                          /* '<S87>/Bitwise AND1' */
  uint16_T ShiftArithmetic1;           /* '<S87>/Shift Arithmetic1' */
  uint16_T B;                          /* '<S87>/Bitwise AND2' */
  uint16_T C;                          /* '<S87>/Bitwise AND3' */
  int16_T Switch1_b;                   /* '<S45>/Switch1' */
  int16_T Switch2;                     /* '<S45>/Switch2' */
  boolean_T CWCCW_GPIO7;               /* '<S7>/CW//CCW_GPIO7' */
  boolean_T ONOFF_GPIO6;               /* '<S7>/ON//OFF_GPIO6' */
  boolean_T NOT;                       /* '<S6>/NOT' */
  boolean_T NOT_d;                     /* '<S131>/NOT' */
  boolean_T DataStoreRead_e;           /* '<S127>/Data Store Read' */
  boolean_T Enable;                    /* '<S11>/Enable' */
  boolean_T DataStoreRead1_l;          /* '<S18>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S18>/Logical Operator' */
  boolean_T Merge_n[3];                /* '<S74>/Merge' */
  boolean_T Merge_k[6];                /* '<S75>/Merge' */
  boolean_T RelationalOperator;        /* '<S45>/Relational Operator' */
  boolean_T fixforDTpropagationissue; /* '<S45>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                     /* '<S45>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S45>/Equal1' */
  boolean_T AND3;                      /* '<S45>/AND3' */
  boolean_T DataTypeConversion_j;      /* '<S87>/Data Type Conversion' */
  boolean_T DataTypeConversion1_d;     /* '<S87>/Data Type Conversion1' */
  boolean_T DataTypeConversion2;       /* '<S87>/Data Type Conversion2' */
  rtB_To_LCD_mcb_bldc_sixstep_f28 To_LCD;/* '<Root>/To_LCD' */
  rtB_SpeedControl_mcb_bldc_sixst SpeedControl;/* '<Root>/Speed Control' */
  rtB_SPIMasterTransfer_mcb_bldc_ SPIMasterTransfer1;/* '<S133>/SPI Master Transfer' */
  rtB_SPIMasterTransfer_mcb_bldc_ SPIMasterTransfer;/* '<S133>/SPI Master Transfer' */
} BlockIO_mcb_bldc_sixstep_f28069;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Sum_DWORK1;                   /* '<S126>/Sum' */
  real32_T Integrator_DSTATE;          /* '<S54>/Integrator' */
  real32_T UnitDelay_DSTATE;           /* '<S107>/Unit Delay' */
  uint32_T Delay_DSTATE[20];           /* '<S104>/Delay' */
  volatile real32_T RT1_Buffer[2];     /* '<Root>/RT1' */
  volatile real32_T RT2_Buffer[2];     /* '<Root>/RT2' */
  real32_T desiredSpeed;               /* '<Root>/g_desiredSpeed' */
  real32_T speedSCI_B;                 /* '<Root>/g_speedSCI_B' */
  int32_T clockTickCounter;            /* '<S6>/Pulse Generator' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S6>/Digital Output' */
  int32_T DigitalOutput1_FRAC_LEN;     /* '<S6>/Digital Output1' */
  int32_T DigitalOutput_FRAC_LEN_n;    /* '<S133>/Digital Output' */
  int32_T DigitalOutput_FRAC_LEN_l;    /* '<S11>/Digital Output' */
  int32_T Add_DWORK1[3];               /* '<S97>/Add' */
  int32_T SpeedCount_DWORK1;           /* '<S104>/SpeedCount' */
  uint16_T Output_DSTATE;              /* '<S90>/Output' */
  volatile int16_T RT1_ActiveBufIdx;   /* '<Root>/RT1' */
  volatile int16_T RT1_semaphoreTaken; /* '<Root>/RT1' */
  volatile int16_T RT2_ActiveBufIdx;   /* '<Root>/RT2' */
  uint16_T IaOffset;                   /* '<Root>/g_IaOffset' */
  uint16_T IbOffset;                   /* '<Root>/g_IbOffset' */
  uint16_T IcOffset;                   /* '<Root>/g_IcOffset' */
  uint16_T Memory_PreviousInput;       /* '<S142>/Memory' */
  uint16_T Memory1_PreviousInput;      /* '<S142>/Memory1' */
  uint16_T Memory2_PreviousInput;      /* '<S142>/Memory2' */
  uint16_T CircBufIdx;                 /* '<S104>/Delay' */
  uint16_T Add_DWORK1_f;               /* '<S17>/Add' */
  int16_T Integrator_PrevResetState;   /* '<S54>/Integrator' */
  boolean_T Enable;                    /* '<Root>/g_Enable' */
  boolean_T readTorqueSign;            /* '<Root>/g_TorqueSign' */
  rtDW_To_LCD_mcb_bldc_sixstep_f2 To_LCD;/* '<Root>/To_LCD' */
  rtDW_SpeedControl_mcb_bldc_sixs SpeedControl;/* '<Root>/Speed Control' */
  rtDW_SPIMasterTransfer_mcb_bldc SPIMasterTransfer1;/* '<S133>/SPI Master Transfer' */
  rtDW_SPIMasterTransfer_mcb_bldc SPIMasterTransfer;/* '<S133>/SPI Master Transfer' */
} D_Work_mcb_bldc_sixstep_f28069m;

/* Invariant block signals (default storage) */
typedef struct {
  const uint16_T Width;                /* '<S14>/Width' */
} ConstBlockIO_mcb_bldc_sixstep_f;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S88>/SA1'
   *   '<S89>/SA2'
   */
  boolean_T pooled13[8];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S88>/SA2'
   *   '<S89>/SA1'
   */
  boolean_T pooled14[8];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S88>/SB1'
   *   '<S89>/SB2'
   */
  boolean_T pooled15[8];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S88>/SB2'
   *   '<S89>/SB1'
   */
  boolean_T pooled16[8];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S88>/SC1'
   *   '<S89>/SC2'
   */
  boolean_T pooled17[8];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S88>/SC2'
   *   '<S89>/SC1'
   */
  boolean_T pooled18[8];
} ConstParam_mcb_bldc_sixstep_f28;

/* Real-time Model Data Structure */
struct tag_RTM_mcb_bldc_sixstep_f28069 {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern BlockIO_mcb_bldc_sixstep_f28069 mcb_bldc_sixstep_f28069mLaunc_B;

/* Block states (default storage) */
extern D_Work_mcb_bldc_sixstep_f28069m mcb_bldc_sixstep_f28069mL_DWork;
extern const ConstBlockIO_mcb_bldc_sixstep_f mcb_bldc_sixstep_f28069m_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstParam_mcb_bldc_sixstep_f28 mcb_bldc_sixstep_f28069m_ConstP;

/* External function called from main */
extern void mcb_bldc_sixstep_f28069mLaunchPad_button_SetEventsForThisBaseStep
  (boolean_T *eventFlags);

/* Model entry point functions */
extern void mcb_bldc_sixstep_f28069mLaunchPad_button_initialize(void);
extern void mcb_bldc_sixstep_f28069mLaunchPad_button_step0(void);
extern void mcb_bldc_sixstep_f28069mLaunchPad_button_step1(void);
extern void mcb_bldc_sixstep_f28069mLaunchPad_button_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mcb_bldc_sixstep_f2806 *const mcb_bldc_sixstep_f28069mLaun_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void ADCINT1(void);
  void mcb_bldc_sixstep_f28069mLaunchPad_button_configure_interrupts (void);
  void mcb_bldc_sixstep_f28069mLaunchPad_button_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button'
 * '<S1>'   : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Code generation'
 * '<S2>'   : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control'
 * '<S3>'   : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Hardware Init'
 * '<S4>'   : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control'
 * '<S5>'   : 'mcb_bldc_sixstep_f28069mLaunchPad_button/To_LCD'
 * '<S6>'   : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Toggle LED'
 * '<S7>'   : 'mcb_bldc_sixstep_f28069mLaunchPad_button/controlButton'
 * '<S8>'   : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Code generation/HWI_ADCINT1'
 * '<S9>'   : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Code generation/HWI_ADCINT1/ECSoC'
 * '<S10>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Code generation/HWI_ADCINT1/ECSoC/ECSimCodegen'
 * '<S11>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/ Code Generation'
 * '<S12>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/ Code Generation1'
 * '<S13>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System'
 * '<S14>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Data_Logging'
 * '<S15>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling'
 * '<S16>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Sensor Driver Blocks (codegen)'
 * '<S17>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/ Code Generation1/CodeGeneration'
 * '<S18>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc'
 * '<S19>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation'
 * '<S20>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset'
 * '<S21>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S22>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S23>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S24>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S25>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S26>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S27>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S28>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S29>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S30>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S31>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S32>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S33>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S34>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S35>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S36>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S37>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S38>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S39>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S40>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S41>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S42>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S43>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S44>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S45>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S46>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S47>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S48>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S49>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S50>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S51>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S52>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S53>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S54>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S55>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S56>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S57>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S58>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S59>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S60>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S61>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S62>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S63>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S64>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S65>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S66>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S67>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S68>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S69>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S70>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S71>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation'
 * '<S72>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation/HALL'
 * '<S73>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position'
 * '<S74>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Sector2vector'
 * '<S75>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation/SwitchingSequence'
 * '<S76>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant'
 * '<S77>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120'
 * '<S78>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem'
 * '<S79>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem1'
 * '<S80>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem2'
 * '<S81>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem3'
 * '<S82>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem4'
 * '<S83>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem5'
 * '<S84>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem6'
 * '<S85>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Sector2vector/Bit Extract'
 * '<S86>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Sector2vector/Default '
 * '<S87>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Sector2vector/Bit Extract/Extract Bits'
 * '<S88>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation/SwitchingSequence/negative'
 * '<S89>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Control_System/Pos_Commutation/Six Step Commutation/SwitchingSequence/positive'
 * '<S90>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Data_Logging/Counter Limited'
 * '<S91>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Data_Logging/Data'
 * '<S92>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Data_Logging/Data_Conditioning'
 * '<S93>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Data_Logging/End'
 * '<S94>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Data_Logging/Start'
 * '<S95>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Data_Logging/Counter Limited/Increment Real World'
 * '<S96>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Data_Logging/Counter Limited/Wrap To Zero'
 * '<S97>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/Convert ADC value to PU'
 * '<S98>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback'
 * '<S99>'  : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/Convert ADC value to PU/LowerSwitchCurrents'
 * '<S100>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed'
 * '<S101>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/IIR Filter'
 * '<S102>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position'
 * '<S103>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder'
 * '<S104>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Speed Measurement'
 * '<S105>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/IIR Filter/IIR Filter'
 * '<S106>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass'
 * '<S107>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S108>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec'
 * '<S109>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point'
 * '<S110>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset'
 * '<S111>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec'
 * '<S112>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem'
 * '<S113>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem1'
 * '<S114>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem'
 * '<S115>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem/Dialog'
 * '<S116>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/DT_Handle'
 * '<S117>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset'
 * '<S118>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/PositionResetAtIndex'
 * '<S119>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem'
 * '<S120>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/DT_Handle/floating-point'
 * '<S121>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem'
 * '<S122>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem/Dialog'
 * '<S123>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem/Dialog'
 * '<S124>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Speed Measurement/DT_Handle'
 * '<S125>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Speed Measurement/DT_Handle/floating-point'
 * '<S126>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Sensor Driver Blocks (codegen)/Convert ADC to PU'
 * '<S127>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Sensor Driver Blocks (codegen)/Convert ADC to PU/Torque sign'
 * '<S128>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Sensor Driver Blocks (codegen)/Convert ADC to PU/Torque sign/Clockwise'
 * '<S129>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Current Control/Sensor Driver Blocks (codegen)/Convert ADC to PU/Torque sign/Counter_Clockwise'
 * '<S130>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Hardware Init/Variant Subsystem'
 * '<S131>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Hardware Init/Variant Subsystem/Code Generation'
 * '<S132>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset '
 * '<S133>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Hardware Init/Variant Subsystem/Code Generation/DRV Enable'
 * '<S134>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Hardware Init/Variant Subsystem/Code Generation/Default ADC Offset'
 * '<S135>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem'
 * '<S136>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem'
 * '<S137>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem1'
 * '<S138>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem2'
 * '<S139>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem3'
 * '<S140>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem4'
 * '<S141>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem5'
 * '<S142>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem'
 * '<S143>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed'
 * '<S144>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/Speed_Ref_Selector'
 * '<S145>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S146>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S147>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S148>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S149>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S150>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S151>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S152>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S153>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S154>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S155>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S156>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S157>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S158>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S159>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S160>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S161>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S162>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S163>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S164>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S165>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S166>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S167>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S168>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S169>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S170>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S171>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S172>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S173>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S174>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S175>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S176>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S177>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S178>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S179>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S180>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S181>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S182>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S183>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S184>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S185>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S186>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S187>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S188>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S189>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S190>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S191>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S192>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S193>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S194>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S195>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S196>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S197>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S198>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S199>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S200>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/To_LCD/Data_Logging'
 * '<S201>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/To_LCD/SCI_Tx_codegen'
 * '<S202>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/To_LCD/Data_Logging/Data'
 * '<S203>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/To_LCD/Data_Logging/Data_Conditioning'
 * '<S204>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/To_LCD/Data_Logging/End'
 * '<S205>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/To_LCD/Data_Logging/Start'
 * '<S206>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/To_LCD/Data_Logging/dataIndexCounter'
 * '<S207>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/To_LCD/Data_Logging/dataIndexCounter/Increment Real World'
 * '<S208>' : 'mcb_bldc_sixstep_f28069mLaunchPad_button/To_LCD/Data_Logging/dataIndexCounter/Wrap To Zero'
 */
#endif              /* RTW_HEADER_mcb_bldc_sixstep_f28069mLaunchPad_button_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
