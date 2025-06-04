/*
 * File: sixstep_f28069mLaunchPad.h
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

#ifndef RTW_HEADER_sixstep_f28069mLaunchPad_h_
#define RTW_HEADER_sixstep_f28069mLaunchPad_h_
#ifndef sixstep_f28069mLaunchPad_COMMON_INCLUDES_
#define sixstep_f28069mLaunchPad_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Gpio.h"
#include "DSP28xx_SciUtil.h"
#include "F2806x_Examples.h"
#include "IQmathLib.h"
#include "MW_SPI.h"
#endif                           /* sixstep_f28069mLaunchPad_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "sixstep_f28069mLaunchPad_types.h"
#include "To_LCD.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <string.h>
#include <stddef.h>
#include "zero_crossing_types.h"
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

extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals for system '<S21>/Bit Extract' */
typedef struct {
  uint16_T ShiftArithmetic;            /* '<S34>/Shift Arithmetic' */
  uint16_T A;                          /* '<S34>/Bitwise AND1' */
  uint16_T ShiftArithmetic1;           /* '<S34>/Shift Arithmetic1' */
  uint16_T B;                          /* '<S34>/Bitwise AND2' */
  uint16_T C;                          /* '<S34>/Bitwise AND3' */
  boolean_T DataTypeConversion;        /* '<S34>/Data Type Conversion' */
  boolean_T DataTypeConversion1;       /* '<S34>/Data Type Conversion1' */
  boolean_T DataTypeConversion2;       /* '<S34>/Data Type Conversion2' */
} rtB_BitExtract_sixstep_f28069mL;

/* Block signals for system '<S217>/SPI Master Transfer' */
typedef struct {
  uint16_T SPIMasterTransfer;          /* '<S217>/SPI Master Transfer' */
} rtB_SPIMasterTransfer_sixstep_f;

/* Block states (default storage) for system '<S217>/SPI Master Transfer' */
typedef struct {
  codertarget_tic2000_blocks_SPIM obj; /* '<S217>/SPI Master Transfer' */
  boolean_T objisempty;                /* '<S217>/SPI Master Transfer' */
} rtDW_SPIMasterTransfer_sixstep_;

/* Block signals for system '<Root>/Speed Control' */
typedef struct {
  real32_T Switch;                     /* '<S232>/Switch' */
  real32_T Product;                    /* '<S287>/Product' */
  real32_T UnitDelay;                  /* '<S287>/Unit Delay' */
  real32_T Product1;                   /* '<S287>/Product1' */
  real32_T Add1;                       /* '<S287>/Add1' */
  real32_T Sum;                        /* '<S231>/Sum' */
  real32_T PProdOut;                   /* '<S273>/PProd Out' */
  real32_T Ki2;                        /* '<S231>/Ki2' */
  real32_T Integrator;                 /* '<S268>/Integrator' */
  real32_T Sum_j;                      /* '<S277>/Sum' */
  real32_T DeadZone;                   /* '<S261>/DeadZone' */
  real32_T IProdOut;                   /* '<S265>/IProd Out' */
  real32_T Switch_a;                   /* '<S259>/Switch' */
  real32_T Saturation;                 /* '<S275>/Saturation' */
  int16_T Switch1;                     /* '<S259>/Switch1' */
  int16_T Switch2;                     /* '<S259>/Switch2' */
  boolean_T DataStoreRead2;            /* '<S231>/Data Store Read2' */
  boolean_T DataStoreRead1;            /* '<S232>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S231>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S259>/Relational Operator' */
  boolean_T fixforDTpropagationissue;/* '<S259>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                    /* '<S259>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S259>/Equal1' */
  boolean_T AND3;                      /* '<S259>/AND3' */
} rtB_SpeedControl_sixstep_f28069;

/* Block states (default storage) for system '<Root>/Speed Control' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S287>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S268>/Integrator' */
  int16_T Integrator_PrevResetState;   /* '<S268>/Integrator' */
} rtDW_SpeedControl_sixstep_f2806;

/* Block signals (default storage) */
typedef struct {
  real_T cu[3];                        /* '<S117>/Switch' */
  uint32_T DigitalInput2[2];           /* '<S206>/Digital Input2' */
  uint32_T DigitalInput3;              /* '<S206>/Digital Input3' */
  uint32_T PositionToCount;            /* '<S180>/PositionToCount' */
  uint32_T Delay;                      /* '<S180>/Delay' */
  uint32_T ShiftArithmetic;            /* '<S122>/Shift Arithmetic' */
  uint32_T ShiftArithmetic1;           /* '<S122>/Shift Arithmetic1' */
  uint32_T Sum;                        /* '<S122>/Sum' */
  uint32_T UnitDelay;                  /* '<S121>/Unit Delay' */
  uint32_T Uk1;                        /* '<S174>/Delay Input1' */
  uint32_T speedCountDelay;            /* '<S123>/speedCountDelay' */
  uint32_T Delay_c;                    /* '<S121>/Delay' */
  uint32_T Sum_o;                      /* '<S121>/Sum' */
  uint32_T Sum_o0;                     /* '<S175>/Sum' */
  uint32_T UnitDelay1;                 /* '<S175>/Unit Delay1' */
  uint32_T Max;                        /* '<S127>/Max' */
  real32_T RT1;                        /* '<Root>/RT1' */
  real32_T RT6;                        /* '<Root>/RT6' */
  real32_T RT2;                        /* '<Root>/RT2' */
  real32_T DataTypeConversion1[2];     /* '<S228>/Data Type Conversion1' */
  real32_T DataTypeConversion1_l;      /* '<S5>/Data Type Conversion1' */
  real32_T Merge1;                     /* '<S11>/Merge1' */
  real32_T DataTypeConversion1_n[3];   /* '<S114>/Data Type Conversion1' */
  real32_T DataTypeConversion[3];      /* '<S117>/Data Type Conversion' */
  real32_T Sum_o5;                     /* '<S114>/Sum' */
  real32_T IDC;                        /* '<S114>/Unary Minus' */
  real32_T Idc_ref;                    /* '<S9>/Abs' */
  real32_T Sign;                       /* '<S9>/Sign' */
  real32_T Sum_c;                      /* '<S16>/Sum' */
  real32_T PProdOut;                   /* '<S76>/PProd Out' */
  real32_T Kp1;                        /* '<S16>/Kp1' */
  real32_T Integrator;                 /* '<S71>/Integrator' */
  real32_T Sum_e;                      /* '<S80>/Sum' */
  real32_T DeadZone;                   /* '<S64>/DeadZone' */
  real32_T IProdOut;                   /* '<S68>/IProd Out' */
  real32_T Switch;                     /* '<S62>/Switch' */
  real32_T Speed_PU;                   /* '<S1>/Input Scaling' */
  real32_T Saturation;                 /* '<S78>/Saturation' */
  real32_T DataTypeConversion1_o[6];   /* '<S9>/Data Type Conversion1' */
  real32_T duty[6];                    /* '<S9>/Product' */
  real32_T DTC;                        /* '<S196>/DTC' */
  real32_T Product;                    /* '<S179>/Product' */
  real32_T DTC_a;                      /* '<S201>/DTC' */
  real32_T SpeedGain;                  /* '<S180>/SpeedGain' */
  real32_T Product_g;                  /* '<S183>/Product' */
  real32_T UnitDelay_i;                /* '<S183>/Unit Delay' */
  real32_T Product1;                   /* '<S183>/Product1' */
  real32_T Add1;                       /* '<S183>/Add1' */
  real32_T Switch_f;                   /* '<S185>/Switch' */
  real32_T Merge;                      /* '<S186>/Merge' */
  real32_T Numberofpolepairs;          /* '<S191>/Number of pole pairs' */
  real32_T Floor;                      /* '<S187>/Floor' */
  real32_T Add;                        /* '<S187>/Add' */
  real32_T Merge_a;                    /* '<S118>/Merge' */
  real32_T Merge1_c;                   /* '<S118>/Merge1' */
  real32_T Product_n;                  /* '<S173>/Product' */
  real32_T UnitDelay_iq;               /* '<S173>/Unit Delay' */
  real32_T Product1_n;                 /* '<S173>/Product1' */
  real32_T Add1_j;                     /* '<S173>/Add1' */
  real32_T currentSpeedData;           /* '<S126>/currentSpeedData' */
  real32_T Divide;                     /* '<S126>/Divide' */
  real32_T SpeedGain_c;                /* '<S126>/SpeedGain' */
  real32_T Merge1_k;                   /* '<S139>/Merge1' */
  real32_T Saturation_i;               /* '<S139>/Saturation' */
  real32_T Merge_aa;                   /* '<S139>/Merge' */
  real32_T countData;                  /* '<S142>/countData' */
  real32_T currentSpeedData_f;         /* '<S142>/currentSpeedData' */
  real32_T Divide_k;                   /* '<S142>/Divide' */
  real32_T countData_g;                /* '<S143>/countData' */
  real32_T previousSpeedData;          /* '<S143>/previousSpeedData' */
  real32_T Divide_ke;                  /* '<S143>/Divide' */
  real32_T currentSpeedData_k;         /* '<S143>/currentSpeedData' */
  real32_T Divide1;                    /* '<S143>/Divide1' */
  real32_T Sum_b;                      /* '<S143>/Sum' */
  real32_T Gain1;                      /* '<S143>/Gain1' */
  real32_T Sum1;                       /* '<S143>/Sum1' */
  real32_T Product_j;                  /* '<S143>/Product' */
  real32_T Merge1_p;                   /* '<S140>/Merge1' */
  real32_T Merge1_o;                   /* '<S141>/Merge1' */
  int32_T DataTypeConversion_b[3];     /* '<S114>/Data Type Conversion' */
  int32_T Add_g[3];                    /* '<S114>/Add' */
  int32_T Q17perunitconversion[3];     /* '<S114>/Q17 per unit conversion' */
  int32_T SpeedCount;                  /* '<S180>/SpeedCount' */
  uint16_T Divide_j;                   /* '<S216>/Divide' */
  uint16_T Divide1_m;                  /* '<S216>/Divide1' */
  uint16_T Divide2;                    /* '<S216>/Divide2' */
  uint16_T ForIterator;                /* '<S219>/For Iterator' */
  uint16_T IAIBMeasurement[2];         /* '<S219>/IA//IB Measurement' */
  uint16_T ICMeasurement;              /* '<S219>/IC Measurement' */
  uint16_T Memory;                     /* '<S226>/Memory' */
  uint16_T Sum_eu;                     /* '<S226>/Sum' */
  uint16_T Memory1;                    /* '<S226>/Memory1' */
  uint16_T Sum1_n;                     /* '<S226>/Sum1' */
  uint16_T Memory2;                    /* '<S226>/Memory2' */
  uint16_T Sum2;                       /* '<S226>/Sum2' */
  uint16_T SCIReceive[2];              /* '<S230>/SCI Receive' */
  uint16_T eQEP_o1;                    /* '<S205>/eQEP' */
  uint16_T eQEP_o2;                    /* '<S205>/eQEP' */
  uint16_T Output;                     /* '<S111>/Output' */
  uint16_T DataStoreRead;              /* '<S114>/Data Store Read' */
  uint16_T DataStoreRead1;             /* '<S114>/Data Store Read1' */
  uint16_T DataStoreRead2;             /* '<S114>/Data Store Read2' */
  uint16_T IAMeasurement;              /* '<S205>/IA Measurement' */
  uint16_T ICIBMeasurement[2];         /* '<S205>/IC//IB Measurement' */
  uint16_T convertTo_uint16[3];        /* '<S108>/convertTo_uint16' */
  uint16_T SCI_Tx_Data[4];             /* '<S10>/mergeDataOut' */
  uint16_T SCI_Tx_Iteration;           /* '<S10>/mergeInteration' */
  uint16_T FixPtSum1;                  /* '<S112>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S113>/FixPt Switch' */
  uint16_T Switch1[6];                 /* '<S202>/Switch1' */
  uint16_T IndexVector;                /* '<S204>/Index Vector' */
  uint16_T Add_m;                      /* '<S204>/Add' */
  uint16_T Scale_to_PWM_Counter_PRD[6];/* '<S202>/Scale_to_PWM_Counter_PRD' */
  uint16_T Merge_g;                    /* '<S179>/Merge' */
  uint16_T Sum3;                       /* '<S193>/Sum3' */
  uint16_T Sum7;                       /* '<S193>/Sum7' */
  uint16_T DataTypeConversion1_l0;     /* '<S119>/Data Type Conversion1' */
  uint16_T DataTypeConversion2;        /* '<S119>/Data Type Conversion2' */
  uint16_T DataTypeConversion_a;       /* '<S158>/Data Type Conversion' */
  uint16_T Switch_m;                   /* '<S123>/Switch' */
  uint16_T DelayOneStep;               /* '<S124>/Delay One Step' */
  uint16_T watchdogcheck;              /* '<S127>/watchdog check' */
  uint16_T Sum_bk;                     /* '<S124>/Sum' */
  uint16_T Merge_f;                    /* '<S158>/Merge' */
  uint16_T Merge_n;                    /* '<S160>/Merge' */
  uint16_T Merge1_n;                   /* '<S160>/Merge1' */
  uint16_T Merge3;                     /* '<S160>/Merge3' */
  uint16_T speedcheck;                 /* '<S127>/speed check' */
  uint16_T Data[3];                    /* '<S107>/Data' */
  uint16_T Data_f[3];                  /* '<S109>/Data' */
  uint16_T Data_fw[3];                 /* '<S110>/Data' */
  int16_T DataTypeConversion2_c[2];    /* '<S228>/Data Type Conversion2' */
  int16_T convertTo_sfix16_En12[3];    /* '<S108>/convertTo_sfix16_En12' */
  int16_T WhileIterator;               /* '<S204>/While Iterator' */
  int16_T UnitDelay_n;                 /* '<S115>/Unit Delay' */
  int16_T Merge1_f;                    /* '<S158>/Merge1' */
  int16_T Merge2;                      /* '<S160>/Merge2' */
  uint16_T Merge_e;                    /* '<S88>/Merge' */
  uint16_T Merge_j;                    /* '<S18>/Merge' */
  int16_T Switch1_b;                   /* '<S62>/Switch1' */
  int16_T Switch2;                     /* '<S62>/Switch2' */
  boolean_T NOT;                       /* '<S215>/NOT' */
  boolean_T DataTypeConversion3;       /* '<S5>/Data Type Conversion3' */
  boolean_T Merge_fv[6];               /* '<S9>/Merge' */
  boolean_T DataStoreRead1_l;          /* '<S16>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S16>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S62>/Relational Operator' */
  boolean_T fixforDTpropagationissue; /* '<S62>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                     /* '<S62>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S62>/Equal1' */
  boolean_T AND3;                      /* '<S62>/AND3' */
  boolean_T Enable;                    /* '<S202>/Enable' */
  boolean_T DataTypeConversion4;       /* '<S118>/Data Type Conversion4' */
  boolean_T FixPtRelationalOperator;   /* '<S174>/FixPt Relational Operator' */
  boolean_T Merge3_p;                  /* '<S158>/Merge3' */
  boolean_T DataTypeConversion_j;      /* '<S123>/Data Type Conversion' */
  boolean_T validityDelay;             /* '<S123>/validityDelay' */
  boolean_T DelayOneStep1;             /* '<S124>/Delay One Step1' */
  boolean_T OR;                        /* '<S124>/OR' */
  boolean_T Compare;                   /* '<S128>/Compare' */
  boolean_T DataStoreRead_n;           /* '<S121>/Data Store Read' */
  boolean_T AND;                       /* '<S121>/AND' */
  boolean_T RelationalOperator_k;      /* '<S160>/Relational Operator' */
  boolean_T LogicalOperator_l;         /* '<S123>/Logical Operator' */
  boolean_T Merge_ng[3];               /* '<S91>/Merge' */
  boolean_T Merge_c[3];                /* '<S21>/Merge' */
  rtB_To_LCD_sixstep_f28069mLaunc To_LCD;/* '<Root>/To_LCD' */
  rtB_SpeedControl_sixstep_f28069 SpeedControl;/* '<Root>/Speed Control' */
  rtB_SPIMasterTransfer_sixstep_f SPIMasterTransfer1;/* '<S217>/SPI Master Transfer' */
  rtB_SPIMasterTransfer_sixstep_f SPIMasterTransfer;/* '<S217>/SPI Master Transfer' */
  rtB_BitExtract_sixstep_f28069mL BitExtract_i;/* '<S91>/Bit Extract' */
  rtB_BitExtract_sixstep_f28069mL BitExtract;/* '<S21>/Bit Extract' */
} BlockIO_sixstep_f28069mLaunchPa;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T Integrator_DSTATE;          /* '<S71>/Integrator' */
  real32_T UnitDelay_DSTATE;           /* '<S183>/Unit Delay' */
  uint32_T Delay_DSTATE[20];           /* '<S180>/Delay' */
  uint32_T UnitDelay_DSTATE_l;         /* '<S121>/Unit Delay' */
  uint32_T Delay_DSTATE_l;             /* '<S121>/Delay' */
  uint32_T UnitDelay1_DSTATE;          /* '<S175>/Unit Delay1' */
  volatile real32_T RT1_Buffer[2];     /* '<Root>/RT1' */
  volatile real32_T RT6_Buffer[2];     /* '<Root>/RT6' */
  volatile real32_T RT2_Buffer[2];     /* '<Root>/RT2' */
  real32_T speedSCI_B;                 /* '<Root>/Data Store Memory3' */
  int32_T DigitalOutput1_FRAC_LEN;     /* '<S8>/Digital Output1' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S217>/Digital Output' */
  int32_T Add_DWORK1[3];               /* '<S114>/Add' */
  int32_T DigitalOutput_FRAC_LEN_f;    /* '<S202>/Digital Output' */
  int32_T SpeedCount_DWORK1;           /* '<S180>/SpeedCount' */
  int16_T UnitDelay_DSTATE_dg;         /* '<S115>/Unit Delay' */
  uint16_T Output_DSTATE;              /* '<S111>/Output' */
  uint16_T DelayOneStep_DSTATE;        /* '<S124>/Delay One Step' */
  volatile int16_T RT1_ActiveBufIdx;   /* '<Root>/RT1' */
  volatile int16_T RT1_semaphoreTaken; /* '<Root>/RT1' */
  volatile int16_T RT6_ActiveBufIdx;   /* '<Root>/RT6' */
  volatile int16_T RT2_ActiveBufIdx;   /* '<Root>/RT2' */
  uint16_T IaOffset;                   /* '<Root>/Data Store Memory1' */
  uint16_T IbOffset;                   /* '<Root>/Data Store Memory2' */
  uint16_T IcOffset;                   /* '<Root>/Data Store Memory9' */
  uint16_T Memory_PreviousInput;       /* '<S226>/Memory' */
  uint16_T Memory1_PreviousInput;      /* '<S226>/Memory1' */
  uint16_T Memory2_PreviousInput;      /* '<S226>/Memory2' */
  uint16_T Add_DWORK1_o;               /* '<S204>/Add' */
  uint16_T CircBufIdx;                 /* '<S180>/Delay' */
  boolean_T DelayOneStep1_DSTATE;      /* '<S124>/Delay One Step1' */
  int16_T Integrator_PrevResetState;   /* '<S71>/Integrator' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
  rtDW_To_LCD_sixstep_f28069mLaun To_LCD;/* '<Root>/To_LCD' */
  rtDW_SpeedControl_sixstep_f2806 SpeedControl;/* '<Root>/Speed Control' */
  rtDW_SPIMasterTransfer_sixstep_ SPIMasterTransfer1;/* '<S217>/SPI Master Transfer' */
  rtDW_SPIMasterTransfer_sixstep_ SPIMasterTransfer;/* '<S217>/SPI Master Transfer' */
} D_Work_sixstep_f28069mLaunchPad;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S121>/Delay' */
} PrevZCSigStates_sixstep_f28069m;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T SpeedConstData;       /* '<S126>/SpeedConstData' */
  const uint16_T dataWidth;            /* '<S10>/dataWidth' */
} ConstBlockIO_sixstep_f28069mLau;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S35>/SC1'
   *   '<S36>/SC2'
   *   '<S105>/SB1'
   *   '<S106>/SB2'
   */
  boolean_T pooled37[8];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S35>/SC2'
   *   '<S36>/SC1'
   *   '<S105>/SA1'
   *   '<S106>/SA2'
   */
  boolean_T pooled38[8];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S105>/SA2'
   *   '<S106>/SA1'
   */
  boolean_T pooled39[8];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S105>/SB2'
   *   '<S106>/SB1'
   */
  boolean_T pooled40[8];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S105>/SC1'
   *   '<S106>/SC2'
   */
  boolean_T pooled41[8];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S105>/SC2'
   *   '<S106>/SC1'
   */
  boolean_T pooled42[8];
} ConstParam_sixstep_f28069mLaunc;

/* Real-time Model Data Structure */
struct tag_RTM_sixstep_f28069mLaunchPa {
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
extern BlockIO_sixstep_f28069mLaunchPa sixstep_f28069mLaunchPad_B;

/* Block states (default storage) */
extern D_Work_sixstep_f28069mLaunchPad sixstep_f28069mLaunchPad_DWork;

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_sixstep_f28069m sixstep_f28069mL_PrevZCSigState;
extern const ConstBlockIO_sixstep_f28069mLau sixstep_f28069mLaunchPad_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstParam_sixstep_f28069mLaunc sixstep_f28069mLaunchPad_ConstP;

/* External function called from main */
extern void sixstep_f28069mLaunchPad_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void sixstep_f28069mLaunchPad_initialize(void);
extern void sixstep_f28069mLaunchPad_step0(void);
extern void sixstep_f28069mLaunchPad_step1(void);
extern void sixstep_f28069mLaunchPad_terminate(void);

/* Real-time Model object */
extern RT_MODEL_sixstep_f28069mLaunchP *const sixstep_f28069mLaunchPad_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void ADCINT1(void);
  interrupt void SCIRXINTA(void);
  void sixstep_f28069mLaunchPad_configure_interrupts (void);
  void sixstep_f28069mLaunchPad_unconfigure_interrupts (void);

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
 * '<Root>' : 'sixstep_f28069mLaunchPad'
 * '<S1>'   : 'sixstep_f28069mLaunchPad/Current Control'
 * '<S2>'   : 'sixstep_f28069mLaunchPad/HW_Interrupt'
 * '<S3>'   : 'sixstep_f28069mLaunchPad/Hardware Init'
 * '<S4>'   : 'sixstep_f28069mLaunchPad/Inverter and Motor - Plant Model'
 * '<S5>'   : 'sixstep_f28069mLaunchPad/Serial Receive'
 * '<S6>'   : 'sixstep_f28069mLaunchPad/Speed Control'
 * '<S7>'   : 'sixstep_f28069mLaunchPad/To_LCD'
 * '<S8>'   : 'sixstep_f28069mLaunchPad/Toggle LED'
 * '<S9>'   : 'sixstep_f28069mLaunchPad/Current Control/Control_System'
 * '<S10>'  : 'sixstep_f28069mLaunchPad/Current Control/Data_Logging'
 * '<S11>'  : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling'
 * '<S12>'  : 'sixstep_f28069mLaunchPad/Current Control/Inverter'
 * '<S13>'  : 'sixstep_f28069mLaunchPad/Current Control/SCI_Tx'
 * '<S14>'  : 'sixstep_f28069mLaunchPad/Current Control/Sensor Driver Blocks'
 * '<S15>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation'
 * '<S16>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc'
 * '<S17>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation'
 * '<S18>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation'
 * '<S19>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation/HALL'
 * '<S20>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation/Position'
 * '<S21>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation/Sector2vector'
 * '<S22>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation/SwitchingSequence'
 * '<S23>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation/Position/PositionSectorvariant'
 * '<S24>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120'
 * '<S25>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem'
 * '<S26>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem1'
 * '<S27>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem2'
 * '<S28>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem3'
 * '<S29>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem4'
 * '<S30>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem5'
 * '<S31>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem6'
 * '<S32>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation/Sector2vector/Bit Extract'
 * '<S33>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation/Sector2vector/Default '
 * '<S34>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation/Sector2vector/Bit Extract/Extract Bits'
 * '<S35>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation/SwitchingSequence/negative'
 * '<S36>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Hall_Commutation/Six Step Commutation/SwitchingSequence/positive'
 * '<S37>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset'
 * '<S38>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S39>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S40>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S41>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S42>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S43>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S44>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S45>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S46>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S47>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S48>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S49>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S50>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S51>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S52>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S53>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S54>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S55>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S56>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S57>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S58>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S59>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S60>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S61>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S62>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S63>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S64>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S65>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S66>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S67>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S68>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S69>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S70>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S71>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S72>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S73>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S74>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S75>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S76>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S77>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S78>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S79>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S80>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S81>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S82>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S83>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S84>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S85>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S86>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S87>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S88>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation'
 * '<S89>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation/HALL'
 * '<S90>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position'
 * '<S91>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Sector2vector'
 * '<S92>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation/SwitchingSequence'
 * '<S93>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant'
 * '<S94>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120'
 * '<S95>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem'
 * '<S96>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem1'
 * '<S97>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem2'
 * '<S98>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem3'
 * '<S99>'  : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem4'
 * '<S100>' : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem5'
 * '<S101>' : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem6'
 * '<S102>' : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Sector2vector/Bit Extract'
 * '<S103>' : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Sector2vector/Default '
 * '<S104>' : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Sector2vector/Bit Extract/Extract Bits'
 * '<S105>' : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation/SwitchingSequence/negative'
 * '<S106>' : 'sixstep_f28069mLaunchPad/Current Control/Control_System/Pos_Commutation/Six Step Commutation/SwitchingSequence/positive'
 * '<S107>' : 'sixstep_f28069mLaunchPad/Current Control/Data_Logging/Data'
 * '<S108>' : 'sixstep_f28069mLaunchPad/Current Control/Data_Logging/Data_Conditioning'
 * '<S109>' : 'sixstep_f28069mLaunchPad/Current Control/Data_Logging/End'
 * '<S110>' : 'sixstep_f28069mLaunchPad/Current Control/Data_Logging/Start'
 * '<S111>' : 'sixstep_f28069mLaunchPad/Current Control/Data_Logging/dataIndexCounter'
 * '<S112>' : 'sixstep_f28069mLaunchPad/Current Control/Data_Logging/dataIndexCounter/Increment Real World'
 * '<S113>' : 'sixstep_f28069mLaunchPad/Current Control/Data_Logging/dataIndexCounter/Wrap To Zero'
 * '<S114>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Convert ADC value to PU'
 * '<S115>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback'
 * '<S116>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback'
 * '<S117>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Convert ADC value to PU/LowerSwitchCurrents'
 * '<S118>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position'
 * '<S119>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Validity'
 * '<S120>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/IIR Filter'
 * '<S121>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Speed Counter'
 * '<S122>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Subsystem'
 * '<S123>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/ExtrapolationOrder'
 * '<S124>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Software Watchdog Timer'
 * '<S125>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant'
 * '<S126>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position'
 * '<S127>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/VaidityCheck'
 * '<S128>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Software Watchdog Timer/Compare To Zero'
 * '<S129>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction'
 * '<S130>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 1'
 * '<S131>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 2'
 * '<S132>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 3'
 * '<S133>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 4'
 * '<S134>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 5'
 * '<S135>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 6'
 * '<S136>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 7'
 * '<S137>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem'
 * '<S138>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem1'
 * '<S139>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1'
 * '<S140>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction'
 * '<S141>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction'
 * '<S142>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/first_order'
 * '<S143>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/second_order'
 * '<S144>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 1'
 * '<S145>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 2'
 * '<S146>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 3'
 * '<S147>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 4'
 * '<S148>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 5'
 * '<S149>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 6'
 * '<S150>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 7'
 * '<S151>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 1'
 * '<S152>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 2'
 * '<S153>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 3'
 * '<S154>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 4'
 * '<S155>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 5'
 * '<S156>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 6'
 * '<S157>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 7'
 * '<S158>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Validity/Subsystem'
 * '<S159>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S160>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Validity/Subsystem/Valid Halls'
 * '<S161>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S162>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S163>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S164>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S165>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S166>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S167>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S168>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S169>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S170>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S171>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/IIR Filter/IIR Filter'
 * '<S172>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/IIR Filter/IIR Filter/Low-pass'
 * '<S173>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S174>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Speed Counter/Detect Change'
 * '<S175>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/Hall Feedback/Speed Counter/Enabled Subsystem'
 * '<S176>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed'
 * '<S177>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/IIR Filter'
 * '<S178>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position'
 * '<S179>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder'
 * '<S180>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Speed Measurement'
 * '<S181>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/IIR Filter/IIR Filter'
 * '<S182>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass'
 * '<S183>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S184>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec'
 * '<S185>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point'
 * '<S186>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset'
 * '<S187>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec'
 * '<S188>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem'
 * '<S189>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem1'
 * '<S190>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem'
 * '<S191>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem/Dialog'
 * '<S192>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/DT_Handle'
 * '<S193>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset'
 * '<S194>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/PositionResetAtIndex'
 * '<S195>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem'
 * '<S196>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/DT_Handle/floating-point'
 * '<S197>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem'
 * '<S198>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem/Dialog'
 * '<S199>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem/Dialog'
 * '<S200>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Speed Measurement/DT_Handle'
 * '<S201>' : 'sixstep_f28069mLaunchPad/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Speed Measurement/DT_Handle/floating-point'
 * '<S202>' : 'sixstep_f28069mLaunchPad/Current Control/Inverter/ Code Generation'
 * '<S203>' : 'sixstep_f28069mLaunchPad/Current Control/SCI_Tx/SCI_Tx_codegen'
 * '<S204>' : 'sixstep_f28069mLaunchPad/Current Control/SCI_Tx/SCI_Tx_codegen/SCI_Tx_codegen'
 * '<S205>' : 'sixstep_f28069mLaunchPad/Current Control/Sensor Driver Blocks/Sensor Driver Blocks (codegen)'
 * '<S206>' : 'sixstep_f28069mLaunchPad/Current Control/Sensor Driver Blocks/Sensor Driver Blocks (codegen)/Read Halls'
 * '<S207>' : 'sixstep_f28069mLaunchPad/HW_Interrupt/Code generation'
 * '<S208>' : 'sixstep_f28069mLaunchPad/HW_Interrupt/Code generation/HWI_ADCINT1'
 * '<S209>' : 'sixstep_f28069mLaunchPad/HW_Interrupt/Code generation/HWI_SCIRXINTA'
 * '<S210>' : 'sixstep_f28069mLaunchPad/HW_Interrupt/Code generation/HWI_ADCINT1/ECSoC'
 * '<S211>' : 'sixstep_f28069mLaunchPad/HW_Interrupt/Code generation/HWI_ADCINT1/ECSoC/ECSimCodegen'
 * '<S212>' : 'sixstep_f28069mLaunchPad/HW_Interrupt/Code generation/HWI_SCIRXINTA/ECSoC'
 * '<S213>' : 'sixstep_f28069mLaunchPad/HW_Interrupt/Code generation/HWI_SCIRXINTA/ECSoC/ECSimCodegen'
 * '<S214>' : 'sixstep_f28069mLaunchPad/Hardware Init/Variant Subsystem'
 * '<S215>' : 'sixstep_f28069mLaunchPad/Hardware Init/Variant Subsystem/Code Generation'
 * '<S216>' : 'sixstep_f28069mLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset '
 * '<S217>' : 'sixstep_f28069mLaunchPad/Hardware Init/Variant Subsystem/Code Generation/DRV Enable'
 * '<S218>' : 'sixstep_f28069mLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Default ADC Offset'
 * '<S219>' : 'sixstep_f28069mLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem'
 * '<S220>' : 'sixstep_f28069mLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem'
 * '<S221>' : 'sixstep_f28069mLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem1'
 * '<S222>' : 'sixstep_f28069mLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem2'
 * '<S223>' : 'sixstep_f28069mLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem3'
 * '<S224>' : 'sixstep_f28069mLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem4'
 * '<S225>' : 'sixstep_f28069mLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem5'
 * '<S226>' : 'sixstep_f28069mLaunchPad/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem'
 * '<S227>' : 'sixstep_f28069mLaunchPad/Inverter and Motor - Plant Model/Codegeneration'
 * '<S228>' : 'sixstep_f28069mLaunchPad/Serial Receive/Data_Conditioning'
 * '<S229>' : 'sixstep_f28069mLaunchPad/Serial Receive/SCI_Rx'
 * '<S230>' : 'sixstep_f28069mLaunchPad/Serial Receive/SCI_Rx/Code Generation'
 * '<S231>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed'
 * '<S232>' : 'sixstep_f28069mLaunchPad/Speed Control/Speed_Ref_Selector'
 * '<S233>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S234>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S235>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S236>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S237>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S238>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S239>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S240>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S241>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S242>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S243>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S244>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S245>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S246>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S247>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S248>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S249>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S250>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S251>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S252>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S253>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S254>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S255>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S256>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S257>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S258>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S259>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S260>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S261>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S262>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S263>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S264>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S265>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S266>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S267>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S268>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S269>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S270>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S271>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S272>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S273>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S274>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S275>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S276>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S277>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S278>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S279>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S280>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S281>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S282>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S283>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S284>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S285>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S286>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S287>' : 'sixstep_f28069mLaunchPad/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S288>' : 'sixstep_f28069mLaunchPad/To_LCD/Data_Logging'
 * '<S289>' : 'sixstep_f28069mLaunchPad/To_LCD/SCI_Tx_codegen'
 * '<S290>' : 'sixstep_f28069mLaunchPad/To_LCD/Data_Logging/Data'
 * '<S291>' : 'sixstep_f28069mLaunchPad/To_LCD/Data_Logging/Data_Conditioning'
 * '<S292>' : 'sixstep_f28069mLaunchPad/To_LCD/Data_Logging/End'
 * '<S293>' : 'sixstep_f28069mLaunchPad/To_LCD/Data_Logging/Start'
 * '<S294>' : 'sixstep_f28069mLaunchPad/To_LCD/Data_Logging/dataIndexCounter'
 * '<S295>' : 'sixstep_f28069mLaunchPad/To_LCD/Data_Logging/dataIndexCounter/Increment Real World'
 * '<S296>' : 'sixstep_f28069mLaunchPad/To_LCD/Data_Logging/dataIndexCounter/Wrap To Zero'
 */
#endif                              /* RTW_HEADER_sixstep_f28069mLaunchPad_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
