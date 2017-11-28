/*
 * plant_block_swing_catch.c
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
#include "plant_block_swing_catch_dt.h"

/* Named constants for Chart: '<S5>/State Switch v1' */
#define plant_block__IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define plant_block_swing_ca_CALL_EVENT (-1)
#define plant_block_swing_ca_IN_ReSwing ((uint8_T)2U)
#define plant_block_swing_catc_IN_Catch ((uint8_T)1U)
#define plant_block_swing_catc_IN_Swing ((uint8_T)4U)
#define plant_block_swing_catch_IN_Rest ((uint8_T)3U)

/* list of Real-Time Windows Target timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.008, 0.0,
};

/* Block signals (auto storage) */
B_plant_block_swing_catch_T plant_block_swing_catch_B;

/* Continuous states */
X_plant_block_swing_catch_T plant_block_swing_catch_X;

/* Block states (auto storage) */
DW_plant_block_swing_catch_T plant_block_swing_catch_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_plant_block_swing_catch_T plant_block_swing_catch_PrevZCX;

/* Real-time model */
RT_MODEL_plant_block_swing_catch_T plant_block_swing_catch_M_;
RT_MODEL_plant_block_swing_catch_T *const plant_block_swing_catch_M =
  &plant_block_swing_catch_M_;

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
  int_T nXc = 15;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  plant_block_swing_catch_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = -0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  if (u1 == 0.0) {
    y = u0;
  } else if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf
                (u1))))) {
    y = (rtNaN);
  } else {
    tmp = u0 / u1;
    if (u1 <= floor(u1)) {
      y = u0 - floor(tmp) * u1;
    } else {
      if (fabs(tmp - rt_roundd_snf(tmp)) <= DBL_EPSILON * fabs(tmp)) {
        y = 0.0;
      } else {
        y = (tmp - floor(tmp)) * u1;
      }
    }
  }

  return y;
}

/* Model output function */
void plant_block_swing_catch_output(void)
{
  /* local block i/o variables */
  real_T rtb_Filter;
  real_T rtb_Integrator;
  real_T rtb_Sum;
  real_T rtb_SliderGain;
  real_T rtb_SliderGain_o;
  real_T rtb_SliderGain_k;
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    /* set solver stop time */
    if (!(plant_block_swing_catch_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&plant_block_swing_catch_M->solverInfo,
                            ((plant_block_swing_catch_M->Timing.clockTickH0 + 1)
        * plant_block_swing_catch_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&plant_block_swing_catch_M->solverInfo,
                            ((plant_block_swing_catch_M->Timing.clockTick0 + 1) *
        plant_block_swing_catch_M->Timing.stepSize0 +
        plant_block_swing_catch_M->Timing.clockTickH0 *
        plant_block_swing_catch_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(plant_block_swing_catch_M)) {
    plant_block_swing_catch_M->Timing.t[0] = rtsiGetT
      (&plant_block_swing_catch_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    /* Level2 S-Function Block: '<S1>/S-Function' (ECPDSPDriver) */
    {
      SimStruct *rts = plant_block_swing_catch_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<Root>/Gain1' */
    plant_block_swing_catch_B.theta = plant_block_swing_catch_P.Gain1_Gain *
      plant_block_swing_catch_B.SFunction[2];

    /* Math: '<S5>/theta correction1' incorporates:
     *  Abs: '<S5>/Abs'
     *  Constant: '<S5>/Constant4'
     */
    plant_block_swing_catch_B.thetacorrection1 = rt_modd_snf(fabs
      (plant_block_swing_catch_B.theta),
      plant_block_swing_catch_P.Constant4_Value);
  }

  /* Derivative: '<Root>/Derivative1' */
  {
    real_T t = plant_block_swing_catch_M->Timing.t[0];
    real_T timeStampA = plant_block_swing_catch_DW.Derivative1_RWORK.TimeStampA;
    real_T timeStampB = plant_block_swing_catch_DW.Derivative1_RWORK.TimeStampB;
    real_T *lastU = &plant_block_swing_catch_DW.Derivative1_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      plant_block_swing_catch_B.theta_dot = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &plant_block_swing_catch_DW.Derivative1_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative1_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      plant_block_swing_catch_B.theta_dot = (plant_block_swing_catch_B.theta -
        *lastU++) / deltaT;
    }
  }

  /* Abs: '<S5>/Abs1' */
  plant_block_swing_catch_B.Abs1 = fabs(plant_block_swing_catch_B.theta_dot);
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    /* Chart: '<S5>/State Switch v1' */
    /* Gateway: State Selection/State Switch v1 */
    plant_block_swing_catch_DW.sfEvent = plant_block_swing_ca_CALL_EVENT;

    /* During: State Selection/State Switch v1 */
    if (plant_block_swing_catch_DW.is_active_c3_plant_block_swing_ == 0U) {
      /* Entry: State Selection/State Switch v1 */
      plant_block_swing_catch_DW.is_active_c3_plant_block_swing_ = 1U;

      /* Entry Internal: State Selection/State Switch v1 */
      /* Transition: '<S12>:2' */
      plant_block_swing_catch_DW.is_c3_plant_block_swing_catch =
        plant_block_swing_catch_IN_Rest;

      /* Entry 'Rest': '<S12>:1' */
      plant_block_swing_catch_B.x = 1.0;
      plant_block_swing_catch_B.y = 0.0;
      plant_block_swing_catch_B.z = 0.0;
      plant_block_swing_catch_B.r = 0.0;
    } else {
      switch (plant_block_swing_catch_DW.is_c3_plant_block_swing_catch) {
       case plant_block_swing_catc_IN_Catch:
        /* During 'Catch': '<S12>:6' */
        if ((plant_block_swing_catch_B.Abs1 > 8.0) &&
            (plant_block_swing_catch_B.thetacorrection1 > 2.748893571891069) &&
            (plant_block_swing_catch_B.thetacorrection1 < 3.5342917352885173)) {
          /* Transition: '<S12>:34' */
          plant_block_swing_catch_DW.is_c3_plant_block_swing_catch =
            plant_block_swing_ca_IN_ReSwing;

          /* Entry 'ReSwing': '<S12>:33' */
          plant_block_swing_catch_B.x = 1.0;
          plant_block_swing_catch_B.y = 0.0;
          plant_block_swing_catch_B.z = 0.0;
          plant_block_swing_catch_B.r = 1.0;
        } else {
          if ((plant_block_swing_catch_B.thetacorrection1 < 2.826) ||
              (plant_block_swing_catch_B.thetacorrection1 > 3.454)) {
            /* Transition: '<S12>:7' */
            plant_block_swing_catch_DW.is_c3_plant_block_swing_catch =
              plant_block_swing_ca_IN_ReSwing;

            /* Entry 'ReSwing': '<S12>:33' */
            plant_block_swing_catch_B.x = 1.0;
            plant_block_swing_catch_B.y = 0.0;
            plant_block_swing_catch_B.z = 0.0;
            plant_block_swing_catch_B.r = 1.0;
          }
        }
        break;

       case plant_block_swing_ca_IN_ReSwing:
        /* During 'ReSwing': '<S12>:33' */
        if ((plant_block_swing_catch_B.Abs1 < 2.0) &&
            ((plant_block_swing_catch_B.thetacorrection1 < 0.78539816339744828) ||
             (plant_block_swing_catch_B.thetacorrection1 > 5.497787143782138)))
        {
          /* Transition: '<S12>:35' */
          plant_block_swing_catch_DW.is_c3_plant_block_swing_catch =
            plant_block_swing_catc_IN_Swing;

          /* Entry 'Swing': '<S12>:5' */
          plant_block_swing_catch_B.x = 0.0;
          plant_block_swing_catch_B.y = 1.0;
          plant_block_swing_catch_B.z = 0.0;
          plant_block_swing_catch_B.r = 0.0;
        }
        break;

       case plant_block_swing_catch_IN_Rest:
        /* During 'Rest': '<S12>:1' */
        if ((plant_block_swing_catch_B.thetacorrection1 > 0.12) &&
            (plant_block_swing_catch_B.Abs1 > 0.12)) {
          /* Transition: '<S12>:13' */
          plant_block_swing_catch_DW.is_c3_plant_block_swing_catch =
            plant_block_swing_catc_IN_Swing;

          /* Entry 'Swing': '<S12>:5' */
          plant_block_swing_catch_B.x = 0.0;
          plant_block_swing_catch_B.y = 1.0;
          plant_block_swing_catch_B.z = 0.0;
          plant_block_swing_catch_B.r = 0.0;
        }
        break;

       default:
        /* During 'Swing': '<S12>:5' */
        if ((2.826 < plant_block_swing_catch_B.thetacorrection1) &&
            (plant_block_swing_catch_B.thetacorrection1 < 3.454)) {
          /* Transition: '<S12>:8' */
          plant_block_swing_catch_DW.is_c3_plant_block_swing_catch =
            plant_block_swing_catc_IN_Catch;

          /* Entry 'Catch': '<S12>:6' */
          plant_block_swing_catch_B.x = 0.0;
          plant_block_swing_catch_B.y = 0.0;
          plant_block_swing_catch_B.z = 1.0;
          plant_block_swing_catch_B.r = 0.0;
        } else {
          if ((plant_block_swing_catch_B.thetacorrection1 < 0.12) &&
              (plant_block_swing_catch_B.Abs1 < 0.12)) {
            /* Transition: '<S12>:12' */
            plant_block_swing_catch_DW.is_c3_plant_block_swing_catch =
              plant_block_swing_catch_IN_Rest;

            /* Entry 'Rest': '<S12>:1' */
            plant_block_swing_catch_B.x = 1.0;
            plant_block_swing_catch_B.y = 0.0;
            plant_block_swing_catch_B.z = 0.0;
            plant_block_swing_catch_B.r = 0.0;
          }
        }
        break;
      }
    }

    /* End of Chart: '<S5>/State Switch v1' */
  }

  /* TransferFcn: '<Root>/Low Pass Filter Fly Wheel4' */
  rtb_Sum = plant_block_swing_catch_P.LowPassFilterFlyWheel4_C*
    plant_block_swing_catch_X.LowPassFilterFlyWheel4_CSTATE;

  /* Math: '<Root>/theta correction2' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  rtb_Sum = rt_modd_snf(rtb_Sum, plant_block_swing_catch_P.Constant1_Value);

  /* Sum: '<Root>/Add2' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  plant_block_swing_catch_B.Add2 = rtb_Sum -
    plant_block_swing_catch_P.Constant2_Value;
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
  }

  /* TransferFcn: '<Root>/Low Pass Filter Fly Wheel6' */
  rtb_Sum = plant_block_swing_catch_P.LowPassFilterFlyWheel6_C*
    plant_block_swing_catch_X.LowPassFilterFlyWheel6_CSTATE;

  /* Gain: '<S13>/Slider Gain' */
  rtb_SliderGain = plant_block_swing_catch_P.SliderGain_Gain * rtb_Sum;

  /* TransferFcn: '<Root>/Low Pass Filter Fly Wheel5' */
  plant_block_swing_catch_B.LowPassFilterFlyWheel5 =
    plant_block_swing_catch_P.LowPassFilterFlyWheel5_C*
    plant_block_swing_catch_X.LowPassFilterFlyWheel5_CSTATE;

  /* Derivative: '<Root>/Derivative4' */
  {
    real_T t = plant_block_swing_catch_M->Timing.t[0];
    real_T timeStampA = plant_block_swing_catch_DW.Derivative4_RWORK.TimeStampA;
    real_T timeStampB = plant_block_swing_catch_DW.Derivative4_RWORK.TimeStampB;
    real_T *lastU = &plant_block_swing_catch_DW.Derivative4_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      rtb_Sum = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &plant_block_swing_catch_DW.Derivative4_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative4_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      rtb_Sum = (plant_block_swing_catch_B.LowPassFilterFlyWheel5 - *lastU++) /
        deltaT;
    }
  }

  /* Gain: '<S14>/Slider Gain' */
  rtb_SliderGain_o = plant_block_swing_catch_P.SliderGain_Gain_n * rtb_Sum;

  /* Gain: '<S15>/Slider Gain' */
  rtb_SliderGain_k = plant_block_swing_catch_P.SliderGain_Gain_a *
    plant_block_swing_catch_B.Add2;

  /* TransferFcn: '<Root>/Low Pass Filter Fly Wheel3' */
  plant_block_swing_catch_B.LowPassFilterFlyWheel3 =
    plant_block_swing_catch_P.LowPassFilterFlyWheel3_C*
    plant_block_swing_catch_X.LowPassFilterFlyWheel3_CSTATE;

  /* Derivative: '<Root>/Derivative5' */
  {
    real_T t = plant_block_swing_catch_M->Timing.t[0];
    real_T timeStampA = plant_block_swing_catch_DW.Derivative5_RWORK.TimeStampA;
    real_T timeStampB = plant_block_swing_catch_DW.Derivative5_RWORK.TimeStampB;
    real_T *lastU = &plant_block_swing_catch_DW.Derivative5_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      rtb_Sum = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &plant_block_swing_catch_DW.Derivative5_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative5_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      rtb_Sum = (plant_block_swing_catch_B.LowPassFilterFlyWheel3 - *lastU++) /
        deltaT;
    }
  }

  /* Product: '<Root>/Product2' incorporates:
   *  Gain: '<S16>/Slider Gain'
   *  Gain: '<S6>/Gain4'
   *  Sum: '<S6>/Add'
   */
  plant_block_swing_catch_B.Product2 = (((rtb_SliderGain + rtb_SliderGain_o) +
    rtb_SliderGain_k) + plant_block_swing_catch_P.SliderGain_Gain_c * rtb_Sum) *
    plant_block_swing_catch_P.Gain4_Gain * plant_block_swing_catch_B.z;
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
  }

  /* TransferFcn: '<S2>/Low Pass Filter Fly Wheel' */
  plant_block_swing_catch_B.LowPassFilterFlyWheel =
    plant_block_swing_catch_P.LowPassFilterFlyWheel_C*
    plant_block_swing_catch_X.LowPassFilterFlyWheel_CSTATE;

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S2>/Desired rpm'
   */
  rtb_Sum = plant_block_swing_catch_P.Desiredrpm_Value -
    plant_block_swing_catch_B.LowPassFilterFlyWheel;

  /* Integrator: '<S8>/Integrator' */
  rtb_Filter = plant_block_swing_catch_X.Integrator_CSTATE;

  /* Integrator: '<S8>/Filter' */
  rtb_Integrator = plant_block_swing_catch_X.Filter_CSTATE;

  /* Gain: '<S8>/Filter Coefficient' incorporates:
   *  Gain: '<S8>/Derivative Gain'
   *  Sum: '<S8>/SumD'
   */
  plant_block_swing_catch_B.FilterCoefficient =
    (plant_block_swing_catch_P.DerivativeGain_Gain * rtb_Sum - rtb_Integrator) *
    plant_block_swing_catch_P.FilterCoefficient_Gain;

  /* Sum: '<S8>/Sum' incorporates:
   *  Gain: '<S8>/Proportional Gain'
   */
  rtb_Filter = (plant_block_swing_catch_P.ProportionalGain_Gain * rtb_Sum +
                rtb_Filter) + plant_block_swing_catch_B.FilterCoefficient;

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Filter >= plant_block_swing_catch_P.Saturation_UpperSat) {
    plant_block_swing_catch_B.Saturation =
      plant_block_swing_catch_P.Saturation_UpperSat;
  } else if (rtb_Filter <= plant_block_swing_catch_P.Saturation_LowerSat) {
    plant_block_swing_catch_B.Saturation =
      plant_block_swing_catch_P.Saturation_LowerSat;
  } else {
    plant_block_swing_catch_B.Saturation = rtb_Filter;
  }

  /* End of Saturate: '<S2>/Saturation' */
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    /* Gain: '<Root>/Gain' */
    plant_block_swing_catch_B.Gain = plant_block_swing_catch_P.Gain_Gain *
      plant_block_swing_catch_B.SFunction[1];
  }

  /* Derivative: '<Root>/Derivative6' */
  {
    real_T t = plant_block_swing_catch_M->Timing.t[0];
    real_T timeStampA = plant_block_swing_catch_DW.Derivative6_RWORK.TimeStampA;
    real_T timeStampB = plant_block_swing_catch_DW.Derivative6_RWORK.TimeStampB;
    real_T *lastU = &plant_block_swing_catch_DW.Derivative6_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      plant_block_swing_catch_B.Derivative6 = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &plant_block_swing_catch_DW.Derivative6_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative6_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      plant_block_swing_catch_B.Derivative6 = (plant_block_swing_catch_B.Gain - *
        lastU++) / deltaT;
    }
  }

  /* TransferFcn: '<Root>/Low Pass Filter Gimble Velocity' */
  plant_block_swing_catch_B.ActualGimbleVelocity =
    plant_block_swing_catch_P.LowPassFilterGimbleVelocity_C*
    plant_block_swing_catch_X.LowPassFilterGimbleVelocity_CST;
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
  }

  /* TransferFcn: '<S7>/Transfer Fcn' */
  plant_block_swing_catch_B.TransferFcn =
    plant_block_swing_catch_P.TransferFcn_C*
    plant_block_swing_catch_X.TransferFcn_CSTATE;

  /* Gain: '<S18>/Proportional Gain' */
  rtb_SliderGain = plant_block_swing_catch_P.ProportionalGain_Gain_n *
    plant_block_swing_catch_B.TransferFcn;

  /* Integrator: '<S18>/Integrator' */
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
                       &plant_block_swing_catch_PrevZCX.Integrator_Reset_ZCE,
                       plant_block_swing_catch_B.y);

    /* evaluate zero-crossings */
    if (zcEvent) {
      plant_block_swing_catch_X.Integrator_CSTATE_m =
        plant_block_swing_catch_P.Integrator_IC_b;
    }
  }

  rtb_Integrator = plant_block_swing_catch_X.Integrator_CSTATE_m;

  /* Gain: '<S18>/Derivative Gain' */
  rtb_SliderGain_o = plant_block_swing_catch_P.DerivativeGain_Gain_l *
    plant_block_swing_catch_B.TransferFcn;

  /* Integrator: '<S18>/Filter' */
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(FALLING_ZERO_CROSSING,
                       &plant_block_swing_catch_PrevZCX.Filter_Reset_ZCE,
                       plant_block_swing_catch_B.y);

    /* evaluate zero-crossings */
    if (zcEvent) {
      plant_block_swing_catch_X.Filter_CSTATE_f =
        plant_block_swing_catch_P.Filter_IC_m;
    }
  }

  rtb_Filter = plant_block_swing_catch_X.Filter_CSTATE_f;

  /* Gain: '<S18>/Filter Coefficient' incorporates:
   *  Sum: '<S18>/SumD'
   */
  plant_block_swing_catch_B.FilterCoefficient_a = (rtb_SliderGain_o - rtb_Filter)
    * plant_block_swing_catch_P.FilterCoefficient_Gain_e;

  /* Sum: '<S18>/Sum' */
  plant_block_swing_catch_B.Sum = (rtb_SliderGain + rtb_Integrator) +
    plant_block_swing_catch_B.FilterCoefficient_a;

  /* TransferFcn: '<Root>/Low Pass Filter Fly Wheel2' */
  plant_block_swing_catch_B.LowPassFilterFlyWheel2 =
    plant_block_swing_catch_P.LowPassFilterFlyWheel2_C*
    plant_block_swing_catch_X.LowPassFilterFlyWheel2_CSTATE;

  /* Gain: '<S7>/Gain' incorporates:
   *  Math: '<S7>/Math Function'
   *
   * About '<S7>/Math Function':
   *  Operator: magnitude^2
   */
  rtb_SliderGain = plant_block_swing_catch_B.LowPassFilterFlyWheel2 *
    plant_block_swing_catch_B.LowPassFilterFlyWheel2 *
    plant_block_swing_catch_P.Gain_Gain_h;

  /* TransferFcn: '<Root>/Low Pass Filter Fly Wheel1' */
  plant_block_swing_catch_B.LowPassFilterFlyWheel1 =
    plant_block_swing_catch_P.LowPassFilterFlyWheel1_C*
    plant_block_swing_catch_X.LowPassFilterFlyWheel1_CSTATE;

  /* Sum: '<S7>/Sum' incorporates:
   *  Constant: '<S7>/Constant'
   *  Gain: '<S7>/Gain2'
   *  Sum: '<S7>/Sum1'
   *  Trigonometry: '<S7>/Trigonometric Function'
   */
  plant_block_swing_catch_B.E = (cos
    (plant_block_swing_catch_B.LowPassFilterFlyWheel1) +
    plant_block_swing_catch_P.Constant_Value) *
    plant_block_swing_catch_P.Gain2_Gain + rtb_SliderGain;

  /* Product: '<S7>/Product2' incorporates:
   *  Product: '<S7>/Product1'
   *  Trigonometry: '<S7>/Trigonometric Function1'
   */
  plant_block_swing_catch_B.Product2_b = plant_block_swing_catch_B.E * cos
    (plant_block_swing_catch_B.LowPassFilterFlyWheel1) *
    plant_block_swing_catch_B.LowPassFilterFlyWheel2;

  /* Gain: '<S7>/Table Acceleration to Gimble Velocity' incorporates:
   *  Product: '<S7>/Product3'
   */
  plant_block_swing_catch_B.w_2 = plant_block_swing_catch_B.Sum *
    plant_block_swing_catch_B.Product2_b *
    plant_block_swing_catch_P.TableAccelerationtoGimbleVeloci;

  /* Product: '<Root>/Enable Swing Velocity' */
  plant_block_swing_catch_B.EnableSwingVelocity = plant_block_swing_catch_B.w_2 *
    plant_block_swing_catch_B.y;

  /* Sum: '<S3>/Add3' */
  rtb_Integrator = (plant_block_swing_catch_B.Product2 -
                    plant_block_swing_catch_B.ActualGimbleVelocity) +
    plant_block_swing_catch_B.EnableSwingVelocity;

  /* Product: '<S3>/Product' */
  plant_block_swing_catch_B.Product = plant_block_swing_catch_B.z *
    rtb_Integrator;

  /* Gain: '<S11>/Slider Gain' */
  plant_block_swing_catch_B.SliderGain =
    plant_block_swing_catch_P.SliderGain_Gain_e *
    plant_block_swing_catch_B.Product;
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    /* Abs: '<S3>/Abs' incorporates:
     *  Constant: '<S3>/Constant'
     *  Sum: '<S3>/Add1'
     */
    plant_block_swing_catch_B.Abs = fabs
      (plant_block_swing_catch_P.Constant_Value_d - plant_block_swing_catch_B.z);
  }

  /* Product: '<S3>/Product1' */
  plant_block_swing_catch_B.Product1 = rtb_Integrator *
    plant_block_swing_catch_B.Abs;

  /* Integrator: '<S10>/Integrator' */
  rtb_Integrator = plant_block_swing_catch_X.Integrator_CSTATE_k;

  /* Integrator: '<S10>/Filter' */
  rtb_Filter = plant_block_swing_catch_X.Filter_CSTATE_o;

  /* Gain: '<S10>/Filter Coefficient' incorporates:
   *  Gain: '<S10>/Derivative Gain'
   *  Sum: '<S10>/SumD'
   */
  plant_block_swing_catch_B.FilterCoefficient_p =
    (plant_block_swing_catch_P.DerivativeGain_Gain_n *
     plant_block_swing_catch_B.Product1 - rtb_Filter) *
    plant_block_swing_catch_P.FilterCoefficient_Gain_f;

  /* Sum: '<S10>/Sum' incorporates:
   *  Gain: '<S10>/Proportional Gain'
   */
  plant_block_swing_catch_B.Sum_o =
    (plant_block_swing_catch_P.ProportionalGain_Gain_i *
     plant_block_swing_catch_B.Product1 + rtb_Integrator) +
    plant_block_swing_catch_B.FilterCoefficient_p;

  /* Saturate: '<S3>/Saturation1' */
  if (plant_block_swing_catch_B.SliderGain >=
      plant_block_swing_catch_P.Saturation1_UpperSat) {
    rtb_SliderGain = plant_block_swing_catch_P.Saturation1_UpperSat;
  } else if (plant_block_swing_catch_B.SliderGain <=
             plant_block_swing_catch_P.Saturation1_LowerSat) {
    rtb_SliderGain = plant_block_swing_catch_P.Saturation1_LowerSat;
  } else {
    rtb_SliderGain = plant_block_swing_catch_B.SliderGain;
  }

  /* Saturate: '<S3>/Saturation2' */
  if (plant_block_swing_catch_B.Sum_o >=
      plant_block_swing_catch_P.Saturation2_UpperSat) {
    rtb_SliderGain_o = plant_block_swing_catch_P.Saturation2_UpperSat;
  } else if (plant_block_swing_catch_B.Sum_o <=
             plant_block_swing_catch_P.Saturation2_LowerSat) {
    rtb_SliderGain_o = plant_block_swing_catch_P.Saturation2_LowerSat;
  } else {
    rtb_SliderGain_o = plant_block_swing_catch_B.Sum_o;
  }

  /* Sum: '<S3>/Add' incorporates:
   *  Saturate: '<S3>/Saturation1'
   *  Saturate: '<S3>/Saturation2'
   */
  plant_block_swing_catch_B.Add = rtb_SliderGain + rtb_SliderGain_o;
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    /* Gain: '<S2>/encoder to radians' */
    plant_block_swing_catch_B.encodertoradians =
      plant_block_swing_catch_P.encodertoradians_Gain *
      plant_block_swing_catch_B.SFunction[0];
  }

  /* Derivative: '<S2>/Derivative' */
  {
    real_T t = plant_block_swing_catch_M->Timing.t[0];
    real_T timeStampA = plant_block_swing_catch_DW.Derivative_RWORK.TimeStampA;
    real_T timeStampB = plant_block_swing_catch_DW.Derivative_RWORK.TimeStampB;
    real_T *lastU = &plant_block_swing_catch_DW.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      plant_block_swing_catch_B.Derivative = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &plant_block_swing_catch_DW.Derivative_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      plant_block_swing_catch_B.Derivative =
        (plant_block_swing_catch_B.encodertoradians - *lastU++) / deltaT;
    }
  }

  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
  }

  /* Gain: '<S8>/Integral Gain' */
  plant_block_swing_catch_B.IntegralGain =
    plant_block_swing_catch_P.IntegralGain_Gain * rtb_Sum;

  /* Gain: '<S2>/rad//sec to rpm' */
  plant_block_swing_catch_B.radsectorpm =
    plant_block_swing_catch_P.radsectorpm_Gain *
    plant_block_swing_catch_B.Derivative;
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    /* Gain: '<Root>/Gain3' */
    plant_block_swing_catch_B.theta4 = plant_block_swing_catch_P.Gain3_Gain *
      plant_block_swing_catch_B.SFunction[3];
  }

  /* Gain: '<S10>/Integral Gain' */
  plant_block_swing_catch_B.IntegralGain_a =
    plant_block_swing_catch_P.IntegralGain_Gain_m *
    plant_block_swing_catch_B.Product1;
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    /* Abs: '<S7>/Abs1' incorporates:
     *  Constant: '<S7>/Constant4'
     *  Sum: '<S7>/Sum4'
     */
    plant_block_swing_catch_B.Resetafterswingstate = fabs
      (plant_block_swing_catch_P.Constant4_Value_l - plant_block_swing_catch_B.y);

    /* UnitDelay: '<S19>/FixPt Unit Delay1' */
    plant_block_swing_catch_B.FixPtUnitDelay1 =
      plant_block_swing_catch_DW.FixPtUnitDelay1_DSTATE;
  }

  /* Switch: '<S19>/Reset' incorporates:
   *  Constant: '<S19>/Initial Condition'
   *  MinMax: '<S17>/MinMax'
   */
  if (plant_block_swing_catch_B.Resetafterswingstate != 0.0) {
    plant_block_swing_catch_B.Reset =
      plant_block_swing_catch_P.InitialCondition_Value;
  } else if ((plant_block_swing_catch_B.E <=
              plant_block_swing_catch_B.FixPtUnitDelay1) || rtIsNaN
             (plant_block_swing_catch_B.FixPtUnitDelay1)) {
    /* MinMax: '<S17>/MinMax' */
    plant_block_swing_catch_B.Reset = plant_block_swing_catch_B.E;
  } else {
    /* MinMax: '<S17>/MinMax' */
    plant_block_swing_catch_B.Reset = plant_block_swing_catch_B.FixPtUnitDelay1;
  }

  /* End of Switch: '<S19>/Reset' */

  /* Sum: '<S7>/Sum3' incorporates:
   *  Constant: '<S7>/Desired Energy'
   *  Product: '<S7>/Product4'
   */
  plant_block_swing_catch_B.Sum3 = plant_block_swing_catch_P.DesiredEnergy_Value
    - plant_block_swing_catch_B.Reset * plant_block_swing_catch_B.y;
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
  }

  /* Gain: '<S18>/Integral Gain' */
  plant_block_swing_catch_B.IntegralGain_p =
    plant_block_swing_catch_P.IntegralGain_Gain_d *
    plant_block_swing_catch_B.TransferFcn;
}

/* Model update function */
void plant_block_swing_catch_update(void)
{
  /* Update for Derivative: '<Root>/Derivative1' */
  {
    real_T timeStampA = plant_block_swing_catch_DW.Derivative1_RWORK.TimeStampA;
    real_T timeStampB = plant_block_swing_catch_DW.Derivative1_RWORK.TimeStampB;
    real_T* lastTime = &plant_block_swing_catch_DW.Derivative1_RWORK.TimeStampA;
    real_T* lastU = &plant_block_swing_catch_DW.Derivative1_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &plant_block_swing_catch_DW.Derivative1_RWORK.TimeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative1_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &plant_block_swing_catch_DW.Derivative1_RWORK.TimeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative1_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = plant_block_swing_catch_M->Timing.t[0];
    *lastU++ = plant_block_swing_catch_B.theta;
  }

  /* Update for Derivative: '<Root>/Derivative4' */
  {
    real_T timeStampA = plant_block_swing_catch_DW.Derivative4_RWORK.TimeStampA;
    real_T timeStampB = plant_block_swing_catch_DW.Derivative4_RWORK.TimeStampB;
    real_T* lastTime = &plant_block_swing_catch_DW.Derivative4_RWORK.TimeStampA;
    real_T* lastU = &plant_block_swing_catch_DW.Derivative4_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &plant_block_swing_catch_DW.Derivative4_RWORK.TimeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative4_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &plant_block_swing_catch_DW.Derivative4_RWORK.TimeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative4_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = plant_block_swing_catch_M->Timing.t[0];
    *lastU++ = plant_block_swing_catch_B.LowPassFilterFlyWheel5;
  }

  /* Update for Derivative: '<Root>/Derivative5' */
  {
    real_T timeStampA = plant_block_swing_catch_DW.Derivative5_RWORK.TimeStampA;
    real_T timeStampB = plant_block_swing_catch_DW.Derivative5_RWORK.TimeStampB;
    real_T* lastTime = &plant_block_swing_catch_DW.Derivative5_RWORK.TimeStampA;
    real_T* lastU = &plant_block_swing_catch_DW.Derivative5_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &plant_block_swing_catch_DW.Derivative5_RWORK.TimeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative5_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &plant_block_swing_catch_DW.Derivative5_RWORK.TimeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative5_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = plant_block_swing_catch_M->Timing.t[0];
    *lastU++ = plant_block_swing_catch_B.LowPassFilterFlyWheel3;
  }

  /* Update for Derivative: '<Root>/Derivative6' */
  {
    real_T timeStampA = plant_block_swing_catch_DW.Derivative6_RWORK.TimeStampA;
    real_T timeStampB = plant_block_swing_catch_DW.Derivative6_RWORK.TimeStampB;
    real_T* lastTime = &plant_block_swing_catch_DW.Derivative6_RWORK.TimeStampA;
    real_T* lastU = &plant_block_swing_catch_DW.Derivative6_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &plant_block_swing_catch_DW.Derivative6_RWORK.TimeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative6_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &plant_block_swing_catch_DW.Derivative6_RWORK.TimeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative6_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = plant_block_swing_catch_M->Timing.t[0];
    *lastU++ = plant_block_swing_catch_B.Gain;
  }

  /* Update for Derivative: '<S2>/Derivative' */
  {
    real_T timeStampA = plant_block_swing_catch_DW.Derivative_RWORK.TimeStampA;
    real_T timeStampB = plant_block_swing_catch_DW.Derivative_RWORK.TimeStampB;
    real_T* lastTime = &plant_block_swing_catch_DW.Derivative_RWORK.TimeStampA;
    real_T* lastU = &plant_block_swing_catch_DW.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &plant_block_swing_catch_DW.Derivative_RWORK.TimeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &plant_block_swing_catch_DW.Derivative_RWORK.TimeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = plant_block_swing_catch_M->Timing.t[0];
    *lastU++ = plant_block_swing_catch_B.encodertoradians;
  }

  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    /* Update for UnitDelay: '<S19>/FixPt Unit Delay1' */
    plant_block_swing_catch_DW.FixPtUnitDelay1_DSTATE =
      plant_block_swing_catch_B.Reset;
  }

  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    rt_ertODEUpdateContinuousStates(&plant_block_swing_catch_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++plant_block_swing_catch_M->Timing.clockTick0)) {
    ++plant_block_swing_catch_M->Timing.clockTickH0;
  }

  plant_block_swing_catch_M->Timing.t[0] = rtsiGetSolverStopTime
    (&plant_block_swing_catch_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.008s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++plant_block_swing_catch_M->Timing.clockTick1)) {
      ++plant_block_swing_catch_M->Timing.clockTickH1;
    }

    plant_block_swing_catch_M->Timing.t[1] =
      plant_block_swing_catch_M->Timing.clockTick1 *
      plant_block_swing_catch_M->Timing.stepSize1 +
      plant_block_swing_catch_M->Timing.clockTickH1 *
      plant_block_swing_catch_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void plant_block_swing_catch_derivatives(void)
{
  XDot_plant_block_swing_catch_T *_rtXdot;
  _rtXdot = ((XDot_plant_block_swing_catch_T *)
             plant_block_swing_catch_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/Low Pass Filter Fly Wheel4' */
  {
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)
      ->LowPassFilterFlyWheel4_CSTATE = plant_block_swing_catch_B.theta;
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)
      ->LowPassFilterFlyWheel4_CSTATE +=
      (plant_block_swing_catch_P.LowPassFilterFlyWheel4_A)*
      plant_block_swing_catch_X.LowPassFilterFlyWheel4_CSTATE;
  }

  /* Derivatives for TransferFcn: '<Root>/Low Pass Filter Fly Wheel6' */
  {
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)
      ->LowPassFilterFlyWheel6_CSTATE = plant_block_swing_catch_B.theta4;
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)
      ->LowPassFilterFlyWheel6_CSTATE +=
      (plant_block_swing_catch_P.LowPassFilterFlyWheel6_A)*
      plant_block_swing_catch_X.LowPassFilterFlyWheel6_CSTATE;
  }

  /* Derivatives for TransferFcn: '<Root>/Low Pass Filter Fly Wheel5' */
  {
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)
      ->LowPassFilterFlyWheel5_CSTATE = plant_block_swing_catch_B.theta4;
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)
      ->LowPassFilterFlyWheel5_CSTATE +=
      (plant_block_swing_catch_P.LowPassFilterFlyWheel5_A)*
      plant_block_swing_catch_X.LowPassFilterFlyWheel5_CSTATE;
  }

  /* Derivatives for TransferFcn: '<Root>/Low Pass Filter Fly Wheel3' */
  {
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)
      ->LowPassFilterFlyWheel3_CSTATE = plant_block_swing_catch_B.theta;
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)
      ->LowPassFilterFlyWheel3_CSTATE +=
      (plant_block_swing_catch_P.LowPassFilterFlyWheel3_A)*
      plant_block_swing_catch_X.LowPassFilterFlyWheel3_CSTATE;
  }

  /* Derivatives for TransferFcn: '<S2>/Low Pass Filter Fly Wheel' */
  {
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)->LowPassFilterFlyWheel_CSTATE
      = plant_block_swing_catch_B.radsectorpm;
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)->LowPassFilterFlyWheel_CSTATE
      += (plant_block_swing_catch_P.LowPassFilterFlyWheel_A)*
      plant_block_swing_catch_X.LowPassFilterFlyWheel_CSTATE;
  }

  /* Derivatives for Integrator: '<S8>/Integrator' */
  _rtXdot->Integrator_CSTATE = plant_block_swing_catch_B.IntegralGain;

  /* Derivatives for Integrator: '<S8>/Filter' */
  _rtXdot->Filter_CSTATE = plant_block_swing_catch_B.FilterCoefficient;

  /* Derivatives for TransferFcn: '<Root>/Low Pass Filter Gimble Velocity' */
  {
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)
      ->LowPassFilterGimbleVelocity_CST = plant_block_swing_catch_B.Derivative6;
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)
      ->LowPassFilterGimbleVelocity_CST +=
      (plant_block_swing_catch_P.LowPassFilterGimbleVelocity_A)*
      plant_block_swing_catch_X.LowPassFilterGimbleVelocity_CST;
  }

  /* Derivatives for TransferFcn: '<S7>/Transfer Fcn' */
  {
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)->TransferFcn_CSTATE =
      plant_block_swing_catch_B.Sum3;
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)->TransferFcn_CSTATE +=
      (plant_block_swing_catch_P.TransferFcn_A)*
      plant_block_swing_catch_X.TransferFcn_CSTATE;
  }

  /* Derivatives for Integrator: '<S18>/Integrator' */
  {
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)->Integrator_CSTATE_m =
      plant_block_swing_catch_B.IntegralGain_p;
  }

  /* Derivatives for Integrator: '<S18>/Filter' */
  {
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)->Filter_CSTATE_f =
      plant_block_swing_catch_B.FilterCoefficient_a;
  }

  /* Derivatives for TransferFcn: '<Root>/Low Pass Filter Fly Wheel2' */
  {
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)
      ->LowPassFilterFlyWheel2_CSTATE = plant_block_swing_catch_B.theta_dot;
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)
      ->LowPassFilterFlyWheel2_CSTATE +=
      (plant_block_swing_catch_P.LowPassFilterFlyWheel2_A)*
      plant_block_swing_catch_X.LowPassFilterFlyWheel2_CSTATE;
  }

  /* Derivatives for TransferFcn: '<Root>/Low Pass Filter Fly Wheel1' */
  {
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)
      ->LowPassFilterFlyWheel1_CSTATE = plant_block_swing_catch_B.theta;
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)
      ->LowPassFilterFlyWheel1_CSTATE +=
      (plant_block_swing_catch_P.LowPassFilterFlyWheel1_A)*
      plant_block_swing_catch_X.LowPassFilterFlyWheel1_CSTATE;
  }

  /* Derivatives for Integrator: '<S10>/Integrator' */
  _rtXdot->Integrator_CSTATE_k = plant_block_swing_catch_B.IntegralGain_a;

  /* Derivatives for Integrator: '<S10>/Filter' */
  _rtXdot->Filter_CSTATE_o = plant_block_swing_catch_B.FilterCoefficient_p;
}

/* Model initialize function */
void plant_block_swing_catch_initialize(void)
{
  /* Level2 S-Function Block: '<S1>/S-Function' (ECPDSPDriver) */
  {
    SimStruct *rts = plant_block_swing_catch_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  plant_block_swing_catch_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  plant_block_swing_catch_PrevZCX.Filter_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  plant_block_swing_catch_DW.Derivative1_RWORK.TimeStampA = rtInf;
  plant_block_swing_catch_DW.Derivative1_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for Chart: '<S5>/State Switch v1' */
  plant_block_swing_catch_DW.sfEvent = plant_block_swing_ca_CALL_EVENT;
  plant_block_swing_catch_DW.is_active_c3_plant_block_swing_ = 0U;
  plant_block_swing_catch_DW.is_c3_plant_block_swing_catch =
    plant_block__IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for TransferFcn: '<Root>/Low Pass Filter Fly Wheel4' */
  plant_block_swing_catch_X.LowPassFilterFlyWheel4_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Low Pass Filter Fly Wheel6' */
  plant_block_swing_catch_X.LowPassFilterFlyWheel6_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Low Pass Filter Fly Wheel5' */
  plant_block_swing_catch_X.LowPassFilterFlyWheel5_CSTATE = 0.0;

  /* InitializeConditions for Derivative: '<Root>/Derivative4' */
  plant_block_swing_catch_DW.Derivative4_RWORK.TimeStampA = rtInf;
  plant_block_swing_catch_DW.Derivative4_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for TransferFcn: '<Root>/Low Pass Filter Fly Wheel3' */
  plant_block_swing_catch_X.LowPassFilterFlyWheel3_CSTATE = 0.0;

  /* InitializeConditions for Derivative: '<Root>/Derivative5' */
  plant_block_swing_catch_DW.Derivative5_RWORK.TimeStampA = rtInf;
  plant_block_swing_catch_DW.Derivative5_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for TransferFcn: '<S2>/Low Pass Filter Fly Wheel' */
  plant_block_swing_catch_X.LowPassFilterFlyWheel_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S8>/Integrator' */
  plant_block_swing_catch_X.Integrator_CSTATE =
    plant_block_swing_catch_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S8>/Filter' */
  plant_block_swing_catch_X.Filter_CSTATE = plant_block_swing_catch_P.Filter_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative6' */
  plant_block_swing_catch_DW.Derivative6_RWORK.TimeStampA = rtInf;
  plant_block_swing_catch_DW.Derivative6_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for TransferFcn: '<Root>/Low Pass Filter Gimble Velocity' */
  plant_block_swing_catch_X.LowPassFilterGimbleVelocity_CST = 0.0;

  /* InitializeConditions for TransferFcn: '<S7>/Transfer Fcn' */
  plant_block_swing_catch_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S18>/Integrator' */
  plant_block_swing_catch_X.Integrator_CSTATE_m =
    plant_block_swing_catch_P.Integrator_IC_b;

  /* InitializeConditions for Integrator: '<S18>/Filter' */
  plant_block_swing_catch_X.Filter_CSTATE_f =
    plant_block_swing_catch_P.Filter_IC_m;

  /* InitializeConditions for TransferFcn: '<Root>/Low Pass Filter Fly Wheel2' */
  plant_block_swing_catch_X.LowPassFilterFlyWheel2_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Low Pass Filter Fly Wheel1' */
  plant_block_swing_catch_X.LowPassFilterFlyWheel1_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S10>/Integrator' */
  plant_block_swing_catch_X.Integrator_CSTATE_k =
    plant_block_swing_catch_P.Integrator_IC_p;

  /* InitializeConditions for Integrator: '<S10>/Filter' */
  plant_block_swing_catch_X.Filter_CSTATE_o =
    plant_block_swing_catch_P.Filter_IC_mr;

  /* InitializeConditions for Derivative: '<S2>/Derivative' */
  plant_block_swing_catch_DW.Derivative_RWORK.TimeStampA = rtInf;
  plant_block_swing_catch_DW.Derivative_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for UnitDelay: '<S19>/FixPt Unit Delay1' */
  plant_block_swing_catch_DW.FixPtUnitDelay1_DSTATE =
    plant_block_swing_catch_P.FixPtUnitDelay1_InitialConditio;
}

/* Model terminate function */
void plant_block_swing_catch_terminate(void)
{
  /* Level2 S-Function Block: '<S1>/S-Function' (ECPDSPDriver) */
  {
    SimStruct *rts = plant_block_swing_catch_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  plant_block_swing_catch_output();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  plant_block_swing_catch_update();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  plant_block_swing_catch_initialize();
}

void MdlTerminate(void)
{
  plant_block_swing_catch_terminate();
}

/* Registration function */
RT_MODEL_plant_block_swing_catch_T *plant_block_swing_catch(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)plant_block_swing_catch_M, 0,
                sizeof(RT_MODEL_plant_block_swing_catch_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&plant_block_swing_catch_M->solverInfo,
                          &plant_block_swing_catch_M->Timing.simTimeStep);
    rtsiSetTPtr(&plant_block_swing_catch_M->solverInfo, &rtmGetTPtr
                (plant_block_swing_catch_M));
    rtsiSetStepSizePtr(&plant_block_swing_catch_M->solverInfo,
                       &plant_block_swing_catch_M->Timing.stepSize0);
    rtsiSetdXPtr(&plant_block_swing_catch_M->solverInfo,
                 &plant_block_swing_catch_M->ModelData.derivs);
    rtsiSetContStatesPtr(&plant_block_swing_catch_M->solverInfo,
                         &plant_block_swing_catch_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&plant_block_swing_catch_M->solverInfo,
      &plant_block_swing_catch_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&plant_block_swing_catch_M->solverInfo,
                          (&rtmGetErrorStatus(plant_block_swing_catch_M)));
    rtsiSetRTModelPtr(&plant_block_swing_catch_M->solverInfo,
                      plant_block_swing_catch_M);
  }

  rtsiSetSimTimeStep(&plant_block_swing_catch_M->solverInfo, MAJOR_TIME_STEP);
  plant_block_swing_catch_M->ModelData.intgData.f[0] =
    plant_block_swing_catch_M->ModelData.odeF[0];
  plant_block_swing_catch_M->ModelData.contStates = ((real_T *)
    &plant_block_swing_catch_X);
  rtsiSetSolverData(&plant_block_swing_catch_M->solverInfo, (void *)
                    &plant_block_swing_catch_M->ModelData.intgData);
  rtsiSetSolverName(&plant_block_swing_catch_M->solverInfo,"ode1");
  plant_block_swing_catch_M->solverInfoPtr =
    (&plant_block_swing_catch_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = plant_block_swing_catch_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    plant_block_swing_catch_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    plant_block_swing_catch_M->Timing.sampleTimes =
      (&plant_block_swing_catch_M->Timing.sampleTimesArray[0]);
    plant_block_swing_catch_M->Timing.offsetTimes =
      (&plant_block_swing_catch_M->Timing.offsetTimesArray[0]);

    /* task periods */
    plant_block_swing_catch_M->Timing.sampleTimes[0] = (0.0);
    plant_block_swing_catch_M->Timing.sampleTimes[1] = (0.008);

    /* task offsets */
    plant_block_swing_catch_M->Timing.offsetTimes[0] = (0.0);
    plant_block_swing_catch_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(plant_block_swing_catch_M,
             &plant_block_swing_catch_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = plant_block_swing_catch_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    plant_block_swing_catch_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(plant_block_swing_catch_M, 420.0);
  plant_block_swing_catch_M->Timing.stepSize0 = 0.008;
  plant_block_swing_catch_M->Timing.stepSize1 = 0.008;

  /* External mode info */
  plant_block_swing_catch_M->Sizes.checksums[0] = (1425515457U);
  plant_block_swing_catch_M->Sizes.checksums[1] = (3403792553U);
  plant_block_swing_catch_M->Sizes.checksums[2] = (1572016139U);
  plant_block_swing_catch_M->Sizes.checksums[3] = (1125992215U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    plant_block_swing_catch_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(plant_block_swing_catch_M->extModeInfo,
      &plant_block_swing_catch_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(plant_block_swing_catch_M->extModeInfo,
                        plant_block_swing_catch_M->Sizes.checksums);
    rteiSetTPtr(plant_block_swing_catch_M->extModeInfo, rtmGetTPtr
                (plant_block_swing_catch_M));
  }

  plant_block_swing_catch_M->solverInfoPtr =
    (&plant_block_swing_catch_M->solverInfo);
  plant_block_swing_catch_M->Timing.stepSize = (0.008);
  rtsiSetFixedStepSize(&plant_block_swing_catch_M->solverInfo, 0.008);
  rtsiSetSolverMode(&plant_block_swing_catch_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  plant_block_swing_catch_M->ModelData.blockIO = ((void *)
    &plant_block_swing_catch_B);

  {
    int_T i;
    for (i = 0; i < 5; i++) {
      plant_block_swing_catch_B.SFunction[i] = 0.0;
    }

    plant_block_swing_catch_B.theta = 0.0;
    plant_block_swing_catch_B.thetacorrection1 = 0.0;
    plant_block_swing_catch_B.theta_dot = 0.0;
    plant_block_swing_catch_B.Abs1 = 0.0;
    plant_block_swing_catch_B.Add2 = 0.0;
    plant_block_swing_catch_B.LowPassFilterFlyWheel5 = 0.0;
    plant_block_swing_catch_B.LowPassFilterFlyWheel3 = 0.0;
    plant_block_swing_catch_B.Product2 = 0.0;
    plant_block_swing_catch_B.LowPassFilterFlyWheel = 0.0;
    plant_block_swing_catch_B.FilterCoefficient = 0.0;
    plant_block_swing_catch_B.Saturation = 0.0;
    plant_block_swing_catch_B.Gain = 0.0;
    plant_block_swing_catch_B.Derivative6 = 0.0;
    plant_block_swing_catch_B.ActualGimbleVelocity = 0.0;
    plant_block_swing_catch_B.TransferFcn = 0.0;
    plant_block_swing_catch_B.FilterCoefficient_a = 0.0;
    plant_block_swing_catch_B.Sum = 0.0;
    plant_block_swing_catch_B.LowPassFilterFlyWheel2 = 0.0;
    plant_block_swing_catch_B.LowPassFilterFlyWheel1 = 0.0;
    plant_block_swing_catch_B.E = 0.0;
    plant_block_swing_catch_B.Product2_b = 0.0;
    plant_block_swing_catch_B.w_2 = 0.0;
    plant_block_swing_catch_B.EnableSwingVelocity = 0.0;
    plant_block_swing_catch_B.Product = 0.0;
    plant_block_swing_catch_B.SliderGain = 0.0;
    plant_block_swing_catch_B.Abs = 0.0;
    plant_block_swing_catch_B.Product1 = 0.0;
    plant_block_swing_catch_B.FilterCoefficient_p = 0.0;
    plant_block_swing_catch_B.Sum_o = 0.0;
    plant_block_swing_catch_B.Add = 0.0;
    plant_block_swing_catch_B.encodertoradians = 0.0;
    plant_block_swing_catch_B.Derivative = 0.0;
    plant_block_swing_catch_B.IntegralGain = 0.0;
    plant_block_swing_catch_B.radsectorpm = 0.0;
    plant_block_swing_catch_B.theta4 = 0.0;
    plant_block_swing_catch_B.IntegralGain_a = 0.0;
    plant_block_swing_catch_B.Resetafterswingstate = 0.0;
    plant_block_swing_catch_B.FixPtUnitDelay1 = 0.0;
    plant_block_swing_catch_B.Reset = 0.0;
    plant_block_swing_catch_B.Sum3 = 0.0;
    plant_block_swing_catch_B.IntegralGain_p = 0.0;
    plant_block_swing_catch_B.x = 0.0;
    plant_block_swing_catch_B.y = 0.0;
    plant_block_swing_catch_B.z = 0.0;
    plant_block_swing_catch_B.r = 0.0;
  }

  /* parameters */
  plant_block_swing_catch_M->ModelData.defaultParam = ((real_T *)
    &plant_block_swing_catch_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &plant_block_swing_catch_X;
    plant_block_swing_catch_M->ModelData.contStates = (x);
    (void) memset((void *)&plant_block_swing_catch_X, 0,
                  sizeof(X_plant_block_swing_catch_T));
  }

  /* states (dwork) */
  plant_block_swing_catch_M->ModelData.dwork = ((void *)
    &plant_block_swing_catch_DW);
  (void) memset((void *)&plant_block_swing_catch_DW, 0,
                sizeof(DW_plant_block_swing_catch_T));
  plant_block_swing_catch_DW.FixPtUnitDelay1_DSTATE = 0.0;
  plant_block_swing_catch_DW.Derivative1_RWORK.TimeStampA = 0.0;
  plant_block_swing_catch_DW.Derivative1_RWORK.LastUAtTimeA = 0.0;
  plant_block_swing_catch_DW.Derivative1_RWORK.TimeStampB = 0.0;
  plant_block_swing_catch_DW.Derivative1_RWORK.LastUAtTimeB = 0.0;
  plant_block_swing_catch_DW.Derivative4_RWORK.TimeStampA = 0.0;
  plant_block_swing_catch_DW.Derivative4_RWORK.LastUAtTimeA = 0.0;
  plant_block_swing_catch_DW.Derivative4_RWORK.TimeStampB = 0.0;
  plant_block_swing_catch_DW.Derivative4_RWORK.LastUAtTimeB = 0.0;
  plant_block_swing_catch_DW.Derivative5_RWORK.TimeStampA = 0.0;
  plant_block_swing_catch_DW.Derivative5_RWORK.LastUAtTimeA = 0.0;
  plant_block_swing_catch_DW.Derivative5_RWORK.TimeStampB = 0.0;
  plant_block_swing_catch_DW.Derivative5_RWORK.LastUAtTimeB = 0.0;
  plant_block_swing_catch_DW.Derivative6_RWORK.TimeStampA = 0.0;
  plant_block_swing_catch_DW.Derivative6_RWORK.LastUAtTimeA = 0.0;
  plant_block_swing_catch_DW.Derivative6_RWORK.TimeStampB = 0.0;
  plant_block_swing_catch_DW.Derivative6_RWORK.LastUAtTimeB = 0.0;
  plant_block_swing_catch_DW.Derivative_RWORK.TimeStampA = 0.0;
  plant_block_swing_catch_DW.Derivative_RWORK.LastUAtTimeA = 0.0;
  plant_block_swing_catch_DW.Derivative_RWORK.TimeStampB = 0.0;
  plant_block_swing_catch_DW.Derivative_RWORK.LastUAtTimeB = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    plant_block_swing_catch_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &plant_block_swing_catch_M->NonInlinedSFcns.sfcnInfo;
    plant_block_swing_catch_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (plant_block_swing_catch_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &plant_block_swing_catch_M->Sizes.numSampTimes);
    plant_block_swing_catch_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (plant_block_swing_catch_M)[0]);
    plant_block_swing_catch_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (plant_block_swing_catch_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,
                   plant_block_swing_catch_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(plant_block_swing_catch_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(plant_block_swing_catch_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (plant_block_swing_catch_M));
    rtssSetStepSizePtr(sfcnInfo, &plant_block_swing_catch_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (plant_block_swing_catch_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &plant_block_swing_catch_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &plant_block_swing_catch_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &plant_block_swing_catch_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &plant_block_swing_catch_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &plant_block_swing_catch_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &plant_block_swing_catch_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &plant_block_swing_catch_M->solverInfoPtr);
  }

  plant_block_swing_catch_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)
                  &plant_block_swing_catch_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  1*sizeof(SimStruct));
    plant_block_swing_catch_M->childSfunctions =
      (&plant_block_swing_catch_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    plant_block_swing_catch_M->childSfunctions[0] =
      (&plant_block_swing_catch_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: plant_block_swing_catch/<S1>/S-Function (ECPDSPDriver) */
    {
      SimStruct *rts = plant_block_swing_catch_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        plant_block_swing_catch_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        plant_block_swing_catch_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        plant_block_swing_catch_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &plant_block_swing_catch_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, plant_block_swing_catch_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &plant_block_swing_catch_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &plant_block_swing_catch_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &plant_block_swing_catch_M->
                         NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &plant_block_swing_catch_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &plant_block_swing_catch_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &plant_block_swing_catch_B.Saturation;
          sfcnUPtrs[1] = &plant_block_swing_catch_B.Add;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &plant_block_swing_catch_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            plant_block_swing_catch_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "plant_block_swing_catch/ECPDSP Driver/S-Function");
      ssSetRTModel(rts,plant_block_swing_catch_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &plant_block_swing_catch_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       plant_block_swing_catch_P.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       plant_block_swing_catch_P.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       plant_block_swing_catch_P.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       plant_block_swing_catch_P.SFunction_P4_Size);
      }

      /* registration */
      ECPDSPDriver(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.008);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  plant_block_swing_catch_M->Sizes.numContStates = (15);/* Number of continuous states */
  plant_block_swing_catch_M->Sizes.numY = (0);/* Number of model outputs */
  plant_block_swing_catch_M->Sizes.numU = (0);/* Number of model inputs */
  plant_block_swing_catch_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  plant_block_swing_catch_M->Sizes.numSampTimes = (2);/* Number of sample times */
  plant_block_swing_catch_M->Sizes.numBlocks = (131);/* Number of blocks */
  plant_block_swing_catch_M->Sizes.numBlockIO = (46);/* Number of block outputs */
  plant_block_swing_catch_M->Sizes.numBlockPrms = (83);/* Sum of parameter "widths" */
  return plant_block_swing_catch_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
