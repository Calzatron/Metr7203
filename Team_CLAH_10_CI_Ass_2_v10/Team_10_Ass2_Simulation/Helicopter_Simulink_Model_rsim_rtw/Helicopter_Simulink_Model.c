/*
 * Helicopter_Simulink_Model.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Helicopter_Simulink_Model".
 *
 * Model version              : 1.14
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed Oct 25 14:31:05 2017
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
#include "Helicopter_Simulink_Model.h"
#include "Helicopter_Simulink_Model_private.h"
#include "Helicopter_Simulink_Model_dt.h"

/* user code (top of parameter file) */
const int_T gblNumToFiles = 0;
const int_T gblNumFrFiles = 0;
const int_T gblNumFrWksBlocks = 0;
const char *gblSlvrJacPatternFileName =
  "Helicopter_Simulink_Model_rsim_rtw\\Helicopter_Simulink_Model_Jpattern.mat";

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
real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

/* Initial conditions for root system: '<Root>' */
void MdlInitialize(void)
{
  uint32_T tseed;
  int32_T r;
  int32_T t;
  real_T tmp;

  /* InitializeConditions for UniformRandomNumber: '<Root>/Sensor Noise' */
  tmp = floor(rtP.SensorNoise_Seed);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
  r = (int32_T)(tseed >> 16U);
  t = (int32_T)(tseed & 32768U);
  tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
  if (tseed < 1U) {
    tseed = 1144108930U;
  } else {
    if (tseed > 2147483646U) {
      tseed = 2147483646U;
    }
  }

  rtDW.RandSeed = tseed;
  rtDW.SensorNoise_NextOutput = (rtP.SensorNoise_Maximum -
    rtP.SensorNoise_Minimum) * rt_urand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed) +
    rtP.SensorNoise_Minimum;

  /* End of InitializeConditions for UniformRandomNumber: '<Root>/Sensor Noise' */

  /* InitializeConditions for StateSpace: '<Root>/State-Space' */
  for (r = 0; r < 6; r++) {
    rtX.StateSpace_CSTATE[r] = rtP.StateSpace_X0;
  }

  /* End of InitializeConditions for StateSpace: '<Root>/State-Space' */
  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  {
    int_T i1;
    real_T *xc = &rtX.Integrator_CSTATE[0];
    for (i1=0; i1 < 6; i1++) {
      xc[i1] = rtP.Integrator_IC;
    }
  }

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  rtX.Integrator1_CSTATE[0] = rtP.Integrator1_IC;
  rtX.Integrator1_CSTATE[1] = rtP.Integrator1_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  rtDW.TimeStampA = (rtInf);
  rtDW.TimeStampB = (rtInf);
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{
  /* Start for Scope: '<Root>/Input Output' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 5 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1 };

    static int_T rt_ScopeSignalDimensions[] = { 5 };

    static void *rt_ScopeCurrSigDims[] = { (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "" };

    static char_T rt_ScopeSignalTitles[] = "";
    static int_T rt_ScopeSignalTitleLengths[] = { 0 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 1, 1, 1, 1, 1 };

    BuiltInDTypeId dTypes[1] = { SS_DOUBLE };

    static char_T rt_ScopeBlockName[] = "Helicopter_Simulink_Model/Input Output";
    rt_ScopeSignalInfo.numSignals = 1;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = (NULL);
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    rtDW.InputOutput_PWORK.LoggedData = rt_CreateStructLogVar(
      ssGetRTWLogInfo(rtS),
      ssGetTStart(rtS),
      ssGetTFinal(rtS),
      0.0,
      (&ssGetErrorStatus(rtS)),
      "io",
      1,
      0,
      1,
      0.0,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (rtDW.InputOutput_PWORK.LoggedData == (NULL))
      return;
  }

  MdlInitialize();
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_x_hat[6];
  real_T rtb_Sum1[3];
  real_T rtb_Derivative[3];
  real_T rtb_Statefeedback[2];
  real_T rtb_C_0[2];
  int_T iy;
  int_T ci;
  real_T (*lastU)[3];
  real_T rtb_SensorNoise;
  real_T tmp[6];
  real_T tmp_0[6];
  real_T tmp_1;
  if (ssIsSampleHit(rtS, 2, 0)) {
    /* UniformRandomNumber: '<Root>/Sensor Noise' */
    rtb_SensorNoise = rtDW.SensorNoise_NextOutput;
  }

  /* StateSpace: '<Root>/State-Space' */
  rtB.y[0] = 0.0;
  rtB.y[1] = 0.0;
  rtB.y[2] = 0.0;
  for (iy = 0; iy < 3; iy++) {
    for (ci = 0; ci < 6; ci++) {
      rtB.y[iy] += rtP.C[ci * 3 + iy] * rtX.StateSpace_CSTATE[ci];
    }
  }

  /* End of StateSpace: '<Root>/State-Space' */
  if (ssIsSampleHit(rtS, 2, 0)) {
    /* Sum: '<Root>/Sum3' incorporates:
     *  ZeroOrderHold: '<Root>/Zero-Order Hold'
     */
    rtB.Sum3[0] = rtb_SensorNoise + rtB.y[0];
    rtB.Sum3[1] = rtb_SensorNoise + rtB.y[1];
    rtB.Sum3[2] = rtb_SensorNoise + rtB.y[2];
  }

  /* Integrator: '<Root>/Integrator' */
  {
    int_T i1;
    real_T *y0 = &rtb_x_hat[0];
    real_T *xc = &rtX.Integrator_CSTATE[0];
    for (i1=0; i1 < 6; i1++) {
      y0[i1] = xc[i1];
    }
  }

  /* Gain: '<Root>/C' */
  for (iy = 0; iy < 3; iy++) {
    rtb_Derivative[iy] = 0.0;
    for (ci = 0; ci < 6; ci++) {
      rtb_Derivative[iy] += rtP.C[3 * ci + iy] * rtb_x_hat[ci];
    }
  }

  /* End of Gain: '<Root>/C' */

  /* Sum: '<Root>/Sum1' */
  rtb_Sum1[0] = rtB.Sum3[0] - rtb_Derivative[0];
  rtb_Sum1[1] = rtB.Sum3[1] - rtb_Derivative[1];
  rtb_Sum1[2] = rtB.Sum3[2] - rtb_Derivative[2];
  if (ssIsSampleHit(rtS, 1, 0)) {
    /* Step: '<Root>/Step' */
    rtDW.Step_MODE = (ssGetTaskTime(rtS,1) >= rtP.Step_Time);

    /* Step: '<Root>/Step1' */
    rtDW.Step1_MODE = (ssGetTaskTime(rtS,1) >= rtP.Step1_Time);

    /* Step: '<Root>/Step' */
    if (rtDW.Step_MODE == 1) {
      rtb_SensorNoise = rtP.Step_YFinal;
    } else {
      rtb_SensorNoise = rtP.Step_Y0;
    }

    /* Step: '<Root>/Step1' */
    if (rtDW.Step1_MODE == 1) {
      tmp_1 = rtP.Step1_YFinal;
    } else {
      tmp_1 = rtP.Step1_Y0;
    }

    /* Sum: '<Root>/Add2' */
    rtB.Add2 = rtb_SensorNoise + tmp_1;

    /* Step: '<Root>/Step2' */
    rtDW.Step2_MODE = (ssGetTaskTime(rtS,1) >= rtP.Step2_Time);

    /* Step: '<Root>/Step3' */
    rtDW.Step3_MODE = (ssGetTaskTime(rtS,1) >= rtP.Step3_Time);

    /* Step: '<Root>/Step2' */
    if (rtDW.Step2_MODE == 1) {
      rtb_SensorNoise = rtP.Step2_YFinal;
    } else {
      rtb_SensorNoise = rtP.Step2_Y0;
    }

    /* Step: '<Root>/Step3' */
    if (rtDW.Step3_MODE == 1) {
      tmp_1 = rtP.Step3_YFinal;
    } else {
      tmp_1 = rtP.Step3_Y0;
    }

    /* Sum: '<Root>/Add1' */
    rtB.Add1 = rtb_SensorNoise + tmp_1;

    /* Gain: '<Root>/Kr' incorporates:
     *  SignalConversion: '<Root>/TmpSignal ConversionAtKrInport1'
     */
    rtB.Kr[0] = 0.0;
    rtB.Kr[0] += rtP.K_r[0] * rtB.Add2;
    rtB.Kr[0] += rtP.K_r[2] * rtB.Add1;
    rtB.Kr[1] = 0.0;
    rtB.Kr[1] += rtP.K_r[1] * rtB.Add2;
    rtB.Kr[1] += rtP.K_r[3] * rtB.Add1;

    /* Scope: '<Root>/Input Output' */
    if (ssGetLogOutput(rtS)) {
      StructLogVar *svar = (StructLogVar *)rtDW.InputOutput_PWORK.LoggedData;
      LogVar *var = svar->signals.values;

      /* time */
      {
        double locTime = ssGetTaskTime(rtS,1);
        rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
      }

      /* signals */
      {
        real_T up0[5];
        up0[0] = rtB.Sum3[0];
        up0[1] = rtB.Sum3[1];
        up0[2] = rtB.Sum3[2];
        up0[3] = rtB.Add2;
        up0[4] = rtB.Add1;
        rt_UpdateLogVar((LogVar *)var, up0, 0);
      }
    }
  }

  /* Integrator: '<Root>/Integrator1'
   *
   * Regarding '<Root>/Integrator1':
   *  Limited Integrator
   */
  if (ssIsMajorTimeStep(rtS)) {
    if (rtX.Integrator1_CSTATE[0] >= rtP.Integrator1_UpperSat ) {
      rtX.Integrator1_CSTATE[0] = rtP.Integrator1_UpperSat;
    } else if (rtX.Integrator1_CSTATE[0] <= (rtP.Integrator1_LowerSat) ) {
      rtX.Integrator1_CSTATE[0] = (rtP.Integrator1_LowerSat);
    }

    if (rtX.Integrator1_CSTATE[1] >= rtP.Integrator1_UpperSat ) {
      rtX.Integrator1_CSTATE[1] = rtP.Integrator1_UpperSat;
    } else if (rtX.Integrator1_CSTATE[1] <= (rtP.Integrator1_LowerSat) ) {
      rtX.Integrator1_CSTATE[1] = (rtP.Integrator1_LowerSat);
    }
  }

  rtb_Statefeedback[0] = rtX.Integrator1_CSTATE[0];
  rtb_Statefeedback[1] = rtX.Integrator1_CSTATE[1];

  /* Gain: '<Root>/Ki' */
  rtb_C_0[0] = 0.0;
  rtb_C_0[0] += rtP.K_i[0] * rtb_Statefeedback[0];
  rtb_C_0[0] += rtP.K_i[2] * rtb_Statefeedback[1];
  rtb_C_0[1] = 0.0;
  rtb_C_0[1] += rtP.K_i[1] * rtb_Statefeedback[0];
  rtb_C_0[1] += rtP.K_i[3] * rtb_Statefeedback[1];

  /* Gain: '<Root>/State-feedback' */
  for (iy = 0; iy < 2; iy++) {
    rtb_Statefeedback[iy] = 0.0;
    for (ci = 0; ci < 6; ci++) {
      rtb_Statefeedback[iy] += rtP.K_sf[(ci << 1) + iy] * rtb_x_hat[ci];
    }
  }

  /* End of Gain: '<Root>/State-feedback' */

  /* Sum: '<Root>/Sum' */
  rtB.InputVoltage[0] = (rtB.Kr[0] + rtb_C_0[0]) - rtb_Statefeedback[0];
  rtB.InputVoltage[1] = (rtB.Kr[1] + rtb_C_0[1]) - rtb_Statefeedback[1];
  if (ssIsSampleHit(rtS, 2, 0)) {
  }

  /* Derivative: '<Root>/Derivative' */
  if ((rtDW.TimeStampA >= ssGetT(rtS)) && (rtDW.TimeStampB >= ssGetT(rtS))) {
    rtb_Derivative[0] = 0.0;
    rtb_Derivative[1] = 0.0;
    rtb_Derivative[2] = 0.0;
  } else {
    rtb_SensorNoise = rtDW.TimeStampA;
    lastU = (real_T (*)[3])rtDW.LastUAtTimeA;
    if (rtDW.TimeStampA < rtDW.TimeStampB) {
      if (rtDW.TimeStampB < ssGetT(rtS)) {
        rtb_SensorNoise = rtDW.TimeStampB;
        lastU = (real_T (*)[3])rtDW.LastUAtTimeB;
      }
    } else {
      if (rtDW.TimeStampA >= ssGetT(rtS)) {
        rtb_SensorNoise = rtDW.TimeStampB;
        lastU = (real_T (*)[3])rtDW.LastUAtTimeB;
      }
    }

    rtb_SensorNoise = ssGetT(rtS) - rtb_SensorNoise;
    rtb_Derivative[0] = (rtB.Sum3[0] - (*lastU)[0]) / rtb_SensorNoise;
    rtb_Derivative[1] = (rtB.Sum3[1] - (*lastU)[1]) / rtb_SensorNoise;
    rtb_Derivative[2] = (rtB.Sum3[2] - (*lastU)[2]) / rtb_SensorNoise;
  }

  /* End of Derivative: '<Root>/Derivative' */
  if (ssIsSampleHit(rtS, 1, 0)) {
  }

  for (iy = 0; iy < 6; iy++) {
    /* Gain: '<Root>/Gain2' incorporates:
     *  Sum: '<Root>/Add'
     */
    tmp[iy] = rtP.L[iy + 12] * rtb_Sum1[2] + (rtP.L[iy + 6] * rtb_Sum1[1] +
      rtP.L[iy] * rtb_Sum1[0]);

    /* Gain: '<Root>/B' incorporates:
     *  Sum: '<Root>/Add'
     */
    tmp_0[iy] = rtP.B[iy + 6] * rtB.InputVoltage[1] + rtP.B[iy] *
      rtB.InputVoltage[0];
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Gain: '<Root>/A'
   */
  for (iy = 0; iy < 6; iy++) {
    rtb_SensorNoise = 0.0;
    for (ci = 0; ci < 6; ci++) {
      rtb_SensorNoise += rtP.A[6 * ci + iy] * rtb_x_hat[ci];
    }

    rtB.x_dot[iy] = (tmp[iy] + tmp_0[iy]) + rtb_SensorNoise;
  }

  /* Gain: '<Root>/C_0' */
  for (iy = 0; iy < 2; iy++) {
    rtb_C_0[iy] = 0.0;
    for (ci = 0; ci < 6; ci++) {
      rtb_C_0[iy] += rtP.C_0[(ci << 1) + iy] * rtb_x_hat[ci];
    }
  }

  /* End of Gain: '<Root>/C_0' */

  /* Sum: '<Root>/Sum2' */
  rtB.Sum2[0] = rtB.Add2 - rtb_C_0[0];
  rtB.Sum2[1] = rtB.Add1 - rtb_C_0[1];
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{
  real_T (*lastU)[3];
  if (ssIsSampleHit(rtS, 2, 0)) {
    /* Update for UniformRandomNumber: '<Root>/Sensor Noise' */
    rtDW.SensorNoise_NextOutput = (rtP.SensorNoise_Maximum -
      rtP.SensorNoise_Minimum) * rt_urand_Upu32_Yd_f_pw_snf(&rtDW.RandSeed) +
      rtP.SensorNoise_Minimum;
  }

  /* Update for Integrator: '<Root>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if (rtX.Integrator1_CSTATE[0] == rtP.Integrator1_UpperSat) {
      switch (rtDW.Integrator1_MODE[0]) {
       case INTG_UPPER_SAT:
        if (rtB.Sum2[0] < 0.0) {
          ssSetSolverNeedsReset(rtS);
          rtDW.Integrator1_MODE[0] = INTG_LEAVING_UPPER_SAT;
        }
        break;

       case INTG_LEAVING_UPPER_SAT:
        if (rtB.Sum2[0] >= 0.0) {
          rtDW.Integrator1_MODE[0] = INTG_UPPER_SAT;
          ssSetSolverNeedsReset(rtS);
        }
        break;

       default:
        ssSetSolverNeedsReset(rtS);
        if (rtB.Sum2[0] < 0.0) {
          rtDW.Integrator1_MODE[0] = INTG_LEAVING_UPPER_SAT;
        } else {
          rtDW.Integrator1_MODE[0] = INTG_UPPER_SAT;
        }
        break;
      }
    } else if (rtX.Integrator1_CSTATE[0] == (rtP.Integrator1_LowerSat)) {
      switch (rtDW.Integrator1_MODE[0]) {
       case INTG_LOWER_SAT:
        if (rtB.Sum2[0] > 0.0) {
          ssSetSolverNeedsReset(rtS);
          rtDW.Integrator1_MODE[0] = INTG_LEAVING_LOWER_SAT;
        }
        break;

       case INTG_LEAVING_LOWER_SAT:
        if (rtB.Sum2[0] <= 0.0) {
          rtDW.Integrator1_MODE[0] = INTG_LOWER_SAT;
          ssSetSolverNeedsReset(rtS);
        }
        break;

       default:
        ssSetSolverNeedsReset(rtS);
        if (rtB.Sum2[0] > 0.0) {
          rtDW.Integrator1_MODE[0] = INTG_LEAVING_LOWER_SAT;
        } else {
          rtDW.Integrator1_MODE[0] = INTG_LOWER_SAT;
        }
        break;
      }
    } else {
      rtDW.Integrator1_MODE[0] = INTG_NORMAL;
    }

    if (rtX.Integrator1_CSTATE[1] == rtP.Integrator1_UpperSat) {
      switch (rtDW.Integrator1_MODE[1]) {
       case INTG_UPPER_SAT:
        if (rtB.Sum2[1] < 0.0) {
          ssSetSolverNeedsReset(rtS);
          rtDW.Integrator1_MODE[1] = INTG_LEAVING_UPPER_SAT;
        }
        break;

       case INTG_LEAVING_UPPER_SAT:
        if (rtB.Sum2[1] >= 0.0) {
          rtDW.Integrator1_MODE[1] = INTG_UPPER_SAT;
          ssSetSolverNeedsReset(rtS);
        }
        break;

       default:
        ssSetSolverNeedsReset(rtS);
        if (rtB.Sum2[1] < 0.0) {
          rtDW.Integrator1_MODE[1] = INTG_LEAVING_UPPER_SAT;
        } else {
          rtDW.Integrator1_MODE[1] = INTG_UPPER_SAT;
        }
        break;
      }
    } else if (rtX.Integrator1_CSTATE[1] == (rtP.Integrator1_LowerSat)) {
      switch (rtDW.Integrator1_MODE[1]) {
       case INTG_LOWER_SAT:
        if (rtB.Sum2[1] > 0.0) {
          ssSetSolverNeedsReset(rtS);
          rtDW.Integrator1_MODE[1] = INTG_LEAVING_LOWER_SAT;
        }
        break;

       case INTG_LEAVING_LOWER_SAT:
        if (rtB.Sum2[1] <= 0.0) {
          rtDW.Integrator1_MODE[1] = INTG_LOWER_SAT;
          ssSetSolverNeedsReset(rtS);
        }
        break;

       default:
        ssSetSolverNeedsReset(rtS);
        if (rtB.Sum2[1] > 0.0) {
          rtDW.Integrator1_MODE[1] = INTG_LEAVING_LOWER_SAT;
        } else {
          rtDW.Integrator1_MODE[1] = INTG_LOWER_SAT;
        }
        break;
      }
    } else {
      rtDW.Integrator1_MODE[1] = INTG_NORMAL;
    }
  }

  /* Update for Derivative: '<Root>/Derivative' */
  if (rtDW.TimeStampA == (rtInf)) {
    rtDW.TimeStampA = ssGetT(rtS);
    lastU = (real_T (*)[3])rtDW.LastUAtTimeA;
  } else if (rtDW.TimeStampB == (rtInf)) {
    rtDW.TimeStampB = ssGetT(rtS);
    lastU = (real_T (*)[3])rtDW.LastUAtTimeB;
  } else if (rtDW.TimeStampA < rtDW.TimeStampB) {
    rtDW.TimeStampA = ssGetT(rtS);
    lastU = (real_T (*)[3])rtDW.LastUAtTimeA;
  } else {
    rtDW.TimeStampB = ssGetT(rtS);
    lastU = (real_T (*)[3])rtDW.LastUAtTimeB;
  }

  (*lastU)[0] = rtB.Sum3[0];
  (*lastU)[1] = rtB.Sum3[1];
  (*lastU)[2] = rtB.Sum3[2];

  /* End of Update for Derivative: '<Root>/Derivative' */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void MdlDerivatives(void)
{
  int_T is;
  int_T ci;
  XDot *_rtXdot;
  _rtXdot = ((XDot *) ssGetdX(rtS));

  /* Derivatives for StateSpace: '<Root>/State-Space' */
  for (is = 0; is < 6; is++) {
    _rtXdot->StateSpace_CSTATE[is] = 0.0;
    for (ci = 0; ci < 6; ci++) {
      _rtXdot->StateSpace_CSTATE[is] += rtP.A[ci * 6 + is] *
        rtX.StateSpace_CSTATE[ci];
    }

    _rtXdot->StateSpace_CSTATE[is] += rtP.B[is] * rtB.InputVoltage[0];
    _rtXdot->StateSpace_CSTATE[is] += rtP.B[6 + is] * rtB.InputVoltage[1];
  }

  /* End of Derivatives for StateSpace: '<Root>/State-Space' */
  /* Derivatives for Integrator: '<Root>/Integrator' */
  {
    {
      int_T i1;
      const real_T *u0 = &rtB.x_dot[0];
      real_T *xdot = &((XDot *) ssGetdX(rtS))->Integrator_CSTATE[0];
      for (i1=0; i1 < 6; i1++) {
        xdot[i1] = u0[i1];
      }
    }
  }

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    if ((rtDW.Integrator1_MODE[0] != INTG_UPPER_SAT)
        && (rtDW.Integrator1_MODE[0] != INTG_LOWER_SAT) ) {
      ((XDot *) ssGetdX(rtS))->Integrator1_CSTATE[0] = rtB.Sum2[0];
      ((XDis *) ssGetContStateDisabled(rtS))->Integrator1_CSTATE[0] = false;
    } else {
      /* in saturation */
      ((XDot *) ssGetdX(rtS))->Integrator1_CSTATE[0] = 0.0;
      if ((rtDW.Integrator1_MODE[0] == INTG_UPPER_SAT) ||
          (rtDW.Integrator1_MODE[0] == INTG_LOWER_SAT)) {
        ((XDis *) ssGetContStateDisabled(rtS))->Integrator1_CSTATE[0] = true;
      }
    }

    if ((rtDW.Integrator1_MODE[1] != INTG_UPPER_SAT)
        && (rtDW.Integrator1_MODE[1] != INTG_LOWER_SAT) ) {
      ((XDot *) ssGetdX(rtS))->Integrator1_CSTATE[1] = rtB.Sum2[1];
      ((XDis *) ssGetContStateDisabled(rtS))->Integrator1_CSTATE[1] = false;
    } else {
      /* in saturation */
      ((XDot *) ssGetdX(rtS))->Integrator1_CSTATE[1] = 0.0;
      if ((rtDW.Integrator1_MODE[1] == INTG_UPPER_SAT) ||
          (rtDW.Integrator1_MODE[1] == INTG_LOWER_SAT)) {
        ((XDis *) ssGetContStateDisabled(rtS))->Integrator1_CSTATE[1] = true;
      }
    }
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

  /* ZeroCrossings for Step: '<Root>/Step2' */
  ((ZCV *) ssGetSolverZcSignalVector(rtS))->Step2_StepTime_ZC = ssGetT(rtS) -
    rtP.Step2_Time;

  /* ZeroCrossings for Step: '<Root>/Step3' */
  ((ZCV *) ssGetSolverZcSignalVector(rtS))->Step3_StepTime_ZC = ssGetT(rtS) -
    rtP.Step3_Time;

  /* ZeroCrossings for Integrator: '<Root>/Integrator1' */
  {
    enum { INTG_NORMAL, INTG_LEAVING_UPPER_SAT, INTG_LEAVING_LOWER_SAT,
      INTG_UPPER_SAT, INTG_LOWER_SAT };

    /* zero crossings for enter into limited region */
    if (rtDW.Integrator1_MODE[0] == INTG_LEAVING_UPPER_SAT &&
        rtX.Integrator1_CSTATE[0] >= rtP.Integrator1_UpperSat) {
      ((ZCV *) ssGetSolverZcSignalVector(rtS))->Integrator1_IntgUpLimit_ZC[0] =
        0.0;
    } else {
      ((ZCV *) ssGetSolverZcSignalVector(rtS))->Integrator1_IntgUpLimit_ZC[0] =
        rtX.Integrator1_CSTATE[0] - rtP.Integrator1_UpperSat;
    }

    if (rtDW.Integrator1_MODE[0] == INTG_LEAVING_LOWER_SAT &&
        rtX.Integrator1_CSTATE[0] <= (rtP.Integrator1_LowerSat)) {
      ((ZCV *) ssGetSolverZcSignalVector(rtS))->Integrator1_IntgLoLimit_ZC[0] =
        0.0;
    } else {
      ((ZCV *) ssGetSolverZcSignalVector(rtS))->Integrator1_IntgLoLimit_ZC[0] =
        rtX.Integrator1_CSTATE[0] - (rtP.Integrator1_LowerSat);
    }

    if (rtDW.Integrator1_MODE[1] == INTG_LEAVING_UPPER_SAT &&
        rtX.Integrator1_CSTATE[1] >= rtP.Integrator1_UpperSat) {
      ((ZCV *) ssGetSolverZcSignalVector(rtS))->Integrator1_IntgUpLimit_ZC[1] =
        0.0;
    } else {
      ((ZCV *) ssGetSolverZcSignalVector(rtS))->Integrator1_IntgUpLimit_ZC[1] =
        rtX.Integrator1_CSTATE[1] - rtP.Integrator1_UpperSat;
    }

    if (rtDW.Integrator1_MODE[1] == INTG_LEAVING_LOWER_SAT &&
        rtX.Integrator1_CSTATE[1] <= (rtP.Integrator1_LowerSat)) {
      ((ZCV *) ssGetSolverZcSignalVector(rtS))->Integrator1_IntgLoLimit_ZC[1] =
        0.0;
    } else {
      ((ZCV *) ssGetSolverZcSignalVector(rtS))->Integrator1_IntgLoLimit_ZC[1] =
        rtX.Integrator1_CSTATE[1] - (rtP.Integrator1_LowerSat);
    }

    /* zero crossings for leaving limited region */
    {
      if ((rtDW.Integrator1_MODE[0] == INTG_UPPER_SAT) ||(rtDW.Integrator1_MODE
           [0] == INTG_LOWER_SAT)) {
        ((ZCV *) ssGetSolverZcSignalVector(rtS))->Integrator1_LeaveSaturate_ZC[0]
          = rtB.Sum2[0];
      } else {
        ((ZCV *) ssGetSolverZcSignalVector(rtS))->Integrator1_LeaveSaturate_ZC[0]
          = 0.0;
      }

      if ((rtDW.Integrator1_MODE[1] == INTG_UPPER_SAT) ||(rtDW.Integrator1_MODE
           [1] == INTG_LOWER_SAT)) {
        ((ZCV *) ssGetSolverZcSignalVector(rtS))->Integrator1_LeaveSaturate_ZC[1]
          = rtB.Sum2[1];
      } else {
        ((ZCV *) ssGetSolverZcSignalVector(rtS))->Integrator1_LeaveSaturate_ZC[1]
          = 0.0;
      }
    }
  }
}

/* Termination for root system: '<Root>' */
void MdlTerminate(void)
{
}

/* Function to initialize sizes */
void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 14);         /* Number of continuous states */
  ssSetNumPeriodicContStates(rtS, 0);  /* Number of periodic continuous states */
  ssSetNumY(rtS, 0);                   /* Number of model outputs */
  ssSetNumU(rtS, 0);                   /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 0);      /* The model is not direct feedthrough */
  ssSetNumSampleTimes(rtS, 3);         /* Number of sample times */
  ssSetNumBlocks(rtS, 37);             /* Number of blocks */
  ssSetNumBlockIO(rtS, 8);             /* Number of block outputs */
  ssSetNumBlockParams(rtS, 136);       /* Sum of parameter "widths" */
}

/* Function to initialize sample times. */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.0);
  ssSetSampleTime(rtS, 1, 0.0);
  ssSetSampleTime(rtS, 2, 0.012);

  /* task offsets */
  ssSetOffsetTime(rtS, 0, 0.0);
  ssSetOffsetTime(rtS, 1, 1.0);
  ssSetOffsetTime(rtS, 2, 0.0);
}

/* Function to register the model */
SimStruct * Helicopter_Simulink_Model(void)
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
  ssSetModelName(rtS, "Helicopter_Simulink_Model");
  ssSetPath(rtS, "Helicopter_Simulink_Model");
  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 50.0);

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
    static boolean_T contStatesDisabled[14];
    static real_T absTol[14] = { 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6,
      1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6 };

    static uint8_T absTolControl[14] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U };

    static uint8_T zcAttributes[10] = { (ZC_EVENT_ALL_UP), (ZC_EVENT_ALL_UP),
      (ZC_EVENT_ALL_UP), (ZC_EVENT_ALL_UP), (ZC_EVENT_ALL_UP), (ZC_EVENT_ALL_UP),
      (ZC_EVENT_ALL_DN), (ZC_EVENT_ALL_DN), (ZC_EVENT_ALL), (ZC_EVENT_ALL) };

    static ssNonContDerivSigInfo nonContDerivSigInfo[4] = {
      { 2*sizeof(real_T), (char*)(&rtB.Kr[0]), (NULL) }
      , { 1*sizeof(real_T), (char*)(&rtB.Add1), (NULL) }
      , { 1*sizeof(real_T), (char*)(&rtB.Add2), (NULL) }
      , { 3*sizeof(real_T), (char*)(&rtB.Sum3[0]), (NULL) }
    };

    ssSetSolverRelTol(rtS, 0.001);
    ssSetStepSize(rtS, 0.0);
    ssSetMinStepSize(rtS, 0.0001);
    ssSetMaxNumMinSteps(rtS, -1);
    ssSetMinStepViolatedError(rtS, 0);
    ssSetMaxStepSize(rtS, 0.001);
    ssSetSolverMaxOrder(rtS, -1);
    ssSetSolverRefineFactor(rtS, 1);
    ssSetOutputTimes(rtS, (NULL));
    ssSetNumOutputTimes(rtS, 0);
    ssSetOutputTimesOnly(rtS, 0);
    ssSetOutputTimesIndex(rtS, 0);
    ssSetZCCacheNeedsReset(rtS, 1);
    ssSetDerivCacheNeedsReset(rtS, 0);
    ssSetNumNonContDerivSigInfos(rtS, 4);
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
    ssSetSolverNumZcSignals(rtS, 10);
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
    ssSetNumNonsampledZCs(rtS, 10);
    ssSetContStateDisabled(rtS, contStatesDisabled);
    ssSetSolverMaxConsecutiveMinStep(rtS, 1);
  }

  ssSetChecksumVal(rtS, 0, 1939716385U);
  ssSetChecksumVal(rtS, 1, 1654384753U);
  ssSetChecksumVal(rtS, 2, 1504546028U);
  ssSetChecksumVal(rtS, 3, 4237664371U);
  return rtS;
}
