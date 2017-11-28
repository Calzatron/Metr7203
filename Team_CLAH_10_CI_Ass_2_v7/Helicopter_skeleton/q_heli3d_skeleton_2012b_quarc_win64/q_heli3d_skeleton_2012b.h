/*
 * q_heli3d_skeleton_2012b.h
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
#ifndef RTW_HEADER_q_heli3d_skeleton_2012b_h_
#define RTW_HEADER_q_heli3d_skeleton_2012b_h_
#ifndef q_heli3d_skeleton_2012b_COMMON_INCLUDES_
# define q_heli3d_skeleton_2012b_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_hid.h"
#include "quanser_memory.h"
#include "quanser_extern.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#endif                                 /* q_heli3d_skeleton_2012b_COMMON_INCLUDES_ */

#include "q_heli3d_skeleton_2012b_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ()
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ()
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ()
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ()
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ()
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ()
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ()
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ()
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ()
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ()
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ()
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ()
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ()
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ()
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ()
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ()
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ()
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ()
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ()
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ()
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)             (rtmGetTPtr((rtm))[0] = (val))
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define q_heli3d_skeleton_2012b_rtModel RT_MODEL_q_heli3d_skeleton_2012

/* Block signals (auto storage) */
typedef struct {
  real_T SliderGain;                   /* '<S4>/Slider Gain' */
  real_T Gain1[2];                     /* '<S10>/Gain1' */
  real_T ReferenceGain[2];             /* '<Root>/Reference Gain' */
  real_T z[2];                         /* '<Root>/Integrator1' */
  real_T IntegralGain[2];              /* '<Root>/Integral Gain' */
  real_T x[6];                         /* '<Root>/Integrator' */
  real_T StateFeedback[2];             /* '<Root>/State Feedback' */
  real_T ZeroingBias[2];               /* '<Root>/Zero'ing Bias' */
  real_T DACBLimitV[2];                /* '<S1>/DACB Limit (V)' */
  real_T AmplifierGain[2];             /* '<S1>/Amplifier Gain' */
  real_T EncoderResolutionPitchradcount;/* '<S1>/Encoder Resolution: Pitch (rad//count)' */
  real_T EncoderResolutionTravelradcount;/* '<S1>/Encoder Resolution: Travel (rad//count)' */
  real_T InitialElevationrad;          /* '<S1>/Initial Elevation (rad)' */
  real_T y_hat[3];                     /* '<Root>/Gain2' */
  real_T Add1[3];                      /* '<Root>/Add1' */
  real_T y_hat_j[2];                   /* '<Root>/Output Reference' */
  real_T zry_hat[2];                   /* '<Root>/Sum1' */
  real_T TransferFcn;                  /* '<Root>/Transfer Fcn' */
  real_T TransferFcn1;                 /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn2;                 /* '<Root>/Transfer Fcn2' */
  real_T y[3];                         /* '<Root>/3-DOF Plant' */
  real_T DerivePosition[3];            /* '<Root>/Derive Position' */
  real_T x_dot[6];                     /* '<Root>/Add' */
  real_T RateTransitionz;              /* '<S3>/Rate Transition: z' */
  real_T RateTransitionx;              /* '<S3>/Rate Transition: x' */
  real_T CalibrationXdegsV;            /* '<S3>/Calibration: X  (deg//s//V)' */
  real_T RateTransitiony;              /* '<S3>/Rate Transition: y' */
  real_T CalibrationYdegsV;            /* '<S3>/Calibration: Y  (deg//s//V)' */
  real_T startTime;                    /* '<S7>/startTime' */
} BlockIO_q_heli3d_skeleton_2012b;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T HILInitialize_AIMinimums[8];  /* '<S1>/HIL Initialize' */
  real_T HILInitialize_AIMaximums[8];  /* '<S1>/HIL Initialize' */
  real_T HILInitialize_AOMinimums[8];  /* '<S1>/HIL Initialize' */
  real_T HILInitialize_AOMaximums[8];  /* '<S1>/HIL Initialize' */
  real_T HILInitialize_AOVoltages[8];  /* '<S1>/HIL Initialize' */
  real_T HILInitialize_FilterFrequency[8];/* '<S1>/HIL Initialize' */
  real_T HILInitialize_POSortedFreqs[8];/* '<S1>/HIL Initialize' */
  real_T HILInitialize_POValues[8];    /* '<S1>/HIL Initialize' */
  real_T RateTransitionz_Buffer0;      /* '<S3>/Rate Transition: z' */
  real_T RateTransitionx_Buffer0;      /* '<S3>/Rate Transition: x' */
  real_T RateTransitiony_Buffer0;      /* '<S3>/Rate Transition: y' */
  t_game_controller GameController_Controller;/* '<S3>/Game Controller' */
  t_card HILInitialize_Card;           /* '<S1>/HIL Initialize' */
  t_task HILReadEncoderTimebase_Task;  /* '<S1>/HIL Read Encoder Timebase' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA[3];
    real_T TimeStampB;
    real_T LastUAtTimeB[3];
  } DerivePosition_RWORK;              /* '<Root>/Derive Position' */

  void *HILWriteAnalog_PWORK;          /* '<S1>/HIL Write Analog' */
  void *HILWriteDigital_PWORK;         /* '<S1>/HIL Write Digital' */
  struct {
    void *LoggedData;
  } Error_PWORK;                       /* '<Root>/Error' */

  struct {
    void *LoggedData;
  } ErrorbetweenReferenceandEstimat;   /* '<Root>/Error between Reference and Estimate' */

  struct {
    void *LoggedData;
  } FilteredPlantVelocity_PWORK;       /* '<Root>/Filtered Plant Velocity' */

  struct {
    void *LoggedData;
  } Integral_PWORK;                    /* '<Root>/Integral' */

  struct {
    void *LoggedData;
  } IntegralInput_PWORK;               /* '<Root>/Integral Input' */

  struct {
    void *LoggedData;
  } JoystickReference_PWORK;           /* '<Root>/Joystick Reference' */

  struct {
    void *LoggedData;
  } Meas_PWORK;                        /* '<Root>/Meas' */

  struct {
    void *LoggedData;
  } MotorVoltage_PWORK;                /* '<Root>/Motor Voltage' */

  struct {
    void *LoggedData;
  } Motorvoltage_PWORK;                /* '<Root>/Motor voltage' */

  struct {
    void *LoggedData;
  } ObserverOutput_PWORK;              /* '<Root>/Observer Output' */

  struct {
    void *LoggedData;
  } PlantOutput_PWORK;                 /* '<Root>/Plant Output' */

  struct {
    void *LoggedData;
  } PlantVoltageInput_PWORK;           /* '<Root>/Plant Voltage  Input' */

  struct {
    void *LoggedData;
  } RawVelocities_PWORK;               /* '<Root>/Raw Velocities' */

  struct {
    void *LoggedData;
  } ReferenceandOutput_PWORK;          /* '<Root>/Reference and Output' */

  struct {
    void *LoggedData;
  } StateFeedbackInput_PWORK;          /* '<Root>/State Feedback Input' */

  struct {
    void *LoggedData;
  } VoltageReferenceInput_PWORK;       /* '<Root>/Voltage Reference Input' */

  struct {
    void *LoggedData;
  } x_hat_pos_PWORK;                   /* '<Root>/x_hat_pos' */

  struct {
    void *LoggedData;
  } x_hat_vel_PWORK;                   /* '<Root>/x_hat_vel' */

  struct {
    void *LoggedData;
  } y_estElevationandTravel_PWORK;     /* '<Root>/y_est - Elevation and Travel' */

  int32_T HILInitialize_ClockModes[3]; /* '<S1>/HIL Initialize' */
  int32_T HILInitialize_DOStates[4];   /* '<S1>/HIL Initialize' */
  int32_T HILInitialize_QuadratureModes[8];/* '<S1>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[8];/* '<S1>/HIL Initialize' */
  int32_T HILInitialize_POModeValues[8];/* '<S1>/HIL Initialize' */
  int32_T HILInitialize_POAlignValues[8];/* '<S1>/HIL Initialize' */
  int32_T HILInitialize_POPolarityVals[8];/* '<S1>/HIL Initialize' */
  int32_T HILReadEncoderTimebase_Buffer[3];/* '<S1>/HIL Read Encoder Timebase' */
  uint32_T HILInitialize_POSortedChans[8];/* '<S1>/HIL Initialize' */
  boolean_T HILInitialize_DOBits[4];   /* '<S1>/HIL Initialize' */
  t_boolean HILWriteDigital_Buffer[4]; /* '<S1>/HIL Write Digital' */
} D_Work_q_heli3d_skeleton_2012b;

/* Continuous states (auto storage) */
typedef struct {
  real_T DesPositionElevationdeg_CSTATE;/* '<S3>/Des Position:  Elevation (deg)' */
  real_T DesPositionTraveldeg_CSTATE;  /* '<S3>/Des Position:  Travel (deg)' */
  real_T Integrator1_CSTATE[2];        /* '<Root>/Integrator1' */
  real_T Integrator_CSTATE[6];         /* '<Root>/Integrator' */
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE;          /* '<Root>/Transfer Fcn2' */
} ContinuousStates_q_heli3d_skele;

/* State derivatives (auto storage) */
typedef struct {
  real_T DesPositionElevationdeg_CSTATE;/* '<S3>/Des Position:  Elevation (deg)' */
  real_T DesPositionTraveldeg_CSTATE;  /* '<S3>/Des Position:  Travel (deg)' */
  real_T Integrator1_CSTATE[2];        /* '<Root>/Integrator1' */
  real_T Integrator_CSTATE[6];         /* '<Root>/Integrator' */
  real_T TransferFcn_CSTATE;           /* '<Root>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE;          /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE;          /* '<Root>/Transfer Fcn2' */
} StateDerivatives_q_heli3d_skele;

/* State disabled  */
typedef struct {
  boolean_T DesPositionElevationdeg_CSTATE;/* '<S3>/Des Position:  Elevation (deg)' */
  boolean_T DesPositionTraveldeg_CSTATE;/* '<S3>/Des Position:  Travel (deg)' */
  boolean_T Integrator1_CSTATE[2];     /* '<Root>/Integrator1' */
  boolean_T Integrator_CSTATE[6];      /* '<Root>/Integrator' */
  boolean_T TransferFcn_CSTATE;        /* '<Root>/Transfer Fcn' */
  boolean_T TransferFcn1_CSTATE;       /* '<Root>/Transfer Fcn1' */
  boolean_T TransferFcn2_CSTATE;       /* '<Root>/Transfer Fcn2' */
} StateDisabled_q_heli3d_skeleton;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (auto storage) */
struct Parameters_q_heli3d_skeleton_20_ {
  real_T HILInitialize_OOStart;        /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_OOEnter;        /* Expression: set_other_outputs_at_switch_in
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_OOTerminate;    /* Expression: set_other_outputs_at_terminate
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_OOExit;         /* Expression: set_other_outputs_at_switch_out
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_AIHigh;         /* Expression: analog_input_maximums
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_AILow;          /* Expression: analog_input_minimums
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_AOHigh;         /* Expression: analog_output_maximums
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_AOLow;          /* Expression: analog_output_minimums
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_AOInitial;      /* Expression: initial_analog_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_AOFinal;        /* Expression: final_analog_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_AOWatchdog;     /* Expression: watchdog_analog_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_POFrequency;    /* Expression: pwm_frequency
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_POLeading;      /* Expression: pwm_leading_deadband
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_POTrailing;     /* Expression: pwm_trailing_deadband
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_POInitial;      /* Expression: initial_pwm_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_POFinal;        /* Expression: final_pwm_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T HILInitialize_POWatchdog;     /* Expression: watchdog_pwm_outputs
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T SliderGain_Gain;              /* Expression: gain
                                        * Referenced by: '<S4>/Slider Gain'
                                        */
  real_T DesPositionElevationdeg_IC;   /* Expression: elev_0*180/pi
                                        * Referenced by: '<S3>/Des Position:  Elevation (deg)'
                                        */
  real_T DesPositionElevationdeg_UpperSa;/* Expression: CMD_ELEV_POS_LIMIT_UPPER
                                          * Referenced by: '<S3>/Des Position:  Elevation (deg)'
                                          */
  real_T DesPositionElevationdeg_LowerSa;/* Expression: CMD_ELEV_POS_LIMIT_LOWER
                                          * Referenced by: '<S3>/Des Position:  Elevation (deg)'
                                          */
  real_T DesPositionTraveldeg_IC;      /* Expression: 0
                                        * Referenced by: '<S3>/Des Position:  Travel (deg)'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T ReferenceGain_Gain[4];        /* Expression: K_r
                                        * Referenced by: '<Root>/Reference Gain'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Integrator1_UpperSat;         /* Expression: 0.7
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Integrator1_LowerSat;         /* Expression: -0.7
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T IntegralGain_Gain[4];         /* Expression: K_i
                                        * Referenced by: '<Root>/Integral Gain'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T StateFeedback_Gain[12];       /* Expression: K_sf
                                        * Referenced by: '<Root>/State Feedback'
                                        */
  real_T ZeroingBias_Bias;             /* Expression: Vo
                                        * Referenced by: '<Root>/Zero'ing Bias'
                                        */
  real_T AmplifierVoltageLimitV_UpperSat;/* Expression: VMAX_AMP
                                          * Referenced by: '<S1>/Amplifier Voltage  Limit (V)'
                                          */
  real_T AmplifierVoltageLimitV_LowerSat;/* Expression: -VMAX_AMP
                                          * Referenced by: '<S1>/Amplifier Voltage  Limit (V)'
                                          */
  real_T AmplifierGainPreCompensation_Ga;/* Expression:  1 / K_AMP
                                          * Referenced by: '<S1>/Amplifier Gain Pre-Compensation'
                                          */
  real_T DACBLimitV_UpperSat;          /* Expression: VMAX_DAC
                                        * Referenced by: '<S1>/DACB Limit (V)'
                                        */
  real_T DACBLimitV_LowerSat;          /* Expression: -VMAX_DAC
                                        * Referenced by: '<S1>/DACB Limit (V)'
                                        */
  real_T AmplifierGain_Gain;           /* Expression:  K_AMP
                                        * Referenced by: '<S1>/Amplifier Gain'
                                        */
  real_T EncoderResolutionElevationradco;/* Expression: K_EC_E
                                          * Referenced by: '<S1>/Encoder Resolution: Elevation (rad//count)'
                                          */
  real_T EncoderResolutionPitchradcount_;/* Expression: K_EC_P
                                          * Referenced by: '<S1>/Encoder Resolution: Pitch (rad//count)'
                                          */
  real_T EncoderResolutionTravelradcount;/* Expression: K_EC_T
                                          * Referenced by: '<S1>/Encoder Resolution: Travel (rad//count)'
                                          */
  real_T InitialElevationrad_Bias;     /* Expression: elev_0
                                        * Referenced by: '<S1>/Initial Elevation (rad)'
                                        */
  real_T EnableAmp_Value[4];           /* Expression: [1 1 1 1]
                                        * Referenced by: '<S1>/Enable Amp'
                                        */
  real_T Gain2_Gain[18];               /* Expression: C
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T OutputReference_Gain[12];     /* Expression: C_0
                                        * Referenced by: '<Root>/Output Reference'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T TransferFcn_D;                /* Computed Parameter: TransferFcn_D
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_D;               /* Computed Parameter: TransferFcn1_D
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T TransferFcn2_A;               /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_C;               /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_D;               /* Computed Parameter: TransferFcn2_D
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */
  real_T Gain8_Gain[18];               /* Expression: L
                                        * Referenced by: '<Root>/Gain8'
                                        */
  real_T StateInput_Gain[12];          /* Expression: B
                                        * Referenced by: '<Root>/State Input'
                                        */
  real_T SystemMatrix_Gain[36];        /* Expression: A
                                        * Referenced by: '<Root>/System Matrix'
                                        */
  real_T RateTransitionz_X0;           /* Expression: 0
                                        * Referenced by: '<S3>/Rate Transition: z'
                                        */
  real_T Inverse_Gain;                 /* Expression: -1
                                        * Referenced by: '<S9>/Inverse'
                                        */
  real_T Bias_Bias;                    /* Expression: 1
                                        * Referenced by: '<S9>/Bias'
                                        */
  real_T Constant_Value_c;             /* Expression: 2
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T RateTransitionx_X0;           /* Expression: 0
                                        * Referenced by: '<S3>/Rate Transition: x'
                                        */
  real_T CalibrationXdegsV_Gain;       /* Expression: K_JOYSTICK_X
                                        * Referenced by: '<S3>/Calibration: X  (deg//s//V)'
                                        */
  real_T RateTransitiony_X0;           /* Expression: 0
                                        * Referenced by: '<S3>/Rate Transition: y'
                                        */
  real_T CalibrationYdegsV_Gain;       /* Expression: K_JOYSTICK_Y
                                        * Referenced by: '<S3>/Calibration: Y  (deg//s//V)'
                                        */
  int32_T HILInitialize_CKChannels[3]; /* Computed Parameter: HILInitialize_CKChannels
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  int32_T HILInitialize_DOWatchdog;    /* Computed Parameter: HILInitialize_DOWatchdog
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  int32_T HILInitialize_EIInitial;     /* Computed Parameter: HILInitialize_EIInitial
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  int32_T HILInitialize_POModes;       /* Computed Parameter: HILInitialize_POModes
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  int32_T HILInitialize_POConfiguration;/* Computed Parameter: HILInitialize_POConfiguration
                                         * Referenced by: '<S1>/HIL Initialize'
                                         */
  int32_T HILInitialize_POAlignment;   /* Computed Parameter: HILInitialize_POAlignment
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  int32_T HILInitialize_POPolarity;    /* Computed Parameter: HILInitialize_POPolarity
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  int32_T HILReadEncoderTimebase_Clock;/* Computed Parameter: HILReadEncoderTimebase_Clock
                                        * Referenced by: '<S1>/HIL Read Encoder Timebase'
                                        */
  uint32_T HILInitialize_AIChannels[8];/* Computed Parameter: HILInitialize_AIChannels
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  uint32_T HILInitialize_AOChannels[8];/* Computed Parameter: HILInitialize_AOChannels
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  uint32_T HILInitialize_DIChannels[4];/* Computed Parameter: HILInitialize_DIChannels
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  uint32_T HILInitialize_DOChannels[4];/* Computed Parameter: HILInitialize_DOChannels
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  uint32_T HILInitialize_EIChannels[8];/* Computed Parameter: HILInitialize_EIChannels
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  uint32_T HILInitialize_EIQuadrature; /* Computed Parameter: HILInitialize_EIQuadrature
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  uint32_T HILInitialize_POChannels[8];/* Computed Parameter: HILInitialize_POChannels
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  uint32_T HILReadEncoderTimebase_Channels[3];/* Computed Parameter: HILReadEncoderTimebase_Channels
                                               * Referenced by: '<S1>/HIL Read Encoder Timebase'
                                               */
  uint32_T HILReadEncoderTimebase_SamplesI;/* Computed Parameter: HILReadEncoderTimebase_SamplesI
                                            * Referenced by: '<S1>/HIL Read Encoder Timebase'
                                            */
  uint32_T HILWriteAnalog_Channels[2]; /* Computed Parameter: HILWriteAnalog_Channels
                                        * Referenced by: '<S1>/HIL Write Analog'
                                        */
  uint32_T HILWriteDigital_Channels[4];/* Computed Parameter: HILWriteDigital_Channels
                                        * Referenced by: '<S1>/HIL Write Digital'
                                        */
  uint16_T GameController_BufferSize;  /* Computed Parameter: GameController_BufferSize
                                        * Referenced by: '<S3>/Game Controller'
                                        */
  uint8_T GameController_ControllerNumber;/* Computed Parameter: GameController_ControllerNumber
                                           * Referenced by: '<S3>/Game Controller'
                                           */
  boolean_T HILInitialize_Active;      /* Computed Parameter: HILInitialize_Active
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKPStart;    /* Computed Parameter: HILInitialize_CKPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKPEnter;    /* Computed Parameter: HILInitialize_CKPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKStart;     /* Computed Parameter: HILInitialize_CKStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKEnter;     /* Computed Parameter: HILInitialize_CKEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AIPStart;    /* Computed Parameter: HILInitialize_AIPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AIPEnter;    /* Computed Parameter: HILInitialize_AIPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOPStart;    /* Computed Parameter: HILInitialize_AOPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOPEnter;    /* Computed Parameter: HILInitialize_AOPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOStart;     /* Computed Parameter: HILInitialize_AOStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOEnter;     /* Computed Parameter: HILInitialize_AOEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOTerminate; /* Computed Parameter: HILInitialize_AOTerminate
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOExit;      /* Computed Parameter: HILInitialize_AOExit
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOReset;     /* Computed Parameter: HILInitialize_AOReset
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOPStart;    /* Computed Parameter: HILInitialize_DOPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOPEnter;    /* Computed Parameter: HILInitialize_DOPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOStart;     /* Computed Parameter: HILInitialize_DOStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOEnter;     /* Computed Parameter: HILInitialize_DOEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOTerminate; /* Computed Parameter: HILInitialize_DOTerminate
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOExit;      /* Computed Parameter: HILInitialize_DOExit
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOReset;     /* Computed Parameter: HILInitialize_DOReset
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIPStart;    /* Computed Parameter: HILInitialize_EIPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIPEnter;    /* Computed Parameter: HILInitialize_EIPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIStart;     /* Computed Parameter: HILInitialize_EIStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIEnter;     /* Computed Parameter: HILInitialize_EIEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POPStart;    /* Computed Parameter: HILInitialize_POPStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POPEnter;    /* Computed Parameter: HILInitialize_POPEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POStart;     /* Computed Parameter: HILInitialize_POStart
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POEnter;     /* Computed Parameter: HILInitialize_POEnter
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POTerminate; /* Computed Parameter: HILInitialize_POTerminate
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POExit;      /* Computed Parameter: HILInitialize_POExit
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POReset;     /* Computed Parameter: HILInitialize_POReset
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_OOReset;     /* Computed Parameter: HILInitialize_OOReset
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOInitial;   /* Computed Parameter: HILInitialize_DOInitial
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOFinal;     /* Computed Parameter: HILInitialize_DOFinal
                                        * Referenced by: '<S1>/HIL Initialize'
                                        */
  boolean_T HILReadEncoderTimebase_Active;/* Computed Parameter: HILReadEncoderTimebase_Active
                                           * Referenced by: '<S1>/HIL Read Encoder Timebase'
                                           */
  boolean_T HILWriteAnalog_Active;     /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<S1>/HIL Write Analog'
                                        */
  boolean_T HILWriteDigital_Active;    /* Computed Parameter: HILWriteDigital_Active
                                        * Referenced by: '<S1>/HIL Write Digital'
                                        */
  boolean_T GameController_AutoCenter; /* Computed Parameter: GameController_AutoCenter
                                        * Referenced by: '<S3>/Game Controller'
                                        */
  boolean_T GameController_Enabled;    /* Computed Parameter: GameController_Enabled
                                        * Referenced by: '<S3>/Game Controller'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_q_heli3d_skeleton_2012 {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    real_T *contStates;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][13];
    ODE1_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[3];
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_q_heli3d_skeleton_20 q_heli3d_skeleton_2012b_P;

/* Block signals (auto storage) */
extern BlockIO_q_heli3d_skeleton_2012b q_heli3d_skeleton_2012b_B;

/* Continuous states (auto storage) */
extern ContinuousStates_q_heli3d_skele q_heli3d_skeleton_2012b_X;

/* Block states (auto storage) */
extern D_Work_q_heli3d_skeleton_2012b q_heli3d_skeleton_2012b_DWork;

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* Model entry point functions */
extern void q_heli3d_skeleton_2012b_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void q_heli3d_skeleton_2012b_initialize(void);
extern void q_heli3d_skeleton_2012b_step0(void);
extern void q_heli3d_skeleton_2012b_step(int_T tid);
extern void q_heli3d_skeleton_2012b_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_q_heli3d_skeleton_2012 *const q_heli3d_skeleton_2012b_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'q_heli3d_skeleton_2012b'
 * '<S1>'   : 'q_heli3d_skeleton_2012b/3-DOF Plant'
 * '<S2>'   : 'q_heli3d_skeleton_2012b/Desired Angle from Program'
 * '<S3>'   : 'q_heli3d_skeleton_2012b/Desired Position from Joystick'
 * '<S4>'   : 'q_heli3d_skeleton_2012b/Slider Offset Voltage'
 * '<S5>'   : 'q_heli3d_skeleton_2012b/Desired Angle from Program/Constant: Elevation (deg)'
 * '<S6>'   : 'q_heli3d_skeleton_2012b/Desired Angle from Program/Constant: Travel (deg)'
 * '<S7>'   : 'q_heli3d_skeleton_2012b/Desired Angle from Program/Repeating Sequence'
 * '<S8>'   : 'q_heli3d_skeleton_2012b/Desired Angle from Program/deg to rad'
 * '<S9>'   : 'q_heli3d_skeleton_2012b/Desired Position from Joystick/Convert (-1,1) to (0,1)'
 * '<S10>'  : 'q_heli3d_skeleton_2012b/Desired Position from Joystick/deg to rad'
 */
#endif                                 /* RTW_HEADER_q_heli3d_skeleton_2012b_h_ */
