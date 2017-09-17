/*
 * State_Flow_v0_data.c
 *
 * Code generation for model "State_Flow_v0".
 *
 * Model version              : 1.38
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Mon Sep 11 09:03:56 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "State_Flow_v0.h"
#include "State_Flow_v0_private.h"

/* Block parameters (auto storage) */
P_State_Flow_v0_T State_Flow_v0_P = {
  /*  Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S1>/S-Function'
   */
  { 1.0, 6.0 },

  /*  Computed Parameter: SFunction_P1
   * Referenced by: '<S1>/S-Function'
   */
  { 48.0, 120.0, 67.0, 48.0, 48.0, 48.0 },

  /*  Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  0.008,                               /* Expression: STime
                                        * Referenced by: '<S1>/S-Function'
                                        */

  /*  Computed Parameter: SFunction_P3_Size
   * Referenced by: '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  500.0,                               /* Expression: TimeOutPer
                                        * Referenced by: '<S1>/S-Function'
                                        */

  /*  Computed Parameter: SFunction_P4_Size
   * Referenced by: '<S1>/S-Function'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: HWAccess
                                        * Referenced by: '<S1>/S-Function'
                                        */
  1.1982361963190184E-5,               /* Expression: 1/(2608*32)
                                        * Referenced by: '<Root>/Gain1'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<Root>/Constant4'
                                        */
  -92.7915,                            /* Expression: -92.7915
                                        * Referenced by: '<S7>/Gain2'
                                        */
  -16.9657,                            /* Expression: -16.9657
                                        * Referenced by: '<S7>/Gain3'
                                        */
  1.227415553809898E-5,                /* Expression: 1/(2546*32)
                                        * Referenced by: '<Root>/Gain3'
                                        */
  -18.7746,                            /* Expression: -18.7746
                                        * Referenced by: '<S7>/Gain'
                                        */
  -15.5039,                            /* Expression: -15.5039
                                        * Referenced by: '<S7>/Gain1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S7>/Gain4'
                                        */
  1500.0,                              /* Expression: 1500
                                        * Referenced by: '<S7>/Gain5'
                                        */
  -5.0,                                /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  5.0,                                 /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  2.945334590009425E-5,                /* Expression: 1/(1061*32)
                                        * Referenced by: '<Root>/Gain4'
                                        */
  8.0499742400824321E-6,               /* Expression: 1/(3882*32)
                                        * Referenced by: '<Root>/Gain'
                                        */
  400.0,                               /* Expression: 400
                                        * Referenced by: '<Root>/Constant1'
                                        */
  60.0,                                /* Expression: P
                                        * Referenced by: '<S4>/Proportional Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S4>/Integrator'
                                        */
  2.6,                                 /* Expression: D
                                        * Referenced by: '<S4>/Derivative Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S4>/Filter'
                                        */
  100.0,                               /* Expression: N
                                        * Referenced by: '<S4>/Filter Coefficient'
                                        */
  32000.0,                             /* Expression: 32000
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -32000.0,                            /* Expression: -32000
                                        * Referenced by: '<Root>/Saturation'
                                        */
  0.0,                                 /* Expression: vinit
                                        * Referenced by: '<S9>/Initial Condition'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Constant2'
                                        */
  0.0,                                 /* Expression: vinit
                                        * Referenced by: '<S9>/FixPt Unit Delay1'
                                        */
  -384.615,                            /* Expression: -384.615
                                        * Referenced by: '<S6>/Gain4'
                                        */
  7769.23,                             /* Expression: 7769.23
                                        * Referenced by: '<S6>/Constant1'
                                        */
  7000.0,                              /* Expression: 7000
                                        * Referenced by: '<S6>/Saturation'
                                        */
  2000.0,                              /* Expression: 2000
                                        * Referenced by: '<S6>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S6>/Gain5'
                                        */
  0.00655,                             /* Expression: 0.5*0.0131
                                        * Referenced by: '<S6>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S6>/Constant'
                                        */
  0.418184604,                         /* Expression: 0.1580*9.81*0.2698
                                        * Referenced by: '<S6>/Gain2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S6>/Gain3'
                                        */
  0.36160836773901645,                 /* Expression: 0.1530/(41.8879*0.0273*0.37)
                                        * Referenced by: '<S6>/Gain1'
                                        */
  30.0,                                /* Expression: 30
                                        * Referenced by: '<Root>/Step on'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step on'
                                        */
  14000.0,                             /* Expression: 14000
                                        * Referenced by: '<Root>/Step on'
                                        */
  30.15,                               /* Expression: 30.15
                                        * Referenced by: '<Root>/Step off'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step off'
                                        */
  -14000.0,                            /* Expression: -14000
                                        * Referenced by: '<Root>/Step off'
                                        */
  9.5492965855137211,                  /* Expression: 30/pi
                                        * Referenced by: '<Root>/Gain5'
                                        */
  10.0,                                /* Expression: I
                                        * Referenced by: '<S4>/Integral Gain'
                                        */
  22000.0,                             /* Expression: 22000
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  -22000.0,                            /* Expression: -22000
                                        * Referenced by: '<Root>/Saturation1'
                                        */

  /* Start of '<Root>/Enabled Subsystem2' */
  {
    0.0                                /* Expression: [0]
                                        * Referenced by: '<S3>/u -out'
                                        */
  }
  /* End of '<Root>/Enabled Subsystem2' */
  ,

  /* Start of '<Root>/Enabled Subsystem' */
  {
    0.0                                /* Expression: [0]
                                        * Referenced by: '<S2>/u -out'
                                        */
  }
  /* End of '<Root>/Enabled Subsystem' */
};
