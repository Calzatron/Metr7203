/*
 * plant_block_data.c
 *
 * Code generation for model "plant_block".
 *
 * Model version              : 1.147
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Wed Aug 30 09:38:31 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "plant_block.h"
#include "plant_block_private.h"

/* Block parameters (auto storage) */
P_plant_block_T plant_block_P = {
  -5.0,                                /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  5.0,                                 /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */

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
  2.945334590009425E-5,                /* Expression: 1/(1061*32)
                                        * Referenced by: '<Root>/Gain4'
                                        */
  400.0,                               /* Expression: 400
                                        * Referenced by: '<Root>/Constant'
                                        */
  60.0,                                /* Expression: P
                                        * Referenced by: '<S2>/Proportional Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S2>/Integrator'
                                        */
  2.6,                                 /* Expression: D
                                        * Referenced by: '<S2>/Derivative Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S2>/Filter'
                                        */
  100.0,                               /* Expression: N
                                        * Referenced by: '<S2>/Filter Coefficient'
                                        */
  32000.0,                             /* Expression: 32000
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -32000.0,                            /* Expression: -32000
                                        * Referenced by: '<Root>/Saturation'
                                        */
  1.1982361963190184E-5,               /* Expression: 1/(2608*32)
                                        * Referenced by: '<Root>/Gain1'
                                        */
  30.0,                                /* Expression: 30
                                        * Referenced by: '<Root>/Step on'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step on'
                                        */
  15000.0,                             /* Expression: 15000
                                        * Referenced by: '<Root>/Step on'
                                        */
  30.25,                               /* Expression: 30.25
                                        * Referenced by: '<Root>/Step off'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step off'
                                        */
  -15000.0,                            /* Expression: -15000
                                        * Referenced by: '<Root>/Step off'
                                        */
  30.32,                               /* Expression: 30.32
                                        * Referenced by: '<Root>/Step on1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step on1'
                                        */
  -30000.0,                            /* Expression: -30000
                                        * Referenced by: '<Root>/Step on1'
                                        */
  30.57,                               /* Expression: 30.57
                                        * Referenced by: '<Root>/Step off1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step off1'
                                        */
  30000.0,                             /* Expression: 30000
                                        * Referenced by: '<Root>/Step off1'
                                        */
  9.5492965855137211,                  /* Expression: 30/pi
                                        * Referenced by: '<Root>/Gain5'
                                        */
  10.0                                 /* Expression: I
                                        * Referenced by: '<S2>/Integral Gain'
                                        */
};
