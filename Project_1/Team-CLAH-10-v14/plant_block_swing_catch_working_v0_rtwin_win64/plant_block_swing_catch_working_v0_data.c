/*
 * plant_block_swing_catch_working_v0_data.c
 *
 * Code generation for model "plant_block_swing_catch_working_v0".
 *
 * Model version              : 1.234
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Thu Sep 21 06:40:40 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "plant_block_swing_catch_working_v0.h"
#include "plant_block_swing_catch_working_v0_private.h"

/* Block parameters (auto storage) */
P_plant_block_swing_catch_working_v0_T plant_block_swing_catch_working_v0_P = {
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
                                        * Referenced by: '<S6>/Constant4'
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
  -30.0,                               /* Computed Parameter: LowPassFilterGimbleVelocity_A
                                        * Referenced by: '<Root>/Low Pass Filter Gimble Velocity'
                                        */
  30.0,                                /* Computed Parameter: LowPassFilterGimbleVelocity_C
                                        * Referenced by: '<Root>/Low Pass Filter Gimble Velocity'
                                        */
  -40.0,                               /* Computed Parameter: LowPassFilterFlyWheel6_A
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel6'
                                        */
  40.0,                                /* Computed Parameter: LowPassFilterFlyWheel6_C
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel6'
                                        */
  -0.55,                               /* Expression: gain
                                        * Referenced by: '<S21>/Slider Gain'
                                        */
  -40.0,                               /* Computed Parameter: LowPassFilterFlyWheel5_A
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel5'
                                        */
  40.0,                                /* Computed Parameter: LowPassFilterFlyWheel5_C
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel5'
                                        */
  -10.4902,                            /* Expression: gain
                                        * Referenced by: '<S22>/Slider Gain'
                                        */
  -33.397,                             /* Expression: gain
                                        * Referenced by: '<S23>/Slider Gain'
                                        */
  -40.0,                               /* Computed Parameter: LowPassFilterFlyWheel3_A
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel3'
                                        */
  40.0,                                /* Computed Parameter: LowPassFilterFlyWheel3_C
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel3'
                                        */
  -6.1266,                             /* Expression: gain
                                        * Referenced by: '<S24>/Slider Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S8>/Gain4'
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
                                        * Referenced by: '<S11>/Proportional Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S11>/Integrator'
                                        */
  0.0,                                 /* Expression: D
                                        * Referenced by: '<S11>/Derivative Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S11>/Filter'
                                        */
  100.0,                               /* Expression: N
                                        * Referenced by: '<S11>/Filter Coefficient'
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
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<Root>/Constant4'
                                        */
  -15.0,                               /* Computed Parameter: LowPassFilterGimbleVelocity1_A
                                        * Referenced by: '<Root>/Low Pass Filter Gimble Velocity1'
                                        */
  15.0,                                /* Computed Parameter: LowPassFilterGimbleVelocity1_C
                                        * Referenced by: '<Root>/Low Pass Filter Gimble Velocity1'
                                        */
  -30.0,                               /* Computed Parameter: PositionFilter_A
                                        * Referenced by: '<S4>/Position Filter'
                                        */
  30.0,                                /* Computed Parameter: PositionFilter_C
                                        * Referenced by: '<S4>/Position Filter'
                                        */
  472.8114,                            /* Expression: gain
                                        * Referenced by: '<S19>/Slider Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  0.0,                                 /* Expression: gain
                                        * Referenced by: '<S18>/Slider Gain'
                                        */
  2500.0,                              /* Expression: 2500
                                        * Referenced by: '<S4>/Saturation1'
                                        */
  -2500.0,                             /* Expression: -2500
                                        * Referenced by: '<S4>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator3'
                                        */
  40.0,                                /* Expression: gain
                                        * Referenced by: '<S16>/Slider Gain'
                                        */
  990.0,                               /* Expression: gain
                                        * Referenced by: '<S17>/Slider Gain'
                                        */
  40000.0,                             /* Expression: 40000
                                        * Referenced by: '<S4>/Saturation'
                                        */
  -40000.0,                            /* Expression: -40000
                                        * Referenced by: '<S4>/Saturation'
                                        */
  -4.0,                                /* Expression: gain
                                        * Referenced by: '<S15>/Slider Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */
  20.0,                                /* Expression: gain
                                        * Referenced by: '<S14>/Slider Gain'
                                        */
  -9.0,                                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S9>/Transfer Fcn'
                                        */
  9.0,                                 /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S9>/Transfer Fcn'
                                        */
  0.48,                                /* Expression: P
                                        * Referenced by: '<S26>/Proportional Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S26>/Integrator'
                                        */
  0.0,                                 /* Expression: D
                                        * Referenced by: '<S26>/Derivative Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S26>/Filter'
                                        */
  100.0,                               /* Expression: N
                                        * Referenced by: '<S26>/Filter Coefficient'
                                        */
  -10.0,                               /* Computed Parameter: LowPassFilterFlyWheel2_A
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel2'
                                        */
  10.0,                                /* Computed Parameter: LowPassFilterFlyWheel2_C
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel2'
                                        */
  0.00655,                             /* Expression: 0.5*0.0131
                                        * Referenced by: '<S9>/Gain'
                                        */
  -8.0,                                /* Computed Parameter: LowPassFilterFlyWheel1_A
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel1'
                                        */
  8.0,                                 /* Computed Parameter: LowPassFilterFlyWheel1_C
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
  0.418184604,                         /* Expression: 0.1580*9.81*0.2698
                                        * Referenced by: '<S9>/Gain2'
                                        */
  0.36160836773901645,                 /* Expression: 0.1530/(41.8879*0.0273*0.37)
                                        * Referenced by: '<S9>/Table Acceleration to Gimble Velocity'
                                        */
  1410.0,                              /* Expression: gain
                                        * Referenced by: '<S13>/Slider Gain'
                                        */
  50000.0,                             /* Expression: 50000
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  -50000.0,                            /* Expression: -50000
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  10000.0,                             /* Expression: P
                                        * Referenced by: '<S12>/Proportional Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S12>/Integrator'
                                        */
  0.0,                                 /* Expression: D
                                        * Referenced by: '<S12>/Derivative Gain'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S12>/Filter'
                                        */
  100.0,                               /* Expression: N
                                        * Referenced by: '<S12>/Filter Coefficient'
                                        */
  23500.0,                             /* Expression: 23500
                                        * Referenced by: '<S3>/Saturation2'
                                        */
  -23500.0,                            /* Expression: -23500
                                        * Referenced by: '<S3>/Saturation2'
                                        */
  -9.0,                                /* Computed Parameter: LowPassFilterFlyWheel_A_b
                                        * Referenced by: '<S10>/Low Pass Filter Fly Wheel'
                                        */
  9.0,                                 /* Computed Parameter: LowPassFilterFlyWheel_C_g
                                        * Referenced by: '<S10>/Low Pass Filter Fly Wheel'
                                        */
  23500.0,                             /* Expression: 23500
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  -23500.0,                            /* Expression: -23500
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<Root>/Constant5'
                                        */
  57.295827908797776,                  /* Expression: 180/3.14159
                                        * Referenced by: '<Root>/Gain4'
                                        */
  -15.0,                               /* Computed Parameter: LowPassFilterGimbleVelocity2_A
                                        * Referenced by: '<Root>/Low Pass Filter Gimble Velocity2'
                                        */
  15.0,                                /* Computed Parameter: LowPassFilterGimbleVelocity2_C
                                        * Referenced by: '<Root>/Low Pass Filter Gimble Velocity2'
                                        */
  1.227415553809898E-5,                /* Expression: 1/(2546*32)
                                        * Referenced by: '<Root>/Gain3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  2.945334590009425E-5,                /* Expression: 1/(1061*32)
                                        * Referenced by: '<S2>/encoder to radians'
                                        */
  20.0,                                /* Expression: I
                                        * Referenced by: '<S11>/Integral Gain'
                                        */
  9.5492965855137211,                  /* Expression: 30/pi
                                        * Referenced by: '<S2>/rad//sec to rpm'
                                        */
  2500.0,                              /* Expression: I
                                        * Referenced by: '<S12>/Integral Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Constant4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Desired Energy'
                                        */
  0.85,                                /* Expression: vinit
                                        * Referenced by: '<S30>/Initial Condition'
                                        */
  0.85,                                /* Expression: vinit
                                        * Referenced by: '<S30>/FixPt Unit Delay1'
                                        */
  0.06,                                /* Expression: I
                                        * Referenced by: '<S26>/Integral Gain'
                                        */
  -40.0,                               /* Computed Parameter: LowPassFilterFlyWheel7_A
                                        * Referenced by: '<S10>/Low Pass Filter Fly Wheel7'
                                        */
  40.0,                                /* Computed Parameter: LowPassFilterFlyWheel7_C
                                        * Referenced by: '<S10>/Low Pass Filter Fly Wheel7'
                                        */
  70.0,                                /* Expression: gain
                                        * Referenced by: '<S34>/Slider Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Integrator'
                                        */
  38.249,                              /* Expression: gain
                                        * Referenced by: '<S32>/Slider Gain'
                                        */
  -8.0                                 /* Expression: gain
                                        * Referenced by: '<S31>/Slider Gain'
                                        */
};
