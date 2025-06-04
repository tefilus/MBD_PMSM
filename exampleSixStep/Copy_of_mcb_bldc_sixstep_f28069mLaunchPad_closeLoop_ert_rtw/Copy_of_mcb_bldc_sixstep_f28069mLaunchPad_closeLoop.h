/*
 * File: Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop.h
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

#ifndef RTW_HEADER_Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_h_
#define RTW_HEADER_Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_h_
#ifndef Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_COMMON_INCLUDES_
#define Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "F2806x_Device.h"
#include "F2806x_Gpio.h"
#include "DSP28xx_SciUtil.h"
#include "F2806x_Examples.h"
#include "IQmathLib.h"
#include "MW_SPI.h"
#endif
      /* Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_types.h"
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

#define Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_M (Copy_of_mcb_bldc_sixstep_f28_M)

extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals for system '<S133>/SPI Master Transfer' */
typedef struct {
  uint16_T SPIMasterTransfer;          /* '<S133>/SPI Master Transfer' */
} rtB_SPIMasterTransfer_Copy_of_m;

/* Block states (default storage) for system '<S133>/SPI Master Transfer' */
typedef struct {
  codertarget_tic2000_blocks_SPIM obj; /* '<S133>/SPI Master Transfer' */
  boolean_T objisempty;                /* '<S133>/SPI Master Transfer' */
} rtDW_SPIMasterTransfer_Copy_of_;

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
} rtB_SpeedControl_Copy_of_mcb_bl;

/* Block states (default storage) for system '<Root>/Speed Control' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S199>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S180>/Integrator' */
  int16_T Integrator_PrevResetState;   /* '<S180>/Integrator' */
} rtDW_SpeedControl_Copy_of_mcb_b;

/* Block signals (default storage) */
typedef struct {
  real_T cu[3];                        /* '<S100>/Switch' */
  real_T Merge1;                       /* '<S128>/Merge1' */
  real_T Sign;                         /* '<S128>/Sign' */
  real_T ADCThreshold;                 /* '<S127>/ADCThreshold' */
  real_T Sum;                          /* '<S127>/Sum' */
  uint32_T PositionToCount;            /* '<S105>/PositionToCount' */
  uint32_T Delay;                      /* '<S105>/Delay' */
  real32_T DataStoreRead;              /* '<Root>/Data Store Read' */
  real32_T RT1;                        /* '<Root>/RT1' */
  real32_T RT6;                        /* '<Root>/RT6' */
  real32_T RT3;                        /* '<Root>/RT3' */
  real32_T Abs;                        /* '<S2>/Abs' */
  real32_T RT2;                        /* '<Root>/RT2' */
  real32_T DataTypeConversion1[3];     /* '<S98>/Data Type Conversion1' */
  real32_T DataTypeConversion[3];      /* '<S100>/Data Type Conversion' */
  real32_T Sum_o;                      /* '<S98>/Sum' */
  real32_T IDC;                        /* '<S98>/Unary Minus' */
  real32_T toPU;                       /* '<S127>/toPU' */
  real32_T conductSpeed;               /* '<S127>/conductSpeed' */
  real32_T Idc_ref;                    /* '<S13>/Abs' */
  real32_T Sum_c;                      /* '<S18>/Sum' */
  real32_T PProdOut;                   /* '<S59>/PProd Out' */
  real32_T Kp1;                        /* '<S18>/Kp1' */
  real32_T Integrator;                 /* '<S54>/Integrator' */
  real32_T Sum_e;                      /* '<S63>/Sum' */
  real32_T Sign_b;                     /* '<S13>/Sign' */
  real32_T DeadZone;                   /* '<S47>/DeadZone' */
  real32_T IProdOut;                   /* '<S51>/IProd Out' */
  real32_T Switch;                     /* '<S45>/Switch' */
  real32_T DTC;                        /* '<S121>/DTC' */
  real32_T Product;                    /* '<S104>/Product' */
  real32_T DTC_a;                      /* '<S126>/DTC' */
  real32_T SpeedGain;                  /* '<S105>/SpeedGain' */
  real32_T Product_g;                  /* '<S108>/Product' */
  real32_T UnitDelay;                  /* '<S108>/Unit Delay' */
  real32_T Product1;                   /* '<S108>/Product1' */
  real32_T Add1;                       /* '<S108>/Add1' */
  real32_T Switch_f;                   /* '<S110>/Switch' */
  real32_T Merge;                      /* '<S111>/Merge' */
  real32_T Numberofpolepairs;          /* '<S116>/Number of pole pairs' */
  real32_T Floor;                      /* '<S112>/Floor' */
  real32_T Add;                        /* '<S112>/Add' */
  real32_T DataTypeConversion1_o[6];   /* '<S13>/Data Type Conversion1' */
  real32_T Saturation;                 /* '<S61>/Saturation' */
  real32_T duty[6];                    /* '<S13>/Product' */
  int32_T DataTypeConversion_b[3];     /* '<S98>/Data Type Conversion' */
  int32_T Add_g[3];                    /* '<S98>/Add' */
  int32_T Q17perunitconversion[3];     /* '<S98>/Q17 per unit conversion' */
  int32_T SpeedCount;                  /* '<S105>/SpeedCount' */
  uint16_T Divide;                     /* '<S132>/Divide' */
  uint16_T Divide1;                    /* '<S132>/Divide1' */
  uint16_T Divide2;                    /* '<S132>/Divide2' */
  uint16_T ForIterator;                /* '<S135>/For Iterator' */
  uint16_T IAIBMeasurement[2];         /* '<S135>/IA//IB Measurement' */
  uint16_T ICMeasurement;              /* '<S135>/IC Measurement' */
  uint16_T Memory;                     /* '<S142>/Memory' */
  uint16_T Sum_b;                      /* '<S142>/Sum' */
  uint16_T Memory1;                    /* '<S142>/Memory1' */
  uint16_T Sum1;                       /* '<S142>/Sum1' */
  uint16_T Memory2;                    /* '<S142>/Memory2' */
  uint16_T Sum2;                       /* '<S142>/Sum2' */
  uint16_T eQEP_o1;                    /* '<S17>/eQEP' */
  uint16_T eQEP_o2;                    /* '<S17>/eQEP' */
  uint16_T DataStoreRead_i;            /* '<S98>/Data Store Read' */
  uint16_T DataStoreRead1;             /* '<S98>/Data Store Read1' */
  uint16_T DataStoreRead2;             /* '<S98>/Data Store Read2' */
  uint16_T IAMeasurement;              /* '<S17>/IA Measurement' */
  uint16_T ICIBMeasurement[2];         /* '<S17>/IC//IB Measurement' */
  uint16_T speedRef_ADC;               /* '<S17>/speedRef_ADC' */
  uint16_T Switch1[6];                 /* '<S12>/Switch1' */
  uint16_T Output;                     /* '<S90>/Output' */
  uint16_T DataTypeConversion3[2];     /* '<S92>/Data Type Conversion3' */
  uint16_T SCI_Tx_Data[3];             /* '<S14>/Merge' */
  uint16_T SCI_Tx_Iteration;           /* '<S14>/Merge1' */
  uint16_T FixPtSum1;                  /* '<S95>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S96>/FixPt Switch' */
  uint16_T Merge_g;                    /* '<S104>/Merge' */
  uint16_T Sum3;                       /* '<S118>/Sum3' */
  uint16_T Sum7;                       /* '<S118>/Sum7' */
  uint16_T IndexVector;                /* '<S97>/Index Vector' */
  uint16_T Add_gl;                     /* '<S97>/Add' */
  uint16_T Data[2];                    /* '<S91>/Data' */
  uint16_T Data_f[2];                  /* '<S93>/Data' */
  uint16_T Data_fw[2];                 /* '<S94>/Data' */
  uint16_T Scale_to_PWM_Counter_PRD[6];/* '<S12>/Scale_to_PWM_Counter_PRD' */
  int16_T DataTypeConversion_l[2];     /* '<S92>/Data Type Conversion' */
  int16_T WhileIterator;               /* '<S97>/While Iterator' */
  uint16_T Merge_e;                    /* '<S71>/Merge' */
  uint16_T ShiftArithmetic;            /* '<S87>/Shift Arithmetic' */
  uint16_T A;                          /* '<S87>/Bitwise AND1' */
  uint16_T ShiftArithmetic1;           /* '<S87>/Shift Arithmetic1' */
  uint16_T B;                          /* '<S87>/Bitwise AND2' */
  uint16_T C;                          /* '<S87>/Bitwise AND3' */
  int16_T Switch1_b;                   /* '<S45>/Switch1' */
  int16_T Switch2;                     /* '<S45>/Switch2' */
  boolean_T ONOFF_GPIO6;               /* '<S2>/ON//OFF_GPIO6' */
  boolean_T NOT;                       /* '<S131>/NOT' */
  boolean_T CWCCW_GPIO7;               /* '<S11>/CW//CCW_GPIO7' */
  boolean_T DataStoreRead_e;           /* '<S128>/Data Store Read' */
  boolean_T Enable;                    /* '<S12>/Enable' */
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
  rtB_ToLCD_Copy_of_mcb_bldc_sixs ToLCD;/* '<Root>/ToLCD' */
  rtB_SpeedControl_Copy_of_mcb_bl SpeedControl;/* '<Root>/Speed Control' */
  rtB_SPIMasterTransfer_Copy_of_m SPIMasterTransfer1;/* '<S133>/SPI Master Transfer' */
  rtB_SPIMasterTransfer_Copy_of_m SPIMasterTransfer;/* '<S133>/SPI Master Transfer' */
} BlockIO_Copy_of_mcb_bldc_sixste;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Sum_DWORK1;                   /* '<S127>/Sum' */
  real32_T Integrator_DSTATE;          /* '<S54>/Integrator' */
  real32_T UnitDelay_DSTATE;           /* '<S108>/Unit Delay' */
  uint32_T Delay_DSTATE[20];           /* '<S105>/Delay' */
  volatile real32_T RT1_Buffer[2];     /* '<Root>/RT1' */
  volatile real32_T RT2_Buffer[2];     /* '<Root>/RT2' */
  real32_T desiredSpeed;               /* '<Root>/g_desiredSpeed' */
  volatile real32_T RT3_Buffer[2];     /* '<Root>/RT3' */
  real32_T idcSCI_B;                   /* '<Root>/g_idcSCI_B' */
  real32_T speedSCI_B;                 /* '<Root>/g_speedSCI_B' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S7>/Digital Output' */
  int32_T DigitalOutput_FRAC_LEN_g;    /* '<S133>/Digital Output' */
  int32_T Add_DWORK1[3];               /* '<S98>/Add' */
  int32_T DigitalOutput_FRAC_LEN_l;    /* '<S12>/Digital Output' */
  int32_T SpeedCount_DWORK1;           /* '<S105>/SpeedCount' */
  uint16_T Output_DSTATE;              /* '<S90>/Output' */
  volatile int16_T RT1_ActiveBufIdx;   /* '<Root>/RT1' */
  volatile int16_T RT1_semaphoreTaken; /* '<Root>/RT1' */
  volatile int16_T RT2_ActiveBufIdx;   /* '<Root>/RT2' */
  volatile int16_T RT3_ActiveBufIdx;   /* '<Root>/RT3' */
  volatile int16_T RT3_semaphoreTaken; /* '<Root>/RT3' */
  uint16_T IaOffset;                   /* '<Root>/g_IaOffset' */
  uint16_T IbOffset;                   /* '<Root>/g_IbOffset' */
  uint16_T IcOffset;                   /* '<Root>/g_IcOffset' */
  uint16_T Memory_PreviousInput;       /* '<S142>/Memory' */
  uint16_T Memory1_PreviousInput;      /* '<S142>/Memory1' */
  uint16_T Memory2_PreviousInput;      /* '<S142>/Memory2' */
  uint16_T CircBufIdx;                 /* '<S105>/Delay' */
  uint16_T Add_DWORK1_f;               /* '<S97>/Add' */
  int16_T Integrator_PrevResetState;   /* '<S54>/Integrator' */
  boolean_T Enable;                    /* '<Root>/g_Enable' */
  boolean_T readTorqueSign;            /* '<Root>/g_TorqueSign' */
  rtDW_ToLCD_Copy_of_mcb_bldc_six ToLCD;/* '<Root>/ToLCD' */
  rtDW_SpeedControl_Copy_of_mcb_b SpeedControl;/* '<Root>/Speed Control' */
  rtDW_SPIMasterTransfer_Copy_of_ SPIMasterTransfer1;/* '<S133>/SPI Master Transfer' */
  rtDW_SPIMasterTransfer_Copy_of_ SPIMasterTransfer;/* '<S133>/SPI Master Transfer' */
} D_Work_Copy_of_mcb_bldc_sixstep;

/* Invariant block signals (default storage) */
typedef struct {
  const uint16_T Width;                /* '<S14>/Width' */
} ConstBlockIO_Copy_of_mcb_bldc_s;

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
} ConstParam_Copy_of_mcb_bldc_six;

/* Real-time Model Data Structure */
struct tag_RTM_Copy_of_mcb_bldc_sixste {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern BlockIO_Copy_of_mcb_bldc_sixste Copy_of_mcb_bldc_sixstep_f280_B;

/* Block states (default storage) */
extern D_Work_Copy_of_mcb_bldc_sixstep Copy_of_mcb_bldc_sixstep__DWork;
extern const ConstBlockIO_Copy_of_mcb_bldc_s Copy_of_mcb_bldc_sixstep_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstParam_Copy_of_mcb_bldc_six Copy_of_mcb_bldc_sixstep_ConstP;

/* External function called from main */
extern void
  Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_SetEventsForThisBaseStep
  (boolean_T *eventFlags);

/* Model entry point functions */
extern void Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_initialize(void);
extern void Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_step0(void);
extern void Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_step1(void);
extern void Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_step2(void);
extern void Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Copy_of_mcb_bldc_sixst *const Copy_of_mcb_bldc_sixstep_f28_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void ADCINT1(void);
  void Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_configure_interrupts
    (void);
  void
    Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_unconfigure_interrupts
    (void);

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
 * '<Root>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop'
 * '<S1>'   : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/ADC_INT1'
 * '<S2>'   : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/ControlButton'
 * '<S3>'   : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control'
 * '<S4>'   : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/SensorCalib'
 * '<S5>'   : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control'
 * '<S6>'   : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/ToLCD'
 * '<S7>'   : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/ToggleLED'
 * '<S8>'   : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/ADC_INT1/HWI_ADCINT1'
 * '<S9>'   : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/ADC_INT1/HWI_ADCINT1/ECSoC'
 * '<S10>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/ADC_INT1/HWI_ADCINT1/ECSoC/ECSimCodegen'
 * '<S11>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/ControlButton/readDirection'
 * '<S12>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control Signal'
 * '<S13>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System'
 * '<S14>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Logging'
 * '<S15>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Transmit'
 * '<S16>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling'
 * '<S17>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Sensor Driver Blocks'
 * '<S18>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc'
 * '<S19>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation'
 * '<S20>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset'
 * '<S21>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S22>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S23>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S24>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S25>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S26>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S27>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S28>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S29>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S30>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S31>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S32>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S33>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S34>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S35>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S36>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S37>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S38>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S39>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S40>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S41>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S42>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S43>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S44>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S45>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S46>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S47>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S48>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S49>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S50>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S51>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S52>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S53>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S54>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S55>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S56>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S57>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S58>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S59>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S60>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S61>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S62>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S63>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S64>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S65>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S66>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S67>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S68>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S69>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S70>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/PI_Controller_Idc/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S71>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation'
 * '<S72>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/HALL'
 * '<S73>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position'
 * '<S74>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Sector2vector'
 * '<S75>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/SwitchingSequence'
 * '<S76>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant'
 * '<S77>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120'
 * '<S78>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem'
 * '<S79>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem1'
 * '<S80>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem2'
 * '<S81>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem3'
 * '<S82>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem4'
 * '<S83>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem5'
 * '<S84>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Position/PositionSectorvariant/Sector120/Enabled Subsystem6'
 * '<S85>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Sector2vector/Bit Extract'
 * '<S86>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Sector2vector/Default '
 * '<S87>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/Sector2vector/Bit Extract/Extract Bits'
 * '<S88>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/SwitchingSequence/negative'
 * '<S89>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Control_System/Pos_Commutation/Six Step Commutation/SwitchingSequence/positive'
 * '<S90>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Logging/Counter Limited'
 * '<S91>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Logging/Data'
 * '<S92>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Logging/Data_Conditioning'
 * '<S93>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Logging/End'
 * '<S94>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Logging/Start'
 * '<S95>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Logging/Counter Limited/Increment Real World'
 * '<S96>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Logging/Counter Limited/Wrap To Zero'
 * '<S97>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Data_Transmit/CodeGeneration'
 * '<S98>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/Convert ADC value to PU'
 * '<S99>'  : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback'
 * '<S100>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/Convert ADC value to PU/LowerSwitchCurrents'
 * '<S101>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed'
 * '<S102>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/IIR Filter'
 * '<S103>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position'
 * '<S104>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder'
 * '<S105>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Speed Measurement'
 * '<S106>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/IIR Filter/IIR Filter'
 * '<S107>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass'
 * '<S108>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S109>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec'
 * '<S110>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point'
 * '<S111>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset'
 * '<S112>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec'
 * '<S113>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem'
 * '<S114>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem1'
 * '<S115>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem'
 * '<S116>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem/Dialog'
 * '<S117>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/DT_Handle'
 * '<S118>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset'
 * '<S119>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/PositionResetAtIndex'
 * '<S120>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem'
 * '<S121>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/DT_Handle/floating-point'
 * '<S122>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem'
 * '<S123>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem/Dialog'
 * '<S124>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem/Dialog'
 * '<S125>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Speed Measurement/DT_Handle'
 * '<S126>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Input Scaling/QEP Feedback/ Calculate Position and Speed/Speed Measurement/DT_Handle/floating-point'
 * '<S127>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Sensor Driver Blocks/Convert ADC to PU'
 * '<S128>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Sensor Driver Blocks/Convert ADC to PU/Torque sign'
 * '<S129>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Sensor Driver Blocks/Convert ADC to PU/Torque sign/Clockwise'
 * '<S130>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Current Control/Sensor Driver Blocks/Convert ADC to PU/Torque sign/Counter_Clockwise'
 * '<S131>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput'
 * '<S132>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Calculate ADC Offset '
 * '<S133>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/DRV Enable'
 * '<S134>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Default ADC Offset'
 * '<S135>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Calculate ADC Offset /For Iterator Subsystem'
 * '<S136>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Calculate ADC Offset /If Action Subsystem'
 * '<S137>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Calculate ADC Offset /If Action Subsystem1'
 * '<S138>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Calculate ADC Offset /If Action Subsystem2'
 * '<S139>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Calculate ADC Offset /If Action Subsystem3'
 * '<S140>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Calculate ADC Offset /If Action Subsystem4'
 * '<S141>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Calculate ADC Offset /If Action Subsystem5'
 * '<S142>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/SensorCalib/systemOutput/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem'
 * '<S143>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed'
 * '<S144>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/Speed_Ref_Selector'
 * '<S145>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S146>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S147>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S148>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S149>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S150>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S151>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S152>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S153>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S154>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S155>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S156>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S157>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S158>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S159>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S160>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S161>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S162>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S163>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S164>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S165>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S166>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S167>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S168>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S169>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S170>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S171>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S172>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S173>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S174>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S175>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S176>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S177>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S178>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S179>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S180>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S181>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S182>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S183>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S184>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S185>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S186>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S187>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S188>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S189>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S190>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S191>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S192>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S193>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S194>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S195>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S196>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S197>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S198>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S199>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S200>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/ToLCD/Data_Logging'
 * '<S201>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/ToLCD/SCI_Tx_codegen'
 * '<S202>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/ToLCD/Data_Logging/Data'
 * '<S203>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/ToLCD/Data_Logging/Data_Conditioning'
 * '<S204>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/ToLCD/Data_Logging/End'
 * '<S205>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/ToLCD/Data_Logging/Start'
 * '<S206>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/ToLCD/Data_Logging/dataIndexCounter'
 * '<S207>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/ToLCD/Data_Logging/dataIndexCounter/Increment Real World'
 * '<S208>' : 'Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop/ToLCD/Data_Logging/dataIndexCounter/Wrap To Zero'
 */
#endif   /* RTW_HEADER_Copy_of_mcb_bldc_sixstep_f28069mLaunchPad_closeLoop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
