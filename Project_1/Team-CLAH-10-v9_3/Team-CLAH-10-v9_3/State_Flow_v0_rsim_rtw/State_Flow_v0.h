/*
 * State_Flow_v0.h
 *
 * Code generation for model "State_Flow_v0".
 *
 * Model version              : 1.35
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Mon Sep 11 08:59:18 2017
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Specified
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_State_Flow_v0_h_
#define RTW_HEADER_State_Flow_v0_h_
#ifndef State_Flow_v0_COMMON_INCLUDES_
# define State_Flow_v0_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rsim.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#endif                                 /* State_Flow_v0_COMMON_INCLUDES_ */

#include "State_Flow_v0_types.h"
#define MODEL_NAME                     State_Flow_v0
#define NSAMPLE_TIMES                  (3)                       /* Number of sample times */
#define NINPUTS                        (0)                       /* Number of model inputs */
#define NOUTPUTS                       (0)                       /* Number of model outputs */
#define NBLOCKIO                       (18)                      /* Number of data output port signals */
#define NUM_ZC_EVENTS                  (0)                       /* Number of zero-crossing events */
#ifndef NCSTATES
# define NCSTATES                      (3)                       /* Number of continuous states */
#elif NCSTATES != 3
# error Invalid specification of NCSTATES defined in compiler command
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        (NULL)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T SFunction[5];                 /* '<S1>/S-Function' */
  real_T Gain4;                        /* '<Root>/Gain4' */
  real_T FilterCoefficient;            /* '<S4>/Filter Coefficient' */
  real_T Sum;                          /* '<S4>/Sum' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T theta;                        /* '<Root>/Gain1' */
  real_T Stepon;                       /* '<Root>/Step on' */
  real_T Stepoff;                      /* '<Root>/Step off' */
  real_T FixPtUnitDelay1;              /* '<S9>/FixPt Unit Delay1' */
  real_T Reset;                        /* '<S9>/Reset' */
  real_T Sum2;                         /* '<S6>/Sum2' */
  real_T TrigonometricFunction;        /* '<S6>/Trigonometric Function' */
  real_T Gain3;                        /* '<S6>/Gain3' */
  real_T TrigonometricFunction1;       /* '<S6>/Trigonometric Function1' */
  real_T gimbalmotorvoltage;           /* '<Root>/Add' */
  real_T Gain5;                        /* '<Root>/Gain5' */
  real_T IntegralGain;                 /* '<S4>/Integral Gain' */
  real_T Saturation1;                  /* '<Root>/Saturation1' */
} B;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T FixPtUnitDelay1_DSTATE;       /* '<S9>/FixPt Unit Delay1' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK;                  /* '<Root>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative1_RWORK;                 /* '<Root>/Derivative1' */

  struct {
    void *LoggedData;
  } Encoder1_PWORK;                    /* '<Root>/Encoder 1' */

  struct {
    void *LoggedData;
  } FlywheelRotSpeedrads_PWORK;        /* '<Root>/Flywheel Rot Speed, rad//s' */

  struct {
    void *LoggedData;
  } FlywheelRotSpeedrads1_PWORK;       /* '<Root>/Flywheel Rot Speed, rad//s1' */

  struct {
    void *LoggedData;
  } FlywheelRotSpeedrads2_PWORK;       /* '<Root>/Flywheel Rot Speed, rad//s2' */

  struct {
    void *LoggedData;
  } GimbalEncoder1_PWORK;              /* '<Root>/Gimbal Encoder1' */

  struct {
    void *LoggedData;
  } PIDoutputvoltage_PWORK;            /* '<Root>/PID output voltage' */

  struct {
    void *LoggedData;
  } PendulumEncoder_PWORK;             /* '<Root>/Pendulum Encoder' */

  struct {
    void *LoggedData;
  } RPM_PWORK;                         /* '<Root>/RPM' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S6>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S6>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S6>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S6>/Scope3' */

  int_T Saturation_MODE;               /* '<Root>/Saturation' */
  int_T Stepon_MODE;                   /* '<Root>/Step on' */
  int_T Stepoff_MODE;                  /* '<Root>/Step off' */
  int_T Saturation_MODE_l;             /* '<S6>/Saturation' */
  int_T Saturation1_MODE;              /* '<Root>/Saturation1' */
} DW;

/* Continuous states (auto storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
  real_T Filter_CSTATE;                /* '<S4>/Filter' */
} X;

/* State derivatives (auto storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
  real_T Filter_CSTATE;                /* '<S4>/Filter' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn1_CSTATE;       /* '<Root>/Transfer Fcn1' */
  boolean_T Integrator_CSTATE;         /* '<S4>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S4>/Filter' */
} XDis;

/* Continuous State Absolute Tolerance  */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T Integrator_CSTATE;            /* '<S4>/Integrator' */
  real_T Filter_CSTATE;                /* '<S4>/Filter' */
} CStateAbsTol;

/* Zero-crossing (trigger) state */
typedef struct {
  real_T Saturation_UprLim_ZC;         /* '<Root>/Saturation' */
  real_T Saturation_LwrLim_ZC;         /* '<Root>/Saturation' */
  real_T Stepon_StepTime_ZC;           /* '<Root>/Step on' */
  real_T Stepoff_StepTime_ZC;          /* '<Root>/Step off' */
  real_T Saturation_UprLim_ZC_n;       /* '<S6>/Saturation' */
  real_T Saturation_LwrLim_ZC_m;       /* '<S6>/Saturation' */
  real_T Saturation1_UprLim_ZC;        /* '<Root>/Saturation1' */
  real_T Saturation1_LwrLim_ZC;        /* '<Root>/Saturation1' */
} ZCV;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Saturation_UprLim_ZCE;    /* '<Root>/Saturation' */
  ZCSigState Saturation_LwrLim_ZCE;    /* '<Root>/Saturation' */
  ZCSigState Stepon_StepTime_ZCE;      /* '<Root>/Step on' */
  ZCSigState Stepoff_StepTime_ZCE;     /* '<Root>/Step off' */
  ZCSigState Saturation_UprLim_ZCE_n;  /* '<S6>/Saturation' */
  ZCSigState Saturation_LwrLim_ZCE_g;  /* '<S6>/Saturation' */
  ZCSigState Saturation1_UprLim_ZCE;   /* '<Root>/Saturation1' */
  ZCSigState Saturation1_LwrLim_ZCE;   /* '<Root>/Saturation1' */
} PrevZCX;

/* Parameters (auto storage) */
struct P_ {
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T SFunction_P1[6];              /* Computed Parameter: SFunction_P1
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T SFunction_P2;                 /* Expression: STime
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T SFunction_P3_Size[2];         /* Computed Parameter: SFunction_P3_Size
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T SFunction_P3;                 /* Expression: TimeOutPer
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T SFunction_P4_Size[2];         /* Computed Parameter: SFunction_P4_Size
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T SFunction_P4;                 /* Expression: HWAccess
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1/(1061*32)
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/(3882*32)
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T Constant1_Value;              /* Expression: 400
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T ProportionalGain_Gain;        /* Expression: P
                                        * Referenced by: '<S4>/Proportional Gain'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T DerivativeGain_Gain;          /* Expression: D
                                        * Referenced by: '<S4>/Derivative Gain'
                                        */
  real_T Filter_IC;                    /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S4>/Filter'
                                        */
  real_T FilterCoefficient_Gain;       /* Expression: N
                                        * Referenced by: '<S4>/Filter Coefficient'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 32000
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -32000
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/(2608*32)
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Stepon_Time;                  /* Expression: 30
                                        * Referenced by: '<Root>/Step on'
                                        */
  real_T Stepon_Y0;                    /* Expression: 0
                                        * Referenced by: '<Root>/Step on'
                                        */
  real_T Stepon_YFinal;                /* Expression: 14000
                                        * Referenced by: '<Root>/Step on'
                                        */
  real_T Stepoff_Time;                 /* Expression: 30.15
                                        * Referenced by: '<Root>/Step off'
                                        */
  real_T Stepoff_Y0;                   /* Expression: 0
                                        * Referenced by: '<Root>/Step off'
                                        */
  real_T Stepoff_YFinal;               /* Expression: -14000
                                        * Referenced by: '<Root>/Step off'
                                        */
  real_T InitialCondition_Value;       /* Expression: vinit
                                        * Referenced by: '<S9>/Initial Condition'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T FixPtUnitDelay1_InitialConditio;/* Expression: vinit
                                          * Referenced by: '<S9>/FixPt Unit Delay1'
                                          */
  real_T Gain4_Gain_j;                 /* Expression: -384.615
                                        * Referenced by: '<S6>/Gain4'
                                        */
  real_T Constant1_Value_g;            /* Expression: 7769.23
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: 7000
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: 2000
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Gain5_Gain;                   /* Expression: -1
                                        * Referenced by: '<S6>/Gain5'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 0.5*0.0131
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0.1580*9.81*0.2698
                                        * Referenced by: '<S6>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1
                                        * Referenced by: '<S6>/Gain3'
                                        */
  real_T Gain1_Gain_a;                 /* Expression: 0.1530/(41.8879*0.0273*0.37)
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Gain5_Gain_b;                 /* Expression: 30/pi
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T IntegralGain_Gain;            /* Expression: I
                                        * Referenced by: '<S4>/Integral Gain'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 22000
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -22000
                                        * Referenced by: '<Root>/Saturation1'
                                        */
};

extern P rtP;                          /* parameters */

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern B rtB;                          /* block i/o */
extern X rtX;                          /* states (continuous) */
extern DW rtDW;                        /* states (dwork) */
extern PrevZCX rtPrevZCX;              /* prev zc states*/

/* Simulation Structure */
extern SimStruct *const rtS;

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
 * '<Root>' : 'State_Flow_v0'
 * '<S1>'   : 'State_Flow_v0/ECPDSP Driver'
 * '<S2>'   : 'State_Flow_v0/Enabled Subsystem'
 * '<S3>'   : 'State_Flow_v0/Enabled Subsystem2'
 * '<S4>'   : 'State_Flow_v0/PID Controller'
 * '<S5>'   : 'State_Flow_v0/State Switch v1'
 * '<S6>'   : 'State_Flow_v0/Subsystem'
 * '<S7>'   : 'State_Flow_v0/Subsystem1'
 * '<S8>'   : 'State_Flow_v0/Subsystem/MinMax Running Resettable'
 * '<S9>'   : 'State_Flow_v0/Subsystem/MinMax Running Resettable/Unit Delay With Preview Resettable'
 */

/* user code (bottom of header file) */
extern const int_T gblNumToFiles;
extern const int_T gblNumFrFiles;
extern const int_T gblNumFrWksBlocks;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
extern const int_T gblNumRootInportBlks;
extern const int_T gblNumModelInputs;
extern const int_T gblInportDataTypeIdx[];
extern const int_T gblInportDims[];
extern const int_T gblInportComplex[];
extern const int_T gblInportInterpoFlag[];
extern const int_T gblInportContinuous[];

#endif                                 /* RTW_HEADER_State_Flow_v0_h_ */
