/*
 * File: sixstep_f28069mLaunchPad_closeLoop.h
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

#ifndef RTW_HEADER_sixstep_f28069mLaunchPad_closeLoop_h_
#define RTW_HEADER_sixstep_f28069mLaunchPad_closeLoop_h_
#ifndef sixstep_f28069mLaunchPad_closeLoop_COMMON_INCLUDES_
#define sixstep_f28069mLaunchPad_closeLoop_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Gpio.h"
#include "DSP28xx_SciUtil.h"
#include "F2806x_Examples.h"
#include "IQmathLib.h"
#include "MW_SPI.h"
#endif                 /* sixstep_f28069mLaunchPad_closeLoop_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "sixstep_f28069mLaunchPad_closeLoop_types.h"
#include "ToLCD.h"
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

#define sixstep_f28069mLaunchPad_closeLoop_M (sixstep_f28069mLaunchPad_clo_M)

extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals for system '<S135>/SPI Master Transfer' */
typedef struct {
  uint16_T SPIMasterTransfer;          /* '<S135>/SPI Master Transfer' */
} rtB_SPIMasterTransfer_sixstep_f;

/* Block states (default storage) for system '<S135>/SPI Master Transfer' */
typedef struct {
  codertarget_tic2000_blocks_SPIM obj; /* '<S135>/SPI Master Transfer' */
  boolean_T objisempty;                /* '<S135>/SPI Master Transfer' */
} rtDW_SPIMasterTransfer_sixstep_;

/* Block signals for system '<Root>/Speed Control' */
typedef struct {
  real32_T Switch;                     /* '<S146>/Switch' */
  real32_T Product;                    /* '<S201>/Product' */
  real32_T UnitDelay;                  /* '<S201>/Unit Delay' */
  real32_T Product1;                   /* '<S201>/Product1' */
  real32_T Add1;                       /* '<S201>/Add1' */
  real32_T Sum;                        /* '<S145>/Sum' */
  real32_T PProdOut;                   /* '<S187>/PProd Out' */
  real32_T Ki2;                        /* '<S145>/Ki2' */
  real32_T Integrator;                 /* '<S182>/Integrator' */
  real32_T Sum_j;                      /* '<S191>/Sum' */
  real32_T DeadZone;                   /* '<S175>/DeadZone' */
  real32_T IProdOut;                   /* '<S179>/IProd Out' */
  real32_T Switch_a;                   /* '<S173>/Switch' */
  real32_T Saturation;                 /* '<S189>/Saturation' */
  int16_T Switch1;                     /* '<S173>/Switch1' */
  int16_T Switch2;                     /* '<S173>/Switch2' */
  boolean_T DataStoreRead2;            /* '<S145>/Data Store Read2' */
  boolean_T DataStoreRead1;            /* '<S146>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S145>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S173>/Relational Operator' */
  boolean_T fixforDTpropagationissue;/* '<S173>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                    /* '<S173>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S173>/Equal1' */
  boolean_T AND3;                      /* '<S173>/AND3' */
} rtB_SpeedControl_sixstep_f28069;

/* Block states (default storage) for system '<Root>/Speed Control' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S201>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S182>/Integrator' */
  int16_T Integrator_PrevResetState;   /* '<S182>/Integrator' */
} rtDW_SpeedControl_sixstep_f2806;

/* Block signals (default storage) */
typedef struct {
  real_T cu[3];                        /* '<S102>/Switch' */
  real_T Merge1;                       /* '<S130>/Merge1' */
  real_T Sign;                         /* '<S130>/Sign' */
  real_T ADCThreshold;                 /* '<S129>/ADCThreshold' */
  real_T Sum;                          /* '<S129>/Sum' */
  uint32_T PositionToCount;            /* '<S107>/PositionToCount' */
  uint32_T Delay;                      /* '<S107>/Delay' */
  real32_T DataStoreRead;              /* '<Root>/Data Store Read' */
  real32_T RT1;                        /* '<Root>/RT1' */
  real32_T RT6;                        /* '<Root>/RT6' */
  real32_T RT3;                        /* '<Root>/RT3' */
  real32_T Abs;                        /* '<S11>/Abs' */
  real32_T RT2;                        /* '<Root>/RT2' */
  real32_T DataTypeConversion1[3];     /* '<S100>/Data Type Conversion1' */
  real32_T DataTypeConversion[3];      /* '<S102>/Data Type Conversion' */
  real32_T Sum_o;                      /* '<S100>/Sum' */
  real32_T IDC;                        /* '<S100>/Unary Minus' */
  real32_T toPU;                       /* '<S129>/toPU' */
  real32_T Limit;                      /* '<S129>/Limit' */
  real32_T conductSpeed;               /* '<S129>/conductSpeed' */
  real32_T Idc_ref;                    /* '<S15>/Abs' */
  real32_T Sum_c;                      /* '<S20>/Sum' */
  real32_T PProdOut;                   /* '<S61>/PProd Out' */
  real32_T Kp1;                        /* '<S20>/Kp1' */
  real32_T Integrator;                 /* '<S56>/Integrator' */
  real32_T Sum_e;                      /* '<S65>/Sum' */
  real32_T Sign_b;                     /* '<S15>/Sign' */
  real32_T DataStoreRead_c;            /* '<S16>/Data Store Read' */
  real32_T DeadZone;                   /* '<S49>/DeadZone' */
  real32_T IProdOut;                   /* '<S53>/IProd Out' */
  real32_T Switch;                     /* '<S47>/Switch' */
  real32_T DTC;                        /* '<S123>/DTC' */
  real32_T Product;                    /* '<S106>/Product' */
  real32_T DTC_a;                      /* '<S128>/DTC' */
  real32_T SpeedGain;                  /* '<S107>/SpeedGain' */
  real32_T Product_g;                  /* '<S110>/Product' */
  real32_T UnitDelay;                  /* '<S110>/Unit Delay' */
  real32_T Product1;                   /* '<S110>/Product1' */
  real32_T Add1;                       /* '<S110>/Add1' */
  real32_T Switch_f;                   /* '<S112>/Switch' */
  real32_T Merge;                      /* '<S113>/Merge' */
  real32_T Numberofpolepairs;          /* '<S118>/Number of pole pairs' */
  real32_T Floor;                      /* '<S114>/Floor' */
  real32_T Add;                        /* '<S114>/Add' */
  real32_T DataTypeConversion1_o[6];   /* '<S15>/Data Type Conversion1' */
  real32_T Saturation;                 /* '<S63>/Saturation' */
  real32_T duty[6];                    /* '<S15>/Product' */
  int32_T DataTypeConversion_b[3];     /* '<S100>/Data Type Conversion' */
  int32_T Add_g[3];                    /* '<S100>/Add' */
  int32_T Q17perunitconversion[3];     /* '<S100>/Q17 per unit conversion' */
  int32_T SpeedCount;                  /* '<S107>/SpeedCount' */
  uint16_T Divide;                     /* '<S134>/Divide' */
  uint16_T Divide1;                    /* '<S134>/Divide1' */
  uint16_T Divide2;                    /* '<S134>/Divide2' */
  uint16_T ForIterator;                /* '<S137>/For Iterator' */
  uint16_T IAIBMeasurement[2];         /* '<S137>/IA//IB Measurement' */
  uint16_T ICMeasurement;              /* '<S137>/IC Measurement' */
  uint16_T Memory;                     /* '<S144>/Memory' */
  uint16_T Sum_b;                      /* '<S144>/Sum' */
  uint16_T Memory1;                    /* '<S144>/Memory1' */
  uint16_T Sum1;                       /* '<S144>/Sum1' */
  uint16_T Memory2;                    /* '<S144>/Memory2' */
  uint16_T Sum2;                       /* '<S144>/Sum2' */
  uint16_T eQEP_o1;                    /* '<S19>/eQEP' */
  uint16_T eQEP_o2;                    /* '<S19>/eQEP' */
  uint16_T DataStoreRead_i;            /* '<S100>/Data Store Read' */
  uint16_T DataStoreRead1;             /* '<S100>/Data Store Read1' */
  uint16_T DataStoreRead2;             /* '<S100>/Data Store Read2' */
  uint16_T IAMeasurement;              /* '<S19>/IA Measurement' */
  uint16_T ICIBMeasurement[2];         /* '<S19>/IC//IB Measurement' */
  uint16_T speedRef_ADC;               /* '<S19>/speedRef_ADC' */
  uint16_T Switch1[6];                 /* '<S14>/Switch1' */
  uint16_T Output;                     /* '<S92>/Output' */
  uint16_T DataTypeConversion3[3];     /* '<S94>/Data Type Conversion3' */
  uint16_T SCI_Tx_Data[4];             /* '<S16>/Merge' */
  uint16_T SCI_Tx_Iteration;           /* '<S16>/Merge1' */
  uint16_T FixPtSum1;                  /* '<S97>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S98>/FixPt Switch' */
  uint16_T Merge_g;                    /* '<S106>/Merge' */
  uint16_T Sum3;                       /* '<S120>/Sum3' */
  uint16_T Sum7;                       /* '<S120>/Sum7' */
  uint16_T IndexVector;                /* '<S99>/Index Vector' */
  uint16_T Add_gl;                     /* '<S99>/Add' */
  uint16_T Data[3];                    /* '<S93>/Data' */
  uint16_T Data_f[3];                  /* '<S95>/Data' */
  uint16_T Data_fw[3];                 /* '<S96>/Data' */
  uint16_T Scale_to_PWM_Counter_PRD[6];/* '<S14>/Scale_to_PWM_Counter_PRD' */
  int16_T DataTypeConversion_l[3];     /* '<S94>/Data Type Conversion' */
  int16_T WhileIterator;               /* '<S99>/While Iterator' */
  uint16_T Merge_e;                    /* '<S73>/Merge' */
  uint16_T ShiftArithmetic;            /* '<S89>/Shift Arithmetic' */
  uint16_T A;                          /* '<S89>/Bitwise AND1' */
  uint16_T ShiftArithmetic1;           /* '<S89>/Shift Arithmetic1' */
  uint16_T B;                          /* '<S89>/Bitwise AND2' */
  uint16_T C;                          /* '<S89>/Bitwise AND3' */
  int16_T Switch1_b;                   /* '<S47>/Switch1' */
  int16_T Switch2;                     /* '<S47>/Switch2' */
  boolean_T ONOFF_GPIO6;               /* '<S12>/ON//OFF_GPIO6' */
  boolean_T NOT;                       /* '<S133>/NOT' */
  boolean_T CWCCW_GPIO7;               /* '<S13>/CW//CCW_GPIO7' */
  boolean_T DataStoreRead_e;           /* '<S130>/Data Store Read' */
  boolean_T Enable;                    /* '<S14>/Enable' */
  boolean_T DataStoreRead1_l;          /* '<S20>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S20>/Logical Operator' */
  boolean_T Merge_n[3];                /* '<S76>/Merge' */
  boolean_T Merge_k[6];                /* '<S77>/Merge' */
  boolean_T RelationalOperator;        /* '<S47>/Relational Operator' */
  boolean_T fixforDTpropagationissue; /* '<S47>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                     /* '<S47>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S47>/Equal1' */
  boolean_T AND3;                      /* '<S47>/AND3' */
  boolean_T DataTypeConversion_j;      /* '<S89>/Data Type Conversion' */
  boolean_T DataTypeConversion1_d;     /* '<S89>/Data Type Conversion1' */
  boolean_T DataTypeConversion2;       /* '<S89>/Data Type Conversion2' */
  rtB_ToLCD_sixstep_f28069mLaunch ToLCD;/* '<Root>/ToLCD' */
  rtB_SpeedControl_sixstep_f28069 SpeedControl;/* '<Root>/Speed Control' */
  rtB_SPIMasterTransfer_sixstep_f SPIMasterTransfer1;/* '<S135>/SPI Master Transfer' */
  rtB_SPIMasterTransfer_sixstep_f SPIMasterTransfer;/* '<S135>/SPI Master Transfer' */
} BlockIO_sixstep_f28069mLaunchPa;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Sum_DWORK1;                   /* '<S129>/Sum' */
  real32_T Integrator_DSTATE;          /* '<S56>/Integrator' */
  real32_T UnitDelay_DSTATE;           /* '<S110>/Unit Delay' */
  uint32_T Delay_DSTATE[20];           /* '<S107>/Delay' */
  volatile real32_T RT1_Buffer[2];     /* '<Root>/RT1' */
  volatile real32_T RT2_Buffer[2];     /* '<Root>/RT2' */
  real32_T desiredSpeed;               /* '<Root>/g_desiredSpeed' */
  real32_T idcSCI_B;                   /* '<Root>/g_idcSCI_B' */
  real32_T speedSCI_B;                 /* '<Root>/g_speedSCI_B' */
  volatile real32_T RT3_Buffer[2];     /* '<Root>/RT3' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S7>/Digital Output' */
  int32_T DigitalOutput_FRAC_LEN_g;    /* '<S135>/Digital Output' */
  int32_T Add_DWORK1[3];               /* '<S100>/Add' */
  int32_T DigitalOutput_FRAC_LEN_l;    /* '<S14>/Digital Output' */
  int32_T SpeedCount_DWORK1;           /* '<S107>/SpeedCount' */
  uint16_T Output_DSTATE;              /* '<S92>/Output' */
  volatile int16_T RT1_ActiveBufIdx;   /* '<Root>/RT1' */
  volatile int16_T RT1_semaphoreTaken; /* '<Root>/RT1' */
  volatile int16_T RT2_ActiveBufIdx;   /* '<Root>/RT2' */
  volatile int16_T RT3_ActiveBufIdx;   /* '<Root>/RT3' */
  volatile int16_T RT3_semaphoreTaken; /* '<Root>/RT3' */
  uint16_T IaOffset;                   /* '<Root>/g_IaOffset' */
  uint16_T IbOffset;                   /* '<Root>/g_IbOffset' */
  uint16_T IcOffset;                   /* '<Root>/g_IcOffset' */
  uint16_T Memory_PreviousInput;       /* '<S144>/Memory' */
  uint16_T Memory1_PreviousInput;      /* '<S144>/Memory1' */
  uint16_T Memory2_PreviousInput;      /* '<S144>/Memory2' */
  uint16_T CircBufIdx;                 /* '<S107>/Delay' */
  uint16_T Add_DWORK1_f;               /* '<S99>/Add' */
  int16_T Integrator_PrevResetState;   /* '<S56>/Integrator' */
  boolean_T Enable;                    /* '<Root>/g_Enable' */
  boolean_T readTorqueSign;            /* '<Root>/g_TorqueSign' */
  rtDW_ToLCD_sixstep_f28069mLaunc ToLCD;/* '<Root>/ToLCD' */
  rtDW_SpeedControl_sixstep_f2806 SpeedControl;/* '<Root>/Speed Control' */
  rtDW_SPIMasterTransfer_sixstep_ SPIMasterTransfer1;/* '<S135>/SPI Master Transfer' */
  rtDW_SPIMasterTransfer_sixstep_ SPIMasterTransfer;/* '<S135>/SPI Master Transfer' */
} D_Work_sixstep_f28069mLaunchPad;

/* Invariant block signals (default storage) */
typedef struct {
  const uint16_T Width;                /* '<S16>/Width' */
} ConstBlockIO_sixstep_f28069mLau;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S90>/SA1'
   *   '<S91>/SA2'
   */
  boolean_T pooled13[8];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S90>/SA2'
   *   '<S91>/SA1'
   */
  boolean_T pooled14[8];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S90>/SB1'
   *   '<S91>/SB2'
   */
  boolean_T pooled15[8];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S90>/SB2'
   *   '<S91>/SB1'
   */
  boolean_T pooled16[8];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S90>/SC1'
   *   '<S91>/SC2'
   */
  boolean_T pooled17[8];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S90>/SC2'
   *   '<S91>/SC1'
   */
  boolean_T pooled18[8];
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
      uint16_T TID[5];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern BlockIO_sixstep_f28069mLaunchPa sixstep_f28069mLaunchPad_clos_B;

/* Block states (default storage) */
extern D_Work_sixstep_f28069mLaunchPad sixstep_f28069mLaunchPad__DWork;
extern const ConstBlockIO_sixstep_f28069mLau sixstep_f28069mLaunchPad_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstParam_sixstep_f28069mLaunc sixstep_f28069mLaunchPad_ConstP;

/* External function called from main */
extern void sixstep_f28069mLaunchPad_closeLoop_SetEventsForThisBaseStep
  (boolean_T *eventFlags);

/* Model entry point functions */
extern void sixstep_f28069mLaunchPad_closeLoop_initialize(void);
extern void sixstep_f28069mLaunchPad_closeLoop_step0(void);
extern void sixstep_f28069mLaunchPad_closeLoop_step1(void);
extern void sixstep_f28069mLaunchPad_closeLoop_step2(void);
extern void sixstep_f28069mLaunchPad_closeLoop_step3(void);
extern void sixstep_f28069mLaunchPad_closeLoop_step4(void);
extern void sixstep_f28069mLaunchPad_closeLoop_terminate(void);

/* Real-time Model object */
extern RT_MODEL_sixstep_f28069mLaunchP *const sixstep_f28069mLaunchPad_clo_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void ADCINT1(void);
  void sixstep_f28069mLaunchPad_closeLoop_configure_interrupts (void);
  void sixstep_f28069mLaunchPad_closeLoop_unconfigure_interrupts (void);

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
 * '<Root>' : 'sixstep_f28069mLaunchPad_closeLoop'
 * '<S1>'   : 'sixstep_f28069mLaunchPad_closeLoop/ADC_INT1'
 * '<S2>'   : 'sixstep_f28069mLaunchPad_closeLoop/ControlButton'
 * '<S3>'   : 'sixstep_f28069mLaunchPad_closeLoop/Current Control'
 * '<S4>'   : 'sixstep_f28069mLaunchPad_closeLoop/SensorCalib'
 * '<S5>'   : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control'
 * '<S6>'   : 'sixstep_f28069mLaunchPad_closeLoop/ToLCD'
 * '<S7>'   : 'sixstep_f28069mLaunchPad_closeLoop/ToggleLED'
 * '<S8>'   : 'sixstep_f28069mLaunchPad_closeLoop/ADC_INT1/HWI_ADCINT1'
 * '<S9>'   : 'sixstep_f28069mLaunchPad_closeLoop/ADC_INT1/HWI_ADCINT1/ECSoC'
 * '<S10>'  : 'sixstep_f28069mLaunchPad_closeLoop/ADC_INT1/HWI_ADCINT1/ECSoC/ECSimCodegen'
 * '<S11>'  : 'sixstep_f28069mLaunchPad_closeLoop/ControlButton/Direction'
 * '<S12>'  : 'sixstep_f28069mLaunchPad_closeLoop/ControlButton/ON//OFF'
 * '<S13>'  : 'sixstep_f28069mLaunchPad_closeLoop/ControlButton/Direction/readDirection'
 * '<S14>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control Signal'
 * '<S15>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System'
 * '<S16>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Logging'
 * '<S17>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Transmit'
 * '<S18>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling'
 * '<S19>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Sensor Driver Blocks'
 * '<S20>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc'
 * '<S21>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation'
 * '<S22>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset'
 * '<S23>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S24>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S25>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S26>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S27>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S28>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S29>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S30>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S31>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S32>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S33>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S34>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S35>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S36>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S37>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S38>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S39>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S40>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S41>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S42>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S43>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S44>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S45>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S46>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S47>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S48>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S49>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S50>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S51>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S52>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S53>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S54>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S55>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S56>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S57>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S58>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S59>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S60>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S61>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S62>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S63>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S64>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S65>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S66>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S67>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S68>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S69>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S70>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S71>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S72>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S73>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation'
 * '<S74>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/HALL'
 * '<S75>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position'
 * '<S76>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Sector2vector'
 * '<S77>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/SwitchingSequence'
 * '<S78>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant'
 * '<S79>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120'
 * '<S80>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem'
 * '<S81>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem1'
 * '<S82>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem2'
 * '<S83>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem3'
 * '<S84>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem4'
 * '<S85>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem5'
 * '<S86>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem6'
 * '<S87>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Sector2vector/Bit Extract'
 * '<S88>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Sector2vector/Default '
 * '<S89>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Sector2vector/Bit Extract/Extract Bits'
 * '<S90>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/SwitchingSequence/negative'
 * '<S91>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/SwitchingSequence/positive'
 * '<S92>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Logging/Counter Limited'
 * '<S93>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Logging/Data'
 * '<S94>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Logging/Data_Conditioning'
 * '<S95>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Logging/End'
 * '<S96>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Logging/Start'
 * '<S97>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Logging/Counter Limited/Increment Real World'
 * '<S98>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Logging/Counter Limited/Wrap To Zero'
 * '<S99>'  : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Transmit/CodeGeneration'
 * '<S100>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/Convert ADC value to PU'
 * '<S101>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback'
 * '<S102>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/Convert ADC value to PU/LowerSwitchCurrents'
 * '<S103>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed'
 * '<S104>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/IIR Filter'
 * '<S105>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position'
 * '<S106>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder'
 * '<S107>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Speed Measurement'
 * '<S108>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/IIR Filter/IIR Filter'
 * '<S109>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass'
 * '<S110>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S111>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec'
 * '<S112>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point'
 * '<S113>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset'
 * '<S114>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec'
 * '<S115>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem'
 * '<S116>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem1'
 * '<S117>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem'
 * '<S118>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem/Dialog'
 * '<S119>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/DT_Handle'
 * '<S120>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset'
 * '<S121>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/PositionResetAtIndex'
 * '<S122>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem'
 * '<S123>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/DT_Handle/floating-point'
 * '<S124>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem'
 * '<S125>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem/Dialog'
 * '<S126>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem/Dialog'
 * '<S127>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Speed Measurement/DT_Handle'
 * '<S128>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Speed Measurement/DT_Handle/floating-point'
 * '<S129>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Sensor Driver Blocks/Convert ADC to PU'
 * '<S130>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Sensor Driver Blocks/Convert ADC to PU/Torque sign'
 * '<S131>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Sensor Driver Blocks/Convert ADC to PU/Torque sign/Clockwise'
 * '<S132>' : 'sixstep_f28069mLaunchPad_closeLoop/Current Control/Sensor Driver Blocks/Convert ADC to PU/Torque sign/Counter_Clockwise'
 * '<S133>' : 'sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput'
 * '<S134>' : 'sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Calculate ADC Offset '
 * '<S135>' : 'sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/DRV Enable'
 * '<S136>' : 'sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Default ADC Offset'
 * '<S137>' : 'sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Calculate ADC Offset /For Iterator Subsystem'
 * '<S138>' : 'sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Calculate ADC Offset /If Action Subsystem'
 * '<S139>' : 'sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Calculate ADC Offset /If Action Subsystem1'
 * '<S140>' : 'sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Calculate ADC Offset /If Action Subsystem2'
 * '<S141>' : 'sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Calculate ADC Offset /If Action Subsystem3'
 * '<S142>' : 'sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Calculate ADC Offset /If Action Subsystem4'
 * '<S143>' : 'sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Calculate ADC Offset /If Action Subsystem5'
 * '<S144>' : 'sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem'
 * '<S145>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed'
 * '<S146>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/Speed_Ref_Selector'
 * '<S147>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S148>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S149>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S150>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S151>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S152>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S153>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S154>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S155>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S156>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S157>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S158>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S159>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S160>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S161>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S162>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S163>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S164>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S165>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S166>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S167>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S168>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S169>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S170>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S171>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S172>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S173>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S174>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S175>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S176>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S177>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S178>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S179>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S180>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S181>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S182>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S183>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S184>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S185>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S186>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S187>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S188>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S189>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S190>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S191>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S192>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S193>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S194>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S195>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S196>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S197>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S198>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S199>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S200>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S201>' : 'sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S202>' : 'sixstep_f28069mLaunchPad_closeLoop/ToLCD/SCITransmit'
 * '<S203>' : 'sixstep_f28069mLaunchPad_closeLoop/ToLCD/dataLogging'
 * '<S204>' : 'sixstep_f28069mLaunchPad_closeLoop/ToLCD/dataLogging/Data'
 * '<S205>' : 'sixstep_f28069mLaunchPad_closeLoop/ToLCD/dataLogging/Data_Conditioning'
 * '<S206>' : 'sixstep_f28069mLaunchPad_closeLoop/ToLCD/dataLogging/End'
 * '<S207>' : 'sixstep_f28069mLaunchPad_closeLoop/ToLCD/dataLogging/Start'
 * '<S208>' : 'sixstep_f28069mLaunchPad_closeLoop/ToLCD/dataLogging/dataIndexCounter'
 * '<S209>' : 'sixstep_f28069mLaunchPad_closeLoop/ToLCD/dataLogging/dataIndexCounter/Increment Real World'
 * '<S210>' : 'sixstep_f28069mLaunchPad_closeLoop/ToLCD/dataLogging/dataIndexCounter/Wrap To Zero'
 */
#endif                    /* RTW_HEADER_sixstep_f28069mLaunchPad_closeLoop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
