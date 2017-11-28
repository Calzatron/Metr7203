/*
 * plant_block_swing_catch.h
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
#ifndef RTW_HEADER_plant_block_swing_catch_h_
#define RTW_HEADER_plant_block_swing_catch_h_
#ifndef plant_block_swing_catch_COMMON_INCLUDES_
# define plant_block_swing_catch_COMMON_INCLUDES_
#include <math.h>
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "rtwintgt.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#include "rt_zcfcn.h"
#endif                                 /* plant_block_swing_catch_COMMON_INCLUDES_ */

#include "plant_block_swing_catch_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
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
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
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
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
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
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
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
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
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
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
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
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
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
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
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
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
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

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
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
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
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
# define rtmSetT(rtm, val)                                       /* Do Nothing */
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

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define plant_block_swing_catch_rtModel RT_MODEL_plant_block_swing_catch_T

/* Block signals (auto storage) */
typedef struct {
  real_T SFunction[5];                 /* '<S1>/S-Function' */
  real_T theta;                        /* '<Root>/Gain1' */
  real_T thetacorrection1;             /* '<S5>/theta correction1' */
  real_T theta_dot;                    /* '<Root>/Derivative1' */
  real_T Abs1;                         /* '<S5>/Abs1' */
  real_T Add2;                         /* '<Root>/Add2' */
  real_T LowPassFilterFlyWheel5;       /* '<Root>/Low Pass Filter Fly Wheel5' */
  real_T LowPassFilterFlyWheel3;       /* '<Root>/Low Pass Filter Fly Wheel3' */
  real_T Product2;                     /* '<Root>/Product2' */
  real_T LowPassFilterFlyWheel;        /* '<S2>/Low Pass Filter Fly Wheel' */
  real_T FilterCoefficient;            /* '<S8>/Filter Coefficient' */
  real_T Saturation;                   /* '<S2>/Saturation' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Derivative6;                  /* '<Root>/Derivative6' */
  real_T ActualGimbleVelocity;         /* '<Root>/Low Pass Filter Gimble Velocity' */
  real_T TransferFcn;                  /* '<S7>/Transfer Fcn' */
  real_T FilterCoefficient_a;          /* '<S18>/Filter Coefficient' */
  real_T Sum;                          /* '<S18>/Sum' */
  real_T LowPassFilterFlyWheel2;       /* '<Root>/Low Pass Filter Fly Wheel2' */
  real_T LowPassFilterFlyWheel1;       /* '<Root>/Low Pass Filter Fly Wheel1' */
  real_T E;                            /* '<S7>/Sum' */
  real_T Product2_b;                   /* '<S7>/Product2' */
  real_T w_2;                          /* '<S7>/Table Acceleration to Gimble Velocity' */
  real_T EnableSwingVelocity;          /* '<Root>/Enable Swing Velocity' */
  real_T Product;                      /* '<S3>/Product' */
  real_T SliderGain;                   /* '<S11>/Slider Gain' */
  real_T Abs;                          /* '<S3>/Abs' */
  real_T Product1;                     /* '<S3>/Product1' */
  real_T FilterCoefficient_p;          /* '<S10>/Filter Coefficient' */
  real_T Sum_o;                        /* '<S10>/Sum' */
  real_T Add;                          /* '<S3>/Add' */
  real_T encodertoradians;             /* '<S2>/encoder to radians' */
  real_T Derivative;                   /* '<S2>/Derivative' */
  real_T IntegralGain;                 /* '<S8>/Integral Gain' */
  real_T radsectorpm;                  /* '<S2>/rad//sec to rpm' */
  real_T theta4;                       /* '<Root>/Gain3' */
  real_T IntegralGain_a;               /* '<S10>/Integral Gain' */
  real_T Resetafterswingstate;         /* '<S7>/Abs1' */
  real_T FixPtUnitDelay1;              /* '<S19>/FixPt Unit Delay1' */
  real_T Reset;                        /* '<S19>/Reset' */
  real_T Sum3;                         /* '<S7>/Sum3' */
  real_T IntegralGain_p;               /* '<S18>/Integral Gain' */
  real_T x;                            /* '<S5>/State Switch v1' */
  real_T y;                            /* '<S5>/State Switch v1' */
  real_T z;                            /* '<S5>/State Switch v1' */
  real_T r;                            /* '<S5>/State Switch v1' */
} B_plant_block_swing_catch_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T FixPtUnitDelay1_DSTATE;       /* '<S19>/FixPt Unit Delay1' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative1_RWORK;                 /* '<Root>/Derivative1' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative4_RWORK;                 /* '<Root>/Derivative4' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative5_RWORK;                 /* '<Root>/Derivative5' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative6_RWORK;                 /* '<Root>/Derivative6' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK;                  /* '<S2>/Derivative' */

  struct {
    void *LoggedData;
  } AllStopr_PWORK;                    /* '<Root>/All Stop - r' */

  struct {
    void *LoggedData;
  } CatchEnable_PWORK;                 /* '<Root>/Catch Enable' */

  struct {
    void *LoggedData;
  } CatchEnableuin1_PWORK;             /* '<Root>/Catch Enable - u -in1' */

  struct {
    void *LoggedData;
  } CatchEnableuout_PWORK;             /* '<Root>/Catch Enable - u-out' */

  struct {
    void *LoggedData;
  } Encoder1_PWORK;                    /* '<Root>/Encoder 1' */

  struct {
    void *LoggedData;
  } FlywheelVoltage_PWORK;             /* '<Root>/Flywheel Voltage' */

  struct {
    void *LoggedData;
  } GimbalEncoder1_PWORK;              /* '<Root>/Gimbal Encoder1' */

  struct {
    void *LoggedData;
  } GimbleVelocityscope_PWORK;         /* '<Root>/Gimble Velocity scope' */

  struct {
    void *LoggedData;
  } GimbleVoltage_PWORK;               /* '<Root>/Gimble Voltage' */

  struct {
    void *LoggedData;
  } PendulumEncoder_PWORK;             /* '<Root>/Pendulum Encoder' */

  struct {
    void *LoggedData;
  } PendulumEncodervel_PWORK;          /* '<Root>/Pendulum Encoder vel' */

  struct {
    void *LoggedData;
  } Restx_PWORK;                       /* '<Root>/Rest - x' */

  struct {
    void *LoggedData;
  } SwingEnableuin2_PWORK;             /* '<Root>/Swing Enable - u -in2' */

  struct {
    void *LoggedData;
  } SwingEnableuin3_PWORK;             /* '<Root>/Swing Enable - u -in3' */

  struct {
    void *LoggedData;
  } SwingEnableuout_PWORK;             /* '<Root>/Swing Enable - u -out' */

  struct {
    void *LoggedData;
  } SwingEnabley_PWORK;                /* '<Root>/Swing Enable - y' */

  struct {
    void *LoggedData;
  } SwingOuput_PWORK;                  /* '<Root>/Swing Ouput' */

  struct {
    void *LoggedData;
  } FlywheelRotSpeedrads_PWORK;        /* '<S2>/Flywheel Rot Speed, rad//s' */

  struct {
    void *LoggedData;
  } RPM_PWORK;                         /* '<S2>/RPM' */

  struct {
    void *LoggedData;
  } catchcheck_PWORK;                  /* '<S3>/catch check' */

  struct {
    void *LoggedData;
  } catcherror_PWORK;                  /* '<S3>/catch error' */

  struct {
    void *LoggedData;
  } swingcheck_PWORK;                  /* '<S3>/swing check' */

  struct {
    void *LoggedData;
  } swingcheck1_PWORK;                 /* '<S3>/swing check1' */

  struct {
    void *LoggedData;
  } swingcheck2_PWORK;                 /* '<S3>/swing check2' */

  struct {
    void *LoggedData;
  } swingerror_PWORK;                  /* '<S3>/swing error' */

  struct {
    void *LoggedData;
  } Collect_PWORK;                     /* '<S7>/Collect' */

  struct {
    void *LoggedData;
  } Energy_PWORK;                      /* '<S7>/Energy' */

  struct {
    void *LoggedData;
  } Error_PWORK;                       /* '<S7>/Error' */

  struct {
    void *LoggedData;
  } K_PWORK;                           /* '<S7>/K' */

  struct {
    void *LoggedData;
  } Lyapunovseqn_PWORK;                /* '<S7>/Lyapunov's eqn' */

  struct {
    void *LoggedData;
  } MinEnergy_PWORK;                   /* '<S7>/Min Energy' */

  struct {
    void *LoggedData;
  } Theta__PWORK;                      /* '<S7>/Theta_' */

  int32_T sfEvent;                     /* '<S5>/State Switch v1' */
  uint8_T is_active_c3_plant_block_swing_;/* '<S5>/State Switch v1' */
  uint8_T is_c3_plant_block_swing_catch;/* '<S5>/State Switch v1' */
  boolean_T isStable;                  /* '<S5>/State Switch v1' */
} DW_plant_block_swing_catch_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T LowPassFilterFlyWheel4_CSTATE;/* '<Root>/Low Pass Filter Fly Wheel4' */
  real_T LowPassFilterFlyWheel6_CSTATE;/* '<Root>/Low Pass Filter Fly Wheel6' */
  real_T LowPassFilterFlyWheel5_CSTATE;/* '<Root>/Low Pass Filter Fly Wheel5' */
  real_T LowPassFilterFlyWheel3_CSTATE;/* '<Root>/Low Pass Filter Fly Wheel3' */
  real_T LowPassFilterFlyWheel_CSTATE; /* '<S2>/Low Pass Filter Fly Wheel' */
  real_T Integrator_CSTATE;            /* '<S8>/Integrator' */
  real_T Filter_CSTATE;                /* '<S8>/Filter' */
  real_T LowPassFilterGimbleVelocity_CST;/* '<Root>/Low Pass Filter Gimble Velocity' */
  real_T TransferFcn_CSTATE;           /* '<S7>/Transfer Fcn' */
  real_T Integrator_CSTATE_m;          /* '<S18>/Integrator' */
  real_T Filter_CSTATE_f;              /* '<S18>/Filter' */
  real_T LowPassFilterFlyWheel2_CSTATE;/* '<Root>/Low Pass Filter Fly Wheel2' */
  real_T LowPassFilterFlyWheel1_CSTATE;/* '<Root>/Low Pass Filter Fly Wheel1' */
  real_T Integrator_CSTATE_k;          /* '<S10>/Integrator' */
  real_T Filter_CSTATE_o;              /* '<S10>/Filter' */
} X_plant_block_swing_catch_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T LowPassFilterFlyWheel4_CSTATE;/* '<Root>/Low Pass Filter Fly Wheel4' */
  real_T LowPassFilterFlyWheel6_CSTATE;/* '<Root>/Low Pass Filter Fly Wheel6' */
  real_T LowPassFilterFlyWheel5_CSTATE;/* '<Root>/Low Pass Filter Fly Wheel5' */
  real_T LowPassFilterFlyWheel3_CSTATE;/* '<Root>/Low Pass Filter Fly Wheel3' */
  real_T LowPassFilterFlyWheel_CSTATE; /* '<S2>/Low Pass Filter Fly Wheel' */
  real_T Integrator_CSTATE;            /* '<S8>/Integrator' */
  real_T Filter_CSTATE;                /* '<S8>/Filter' */
  real_T LowPassFilterGimbleVelocity_CST;/* '<Root>/Low Pass Filter Gimble Velocity' */
  real_T TransferFcn_CSTATE;           /* '<S7>/Transfer Fcn' */
  real_T Integrator_CSTATE_m;          /* '<S18>/Integrator' */
  real_T Filter_CSTATE_f;              /* '<S18>/Filter' */
  real_T LowPassFilterFlyWheel2_CSTATE;/* '<Root>/Low Pass Filter Fly Wheel2' */
  real_T LowPassFilterFlyWheel1_CSTATE;/* '<Root>/Low Pass Filter Fly Wheel1' */
  real_T Integrator_CSTATE_k;          /* '<S10>/Integrator' */
  real_T Filter_CSTATE_o;              /* '<S10>/Filter' */
} XDot_plant_block_swing_catch_T;

/* State disabled  */
typedef struct {
  boolean_T LowPassFilterFlyWheel4_CSTATE;/* '<Root>/Low Pass Filter Fly Wheel4' */
  boolean_T LowPassFilterFlyWheel6_CSTATE;/* '<Root>/Low Pass Filter Fly Wheel6' */
  boolean_T LowPassFilterFlyWheel5_CSTATE;/* '<Root>/Low Pass Filter Fly Wheel5' */
  boolean_T LowPassFilterFlyWheel3_CSTATE;/* '<Root>/Low Pass Filter Fly Wheel3' */
  boolean_T LowPassFilterFlyWheel_CSTATE;/* '<S2>/Low Pass Filter Fly Wheel' */
  boolean_T Integrator_CSTATE;         /* '<S8>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S8>/Filter' */
  boolean_T LowPassFilterGimbleVelocity_CST;/* '<Root>/Low Pass Filter Gimble Velocity' */
  boolean_T TransferFcn_CSTATE;        /* '<S7>/Transfer Fcn' */
  boolean_T Integrator_CSTATE_m;       /* '<S18>/Integrator' */
  boolean_T Filter_CSTATE_f;           /* '<S18>/Filter' */
  boolean_T LowPassFilterFlyWheel2_CSTATE;/* '<Root>/Low Pass Filter Fly Wheel2' */
  boolean_T LowPassFilterFlyWheel1_CSTATE;/* '<Root>/Low Pass Filter Fly Wheel1' */
  boolean_T Integrator_CSTATE_k;       /* '<S10>/Integrator' */
  boolean_T Filter_CSTATE_o;           /* '<S10>/Filter' */
} XDis_plant_block_swing_catch_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S18>/Integrator' */
  ZCSigState Filter_Reset_ZCE;         /* '<S18>/Filter' */
} PrevZCX_plant_block_swing_catch_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            plant_block_swing_catch_B
#define BlockIO                        B_plant_block_swing_catch_T
#define rtX                            plant_block_swing_catch_X
#define ContinuousStates               X_plant_block_swing_catch_T
#define rtXdot                         plant_block_swing_catch_XDot
#define StateDerivatives               XDot_plant_block_swing_catch_T
#define tXdis                          plant_block_swing_catch_XDis
#define StateDisabled                  XDis_plant_block_swing_catch_T
#define rtP                            plant_block_swing_catch_P
#define Parameters                     P_plant_block_swing_catch_T
#define rtDWork                        plant_block_swing_catch_DW
#define D_Work                         DW_plant_block_swing_catch_T
#define rtPrevZCSigState               plant_block_swing_catch_PrevZCX
#define PrevZCSigStates                PrevZCX_plant_block_swing_catch_T

/* Parameters (auto storage) */
struct P_plant_block_swing_catch_T_ {
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T SFunction_P1[6];              /* Computed Parameter: SFunction_P1
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T SFunction_P2;                 /* Expression: STime
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T SFunction_P3_Size[2];         /* Computed Parameter: SFunction_P3_Size
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T SFunction_P3;                 /* Expression: TimeOutPer
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T SFunction_P4_Size[2];         /* Computed Parameter: SFunction_P4_Size
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T SFunction_P4;                 /* Expression: HWAccess
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/(2608*32)
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Constant4_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S5>/Constant4'
                                        */
  real_T LowPassFilterFlyWheel4_A;     /* Computed Parameter: LowPassFilterFlyWheel4_A
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel4'
                                        */
  real_T LowPassFilterFlyWheel4_C;     /* Computed Parameter: LowPassFilterFlyWheel4_C
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel4'
                                        */
  real_T Constant1_Value;              /* Expression: 2*pi
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: pi
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T LowPassFilterFlyWheel6_A;     /* Computed Parameter: LowPassFilterFlyWheel6_A
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel6'
                                        */
  real_T LowPassFilterFlyWheel6_C;     /* Computed Parameter: LowPassFilterFlyWheel6_C
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel6'
                                        */
  real_T SliderGain_Gain;              /* Expression: gain
                                        * Referenced by: '<S13>/Slider Gain'
                                        */
  real_T LowPassFilterFlyWheel5_A;     /* Computed Parameter: LowPassFilterFlyWheel5_A
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel5'
                                        */
  real_T LowPassFilterFlyWheel5_C;     /* Computed Parameter: LowPassFilterFlyWheel5_C
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel5'
                                        */
  real_T SliderGain_Gain_n;            /* Expression: gain
                                        * Referenced by: '<S14>/Slider Gain'
                                        */
  real_T SliderGain_Gain_a;            /* Expression: gain
                                        * Referenced by: '<S15>/Slider Gain'
                                        */
  real_T LowPassFilterFlyWheel3_A;     /* Computed Parameter: LowPassFilterFlyWheel3_A
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel3'
                                        */
  real_T LowPassFilterFlyWheel3_C;     /* Computed Parameter: LowPassFilterFlyWheel3_C
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel3'
                                        */
  real_T SliderGain_Gain_c;            /* Expression: gain
                                        * Referenced by: '<S16>/Slider Gain'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1
                                        * Referenced by: '<S6>/Gain4'
                                        */
  real_T LowPassFilterFlyWheel_A;      /* Computed Parameter: LowPassFilterFlyWheel_A
                                        * Referenced by: '<S2>/Low Pass Filter Fly Wheel'
                                        */
  real_T LowPassFilterFlyWheel_C;      /* Computed Parameter: LowPassFilterFlyWheel_C
                                        * Referenced by: '<S2>/Low Pass Filter Fly Wheel'
                                        */
  real_T Desiredrpm_Value;             /* Expression: 400
                                        * Referenced by: '<S2>/Desired rpm'
                                        */
  real_T ProportionalGain_Gain;        /* Expression: P
                                        * Referenced by: '<S8>/Proportional Gain'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S8>/Integrator'
                                        */
  real_T DerivativeGain_Gain;          /* Expression: D
                                        * Referenced by: '<S8>/Derivative Gain'
                                        */
  real_T Filter_IC;                    /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S8>/Filter'
                                        */
  real_T FilterCoefficient_Gain;       /* Expression: N
                                        * Referenced by: '<S8>/Filter Coefficient'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 32000
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -32000
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/(3882*32)
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T LowPassFilterGimbleVelocity_A;/* Computed Parameter: LowPassFilterGimbleVelocity_A
                                        * Referenced by: '<Root>/Low Pass Filter Gimble Velocity'
                                        */
  real_T LowPassFilterGimbleVelocity_C;/* Computed Parameter: LowPassFilterGimbleVelocity_C
                                        * Referenced by: '<Root>/Low Pass Filter Gimble Velocity'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S7>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S7>/Transfer Fcn'
                                        */
  real_T ProportionalGain_Gain_n;      /* Expression: P
                                        * Referenced by: '<S18>/Proportional Gain'
                                        */
  real_T Integrator_IC_b;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S18>/Integrator'
                                        */
  real_T DerivativeGain_Gain_l;        /* Expression: D
                                        * Referenced by: '<S18>/Derivative Gain'
                                        */
  real_T Filter_IC_m;                  /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S18>/Filter'
                                        */
  real_T FilterCoefficient_Gain_e;     /* Expression: N
                                        * Referenced by: '<S18>/Filter Coefficient'
                                        */
  real_T LowPassFilterFlyWheel2_A;     /* Computed Parameter: LowPassFilterFlyWheel2_A
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel2'
                                        */
  real_T LowPassFilterFlyWheel2_C;     /* Computed Parameter: LowPassFilterFlyWheel2_C
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel2'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 0.5*0.0131
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T LowPassFilterFlyWheel1_A;     /* Computed Parameter: LowPassFilterFlyWheel1_A
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel1'
                                        */
  real_T LowPassFilterFlyWheel1_C;     /* Computed Parameter: LowPassFilterFlyWheel1_C
                                        * Referenced by: '<Root>/Low Pass Filter Fly Wheel1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0.1580*9.81*0.2698
                                        * Referenced by: '<S7>/Gain2'
                                        */
  real_T TableAccelerationtoGimbleVeloci;/* Expression: 0.1530/(41.8879*0.0273*0.37)
                                          * Referenced by: '<S7>/Table Acceleration to Gimble Velocity'
                                          */
  real_T SliderGain_Gain_e;            /* Expression: gain
                                        * Referenced by: '<S11>/Slider Gain'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 40000
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -40000
                                        * Referenced by: '<S3>/Saturation1'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T ProportionalGain_Gain_i;      /* Expression: P
                                        * Referenced by: '<S10>/Proportional Gain'
                                        */
  real_T Integrator_IC_p;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S10>/Integrator'
                                        */
  real_T DerivativeGain_Gain_n;        /* Expression: D
                                        * Referenced by: '<S10>/Derivative Gain'
                                        */
  real_T Filter_IC_mr;                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S10>/Filter'
                                        */
  real_T FilterCoefficient_Gain_f;     /* Expression: N
                                        * Referenced by: '<S10>/Filter Coefficient'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 9500
                                        * Referenced by: '<S3>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -9500
                                        * Referenced by: '<S3>/Saturation2'
                                        */
  real_T encodertoradians_Gain;        /* Expression: 1/(1061*32)
                                        * Referenced by: '<S2>/encoder to radians'
                                        */
  real_T IntegralGain_Gain;            /* Expression: I
                                        * Referenced by: '<S8>/Integral Gain'
                                        */
  real_T radsectorpm_Gain;             /* Expression: 30/pi
                                        * Referenced by: '<S2>/rad//sec to rpm'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/(2546*32)
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T IntegralGain_Gain_m;          /* Expression: I
                                        * Referenced by: '<S10>/Integral Gain'
                                        */
  real_T Constant4_Value_l;            /* Expression: 1
                                        * Referenced by: '<S7>/Constant4'
                                        */
  real_T DesiredEnergy_Value;          /* Expression: 0
                                        * Referenced by: '<S7>/Desired Energy'
                                        */
  real_T InitialCondition_Value;       /* Expression: vinit
                                        * Referenced by: '<S19>/Initial Condition'
                                        */
  real_T FixPtUnitDelay1_InitialConditio;/* Expression: vinit
                                          * Referenced by: '<S19>/FixPt Unit Delay1'
                                          */
  real_T IntegralGain_Gain_d;          /* Expression: I
                                        * Referenced by: '<S18>/Integral Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_plant_block_swing_catch_T {
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
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[1];
    SimStruct *childSFunctionPtrs[1];
    struct _ssBlkInfo2 blkInfo2[1];
    struct _ssSFcnModelMethods2 methods2[1];
    struct _ssSFcnModelMethods3 methods3[1];
    struct _ssStatesInfo2 statesInfo2[1];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[2];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
    } Sfcn0;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][15];
    ODE1_IntgData intgData;
    void *dwork;
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
    void *xpcData;
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
    time_T stepSize1;
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
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_plant_block_swing_catch_T plant_block_swing_catch_P;

/* Block signals (auto storage) */
extern B_plant_block_swing_catch_T plant_block_swing_catch_B;

/* Continuous states (auto storage) */
extern X_plant_block_swing_catch_T plant_block_swing_catch_X;

/* Block states (auto storage) */
extern DW_plant_block_swing_catch_T plant_block_swing_catch_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_plant_block_swing_catch_T plant_block_swing_catch_PrevZCX;

/* Model entry point functions */
extern RT_MODEL_plant_block_swing_catch_T *plant_block_swing_catch(void);
extern void plant_block_swing_catch_initialize(void);
extern void plant_block_swing_catch_output(void);
extern void plant_block_swing_catch_update(void);
extern void plant_block_swing_catch_terminate(void);

/* Real-time Model object */
extern RT_MODEL_plant_block_swing_catch_T *const plant_block_swing_catch_M;

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
 * '<Root>' : 'plant_block_swing_catch'
 * '<S1>'   : 'plant_block_swing_catch/ECPDSP Driver'
 * '<S2>'   : 'plant_block_swing_catch/Flywheel Control'
 * '<S3>'   : 'plant_block_swing_catch/Gimble Control'
 * '<S4>'   : 'plant_block_swing_catch/PID Controller1'
 * '<S5>'   : 'plant_block_swing_catch/State Selection'
 * '<S6>'   : 'plant_block_swing_catch/Subsystem2'
 * '<S7>'   : 'plant_block_swing_catch/Swing Up'
 * '<S8>'   : 'plant_block_swing_catch/Flywheel Control/PID Controller'
 * '<S9>'   : 'plant_block_swing_catch/Gimble Control/PID Gimble Velocity - Catch'
 * '<S10>'  : 'plant_block_swing_catch/Gimble Control/PID Gimble Velocity - Swing'
 * '<S11>'  : 'plant_block_swing_catch/Gimble Control/Slider Gain'
 * '<S12>'  : 'plant_block_swing_catch/State Selection/State Switch v1'
 * '<S13>'  : 'plant_block_swing_catch/Subsystem2/Slider Gain'
 * '<S14>'  : 'plant_block_swing_catch/Subsystem2/Slider Gain1'
 * '<S15>'  : 'plant_block_swing_catch/Subsystem2/Slider Gain2'
 * '<S16>'  : 'plant_block_swing_catch/Subsystem2/Slider Gain3'
 * '<S17>'  : 'plant_block_swing_catch/Swing Up/MinMax Running Resettable1'
 * '<S18>'  : 'plant_block_swing_catch/Swing Up/PID Controller'
 * '<S19>'  : 'plant_block_swing_catch/Swing Up/MinMax Running Resettable1/Unit Delay With Preview Resettable'
 */
#endif                                 /* RTW_HEADER_plant_block_swing_catch_h_ */
