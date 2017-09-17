/*
 * plant_block_swing_catch_dt.h
 *
 * Code generation for model "plant_block_swing_catch".
 *
 * Model version              : 1.183
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Fri Sep 15 17:30:00 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
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
  { (char_T *)(&plant_block_swing_catch_B.SFunction[0]), 0, 0, 39 }
  ,

  { (char_T *)(&plant_block_swing_catch_DW.FixPtUnitDelay1_DSTATE), 0, 0, 5 },

  { (char_T *)(&plant_block_swing_catch_DW.CatchEnable_PWORK.LoggedData), 11, 0,
    27 },

  { (char_T *)(&plant_block_swing_catch_DW.sfEvent), 6, 0, 1 },

  { (char_T *)(&plant_block_swing_catch_DW.is_active_c3_plant_block_swing_), 3,
    0, 2 },

  { (char_T *)(&plant_block_swing_catch_DW.isStable), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&plant_block_swing_catch_P.SFunction_P1_Size[0]), 0, 0, 71 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] plant_block_swing_catch_dt.h */
