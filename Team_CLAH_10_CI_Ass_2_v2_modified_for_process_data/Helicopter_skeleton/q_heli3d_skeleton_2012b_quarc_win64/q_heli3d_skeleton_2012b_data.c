/*
 * q_heli3d_skeleton_2012b_data.c
 *
 * Code generation for model "q_heli3d_skeleton_2012b".
 *
 * Model version              : 1.64
 * Simulink Coder version : 8.2 (R2012a) 29-Dec-2011
 * C source code generated on : Wed Oct 18 15:54:30 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "q_heli3d_skeleton_2012b.h"
#include "q_heli3d_skeleton_2012b_private.h"

/* Block parameters (auto storage) */
Parameters_q_heli3d_skeleton_20 q_heli3d_skeleton_2012b_P = {
  0.0,                                 /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: set_other_outputs_at_switch_in
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: set_other_outputs_at_terminate
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: set_other_outputs_at_switch_out
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  10.0,                                /* Expression: analog_input_maximums
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  -10.0,                               /* Expression: analog_input_minimums
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  10.0,                                /* Expression: analog_output_maximums
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  -10.0,                               /* Expression: analog_output_minimums
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: initial_analog_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: final_analog_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: watchdog_analog_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  24305.934065934067,                  /* Expression: pwm_frequency
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: pwm_leading_deadband
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: pwm_trailing_deadband
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: initial_pwm_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: final_pwm_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: watchdog_pwm_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  2.1505,                              /* Expression: gain
                                        * Referenced by: '<S6>/Slider Gain'
                                        */
  40.0,                                /* Expression: start
                                        * Referenced by: '<S4>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Step'
                                        */
  12.5,                                /* Expression: slope
                                        * Referenced by: '<S4>/Step'
                                        */
  40.0,                                /* Expression: start
                                        * Referenced by: '<S4>/Constant'
                                        */
  0.0,                                 /* Expression: X0
                                        * Referenced by: '<S4>/Constant1'
                                        */
  40.0,                                /* Expression: 40
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<Root>/Saturation'
                                        */
  40.0,                                /* Expression: start
                                        * Referenced by: '<S5>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Step'
                                        */
  12.5,                                /* Expression: slope
                                        * Referenced by: '<S5>/Step'
                                        */
  40.0,                                /* Expression: start
                                        * Referenced by: '<S5>/Constant'
                                        */
  0.0,                                 /* Expression: X0
                                        * Referenced by: '<S5>/Constant1'
                                        */
  40.0,                                /* Expression: 40
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  0.0,                                 /* Expression: gain
                                        * Referenced by: '<S7>/Slider Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */

  /*  Expression: K
   * Referenced by: '<Root>/Gain3'
   */
  { 40.036643067216211, 40.036643067216211, 36.08137822818582,
    -36.08137822818582, -30.3856756703023, 30.3856756703023, 25.52083997988268,
    25.52083997988268, 11.585881229646212, -11.585881229646212,
    -47.906777687304036, 47.906777687304036 },
  7.4556381118881161,                  /* Expression: Vo
                                        * Referenced by: '<Root>/Bias'
                                        */
  24.0,                                /* Expression: VMAX_AMP
                                        * Referenced by: '<S1>/Amplifier Voltage  Limit (V)'
                                        */
  -24.0,                               /* Expression: -VMAX_AMP
                                        * Referenced by: '<S1>/Amplifier Voltage  Limit (V)'
                                        */
  0.2,                                 /* Expression:  1 / K_AMP
                                        * Referenced by: '<S1>/Amplifier Gain Pre-Compensation'
                                        */
  10.0,                                /* Expression: VMAX_DAC
                                        * Referenced by: '<S1>/DACB Limit (V)'
                                        */
  -10.0,                               /* Expression: -VMAX_DAC
                                        * Referenced by: '<S1>/DACB Limit (V)'
                                        */
  5.0,                                 /* Expression:  K_AMP
                                        * Referenced by: '<S1>/Amplifier Gain'
                                        */
  -0.0015339807878856412,              /* Expression: K_EC_E
                                        * Referenced by: '<S1>/Encoder Resolution: Elevation (rad//count)'
                                        */
  0.0015339807878856412,               /* Expression: K_EC_P
                                        * Referenced by: '<S1>/Encoder Resolution: Pitch (rad//count)'
                                        */
  0.00076699039394282058,              /* Expression: K_EC_T
                                        * Referenced by: '<S1>/Encoder Resolution: Travel (rad//count)'
                                        */
  -0.47996554429844063,                /* Expression: elev_0
                                        * Referenced by: '<S1>/Initial Elevation (rad)'
                                        */

  /*  Expression: [1 1 1 1]
   * Referenced by: '<S1>/Enable Amp'
   */
  { 1.0, 1.0, 1.0, 1.0 },
  -27.5,                               /* Expression: elev_0*180/pi
                                        * Referenced by: '<S3>/Des Position:  Elevation (deg)'
                                        */
  27.5,                                /* Expression: CMD_ELEV_POS_LIMIT_UPPER
                                        * Referenced by: '<S3>/Des Position:  Elevation (deg)'
                                        */
  -27.5,                               /* Expression: CMD_ELEV_POS_LIMIT_LOWER
                                        * Referenced by: '<S3>/Des Position:  Elevation (deg)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Des Position:  Travel (deg)'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S13>/Gain1'
                                        */

  /*  Expression: C_0
   * Referenced by: '<Root>/Gain6'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: K_r
   * Referenced by: '<Root>/Gain4'
   */
  { 40.036643067216211, 40.036643067216211, -30.3856756703023, 30.3856756703023
  },
  -10.0,                               /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  -100.0,                              /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  10.0,                                /* Computed Parameter: TransferFcn_D
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  -10.0,                               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  -100.0,                              /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  10.0,                                /* Computed Parameter: TransferFcn1_D
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  -10.0,                               /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */
  -100.0,                              /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */
  10.0,                                /* Computed Parameter: TransferFcn2_D
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */

  /*  Expression: C
   * Referenced by: '<Root>/Gain2'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 },

  /*  Expression: B
   * Referenced by: '<Root>/Gain'
   */
  { 0.0, 0.0, 0.0, 0.085794874947817359, 0.58101432973052292, 0.0, 0.0, 0.0, 0.0,
    0.085794874947817359, -0.58101432973052292, 0.0 },

  /*  Expression: A
   * Referenced by: '<Root>/Gain1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.2303958542095543,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Rate Transition: z'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S12>/Inverse'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S12>/Bias'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S12>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Rate Transition: x'
                                        */
  40.0,                                /* Expression: K_JOYSTICK_X
                                        * Referenced by: '<S3>/Calibration: X  (deg//s//V)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Rate Transition: y'
                                        */
  45.0,                                /* Expression: K_JOYSTICK_Y
                                        * Referenced by: '<S3>/Calibration: Y  (deg//s//V)'
                                        */

  /*  Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0, 1, 2 },
  0,                                   /* Computed Parameter: HILInitialize_DOWatchdog
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_EIInitial
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POModes
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POConfiguration
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POAlignment
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_POPolarity
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILReadEncoderTimebase_Clock
                                        * Referenced by: '<S1>/HIL Read Encoder Timebase'
                                        */

  /*  Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Computed Parameter: HILInitialize_DIChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 4U, 5U, 6U, 7U },

  /*  Computed Parameter: HILInitialize_DOChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U },

  /*  Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
  4U,                                  /* Computed Parameter: HILInitialize_EIQuadrature
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */

  /*  Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Computed Parameter: HILReadEncoderTimebase_Channels
   * Referenced by: '<S1>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },
  500U,                                /* Computed Parameter: HILReadEncoderTimebase_SamplesI
                                        * Referenced by: '<S1>/HIL Read Encoder Timebase'
                                        */

  /*  Computed Parameter: HILWriteAnalog_Channels
   * Referenced by: '<S1>/HIL Write Analog'
   */
  { 0U, 1U },

  /*  Computed Parameter: HILWriteDigital_Channels
   * Referenced by: '<S1>/HIL Write Digital'
   */
  { 0U, 1U, 2U, 3U },
  12U,                                 /* Computed Parameter: GameController_BufferSize
                                        * Referenced by: '<S3>/Game Controller'
                                        */
  1U,                                  /* Computed Parameter: GameController_ControllerNumber
                                        * Referenced by: '<S3>/Game Controller'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_Active
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_CKPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_CKPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_CKStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_CKEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_AIPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AIPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_AOPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AOPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_AOStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AOEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_AOTerminate
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AOExit
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AOReset
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_DOStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_DOTerminate
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOExit
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOReset
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_EIPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_EIPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_EIStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_EIEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_POPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_POStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_POTerminate
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POExit
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POReset
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_OOReset
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOInitial
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOFinal
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILReadEncoderTimebase_Active
                                        * Referenced by: '<S1>/HIL Read Encoder Timebase'
                                        */
  0,                                   /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<S1>/HIL Write Analog'
                                        */
  0,                                   /* Computed Parameter: HILWriteDigital_Active
                                        * Referenced by: '<S1>/HIL Write Digital'
                                        */
  0,                                   /* Computed Parameter: GameController_AutoCenter
                                        * Referenced by: '<S3>/Game Controller'
                                        */
  1                                    /* Computed Parameter: GameController_Enabled
                                        * Referenced by: '<S3>/Game Controller'
                                        */
};
