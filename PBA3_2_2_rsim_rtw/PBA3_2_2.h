/*
 * PBA3_2_2.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PBA3_2_2".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Sep 04 20:40:32 2017
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PBA3_2_2_h_
#define RTW_HEADER_PBA3_2_2_h_
#include <stddef.h>
#include <math.h>
#include <string.h>
#ifndef PBA3_2_2_COMMON_INCLUDES_
# define PBA3_2_2_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rsim.h"
#include "rt_logging.h"
#include "dt_info.h"
#endif                                 /* PBA3_2_2_COMMON_INCLUDES_ */

#include "PBA3_2_2_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME                     PBA3_2_2
#define NSAMPLE_TIMES                  (2)                       /* Number of sample times */
#define NINPUTS                        (1)                       /* Number of model inputs */
#define NOUTPUTS                       (2)                       /* Number of model outputs */
#define NBLOCKIO                       (4)                       /* Number of data output port signals */
#define NUM_ZC_EVENTS                  (0)                       /* Number of zero-crossing events */
#ifndef NCSTATES
# define NCSTATES                      (4)                       /* Number of continuous states */
#elif NCSTATES != 4
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
  real_T Integrator2;                  /* '<Root>/Integrator2' */
  real_T Integrator;                   /* '<Root>/Integrator' */
  real_T Divide;                       /* '<Root>/Divide' */
  real_T Sum;                          /* '<Root>/Sum' */
} B;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } CartPosition_PWORK;                /* '<Root>/Cart Position' */

  struct {
    void *LoggedData;
  } Force1_PWORK;                      /* '<Root>/Force1' */

  struct {
    void *LoggedData;
  } PendulumAngle_PWORK;               /* '<Root>/Pendulum Angle' */
} DW;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator3_CSTATE;           /* '<Root>/Integrator3' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
} X;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator3_CSTATE;           /* '<Root>/Integrator3' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T Integrator3_CSTATE;        /* '<Root>/Integrator3' */
  boolean_T Integrator1_CSTATE;        /* '<Root>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<Root>/Integrator2' */
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
} XDis;

/* Continuous State Absolute Tolerance  */
typedef struct {
  real_T Integrator3_CSTATE;           /* '<Root>/Integrator3' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
} CStateAbsTol;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T F;                            /* '<Root>/F' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T p;                            /* '<Root>/p' */
  real_T th;                           /* '<Root>/th' */
} ExtY;

/* Parameters (auto storage) */
struct P_ {
  real_T M;                            /* Variable: M
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T c;                            /* Variable: c
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T g;                            /* Variable: g
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T l;                            /* Variable: l
                                        * Referenced by:
                                        *   '<Root>/Gain1'
                                        *   '<Root>/Gain4'
                                        *   '<Root>/Gain5'
                                        *   '<Root>/Gain7'
                                        */
  real_T m;                            /* Variable: m
                                        * Referenced by:
                                        *   '<Root>/Constant'
                                        *   '<Root>/Gain'
                                        *   '<Root>/Gain2'
                                        *   '<Root>/Gain4'
                                        *   '<Root>/Gain8'
                                        */
  real_T rho;                          /* Variable: rho
                                        * Referenced by:
                                        *   '<Root>/Gain1'
                                        *   '<Root>/Gain8'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator3'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
};

extern P rtP;                          /* parameters */

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern B rtB;                          /* block i/o */
extern X rtX;                          /* states (continuous) */
extern DW rtDW;                        /* states (dwork) */
extern ExtU rtU;                       /* external inputs */
extern ExtY rtY;                       /* external outputs */

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
 * '<Root>' : 'PBA3_2_2'
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

#endif                                 /* RTW_HEADER_PBA3_2_2_h_ */
