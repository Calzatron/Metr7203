/*
 * q_heli3d_skeleton_2012b.c
 *
 * Code generation for model "q_heli3d_skeleton_2012b".
 *
 * Model version              : 1.95
 * Simulink Coder version : 8.2 (R2012a) 29-Dec-2011
 * C source code generated on : Fri Oct 20 19:09:42 2017
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "q_heli3d_skeleton_2012b.h"
#include "q_heli3d_skeleton_2012b_private.h"
#include "q_heli3d_skeleton_2012b_dt.h"

/* Block signals (auto storage) */
BlockIO_q_heli3d_skeleton_2012b q_heli3d_skeleton_2012b_B;

/* Continuous states */
ContinuousStates_q_heli3d_skele q_heli3d_skeleton_2012b_X;

/* Block states (auto storage) */
D_Work_q_heli3d_skeleton_2012b q_heli3d_skeleton_2012b_DWork;

/* Real-time model */
RT_MODEL_q_heli3d_skeleton_2012 q_heli3d_skeleton_2012b_M_;
RT_MODEL_q_heli3d_skeleton_2012 *const q_heli3d_skeleton_2012b_M =
  &q_heli3d_skeleton_2012b_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(q_heli3d_skeleton_2012b_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(q_heli3d_skeleton_2012b_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/* rate_monotonic_scheduler */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (q_heli3d_skeleton_2012b_M->Timing.TaskCounters.TID[1] == 0) {
    q_heli3d_skeleton_2012b_M->Timing.RateInteraction.TID1_2 =
      (q_heli3d_skeleton_2012b_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (q_heli3d_skeleton_2012b_M->Timing.TaskCounters.TID[2])++;
  if ((q_heli3d_skeleton_2012b_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    q_heli3d_skeleton_2012b_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 13;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  q_heli3d_skeleton_2012b_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function for TID0 */
void q_heli3d_skeleton_2012b_step0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase[3];
  real_T rtb_DesPositionElevationdeg;
  real_T rtb_Divide;
  int32_T i;
  real_T tmp[6];
  real_T tmp_0[6];
  int32_T i_0;
  real_T rtb_u_idx;
  real_T rtb_u_idx_0;
  if (rtmIsMajorTimeStep(q_heli3d_skeleton_2012b_M)) {
    /* set solver stop time */
    if (!(q_heli3d_skeleton_2012b_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&q_heli3d_skeleton_2012b_M->solverInfo,
                            ((q_heli3d_skeleton_2012b_M->Timing.clockTickH0 + 1)
        * q_heli3d_skeleton_2012b_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&q_heli3d_skeleton_2012b_M->solverInfo,
                            ((q_heli3d_skeleton_2012b_M->Timing.clockTick0 + 1) *
        q_heli3d_skeleton_2012b_M->Timing.stepSize0 +
        q_heli3d_skeleton_2012b_M->Timing.clockTickH0 *
        q_heli3d_skeleton_2012b_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(q_heli3d_skeleton_2012b_M)) {
    q_heli3d_skeleton_2012b_M->Timing.t[0] = rtsiGetT
      (&q_heli3d_skeleton_2012b_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(q_heli3d_skeleton_2012b_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S1>/HIL Read Encoder Timebase' */

    /* S-Function Block: q_heli3d_skeleton_2012b/3-DOF Plant/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (q_heli3d_skeleton_2012b_DWork.HILReadEncoderTimebase_Task, 1,
         &q_heli3d_skeleton_2012b_DWork.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase[0] =
          q_heli3d_skeleton_2012b_DWork.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase[1] =
          q_heli3d_skeleton_2012b_DWork.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase[2] =
          q_heli3d_skeleton_2012b_DWork.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Gain: '<S4>/Slider Gain' incorporates:
     *  Constant: '<Root>/Constant'
     */
    q_heli3d_skeleton_2012b_B.SliderGain =
      q_heli3d_skeleton_2012b_P.SliderGain_Gain *
      q_heli3d_skeleton_2012b_P.Constant_Value;
  }

  /* Integrator: '<S3>/Des Position:  Elevation (deg)'
   *
   * Regarding '<S3>/Des Position:  Elevation (deg)':
   *  Limited Integrator
   */
  if (q_heli3d_skeleton_2012b_X.DesPositionElevationdeg_CSTATE >=
      q_heli3d_skeleton_2012b_P.DesPositionElevationdeg_UpperSa ) {
    q_heli3d_skeleton_2012b_X.DesPositionElevationdeg_CSTATE =
      q_heli3d_skeleton_2012b_P.DesPositionElevationdeg_UpperSa;
  } else if (q_heli3d_skeleton_2012b_X.DesPositionElevationdeg_CSTATE <=
             q_heli3d_skeleton_2012b_P.DesPositionElevationdeg_LowerSa ) {
    q_heli3d_skeleton_2012b_X.DesPositionElevationdeg_CSTATE =
      q_heli3d_skeleton_2012b_P.DesPositionElevationdeg_LowerSa;
  }

  rtb_DesPositionElevationdeg =
    q_heli3d_skeleton_2012b_X.DesPositionElevationdeg_CSTATE;

  /* Gain: '<S10>/Gain1' incorporates:
   *  Integrator: '<S3>/Des Position:  Travel (deg)'
   */
  q_heli3d_skeleton_2012b_B.Gain1[0] = q_heli3d_skeleton_2012b_P.Gain1_Gain *
    rtb_DesPositionElevationdeg;
  q_heli3d_skeleton_2012b_B.Gain1[1] = q_heli3d_skeleton_2012b_P.Gain1_Gain *
    q_heli3d_skeleton_2012b_X.DesPositionTraveldeg_CSTATE;

  /* Gain: '<Root>/Reference Gain' */
  q_heli3d_skeleton_2012b_B.ReferenceGain[0] = 0.0;
  q_heli3d_skeleton_2012b_B.ReferenceGain[0] +=
    q_heli3d_skeleton_2012b_P.ReferenceGain_Gain[0] *
    q_heli3d_skeleton_2012b_B.Gain1[0];
  q_heli3d_skeleton_2012b_B.ReferenceGain[0] +=
    q_heli3d_skeleton_2012b_P.ReferenceGain_Gain[2] *
    q_heli3d_skeleton_2012b_B.Gain1[1];
  q_heli3d_skeleton_2012b_B.ReferenceGain[1] = 0.0;
  q_heli3d_skeleton_2012b_B.ReferenceGain[1] +=
    q_heli3d_skeleton_2012b_P.ReferenceGain_Gain[1] *
    q_heli3d_skeleton_2012b_B.Gain1[0];
  q_heli3d_skeleton_2012b_B.ReferenceGain[1] +=
    q_heli3d_skeleton_2012b_P.ReferenceGain_Gain[3] *
    q_heli3d_skeleton_2012b_B.Gain1[1];

  /* Integrator: '<Root>/Integrator1'
   *
   * Regarding '<Root>/Integrator1':
   *  Limited Integrator
   */
  if (q_heli3d_skeleton_2012b_X.Integrator1_CSTATE[0] >=
      q_heli3d_skeleton_2012b_P.Integrator1_UpperSat ) {
    q_heli3d_skeleton_2012b_X.Integrator1_CSTATE[0] =
      q_heli3d_skeleton_2012b_P.Integrator1_UpperSat;
  } else if (q_heli3d_skeleton_2012b_X.Integrator1_CSTATE[0] <=
             q_heli3d_skeleton_2012b_P.Integrator1_LowerSat ) {
    q_heli3d_skeleton_2012b_X.Integrator1_CSTATE[0] =
      q_heli3d_skeleton_2012b_P.Integrator1_LowerSat;
  }

  if (q_heli3d_skeleton_2012b_X.Integrator1_CSTATE[1] >=
      q_heli3d_skeleton_2012b_P.Integrator1_UpperSat ) {
    q_heli3d_skeleton_2012b_X.Integrator1_CSTATE[1] =
      q_heli3d_skeleton_2012b_P.Integrator1_UpperSat;
  } else if (q_heli3d_skeleton_2012b_X.Integrator1_CSTATE[1] <=
             q_heli3d_skeleton_2012b_P.Integrator1_LowerSat ) {
    q_heli3d_skeleton_2012b_X.Integrator1_CSTATE[1] =
      q_heli3d_skeleton_2012b_P.Integrator1_LowerSat;
  }

  q_heli3d_skeleton_2012b_B.z[0] = q_heli3d_skeleton_2012b_X.Integrator1_CSTATE
    [0];
  q_heli3d_skeleton_2012b_B.z[1] = q_heli3d_skeleton_2012b_X.Integrator1_CSTATE
    [1];

  /* Gain: '<Root>/Integral Gain' */
  q_heli3d_skeleton_2012b_B.IntegralGain[0] = 0.0;
  q_heli3d_skeleton_2012b_B.IntegralGain[0] +=
    q_heli3d_skeleton_2012b_P.IntegralGain_Gain[0] *
    q_heli3d_skeleton_2012b_B.z[0];
  q_heli3d_skeleton_2012b_B.IntegralGain[0] +=
    q_heli3d_skeleton_2012b_P.IntegralGain_Gain[2] *
    q_heli3d_skeleton_2012b_B.z[1];
  q_heli3d_skeleton_2012b_B.IntegralGain[1] = 0.0;
  q_heli3d_skeleton_2012b_B.IntegralGain[1] +=
    q_heli3d_skeleton_2012b_P.IntegralGain_Gain[1] *
    q_heli3d_skeleton_2012b_B.z[0];
  q_heli3d_skeleton_2012b_B.IntegralGain[1] +=
    q_heli3d_skeleton_2012b_P.IntegralGain_Gain[3] *
    q_heli3d_skeleton_2012b_B.z[1];

  /* Integrator: '<Root>/Integrator' */
  for (i = 0; i < 6; i++) {
    q_heli3d_skeleton_2012b_B.x[i] =
      q_heli3d_skeleton_2012b_X.Integrator_CSTATE[i];
  }

  /* End of Integrator: '<Root>/Integrator' */

  /* Gain: '<Root>/State Feedback' */
  for (i = 0; i < 2; i++) {
    q_heli3d_skeleton_2012b_B.StateFeedback[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      q_heli3d_skeleton_2012b_B.StateFeedback[i] +=
        q_heli3d_skeleton_2012b_P.StateFeedback_Gain[(i_0 << 1) + i] *
        q_heli3d_skeleton_2012b_B.x[i_0];
    }
  }

  /* End of Gain: '<Root>/State Feedback' */

  /* Sum: '<Root>/Sum' */
  rtb_u_idx = (q_heli3d_skeleton_2012b_B.ReferenceGain[0] +
               q_heli3d_skeleton_2012b_B.IntegralGain[0]) -
    q_heli3d_skeleton_2012b_B.StateFeedback[0];
  rtb_u_idx_0 = (q_heli3d_skeleton_2012b_B.ReferenceGain[1] +
                 q_heli3d_skeleton_2012b_B.IntegralGain[1]) -
    q_heli3d_skeleton_2012b_B.StateFeedback[1];

  /* Bias: '<Root>/Zero'ing Bias' incorporates:
   *  Sum: '<Root>/Add Votlage'
   */
  q_heli3d_skeleton_2012b_B.ZeroingBias[0] =
    (q_heli3d_skeleton_2012b_B.SliderGain + rtb_u_idx) +
    q_heli3d_skeleton_2012b_P.ZeroingBias_Bias;
  q_heli3d_skeleton_2012b_B.ZeroingBias[1] =
    (q_heli3d_skeleton_2012b_B.SliderGain + rtb_u_idx_0) +
    q_heli3d_skeleton_2012b_P.ZeroingBias_Bias;

  /* Saturate: '<S1>/Amplifier Voltage  Limit (V)' */
  if (q_heli3d_skeleton_2012b_B.ZeroingBias[0] >=
      q_heli3d_skeleton_2012b_P.AmplifierVoltageLimitV_UpperSat) {
    rtb_Divide = q_heli3d_skeleton_2012b_P.AmplifierVoltageLimitV_UpperSat;
  } else if (q_heli3d_skeleton_2012b_B.ZeroingBias[0] <=
             q_heli3d_skeleton_2012b_P.AmplifierVoltageLimitV_LowerSat) {
    rtb_Divide = q_heli3d_skeleton_2012b_P.AmplifierVoltageLimitV_LowerSat;
  } else {
    rtb_Divide = q_heli3d_skeleton_2012b_B.ZeroingBias[0];
  }

  /* Gain: '<S1>/Amplifier Gain Pre-Compensation' incorporates:
   *  Saturate: '<S1>/Amplifier Voltage  Limit (V)'
   */
  rtb_Divide *= q_heli3d_skeleton_2012b_P.AmplifierGainPreCompensation_Ga;

  /* Saturate: '<S1>/DACB Limit (V)' */
  if (rtb_Divide >= q_heli3d_skeleton_2012b_P.DACBLimitV_UpperSat) {
    q_heli3d_skeleton_2012b_B.DACBLimitV[0] =
      q_heli3d_skeleton_2012b_P.DACBLimitV_UpperSat;
  } else if (rtb_Divide <= q_heli3d_skeleton_2012b_P.DACBLimitV_LowerSat) {
    q_heli3d_skeleton_2012b_B.DACBLimitV[0] =
      q_heli3d_skeleton_2012b_P.DACBLimitV_LowerSat;
  } else {
    q_heli3d_skeleton_2012b_B.DACBLimitV[0] = rtb_Divide;
  }

  /* Saturate: '<S1>/Amplifier Voltage  Limit (V)' */
  if (q_heli3d_skeleton_2012b_B.ZeroingBias[1] >=
      q_heli3d_skeleton_2012b_P.AmplifierVoltageLimitV_UpperSat) {
    rtb_Divide = q_heli3d_skeleton_2012b_P.AmplifierVoltageLimitV_UpperSat;
  } else if (q_heli3d_skeleton_2012b_B.ZeroingBias[1] <=
             q_heli3d_skeleton_2012b_P.AmplifierVoltageLimitV_LowerSat) {
    rtb_Divide = q_heli3d_skeleton_2012b_P.AmplifierVoltageLimitV_LowerSat;
  } else {
    rtb_Divide = q_heli3d_skeleton_2012b_B.ZeroingBias[1];
  }

  /* Gain: '<S1>/Amplifier Gain Pre-Compensation' incorporates:
   *  Saturate: '<S1>/Amplifier Voltage  Limit (V)'
   */
  rtb_Divide *= q_heli3d_skeleton_2012b_P.AmplifierGainPreCompensation_Ga;

  /* Saturate: '<S1>/DACB Limit (V)' */
  if (rtb_Divide >= q_heli3d_skeleton_2012b_P.DACBLimitV_UpperSat) {
    q_heli3d_skeleton_2012b_B.DACBLimitV[1] =
      q_heli3d_skeleton_2012b_P.DACBLimitV_UpperSat;
  } else if (rtb_Divide <= q_heli3d_skeleton_2012b_P.DACBLimitV_LowerSat) {
    q_heli3d_skeleton_2012b_B.DACBLimitV[1] =
      q_heli3d_skeleton_2012b_P.DACBLimitV_LowerSat;
  } else {
    q_heli3d_skeleton_2012b_B.DACBLimitV[1] = rtb_Divide;
  }

  if (rtmIsMajorTimeStep(q_heli3d_skeleton_2012b_M)) {
    /* S-Function (hil_write_analog_block): '<S1>/HIL Write Analog' */

    /* S-Function Block: q_heli3d_skeleton_2012b/3-DOF Plant/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
        q_heli3d_skeleton_2012b_P.HILWriteAnalog_Channels, 2,
        q_heli3d_skeleton_2012b_B.DACBLimitV);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
      }
    }
  }

  /* Gain: '<S1>/Amplifier Gain' */
  q_heli3d_skeleton_2012b_B.AmplifierGain[0] =
    q_heli3d_skeleton_2012b_P.AmplifierGain_Gain *
    q_heli3d_skeleton_2012b_B.DACBLimitV[0];
  q_heli3d_skeleton_2012b_B.AmplifierGain[1] =
    q_heli3d_skeleton_2012b_P.AmplifierGain_Gain *
    q_heli3d_skeleton_2012b_B.DACBLimitV[1];
  if (rtmIsMajorTimeStep(q_heli3d_skeleton_2012b_M)) {
    /* Gain: '<S1>/Encoder Resolution: Pitch (rad//count)' */
    q_heli3d_skeleton_2012b_B.EncoderResolutionPitchradcount =
      q_heli3d_skeleton_2012b_P.EncoderResolutionPitchradcount_ *
      rtb_HILReadEncoderTimebase[1];

    /* Gain: '<S1>/Encoder Resolution: Travel (rad//count)' */
    q_heli3d_skeleton_2012b_B.EncoderResolutionTravelradcount =
      q_heli3d_skeleton_2012b_P.EncoderResolutionTravelradcount *
      rtb_HILReadEncoderTimebase[0];

    /* Bias: '<S1>/Initial Elevation (rad)' incorporates:
     *  Gain: '<S1>/Encoder Resolution: Elevation (rad//count)'
     */
    q_heli3d_skeleton_2012b_B.InitialElevationrad =
      q_heli3d_skeleton_2012b_P.EncoderResolutionElevationradco *
      rtb_HILReadEncoderTimebase[2] +
      q_heli3d_skeleton_2012b_P.InitialElevationrad_Bias;

    /* S-Function (hil_write_digital_block): '<S1>/HIL Write Digital' */

    /* S-Function Block: q_heli3d_skeleton_2012b/3-DOF Plant/HIL Write Digital (hil_write_digital_block) */
    {
      t_error result;
      q_heli3d_skeleton_2012b_DWork.HILWriteDigital_Buffer[0] =
        (q_heli3d_skeleton_2012b_P.EnableAmp_Value[0] != 0);
      q_heli3d_skeleton_2012b_DWork.HILWriteDigital_Buffer[1] =
        (q_heli3d_skeleton_2012b_P.EnableAmp_Value[1] != 0);
      q_heli3d_skeleton_2012b_DWork.HILWriteDigital_Buffer[2] =
        (q_heli3d_skeleton_2012b_P.EnableAmp_Value[2] != 0);
      q_heli3d_skeleton_2012b_DWork.HILWriteDigital_Buffer[3] =
        (q_heli3d_skeleton_2012b_P.EnableAmp_Value[3] != 0);
      result = hil_write_digital
        (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
         q_heli3d_skeleton_2012b_P.HILWriteDigital_Channels, 4,
         &q_heli3d_skeleton_2012b_DWork.HILWriteDigital_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
      }
    }
  }

  /* Gain: '<Root>/Gain2' */
  for (i = 0; i < 3; i++) {
    q_heli3d_skeleton_2012b_B.y_hat[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      q_heli3d_skeleton_2012b_B.y_hat[i] +=
        q_heli3d_skeleton_2012b_P.Gain2_Gain[3 * i_0 + i] *
        q_heli3d_skeleton_2012b_B.x[i_0];
    }
  }

  /* End of Gain: '<Root>/Gain2' */

  /* Sum: '<Root>/Add1' */
  q_heli3d_skeleton_2012b_B.Add1[0] =
    q_heli3d_skeleton_2012b_B.InitialElevationrad -
    q_heli3d_skeleton_2012b_B.y_hat[0];
  q_heli3d_skeleton_2012b_B.Add1[1] =
    q_heli3d_skeleton_2012b_B.EncoderResolutionPitchradcount -
    q_heli3d_skeleton_2012b_B.y_hat[1];
  q_heli3d_skeleton_2012b_B.Add1[2] =
    q_heli3d_skeleton_2012b_B.EncoderResolutionTravelradcount -
    q_heli3d_skeleton_2012b_B.y_hat[2];
  if (rtmIsMajorTimeStep(q_heli3d_skeleton_2012b_M)) {
  }

  /* Gain: '<Root>/Output Reference' */
  for (i = 0; i < 2; i++) {
    q_heli3d_skeleton_2012b_B.y_hat_j[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      q_heli3d_skeleton_2012b_B.y_hat_j[i] +=
        q_heli3d_skeleton_2012b_P.OutputReference_Gain[(i_0 << 1) + i] *
        q_heli3d_skeleton_2012b_B.x[i_0];
    }
  }

  /* End of Gain: '<Root>/Output Reference' */

  /* Sum: '<Root>/Sum1' */
  q_heli3d_skeleton_2012b_B.zry_hat[0] = q_heli3d_skeleton_2012b_B.Gain1[0] -
    q_heli3d_skeleton_2012b_B.y_hat_j[0];
  q_heli3d_skeleton_2012b_B.zry_hat[1] = q_heli3d_skeleton_2012b_B.Gain1[1] -
    q_heli3d_skeleton_2012b_B.y_hat_j[1];
  if (rtmIsMajorTimeStep(q_heli3d_skeleton_2012b_M)) {
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  q_heli3d_skeleton_2012b_B.TransferFcn =
    q_heli3d_skeleton_2012b_P.TransferFcn_D*
    q_heli3d_skeleton_2012b_B.InitialElevationrad;
  q_heli3d_skeleton_2012b_B.TransferFcn +=
    q_heli3d_skeleton_2012b_P.TransferFcn_C*
    q_heli3d_skeleton_2012b_X.TransferFcn_CSTATE;

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  q_heli3d_skeleton_2012b_B.TransferFcn1 =
    q_heli3d_skeleton_2012b_P.TransferFcn1_D*
    q_heli3d_skeleton_2012b_B.EncoderResolutionPitchradcount;
  q_heli3d_skeleton_2012b_B.TransferFcn1 +=
    q_heli3d_skeleton_2012b_P.TransferFcn1_C*
    q_heli3d_skeleton_2012b_X.TransferFcn1_CSTATE;

  /* TransferFcn: '<Root>/Transfer Fcn2' */
  q_heli3d_skeleton_2012b_B.TransferFcn2 =
    q_heli3d_skeleton_2012b_P.TransferFcn2_D*
    q_heli3d_skeleton_2012b_B.EncoderResolutionTravelradcount;
  q_heli3d_skeleton_2012b_B.TransferFcn2 +=
    q_heli3d_skeleton_2012b_P.TransferFcn2_C*
    q_heli3d_skeleton_2012b_X.TransferFcn2_CSTATE;
  if (rtmIsMajorTimeStep(q_heli3d_skeleton_2012b_M)) {
    /* SignalConversion: '<Root>/TmpSignal ConversionAtMeasInport1' */
    q_heli3d_skeleton_2012b_B.y[0] =
      q_heli3d_skeleton_2012b_B.InitialElevationrad;
    q_heli3d_skeleton_2012b_B.y[1] =
      q_heli3d_skeleton_2012b_B.EncoderResolutionPitchradcount;
    q_heli3d_skeleton_2012b_B.y[2] =
      q_heli3d_skeleton_2012b_B.EncoderResolutionTravelradcount;
  }

  /* Derivative: '<Root>/Derive Position' */
  {
    real_T t = q_heli3d_skeleton_2012b_M->Timing.t[0];
    real_T timeStampA =
      q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.TimeStampA;
    real_T timeStampB =
      q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.TimeStampB;
    real_T *lastU =
      &q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.LastUAtTimeA[0];
    if (timeStampA >= t && timeStampB >= t) {
      q_heli3d_skeleton_2012b_B.DerivePosition[0] = 0.0;
      q_heli3d_skeleton_2012b_B.DerivePosition[1] = 0.0;
      q_heli3d_skeleton_2012b_B.DerivePosition[2] = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU =
            &q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.LastUAtTimeB[0];
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU =
          &q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.LastUAtTimeB[0];
      }

      deltaT = t - lastTime;
      q_heli3d_skeleton_2012b_B.DerivePosition[0] =
        (q_heli3d_skeleton_2012b_B.InitialElevationrad - *lastU++) / deltaT;
      q_heli3d_skeleton_2012b_B.DerivePosition[1] =
        (q_heli3d_skeleton_2012b_B.EncoderResolutionPitchradcount - *lastU++) /
        deltaT;
      q_heli3d_skeleton_2012b_B.DerivePosition[2] =
        (q_heli3d_skeleton_2012b_B.EncoderResolutionTravelradcount - *lastU++) /
        deltaT;
    }
  }

  if (rtmIsMajorTimeStep(q_heli3d_skeleton_2012b_M)) {
  }

  for (i = 0; i < 6; i++) {
    /* Gain: '<Root>/State Input' incorporates:
     *  Sum: '<Root>/Add'
     */
    tmp_0[i] = q_heli3d_skeleton_2012b_P.StateInput_Gain[i + 6] * rtb_u_idx_0 +
      q_heli3d_skeleton_2012b_P.StateInput_Gain[i] * rtb_u_idx;

    /* Gain: '<Root>/Gain8' incorporates:
     *  Sum: '<Root>/Add'
     */
    tmp[i] = q_heli3d_skeleton_2012b_P.Gain8_Gain[i + 12] *
      q_heli3d_skeleton_2012b_B.Add1[2] +
      (q_heli3d_skeleton_2012b_P.Gain8_Gain[i + 6] *
       q_heli3d_skeleton_2012b_B.Add1[1] +
       q_heli3d_skeleton_2012b_P.Gain8_Gain[i] * q_heli3d_skeleton_2012b_B.Add1
       [0]);
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Gain: '<Root>/System Matrix'
   */
  for (i = 0; i < 6; i++) {
    rtb_Divide = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_Divide += q_heli3d_skeleton_2012b_P.SystemMatrix_Gain[6 * i_0 + i] *
        q_heli3d_skeleton_2012b_B.x[i_0];
    }

    q_heli3d_skeleton_2012b_B.x_dot[i] = (tmp[i] + tmp_0[i]) + rtb_Divide;
  }

  /* RateTransition: '<S3>/Rate Transition: z' */
  if (rtmIsMajorTimeStep(q_heli3d_skeleton_2012b_M)) {
    if (q_heli3d_skeleton_2012b_M->Timing.RateInteraction.TID1_2) {
      q_heli3d_skeleton_2012b_B.RateTransitionz =
        q_heli3d_skeleton_2012b_DWork.RateTransitionz_Buffer0;
    }

    /* Product: '<S9>/Divide' incorporates:
     *  Bias: '<S9>/Bias'
     *  Constant: '<S9>/Constant'
     *  Gain: '<S9>/Inverse'
     */
    rtb_Divide = (q_heli3d_skeleton_2012b_P.Inverse_Gain *
                  q_heli3d_skeleton_2012b_B.RateTransitionz +
                  q_heli3d_skeleton_2012b_P.Bias_Bias) /
      q_heli3d_skeleton_2012b_P.Constant_Value_c;

    /* RateTransition: '<S3>/Rate Transition: x' */
    if (q_heli3d_skeleton_2012b_M->Timing.RateInteraction.TID1_2) {
      q_heli3d_skeleton_2012b_B.RateTransitionx =
        q_heli3d_skeleton_2012b_DWork.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S3>/Rate Transition: x' */

    /* Gain: '<S3>/Calibration: X  (deg//s//V)' incorporates:
     *  Product: '<S3>/Travel Speed  Adj.'
     */
    q_heli3d_skeleton_2012b_B.CalibrationXdegsV = rtb_Divide *
      q_heli3d_skeleton_2012b_B.RateTransitionx *
      q_heli3d_skeleton_2012b_P.CalibrationXdegsV_Gain;

    /* RateTransition: '<S3>/Rate Transition: y' */
    if (q_heli3d_skeleton_2012b_M->Timing.RateInteraction.TID1_2) {
      q_heli3d_skeleton_2012b_B.RateTransitiony =
        q_heli3d_skeleton_2012b_DWork.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S3>/Rate Transition: y' */

    /* Gain: '<S3>/Calibration: Y  (deg//s//V)' incorporates:
     *  Product: '<S3>/Elevation Speed  Adj'
     */
    q_heli3d_skeleton_2012b_B.CalibrationYdegsV =
      q_heli3d_skeleton_2012b_B.RateTransitiony * rtb_Divide *
      q_heli3d_skeleton_2012b_P.CalibrationYdegsV_Gain;
  }

  /* End of RateTransition: '<S3>/Rate Transition: z' */

  /* S-Function (sfun_tstart): '<S7>/startTime' */

  /* S-Function Block (sfun_tstart): <S7>/startTime */
  q_heli3d_skeleton_2012b_B.startTime = (0.0);
  if (rtmIsMajorTimeStep(q_heli3d_skeleton_2012b_M)) {
    /* Update for Derivative: '<Root>/Derive Position' */
    {
      real_T timeStampA =
        q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.TimeStampA;
      real_T timeStampB =
        q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.TimeStampB;
      real_T* lastTime =
        &q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.TimeStampA;
      real_T* lastU =
        &q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.LastUAtTimeA[0];
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime =
            &q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.TimeStampB;
          lastU =
            &q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.LastUAtTimeB[0];
        } else if (timeStampA >= timeStampB) {
          lastTime =
            &q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.TimeStampB;
          lastU =
            &q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.LastUAtTimeB[0];
        }
      }

      *lastTime = q_heli3d_skeleton_2012b_M->Timing.t[0];
      *lastU++ = q_heli3d_skeleton_2012b_B.InitialElevationrad;
      *lastU++ = q_heli3d_skeleton_2012b_B.EncoderResolutionPitchradcount;
      *lastU++ = q_heli3d_skeleton_2012b_B.EncoderResolutionTravelradcount;
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(3);
    rtExtModeUpload(1, q_heli3d_skeleton_2012b_M->Timing.t[0]);
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(q_heli3d_skeleton_2012b_M)) {
    rt_ertODEUpdateContinuousStates(&q_heli3d_skeleton_2012b_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++q_heli3d_skeleton_2012b_M->Timing.clockTick0)) {
      ++q_heli3d_skeleton_2012b_M->Timing.clockTickH0;
    }

    q_heli3d_skeleton_2012b_M->Timing.t[0] = rtsiGetSolverStopTime
      (&q_heli3d_skeleton_2012b_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.002, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    q_heli3d_skeleton_2012b_M->Timing.clockTick1++;
    if (!q_heli3d_skeleton_2012b_M->Timing.clockTick1) {
      q_heli3d_skeleton_2012b_M->Timing.clockTickH1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void q_heli3d_skeleton_2012b_derivatives(void)
{
  int32_T i;
  StateDerivatives_q_heli3d_skele *_rtXdot;
  _rtXdot = ((StateDerivatives_q_heli3d_skele *)
             q_heli3d_skeleton_2012b_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S3>/Des Position:  Elevation (deg)' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( q_heli3d_skeleton_2012b_X.DesPositionElevationdeg_CSTATE <=
            q_heli3d_skeleton_2012b_P.DesPositionElevationdeg_LowerSa );
    usat = ( q_heli3d_skeleton_2012b_X.DesPositionElevationdeg_CSTATE >=
            q_heli3d_skeleton_2012b_P.DesPositionElevationdeg_UpperSa );
    if ((!lsat && !usat) ||
        (lsat && (q_heli3d_skeleton_2012b_B.CalibrationYdegsV > 0)) ||
        (usat && (q_heli3d_skeleton_2012b_B.CalibrationYdegsV < 0)) ) {
      ((StateDerivatives_q_heli3d_skele *)
        q_heli3d_skeleton_2012b_M->ModelData.derivs)
        ->DesPositionElevationdeg_CSTATE =
        q_heli3d_skeleton_2012b_B.CalibrationYdegsV;
    } else {
      /* in saturation */
      ((StateDerivatives_q_heli3d_skele *)
        q_heli3d_skeleton_2012b_M->ModelData.derivs)
        ->DesPositionElevationdeg_CSTATE = 0.0;
    }
  }

  /* Derivatives for Integrator: '<S3>/Des Position:  Travel (deg)' */
  _rtXdot->DesPositionTraveldeg_CSTATE =
    q_heli3d_skeleton_2012b_B.CalibrationXdegsV;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( q_heli3d_skeleton_2012b_X.Integrator1_CSTATE[0] <=
            q_heli3d_skeleton_2012b_P.Integrator1_LowerSat );
    usat = ( q_heli3d_skeleton_2012b_X.Integrator1_CSTATE[0] >=
            q_heli3d_skeleton_2012b_P.Integrator1_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (q_heli3d_skeleton_2012b_B.zry_hat[0] > 0)) ||
        (usat && (q_heli3d_skeleton_2012b_B.zry_hat[0] < 0)) ) {
      ((StateDerivatives_q_heli3d_skele *)
        q_heli3d_skeleton_2012b_M->ModelData.derivs)->Integrator1_CSTATE[0] =
        q_heli3d_skeleton_2012b_B.zry_hat[0];
    } else {
      /* in saturation */
      ((StateDerivatives_q_heli3d_skele *)
        q_heli3d_skeleton_2012b_M->ModelData.derivs)->Integrator1_CSTATE[0] =
        0.0;
    }

    lsat = ( q_heli3d_skeleton_2012b_X.Integrator1_CSTATE[1] <=
            q_heli3d_skeleton_2012b_P.Integrator1_LowerSat );
    usat = ( q_heli3d_skeleton_2012b_X.Integrator1_CSTATE[1] >=
            q_heli3d_skeleton_2012b_P.Integrator1_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (q_heli3d_skeleton_2012b_B.zry_hat[1] > 0)) ||
        (usat && (q_heli3d_skeleton_2012b_B.zry_hat[1] < 0)) ) {
      ((StateDerivatives_q_heli3d_skele *)
        q_heli3d_skeleton_2012b_M->ModelData.derivs)->Integrator1_CSTATE[1] =
        q_heli3d_skeleton_2012b_B.zry_hat[1];
    } else {
      /* in saturation */
      ((StateDerivatives_q_heli3d_skele *)
        q_heli3d_skeleton_2012b_M->ModelData.derivs)->Integrator1_CSTATE[1] =
        0.0;
    }
  }

  /* Derivatives for Integrator: '<Root>/Integrator' */
  for (i = 0; i < 6; i++) {
    _rtXdot->Integrator_CSTATE[i] = q_heli3d_skeleton_2012b_B.x_dot[i];
  }

  /* End of Derivatives for Integrator: '<Root>/Integrator' */
  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  {
    ((StateDerivatives_q_heli3d_skele *)
      q_heli3d_skeleton_2012b_M->ModelData.derivs)->TransferFcn_CSTATE =
      q_heli3d_skeleton_2012b_B.InitialElevationrad;
    ((StateDerivatives_q_heli3d_skele *)
      q_heli3d_skeleton_2012b_M->ModelData.derivs)->TransferFcn_CSTATE +=
      (q_heli3d_skeleton_2012b_P.TransferFcn_A)*
      q_heli3d_skeleton_2012b_X.TransferFcn_CSTATE;
  }

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  {
    ((StateDerivatives_q_heli3d_skele *)
      q_heli3d_skeleton_2012b_M->ModelData.derivs)->TransferFcn1_CSTATE =
      q_heli3d_skeleton_2012b_B.EncoderResolutionPitchradcount;
    ((StateDerivatives_q_heli3d_skele *)
      q_heli3d_skeleton_2012b_M->ModelData.derivs)->TransferFcn1_CSTATE +=
      (q_heli3d_skeleton_2012b_P.TransferFcn1_A)*
      q_heli3d_skeleton_2012b_X.TransferFcn1_CSTATE;
  }

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn2' */
  {
    ((StateDerivatives_q_heli3d_skele *)
      q_heli3d_skeleton_2012b_M->ModelData.derivs)->TransferFcn2_CSTATE =
      q_heli3d_skeleton_2012b_B.EncoderResolutionTravelradcount;
    ((StateDerivatives_q_heli3d_skele *)
      q_heli3d_skeleton_2012b_M->ModelData.derivs)->TransferFcn2_CSTATE +=
      (q_heli3d_skeleton_2012b_P.TransferFcn2_A)*
      q_heli3d_skeleton_2012b_X.TransferFcn2_CSTATE;
  }
}

/* Model step function for TID2 */
void q_heli3d_skeleton_2012b_step2(void) /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_GameController_o4;
  real_T rtb_GameController_o5;
  real_T rtb_GameController_o6;

  /* S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: q_heli3d_skeleton_2012b/Desired Position from Joystick/Game Controller (game_controller_block) */
  {
    if (q_heli3d_skeleton_2012b_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll
        (q_heli3d_skeleton_2012b_DWork.GameController_Controller, &state,
         &new_data);
      if (result == 0) {
        rtb_GameController_o4 = state.x;
        rtb_GameController_o5 = state.y;
        rtb_GameController_o6 = state.z;
      }
    } else {
      rtb_GameController_o4 = 0;
      rtb_GameController_o5 = 0;
      rtb_GameController_o6 = 0;
    }
  }

  /* Update for RateTransition: '<S3>/Rate Transition: z' */
  q_heli3d_skeleton_2012b_DWork.RateTransitionz_Buffer0 = rtb_GameController_o6;

  /* Update for RateTransition: '<S3>/Rate Transition: x' */
  q_heli3d_skeleton_2012b_DWork.RateTransitionx_Buffer0 = rtb_GameController_o4;

  /* Update for RateTransition: '<S3>/Rate Transition: y' */
  q_heli3d_skeleton_2012b_DWork.RateTransitiony_Buffer0 = rtb_GameController_o5;
  rtExtModeUpload(2, (((q_heli3d_skeleton_2012b_M->Timing.clockTick2+
                        q_heli3d_skeleton_2012b_M->Timing.clockTickH2*
                        4294967296.0)) * 0.01));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  q_heli3d_skeleton_2012b_M->Timing.clockTick2++;
  if (!q_heli3d_skeleton_2012b_M->Timing.clockTick2) {
    q_heli3d_skeleton_2012b_M->Timing.clockTickH2++;
  }
}

void q_heli3d_skeleton_2012b_step(int_T tid)
{
  switch (tid) {
   case 0 :
    q_heli3d_skeleton_2012b_step0();
    break;

   case 2 :
    q_heli3d_skeleton_2012b_step2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void q_heli3d_skeleton_2012b_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)q_heli3d_skeleton_2012b_M, 0,
                sizeof(RT_MODEL_q_heli3d_skeleton_2012));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&q_heli3d_skeleton_2012b_M->solverInfo,
                          &q_heli3d_skeleton_2012b_M->Timing.simTimeStep);
    rtsiSetTPtr(&q_heli3d_skeleton_2012b_M->solverInfo, &rtmGetTPtr
                (q_heli3d_skeleton_2012b_M));
    rtsiSetStepSizePtr(&q_heli3d_skeleton_2012b_M->solverInfo,
                       &q_heli3d_skeleton_2012b_M->Timing.stepSize0);
    rtsiSetdXPtr(&q_heli3d_skeleton_2012b_M->solverInfo,
                 &q_heli3d_skeleton_2012b_M->ModelData.derivs);
    rtsiSetContStatesPtr(&q_heli3d_skeleton_2012b_M->solverInfo,
                         &q_heli3d_skeleton_2012b_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&q_heli3d_skeleton_2012b_M->solverInfo,
      &q_heli3d_skeleton_2012b_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&q_heli3d_skeleton_2012b_M->solverInfo,
                          (&rtmGetErrorStatus(q_heli3d_skeleton_2012b_M)));
    rtsiSetRTModelPtr(&q_heli3d_skeleton_2012b_M->solverInfo,
                      q_heli3d_skeleton_2012b_M);
  }

  rtsiSetSimTimeStep(&q_heli3d_skeleton_2012b_M->solverInfo, MAJOR_TIME_STEP);
  q_heli3d_skeleton_2012b_M->ModelData.intgData.f[0] =
    q_heli3d_skeleton_2012b_M->ModelData.odeF[0];
  q_heli3d_skeleton_2012b_M->ModelData.contStates = ((real_T *)
    &q_heli3d_skeleton_2012b_X);
  rtsiSetSolverData(&q_heli3d_skeleton_2012b_M->solverInfo, (void *)
                    &q_heli3d_skeleton_2012b_M->ModelData.intgData);
  rtsiSetSolverName(&q_heli3d_skeleton_2012b_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = q_heli3d_skeleton_2012b_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    q_heli3d_skeleton_2012b_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    q_heli3d_skeleton_2012b_M->Timing.sampleTimes =
      (&q_heli3d_skeleton_2012b_M->Timing.sampleTimesArray[0]);
    q_heli3d_skeleton_2012b_M->Timing.offsetTimes =
      (&q_heli3d_skeleton_2012b_M->Timing.offsetTimesArray[0]);

    /* task periods */
    q_heli3d_skeleton_2012b_M->Timing.sampleTimes[0] = (0.0);
    q_heli3d_skeleton_2012b_M->Timing.sampleTimes[1] = (0.002);
    q_heli3d_skeleton_2012b_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    q_heli3d_skeleton_2012b_M->Timing.offsetTimes[0] = (0.0);
    q_heli3d_skeleton_2012b_M->Timing.offsetTimes[1] = (0.0);
    q_heli3d_skeleton_2012b_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(q_heli3d_skeleton_2012b_M,
             &q_heli3d_skeleton_2012b_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = q_heli3d_skeleton_2012b_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      q_heli3d_skeleton_2012b_M->Timing.perTaskSampleHitsArray;
    q_heli3d_skeleton_2012b_M->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    q_heli3d_skeleton_2012b_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(q_heli3d_skeleton_2012b_M, -1);
  q_heli3d_skeleton_2012b_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  q_heli3d_skeleton_2012b_M->Sizes.checksums[0] = (775744822U);
  q_heli3d_skeleton_2012b_M->Sizes.checksums[1] = (1528882478U);
  q_heli3d_skeleton_2012b_M->Sizes.checksums[2] = (142432245U);
  q_heli3d_skeleton_2012b_M->Sizes.checksums[3] = (3958259431U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    q_heli3d_skeleton_2012b_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(q_heli3d_skeleton_2012b_M->extModeInfo,
      &q_heli3d_skeleton_2012b_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(q_heli3d_skeleton_2012b_M->extModeInfo,
                        q_heli3d_skeleton_2012b_M->Sizes.checksums);
    rteiSetTPtr(q_heli3d_skeleton_2012b_M->extModeInfo, rtmGetTPtr
                (q_heli3d_skeleton_2012b_M));
  }

  q_heli3d_skeleton_2012b_M->solverInfoPtr =
    (&q_heli3d_skeleton_2012b_M->solverInfo);
  q_heli3d_skeleton_2012b_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&q_heli3d_skeleton_2012b_M->solverInfo, 0.002);
  rtsiSetSolverMode(&q_heli3d_skeleton_2012b_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  {
    int_T i;
    for (i = 0; i < 6; i++) {
      q_heli3d_skeleton_2012b_B.x[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      q_heli3d_skeleton_2012b_B.x_dot[i] = 0.0;
    }

    q_heli3d_skeleton_2012b_B.SliderGain = 0.0;
    q_heli3d_skeleton_2012b_B.Gain1[0] = 0.0;
    q_heli3d_skeleton_2012b_B.Gain1[1] = 0.0;
    q_heli3d_skeleton_2012b_B.ReferenceGain[0] = 0.0;
    q_heli3d_skeleton_2012b_B.ReferenceGain[1] = 0.0;
    q_heli3d_skeleton_2012b_B.z[0] = 0.0;
    q_heli3d_skeleton_2012b_B.z[1] = 0.0;
    q_heli3d_skeleton_2012b_B.IntegralGain[0] = 0.0;
    q_heli3d_skeleton_2012b_B.IntegralGain[1] = 0.0;
    q_heli3d_skeleton_2012b_B.StateFeedback[0] = 0.0;
    q_heli3d_skeleton_2012b_B.StateFeedback[1] = 0.0;
    q_heli3d_skeleton_2012b_B.ZeroingBias[0] = 0.0;
    q_heli3d_skeleton_2012b_B.ZeroingBias[1] = 0.0;
    q_heli3d_skeleton_2012b_B.DACBLimitV[0] = 0.0;
    q_heli3d_skeleton_2012b_B.DACBLimitV[1] = 0.0;
    q_heli3d_skeleton_2012b_B.AmplifierGain[0] = 0.0;
    q_heli3d_skeleton_2012b_B.AmplifierGain[1] = 0.0;
    q_heli3d_skeleton_2012b_B.EncoderResolutionPitchradcount = 0.0;
    q_heli3d_skeleton_2012b_B.EncoderResolutionTravelradcount = 0.0;
    q_heli3d_skeleton_2012b_B.InitialElevationrad = 0.0;
    q_heli3d_skeleton_2012b_B.y_hat[0] = 0.0;
    q_heli3d_skeleton_2012b_B.y_hat[1] = 0.0;
    q_heli3d_skeleton_2012b_B.y_hat[2] = 0.0;
    q_heli3d_skeleton_2012b_B.Add1[0] = 0.0;
    q_heli3d_skeleton_2012b_B.Add1[1] = 0.0;
    q_heli3d_skeleton_2012b_B.Add1[2] = 0.0;
    q_heli3d_skeleton_2012b_B.y_hat_j[0] = 0.0;
    q_heli3d_skeleton_2012b_B.y_hat_j[1] = 0.0;
    q_heli3d_skeleton_2012b_B.zry_hat[0] = 0.0;
    q_heli3d_skeleton_2012b_B.zry_hat[1] = 0.0;
    q_heli3d_skeleton_2012b_B.TransferFcn = 0.0;
    q_heli3d_skeleton_2012b_B.TransferFcn1 = 0.0;
    q_heli3d_skeleton_2012b_B.TransferFcn2 = 0.0;
    q_heli3d_skeleton_2012b_B.y[0] = 0.0;
    q_heli3d_skeleton_2012b_B.y[1] = 0.0;
    q_heli3d_skeleton_2012b_B.y[2] = 0.0;
    q_heli3d_skeleton_2012b_B.DerivePosition[0] = 0.0;
    q_heli3d_skeleton_2012b_B.DerivePosition[1] = 0.0;
    q_heli3d_skeleton_2012b_B.DerivePosition[2] = 0.0;
    q_heli3d_skeleton_2012b_B.RateTransitionz = 0.0;
    q_heli3d_skeleton_2012b_B.RateTransitionx = 0.0;
    q_heli3d_skeleton_2012b_B.CalibrationXdegsV = 0.0;
    q_heli3d_skeleton_2012b_B.RateTransitiony = 0.0;
    q_heli3d_skeleton_2012b_B.CalibrationYdegsV = 0.0;
    q_heli3d_skeleton_2012b_B.startTime = 0.0;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&q_heli3d_skeleton_2012b_X, 0,
                  sizeof(ContinuousStates_q_heli3d_skele));
  }

  /* states (dwork) */
  (void) memset((void *)&q_heli3d_skeleton_2012b_DWork, 0,
                sizeof(D_Work_q_heli3d_skeleton_2012b));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      q_heli3d_skeleton_2012b_DWork.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      q_heli3d_skeleton_2012b_DWork.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      q_heli3d_skeleton_2012b_DWork.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      q_heli3d_skeleton_2012b_DWork.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      q_heli3d_skeleton_2012b_DWork.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      q_heli3d_skeleton_2012b_DWork.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      q_heli3d_skeleton_2012b_DWork.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      q_heli3d_skeleton_2012b_DWork.HILInitialize_POValues[i] = 0.0;
    }
  }

  q_heli3d_skeleton_2012b_DWork.RateTransitionz_Buffer0 = 0.0;
  q_heli3d_skeleton_2012b_DWork.RateTransitionx_Buffer0 = 0.0;
  q_heli3d_skeleton_2012b_DWork.RateTransitiony_Buffer0 = 0.0;
  q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.TimeStampA = 0.0;
  q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.LastUAtTimeA[0] = 0.0;
  q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.LastUAtTimeA[1] = 0.0;
  q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.LastUAtTimeA[2] = 0.0;
  q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.TimeStampB = 0.0;
  q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.LastUAtTimeB[0] = 0.0;
  q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.LastUAtTimeB[1] = 0.0;
  q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.LastUAtTimeB[2] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    q_heli3d_skeleton_2012b_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  q_heli3d_skeleton_2012b_M->Sizes.numContStates = (13);/* Number of continuous states */
  q_heli3d_skeleton_2012b_M->Sizes.numY = (0);/* Number of model outputs */
  q_heli3d_skeleton_2012b_M->Sizes.numU = (0);/* Number of model inputs */
  q_heli3d_skeleton_2012b_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  q_heli3d_skeleton_2012b_M->Sizes.numSampTimes = (3);/* Number of sample times */
  q_heli3d_skeleton_2012b_M->Sizes.numBlocks = (71);/* Number of blocks */
  q_heli3d_skeleton_2012b_M->Sizes.numBlockIO = (29);/* Number of block outputs */
  q_heli3d_skeleton_2012b_M->Sizes.numBlockPrms = (279);/* Sum of parameter "widths" */

  /* Start for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: q_heli3d_skeleton_2012b/3-DOF Plant/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0",
                      &q_heli3d_skeleton_2012b_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card, "update_rate=normal",
       19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(q_heli3d_skeleton_2012b_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
      return;
    }

    if ((q_heli3d_skeleton_2012b_P.HILInitialize_AIPStart && !is_switching) ||
        (q_heli3d_skeleton_2012b_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = q_heli3d_skeleton_2012b_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = q_heli3d_skeleton_2012b_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
         q_heli3d_skeleton_2012b_P.HILInitialize_AIChannels, 8U,
         &q_heli3d_skeleton_2012b_DWork.HILInitialize_AIMinimums[0],
         &q_heli3d_skeleton_2012b_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
        return;
      }
    }

    if ((q_heli3d_skeleton_2012b_P.HILInitialize_AOPStart && !is_switching) ||
        (q_heli3d_skeleton_2012b_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = q_heli3d_skeleton_2012b_P.HILInitialize_AOLow;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = q_heli3d_skeleton_2012b_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges
        (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
         q_heli3d_skeleton_2012b_P.HILInitialize_AOChannels, 8U,
         &q_heli3d_skeleton_2012b_DWork.HILInitialize_AOMinimums[0],
         &q_heli3d_skeleton_2012b_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
        return;
      }
    }

    if ((q_heli3d_skeleton_2012b_P.HILInitialize_AOStart && !is_switching) ||
        (q_heli3d_skeleton_2012b_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = q_heli3d_skeleton_2012b_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
        q_heli3d_skeleton_2012b_P.HILInitialize_AOChannels, 8U,
        &q_heli3d_skeleton_2012b_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
        return;
      }
    }

    if (q_heli3d_skeleton_2012b_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = q_heli3d_skeleton_2012b_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
         q_heli3d_skeleton_2012b_P.HILInitialize_AOChannels, 8U,
         &q_heli3d_skeleton_2012b_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
       q_heli3d_skeleton_2012b_P.HILInitialize_DIChannels, 4U,
       q_heli3d_skeleton_2012b_P.HILInitialize_DOChannels, 4U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
      return;
    }

    if ((q_heli3d_skeleton_2012b_P.HILInitialize_DOStart && !is_switching) ||
        (q_heli3d_skeleton_2012b_P.HILInitialize_DOEnter && is_switching)) {
      q_heli3d_skeleton_2012b_DWork.HILInitialize_DOBits[0] =
        q_heli3d_skeleton_2012b_P.HILInitialize_DOInitial;
      q_heli3d_skeleton_2012b_DWork.HILInitialize_DOBits[1] =
        q_heli3d_skeleton_2012b_P.HILInitialize_DOInitial;
      q_heli3d_skeleton_2012b_DWork.HILInitialize_DOBits[2] =
        q_heli3d_skeleton_2012b_P.HILInitialize_DOInitial;
      q_heli3d_skeleton_2012b_DWork.HILInitialize_DOBits[3] =
        q_heli3d_skeleton_2012b_P.HILInitialize_DOInitial;
      result = hil_write_digital
        (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
         q_heli3d_skeleton_2012b_P.HILInitialize_DOChannels, 4U, (t_boolean *)
         &q_heli3d_skeleton_2012b_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
        return;
      }
    }

    if (q_heli3d_skeleton_2012b_P.HILInitialize_DOReset) {
      q_heli3d_skeleton_2012b_DWork.HILInitialize_DOStates[0] =
        q_heli3d_skeleton_2012b_P.HILInitialize_DOWatchdog;
      q_heli3d_skeleton_2012b_DWork.HILInitialize_DOStates[1] =
        q_heli3d_skeleton_2012b_P.HILInitialize_DOWatchdog;
      q_heli3d_skeleton_2012b_DWork.HILInitialize_DOStates[2] =
        q_heli3d_skeleton_2012b_P.HILInitialize_DOWatchdog;
      q_heli3d_skeleton_2012b_DWork.HILInitialize_DOStates[3] =
        q_heli3d_skeleton_2012b_P.HILInitialize_DOWatchdog;
      result = hil_watchdog_set_digital_expiration_state
        (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
         q_heli3d_skeleton_2012b_P.HILInitialize_DOChannels, 4U, (const
          t_digital_state *)
         &q_heli3d_skeleton_2012b_DWork.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
        return;
      }
    }

    if ((q_heli3d_skeleton_2012b_P.HILInitialize_EIPStart && !is_switching) ||
        (q_heli3d_skeleton_2012b_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] =
            q_heli3d_skeleton_2012b_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
         q_heli3d_skeleton_2012b_P.HILInitialize_EIChannels, 8U,
         (t_encoder_quadrature_mode *)
         &q_heli3d_skeleton_2012b_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
        return;
      }
    }

    if ((q_heli3d_skeleton_2012b_P.HILInitialize_EIStart && !is_switching) ||
        (q_heli3d_skeleton_2012b_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            q_heli3d_skeleton_2012b_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts
        (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
         q_heli3d_skeleton_2012b_P.HILInitialize_EIChannels, 8U,
         &q_heli3d_skeleton_2012b_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
        return;
      }
    }

    if ((q_heli3d_skeleton_2012b_P.HILInitialize_POPStart && !is_switching) ||
        (q_heli3d_skeleton_2012b_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = q_heli3d_skeleton_2012b_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
        q_heli3d_skeleton_2012b_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &q_heli3d_skeleton_2012b_DWork.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          q_heli3d_skeleton_2012b_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            q_heli3d_skeleton_2012b_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            q_heli3d_skeleton_2012b_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = q_heli3d_skeleton_2012b_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            q_heli3d_skeleton_2012b_DWork.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            q_heli3d_skeleton_2012b_DWork.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              q_heli3d_skeleton_2012b_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency
          (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
           &q_heli3d_skeleton_2012b_DWork.HILInitialize_POSortedChans[0],
           num_duty_cycle_modes,
           &q_heli3d_skeleton_2012b_DWork.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
           &q_heli3d_skeleton_2012b_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes],
           num_frequency_modes,
           &q_heli3d_skeleton_2012b_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            q_heli3d_skeleton_2012b_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] =
            q_heli3d_skeleton_2012b_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] =
            q_heli3d_skeleton_2012b_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration
        (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
         q_heli3d_skeleton_2012b_P.HILInitialize_POChannels, 8U,
         (t_pwm_configuration *)
         &q_heli3d_skeleton_2012b_DWork.HILInitialize_POModeValues[0],
         (t_pwm_alignment *)
         &q_heli3d_skeleton_2012b_DWork.HILInitialize_POAlignValues[0],
         (t_pwm_polarity *)
         &q_heli3d_skeleton_2012b_DWork.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] =
            q_heli3d_skeleton_2012b_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = q_heli3d_skeleton_2012b_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband
        (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
         q_heli3d_skeleton_2012b_P.HILInitialize_POChannels, 8U,
         &q_heli3d_skeleton_2012b_DWork.HILInitialize_POSortedFreqs[0],
         &q_heli3d_skeleton_2012b_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
        return;
      }
    }

    if ((q_heli3d_skeleton_2012b_P.HILInitialize_POStart && !is_switching) ||
        (q_heli3d_skeleton_2012b_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = q_heli3d_skeleton_2012b_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
        q_heli3d_skeleton_2012b_P.HILInitialize_POChannels, 8U,
        &q_heli3d_skeleton_2012b_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
        return;
      }
    }

    if (q_heli3d_skeleton_2012b_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = q_heli3d_skeleton_2012b_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
         q_heli3d_skeleton_2012b_P.HILInitialize_POChannels, 8U,
         &q_heli3d_skeleton_2012b_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S1>/HIL Read Encoder Timebase' */

  /* S-Function Block: q_heli3d_skeleton_2012b/3-DOF Plant/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
       q_heli3d_skeleton_2012b_P.HILReadEncoderTimebase_SamplesI,
       q_heli3d_skeleton_2012b_P.HILReadEncoderTimebase_Channels, 3,
       &q_heli3d_skeleton_2012b_DWork.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S3>/Rate Transition: z' */
  q_heli3d_skeleton_2012b_B.RateTransitionz =
    q_heli3d_skeleton_2012b_P.RateTransitionz_X0;

  /* Start for RateTransition: '<S3>/Rate Transition: x' */
  q_heli3d_skeleton_2012b_B.RateTransitionx =
    q_heli3d_skeleton_2012b_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S3>/Rate Transition: y' */
  q_heli3d_skeleton_2012b_B.RateTransitiony =
    q_heli3d_skeleton_2012b_P.RateTransitiony_X0;

  /* Start for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: q_heli3d_skeleton_2012b/Desired Position from Joystick/Game Controller (game_controller_block) */
  {
    if (q_heli3d_skeleton_2012b_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open
        (q_heli3d_skeleton_2012b_P.GameController_ControllerNumber,
         q_heli3d_skeleton_2012b_P.GameController_BufferSize, deadzone,
         saturation, q_heli3d_skeleton_2012b_P.GameController_AutoCenter, 0, 1.0,
         &q_heli3d_skeleton_2012b_DWork.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
      }
    }
  }

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<S3>/Des Position:  Elevation (deg)' */
    q_heli3d_skeleton_2012b_X.DesPositionElevationdeg_CSTATE =
      q_heli3d_skeleton_2012b_P.DesPositionElevationdeg_IC;

    /* InitializeConditions for Integrator: '<S3>/Des Position:  Travel (deg)' */
    q_heli3d_skeleton_2012b_X.DesPositionTraveldeg_CSTATE =
      q_heli3d_skeleton_2012b_P.DesPositionTraveldeg_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator1' */
    q_heli3d_skeleton_2012b_X.Integrator1_CSTATE[0] =
      q_heli3d_skeleton_2012b_P.Integrator1_IC;
    q_heli3d_skeleton_2012b_X.Integrator1_CSTATE[1] =
      q_heli3d_skeleton_2012b_P.Integrator1_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    for (i = 0; i < 6; i++) {
      q_heli3d_skeleton_2012b_X.Integrator_CSTATE[i] =
        q_heli3d_skeleton_2012b_P.Integrator_IC;
    }

    /* End of InitializeConditions for Integrator: '<Root>/Integrator' */
    /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
    q_heli3d_skeleton_2012b_X.TransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
    q_heli3d_skeleton_2012b_X.TransferFcn1_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2' */
    q_heli3d_skeleton_2012b_X.TransferFcn2_CSTATE = 0.0;

    /* InitializeConditions for Derivative: '<Root>/Derive Position' */
    q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.TimeStampA = rtInf;
    q_heli3d_skeleton_2012b_DWork.DerivePosition_RWORK.TimeStampB = rtInf;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: z' */
    q_heli3d_skeleton_2012b_DWork.RateTransitionz_Buffer0 =
      q_heli3d_skeleton_2012b_P.RateTransitionz_X0;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: x' */
    q_heli3d_skeleton_2012b_DWork.RateTransitionx_Buffer0 =
      q_heli3d_skeleton_2012b_P.RateTransitionx_X0;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: y' */
    q_heli3d_skeleton_2012b_DWork.RateTransitiony_Buffer0 =
      q_heli3d_skeleton_2012b_P.RateTransitiony_X0;
  }
}

/* Model terminate function */
void q_heli3d_skeleton_2012b_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: q_heli3d_skeleton_2012b/3-DOF Plant/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(q_heli3d_skeleton_2012b_DWork.HILInitialize_Card);
    hil_monitor_stop_all(q_heli3d_skeleton_2012b_DWork.HILInitialize_Card);
    is_switching = false;
    if ((q_heli3d_skeleton_2012b_P.HILInitialize_AOTerminate && !is_switching) ||
        (q_heli3d_skeleton_2012b_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = q_heli3d_skeleton_2012b_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((q_heli3d_skeleton_2012b_P.HILInitialize_DOTerminate && !is_switching) ||
        (q_heli3d_skeleton_2012b_P.HILInitialize_DOExit && is_switching)) {
      q_heli3d_skeleton_2012b_DWork.HILInitialize_DOBits[0] =
        q_heli3d_skeleton_2012b_P.HILInitialize_DOFinal;
      q_heli3d_skeleton_2012b_DWork.HILInitialize_DOBits[1] =
        q_heli3d_skeleton_2012b_P.HILInitialize_DOFinal;
      q_heli3d_skeleton_2012b_DWork.HILInitialize_DOBits[2] =
        q_heli3d_skeleton_2012b_P.HILInitialize_DOFinal;
      q_heli3d_skeleton_2012b_DWork.HILInitialize_DOBits[3] =
        q_heli3d_skeleton_2012b_P.HILInitialize_DOFinal;
      num_final_digital_outputs = 4U;
    }

    if ((q_heli3d_skeleton_2012b_P.HILInitialize_POTerminate && !is_switching) ||
        (q_heli3d_skeleton_2012b_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues =
          &q_heli3d_skeleton_2012b_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = q_heli3d_skeleton_2012b_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        || num_final_digital_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(q_heli3d_skeleton_2012b_DWork.HILInitialize_Card
                         , q_heli3d_skeleton_2012b_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , q_heli3d_skeleton_2012b_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , q_heli3d_skeleton_2012b_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , NULL, 0
                         ,
                         &q_heli3d_skeleton_2012b_DWork.HILInitialize_AOVoltages[
                         0]
                         ,
                         &q_heli3d_skeleton_2012b_DWork.HILInitialize_POValues[0]
                         , (t_boolean *)
                         &q_heli3d_skeleton_2012b_DWork.HILInitialize_DOBits[0]
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
             q_heli3d_skeleton_2012b_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &q_heli3d_skeleton_2012b_DWork.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm
            (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
             q_heli3d_skeleton_2012b_P.HILInitialize_POChannels,
             num_final_pwm_outputs,
             &q_heli3d_skeleton_2012b_DWork.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (q_heli3d_skeleton_2012b_DWork.HILInitialize_Card,
             q_heli3d_skeleton_2012b_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &q_heli3d_skeleton_2012b_DWork.HILInitialize_DOBits[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(q_heli3d_skeleton_2012b_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(q_heli3d_skeleton_2012b_DWork.HILInitialize_Card);
    hil_monitor_delete_all(q_heli3d_skeleton_2012b_DWork.HILInitialize_Card);
    hil_close(q_heli3d_skeleton_2012b_DWork.HILInitialize_Card);
    q_heli3d_skeleton_2012b_DWork.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: q_heli3d_skeleton_2012b/Desired Position from Joystick/Game Controller (game_controller_block) */
  {
    if (q_heli3d_skeleton_2012b_P.GameController_Enabled) {
      game_controller_close
        (q_heli3d_skeleton_2012b_DWork.GameController_Controller);
      q_heli3d_skeleton_2012b_DWork.GameController_Controller = NULL;
    }
  }
}
