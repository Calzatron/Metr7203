/*
 * Helicopter_Simulink_Model.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Helicopter_Simulink_Model".
 *
 * Model version              : 1.14
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed Oct 25 14:31:05 2017
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Helicopter_Simulink_Model_h_
#define RTW_HEADER_Helicopter_Simulink_Model_h_
#include <stddef.h>
#include <math.h>
#include <string.h>
#ifndef Helicopter_Simulink_Model_COMMON_INCLUDES_
# define Helicopter_Simulink_Model_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rsim.h"
#include "rt_logging.h"
#include "dt_info.h"
#endif                                 /* Helicopter_Simulink_Model_COMMON_INCLUDES_ */

#include "Helicopter_Simulink_Model_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#define MODEL_NAME                     Helicopter_Simulink_Model
#define NSAMPLE_TIMES                  (3)                       /* Number of sample times */
#define NINPUTS                        (0)                       /* Number of model inputs */
#define NOUTPUTS                       (0)                       /* Number of model outputs */
#define NBLOCKIO                       (8)                       /* Number of data output port signals */
#define NUM_ZC_EVENTS                  (0)                       /* Number of zero-crossing events */
#ifndef NCSTATES
# define NCSTATES                      (14)                      /* Number of continuous states */
#elif NCSTATES != 14
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
  real_T y[3];                         /* '<Root>/State-Space' */
  real_T Sum3[3];                      /* '<Root>/Sum3' */
  real_T Add2;                         /* '<Root>/Add2' */
  real_T Add1;                         /* '<Root>/Add1' */
  real_T Kr[2];                        /* '<Root>/Kr' */
  real_T InputVoltage[2];              /* '<Root>/Sum' */
  real_T x_dot[6];                     /* '<Root>/Add' */
  real_T Sum2[2];                      /* '<Root>/Sum2' */
} B;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SensorNoise_NextOutput;       /* '<Root>/Sensor Noise' */
  real_T TimeStampA;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeA[3];              /* '<Root>/Derivative' */
  real_T TimeStampB;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeB[3];              /* '<Root>/Derivative' */
  struct {
    void *LoggedData;
  } EncoderReading_PWORK;              /* '<Root>/Encoder Reading' */

  struct {
    void *LoggedData;
  } Error_PWORK;                       /* '<Root>/Error' */

  struct {
    void *LoggedData;
  } Input_PWORK;                       /* '<Root>/Input' */

  struct {
    void *LoggedData;
  } InputOutput_PWORK;                 /* '<Root>/Input Output' */

  struct {
    void *LoggedData;
  } IntegralScope_PWORK;               /* '<Root>/Integral Scope' */

  struct {
    void *LoggedData;
  } ObserverPositions_PWORK;           /* '<Root>/Observer Positions' */

  struct {
    void *LoggedData;
  } ObserverStates_PWORK;              /* '<Root>/Observer States' */

  struct {
    void *LoggedData;
  } PlantInput_PWORK;                  /* '<Root>/Plant Input' */

  struct {
    void *LoggedData;
  } PlantPositions_PWORK;              /* '<Root>/Plant Positions' */

  struct {
    void *LoggedData;
  } PlantStates_PWORK;                 /* '<Root>/Plant States' */

  struct {
    void *LoggedData;
  } Reference_PWORK;                   /* '<Root>/Reference' */

  uint32_T RandSeed;                   /* '<Root>/Sensor Noise' */
  int_T Step_MODE;                     /* '<Root>/Step' */
  int_T Step1_MODE;                    /* '<Root>/Step1' */
  int_T Step2_MODE;                    /* '<Root>/Step2' */
  int_T Step3_MODE;                    /* '<Root>/Step3' */
  int_T Integrator1_MODE[2];           /* '<Root>/Integrator1' */
} DW;

/* Continuous states (auto storage) */
typedef struct {
  real_T StateSpace_CSTATE[6];         /* '<Root>/State-Space' */
  real_T Integrator_CSTATE[6];         /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE[2];        /* '<Root>/Integrator1' */
} X;

/* State derivatives (auto storage) */
typedef struct {
  real_T StateSpace_CSTATE[6];         /* '<Root>/State-Space' */
  real_T Integrator_CSTATE[6];         /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE[2];        /* '<Root>/Integrator1' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T StateSpace_CSTATE[6];      /* '<Root>/State-Space' */
  boolean_T Integrator_CSTATE[6];      /* '<Root>/Integrator' */
  boolean_T Integrator1_CSTATE[2];     /* '<Root>/Integrator1' */
} XDis;

/* Continuous State Absolute Tolerance  */
typedef struct {
  real_T StateSpace_CSTATE[6];         /* '<Root>/State-Space' */
  real_T Integrator_CSTATE[6];         /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE[2];        /* '<Root>/Integrator1' */
} CStateAbsTol;

/* Zero-crossing (trigger) state */
typedef struct {
  real_T Step_StepTime_ZC;             /* '<Root>/Step' */
  real_T Step1_StepTime_ZC;            /* '<Root>/Step1' */
  real_T Step2_StepTime_ZC;            /* '<Root>/Step2' */
  real_T Step3_StepTime_ZC;            /* '<Root>/Step3' */
  real_T Integrator1_IntgUpLimit_ZC[2];/* '<Root>/Integrator1' */
  real_T Integrator1_IntgLoLimit_ZC[2];/* '<Root>/Integrator1' */
  real_T Integrator1_LeaveSaturate_ZC[2];/* '<Root>/Integrator1' */
} ZCV;

/* Parameters (auto storage) */
struct P_ {
  real_T A[36];                        /* Variable: A
                                        * Referenced by:
                                        *   '<Root>/A'
                                        *   '<Root>/State-Space'
                                        */
  real_T B[12];                        /* Variable: B
                                        * Referenced by:
                                        *   '<Root>/B'
                                        *   '<Root>/State-Space'
                                        */
  real_T C[18];                        /* Variable: C
                                        * Referenced by:
                                        *   '<Root>/C'
                                        *   '<Root>/State-Space'
                                        */
  real_T C_0[12];                      /* Variable: C_0
                                        * Referenced by: '<Root>/C_0'
                                        */
  real_T K_i[4];                       /* Variable: K_i
                                        * Referenced by: '<Root>/Ki'
                                        */
  real_T K_r[4];                       /* Variable: K_r
                                        * Referenced by: '<Root>/Kr'
                                        */
  real_T K_sf[12];                     /* Variable: K_sf
                                        * Referenced by: '<Root>/State-feedback'
                                        */
  real_T L[18];                        /* Variable: L
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T SensorNoise_Minimum;          /* Expression: -0.0002
                                        * Referenced by: '<Root>/Sensor Noise'
                                        */
  real_T SensorNoise_Maximum;          /* Expression: 0.0002
                                        * Referenced by: '<Root>/Sensor Noise'
                                        */
  real_T SensorNoise_Seed;             /* Expression: 0
                                        * Referenced by: '<Root>/Sensor Noise'
                                        */
  real_T StateSpace_X0;                /* Expression: 0
                                        * Referenced by: '<Root>/State-Space'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Step_Time;                    /* Expression: 10
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0.3
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step1_Time;                   /* Expression: 30
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: -0.3
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step2_Time;                   /* Expression: 10
                                        * Referenced by: '<Root>/Step2'
                                        */
  real_T Step2_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step2'
                                        */
  real_T Step2_YFinal;                 /* Expression: 0.8
                                        * Referenced by: '<Root>/Step2'
                                        */
  real_T Step3_Time;                   /* Expression: 30
                                        * Referenced by: '<Root>/Step3'
                                        */
  real_T Step3_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step3'
                                        */
  real_T Step3_YFinal;                 /* Expression: -0.8
                                        * Referenced by: '<Root>/Step3'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Integrator1_UpperSat;         /* Expression: 0.7
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Integrator1_LowerSat;         /* Expression: -0.7
                                        * Referenced by: '<Root>/Integrator1'
                                        */
};

extern P rtP;                          /* parameters */

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern B rtB;                          /* block i/o */
extern X rtX;                          /* states (continuous) */
extern DW rtDW;                        /* states (dwork) */

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
 * '<Root>' : 'Helicopter_Simulink_Model'
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

#endif                                 /* RTW_HEADER_Helicopter_Simulink_Model_h_ */
