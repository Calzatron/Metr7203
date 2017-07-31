/*
 * Simulink_Model_Q1.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Simulink_Model_Q1".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Jul 31 22:53:40 2017
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Simulink_Model_Q1_h_
#define RTW_HEADER_Simulink_Model_Q1_h_
#include <stddef.h>
#include <string.h>
#ifndef Simulink_Model_Q1_COMMON_INCLUDES_
# define Simulink_Model_Q1_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rsim.h"
#include "rt_logging.h"
#include "dt_info.h"
#endif                                 /* Simulink_Model_Q1_COMMON_INCLUDES_ */

#include "Simulink_Model_Q1_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "Get_alpha.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME                     Simulink_Model_Q1
#define NSAMPLE_TIMES                  (2)                       /* Number of sample times */
#define NINPUTS                        (0)                       /* Number of model inputs */
#define NOUTPUTS                       (0)                       /* Number of model outputs */
#define NBLOCKIO                       (6)                       /* Number of data output port signals */
#define NUM_ZC_EVENTS                  (0)                       /* Number of zero-crossing events */
#ifndef NCSTATES
# define NCSTATES                      (2)                       /* Number of continuous states */
#elif NCSTATES != 2
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
  real_T Velocity;                     /* '<Root>/Integrator' */
  real_T Alpha;                        /* '<Root>/Function Caller' */
  real_T V_Reg;                        /* '<Root>/V_Reg' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T u;                            /* '<Root>/Sum2' */
  real_T Gain;                         /* '<Root>/Gain' */
} B;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int_T V_Reg_MODE;                    /* '<Root>/V_Reg' */
  int_T Saturation_MODE;               /* '<Root>/Saturation' */
} DW;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
} X;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<Root>/Integrator1' */
} XDis;

/* Continuous State Absolute Tolerance  */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
} CStateAbsTol;

/* Zero-crossing (trigger) state */
typedef struct {
  real_T V_Reg_StepTime_ZC;            /* '<Root>/V_Reg' */
  real_T Saturation_UprLim_ZC;         /* '<Root>/Saturation' */
  real_T Saturation_LwrLim_ZC;         /* '<Root>/Saturation' */
} ZCV;

/* Parameters (auto storage) */
struct P_ {
  real_T Ki;                           /* Variable: Ki
                                        * Referenced by: '<Root>/Integral Gain'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by: '<Root>/Proportional Gain'
                                        */
  real_T Tm;                           /* Variable: Tm
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T beta;                         /* Variable: beta
                                        * Referenced by: '<Root>/Vr3'
                                        */
  real_T m;                            /* Variable: m
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T wm;                           /* Variable: wm
                                        * Referenced by: '<Root>/Vr1'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Vr2_Value;                    /* Expression: 1
                                        * Referenced by: '<Root>/Vr2'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T V_Reg_Time;                   /* Expression: 1
                                        * Referenced by: '<Root>/V_Reg'
                                        */
  real_T V_Reg_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/V_Reg'
                                        */
  real_T V_Reg_YFinal;                 /* Expression: 20
                                        * Referenced by: '<Root>/V_Reg'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
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
 * '<Root>' : 'Simulink_Model_Q1'
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

#endif                                 /* RTW_HEADER_Simulink_Model_Q1_h_ */
