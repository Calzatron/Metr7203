/*
 * plant_block_swing_catch_data.c
 *
 * Code generation for model "plant_block_swing_catch".
 *
 * Model version              : 1.218
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Mon Sep 18 16:54:28 2017
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
                                        * Referenced by: '<S5>/Constant4'
                                        */
  -40.0,                               /* Computed Parameter: LowPassFilterFlyWheel4_A
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel4'
                                        */
  40.0,                                /* Computed Parameter: LowPassFilterFlyWheel4_C
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel4'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<Root>/Constant1'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<Root>/Constant2'
                                        */
  -40.0,                               /* Computed Parameter: LowPassFilterFlyWheel6_A
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel6'
                                        */
  40.0,                                /* Computed Parameter: LowPassFilterFlyWheel6_C
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel6'
                                        */
  -1.1972,                             /* Expression: gain
                                        * Referenced by: '<S13>/Slider Gain'
                                        */
  -40.0,                               /* Computed Parameter: LowPassFilterFlyWheel5_A
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel5'
                                        */
  40.0,                                /* Computed Parameter: LowPassFilterFlyWheel5_C
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel5'
                                        */
  -8.3202,                             /* Expression: gain
                                        * Referenced by: '<S14>/Slider Gain'
                                        */
  -45.547,                             /* Expression: gain
                                        * Referenced by: '<S15>/Slider Gain'
                                        */
  -40.0,                               /* Computed Parameter: LowPassFilterFlyWheel3_A
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel3'
                                        */
  40.0,                                /* Computed Parameter: LowPassFilterFlyWheel3_C
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel3'
                                        */
  -8.2266,                             /* Expression: gain
                                        * Referenced by: '<S16>/Slider Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S6>/Gain4'
                                        */
  -5.0,                                /* Computed Parameter: LowPassFilterFlyWheel_A
                                        * Referenced by: '<S2>/Low Pass Filter Fly Wheel'
                                        */
  5.0,                                 /* Computed Parameter: LowPassFilterFlyWheel_C
                                        * Referenced by: '<S2>/Low Pass Filter Fly Wheel'
                                        */
  400.0,                               /* Expression: 400
                                        * Referenced by: '<S2>/Desired rpm'
                                        */
  4600.0,                              /* Expression: P
                                        * Referenced by: '<S8>/Proportional Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S8>/Integrator'
                                        */
  0.0,                                 /* Expression: D
                                        * Referenced by: '<S8>/Derivative Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S8>/Filter'
                                        */
  100.0,                               /* Expression: N
                                        * Referenced by: '<S8>/Filter Coefficient'
                                        */
  32000.0,                             /* Expression: 32000
                                        * Referenced by: '<S2>/Saturation'
                                        */
  -32000.0,                            /* Expression: -32000
                                        * Referenced by: '<S2>/Saturation'
                                        */
  8.0499742400824321E-6,               /* Expression: 1/(3882*32)
                                        * Referenced by: '<Root>/Gain'
                                        */
  -45.0,                               /* Computed Parameter: LowPassFilterGimbleVelocity_A
                                        * Referenced by: '<Root>/Low Pass Filter Gimble Velocity'
                                        */
  45.0,                                /* Computed Parameter: LowPassFilterGimbleVelocity_C
                                        * Referenced by: '<Root>/Low Pass Filter Gimble Velocity'
                                        */
  -15.0,                               /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S7>/Transfer Fcn'
                                        */
  15.0,                                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S7>/Transfer Fcn'
                                        */
  0.5,                                 /* Expression: P
                                        * Referenced by: '<S18>/Proportional Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S18>/Integrator'
                                        */
  0.0,                                 /* Expression: D
                                        * Referenced by: '<S18>/Derivative Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S18>/Filter'
                                        */
  100.0,                               /* Expression: N
                                        * Referenced by: '<S18>/Filter Coefficient'
                                        */
  -10.0,                               /* Computed Parameter: LowPassFilterFlyWheel2_A
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel2'
                                        */
  10.0,                                /* Computed Parameter: LowPassFilterFlyWheel2_C
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel2'
                                        */
  0.00655,                             /* Expression: 0.5*0.0131
                                        * Referenced by: '<S7>/Gain'
                                        */
  -8.0,                                /* Computed Parameter: LowPassFilterFlyWheel1_A
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel1'
                                        */
  8.0,                                 /* Computed Parameter: LowPassFilterFlyWheel1_C
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  0.418184604,                         /* Expression: 0.1580*9.81*0.2698
                                        * Referenced by: '<S7>/Gain2'
                                        */
  0.36160836773901645,                 /* Expression: 0.1530/(41.8879*0.0273*0.37)
                                        * Referenced by: '<S7>/Table Acceleration to Gimble Velocity'
                                        */
  1626.958,                            /* Expression: gain
                                        * Referenced by: '<S11>/Slider Gain'
                                        */
  40000.0,                             /* Expression: 40000
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  -40000.0,                            /* Expression: -40000
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  12000.0,                             /* Expression: P
                                        * Referenced by: '<S10>/Proportional Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S10>/Integrator'
                                        */
  0.0,                                 /* Expression: D
                                        * Referenced by: '<S10>/Derivative Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S10>/Filter'
                                        */
  100.0,                               /* Expression: N
                                        * Referenced by: '<S10>/Filter Coefficient'
                                        */
  9500.0,                              /* Expression: 9500
                                        * Referenced by: '<S3>/Saturation2'
                                        */
  -9500.0,                             /* Expression: -9500
                                        * Referenced by: '<S3>/Saturation2'
                                        */
  2.945334590009425E-5,                /* Expression: 1/(1061*32)
                                        * Referenced by: '<S2>/encoder to radians'
                                        */
  20.0,                                /* Expression: I
                                        * Referenced by: '<S8>/Integral Gain'
                                        */
  9.5492965855137211,                  /* Expression: 30/pi
                                        * Referenced by: '<S2>/rad//sec to rpm'
                                        */
  1.227415553809898E-5,                /* Expression: 1/(2546*32)
                                        * Referenced by: '<Root>/Gain3'
                                        */
  2500.0,                              /* Expression: I
                                        * Referenced by: '<S10>/Integral Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Constant4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Desired Energy'
                                        */
  0.85,                                /* Expression: vinit
                                        * Referenced by: '<S19>/Initial Condition'
                                        */
  0.85,                                /* Expression: vinit
                                        * Referenced by: '<S19>/FixPt Unit Delay1'
                                        */
  0.15                                 /* Expression: I
                                        * Referenced by: '<S18>/Integral Gain'
                                        */
};
