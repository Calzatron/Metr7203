/*
 * State_Flow_v0_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&State_Flow_v0_B.SFunction[0]), 0, 0, 31 },

  { (char_T *)(&State_Flow_v0_B.EnabledSubsystem2.uin), 0, 0, 1 },

  { (char_T *)(&State_Flow_v0_B.EnabledSubsystem.uin), 0, 0, 1 }
  ,

  { (char_T *)(&State_Flow_v0_DW.FixPtUnitDelay1_DSTATE), 0, 0, 4 },

  { (char_T *)(&State_Flow_v0_DW.CatchEnable_PWORK.LoggedData), 11, 0, 19 },

  { (char_T *)(&State_Flow_v0_DW.sfEvent), 6, 0, 1 },

  { (char_T *)(&State_Flow_v0_DW.is_active_c3_State_Flow_v0), 3, 0, 2 },

  { (char_T *)(&State_Flow_v0_DW.isStable), 8, 0, 1 },

  { (char_T *)(&State_Flow_v0_DW.EnabledSubsystem2.EnabledSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&State_Flow_v0_DW.EnabledSubsystem2.EnabledSubsystem_MODE), 8, 0,
    1 },

  { (char_T *)(&State_Flow_v0_DW.EnabledSubsystem.EnabledSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&State_Flow_v0_DW.EnabledSubsystem.EnabledSubsystem_MODE), 8, 0,
    1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  12U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&State_Flow_v0_P.SFunction_P1_Size[0]), 0, 0, 61 },

  { (char_T *)(&State_Flow_v0_P.EnabledSubsystem2.uout_Y0), 0, 0, 1 },

  { (char_T *)(&State_Flow_v0_P.EnabledSubsystem.uout_Y0), 0, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] State_Flow_v0_dt.h */
