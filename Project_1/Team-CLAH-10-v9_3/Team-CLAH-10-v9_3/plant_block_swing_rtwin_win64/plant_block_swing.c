/*
 * plant_block_swing.c
 *
 * Code generation for model "plant_block_swing".
 *
 * Model version              : 1.168
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Mon Sep 11 08:07:00 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "plant_block_swing.h"
#include "plant_block_swing_private.h"
#include "plant_block_swing_dt.h"

/* list of Real-Time Windows Target timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.008, 0.0,
};

/* Block signals (auto storage) */
B_plant_block_swing_T plant_block_swing_B;

/* Continuous states */
X_plant_block_swing_T plant_block_swing_X;

/* Block states (auto storage) */
DW_plant_block_swing_T plant_block_swing_DW;

/* Real-time model */
RT_MODEL_plant_block_swing_T plant_block_swing_M_;
RT_MODEL_plant_block_swing_T *const plant_block_swing_M = &plant_block_swing_M_;

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
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  plant_block_swing_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void plant_block_swing_output(void)
{
  real_T rtb_Sum;
  real_T rtb_Stepoff;
  real_T rtb_gimbalmotorvoltage;
  real_T u;
  if (rtmIsMajorTimeStep(plant_block_swing_M)) {
    /* set solver stop time */
    if (!(plant_block_swing_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&plant_block_swing_M->solverInfo,
                            ((plant_block_swing_M->Timing.clockTickH0 + 1) *
        plant_block_swing_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&plant_block_swing_M->solverInfo,
                            ((plant_block_swing_M->Timing.clockTick0 + 1) *
        plant_block_swing_M->Timing.stepSize0 +
        plant_block_swing_M->Timing.clockTickH0 *
        plant_block_swing_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(plant_block_swing_M)) {
    plant_block_swing_M->Timing.t[0] = rtsiGetT(&plant_block_swing_M->solverInfo);
  }

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  plant_block_swing_B.TransferFcn1 = plant_block_swing_P.TransferFcn1_C*
    plant_block_swing_X.TransferFcn1_CSTATE;
  if (rtmIsMajorTimeStep(plant_block_swing_M)) {
    /* Level2 S-Function Block: '<S1>/S-Function' (ECPDSPDriver) */
    {
      SimStruct *rts = plant_block_swing_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<Root>/Gain4' */
    plant_block_swing_B.Gain4 = plant_block_swing_P.Gain4_Gain *
      plant_block_swing_B.SFunction[0];
  }

  /* Derivative: '<Root>/Derivative' */
  {
    real_T t = plant_block_swing_M->Timing.t[0];
    real_T timeStampA = plant_block_swing_DW.Derivative_RWORK.TimeStampA;
    real_T timeStampB = plant_block_swing_DW.Derivative_RWORK.TimeStampB;
    real_T *lastU = &plant_block_swing_DW.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      plant_block_swing_B.Derivative = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &plant_block_swing_DW.Derivative_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &plant_block_swing_DW.Derivative_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      plant_block_swing_B.Derivative = (plant_block_swing_B.Gain4 - *lastU++) /
        deltaT;
    }
  }

  if (rtmIsMajorTimeStep(plant_block_swing_M)) {
    /* Gain: '<Root>/Gain' */
    plant_block_swing_B.Gain = plant_block_swing_P.Gain_Gain *
      plant_block_swing_B.SFunction[1];
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Sum = plant_block_swing_P.Constant_Value -
    plant_block_swing_B.TransferFcn1;

  /* Gain: '<S2>/Filter Coefficient' incorporates:
   *  Gain: '<S2>/Derivative Gain'
   *  Integrator: '<S2>/Filter'
   *  Sum: '<S2>/SumD'
   */
  plant_block_swing_B.FilterCoefficient =
    (plant_block_swing_P.DerivativeGain_Gain * rtb_Sum -
     plant_block_swing_X.Filter_CSTATE) *
    plant_block_swing_P.FilterCoefficient_Gain;

  /* Sum: '<S2>/Sum' incorporates:
   *  Gain: '<S2>/Proportional Gain'
   *  Integrator: '<S2>/Integrator'
   */
  u = (plant_block_swing_P.ProportionalGain_Gain * rtb_Sum +
       plant_block_swing_X.Integrator_CSTATE) +
    plant_block_swing_B.FilterCoefficient;

  /* Saturate: '<Root>/Saturation' */
  if (u >= plant_block_swing_P.Saturation_UpperSat) {
    plant_block_swing_B.Saturation = plant_block_swing_P.Saturation_UpperSat;
  } else if (u <= plant_block_swing_P.Saturation_LowerSat) {
    plant_block_swing_B.Saturation = plant_block_swing_P.Saturation_LowerSat;
  } else {
    plant_block_swing_B.Saturation = u;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(plant_block_swing_M)) {
    /* Gain: '<Root>/Gain1' */
    plant_block_swing_B.Gain1 = plant_block_swing_P.Gain1_Gain *
      plant_block_swing_B.SFunction[2];
  }

  /* Step: '<Root>/Step on' */
  if (plant_block_swing_M->Timing.t[0] < plant_block_swing_P.Stepon_Time) {
    rtb_gimbalmotorvoltage = plant_block_swing_P.Stepon_Y0;
  } else {
    rtb_gimbalmotorvoltage = plant_block_swing_P.Stepon_YFinal;
  }

  /* End of Step: '<Root>/Step on' */

  /* Step: '<Root>/Step off' */
  if (plant_block_swing_M->Timing.t[0] < plant_block_swing_P.Stepoff_Time) {
    rtb_Stepoff = plant_block_swing_P.Stepoff_Y0;
  } else {
    rtb_Stepoff = plant_block_swing_P.Stepoff_YFinal;
  }

  /* End of Step: '<Root>/Step off' */

  /* Derivative: '<Root>/Derivative1' */
  {
    real_T t = plant_block_swing_M->Timing.t[0];
    real_T timeStampA = plant_block_swing_DW.Derivative1_RWORK.TimeStampA;
    real_T timeStampB = plant_block_swing_DW.Derivative1_RWORK.TimeStampB;
    real_T *lastU = &plant_block_swing_DW.Derivative1_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      plant_block_swing_B.Derivative1 = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &plant_block_swing_DW.Derivative1_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &plant_block_swing_DW.Derivative1_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      plant_block_swing_B.Derivative1 = (plant_block_swing_B.Gain1 - *lastU++) /
        deltaT;
    }
  }

  if (rtmIsMajorTimeStep(plant_block_swing_M)) {
    /* UnitDelay: '<S5>/FixPt Unit Delay1' */
    plant_block_swing_B.FixPtUnitDelay1 =
      plant_block_swing_DW.FixPtUnitDelay1_DSTATE;
  }

  /* Switch: '<S5>/Reset' incorporates:
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S5>/Initial Condition'
   *  MinMax: '<S4>/MinMax'
   */
  if (plant_block_swing_P.Constant2_Value != 0.0) {
    plant_block_swing_B.Reset = plant_block_swing_P.InitialCondition_Value;
  } else if ((plant_block_swing_B.Derivative1 >=
              plant_block_swing_B.FixPtUnitDelay1) || rtIsNaN
             (plant_block_swing_B.FixPtUnitDelay1)) {
    /* MinMax: '<S4>/MinMax' */
    plant_block_swing_B.Reset = plant_block_swing_B.Derivative1;
  } else {
    /* MinMax: '<S4>/MinMax' */
    plant_block_swing_B.Reset = plant_block_swing_B.FixPtUnitDelay1;
  }

  /* End of Switch: '<S5>/Reset' */

  /* Sum: '<S3>/Sum2' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Gain: '<S3>/Gain4'
   */
  u = plant_block_swing_P.Gain4_Gain_f * plant_block_swing_B.Reset +
    plant_block_swing_P.Constant1_Value;

  /* Saturate: '<S3>/Saturation' */
  if (u >= plant_block_swing_P.Saturation_UpperSat_i) {
    u = plant_block_swing_P.Saturation_UpperSat_i;
  } else {
    if (u <= plant_block_swing_P.Saturation_LowerSat_j) {
      u = plant_block_swing_P.Saturation_LowerSat_j;
    }
  }

  /* Gain: '<S3>/Gain5' incorporates:
   *  Saturate: '<S3>/Saturation'
   */
  plant_block_swing_B.Gain5 = plant_block_swing_P.Gain5_Gain * u;
  if (rtmIsMajorTimeStep(plant_block_swing_M)) {
    /* Gain: '<S3>/Gain3' incorporates:
     *  Constant: '<S3>/Constant'
     *  Gain: '<S3>/Gain2'
     *  Sum: '<S3>/Sum1'
     *  Trigonometry: '<S3>/Trigonometric Function'
     */
    plant_block_swing_B.Gain3 = (cos(plant_block_swing_B.Gain1) +
      plant_block_swing_P.Constant_Value_i) * plant_block_swing_P.Gain2_Gain *
      plant_block_swing_P.Gain3_Gain;
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Gain: '<S3>/Gain'
   *  Math: '<S3>/Math Function'
   *
   * About '<S3>/Math Function':
   *  Operator: magnitude^2
   */
  plant_block_swing_B.E = plant_block_swing_B.Derivative1 *
    plant_block_swing_B.Derivative1 * plant_block_swing_P.Gain_Gain_e +
    plant_block_swing_B.Gain3;
  if (rtmIsMajorTimeStep(plant_block_swing_M)) {
    /* Trigonometry: '<S3>/Trigonometric Function1' */
    plant_block_swing_B.TrigonometricFunction1 = cos(plant_block_swing_B.Gain1);
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Gain: '<S3>/Gain1'
   *  Product: '<S3>/Product1'
   *  Product: '<S3>/Product2'
   *  Product: '<S3>/Product3'
   */
  rtb_gimbalmotorvoltage = plant_block_swing_B.E *
    plant_block_swing_B.TrigonometricFunction1 * plant_block_swing_B.Derivative1
    * plant_block_swing_B.Gain5 * plant_block_swing_P.Gain1_Gain_h +
    (rtb_gimbalmotorvoltage + rtb_Stepoff);

  /* Gain: '<Root>/Gain5' */
  plant_block_swing_B.Gain5_f = plant_block_swing_P.Gain5_Gain_b *
    plant_block_swing_B.Derivative;

  /* Gain: '<S2>/Integral Gain' */
  plant_block_swing_B.IntegralGain = plant_block_swing_P.IntegralGain_Gain *
    rtb_Sum;

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_gimbalmotorvoltage >= plant_block_swing_P.Saturation1_UpperSat) {
    plant_block_swing_B.Saturation1 = plant_block_swing_P.Saturation1_UpperSat;
  } else if (rtb_gimbalmotorvoltage <= plant_block_swing_P.Saturation1_LowerSat)
  {
    plant_block_swing_B.Saturation1 = plant_block_swing_P.Saturation1_LowerSat;
  } else {
    plant_block_swing_B.Saturation1 = rtb_gimbalmotorvoltage;
  }

  /* End of Saturate: '<Root>/Saturation1' */
  if (rtmIsMajorTimeStep(plant_block_swing_M)) {
  }
}

/* Model update function */
void plant_block_swing_update(void)
{
  /* Update for Derivative: '<Root>/Derivative' */
  {
    real_T timeStampA = plant_block_swing_DW.Derivative_RWORK.TimeStampA;
    real_T timeStampB = plant_block_swing_DW.Derivative_RWORK.TimeStampB;
    real_T* lastTime = &plant_block_swing_DW.Derivative_RWORK.TimeStampA;
    real_T* lastU = &plant_block_swing_DW.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &plant_block_swing_DW.Derivative_RWORK.TimeStampB;
        lastU = &plant_block_swing_DW.Derivative_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &plant_block_swing_DW.Derivative_RWORK.TimeStampB;
        lastU = &plant_block_swing_DW.Derivative_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = plant_block_swing_M->Timing.t[0];
    *lastU++ = plant_block_swing_B.Gain4;
  }

  /* Update for Derivative: '<Root>/Derivative1' */
  {
    real_T timeStampA = plant_block_swing_DW.Derivative1_RWORK.TimeStampA;
    real_T timeStampB = plant_block_swing_DW.Derivative1_RWORK.TimeStampB;
    real_T* lastTime = &plant_block_swing_DW.Derivative1_RWORK.TimeStampA;
    real_T* lastU = &plant_block_swing_DW.Derivative1_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &plant_block_swing_DW.Derivative1_RWORK.TimeStampB;
        lastU = &plant_block_swing_DW.Derivative1_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &plant_block_swing_DW.Derivative1_RWORK.TimeStampB;
        lastU = &plant_block_swing_DW.Derivative1_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = plant_block_swing_M->Timing.t[0];
    *lastU++ = plant_block_swing_B.Gain1;
  }

  if (rtmIsMajorTimeStep(plant_block_swing_M)) {
    /* Update for UnitDelay: '<S5>/FixPt Unit Delay1' */
    plant_block_swing_DW.FixPtUnitDelay1_DSTATE = plant_block_swing_B.Reset;
  }

  if (rtmIsMajorTimeStep(plant_block_swing_M)) {
    rt_ertODEUpdateContinuousStates(&plant_block_swing_M->solverInfo);
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
  if (!(++plant_block_swing_M->Timing.clockTick0)) {
    ++plant_block_swing_M->Timing.clockTickH0;
  }

  plant_block_swing_M->Timing.t[0] = rtsiGetSolverStopTime
    (&plant_block_swing_M->solverInfo);

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
    if (!(++plant_block_swing_M->Timing.clockTick1)) {
      ++plant_block_swing_M->Timing.clockTickH1;
    }

    plant_block_swing_M->Timing.t[1] = plant_block_swing_M->Timing.clockTick1 *
      plant_block_swing_M->Timing.stepSize1 +
      plant_block_swing_M->Timing.clockTickH1 *
      plant_block_swing_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void plant_block_swing_derivatives(void)
{
  XDot_plant_block_swing_T *_rtXdot;
  _rtXdot = ((XDot_plant_block_swing_T *) plant_block_swing_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  {
    ((XDot_plant_block_swing_T *) plant_block_swing_M->ModelData.derivs)
      ->TransferFcn1_CSTATE = plant_block_swing_B.Gain5_f;
    ((XDot_plant_block_swing_T *) plant_block_swing_M->ModelData.derivs)
      ->TransferFcn1_CSTATE += (plant_block_swing_P.TransferFcn1_A)*
      plant_block_swing_X.TransferFcn1_CSTATE;
  }

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE = plant_block_swing_B.IntegralGain;

  /* Derivatives for Integrator: '<S2>/Filter' */
  _rtXdot->Filter_CSTATE = plant_block_swing_B.FilterCoefficient;
}

/* Model initialize function */
void plant_block_swing_initialize(void)
{
  /* Level2 S-Function Block: '<S1>/S-Function' (ECPDSPDriver) */
  {
    SimStruct *rts = plant_block_swing_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  plant_block_swing_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  plant_block_swing_DW.Derivative_RWORK.TimeStampA = rtInf;
  plant_block_swing_DW.Derivative_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  plant_block_swing_X.Integrator_CSTATE = plant_block_swing_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S2>/Filter' */
  plant_block_swing_X.Filter_CSTATE = plant_block_swing_P.Filter_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  plant_block_swing_DW.Derivative1_RWORK.TimeStampA = rtInf;
  plant_block_swing_DW.Derivative1_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for UnitDelay: '<S5>/FixPt Unit Delay1' */
  plant_block_swing_DW.FixPtUnitDelay1_DSTATE =
    plant_block_swing_P.FixPtUnitDelay1_InitialConditio;
}

/* Model terminate function */
void plant_block_swing_terminate(void)
{
  /* Level2 S-Function Block: '<S1>/S-Function' (ECPDSPDriver) */
  {
    SimStruct *rts = plant_block_swing_M->childSfunctions[0];
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
  plant_block_swing_output();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  plant_block_swing_update();

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
  plant_block_swing_initialize();
}

void MdlTerminate(void)
{
  plant_block_swing_terminate();
}

/* Registration function */
RT_MODEL_plant_block_swing_T *plant_block_swing(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)plant_block_swing_M, 0,
                sizeof(RT_MODEL_plant_block_swing_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&plant_block_swing_M->solverInfo,
                          &plant_block_swing_M->Timing.simTimeStep);
    rtsiSetTPtr(&plant_block_swing_M->solverInfo, &rtmGetTPtr
                (plant_block_swing_M));
    rtsiSetStepSizePtr(&plant_block_swing_M->solverInfo,
                       &plant_block_swing_M->Timing.stepSize0);
    rtsiSetdXPtr(&plant_block_swing_M->solverInfo,
                 &plant_block_swing_M->ModelData.derivs);
    rtsiSetContStatesPtr(&plant_block_swing_M->solverInfo,
                         &plant_block_swing_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&plant_block_swing_M->solverInfo,
      &plant_block_swing_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&plant_block_swing_M->solverInfo, (&rtmGetErrorStatus
      (plant_block_swing_M)));
    rtsiSetRTModelPtr(&plant_block_swing_M->solverInfo, plant_block_swing_M);
  }

  rtsiSetSimTimeStep(&plant_block_swing_M->solverInfo, MAJOR_TIME_STEP);
  plant_block_swing_M->ModelData.intgData.f[0] =
    plant_block_swing_M->ModelData.odeF[0];
  plant_block_swing_M->ModelData.contStates = ((real_T *) &plant_block_swing_X);
  rtsiSetSolverData(&plant_block_swing_M->solverInfo, (void *)
                    &plant_block_swing_M->ModelData.intgData);
  rtsiSetSolverName(&plant_block_swing_M->solverInfo,"ode1");
  plant_block_swing_M->solverInfoPtr = (&plant_block_swing_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = plant_block_swing_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    plant_block_swing_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    plant_block_swing_M->Timing.sampleTimes =
      (&plant_block_swing_M->Timing.sampleTimesArray[0]);
    plant_block_swing_M->Timing.offsetTimes =
      (&plant_block_swing_M->Timing.offsetTimesArray[0]);

    /* task periods */
    plant_block_swing_M->Timing.sampleTimes[0] = (0.0);
    plant_block_swing_M->Timing.sampleTimes[1] = (0.008);

    /* task offsets */
    plant_block_swing_M->Timing.offsetTimes[0] = (0.0);
    plant_block_swing_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(plant_block_swing_M, &plant_block_swing_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = plant_block_swing_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    plant_block_swing_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(plant_block_swing_M, 120.0);
  plant_block_swing_M->Timing.stepSize0 = 0.008;
  plant_block_swing_M->Timing.stepSize1 = 0.008;

  /* External mode info */
  plant_block_swing_M->Sizes.checksums[0] = (1975002867U);
  plant_block_swing_M->Sizes.checksums[1] = (2153785667U);
  plant_block_swing_M->Sizes.checksums[2] = (2065260775U);
  plant_block_swing_M->Sizes.checksums[3] = (1936540547U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    plant_block_swing_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(plant_block_swing_M->extModeInfo,
      &plant_block_swing_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(plant_block_swing_M->extModeInfo,
                        plant_block_swing_M->Sizes.checksums);
    rteiSetTPtr(plant_block_swing_M->extModeInfo, rtmGetTPtr(plant_block_swing_M));
  }

  plant_block_swing_M->solverInfoPtr = (&plant_block_swing_M->solverInfo);
  plant_block_swing_M->Timing.stepSize = (0.008);
  rtsiSetFixedStepSize(&plant_block_swing_M->solverInfo, 0.008);
  rtsiSetSolverMode(&plant_block_swing_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  plant_block_swing_M->ModelData.blockIO = ((void *) &plant_block_swing_B);

  {
    int_T i;
    for (i = 0; i < 5; i++) {
      plant_block_swing_B.SFunction[i] = 0.0;
    }

    plant_block_swing_B.TransferFcn1 = 0.0;
    plant_block_swing_B.Gain4 = 0.0;
    plant_block_swing_B.Derivative = 0.0;
    plant_block_swing_B.Gain = 0.0;
    plant_block_swing_B.FilterCoefficient = 0.0;
    plant_block_swing_B.Saturation = 0.0;
    plant_block_swing_B.Gain1 = 0.0;
    plant_block_swing_B.Derivative1 = 0.0;
    plant_block_swing_B.FixPtUnitDelay1 = 0.0;
    plant_block_swing_B.Reset = 0.0;
    plant_block_swing_B.Gain5 = 0.0;
    plant_block_swing_B.Gain3 = 0.0;
    plant_block_swing_B.E = 0.0;
    plant_block_swing_B.TrigonometricFunction1 = 0.0;
    plant_block_swing_B.Gain5_f = 0.0;
    plant_block_swing_B.IntegralGain = 0.0;
    plant_block_swing_B.Saturation1 = 0.0;
  }

  /* parameters */
  plant_block_swing_M->ModelData.defaultParam = ((real_T *)&plant_block_swing_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &plant_block_swing_X;
    plant_block_swing_M->ModelData.contStates = (x);
    (void) memset((void *)&plant_block_swing_X, 0,
                  sizeof(X_plant_block_swing_T));
  }

  /* states (dwork) */
  plant_block_swing_M->ModelData.dwork = ((void *) &plant_block_swing_DW);
  (void) memset((void *)&plant_block_swing_DW, 0,
                sizeof(DW_plant_block_swing_T));
  plant_block_swing_DW.FixPtUnitDelay1_DSTATE = 0.0;
  plant_block_swing_DW.Derivative_RWORK.TimeStampA = 0.0;
  plant_block_swing_DW.Derivative_RWORK.LastUAtTimeA = 0.0;
  plant_block_swing_DW.Derivative_RWORK.TimeStampB = 0.0;
  plant_block_swing_DW.Derivative_RWORK.LastUAtTimeB = 0.0;
  plant_block_swing_DW.Derivative1_RWORK.TimeStampA = 0.0;
  plant_block_swing_DW.Derivative1_RWORK.LastUAtTimeA = 0.0;
  plant_block_swing_DW.Derivative1_RWORK.TimeStampB = 0.0;
  plant_block_swing_DW.Derivative1_RWORK.LastUAtTimeB = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    plant_block_swing_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &plant_block_swing_M->NonInlinedSFcns.sfcnInfo;
    plant_block_swing_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(plant_block_swing_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &plant_block_swing_M->Sizes.numSampTimes);
    plant_block_swing_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (plant_block_swing_M)[0]);
    plant_block_swing_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (plant_block_swing_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,plant_block_swing_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(plant_block_swing_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(plant_block_swing_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (plant_block_swing_M));
    rtssSetStepSizePtr(sfcnInfo, &plant_block_swing_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(plant_block_swing_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &plant_block_swing_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &plant_block_swing_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &plant_block_swing_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &plant_block_swing_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &plant_block_swing_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &plant_block_swing_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &plant_block_swing_M->solverInfoPtr);
  }

  plant_block_swing_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&plant_block_swing_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  1*sizeof(SimStruct));
    plant_block_swing_M->childSfunctions =
      (&plant_block_swing_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    plant_block_swing_M->childSfunctions[0] =
      (&plant_block_swing_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: plant_block_swing/<S1>/S-Function (ECPDSPDriver) */
    {
      SimStruct *rts = plant_block_swing_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = plant_block_swing_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = plant_block_swing_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = plant_block_swing_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &plant_block_swing_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, plant_block_swing_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &plant_block_swing_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &plant_block_swing_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &plant_block_swing_M->NonInlinedSFcns.statesInfo2
                         [0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &plant_block_swing_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &plant_block_swing_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &plant_block_swing_B.Saturation;
          sfcnUPtrs[1] = &plant_block_swing_B.Saturation1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &plant_block_swing_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            plant_block_swing_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "plant_block_swing/ECPDSP Driver/S-Function");
      ssSetRTModel(rts,plant_block_swing_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &plant_block_swing_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)plant_block_swing_P.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)plant_block_swing_P.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)plant_block_swing_P.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)plant_block_swing_P.SFunction_P4_Size);
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
  plant_block_swing_M->Sizes.numContStates = (3);/* Number of continuous states */
  plant_block_swing_M->Sizes.numY = (0);/* Number of model outputs */
  plant_block_swing_M->Sizes.numU = (0);/* Number of model inputs */
  plant_block_swing_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  plant_block_swing_M->Sizes.numSampTimes = (2);/* Number of sample times */
  plant_block_swing_M->Sizes.numBlocks = (61);/* Number of blocks */
  plant_block_swing_M->Sizes.numBlockIO = (18);/* Number of block outputs */
  plant_block_swing_M->Sizes.numBlockPrms = (53);/* Sum of parameter "widths" */
  return plant_block_swing_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
