/*
 * State_Flow_v0.c
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
#include "State_Flow_v0_dt.h"

/* Named constants for Chart: '<Root>/State Switch v1' */
#define State_Flow_v0_CALL_EVENT       (-1)
#define State_Flow_v0_IN_Catch         ((uint8_T)1U)
#define State_Flow_v0_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define State_Flow_v0_IN_Rest          ((uint8_T)2U)
#define State_Flow_v0_IN_Swing         ((uint8_T)3U)

/* list of Real-Time Windows Target timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.008, 0.0,
};

/* Block signals (auto storage) */
B_State_Flow_v0_T State_Flow_v0_B;

/* Continuous states */
X_State_Flow_v0_T State_Flow_v0_X;

/* Block states (auto storage) */
DW_State_Flow_v0_T State_Flow_v0_DW;

/* Real-time model */
RT_MODEL_State_Flow_v0_T State_Flow_v0_M_;
RT_MODEL_State_Flow_v0_T *const State_Flow_v0_M = &State_Flow_v0_M_;

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  State_Flow_v0_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  State_Flow_v0_output();
  State_Flow_v0_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  State_Flow_v0_output();
  State_Flow_v0_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  State_Flow_v0_output();
  State_Flow_v0_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  State_Flow_v0_output();
  State_Flow_v0_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  State_Flow_v0_output();
  State_Flow_v0_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Disable for enable system:
 *    '<Root>/Enabled Subsystem'
 *    '<Root>/Enabled Subsystem2'
 */
void State_Flow_v0_EnabledSubsystem_Disable(DW_EnabledSubsystem_State_Flow_v0_T *
  localDW)
{
  localDW->EnabledSubsystem_MODE = FALSE;
}

/*
 * Start for enable system:
 *    '<Root>/Enabled Subsystem'
 *    '<Root>/Enabled Subsystem2'
 */
void State_Flow_v0_EnabledSubsystem_Start(B_EnabledSubsystem_State_Flow_v0_T
  *localB, DW_EnabledSubsystem_State_Flow_v0_T *localDW,
  P_EnabledSubsystem_State_Flow_v0_T *localP)
{
  localDW->EnabledSubsystem_MODE = FALSE;

  /* VirtualOutportStart for Outport: '<S2>/u -out' */
  localB->uin = localP->uout_Y0;
}

/*
 * Output and update for enable system:
 *    '<Root>/Enabled Subsystem'
 *    '<Root>/Enabled Subsystem2'
 */
void State_Flow_v0_EnabledSubsystem(RT_MODEL_State_Flow_v0_T * const
  State_Flow_v0_M, real_T rtu_0, real_T rtu_1,
  B_EnabledSubsystem_State_Flow_v0_T *localB,
  DW_EnabledSubsystem_State_Flow_v0_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (rtmIsMajorTimeStep(State_Flow_v0_M) && rtmIsMajorTimeStep(State_Flow_v0_M))
  {
    if (rtu_0 > 0.0) {
      if (!localDW->EnabledSubsystem_MODE) {
        localDW->EnabledSubsystem_MODE = TRUE;
      }
    } else {
      if (localDW->EnabledSubsystem_MODE) {
        State_Flow_v0_EnabledSubsystem_Disable(localDW);
      }
    }
  }

  if (localDW->EnabledSubsystem_MODE) {
    /* Inport: '<S2>/u - in' */
    localB->uin = rtu_1;
    if (rtmIsMajorTimeStep(State_Flow_v0_M)) {
      srUpdateBC(localDW->EnabledSubsystem_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */
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
void State_Flow_v0_output(void)
{
  /* local block i/o variables */
  real_T rtb_Sum;
  real_T rtb_Gain3;
  real_T tmp;
  if (rtmIsMajorTimeStep(State_Flow_v0_M)) {
    /* set solver stop time */
    if (!(State_Flow_v0_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&State_Flow_v0_M->solverInfo,
                            ((State_Flow_v0_M->Timing.clockTickH0 + 1) *
        State_Flow_v0_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&State_Flow_v0_M->solverInfo,
                            ((State_Flow_v0_M->Timing.clockTick0 + 1) *
        State_Flow_v0_M->Timing.stepSize0 + State_Flow_v0_M->Timing.clockTickH0 *
        State_Flow_v0_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(State_Flow_v0_M)) {
    State_Flow_v0_M->Timing.t[0] = rtsiGetT(&State_Flow_v0_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(State_Flow_v0_DW.EnabledSubsystem.EnabledSubsystem_SubsysRanBC);

  /* RTWBLOCK_START_COMMENT */
  if (rtmIsMajorTimeStep(State_Flow_v0_M)) {
    /* Level2 S-Function Block: '<S1>/S-Function' (ECPDSPDriver) */
    {
      SimStruct *rts = State_Flow_v0_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<Root>/Gain1' */
    State_Flow_v0_B.theta = State_Flow_v0_P.Gain1_Gain *
      State_Flow_v0_B.SFunction[2];

    /* Math: '<Root>/theta correction1' incorporates:
     *  Abs: '<Root>/Abs'
     *  Constant: '<Root>/Constant4'
     */
    State_Flow_v0_B.thetacorrection1 = rt_modd_snf(fabs(State_Flow_v0_B.theta),
      State_Flow_v0_P.Constant4_Value);
  }

  /* Derivative: '<Root>/Derivative1' */
  {
    real_T t = State_Flow_v0_M->Timing.t[0];
    real_T timeStampA = State_Flow_v0_DW.Derivative1_RWORK.TimeStampA;
    real_T timeStampB = State_Flow_v0_DW.Derivative1_RWORK.TimeStampB;
    real_T *lastU = &State_Flow_v0_DW.Derivative1_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      State_Flow_v0_B.theta_dot = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &State_Flow_v0_DW.Derivative1_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &State_Flow_v0_DW.Derivative1_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      State_Flow_v0_B.theta_dot = (State_Flow_v0_B.theta - *lastU++) / deltaT;
    }
  }

  if (rtmIsMajorTimeStep(State_Flow_v0_M)) {
    /* Chart: '<Root>/State Switch v1' */
    /* Gateway: State Switch v1 */
    State_Flow_v0_DW.sfEvent = State_Flow_v0_CALL_EVENT;

    /* During: State Switch v1 */
    if (State_Flow_v0_DW.is_active_c3_State_Flow_v0 == 0U) {
      /* Entry: State Switch v1 */
      State_Flow_v0_DW.is_active_c3_State_Flow_v0 = 1U;

      /* Entry Internal: State Switch v1 */
      /* Transition: '<S5>:2' */
      State_Flow_v0_DW.is_c3_State_Flow_v0 = State_Flow_v0_IN_Rest;

      /* Entry 'Rest': '<S5>:1' */
      State_Flow_v0_B.x = 1.0;
      State_Flow_v0_B.y = 0.0;
      State_Flow_v0_B.z = 0.0;
    } else {
      switch (State_Flow_v0_DW.is_c3_State_Flow_v0) {
       case State_Flow_v0_IN_Catch:
        /* During 'Catch': '<S5>:6' */
        if ((State_Flow_v0_B.thetacorrection1 < 2.7475) ||
            (State_Flow_v0_B.thetacorrection1 > 3.5325)) {
          /* Transition: '<S5>:7' */
          State_Flow_v0_DW.is_c3_State_Flow_v0 = State_Flow_v0_IN_Swing;

          /* Entry 'Swing': '<S5>:5' */
          State_Flow_v0_B.x = 0.0;
          State_Flow_v0_B.y = 1.0;
          State_Flow_v0_B.z = 0.0;
        }
        break;

       case State_Flow_v0_IN_Rest:
        /* During 'Rest': '<S5>:1' */
        if ((State_Flow_v0_B.thetacorrection1 > 0.05) &&
            (State_Flow_v0_B.theta_dot > 0.05)) {
          /* Transition: '<S5>:13' */
          State_Flow_v0_DW.is_c3_State_Flow_v0 = State_Flow_v0_IN_Swing;

          /* Entry 'Swing': '<S5>:5' */
          State_Flow_v0_B.x = 0.0;
          State_Flow_v0_B.y = 1.0;
          State_Flow_v0_B.z = 0.0;
        }
        break;

       default:
        /* During 'Swing': '<S5>:5' */
        if ((2.7475 < State_Flow_v0_B.thetacorrection1) &&
            (State_Flow_v0_B.thetacorrection1 < 3.5325)) {
          /* Transition: '<S5>:8' */
          State_Flow_v0_DW.is_c3_State_Flow_v0 = State_Flow_v0_IN_Catch;

          /* Entry 'Catch': '<S5>:6' */
          State_Flow_v0_B.x = 0.0;
          State_Flow_v0_B.y = 0.0;
          State_Flow_v0_B.z = 1.0;
        } else {
          if ((State_Flow_v0_B.thetacorrection1 < 0.05) &&
              (State_Flow_v0_B.theta_dot < 0.05)) {
            /* Transition: '<S5>:12' */
            State_Flow_v0_DW.is_c3_State_Flow_v0 = State_Flow_v0_IN_Rest;

            /* Entry 'Rest': '<S5>:1' */
            State_Flow_v0_B.x = 1.0;
            State_Flow_v0_B.y = 0.0;
            State_Flow_v0_B.z = 0.0;
          }
        }
        break;
      }
    }

    /* End of Chart: '<Root>/State Switch v1' */

    /* Gain: '<S7>/Gain2' */
    State_Flow_v0_B.Gain2 = State_Flow_v0_P.Gain2_Gain * State_Flow_v0_B.theta;
  }

  /* Gain: '<S7>/Gain3' */
  rtb_Gain3 = State_Flow_v0_P.Gain3_Gain * State_Flow_v0_B.theta_dot;
  if (rtmIsMajorTimeStep(State_Flow_v0_M)) {
    /* Gain: '<Root>/Gain3' */
    State_Flow_v0_B.theta4 = State_Flow_v0_P.Gain3_Gain_o *
      State_Flow_v0_B.SFunction[3];

    /* Gain: '<S7>/Gain' */
    State_Flow_v0_B.Gain = State_Flow_v0_P.Gain_Gain * State_Flow_v0_B.theta4;
  }

  /* Derivative: '<Root>/Derivative2' */
  {
    real_T t = State_Flow_v0_M->Timing.t[0];
    real_T timeStampA = State_Flow_v0_DW.Derivative2_RWORK.TimeStampA;
    real_T timeStampB = State_Flow_v0_DW.Derivative2_RWORK.TimeStampB;
    real_T *lastU = &State_Flow_v0_DW.Derivative2_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      rtb_Sum = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &State_Flow_v0_DW.Derivative2_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &State_Flow_v0_DW.Derivative2_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      rtb_Sum = (State_Flow_v0_B.theta4 - *lastU++) / deltaT;
    }
  }

  /* Gain: '<S7>/Gain5' incorporates:
   *  Gain: '<S7>/Gain1'
   *  Gain: '<S7>/Gain4'
   *  Sum: '<S7>/Add'
   */
  State_Flow_v0_B.Gain5 = (((State_Flow_v0_B.Gain2 + rtb_Gain3) +
    State_Flow_v0_B.Gain) + State_Flow_v0_P.Gain1_Gain_j * rtb_Sum) *
    State_Flow_v0_P.Gain4_Gain * State_Flow_v0_P.Gain5_Gain;
  if (rtmIsMajorTimeStep(State_Flow_v0_M)) {
  }

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem2' */
  State_Flow_v0_EnabledSubsystem(State_Flow_v0_M, State_Flow_v0_B.z,
    State_Flow_v0_B.Gain5, &State_Flow_v0_B.EnabledSubsystem2,
    &State_Flow_v0_DW.EnabledSubsystem2);

  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem2' */
  if (rtmIsMajorTimeStep(State_Flow_v0_M)) {
  }

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  State_Flow_v0_B.TransferFcn1 = State_Flow_v0_P.TransferFcn1_C*
    State_Flow_v0_X.TransferFcn1_CSTATE;
  if (rtmIsMajorTimeStep(State_Flow_v0_M)) {
    /* Gain: '<Root>/Gain4' */
    State_Flow_v0_B.Gain4 = State_Flow_v0_P.Gain4_Gain_k *
      State_Flow_v0_B.SFunction[0];
  }

  /* Derivative: '<Root>/Derivative' */
  {
    real_T t = State_Flow_v0_M->Timing.t[0];
    real_T timeStampA = State_Flow_v0_DW.Derivative_RWORK.TimeStampA;
    real_T timeStampB = State_Flow_v0_DW.Derivative_RWORK.TimeStampB;
    real_T *lastU = &State_Flow_v0_DW.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      State_Flow_v0_B.Derivative = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &State_Flow_v0_DW.Derivative_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &State_Flow_v0_DW.Derivative_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      State_Flow_v0_B.Derivative = (State_Flow_v0_B.Gain4 - *lastU++) / deltaT;
    }
  }

  if (rtmIsMajorTimeStep(State_Flow_v0_M)) {
    /* Gain: '<Root>/Gain' */
    State_Flow_v0_B.Gain_c = State_Flow_v0_P.Gain_Gain_o *
      State_Flow_v0_B.SFunction[1];
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  rtb_Sum = State_Flow_v0_P.Constant1_Value - State_Flow_v0_B.TransferFcn1;

  /* Gain: '<S4>/Filter Coefficient' incorporates:
   *  Gain: '<S4>/Derivative Gain'
   *  Integrator: '<S4>/Filter'
   *  Sum: '<S4>/SumD'
   */
  State_Flow_v0_B.FilterCoefficient = (State_Flow_v0_P.DerivativeGain_Gain *
    rtb_Sum - State_Flow_v0_X.Filter_CSTATE) *
    State_Flow_v0_P.FilterCoefficient_Gain;

  /* Sum: '<S4>/Sum' incorporates:
   *  Gain: '<S4>/Proportional Gain'
   *  Integrator: '<S4>/Integrator'
   */
  rtb_Gain3 = (State_Flow_v0_P.ProportionalGain_Gain * rtb_Sum +
               State_Flow_v0_X.Integrator_CSTATE) +
    State_Flow_v0_B.FilterCoefficient;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Gain3 >= State_Flow_v0_P.Saturation_UpperSat) {
    State_Flow_v0_B.Saturation = State_Flow_v0_P.Saturation_UpperSat;
  } else if (rtb_Gain3 <= State_Flow_v0_P.Saturation_LowerSat) {
    State_Flow_v0_B.Saturation = State_Flow_v0_P.Saturation_LowerSat;
  } else {
    State_Flow_v0_B.Saturation = rtb_Gain3;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(State_Flow_v0_M)) {
    /* UnitDelay: '<S9>/FixPt Unit Delay1' */
    State_Flow_v0_B.FixPtUnitDelay1 = State_Flow_v0_DW.FixPtUnitDelay1_DSTATE;
  }

  /* Switch: '<S9>/Reset' incorporates:
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S9>/Initial Condition'
   *  MinMax: '<S8>/MinMax'
   */
  if (State_Flow_v0_P.Constant2_Value != 0.0) {
    State_Flow_v0_B.Reset = State_Flow_v0_P.InitialCondition_Value;
  } else if ((State_Flow_v0_B.theta_dot >= State_Flow_v0_B.FixPtUnitDelay1) ||
             rtIsNaN(State_Flow_v0_B.FixPtUnitDelay1)) {
    /* MinMax: '<S8>/MinMax' */
    State_Flow_v0_B.Reset = State_Flow_v0_B.theta_dot;
  } else {
    /* MinMax: '<S8>/MinMax' */
    State_Flow_v0_B.Reset = State_Flow_v0_B.FixPtUnitDelay1;
  }

  /* End of Switch: '<S9>/Reset' */

  /* Sum: '<S6>/Sum2' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Gain: '<S6>/Gain4'
   */
  rtb_Gain3 = State_Flow_v0_P.Gain4_Gain_j * State_Flow_v0_B.Reset +
    State_Flow_v0_P.Constant1_Value_g;

  /* Saturate: '<S6>/Saturation' */
  if (rtb_Gain3 >= State_Flow_v0_P.Saturation_UpperSat_h) {
    rtb_Gain3 = State_Flow_v0_P.Saturation_UpperSat_h;
  } else {
    if (rtb_Gain3 <= State_Flow_v0_P.Saturation_LowerSat_j) {
      rtb_Gain3 = State_Flow_v0_P.Saturation_LowerSat_j;
    }
  }

  /* Gain: '<S6>/Gain5' incorporates:
   *  Saturate: '<S6>/Saturation'
   */
  State_Flow_v0_B.Gain5_n = State_Flow_v0_P.Gain5_Gain_o * rtb_Gain3;
  if (rtmIsMajorTimeStep(State_Flow_v0_M)) {
    /* Gain: '<S6>/Gain3' incorporates:
     *  Constant: '<S6>/Constant'
     *  Gain: '<S6>/Gain2'
     *  Sum: '<S6>/Sum1'
     *  Trigonometry: '<S6>/Trigonometric Function'
     */
    State_Flow_v0_B.Gain3 = (cos(State_Flow_v0_B.theta) +
      State_Flow_v0_P.Constant_Value) * State_Flow_v0_P.Gain2_Gain_b *
      State_Flow_v0_P.Gain3_Gain_h;
  }

  /* Sum: '<S6>/Sum' incorporates:
   *  Gain: '<S6>/Gain'
   *  Math: '<S6>/Math Function'
   *
   * About '<S6>/Math Function':
   *  Operator: magnitude^2
   */
  State_Flow_v0_B.E = State_Flow_v0_B.theta_dot * State_Flow_v0_B.theta_dot *
    State_Flow_v0_P.Gain_Gain_i + State_Flow_v0_B.Gain3;
  if (rtmIsMajorTimeStep(State_Flow_v0_M)) {
    /* Trigonometry: '<S6>/Trigonometric Function1' */
    State_Flow_v0_B.TrigonometricFunction1 = cos(State_Flow_v0_B.theta);
  }

  /* Gain: '<S6>/Gain1' incorporates:
   *  Product: '<S6>/Product1'
   *  Product: '<S6>/Product2'
   *  Product: '<S6>/Product3'
   */
  State_Flow_v0_B.Gain1 = State_Flow_v0_B.E *
    State_Flow_v0_B.TrigonometricFunction1 * State_Flow_v0_B.theta_dot *
    State_Flow_v0_B.Gain5_n * State_Flow_v0_P.Gain1_Gain_a;
  if (rtmIsMajorTimeStep(State_Flow_v0_M)) {
  }

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' */
  State_Flow_v0_EnabledSubsystem(State_Flow_v0_M, State_Flow_v0_B.y,
    State_Flow_v0_B.Gain1, &State_Flow_v0_B.EnabledSubsystem,
    &State_Flow_v0_DW.EnabledSubsystem);

  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */
  if (rtmIsMajorTimeStep(State_Flow_v0_M)) {
  }

  /* Step: '<Root>/Step off' */
  rtb_Gain3 = State_Flow_v0_M->Timing.t[0];

  /* Gain: '<Root>/Gain5' */
  State_Flow_v0_B.Gain5_e = State_Flow_v0_P.Gain5_Gain_b *
    State_Flow_v0_B.Derivative;

  /* Gain: '<S4>/Integral Gain' */
  State_Flow_v0_B.IntegralGain = State_Flow_v0_P.IntegralGain_Gain * rtb_Sum;

  /* Step: '<Root>/Step on' */
  if (State_Flow_v0_M->Timing.t[0] < State_Flow_v0_P.Stepon_Time) {
    tmp = State_Flow_v0_P.Stepon_Y0;
  } else {
    tmp = State_Flow_v0_P.Stepon_YFinal;
  }

  /* End of Step: '<Root>/Step on' */

  /* Step: '<Root>/Step off' */
  if (rtb_Gain3 < State_Flow_v0_P.Stepoff_Time) {
    rtb_Gain3 = State_Flow_v0_P.Stepoff_Y0;
  } else {
    rtb_Gain3 = State_Flow_v0_P.Stepoff_YFinal;
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Sum: '<Root>/Add3'
   */
  rtb_Gain3 = (tmp + rtb_Gain3) + (State_Flow_v0_B.EnabledSubsystem.uin +
    State_Flow_v0_B.EnabledSubsystem2.uin);

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_Gain3 >= State_Flow_v0_P.Saturation1_UpperSat) {
    State_Flow_v0_B.Saturation1 = State_Flow_v0_P.Saturation1_UpperSat;
  } else if (rtb_Gain3 <= State_Flow_v0_P.Saturation1_LowerSat) {
    State_Flow_v0_B.Saturation1 = State_Flow_v0_P.Saturation1_LowerSat;
  } else {
    State_Flow_v0_B.Saturation1 = rtb_Gain3;
  }

  /* End of Saturate: '<Root>/Saturation1' */
  if (rtmIsMajorTimeStep(State_Flow_v0_M)) {
  }
}

/* Model update function */
void State_Flow_v0_update(void)
{
  /* Update for Derivative: '<Root>/Derivative1' */
  {
    real_T timeStampA = State_Flow_v0_DW.Derivative1_RWORK.TimeStampA;
    real_T timeStampB = State_Flow_v0_DW.Derivative1_RWORK.TimeStampB;
    real_T* lastTime = &State_Flow_v0_DW.Derivative1_RWORK.TimeStampA;
    real_T* lastU = &State_Flow_v0_DW.Derivative1_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &State_Flow_v0_DW.Derivative1_RWORK.TimeStampB;
        lastU = &State_Flow_v0_DW.Derivative1_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &State_Flow_v0_DW.Derivative1_RWORK.TimeStampB;
        lastU = &State_Flow_v0_DW.Derivative1_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = State_Flow_v0_M->Timing.t[0];
    *lastU++ = State_Flow_v0_B.theta;
  }

  /* Update for Derivative: '<Root>/Derivative2' */
  {
    real_T timeStampA = State_Flow_v0_DW.Derivative2_RWORK.TimeStampA;
    real_T timeStampB = State_Flow_v0_DW.Derivative2_RWORK.TimeStampB;
    real_T* lastTime = &State_Flow_v0_DW.Derivative2_RWORK.TimeStampA;
    real_T* lastU = &State_Flow_v0_DW.Derivative2_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &State_Flow_v0_DW.Derivative2_RWORK.TimeStampB;
        lastU = &State_Flow_v0_DW.Derivative2_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &State_Flow_v0_DW.Derivative2_RWORK.TimeStampB;
        lastU = &State_Flow_v0_DW.Derivative2_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = State_Flow_v0_M->Timing.t[0];
    *lastU++ = State_Flow_v0_B.theta4;
  }

  /* Update for Derivative: '<Root>/Derivative' */
  {
    real_T timeStampA = State_Flow_v0_DW.Derivative_RWORK.TimeStampA;
    real_T timeStampB = State_Flow_v0_DW.Derivative_RWORK.TimeStampB;
    real_T* lastTime = &State_Flow_v0_DW.Derivative_RWORK.TimeStampA;
    real_T* lastU = &State_Flow_v0_DW.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &State_Flow_v0_DW.Derivative_RWORK.TimeStampB;
        lastU = &State_Flow_v0_DW.Derivative_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &State_Flow_v0_DW.Derivative_RWORK.TimeStampB;
        lastU = &State_Flow_v0_DW.Derivative_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = State_Flow_v0_M->Timing.t[0];
    *lastU++ = State_Flow_v0_B.Gain4;
  }

  if (rtmIsMajorTimeStep(State_Flow_v0_M)) {
    /* Update for UnitDelay: '<S9>/FixPt Unit Delay1' */
    State_Flow_v0_DW.FixPtUnitDelay1_DSTATE = State_Flow_v0_B.Reset;
  }

  if (rtmIsMajorTimeStep(State_Flow_v0_M)) {
    rt_ertODEUpdateContinuousStates(&State_Flow_v0_M->solverInfo);
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
  if (!(++State_Flow_v0_M->Timing.clockTick0)) {
    ++State_Flow_v0_M->Timing.clockTickH0;
  }

  State_Flow_v0_M->Timing.t[0] = rtsiGetSolverStopTime
    (&State_Flow_v0_M->solverInfo);

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
    if (!(++State_Flow_v0_M->Timing.clockTick1)) {
      ++State_Flow_v0_M->Timing.clockTickH1;
    }

    State_Flow_v0_M->Timing.t[1] = State_Flow_v0_M->Timing.clockTick1 *
      State_Flow_v0_M->Timing.stepSize1 + State_Flow_v0_M->Timing.clockTickH1 *
      State_Flow_v0_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void State_Flow_v0_derivatives(void)
{
  XDot_State_Flow_v0_T *_rtXdot;
  _rtXdot = ((XDot_State_Flow_v0_T *) State_Flow_v0_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  {
    ((XDot_State_Flow_v0_T *) State_Flow_v0_M->ModelData.derivs)
      ->TransferFcn1_CSTATE = State_Flow_v0_B.Gain5_e;
    ((XDot_State_Flow_v0_T *) State_Flow_v0_M->ModelData.derivs)
      ->TransferFcn1_CSTATE += (State_Flow_v0_P.TransferFcn1_A)*
      State_Flow_v0_X.TransferFcn1_CSTATE;
  }

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE = State_Flow_v0_B.IntegralGain;

  /* Derivatives for Integrator: '<S4>/Filter' */
  _rtXdot->Filter_CSTATE = State_Flow_v0_B.FilterCoefficient;
}

/* Model initialize function */
void State_Flow_v0_initialize(void)
{
  /* Level2 S-Function Block: '<S1>/S-Function' (ECPDSPDriver) */
  {
    SimStruct *rts = State_Flow_v0_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Enabled SubSystem: '<Root>/Enabled Subsystem2' */
  State_Flow_v0_EnabledSubsystem_Start(&State_Flow_v0_B.EnabledSubsystem2,
    &State_Flow_v0_DW.EnabledSubsystem2, (P_EnabledSubsystem_State_Flow_v0_T *)
    &State_Flow_v0_P.EnabledSubsystem2);

  /* End of Start for SubSystem: '<Root>/Enabled Subsystem2' */

  /* Start for Enabled SubSystem: '<Root>/Enabled Subsystem' */
  State_Flow_v0_EnabledSubsystem_Start(&State_Flow_v0_B.EnabledSubsystem,
    &State_Flow_v0_DW.EnabledSubsystem, (P_EnabledSubsystem_State_Flow_v0_T *)
    &State_Flow_v0_P.EnabledSubsystem);

  /* End of Start for SubSystem: '<Root>/Enabled Subsystem' */

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  State_Flow_v0_DW.Derivative1_RWORK.TimeStampA = rtInf;
  State_Flow_v0_DW.Derivative1_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for Chart: '<Root>/State Switch v1' */
  State_Flow_v0_DW.sfEvent = State_Flow_v0_CALL_EVENT;
  State_Flow_v0_DW.is_active_c3_State_Flow_v0 = 0U;
  State_Flow_v0_DW.is_c3_State_Flow_v0 = State_Flow_v0_IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for Derivative: '<Root>/Derivative2' */
  State_Flow_v0_DW.Derivative2_RWORK.TimeStampA = rtInf;
  State_Flow_v0_DW.Derivative2_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  State_Flow_v0_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  State_Flow_v0_DW.Derivative_RWORK.TimeStampA = rtInf;
  State_Flow_v0_DW.Derivative_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  State_Flow_v0_X.Integrator_CSTATE = State_Flow_v0_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S4>/Filter' */
  State_Flow_v0_X.Filter_CSTATE = State_Flow_v0_P.Filter_IC;

  /* InitializeConditions for UnitDelay: '<S9>/FixPt Unit Delay1' */
  State_Flow_v0_DW.FixPtUnitDelay1_DSTATE =
    State_Flow_v0_P.FixPtUnitDelay1_InitialCondition;
}

/* Model terminate function */
void State_Flow_v0_terminate(void)
{
  /* Level2 S-Function Block: '<S1>/S-Function' (ECPDSPDriver) */
  {
    SimStruct *rts = State_Flow_v0_M->childSfunctions[0];
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
  State_Flow_v0_output();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  State_Flow_v0_update();

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
  State_Flow_v0_initialize();
}

void MdlTerminate(void)
{
  State_Flow_v0_terminate();
}

/* Registration function */
RT_MODEL_State_Flow_v0_T *State_Flow_v0(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)State_Flow_v0_M, 0,
                sizeof(RT_MODEL_State_Flow_v0_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&State_Flow_v0_M->solverInfo,
                          &State_Flow_v0_M->Timing.simTimeStep);
    rtsiSetTPtr(&State_Flow_v0_M->solverInfo, &rtmGetTPtr(State_Flow_v0_M));
    rtsiSetStepSizePtr(&State_Flow_v0_M->solverInfo,
                       &State_Flow_v0_M->Timing.stepSize0);
    rtsiSetdXPtr(&State_Flow_v0_M->solverInfo,
                 &State_Flow_v0_M->ModelData.derivs);
    rtsiSetContStatesPtr(&State_Flow_v0_M->solverInfo,
                         &State_Flow_v0_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&State_Flow_v0_M->solverInfo,
      &State_Flow_v0_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&State_Flow_v0_M->solverInfo, (&rtmGetErrorStatus
      (State_Flow_v0_M)));
    rtsiSetRTModelPtr(&State_Flow_v0_M->solverInfo, State_Flow_v0_M);
  }

  rtsiSetSimTimeStep(&State_Flow_v0_M->solverInfo, MAJOR_TIME_STEP);
  State_Flow_v0_M->ModelData.intgData.y = State_Flow_v0_M->ModelData.odeY;
  State_Flow_v0_M->ModelData.intgData.f[0] = State_Flow_v0_M->ModelData.odeF[0];
  State_Flow_v0_M->ModelData.intgData.f[1] = State_Flow_v0_M->ModelData.odeF[1];
  State_Flow_v0_M->ModelData.intgData.f[2] = State_Flow_v0_M->ModelData.odeF[2];
  State_Flow_v0_M->ModelData.intgData.f[3] = State_Flow_v0_M->ModelData.odeF[3];
  State_Flow_v0_M->ModelData.intgData.f[4] = State_Flow_v0_M->ModelData.odeF[4];
  State_Flow_v0_M->ModelData.intgData.f[5] = State_Flow_v0_M->ModelData.odeF[5];
  State_Flow_v0_M->ModelData.contStates = ((real_T *) &State_Flow_v0_X);
  rtsiSetSolverData(&State_Flow_v0_M->solverInfo, (void *)
                    &State_Flow_v0_M->ModelData.intgData);
  rtsiSetSolverName(&State_Flow_v0_M->solverInfo,"ode5");
  State_Flow_v0_M->solverInfoPtr = (&State_Flow_v0_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = State_Flow_v0_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    State_Flow_v0_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    State_Flow_v0_M->Timing.sampleTimes =
      (&State_Flow_v0_M->Timing.sampleTimesArray[0]);
    State_Flow_v0_M->Timing.offsetTimes =
      (&State_Flow_v0_M->Timing.offsetTimesArray[0]);

    /* task periods */
    State_Flow_v0_M->Timing.sampleTimes[0] = (0.0);
    State_Flow_v0_M->Timing.sampleTimes[1] = (0.008);

    /* task offsets */
    State_Flow_v0_M->Timing.offsetTimes[0] = (0.0);
    State_Flow_v0_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(State_Flow_v0_M, &State_Flow_v0_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = State_Flow_v0_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    State_Flow_v0_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(State_Flow_v0_M, 20.0);
  State_Flow_v0_M->Timing.stepSize0 = 0.008;
  State_Flow_v0_M->Timing.stepSize1 = 0.008;

  /* External mode info */
  State_Flow_v0_M->Sizes.checksums[0] = (2489480683U);
  State_Flow_v0_M->Sizes.checksums[1] = (2893304224U);
  State_Flow_v0_M->Sizes.checksums[2] = (1197350479U);
  State_Flow_v0_M->Sizes.checksums[3] = (2446042263U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    State_Flow_v0_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &State_Flow_v0_DW.EnabledSubsystem.EnabledSubsystem_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &State_Flow_v0_DW.EnabledSubsystem2.EnabledSubsystem_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(State_Flow_v0_M->extModeInfo,
      &State_Flow_v0_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(State_Flow_v0_M->extModeInfo,
                        State_Flow_v0_M->Sizes.checksums);
    rteiSetTPtr(State_Flow_v0_M->extModeInfo, rtmGetTPtr(State_Flow_v0_M));
  }

  State_Flow_v0_M->solverInfoPtr = (&State_Flow_v0_M->solverInfo);
  State_Flow_v0_M->Timing.stepSize = (0.008);
  rtsiSetFixedStepSize(&State_Flow_v0_M->solverInfo, 0.008);
  rtsiSetSolverMode(&State_Flow_v0_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  State_Flow_v0_M->ModelData.blockIO = ((void *) &State_Flow_v0_B);
  (void) memset(((void *) &State_Flow_v0_B), 0,
                sizeof(B_State_Flow_v0_T));

  /* parameters */
  State_Flow_v0_M->ModelData.defaultParam = ((real_T *)&State_Flow_v0_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &State_Flow_v0_X;
    State_Flow_v0_M->ModelData.contStates = (x);
    (void) memset((void *)&State_Flow_v0_X, 0,
                  sizeof(X_State_Flow_v0_T));
  }

  /* states (dwork) */
  State_Flow_v0_M->ModelData.dwork = ((void *) &State_Flow_v0_DW);
  (void) memset((void *)&State_Flow_v0_DW, 0,
                sizeof(DW_State_Flow_v0_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    State_Flow_v0_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &State_Flow_v0_M->NonInlinedSFcns.sfcnInfo;
    State_Flow_v0_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(State_Flow_v0_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &State_Flow_v0_M->Sizes.numSampTimes);
    State_Flow_v0_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (State_Flow_v0_M)[0]);
    State_Flow_v0_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (State_Flow_v0_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,State_Flow_v0_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(State_Flow_v0_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(State_Flow_v0_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(State_Flow_v0_M));
    rtssSetStepSizePtr(sfcnInfo, &State_Flow_v0_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(State_Flow_v0_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &State_Flow_v0_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &State_Flow_v0_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &State_Flow_v0_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &State_Flow_v0_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &State_Flow_v0_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &State_Flow_v0_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &State_Flow_v0_M->solverInfoPtr);
  }

  State_Flow_v0_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&State_Flow_v0_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  1*sizeof(SimStruct));
    State_Flow_v0_M->childSfunctions =
      (&State_Flow_v0_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    State_Flow_v0_M->childSfunctions[0] =
      (&State_Flow_v0_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: State_Flow_v0/<S1>/S-Function (ECPDSPDriver) */
    {
      SimStruct *rts = State_Flow_v0_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = State_Flow_v0_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = State_Flow_v0_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = State_Flow_v0_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &State_Flow_v0_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, State_Flow_v0_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &State_Flow_v0_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &State_Flow_v0_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &State_Flow_v0_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &State_Flow_v0_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &State_Flow_v0_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &State_Flow_v0_B.Saturation;
          sfcnUPtrs[1] = &State_Flow_v0_B.Saturation1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &State_Flow_v0_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) State_Flow_v0_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "State_Flow_v0/ECPDSP Driver/S-Function");
      ssSetRTModel(rts,State_Flow_v0_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &State_Flow_v0_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)State_Flow_v0_P.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)State_Flow_v0_P.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)State_Flow_v0_P.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)State_Flow_v0_P.SFunction_P4_Size);
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
  State_Flow_v0_M->Sizes.numContStates = (3);/* Number of continuous states */
  State_Flow_v0_M->Sizes.numY = (0);   /* Number of model outputs */
  State_Flow_v0_M->Sizes.numU = (0);   /* Number of model inputs */
  State_Flow_v0_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  State_Flow_v0_M->Sizes.numSampTimes = (2);/* Number of sample times */
  State_Flow_v0_M->Sizes.numBlocks = (86);/* Number of blocks */
  State_Flow_v0_M->Sizes.numBlockIO = (29);/* Number of block outputs */
  State_Flow_v0_M->Sizes.numBlockPrms = (63);/* Sum of parameter "widths" */
  return State_Flow_v0_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
