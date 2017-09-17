/*
 * plant_block.c
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
#include "plant_block_dt.h"

/* list of Real-Time Windows Target timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.008, 0.0,
};

/* Block signals (auto storage) */
B_plant_block_T plant_block_B;

/* Continuous states */
X_plant_block_T plant_block_X;

/* Block states (auto storage) */
DW_plant_block_T plant_block_DW;

/* Real-time model */
RT_MODEL_plant_block_T plant_block_M_;
RT_MODEL_plant_block_T *const plant_block_M = &plant_block_M_;

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
  plant_block_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void plant_block_output(void)
{
  real_T currentTime;
  real_T currentTime_0;
  real_T currentTime_1;
  real_T rtb_Sum;
  real_T u;
  if (rtmIsMajorTimeStep(plant_block_M)) {
    /* set solver stop time */
    if (!(plant_block_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&plant_block_M->solverInfo,
                            ((plant_block_M->Timing.clockTickH0 + 1) *
        plant_block_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&plant_block_M->solverInfo,
                            ((plant_block_M->Timing.clockTick0 + 1) *
        plant_block_M->Timing.stepSize0 + plant_block_M->Timing.clockTickH0 *
        plant_block_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(plant_block_M)) {
    plant_block_M->Timing.t[0] = rtsiGetT(&plant_block_M->solverInfo);
  }

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  plant_block_B.TransferFcn1 = plant_block_P.TransferFcn1_C*
    plant_block_X.TransferFcn1_CSTATE;
  if (rtmIsMajorTimeStep(plant_block_M)) {
    /* Level2 S-Function Block: '<S1>/S-Function' (ECPDSPDriver) */
    {
      SimStruct *rts = plant_block_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<Root>/Gain4' */
    plant_block_B.Gain4 = plant_block_P.Gain4_Gain * plant_block_B.SFunction[0];
  }

  /* Derivative: '<Root>/Derivative' */
  {
    real_T t = plant_block_M->Timing.t[0];
    real_T timeStampA = plant_block_DW.Derivative_RWORK.TimeStampA;
    real_T timeStampB = plant_block_DW.Derivative_RWORK.TimeStampB;
    real_T *lastU = &plant_block_DW.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      plant_block_B.Derivative = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &plant_block_DW.Derivative_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &plant_block_DW.Derivative_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      plant_block_B.Derivative = (plant_block_B.Gain4 - *lastU++) / deltaT;
    }
  }

  if (rtmIsMajorTimeStep(plant_block_M)) {
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Sum = plant_block_P.Constant_Value - plant_block_B.TransferFcn1;

  /* Gain: '<S2>/Filter Coefficient' incorporates:
   *  Gain: '<S2>/Derivative Gain'
   *  Integrator: '<S2>/Filter'
   *  Sum: '<S2>/SumD'
   */
  plant_block_B.FilterCoefficient = (plant_block_P.DerivativeGain_Gain * rtb_Sum
    - plant_block_X.Filter_CSTATE) * plant_block_P.FilterCoefficient_Gain;

  /* Sum: '<S2>/Sum' incorporates:
   *  Gain: '<S2>/Proportional Gain'
   *  Integrator: '<S2>/Integrator'
   */
  u = (plant_block_P.ProportionalGain_Gain * rtb_Sum +
       plant_block_X.Integrator_CSTATE) + plant_block_B.FilterCoefficient;

  /* Saturate: '<Root>/Saturation' */
  if (u >= plant_block_P.Saturation_UpperSat) {
    plant_block_B.Saturation = plant_block_P.Saturation_UpperSat;
  } else if (u <= plant_block_P.Saturation_LowerSat) {
    plant_block_B.Saturation = plant_block_P.Saturation_LowerSat;
  } else {
    plant_block_B.Saturation = u;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(plant_block_M)) {
    /* Gain: '<Root>/Gain1' */
    plant_block_B.Gain1 = plant_block_P.Gain1_Gain * plant_block_B.SFunction[2];
  }

  /* Step: '<Root>/Step on' */
  u = plant_block_M->Timing.t[0];

  /* Step: '<Root>/Step off' */
  currentTime = plant_block_M->Timing.t[0];

  /* Step: '<Root>/Step on1' */
  currentTime_0 = plant_block_M->Timing.t[0];

  /* Step: '<Root>/Step off1' */
  currentTime_1 = plant_block_M->Timing.t[0];

  /* Step: '<Root>/Step on' */
  if (u < plant_block_P.Stepon_Time) {
    u = plant_block_P.Stepon_Y0;
  } else {
    u = plant_block_P.Stepon_YFinal;
  }

  /* Step: '<Root>/Step off' */
  if (currentTime < plant_block_P.Stepoff_Time) {
    currentTime = plant_block_P.Stepoff_Y0;
  } else {
    currentTime = plant_block_P.Stepoff_YFinal;
  }

  /* Step: '<Root>/Step on1' */
  if (currentTime_0 < plant_block_P.Stepon1_Time) {
    currentTime_0 = plant_block_P.Stepon1_Y0;
  } else {
    currentTime_0 = plant_block_P.Stepon1_YFinal;
  }

  /* Step: '<Root>/Step off1' */
  if (currentTime_1 < plant_block_P.Stepoff1_Time) {
    currentTime_1 = plant_block_P.Stepoff1_Y0;
  } else {
    currentTime_1 = plant_block_P.Stepoff1_YFinal;
  }

  /* Sum: '<Root>/Add' */
  plant_block_B.gimbalmotorvoltage = ((u + currentTime) + currentTime_0) +
    currentTime_1;

  /* Gain: '<Root>/Gain5' */
  plant_block_B.Gain5 = plant_block_P.Gain5_Gain * plant_block_B.Derivative;

  /* Gain: '<S2>/Integral Gain' */
  plant_block_B.IntegralGain = plant_block_P.IntegralGain_Gain * rtb_Sum;
}

/* Model update function */
void plant_block_update(void)
{
  /* Update for Derivative: '<Root>/Derivative' */
  {
    real_T timeStampA = plant_block_DW.Derivative_RWORK.TimeStampA;
    real_T timeStampB = plant_block_DW.Derivative_RWORK.TimeStampB;
    real_T* lastTime = &plant_block_DW.Derivative_RWORK.TimeStampA;
    real_T* lastU = &plant_block_DW.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &plant_block_DW.Derivative_RWORK.TimeStampB;
        lastU = &plant_block_DW.Derivative_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &plant_block_DW.Derivative_RWORK.TimeStampB;
        lastU = &plant_block_DW.Derivative_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = plant_block_M->Timing.t[0];
    *lastU++ = plant_block_B.Gain4;
  }

  if (rtmIsMajorTimeStep(plant_block_M)) {
    rt_ertODEUpdateContinuousStates(&plant_block_M->solverInfo);
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
  if (!(++plant_block_M->Timing.clockTick0)) {
    ++plant_block_M->Timing.clockTickH0;
  }

  plant_block_M->Timing.t[0] = rtsiGetSolverStopTime(&plant_block_M->solverInfo);

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
    if (!(++plant_block_M->Timing.clockTick1)) {
      ++plant_block_M->Timing.clockTickH1;
    }

    plant_block_M->Timing.t[1] = plant_block_M->Timing.clockTick1 *
      plant_block_M->Timing.stepSize1 + plant_block_M->Timing.clockTickH1 *
      plant_block_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void plant_block_derivatives(void)
{
  XDot_plant_block_T *_rtXdot;
  _rtXdot = ((XDot_plant_block_T *) plant_block_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  {
    ((XDot_plant_block_T *) plant_block_M->ModelData.derivs)
      ->TransferFcn1_CSTATE = plant_block_B.Gain5;
    ((XDot_plant_block_T *) plant_block_M->ModelData.derivs)
      ->TransferFcn1_CSTATE += (plant_block_P.TransferFcn1_A)*
      plant_block_X.TransferFcn1_CSTATE;
  }

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE = plant_block_B.IntegralGain;

  /* Derivatives for Integrator: '<S2>/Filter' */
  _rtXdot->Filter_CSTATE = plant_block_B.FilterCoefficient;
}

/* Model initialize function */
void plant_block_initialize(void)
{
  /* Level2 S-Function Block: '<S1>/S-Function' (ECPDSPDriver) */
  {
    SimStruct *rts = plant_block_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  plant_block_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  plant_block_DW.Derivative_RWORK.TimeStampA = rtInf;
  plant_block_DW.Derivative_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  plant_block_X.Integrator_CSTATE = plant_block_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S2>/Filter' */
  plant_block_X.Filter_CSTATE = plant_block_P.Filter_IC;
}

/* Model terminate function */
void plant_block_terminate(void)
{
  /* Level2 S-Function Block: '<S1>/S-Function' (ECPDSPDriver) */
  {
    SimStruct *rts = plant_block_M->childSfunctions[0];
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
  plant_block_output();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  plant_block_update();

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
  plant_block_initialize();
}

void MdlTerminate(void)
{
  plant_block_terminate();
}

/* Registration function */
RT_MODEL_plant_block_T *plant_block(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)plant_block_M, 0,
                sizeof(RT_MODEL_plant_block_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&plant_block_M->solverInfo,
                          &plant_block_M->Timing.simTimeStep);
    rtsiSetTPtr(&plant_block_M->solverInfo, &rtmGetTPtr(plant_block_M));
    rtsiSetStepSizePtr(&plant_block_M->solverInfo,
                       &plant_block_M->Timing.stepSize0);
    rtsiSetdXPtr(&plant_block_M->solverInfo, &plant_block_M->ModelData.derivs);
    rtsiSetContStatesPtr(&plant_block_M->solverInfo,
                         &plant_block_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&plant_block_M->solverInfo,
      &plant_block_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&plant_block_M->solverInfo, (&rtmGetErrorStatus
      (plant_block_M)));
    rtsiSetRTModelPtr(&plant_block_M->solverInfo, plant_block_M);
  }

  rtsiSetSimTimeStep(&plant_block_M->solverInfo, MAJOR_TIME_STEP);
  plant_block_M->ModelData.intgData.f[0] = plant_block_M->ModelData.odeF[0];
  plant_block_M->ModelData.contStates = ((real_T *) &plant_block_X);
  rtsiSetSolverData(&plant_block_M->solverInfo, (void *)
                    &plant_block_M->ModelData.intgData);
  rtsiSetSolverName(&plant_block_M->solverInfo,"ode1");
  plant_block_M->solverInfoPtr = (&plant_block_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = plant_block_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    plant_block_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    plant_block_M->Timing.sampleTimes = (&plant_block_M->
      Timing.sampleTimesArray[0]);
    plant_block_M->Timing.offsetTimes = (&plant_block_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    plant_block_M->Timing.sampleTimes[0] = (0.0);
    plant_block_M->Timing.sampleTimes[1] = (0.008);

    /* task offsets */
    plant_block_M->Timing.offsetTimes[0] = (0.0);
    plant_block_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(plant_block_M, &plant_block_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = plant_block_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    plant_block_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(plant_block_M, 120.0);
  plant_block_M->Timing.stepSize0 = 0.008;
  plant_block_M->Timing.stepSize1 = 0.008;

  /* External mode info */
  plant_block_M->Sizes.checksums[0] = (3990516266U);
  plant_block_M->Sizes.checksums[1] = (3690614074U);
  plant_block_M->Sizes.checksums[2] = (2192375545U);
  plant_block_M->Sizes.checksums[3] = (294007649U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    plant_block_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(plant_block_M->extModeInfo,
      &plant_block_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(plant_block_M->extModeInfo,
                        plant_block_M->Sizes.checksums);
    rteiSetTPtr(plant_block_M->extModeInfo, rtmGetTPtr(plant_block_M));
  }

  plant_block_M->solverInfoPtr = (&plant_block_M->solverInfo);
  plant_block_M->Timing.stepSize = (0.008);
  rtsiSetFixedStepSize(&plant_block_M->solverInfo, 0.008);
  rtsiSetSolverMode(&plant_block_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  plant_block_M->ModelData.blockIO = ((void *) &plant_block_B);

  {
    int_T i;
    for (i = 0; i < 5; i++) {
      plant_block_B.SFunction[i] = 0.0;
    }

    plant_block_B.TransferFcn1 = 0.0;
    plant_block_B.Gain4 = 0.0;
    plant_block_B.Derivative = 0.0;
    plant_block_B.FilterCoefficient = 0.0;
    plant_block_B.Saturation = 0.0;
    plant_block_B.Gain1 = 0.0;
    plant_block_B.gimbalmotorvoltage = 0.0;
    plant_block_B.Gain5 = 0.0;
    plant_block_B.IntegralGain = 0.0;
  }

  /* parameters */
  plant_block_M->ModelData.defaultParam = ((real_T *)&plant_block_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &plant_block_X;
    plant_block_M->ModelData.contStates = (x);
    (void) memset((void *)&plant_block_X, 0,
                  sizeof(X_plant_block_T));
  }

  /* states (dwork) */
  plant_block_M->ModelData.dwork = ((void *) &plant_block_DW);
  (void) memset((void *)&plant_block_DW, 0,
                sizeof(DW_plant_block_T));
  plant_block_DW.Derivative_RWORK.TimeStampA = 0.0;
  plant_block_DW.Derivative_RWORK.LastUAtTimeA = 0.0;
  plant_block_DW.Derivative_RWORK.TimeStampB = 0.0;
  plant_block_DW.Derivative_RWORK.LastUAtTimeB = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    plant_block_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &plant_block_M->NonInlinedSFcns.sfcnInfo;
    plant_block_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(plant_block_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &plant_block_M->Sizes.numSampTimes);
    plant_block_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(plant_block_M)
      [0]);
    plant_block_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(plant_block_M)
      [1]);
    rtssSetTPtrPtr(sfcnInfo,plant_block_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(plant_block_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(plant_block_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(plant_block_M));
    rtssSetStepSizePtr(sfcnInfo, &plant_block_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(plant_block_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &plant_block_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &plant_block_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &plant_block_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &plant_block_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &plant_block_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &plant_block_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &plant_block_M->solverInfoPtr);
  }

  plant_block_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&plant_block_M->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    plant_block_M->childSfunctions =
      (&plant_block_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    plant_block_M->childSfunctions[0] =
      (&plant_block_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: plant_block/<S1>/S-Function (ECPDSPDriver) */
    {
      SimStruct *rts = plant_block_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = plant_block_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = plant_block_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = plant_block_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &plant_block_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, plant_block_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &plant_block_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &plant_block_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &plant_block_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &plant_block_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &plant_block_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &plant_block_B.Saturation;
          sfcnUPtrs[1] = &plant_block_B.gimbalmotorvoltage;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &plant_block_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) plant_block_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "plant_block/ECPDSP Driver/S-Function");
      ssSetRTModel(rts,plant_block_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &plant_block_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)plant_block_P.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)plant_block_P.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)plant_block_P.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)plant_block_P.SFunction_P4_Size);
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
  plant_block_M->Sizes.numContStates = (3);/* Number of continuous states */
  plant_block_M->Sizes.numY = (0);     /* Number of model outputs */
  plant_block_M->Sizes.numU = (0);     /* Number of model inputs */
  plant_block_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  plant_block_M->Sizes.numSampTimes = (2);/* Number of sample times */
  plant_block_M->Sizes.numBlocks = (31);/* Number of blocks */
  plant_block_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  plant_block_M->Sizes.numBlockPrms = (43);/* Sum of parameter "widths" */
  return plant_block_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
