/*
 * PBA3_2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PBA3_2".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Sep 04 17:43:15 2017
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <math.h>
#include "PBA3_2.h"
#include "PBA3_2_private.h"
#include "PBA3_2_dt.h"

/* user code (top of parameter file) */
const int_T gblNumToFiles = 0;
const int_T gblNumFrFiles = 0;
const int_T gblNumFrWksBlocks = 0;
const char *gblSlvrJacPatternFileName = "PBA3_2_rsim_rtw\\PBA3_2_Jpattern.mat";

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
  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  rtX.Integrator_CSTATE = rtP.Integrator_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  rtX.Integrator1_CSTATE = rtP.Integrator1_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  rtX.Integrator2_CSTATE = rtP.Integrator2_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator3' */
  rtX.Integrator3_CSTATE = rtP.Integrator3_IC;
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{
  MdlInitialize();
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_Integrator1;
  real_T rtb_Sum2;
  real_T rtb_Gain3;
  real_T rtb_Gain2;

  /* Integrator: '<Root>/Integrator' */
  rtb_Integrator1 = rtX.Integrator_CSTATE;
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Step: '<Root>/Step' */
    rtDW.Step_MODE = (ssGetTaskTime(rtS,1) >= rtP.Step_Time);
    if (rtDW.Step_MODE == 1) {
      rtb_Sum2 = rtP.Step_YFinal;
    } else {
      rtb_Sum2 = rtP.Step_Y0;
    }

    /* End of Step: '<Root>/Step' */

    /* Step: '<Root>/Step1' */
    rtDW.Step1_MODE = (ssGetTaskTime(rtS,1) >= rtP.Step1_Time);
    if (rtDW.Step1_MODE == 1) {
      rtb_Gain3 = rtP.Step1_YFinal;
    } else {
      rtb_Gain3 = rtP.Step1_Y0;
    }

    /* End of Step: '<Root>/Step1' */

    /* Sum: '<Root>/Sum2' */
    rtb_Sum2 -= rtb_Gain3;
  }

  /* Integrator: '<Root>/Integrator1' */
  rtb_Integrator1 = rtX.Integrator1_CSTATE;

  /* Integrator: '<Root>/Integrator2' */
  rtB.Integrator2 = rtX.Integrator2_CSTATE;

  /* Gain: '<Root>/Gain3' */
  rtb_Gain3 = -rtP.c / rtP.M * rtB.Integrator2;

  /* Gain: '<Root>/Gain2' */
  rtb_Gain2 = rtP.m * rtP.g / rtP.M * rtb_Integrator1;

  /* Integrator: '<Root>/Integrator3' */
  rtB.Integrator3 = rtX.Integrator3_CSTATE;
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Gain: '<Root>/Gain' */
    rtB.Gain = 1.0 / rtP.M * rtb_Sum2;

    /* Gain: '<Root>/Gain1' */
    rtB.Gain1 = 1.0 / (rtP.M * rtP.l) * rtb_Sum2;
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/Gain5'
   *  Gain: '<Root>/Gain6'
   *  Gain: '<Root>/Gain7'
   *  Sum: '<Root>/Add1'
   */
  rtB.Sum = (((rtP.m * rtP.g / (rtP.M * rtP.l) + rtP.g / rtP.l) *
              rtb_Integrator1 + -rtP.c / (rtP.M * rtP.l) * rtB.Integrator2) +
             (-(rtP.rho / rtP.M) - rtP.rho / rtP.m) * rtB.Integrator3) +
    rtB.Gain1;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/Gain4'
   *  Sum: '<Root>/Add'
   */
  rtB.Sum1 = (-rtP.rho / (rtP.l * rtP.M) * rtB.Integrator3 + (rtb_Gain3 +
    rtb_Gain2)) + rtB.Gain;
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void MdlDerivatives(void)
{
  /* Derivatives for Integrator: '<Root>/Integrator' */
  {
    ((XDot *) ssGetdX(rtS))->Integrator_CSTATE = rtB.Integrator2;
  }

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  {
    ((XDot *) ssGetdX(rtS))->Integrator1_CSTATE = rtB.Integrator3;
  }

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  {
    ((XDot *) ssGetdX(rtS))->Integrator2_CSTATE = rtB.Sum1;
  }

  /* Derivatives for Integrator: '<Root>/Integrator3' */
  {
    ((XDot *) ssGetdX(rtS))->Integrator3_CSTATE = rtB.Sum;
  }
}

/* Projection for root system: '<Root>' */
void MdlProjection(void)
{
}

/* ZeroCrossings for root system: '<Root>' */
void MdlZeroCrossings(void)
{
  /* ZeroCrossings for Step: '<Root>/Step' */
  ((ZCV *) ssGetSolverZcSignalVector(rtS))->Step_StepTime_ZC = ssGetT(rtS) -
    rtP.Step_Time;

  /* ZeroCrossings for Step: '<Root>/Step1' */
  ((ZCV *) ssGetSolverZcSignalVector(rtS))->Step1_StepTime_ZC = ssGetT(rtS) -
    rtP.Step1_Time;
}

/* Termination for root system: '<Root>' */
void MdlTerminate(void)
{
}

/* Function to initialize sizes */
void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 4);          /* Number of continuous states */
  ssSetNumPeriodicContStates(rtS, 0);  /* Number of periodic continuous states */
  ssSetNumY(rtS, 0);                   /* Number of model outputs */
  ssSetNumU(rtS, 0);                   /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 0);      /* The model is not direct feedthrough */
  ssSetNumSampleTimes(rtS, 2);         /* Number of sample times */
  ssSetNumBlocks(rtS, 22);             /* Number of blocks */
  ssSetNumBlockIO(rtS, 6);             /* Number of block outputs */
  ssSetNumBlockParams(rtS, 16);        /* Sum of parameter "widths" */
}

/* Function to initialize sample times. */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.0);
  ssSetSampleTime(rtS, 1, 0.0);

  /* task offsets */
  ssSetOffsetTime(rtS, 0, 0.0);
  ssSetOffsetTime(rtS, 1, 1.0);
}

/* Function to register the model */
SimStruct * PBA3_2(void)
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
  ssSetModelName(rtS, "PBA3_2");
  ssSetPath(rtS, "PBA3_2");
  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 10.0);

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
    rtliSetLogVarNameModifier(ssGetRTWLogInfo(rtS), "rt_");
    rtliSetLogFormat(ssGetRTWLogInfo(rtS), 0);
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
    static ssPeriodicStatesInfo periodicStatesInfo;
    ssSetPeriodicStatesInfo(rtS, &periodicStatesInfo);
  }

  {
    static ssSolverInfo slvrInfo;
    static boolean_T contStatesDisabled[4];
    static real_T absTol[4] = { 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6 };

    static uint8_T absTolControl[4] = { 0U, 0U, 0U, 0U };

    static uint8_T zcAttributes[2] = { (ZC_EVENT_ALL_UP), (ZC_EVENT_ALL_UP) };

    static ssNonContDerivSigInfo nonContDerivSigInfo[2] = {
      { 1*sizeof(real_T), (char*)(&rtB.Gain1), (NULL) }
      , { 1*sizeof(real_T), (char*)(&rtB.Gain), (NULL) }
    };

    ssSetSolverRelTol(rtS, 0.001);
    ssSetStepSize(rtS, 0.0);
    ssSetMinStepSize(rtS, 0.0);
    ssSetMaxNumMinSteps(rtS, -1);
    ssSetMinStepViolatedError(rtS, 0);
    ssSetMaxStepSize(rtS, 0.2);
    ssSetSolverMaxOrder(rtS, -1);
    ssSetSolverRefineFactor(rtS, 1);
    ssSetOutputTimes(rtS, (NULL));
    ssSetNumOutputTimes(rtS, 0);
    ssSetOutputTimesOnly(rtS, 0);
    ssSetOutputTimesIndex(rtS, 0);
    ssSetZCCacheNeedsReset(rtS, 0);
    ssSetDerivCacheNeedsReset(rtS, 0);
    ssSetNumNonContDerivSigInfos(rtS, 2);
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
    ssSetSolverNumZcSignals(rtS, 2);
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
    ssSetNumNonsampledZCs(rtS, 2);
    ssSetContStateDisabled(rtS, contStatesDisabled);
    ssSetSolverMaxConsecutiveMinStep(rtS, 1);
  }

  ssSetChecksumVal(rtS, 0, 1472448903U);
  ssSetChecksumVal(rtS, 1, 1318665350U);
  ssSetChecksumVal(rtS, 2, 3652969513U);
  ssSetChecksumVal(rtS, 3, 1982666000U);
  return rtS;
}
