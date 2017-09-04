/*
 * PBA3_2_2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PBA3_2_2".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Sep 04 20:40:32 2017
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
#include "PBA3_2_2.h"
#include "PBA3_2_2_private.h"
#include "PBA3_2_2_dt.h"

/* user code (top of parameter file) */
const int_T gblNumToFiles = 0;
const int_T gblNumFrFiles = 0;
const int_T gblNumFrWksBlocks = 0;
const char *gblSlvrJacPatternFileName =
  "PBA3_2_2_rsim_rtw\\PBA3_2_2_Jpattern.mat";

/* Root inports information  */
const int_T gblNumRootInportBlks = 1;
const int_T gblNumModelInputs = 1;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
const int_T gblInportDataTypeIdx[] = { 0 };

const int_T gblInportDims[] = { 1, 1 } ;

const int_T gblInportComplex[] = { 0 };

const int_T gblInportInterpoFlag[] = { 1 };

const int_T gblInportContinuous[] = { 1 };

#include "simstruc.h"
#include "fixedpoint.h"

/* Block signals (auto storage) */
B rtB;

/* Continuous states */
X rtX;

/* Block states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Parent Simstruct */
static SimStruct model_S;
SimStruct *const rtS = &model_S;

/* Initial conditions for root system: '<Root>' */
void MdlInitialize(void)
{
  /* InitializeConditions for Integrator: '<Root>/Integrator3' */
  rtX.Integrator3_CSTATE = rtP.Integrator3_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  rtX.Integrator1_CSTATE = rtP.Integrator1_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  rtX.Integrator2_CSTATE = rtP.Integrator2_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  rtX.Integrator_CSTATE = rtP.Integrator_IC;
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
  real_T rtb_TrigonometricFunction3;
  real_T rtb_Gain3;
  real_T rtb_TrigonometricFunction;
  real_T rtb_Gain;
  real_T rtb_Add;

  /* Read data from the mat file of inport block */
  if (gblInportFileName != (NULL)) {
    int_T currTimeIdx;
    int_T i;

    /*
     *  Read in data from mat file for root inport F
     */
    if (gblInportTUtables[0].nTimePoints > 0) {
      if (1) {
        real_T time = ssGetTaskTime(rtS,0);
        int k = 1;
        if (gblInportTUtables[0].nTimePoints == 1) {
          k = 0;
        }

        currTimeIdx = rt_getTimeIdx(gblInportTUtables[0].time, time,
          gblInportTUtables[0].nTimePoints,
          gblInportTUtables[0].currTimeIdx,
          1,
          0);
        gblInportTUtables[0].currTimeIdx = currTimeIdx;
        for (i = 0; i < 1; i++) {
          real_T* realPtr1 = (real_T*)gblInportTUtables[0].ur +
            i*gblInportTUtables[0].nTimePoints +currTimeIdx;
          real_T* realPtr2 = realPtr1 + 1*k;
          (void)rt_Interpolate_Datatype(
            realPtr1,
            realPtr2,
            &rtU.F,
            time,
            gblInportTUtables[0].time[currTimeIdx],
            gblInportTUtables[0].time[currTimeIdx + k],
            gblInportTUtables[0].uDataType);
        }
      }
    }
  }

  /* end read inport data from file */

  /* Integrator: '<Root>/Integrator3' */
  rtb_TrigonometricFunction3 = rtX.Integrator3_CSTATE;

  /* Outport: '<Root>/p' */
  rtY.p = rtb_TrigonometricFunction3;

  /* Integrator: '<Root>/Integrator1' */
  rtb_Integrator1 = rtX.Integrator1_CSTATE;

  /* Outport: '<Root>/th' */
  rtY.th = rtb_Integrator1;

  /* Trigonometry: '<Root>/Trigonometric Function3' */
  rtb_TrigonometricFunction3 = cos(rtb_Integrator1);

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain2'
   *  Product: '<Root>/Product5'
   */
  rtb_Add = (rtP.m + rtP.M) - rtb_TrigonometricFunction3 *
    rtb_TrigonometricFunction3 * rtP.m;

  /* Integrator: '<Root>/Integrator2' */
  rtB.Integrator2 = rtX.Integrator2_CSTATE;

  /* Gain: '<Root>/Gain3' */
  rtb_Gain3 = rtP.c * rtB.Integrator2;

  /* Trigonometry: '<Root>/Trigonometric Function' */
  rtb_TrigonometricFunction = cos(rtb_Integrator1);

  /* Gain: '<Root>/Gain' incorporates:
   *  Product: '<Root>/Product'
   *  Trigonometry: '<Root>/Trigonometric Function1'
   */
  rtb_Gain = rtP.m * rtP.g * (rtb_TrigonometricFunction * sin(rtb_Integrator1));

  /* Integrator: '<Root>/Integrator' */
  rtB.Integrator = rtX.Integrator_CSTATE;

  /* Product: '<Root>/Divide' incorporates:
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain4'
   *  Inport: '<Root>/F'
   *  Product: '<Root>/Product1'
   *  Product: '<Root>/Product2'
   *  Product: '<Root>/Product3'
   *  Sum: '<Root>/Add1'
   *  Trigonometry: '<Root>/Trigonometric Function6'
   */
  rtB.Divide = ((((rtb_Gain - rtb_Gain3) - rtP.rho / rtP.l * (rtB.Integrator *
    rtb_TrigonometricFunction)) - rtP.m * rtP.l * (rtB.Integrator *
    rtB.Integrator) * sin(rtb_Integrator1)) + rtU.F) / rtb_Add;

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/Gain5'
   *  Gain: '<Root>/Gain7'
   *  Gain: '<Root>/Gain8'
   *  Product: '<Root>/Product4'
   *  Trigonometry: '<Root>/Trigonometric Function2'
   */
  rtB.Sum = (1.0 / rtP.l * sin(rtb_Integrator1) - rtP.rho / rtP.m *
             rtB.Integrator) + 1.0 / rtP.l * rtb_TrigonometricFunction3 *
    rtB.Divide;
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
  /* Derivatives for Integrator: '<Root>/Integrator3' */
  {
    ((XDot *) ssGetdX(rtS))->Integrator3_CSTATE = rtB.Integrator2;
  }

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  {
    ((XDot *) ssGetdX(rtS))->Integrator1_CSTATE = rtB.Integrator;
  }

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  {
    ((XDot *) ssGetdX(rtS))->Integrator2_CSTATE = rtB.Divide;
  }

  /* Derivatives for Integrator: '<Root>/Integrator' */
  {
    ((XDot *) ssGetdX(rtS))->Integrator_CSTATE = rtB.Sum;
  }
}

/* Projection for root system: '<Root>' */
void MdlProjection(void)
{
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
  ssSetNumY(rtS, 2);                   /* Number of model outputs */
  ssSetNumU(rtS, 1);                   /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 1);      /* The model is direct feedthrough */
  ssSetNumSampleTimes(rtS, 2);         /* Number of sample times */
  ssSetNumBlocks(rtS, 33);             /* Number of blocks */
  ssSetNumBlockIO(rtS, 4);             /* Number of block outputs */
  ssSetNumBlockParams(rtS, 10);        /* Sum of parameter "widths" */
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
SimStruct * PBA3_2_2(void)
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

  /* external inputs */
  {
    ssSetU(rtS, ((void*) &rtU));
    rtU.F = 0.0;
  }

  /* external outputs */
  {
    ssSetY(rtS, &rtY);
    (void) memset((void *)&rtY, 0,
                  sizeof(ExtY));
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
  ssSetModelName(rtS, "PBA3_2_2");
  ssSetPath(rtS, "PBA3_2_2");
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
    rtliSetLogMaxRows(ssGetRTWLogInfo(rtS), 1000);
    rtliSetLogDecimation(ssGetRTWLogInfo(rtS), 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &rtY.p,
        &rtY.th
      };

      rtliSetLogYSignalPtrs(ssGetRTWLogInfo(rtS), ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "PBA3_2_2/p",
        "PBA3_2_2/th" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          2,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(ssGetRTWLogInfo(rtS), rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(ssGetRTWLogInfo(rtS), "yout");
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
    ssSetNumNonContDerivSigInfos(rtS, 0);
    ssSetNonContDerivSigInfos(rtS, (NULL));
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
    ssSetSolverMaxConsecutiveMinStep(rtS, 1);
    ssSetSolverShapePreserveControl(rtS, 2);
    ssSetTNextTid(rtS, INT_MIN);
    ssSetTNext(rtS, rtMinusInf);
    ssSetSolverNeedsReset(rtS);
    ssSetNumNonsampledZCs(rtS, 0);
    ssSetContStateDisabled(rtS, contStatesDisabled);
    ssSetSolverMaxConsecutiveMinStep(rtS, 1);
  }

  ssSetChecksumVal(rtS, 0, 2076294U);
  ssSetChecksumVal(rtS, 1, 3312175391U);
  ssSetChecksumVal(rtS, 2, 283446265U);
  ssSetChecksumVal(rtS, 3, 914796444U);
  return rtS;
}
