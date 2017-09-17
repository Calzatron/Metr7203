/*
 * plant_block_swing_catch_data.c
 *
 * Code generation for model "plant_block_swing_catch".
 *
 * Model version              : 1.183
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Fri Sep 15 17:30:00 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "plant_block_swing_catch.h"
#include "plant_block_swing_catch_private.h"

/* Block parameters (auto storage) */
P_plant_block_swing_catch_T plant_block_swing_catch_P = {
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
  -40.0,                               /* Computed Parameter: TransferFcn5_A
                                        * Referenced by: '<Root>/Transfer Fcn5'
                                        */
  40.0,                                /* Computed Parameter: TransferFcn5_C
                                        * Referenced by: '<Root>/Transfer Fcn5'
                                        */
  -15.0,                               /* Expression: -15
                                        * Referenced by: '<S7>/Gain2'
                                        */
  -20.0,                               /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */
  20.0,                                /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */
  -5.5,                                /* Expression: -5.5
                                        * Referenced by: '<S7>/Gain3'
                                        */
  -40.0,                               /* Computed Parameter: TransferFcn3_A
                                        * Referenced by: '<Root>/Transfer Fcn3'
                                        */
  40.0,                                /* Computed Parameter: TransferFcn3_C
                                        * Referenced by: '<Root>/Transfer Fcn3'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<Root>/Constant1'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<Root>/Constant2'
                                        */
  -48.0,                               /* Expression: -48
                                        * Referenced by: '<S7>/Gain'
                                        */
  -40.0,                               /* Computed Parameter: TransferFcn4_A
                                        * Referenced by: '<Root>/Transfer Fcn4'
                                        */
  40.0,                                /* Computed Parameter: TransferFcn4_C
                                        * Referenced by: '<Root>/Transfer Fcn4'
                                        */
  -7.0,                                /* Expression: -7
                                        * Referenced by: '<S7>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Gain4'
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
  13.0,                                /* Expression: 13
                                        * Referenced by: '<Root>/Gain6'
                                        */
  400.0,                               /* Expression: 400
                                        * Referenced by: '<Root>/Constant'
                                        */
  60.0,                                /* Expression: P
                                        * Referenced by: '<S3>/Proportional Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S3>/Integrator'
                                        */
  2.6,                                 /* Expression: D
                                        * Referenced by: '<S3>/Derivative Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S3>/Filter'
                                        */
  100.0,                               /* Expression: N
                                        * Referenced by: '<S3>/Filter Coefficient'
                                        */
  32000.0,                             /* Expression: 32000
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -32000.0,                            /* Expression: -32000
                                        * Referenced by: '<Root>/Saturation'
                                        */
  120.0,                               /* Expression: P
                                        * Referenced by: '<S4>/Proportional Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S4>/Integrator'
                                        */
  0.0,                                 /* Expression: D
                                        * Referenced by: '<S4>/Derivative Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S4>/Filter'
                                        */
  100.0,                               /* Expression: N
                                        * Referenced by: '<S4>/Filter Coefficient'
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
  -435.0,                              /* Expression: -435
                                        * Referenced by: '<S6>/Gain4'
                                        */
  7300.0,                              /* Expression: 7300
                                        * Referenced by: '<S6>/Constant1'
                                        */
  7300.0,                              /* Expression: 7300
                                        * Referenced by: '<S6>/Saturation'
                                        */
  1400.0,                              /* Expression: 1400
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
  22000.0,                             /* Expression: 22000
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  -22000.0,                            /* Expression: -22000
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  1.227415553809898E-5,                /* Expression: 1/(2546*32)
                                        * Referenced by: '<Root>/Gain3'
                                        */
  9.5492965855137211,                  /* Expression: 30/pi
                                        * Referenced by: '<Root>/Gain5'
                                        */
  10.0,                                /* Expression: I
                                        * Referenced by: '<S3>/Integral Gain'
                                        */
  5.0                                  /* Expression: I
                                        * Referenced by: '<S4>/Integral Gain'
                                        */
};
