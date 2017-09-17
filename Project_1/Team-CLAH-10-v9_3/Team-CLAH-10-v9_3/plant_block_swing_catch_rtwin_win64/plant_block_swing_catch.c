/*
 * plant_block_swing_catch.c
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
#include "plant_block_swing_catch_dt.h"

/* Named constants for Chart: '<Root>/State Switch v1' */
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
  int_T nXc = 9;
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
  real_T rtb_Sum;
  real_T rtb_Gain2;
  real_T rtb_Gain3;
  real_T rtb_Gain;
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

    /* Math: '<Root>/theta correction1' incorporates:
     *  Abs: '<Root>/Abs'
     *  Constant: '<Root>/Constant4'
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

  /* Abs: '<Root>/Abs1' */
  plant_block_swing_catch_B.Abs1 = fabs(plant_block_swing_catch_B.theta_dot);
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    /* Chart: '<Root>/State Switch v1' */
    /* Gateway: State Switch v1 */
    plant_block_swing_catch_DW.sfEvent = plant_block_swing_ca_CALL_EVENT;

    /* During: State Switch v1 */
    if (plant_block_swing_catch_DW.is_active_c3_plant_block_swing_ == 0U) {
      /* Entry: State Switch v1 */
      plant_block_swing_catch_DW.is_active_c3_plant_block_swing_ = 1U;

      /* Entry Internal: State Switch v1 */
      /* Transition: '<S5>:2' */
      plant_block_swing_catch_DW.is_c3_plant_block_swing_catch =
        plant_block_swing_catch_IN_Rest;

      /* Entry 'Rest': '<S5>:1' */
      plant_block_swing_catch_B.x = 1.0;
      plant_block_swing_catch_B.y = 0.0;
      plant_block_swing_catch_B.z = 0.0;
    } else {
      switch (plant_block_swing_catch_DW.is_c3_plant_block_swing_catch) {
       case plant_block_swing_catc_IN_Catch:
        /* During 'Catch': '<S5>:6' */
        if ((plant_block_swing_catch_B.thetacorrection1 < 2.7475) ||
            (plant_block_swing_catch_B.thetacorrection1 > 3.5325)) {
          /* Transition: '<S5>:7' */
          plant_block_swing_catch_DW.is_c3_plant_block_swing_catch =
            plant_block_swing_catc_IN_Swing;

          /* Entry 'Swing': '<S5>:5' */
          plant_block_swing_catch_B.x = 0.0;
          plant_block_swing_catch_B.y = 1.0;
          plant_block_swing_catch_B.z = 0.0;
        } else {
          if (plant_block_swing_catch_B.Abs1 > 12.5) {
            /* Transition: '<S5>:34' */
            plant_block_swing_catch_DW.is_c3_plant_block_swing_catch =
              plant_block_swing_ca_IN_ReSwing;

            /* Entry 'ReSwing': '<S5>:33' */
            plant_block_swing_catch_B.x = 1.0;
            plant_block_swing_catch_B.y = 0.0;
            plant_block_swing_catch_B.z = 0.0;
          }
        }
        break;

       case plant_block_swing_ca_IN_ReSwing:
        /* During 'ReSwing': '<S5>:33' */
        if (plant_block_swing_catch_B.Abs1 < 6.0) {
          /* Transition: '<S5>:35' */
          plant_block_swing_catch_DW.is_c3_plant_block_swing_catch =
            plant_block_swing_catc_IN_Swing;

          /* Entry 'Swing': '<S5>:5' */
          plant_block_swing_catch_B.x = 0.0;
          plant_block_swing_catch_B.y = 1.0;
          plant_block_swing_catch_B.z = 0.0;
        }
        break;

       case plant_block_swing_catch_IN_Rest:
        /* During 'Rest': '<S5>:1' */
        if ((plant_block_swing_catch_B.thetacorrection1 > 0.12) &&
            (plant_block_swing_catch_B.Abs1 > 0.12)) {
          /* Transition: '<S5>:13' */
          plant_block_swing_catch_DW.is_c3_plant_block_swing_catch =
            plant_block_swing_catc_IN_Swing;

          /* Entry 'Swing': '<S5>:5' */
          plant_block_swing_catch_B.x = 0.0;
          plant_block_swing_catch_B.y = 1.0;
          plant_block_swing_catch_B.z = 0.0;
        }
        break;

       default:
        /* During 'Swing': '<S5>:5' */
        if ((2.7475 < plant_block_swing_catch_B.thetacorrection1) &&
            (plant_block_swing_catch_B.thetacorrection1 < 3.5325)) {
          /* Transition: '<S5>:8' */
          plant_block_swing_catch_DW.is_c3_plant_block_swing_catch =
            plant_block_swing_catc_IN_Catch;

          /* Entry 'Catch': '<S5>:6' */
          plant_block_swing_catch_B.x = 0.0;
          plant_block_swing_catch_B.y = 0.0;
          plant_block_swing_catch_B.z = 1.0;
        } else {
          if ((plant_block_swing_catch_B.thetacorrection1 < 0.12) &&
              (plant_block_swing_catch_B.Abs1 < 0.12)) {
            /* Transition: '<S5>:12' */
            plant_block_swing_catch_DW.is_c3_plant_block_swing_catch =
              plant_block_swing_catch_IN_Rest;

            /* Entry 'Rest': '<S5>:1' */
            plant_block_swing_catch_B.x = 1.0;
            plant_block_swing_catch_B.y = 0.0;
            plant_block_swing_catch_B.z = 0.0;
          }
        }
        break;
      }
    }

    /* End of Chart: '<Root>/State Switch v1' */
  }

  /* TransferFcn: '<Root>/Transfer Fcn5' */
  rtb_Sum = plant_block_swing_catch_P.TransferFcn5_C*
    plant_block_swing_catch_X.TransferFcn5_CSTATE;

  /* Gain: '<S7>/Gain2' */
  rtb_Gain2 = plant_block_swing_catch_P.Gain2_Gain * rtb_Sum;

  /* TransferFcn: '<Root>/Transfer Fcn2' */
  rtb_Sum = plant_block_swing_catch_P.TransferFcn2_C*
    plant_block_swing_catch_X.TransferFcn2_CSTATE;

  /* Gain: '<S7>/Gain3' */
  rtb_Gain3 = plant_block_swing_catch_P.Gain3_Gain * rtb_Sum;

  /* TransferFcn: '<Root>/Transfer Fcn3' */
  rtb_Sum = plant_block_swing_catch_P.TransferFcn3_C*
    plant_block_swing_catch_X.TransferFcn3_CSTATE;

  /* Math: '<Root>/theta correction2' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  rtb_Sum = rt_modd_snf(rtb_Sum, plant_block_swing_catch_P.Constant1_Value);

  /* Sum: '<Root>/Add2' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  plant_block_swing_catch_B.Add2 = rtb_Sum -
    plant_block_swing_catch_P.Constant2_Value;

  /* Gain: '<S7>/Gain' */
  rtb_Gain = plant_block_swing_catch_P.Gain_Gain *
    plant_block_swing_catch_B.Add2;

  /* TransferFcn: '<Root>/Transfer Fcn4' */
  rtb_Sum = plant_block_swing_catch_P.TransferFcn4_C*
    plant_block_swing_catch_X.TransferFcn4_CSTATE;

  /* Gain: '<S7>/Gain4' incorporates:
   *  Gain: '<S7>/Gain1'
   *  Sum: '<S7>/Add'
   */
  plant_block_swing_catch_B.Gain4 = (((rtb_Gain2 + rtb_Gain3) + rtb_Gain) +
    plant_block_swing_catch_P.Gain1_Gain_j * rtb_Sum) *
    plant_block_swing_catch_P.Gain4_Gain;
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
  }

  /* Product: '<Root>/Product1' */
  plant_block_swing_catch_B.Product1 = plant_block_swing_catch_B.z *
    plant_block_swing_catch_B.Gain4;
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
  }

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  plant_block_swing_catch_B.TransferFcn1 =
    plant_block_swing_catch_P.TransferFcn1_C*
    plant_block_swing_catch_X.TransferFcn1_CSTATE;
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    /* Gain: '<Root>/Gain4' */
    plant_block_swing_catch_B.Gain4_e = plant_block_swing_catch_P.Gain4_Gain_c *
      plant_block_swing_catch_B.SFunction[0];
  }

  /* Derivative: '<Root>/Derivative' */
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
      plant_block_swing_catch_B.Derivative = (plant_block_swing_catch_B.Gain4_e
        - *lastU++) / deltaT;
    }
  }

  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    /* Gain: '<Root>/Gain' */
    plant_block_swing_catch_B.Gain = plant_block_swing_catch_P.Gain_Gain_l *
      plant_block_swing_catch_B.SFunction[1];
  }

  /* Derivative: '<Root>/Derivative3' */
  {
    real_T t = plant_block_swing_catch_M->Timing.t[0];
    real_T timeStampA = plant_block_swing_catch_DW.Derivative3_RWORK.TimeStampA;
    real_T timeStampB = plant_block_swing_catch_DW.Derivative3_RWORK.TimeStampB;
    real_T *lastU = &plant_block_swing_catch_DW.Derivative3_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      rtb_Sum = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &plant_block_swing_catch_DW.Derivative3_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative3_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      rtb_Sum = (plant_block_swing_catch_B.Gain - *lastU++) / deltaT;
    }
  }

  /* Product: '<Root>/Product3' incorporates:
   *  Gain: '<Root>/Gain6'
   */
  plant_block_swing_catch_B.Product3 = plant_block_swing_catch_P.Gain6_Gain *
    rtb_Sum * plant_block_swing_catch_B.z;
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Sum = plant_block_swing_catch_P.Constant_Value -
    plant_block_swing_catch_B.TransferFcn1;

  /* Gain: '<S3>/Filter Coefficient' incorporates:
   *  Gain: '<S3>/Derivative Gain'
   *  Integrator: '<S3>/Filter'
   *  Sum: '<S3>/SumD'
   */
  plant_block_swing_catch_B.FilterCoefficient =
    (plant_block_swing_catch_P.DerivativeGain_Gain * rtb_Sum -
     plant_block_swing_catch_X.Filter_CSTATE) *
    plant_block_swing_catch_P.FilterCoefficient_Gain;

  /* Sum: '<S3>/Sum' incorporates:
   *  Gain: '<S3>/Proportional Gain'
   *  Integrator: '<S3>/Integrator'
   */
  rtb_Gain2 = (plant_block_swing_catch_P.ProportionalGain_Gain * rtb_Sum +
               plant_block_swing_catch_X.Integrator_CSTATE) +
    plant_block_swing_catch_B.FilterCoefficient;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Gain2 >= plant_block_swing_catch_P.Saturation_UpperSat) {
    plant_block_swing_catch_B.Saturation =
      plant_block_swing_catch_P.Saturation_UpperSat;
  } else if (rtb_Gain2 <= plant_block_swing_catch_P.Saturation_LowerSat) {
    plant_block_swing_catch_B.Saturation =
      plant_block_swing_catch_P.Saturation_LowerSat;
  } else {
    plant_block_swing_catch_B.Saturation = rtb_Gain2;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
  }

  /* Sum: '<Root>/Add1' */
  plant_block_swing_catch_B.Add1 = plant_block_swing_catch_B.Product1 -
    plant_block_swing_catch_B.Product3;

  /* Gain: '<S4>/Filter Coefficient' incorporates:
   *  Gain: '<S4>/Derivative Gain'
   *  Integrator: '<S4>/Filter'
   *  Sum: '<S4>/SumD'
   */
  plant_block_swing_catch_B.FilterCoefficient_k =
    (plant_block_swing_catch_P.DerivativeGain_Gain_n *
     plant_block_swing_catch_B.Add1 - plant_block_swing_catch_X.Filter_CSTATE_e)
    * plant_block_swing_catch_P.FilterCoefficient_Gain_g;

  /* Sum: '<S4>/Sum' incorporates:
   *  Gain: '<S4>/Proportional Gain'
   *  Integrator: '<S4>/Integrator'
   */
  plant_block_swing_catch_B.Sum =
    (plant_block_swing_catch_P.ProportionalGain_Gain_b *
     plant_block_swing_catch_B.Add1 +
     plant_block_swing_catch_X.Integrator_CSTATE_b) +
    plant_block_swing_catch_B.FilterCoefficient_k;
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    /* UnitDelay: '<S9>/FixPt Unit Delay1' */
    plant_block_swing_catch_B.FixPtUnitDelay1 =
      plant_block_swing_catch_DW.FixPtUnitDelay1_DSTATE;
  }

  /* Switch: '<S9>/Reset' incorporates:
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S9>/Initial Condition'
   */
  if (plant_block_swing_catch_P.Constant2_Value_l != 0.0) {
    plant_block_swing_catch_B.Reset =
      plant_block_swing_catch_P.InitialCondition_Value;
  } else {
    /* Abs: '<S6>/Abs' */
    rtb_Gain2 = fabs(plant_block_swing_catch_B.theta_dot);

    /* MinMax: '<S8>/MinMax' */
    if ((rtb_Gain2 >= plant_block_swing_catch_B.FixPtUnitDelay1) || rtIsNaN
        (plant_block_swing_catch_B.FixPtUnitDelay1)) {
      plant_block_swing_catch_B.Reset = rtb_Gain2;
    } else {
      plant_block_swing_catch_B.Reset =
        plant_block_swing_catch_B.FixPtUnitDelay1;
    }

    /* End of MinMax: '<S8>/MinMax' */
  }

  /* End of Switch: '<S9>/Reset' */

  /* Sum: '<S6>/Sum2' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Gain: '<S6>/Gain4'
   */
  rtb_Gain2 = plant_block_swing_catch_P.Gain4_Gain_f *
    plant_block_swing_catch_B.Reset +
    plant_block_swing_catch_P.Constant1_Value_a;

  /* Saturate: '<S6>/Saturation' */
  if (rtb_Gain2 >= plant_block_swing_catch_P.Saturation_UpperSat_p) {
    rtb_Gain2 = plant_block_swing_catch_P.Saturation_UpperSat_p;
  } else {
    if (rtb_Gain2 <= plant_block_swing_catch_P.Saturation_LowerSat_f) {
      rtb_Gain2 = plant_block_swing_catch_P.Saturation_LowerSat_f;
    }
  }

  /* Gain: '<S6>/Gain5' incorporates:
   *  Saturate: '<S6>/Saturation'
   */
  plant_block_swing_catch_B.Gain5 = plant_block_swing_catch_P.Gain5_Gain *
    rtb_Gain2;
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    /* Gain: '<S6>/Gain3' incorporates:
     *  Constant: '<S6>/Constant'
     *  Gain: '<S6>/Gain2'
     *  Sum: '<S6>/Sum1'
     *  Trigonometry: '<S6>/Trigonometric Function'
     */
    plant_block_swing_catch_B.Gain3 = (cos(plant_block_swing_catch_B.theta) +
      plant_block_swing_catch_P.Constant_Value_g) *
      plant_block_swing_catch_P.Gain2_Gain_d *
      plant_block_swing_catch_P.Gain3_Gain_f;
  }

  /* Sum: '<S6>/Sum' incorporates:
   *  Gain: '<S6>/Gain'
   *  Math: '<S6>/Math Function'
   *
   * About '<S6>/Math Function':
   *  Operator: magnitude^2
   */
  plant_block_swing_catch_B.E = plant_block_swing_catch_B.theta_dot *
    plant_block_swing_catch_B.theta_dot * plant_block_swing_catch_P.Gain_Gain_h
    + plant_block_swing_catch_B.Gain3;
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    /* Trigonometry: '<S6>/Trigonometric Function1' */
    plant_block_swing_catch_B.TrigonometricFunction1 = cos
      (plant_block_swing_catch_B.theta);
  }

  /* Gain: '<S6>/Gain1' incorporates:
   *  Product: '<S6>/Product1'
   *  Product: '<S6>/Product2'
   *  Product: '<S6>/Product3'
   */
  plant_block_swing_catch_B.Gain1 = plant_block_swing_catch_B.E *
    plant_block_swing_catch_B.TrigonometricFunction1 *
    plant_block_swing_catch_B.theta_dot * plant_block_swing_catch_B.Gain5 *
    plant_block_swing_catch_P.Gain1_Gain_a;
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
  }

  /* Product: '<Root>/Product2' */
  plant_block_swing_catch_B.Product2 = plant_block_swing_catch_B.Gain1 *
    plant_block_swing_catch_B.y;

  /* Sum: '<Root>/Add' incorporates:
   *  Sum: '<Root>/Add3'
   */
  rtb_Gain2 = (0.0 + 0.0) + (plant_block_swing_catch_B.Sum +
    plant_block_swing_catch_B.Product2);

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_Gain2 >= plant_block_swing_catch_P.Saturation1_UpperSat) {
    plant_block_swing_catch_B.Saturation1 =
      plant_block_swing_catch_P.Saturation1_UpperSat;
  } else if (rtb_Gain2 <= plant_block_swing_catch_P.Saturation1_LowerSat) {
    plant_block_swing_catch_B.Saturation1 =
      plant_block_swing_catch_P.Saturation1_LowerSat;
  } else {
    plant_block_swing_catch_B.Saturation1 = rtb_Gain2;
  }

  /* End of Saturate: '<Root>/Saturation1' */
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    /* Gain: '<Root>/Gain3' */
    plant_block_swing_catch_B.theta4 = plant_block_swing_catch_P.Gain3_Gain_b *
      plant_block_swing_catch_B.SFunction[3];
  }

  /* Derivative: '<Root>/Derivative2' */
  {
    real_T t = plant_block_swing_catch_M->Timing.t[0];
    real_T timeStampA = plant_block_swing_catch_DW.Derivative2_RWORK.TimeStampA;
    real_T timeStampB = plant_block_swing_catch_DW.Derivative2_RWORK.TimeStampB;
    real_T *lastU = &plant_block_swing_catch_DW.Derivative2_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      plant_block_swing_catch_B.Derivative2 = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &plant_block_swing_catch_DW.Derivative2_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative2_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      plant_block_swing_catch_B.Derivative2 = (plant_block_swing_catch_B.theta4
        - *lastU++) / deltaT;
    }
  }

  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
  }

  /* Gain: '<Root>/Gain5' */
  plant_block_swing_catch_B.Gain5_f = plant_block_swing_catch_P.Gain5_Gain_b *
    plant_block_swing_catch_B.Derivative;

  /* Gain: '<S3>/Integral Gain' */
  plant_block_swing_catch_B.IntegralGain =
    plant_block_swing_catch_P.IntegralGain_Gain * rtb_Sum;

  /* Gain: '<S4>/Integral Gain' */
  plant_block_swing_catch_B.IntegralGain_i =
    plant_block_swing_catch_P.IntegralGain_Gain_o *
    plant_block_swing_catch_B.Add1;
  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
  }
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

  /* Update for Derivative: '<Root>/Derivative' */
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
    *lastU++ = plant_block_swing_catch_B.Gain4_e;
  }

  /* Update for Derivative: '<Root>/Derivative3' */
  {
    real_T timeStampA = plant_block_swing_catch_DW.Derivative3_RWORK.TimeStampA;
    real_T timeStampB = plant_block_swing_catch_DW.Derivative3_RWORK.TimeStampB;
    real_T* lastTime = &plant_block_swing_catch_DW.Derivative3_RWORK.TimeStampA;
    real_T* lastU = &plant_block_swing_catch_DW.Derivative3_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &plant_block_swing_catch_DW.Derivative3_RWORK.TimeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative3_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &plant_block_swing_catch_DW.Derivative3_RWORK.TimeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative3_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = plant_block_swing_catch_M->Timing.t[0];
    *lastU++ = plant_block_swing_catch_B.Gain;
  }

  if (rtmIsMajorTimeStep(plant_block_swing_catch_M)) {
    /* Update for UnitDelay: '<S9>/FixPt Unit Delay1' */
    plant_block_swing_catch_DW.FixPtUnitDelay1_DSTATE =
      plant_block_swing_catch_B.Reset;
  }

  /* Update for Derivative: '<Root>/Derivative2' */
  {
    real_T timeStampA = plant_block_swing_catch_DW.Derivative2_RWORK.TimeStampA;
    real_T timeStampB = plant_block_swing_catch_DW.Derivative2_RWORK.TimeStampB;
    real_T* lastTime = &plant_block_swing_catch_DW.Derivative2_RWORK.TimeStampA;
    real_T* lastU = &plant_block_swing_catch_DW.Derivative2_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &plant_block_swing_catch_DW.Derivative2_RWORK.TimeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative2_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &plant_block_swing_catch_DW.Derivative2_RWORK.TimeStampB;
        lastU = &plant_block_swing_catch_DW.Derivative2_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = plant_block_swing_catch_M->Timing.t[0];
    *lastU++ = plant_block_swing_catch_B.theta4;
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

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn5' */
  {
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)->TransferFcn5_CSTATE =
      plant_block_swing_catch_B.theta4;
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)->TransferFcn5_CSTATE +=
      (plant_block_swing_catch_P.TransferFcn5_A)*
      plant_block_swing_catch_X.TransferFcn5_CSTATE;
  }

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn2' */
  {
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)->TransferFcn2_CSTATE =
      plant_block_swing_catch_B.Derivative2;
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)->TransferFcn2_CSTATE +=
      (plant_block_swing_catch_P.TransferFcn2_A)*
      plant_block_swing_catch_X.TransferFcn2_CSTATE;
  }

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn3' */
  {
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)->TransferFcn3_CSTATE =
      plant_block_swing_catch_B.theta;
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)->TransferFcn3_CSTATE +=
      (plant_block_swing_catch_P.TransferFcn3_A)*
      plant_block_swing_catch_X.TransferFcn3_CSTATE;
  }

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn4' */
  {
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)->TransferFcn4_CSTATE =
      plant_block_swing_catch_B.theta_dot;
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)->TransferFcn4_CSTATE +=
      (plant_block_swing_catch_P.TransferFcn4_A)*
      plant_block_swing_catch_X.TransferFcn4_CSTATE;
  }

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  {
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)->TransferFcn1_CSTATE =
      plant_block_swing_catch_B.Gain5_f;
    ((XDot_plant_block_swing_catch_T *)
      plant_block_swing_catch_M->ModelData.derivs)->TransferFcn1_CSTATE +=
      (plant_block_swing_catch_P.TransferFcn1_A)*
      plant_block_swing_catch_X.TransferFcn1_CSTATE;
  }

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE = plant_block_swing_catch_B.IntegralGain;

  /* Derivatives for Integrator: '<S3>/Filter' */
  _rtXdot->Filter_CSTATE = plant_block_swing_catch_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE_b = plant_block_swing_catch_B.IntegralGain_i;

  /* Derivatives for Integrator: '<S4>/Filter' */
  _rtXdot->Filter_CSTATE_e = plant_block_swing_catch_B.FilterCoefficient_k;
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

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  plant_block_swing_catch_DW.Derivative1_RWORK.TimeStampA = rtInf;
  plant_block_swing_catch_DW.Derivative1_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for Chart: '<Root>/State Switch v1' */
  plant_block_swing_catch_DW.sfEvent = plant_block_swing_ca_CALL_EVENT;
  plant_block_swing_catch_DW.is_active_c3_plant_block_swing_ = 0U;
  plant_block_swing_catch_DW.is_c3_plant_block_swing_catch =
    plant_block__IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn5' */
  plant_block_swing_catch_X.TransferFcn5_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2' */
  plant_block_swing_catch_X.TransferFcn2_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn3' */
  plant_block_swing_catch_X.TransferFcn3_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn4' */
  plant_block_swing_catch_X.TransferFcn4_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  plant_block_swing_catch_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  plant_block_swing_catch_DW.Derivative_RWORK.TimeStampA = rtInf;
  plant_block_swing_catch_DW.Derivative_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for Derivative: '<Root>/Derivative3' */
  plant_block_swing_catch_DW.Derivative3_RWORK.TimeStampA = rtInf;
  plant_block_swing_catch_DW.Derivative3_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  plant_block_swing_catch_X.Integrator_CSTATE =
    plant_block_swing_catch_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S3>/Filter' */
  plant_block_swing_catch_X.Filter_CSTATE = plant_block_swing_catch_P.Filter_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  plant_block_swing_catch_X.Integrator_CSTATE_b =
    plant_block_swing_catch_P.Integrator_IC_l;

  /* InitializeConditions for Integrator: '<S4>/Filter' */
  plant_block_swing_catch_X.Filter_CSTATE_e =
    plant_block_swing_catch_P.Filter_IC_o;

  /* InitializeConditions for UnitDelay: '<S9>/FixPt Unit Delay1' */
  plant_block_swing_catch_DW.FixPtUnitDelay1_DSTATE =
    plant_block_swing_catch_P.FixPtUnitDelay1_InitialConditio;

  /* InitializeConditions for Derivative: '<Root>/Derivative2' */
  plant_block_swing_catch_DW.Derivative2_RWORK.TimeStampA = rtInf;
  plant_block_swing_catch_DW.Derivative2_RWORK.TimeStampB = rtInf;
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

  rtmSetTFinal(plant_block_swing_catch_M, 120.0);
  plant_block_swing_catch_M->Timing.stepSize0 = 0.008;
  plant_block_swing_catch_M->Timing.stepSize1 = 0.008;

  /* External mode info */
  plant_block_swing_catch_M->Sizes.checksums[0] = (3959971182U);
  plant_block_swing_catch_M->Sizes.checksums[1] = (2294589923U);
  plant_block_swing_catch_M->Sizes.checksums[2] = (2279569597U);
  plant_block_swing_catch_M->Sizes.checksums[3] = (1589219494U);

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
    plant_block_swing_catch_B.Gain4 = 0.0;
    plant_block_swing_catch_B.Product1 = 0.0;
    plant_block_swing_catch_B.TransferFcn1 = 0.0;
    plant_block_swing_catch_B.Gain4_e = 0.0;
    plant_block_swing_catch_B.Derivative = 0.0;
    plant_block_swing_catch_B.Gain = 0.0;
    plant_block_swing_catch_B.Product3 = 0.0;
    plant_block_swing_catch_B.FilterCoefficient = 0.0;
    plant_block_swing_catch_B.Saturation = 0.0;
    plant_block_swing_catch_B.Add1 = 0.0;
    plant_block_swing_catch_B.FilterCoefficient_k = 0.0;
    plant_block_swing_catch_B.Sum = 0.0;
    plant_block_swing_catch_B.FixPtUnitDelay1 = 0.0;
    plant_block_swing_catch_B.Reset = 0.0;
    plant_block_swing_catch_B.Gain5 = 0.0;
    plant_block_swing_catch_B.Gain3 = 0.0;
    plant_block_swing_catch_B.E = 0.0;
    plant_block_swing_catch_B.TrigonometricFunction1 = 0.0;
    plant_block_swing_catch_B.Gain1 = 0.0;
    plant_block_swing_catch_B.Product2 = 0.0;
    plant_block_swing_catch_B.Saturation1 = 0.0;
    plant_block_swing_catch_B.theta4 = 0.0;
    plant_block_swing_catch_B.Derivative2 = 0.0;
    plant_block_swing_catch_B.Gain5_f = 0.0;
    plant_block_swing_catch_B.IntegralGain = 0.0;
    plant_block_swing_catch_B.IntegralGain_i = 0.0;
    plant_block_swing_catch_B.x = 0.0;
    plant_block_swing_catch_B.y = 0.0;
    plant_block_swing_catch_B.z = 0.0;
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
  plant_block_swing_catch_DW.Derivative_RWORK.TimeStampA = 0.0;
  plant_block_swing_catch_DW.Derivative_RWORK.LastUAtTimeA = 0.0;
  plant_block_swing_catch_DW.Derivative_RWORK.TimeStampB = 0.0;
  plant_block_swing_catch_DW.Derivative_RWORK.LastUAtTimeB = 0.0;
  plant_block_swing_catch_DW.Derivative3_RWORK.TimeStampA = 0.0;
  plant_block_swing_catch_DW.Derivative3_RWORK.LastUAtTimeA = 0.0;
  plant_block_swing_catch_DW.Derivative3_RWORK.TimeStampB = 0.0;
  plant_block_swing_catch_DW.Derivative3_RWORK.LastUAtTimeB = 0.0;
  plant_block_swing_catch_DW.Derivative2_RWORK.TimeStampA = 0.0;
  plant_block_swing_catch_DW.Derivative2_RWORK.LastUAtTimeA = 0.0;
  plant_block_swing_catch_DW.Derivative2_RWORK.TimeStampB = 0.0;
  plant_block_swing_catch_DW.Derivative2_RWORK.LastUAtTimeB = 0.0;

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
          sfcnUPtrs[1] = &plant_block_swing_catch_B.Saturation1;
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
  plant_block_swing_catch_M->Sizes.numContStates = (9);/* Number of continuous states */
  plant_block_swing_catch_M->Sizes.numY = (0);/* Number of model outputs */
  plant_block_swing_catch_M->Sizes.numU = (0);/* Number of model inputs */
  plant_block_swing_catch_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  plant_block_swing_catch_M->Sizes.numSampTimes = (2);/* Number of sample times */
  plant_block_swing_catch_M->Sizes.numBlocks = (111);/* Number of blocks */
  plant_block_swing_catch_M->Sizes.numBlockIO = (36);/* Number of block outputs */
  plant_block_swing_catch_M->Sizes.numBlockPrms = (71);/* Sum of parameter "widths" */
  return plant_block_swing_catch_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
