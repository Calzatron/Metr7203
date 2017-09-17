/*
 * State_Flow_v0.c
 *
 * Code generation for model "State_Flow_v0".
 *
 * Model version              : 1.35
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Mon Sep 11 08:59:18 2017
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Specified
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include <math.h>
#include "State_Flow_v0.h"
#include "State_Flow_v0_private.h"
#include "State_Flow_v0_dt.h"

/* user code (top of parameter file) */
const int_T gblNumToFiles = 0;
const int_T gblNumFrFiles = 0;
const int_T gblNumFrWksBlocks = 0;
const char *gblSlvrJacPatternFileName =
  "State_Flow_v0_rsim_rtw\\State_Flow_v0_Jpattern.mat";

/* Root inports information  */
const int_T gblNumRootInportBlks = 0;
const int_T gblNumModelInputs = 0;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
const int_T gblInportDataTypeIdx[] = { -1 };

const int_T gblInportDims[] = { -1 } ;

const int_T gblInportComplex[] = { -1 };

const int_T gblInportInterpoFlag[] = { -1 };

const int_T gblInportContinuous[] = { -1 };

#include "simstruc.h"
#include "fixedpoint.h"

/* Block signals (auto storage) */
B rtB;

/* Continuous states */
X rtX;

/* Block states (auto storage) */
DW rtDW;

/* Parent Simstruct */
static SimStruct model_S;
SimStruct *const rtS = &model_S;

/* Initial conditions for root system: '<Root>' */
void MdlInitialize(void)
{
  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  rtDW.Derivative_RWORK.TimeStampA = rtInf;
  rtDW.Derivative_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  rtX.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  rtX.Integrator_CSTATE = rtP.Integrator_IC;

  /* InitializeConditions for Integrator: '<S4>/Filter' */
  rtX.Filter_CSTATE = rtP.Filter_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  rtDW.Derivative1_RWORK.TimeStampA = rtInf;
  rtDW.Derivative1_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for UnitDelay: '<S9>/FixPt Unit Delay1' */
  rtDW.FixPtUnitDelay1_DSTATE = rtP.FixPtUnitDelay1_InitialConditio;
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{
  /* Level2 S-Function Block: '<S1>/S-Function' (ECPDSPDriver) */
  {
    SimStruct *rts = ssGetSFunction(rtS, 0);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  MdlInitialize();
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_theta_dot;
  real_T rtb_Derivative;
  real_T rtb_TransferFcn1;
  real_T rtb_E;
  real_T rtb_Gain5;
  real_T rtb_Gain_c;
  real_T rtb_Sum;
  real_T rtb_ProportionalGain;
  real_T rtb_DerivativeGain;
  if (ssIsSampleHit(rtS, 2, 0)) {
    /* Level2 S-Function Block: '<S1>/S-Function' (ECPDSPDriver) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 0);
      sfcnOutputs(rts, 0);
    }

    /* Gain: '<Root>/Gain4' */
    rtB.Gain4 = rtP.Gain4_Gain * rtB.SFunction[0];
  }

  /* Derivative: '<Root>/Derivative' */
  {
    real_T t = ssGetTaskTime(rtS,0);
    real_T timeStampA = rtDW.Derivative_RWORK.TimeStampA;
    real_T timeStampB = rtDW.Derivative_RWORK.TimeStampB;
    real_T *lastU = &rtDW.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      rtb_Derivative = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &rtDW.Derivative_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &rtDW.Derivative_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      rtb_Derivative = (rtB.Gain4 - *lastU++) / deltaT;
    }
  }

  if (ssIsSampleHit(rtS, 2, 0)) {
    /* Gain: '<Root>/Gain' */
    rtb_Gain_c = rtP.Gain_Gain * rtB.SFunction[1];
  }

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  rtb_TransferFcn1 = rtP.TransferFcn1_C*rtX.TransferFcn1_CSTATE;

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  rtb_Sum = rtP.Constant1_Value - rtb_TransferFcn1;

  /* Gain: '<S4>/Proportional Gain' */
  rtb_ProportionalGain = rtP.ProportionalGain_Gain * rtb_Sum;

  /* Integrator: '<S4>/Integrator' */
  rtb_E = rtX.Integrator_CSTATE;

  /* Gain: '<S4>/Derivative Gain' */
  rtb_DerivativeGain = rtP.DerivativeGain_Gain * rtb_Sum;

  /* Integrator: '<S4>/Filter' */
  rtb_Gain5 = rtX.Filter_CSTATE;

  /* Gain: '<S4>/Filter Coefficient' incorporates:
   *  Sum: '<S4>/SumD'
   */
  rtB.FilterCoefficient = (rtb_DerivativeGain - rtb_Gain5) *
    rtP.FilterCoefficient_Gain;

  /* Sum: '<S4>/Sum' */
  rtB.Sum = (rtb_ProportionalGain + rtb_E) + rtB.FilterCoefficient;

  /* Saturate: '<Root>/Saturation' */
  if (ssIsMajorTimeStep(rtS)) {
    rtDW.Saturation_MODE = rtB.Sum >= rtP.Saturation_UpperSat ? 1 : rtB.Sum >
      rtP.Saturation_LowerSat ? 0 : -1;
  }

  rtB.Saturation = rtDW.Saturation_MODE == 1 ? rtP.Saturation_UpperSat :
    rtDW.Saturation_MODE == -1 ? rtP.Saturation_LowerSat : rtB.Sum;

  /* End of Saturate: '<Root>/Saturation' */
  if (ssIsSampleHit(rtS, 2, 0)) {
    /* Gain: '<Root>/Gain1' */
    rtB.theta = rtP.Gain1_Gain * rtB.SFunction[2];
  }

  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Step: '<Root>/Step on' */
    if (ssIsMajorTimeStep(rtS)) {
      rtDW.Stepon_MODE = (ssGetTaskTime(rtS,1) >= rtP.Stepon_Time);
    }

    if (rtDW.Stepon_MODE == 1) {
      rtB.Stepon = rtP.Stepon_YFinal;
    } else {
      rtB.Stepon = rtP.Stepon_Y0;
    }

    /* End of Step: '<Root>/Step on' */

    /* Step: '<Root>/Step off' */
    if (ssIsMajorTimeStep(rtS)) {
      rtDW.Stepoff_MODE = (ssGetTaskTime(rtS,1) >= rtP.Stepoff_Time);
    }

    if (rtDW.Stepoff_MODE == 1) {
      rtB.Stepoff = rtP.Stepoff_YFinal;
    } else {
      rtB.Stepoff = rtP.Stepoff_Y0;
    }

    /* End of Step: '<Root>/Step off' */
  }

  /* Derivative: '<Root>/Derivative1' */
  {
    real_T t = ssGetTaskTime(rtS,0);
    real_T timeStampA = rtDW.Derivative1_RWORK.TimeStampA;
    real_T timeStampB = rtDW.Derivative1_RWORK.TimeStampB;
    real_T *lastU = &rtDW.Derivative1_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      rtb_theta_dot = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &rtDW.Derivative1_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &rtDW.Derivative1_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      rtb_theta_dot = (rtB.theta - *lastU++) / deltaT;
    }
  }

  if (ssIsSampleHit(rtS, 1, 0)) {
    /* UnitDelay: '<S9>/FixPt Unit Delay1' */
    rtB.FixPtUnitDelay1 = rtDW.FixPtUnitDelay1_DSTATE;
  }

  /* Switch: '<S9>/Reset' incorporates:
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S9>/Initial Condition'
   *  MinMax: '<S8>/MinMax'
   */
  if (rtP.Constant2_Value != 0.0) {
    rtB.Reset = rtP.InitialCondition_Value;
  } else if ((rtb_theta_dot >= rtB.FixPtUnitDelay1) || rtIsNaN
             (rtB.FixPtUnitDelay1)) {
    /* MinMax: '<S8>/MinMax' */
    rtB.Reset = rtb_theta_dot;
  } else {
    /* MinMax: '<S8>/MinMax' */
    rtB.Reset = rtB.FixPtUnitDelay1;
  }

  /* End of Switch: '<S9>/Reset' */

  /* Sum: '<S6>/Sum2' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Gain: '<S6>/Gain4'
   */
  rtB.Sum2 = rtP.Gain4_Gain_j * rtB.Reset + rtP.Constant1_Value_g;

  /* Saturate: '<S6>/Saturation' */
  if (ssIsMajorTimeStep(rtS)) {
    rtDW.Saturation_MODE_l = rtB.Sum2 >= rtP.Saturation_UpperSat_h ? 1 :
      rtB.Sum2 > rtP.Saturation_LowerSat_j ? 0 : -1;
  }

  rtb_Gain5 = rtDW.Saturation_MODE_l == 1 ? rtP.Saturation_UpperSat_h :
    rtDW.Saturation_MODE_l == -1 ? rtP.Saturation_LowerSat_j : rtB.Sum2;

  /* End of Saturate: '<S6>/Saturation' */

  /* Gain: '<S6>/Gain5' */
  rtb_Gain5 *= rtP.Gain5_Gain;
  if (ssIsSampleHit(rtS, 2, 0)) {
    /* Trigonometry: '<S6>/Trigonometric Function' */
    rtB.TrigonometricFunction = cos(rtB.theta);
  }

  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Gain: '<S6>/Gain3' incorporates:
     *  Constant: '<S6>/Constant'
     *  Gain: '<S6>/Gain2'
     *  Sum: '<S6>/Sum1'
     */
    rtB.Gain3 = (rtB.TrigonometricFunction + rtP.Constant_Value) *
      rtP.Gain2_Gain * rtP.Gain3_Gain;
  }

  /* Sum: '<S6>/Sum' incorporates:
   *  Gain: '<S6>/Gain'
   *  Math: '<S6>/Math Function'
   *
   * About '<S6>/Math Function':
   *  Operator: magnitude^2
   */
  rtb_E = rtb_theta_dot * rtb_theta_dot * rtP.Gain_Gain_i + rtB.Gain3;
  if (ssIsSampleHit(rtS, 2, 0)) {
    /* Trigonometry: '<S6>/Trigonometric Function1' */
    rtB.TrigonometricFunction1 = cos(rtB.theta);
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Gain: '<S6>/Gain1'
   *  Product: '<S6>/Product1'
   *  Product: '<S6>/Product2'
   *  Product: '<S6>/Product3'
   */
  rtB.gimbalmotorvoltage = rtb_E * rtB.TrigonometricFunction1 * rtb_theta_dot *
    rtb_Gain5 * rtP.Gain1_Gain_a + (rtB.Stepon + rtB.Stepoff);

  /* Gain: '<Root>/Gain5' */
  rtB.Gain5 = rtP.Gain5_Gain_b * rtb_Derivative;

  /* Gain: '<S4>/Integral Gain' */
  rtB.IntegralGain = rtP.IntegralGain_Gain * rtb_Sum;

  /* Saturate: '<Root>/Saturation1' */
  if (ssIsMajorTimeStep(rtS)) {
    rtDW.Saturation1_MODE = rtB.gimbalmotorvoltage >= rtP.Saturation1_UpperSat ?
      1 : rtB.gimbalmotorvoltage > rtP.Saturation1_LowerSat ? 0 : -1;
  }

  rtB.Saturation1 = rtDW.Saturation1_MODE == 1 ? rtP.Saturation1_UpperSat :
    rtDW.Saturation1_MODE == -1 ? rtP.Saturation1_LowerSat :
    rtB.gimbalmotorvoltage;

  /* End of Saturate: '<Root>/Saturation1' */

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{
  /* Update for Derivative: '<Root>/Derivative' */
  {
    real_T timeStampA = rtDW.Derivative_RWORK.TimeStampA;
    real_T timeStampB = rtDW.Derivative_RWORK.TimeStampB;
    real_T* lastTime = &rtDW.Derivative_RWORK.TimeStampA;
    real_T* lastU = &rtDW.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &rtDW.Derivative_RWORK.TimeStampB;
        lastU = &rtDW.Derivative_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &rtDW.Derivative_RWORK.TimeStampB;
        lastU = &rtDW.Derivative_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = ssGetTaskTime(rtS,0);
    *lastU++ = rtB.Gain4;
  }

  /* Update for Derivative: '<Root>/Derivative1' */
  {
    real_T timeStampA = rtDW.Derivative1_RWORK.TimeStampA;
    real_T timeStampB = rtDW.Derivative1_RWORK.TimeStampB;
    real_T* lastTime = &rtDW.Derivative1_RWORK.TimeStampA;
    real_T* lastU = &rtDW.Derivative1_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &rtDW.Derivative1_RWORK.TimeStampB;
        lastU = &rtDW.Derivative1_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &rtDW.Derivative1_RWORK.TimeStampB;
        lastU = &rtDW.Derivative1_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = ssGetTaskTime(rtS,0);
    *lastU++ = rtB.theta;
  }

  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Update for UnitDelay: '<S9>/FixPt Unit Delay1' */
    rtDW.FixPtUnitDelay1_DSTATE = rtB.Reset;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void MdlDerivatives(void)
{
  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  {
    ((XDot *) ssGetdX(rtS))->TransferFcn1_CSTATE = rtB.Gain5;
    ((XDot *) ssGetdX(rtS))->TransferFcn1_CSTATE += (rtP.TransferFcn1_A)*
      rtX.TransferFcn1_CSTATE;
  }

  /* Derivatives for Integrator: '<S4>/Integrator' */
  {
    ((XDot *) ssGetdX(rtS))->Integrator_CSTATE = rtB.IntegralGain;
  }

  /* Derivatives for Integrator: '<S4>/Filter' */
  {
    ((XDot *) ssGetdX(rtS))->Filter_CSTATE = rtB.FilterCoefficient;
  }
}

/* Projection for root system: '<Root>' */
void MdlProjection(void)
{
}

/* ZeroCrossings for root system: '<Root>' */
void MdlZeroCrossings(void)
{
  /* ZeroCrossings for Saturate: '<Root>/Saturation' */
  ((ZCV *) ssGetSolverZcSignalVector(rtS))->Saturation_UprLim_ZC = rtB.Sum -
    rtP.Saturation_UpperSat;
  ((ZCV *) ssGetSolverZcSignalVector(rtS))->Saturation_LwrLim_ZC = rtB.Sum -
    rtP.Saturation_LowerSat;

  /* ZeroCrossings for Step: '<Root>/Step on' */
  ((ZCV *) ssGetSolverZcSignalVector(rtS))->Stepon_StepTime_ZC = ssGetT(rtS) -
    rtP.Stepon_Time;

  /* ZeroCrossings for Step: '<Root>/Step off' */
  ((ZCV *) ssGetSolverZcSignalVector(rtS))->Stepoff_StepTime_ZC = ssGetT(rtS) -
    rtP.Stepoff_Time;

  /* ZeroCrossings for Saturate: '<S6>/Saturation' */
  ((ZCV *) ssGetSolverZcSignalVector(rtS))->Saturation_UprLim_ZC_n = rtB.Sum2 -
    rtP.Saturation_UpperSat_h;
  ((ZCV *) ssGetSolverZcSignalVector(rtS))->Saturation_LwrLim_ZC_m = rtB.Sum2 -
    rtP.Saturation_LowerSat_j;

  /* ZeroCrossings for Saturate: '<Root>/Saturation1' */
  ((ZCV *) ssGetSolverZcSignalVector(rtS))->Saturation1_UprLim_ZC =
    rtB.gimbalmotorvoltage - rtP.Saturation1_UpperSat;
  ((ZCV *) ssGetSolverZcSignalVector(rtS))->Saturation1_LwrLim_ZC =
    rtB.gimbalmotorvoltage - rtP.Saturation1_LowerSat;
}

/* Termination for root system: '<Root>' */
void MdlTerminate(void)
{
  /* Level2 S-Function Block: '<S1>/S-Function' (ECPDSPDriver) */
  {
    SimStruct *rts = ssGetSFunction(rtS, 0);
    sfcnTerminate(rts);
  }
}

/* Function to initialize sizes */
void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 3);          /* Number of continuous states */
  ssSetNumY(rtS, 0);                   /* Number of model outputs */
  ssSetNumU(rtS, 0);                   /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 0);      /* The model is not direct feedthrough */
  ssSetNumSampleTimes(rtS, 3);         /* Number of sample times */
  ssSetNumBlocks(rtS, 60);             /* Number of blocks */
  ssSetNumBlockIO(rtS, 18);            /* Number of block outputs */
  ssSetNumBlockParams(rtS, 53);        /* Sum of parameter "widths" */
}

/* Function to initialize sample times. */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.0);
  ssSetSampleTime(rtS, 1, 0.0);
  ssSetSampleTime(rtS, 2, 0.008);

  /* task offsets */
  ssSetOffsetTime(rtS, 0, 0.0);
  ssSetOffsetTime(rtS, 1, 1.0);
  ssSetOffsetTime(rtS, 2, 0.0);
}

/* Function to register the model */
SimStruct * State_Flow_v0(void)
{
  static struct _ssMdlInfo mdlInfo;
  (void) memset((char *)rtS, 0,
                sizeof(SimStruct));
  (void) memset((char *)&mdlInfo, 0,
                sizeof(struct _ssMdlInfo));
  ssSetMdlInfoPtr(rtS, &mdlInfo);

  /* timing info */
  {
    static time_T mdlPeriod[NSAMPLE_TIMES];
    static time_T mdlOffset[NSAMPLE_TIMES];
    static time_T mdlTaskTimes[NSAMPLE_TIMES];
    static int_T mdlTsMap[NSAMPLE_TIMES];
    static int_T mdlSampleHits[NSAMPLE_TIMES];
    static boolean_T mdlTNextWasAdjustedPtr[NSAMPLE_TIMES];
    static int_T mdlPerTaskSampleHits[NSAMPLE_TIMES * NSAMPLE_TIMES];
    static time_T mdlTimeOfNextSampleHit[NSAMPLE_TIMES];

    {
      int_T i;
      for (i = 0; i < NSAMPLE_TIMES; i++) {
        mdlPeriod[i] = 0.0;
        mdlOffset[i] = 0.0;
        mdlTaskTimes[i] = 0.0;
        mdlTsMap[i] = i;
        mdlSampleHits[i] = 1;
      }
    }

    ssSetSampleTimePtr(rtS, &mdlPeriod[0]);
    ssSetOffsetTimePtr(rtS, &mdlOffset[0]);
    ssSetSampleTimeTaskIDPtr(rtS, &mdlTsMap[0]);
    ssSetTPtr(rtS, &mdlTaskTimes[0]);
    ssSetSampleHitPtr(rtS, &mdlSampleHits[0]);
    ssSetTNextWasAdjustedPtr(rtS, &mdlTNextWasAdjustedPtr[0]);
    ssSetPerTaskSampleHitsPtr(rtS, &mdlPerTaskSampleHits[0]);
    ssSetTimeOfNextSampleHitPtr(rtS, &mdlTimeOfNextSampleHit[0]);
  }

  ssSetSolverMode(rtS, SOLVER_MODE_SINGLETASKING);

  /*
   * initialize model vectors and cache them in SimStruct
   */

  /* block I/O */
  {
    ssSetBlockIO(rtS, ((void *) &rtB));
    (void) memset(((void *) &rtB), 0,
                  sizeof(B));
  }

  /* parameters */
  ssSetDefaultParam(rtS, (real_T *) &rtP);

  /* states (continuous)*/
  {
    real_T *x = (real_T *) &rtX;
    ssSetContStates(rtS, x);
    (void) memset((void *)x, 0,
                  sizeof(X));
  }

  /* states (dwork) */
  {
    void *dwork = (void *) &rtDW;
    ssSetRootDWork(rtS, dwork);
    (void) memset(dwork, 0,
                  sizeof(DW));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ssSetModelMappingInfo(rtS, &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Model specific registration */
  ssSetRootSS(rtS, rtS);
  ssSetVersion(rtS, SIMSTRUCT_VERSION_LEVEL2);
  ssSetModelName(rtS, "State_Flow_v0");
  ssSetPath(rtS, "State_Flow_v0");
  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 20.0);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ssSetRTWLogInfo(rtS, &rt_DataLoggingInfo);
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogXSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogT(ssGetRTWLogInfo(rtS), "tout");
    rtliSetLogX(ssGetRTWLogInfo(rtS), "");
    rtliSetLogXFinal(ssGetRTWLogInfo(rtS), "");
    rtliSetSigLog(ssGetRTWLogInfo(rtS), "");
    rtliSetLogVarNameModifier(ssGetRTWLogInfo(rtS), "rt_");
    rtliSetLogFormat(ssGetRTWLogInfo(rtS), 2);
    rtliSetLogMaxRows(ssGetRTWLogInfo(rtS), 0);
    rtliSetLogDecimation(ssGetRTWLogInfo(rtS), 1);
    rtliSetLogY(ssGetRTWLogInfo(rtS), "");
    rtliSetLogYSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogYSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
  }

  {
    static struct _ssStatesInfo2 statesInfo2;
    ssSetStatesInfo2(rtS, &statesInfo2);
  }

  {
    static ssSolverInfo slvrInfo;
    static boolean_T contStatesDisabled[3];
    static real_T absTol[3] = { 1.0E-6, 1.0E-6, 1.0E-6 };

    static uint8_T absTolControl[3] = { 0U, 0U, 0U };

    static uint8_T zcAttributes[8] = { (ZC_EVENT_ALL), (ZC_EVENT_ALL),
      (ZC_EVENT_ALL_UP), (ZC_EVENT_ALL_UP), (ZC_EVENT_ALL), (ZC_EVENT_ALL),
      (ZC_EVENT_ALL), (ZC_EVENT_ALL) };

    static ssNonContDerivSigInfo nonContDerivSigInfo[1] = {
      { 1*sizeof(real_T), (char*)(&rtB.Gain4), (NULL) }
    };

    ssSetSolverRelTol(rtS, 0.001);
    ssSetStepSize(rtS, 0.0);
    ssSetMinStepSize(rtS, 0.0);
    ssSetMaxNumMinSteps(rtS, -1);
    ssSetMinStepViolatedError(rtS, 0);
    ssSetMaxStepSize(rtS, 0.008);
    ssSetSolverMaxOrder(rtS, -1);
    ssSetSolverRefineFactor(rtS, 1);
    ssSetOutputTimes(rtS, (NULL));
    ssSetNumOutputTimes(rtS, 0);
    ssSetOutputTimesOnly(rtS, 0);
    ssSetOutputTimesIndex(rtS, 0);
    ssSetZCCacheNeedsReset(rtS, 1);
    ssSetDerivCacheNeedsReset(rtS, 0);
    ssSetNumNonContDerivSigInfos(rtS, 1);
    ssSetNonContDerivSigInfos(rtS, nonContDerivSigInfo);
    ssSetSolverInfo(rtS, &slvrInfo);
    ssSetSolverName(rtS, "ode45");
    ssSetVariableStepSolver(rtS, 1);
    ssSetSolverConsistencyChecking(rtS, 0);
    ssSetSolverAdaptiveZcDetection(rtS, 0);
    ssSetSolverRobustResetMethod(rtS, 0);
    ssSetAbsTolVector(rtS, absTol);
    ssSetAbsTolControlVector(rtS, absTolControl);
    ssSetSolverAbsTol_Obsolete(rtS, absTol);
    ssSetSolverAbsTolControl_Obsolete(rtS, absTolControl);
    ssSetSolverStateProjection(rtS, 0);
    ssSetSolverMassMatrixType(rtS, (ssMatrixType)0);
    ssSetSolverMassMatrixNzMax(rtS, 0);
    ssSetModelOutputs(rtS, MdlOutputs);
    ssSetModelLogData(rtS, rt_UpdateTXYLogVars);
    ssSetModelUpdate(rtS, MdlUpdate);
    ssSetModelDerivatives(rtS, MdlDerivatives);
    ssSetSolverZcSignalAttrib(rtS, zcAttributes);
    ssSetSolverNumZcSignals(rtS, 8);
    ssSetModelZeroCrossings(rtS, MdlZeroCrossings);
    ssSetSolverConsecutiveZCsStepRelTol(rtS, 2.8421709430404007E-13);
    ssSetSolverMaxConsecutiveZCs(rtS, 1000);
    ssSetSolverConsecutiveZCsError(rtS, 2);
    ssSetSolverMaskedZcDiagnostic(rtS, 1);
    ssSetSolverIgnoredZcDiagnostic(rtS, 1);
    ssSetSolverMaxConsecutiveMinStep(rtS, 1);
    ssSetSolverShapePreserveControl(rtS, 2);
    ssSetTNextTid(rtS, INT_MIN);
    ssSetTNext(rtS, rtMinusInf);
    ssSetSolverNeedsReset(rtS);
    ssSetNumNonsampledZCs(rtS, 8);
    ssSetContStateDisabled(rtS, contStatesDisabled);
    ssSetSolverMaxConsecutiveMinStep(rtS, 1);
  }

  ssSetChecksumVal(rtS, 0, 2685009145U);
  ssSetChecksumVal(rtS, 1, 3934435865U);
  ssSetChecksumVal(rtS, 2, 1415350355U);
  ssSetChecksumVal(rtS, 3, 2059386061U);

  /* child S-Function registration */
  ssSetNumSFunctions(rtS, 1);

  /* register each child */
  {
    static SimStruct childSFunctions[1];
    static SimStruct *childSFunctionPtrs[1];
    (void) memset((void *)&childSFunctions[0], 0,
                  sizeof(childSFunctions));
    ssSetSFunctions(rtS, &childSFunctionPtrs[0]);
    ssSetSFunction(rtS, 0, &childSFunctions[0]);

    /* Level2 S-Function Block: State_Flow_v0/<S1>/S-Function (ECPDSPDriver) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 0);

      /* timing info */
      static time_T sfcnPeriod[1];
      static time_T sfcnOffset[1];
      static int_T sfcnTsMap[1];
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      ssSetMdlInfoPtr(rts, ssGetMdlInfoPtr(rtS));

      /* Allocate memory of model methods 2 */
      {
        static struct _ssSFcnModelMethods2 methods2;
        ssSetModelMethods2(rts, &methods2);
      }

      /* Allocate memory of model methods 3 */
      {
        static struct _ssSFcnModelMethods3 methods3;
        ssSetModelMethods3(rts, &methods3);
      }

      /* Allocate memory for states auxilliary information */
      {
        static struct _ssStatesInfo2 statesInfo2;
        ssSetStatesInfo2(rts, &statesInfo2);
      }

      /* inputs */
      {
        static struct _ssPortInputs inputPortInfo[1];
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts, &inputPortInfo[0]);

        /* port 0 */
        {
          static real_T const *sfcnUPtrs[2];
          sfcnUPtrs[0] = &rtB.Saturation;
          sfcnUPtrs[1] = &rtB.Saturation1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        static struct _ssPortOutputs outputPortInfo[1];
        ssSetPortInfoForOutputs(rts, &outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) rtB.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "State_Flow_v0/ECPDSP Driver/S-Function");
      if (ssGetRTModel(rtS) == (NULL)) {
        ssSetParentSS(rts, rtS);
        ssSetRootSS(rts, ssGetRootSS(rtS));
      } else {
        ssSetRTModel(rts,ssGetRTModel(rtS));
        ssSetParentSS(rts, (NULL));
        ssSetRootSS(rts, rts);
      }

      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        static mxArray *sfcnParams[4];
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)rtP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)rtP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)rtP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)rtP.SFunction_P4_Size);
      }

      /* registration */
      ECPDSPDriver(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.008);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

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

  return rtS;
}
