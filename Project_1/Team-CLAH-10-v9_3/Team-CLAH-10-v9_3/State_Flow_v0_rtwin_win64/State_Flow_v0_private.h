/*
 * State_Flow_v0_private.h
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
#ifndef RTW_HEADER_State_Flow_v0_private_h_
#define RTW_HEADER_State_Flow_v0_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern void ECPDSPDriver(SimStruct *rts);
extern void State_Flow_v0_EnabledSubsystem_Start
  (B_EnabledSubsystem_State_Flow_v0_T *localB,
   DW_EnabledSubsystem_State_Flow_v0_T *localDW,
   P_EnabledSubsystem_State_Flow_v0_T *localP);
extern void State_Flow_v0_EnabledSubsystem_Disable
  (DW_EnabledSubsystem_State_Flow_v0_T *localDW);
extern void State_Flow_v0_EnabledSubsystem(RT_MODEL_State_Flow_v0_T * const
  State_Flow_v0_M, real_T rtu_0, real_T rtu_1,
  B_EnabledSubsystem_State_Flow_v0_T *localB,
  DW_EnabledSubsystem_State_Flow_v0_T *localDW);

/* private model entry point functions */
extern void State_Flow_v0_derivatives(void);

#endif                                 /* RTW_HEADER_State_Flow_v0_private_h_ */
