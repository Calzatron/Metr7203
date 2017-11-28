/* Include files */

#include "blascompat32.h"
#include "q_heli3d_skeleton_2012b_sfun.h"
#include "c1_q_heli3d_skeleton_2012b.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "q_heli3d_skeleton_2012b_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_No_Reset                 ((uint8_T)1U)
#define c1_IN_Reset                    ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance);
static void initialize_params_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance);
static void enable_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance);
static void disable_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance);
static void ext_mode_exec_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance);
static void set_sim_state_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance, const mxArray
   *c1_st);
static void c1_set_sim_state_side_effects_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance);
static void finalize_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance);
static void sf_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance);
static void initSimStructsc1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static int32_T c1_emlrt_marshallIn(SFc1_q_heli3d_skeleton_2012bInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_b_emlrt_marshallIn(SFc1_q_heli3d_skeleton_2012bInstanceStruct
  *chartInstance, const mxArray *c1_x, const char_T *c1_identifier);
static real_T c1_c_emlrt_marshallIn(SFc1_q_heli3d_skeleton_2012bInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_d_emlrt_marshallIn(SFc1_q_heli3d_skeleton_2012bInstanceStruct *
  chartInstance, const mxArray *c1_is_active_c1_q_heli3d_skeleton_2012b, const
  char_T *c1_identifier);
static uint8_T c1_e_emlrt_marshallIn(SFc1_q_heli3d_skeleton_2012bInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static const mxArray *c1_f_emlrt_marshallIn
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance, const mxArray
   *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier);
static const mxArray *c1_g_emlrt_marshallIn
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_q_heli3d_skeleton_2012bInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance)
{
  int32_T *c1_sfEvent;
  uint8_T *c1_is_active_c1_q_heli3d_skeleton_2012b;
  uint8_T *c1_is_c1_q_heli3d_skeleton_2012b;
  real_T *c1_x;
  c1_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_c1_q_heli3d_skeleton_2012b = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_is_active_c1_q_heli3d_skeleton_2012b = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  *c1_is_active_c1_q_heli3d_skeleton_2012b = 0U;
  *c1_is_c1_q_heli3d_skeleton_2012b = 0U;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c1_x = 0.0;
  }
}

static void initialize_params_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance)
{
}

static void enable_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance)
{
  uint32_T c1_prevAniVal;
  uint8_T *c1_is_active_c1_q_heli3d_skeleton_2012b;
  uint8_T *c1_is_c1_q_heli3d_skeleton_2012b;
  int32_T *c1_sfEvent;
  c1_is_c1_q_heli3d_skeleton_2012b = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_is_active_c1_q_heli3d_skeleton_2012b = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  c1_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if (*c1_is_active_c1_q_heli3d_skeleton_2012b == 1) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, *c1_sfEvent);
  }

  if (*c1_is_c1_q_heli3d_skeleton_2012b == c1_IN_No_Reset) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *c1_sfEvent);
  }

  if (*c1_is_c1_q_heli3d_skeleton_2012b == c1_IN_Reset) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *c1_sfEvent);
  }

  sf_debug_set_animation(c1_prevAniVal);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance)
{
  c1_update_debugger_state_c1_q_heli3d_skeleton_2012b(chartInstance);
}

static const mxArray *get_sim_state_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  uint8_T c1_b_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  uint8_T c1_c_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T *c1_x;
  uint8_T *c1_is_active_c1_q_heli3d_skeleton_2012b;
  uint8_T *c1_is_c1_q_heli3d_skeleton_2012b;
  c1_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_c1_q_heli3d_skeleton_2012b = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_is_active_c1_q_heli3d_skeleton_2012b = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(3), FALSE);
  c1_hoistedGlobal = *c1_x;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_is_active_c1_q_heli3d_skeleton_2012b;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *c1_is_c1_q_heli3d_skeleton_2012b;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_x;
  uint8_T *c1_is_active_c1_q_heli3d_skeleton_2012b;
  uint8_T *c1_is_c1_q_heli3d_skeleton_2012b;
  c1_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_c1_q_heli3d_skeleton_2012b = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_is_active_c1_q_heli3d_skeleton_2012b = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c1_u = sf_mex_dup(c1_st);
  *c1_x = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "x");
  *c1_is_active_c1_q_heli3d_skeleton_2012b = c1_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 1)), "is_active_c1_q_heli3d_skeleton_2012b");
  *c1_is_c1_q_heli3d_skeleton_2012b = c1_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 2)), "is_c1_q_heli3d_skeleton_2012b");
  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 3)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_q_heli3d_skeleton_2012b(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_c1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance)
{
  boolean_T c1_temp;
  boolean_T c1_b_temp;
  boolean_T c1_out;
  boolean_T c1_c_temp;
  boolean_T c1_d_temp;
  boolean_T c1_b_out;
  int32_T *c1_sfEvent;
  uint8_T *c1_is_active_c1_q_heli3d_skeleton_2012b;
  uint8_T *c1_is_c1_q_heli3d_skeleton_2012b;
  real_T *c1_v1;
  real_T *c1_v2;
  real_T *c1_e;
  real_T *c1_x;
  c1_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_v2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_v1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_e = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_is_c1_q_heli3d_skeleton_2012b = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c1_is_active_c1_q_heli3d_skeleton_2012b = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  c1_set_sim_state_side_effects_c1_q_heli3d_skeleton_2012b(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, *c1_sfEvent);
  *c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *c1_sfEvent);
  if (*c1_is_active_c1_q_heli3d_skeleton_2012b == 0) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, *c1_sfEvent);
    *c1_is_active_c1_q_heli3d_skeleton_2012b = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, *c1_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *c1_sfEvent);
    *c1_is_c1_q_heli3d_skeleton_2012b = c1_IN_No_Reset;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *c1_sfEvent);
    *c1_x = 1.0;
  } else {
    switch (*c1_is_c1_q_heli3d_skeleton_2012b) {
     case c1_IN_No_Reset:
      CV_CHART_EVAL(0, 0, 1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, *c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, *c1_sfEvent);
      c1_temp = (_SFD_CCP_CALL(1U, 0, muDoubleScalarAbs(*c1_v1) < 0.3 != 0U,
                  *c1_sfEvent) != 0);
      if (c1_temp) {
        c1_temp = (_SFD_CCP_CALL(1U, 1, muDoubleScalarAbs(*c1_v2) < 0.3 != 0U,
                    *c1_sfEvent) != 0);
      }

      c1_b_temp = c1_temp;
      if (c1_b_temp) {
        c1_b_temp = (_SFD_CCP_CALL(1U, 2, muDoubleScalarAbs(*c1_e) < 0.015 != 0U,
          *c1_sfEvent) != 0);
      }

      c1_out = (CV_TRANSITION_EVAL(1U, (int32_T)c1_b_temp) != 0);
      if (c1_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *c1_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *c1_sfEvent);
        *c1_is_c1_q_heli3d_skeleton_2012b = c1_IN_Reset;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *c1_sfEvent);
        *c1_x = 0.0;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
      break;

     case c1_IN_Reset:
      CV_CHART_EVAL(0, 0, 2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, *c1_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, *c1_sfEvent);
      c1_c_temp = (_SFD_CCP_CALL(2U, 0, muDoubleScalarAbs(*c1_v1) > 0.3 != 0U,
        *c1_sfEvent) != 0);
      if (!c1_c_temp) {
        c1_c_temp = (_SFD_CCP_CALL(2U, 1, muDoubleScalarAbs(*c1_v2) > 0.3 != 0U,
          *c1_sfEvent) != 0);
      }

      c1_d_temp = c1_c_temp;
      if (!c1_d_temp) {
        c1_d_temp = (_SFD_CCP_CALL(2U, 2, muDoubleScalarAbs(*c1_e) > 0.015 != 0U,
          *c1_sfEvent) != 0);
      }

      c1_b_out = (CV_TRANSITION_EVAL(2U, (int32_T)c1_d_temp) != 0);
      if (c1_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *c1_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *c1_sfEvent);
        *c1_is_c1_q_heli3d_skeleton_2012b = c1_IN_No_Reset;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *c1_sfEvent);
        *c1_x = 1.0;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *c1_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);
      *c1_is_c1_q_heli3d_skeleton_2012b = c1_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *c1_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
  sf_debug_check_for_state_inconsistency(_q_heli3d_skeleton_2012bMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_q_heli3d_skeleton_2012b
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

const mxArray *sf_c1_q_heli3d_skeleton_2012b_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance;
  chartInstance = (SFc1_q_heli3d_skeleton_2012bInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_emlrt_marshallIn(SFc1_q_heli3d_skeleton_2012bInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i0, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance;
  chartInstance = (SFc1_q_heli3d_skeleton_2012bInstanceStruct *)
    chartInstanceVoid;
  c1_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_sfEvent), &c1_thisId);
  sf_mex_destroy(&c1_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance;
  chartInstance = (SFc1_q_heli3d_skeleton_2012bInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_b_emlrt_marshallIn(SFc1_q_heli3d_skeleton_2012bInstanceStruct
  *chartInstance, const mxArray *c1_x, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_x), &c1_thisId);
  sf_mex_destroy(&c1_x);
  return c1_y;
}

static real_T c1_c_emlrt_marshallIn(SFc1_q_heli3d_skeleton_2012bInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_x;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance;
  chartInstance = (SFc1_q_heli3d_skeleton_2012bInstanceStruct *)
    chartInstanceVoid;
  c1_x = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_x), &c1_thisId);
  sf_mex_destroy(&c1_x);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_q_heli3d_skeleton_2012bInstanceStruct *
  chartInstance, const mxArray *c1_is_active_c1_q_heli3d_skeleton_2012b, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_is_active_c1_q_heli3d_skeleton_2012b), &c1_thisId);
  sf_mex_destroy(&c1_is_active_c1_q_heli3d_skeleton_2012b);
  return c1_y;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_q_heli3d_skeleton_2012bInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static const mxArray *c1_f_emlrt_marshallIn
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance, const mxArray
   *c1_b_setSimStateSideEffectsInfo, const char_T *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), FALSE);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_g_emlrt_marshallIn
  (SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), FALSE);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_q_heli3d_skeleton_2012bInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c1_q_heli3d_skeleton_2012b_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2417983222U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3738215114U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1804036067U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(506672450U);
}

mxArray *sf_c1_q_heli3d_skeleton_2012b_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Ks5rOroYG8DAxu8lInB9DE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_q_heli3d_skeleton_2012b(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[11],T\"x\",},{M[8],M[0],T\"is_active_c1_q_heli3d_skeleton_2012b\",},{M[9],M[0],T\"is_c1_q_heli3d_skeleton_2012b\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_q_heli3d_skeleton_2012b_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance;
    chartInstance = (SFc1_q_heli3d_skeleton_2012bInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_q_heli3d_skeleton_2012bMachineNumber_,
           1,
           2,
           3,
           4,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_q_heli3d_skeleton_2012bMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_q_heli3d_skeleton_2012bMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_q_heli3d_skeleton_2012bMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"e");
          _SFD_SET_DATA_PROPS(1,1,1,0,"v1");
          _SFD_SET_DATA_PROPS(2,1,1,0,"v2");
          _SFD_SET_DATA_PROPS(3,2,0,1,"x");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 20, 38 };

          static unsigned int sEndGuardMap[] = { 15, 33, 52 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(1,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 20, 38 };

          static unsigned int sEndGuardMap[] = { 15, 33, 52 };

          static int sPostFixPredicateTree[] = { 0, 1, -2, 2, -2 };

          _SFD_CV_INIT_TRANS(2,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(1,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2, 20, 38 };

          static unsigned int sEndGuardMap[] = { 15, 33, 52 };

          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,3,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 2, 20, 38 };

          static unsigned int sEndGuardMap[] = { 15, 33, 52 };

          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          real_T *c1_e;
          real_T *c1_v1;
          real_T *c1_v2;
          real_T *c1_x;
          c1_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_v2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_v1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_e = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_e);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_v1);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_v2);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_x);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_q_heli3d_skeleton_2012bMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "lrpfWxd57AKRP18UjpGwEH";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_q_heli3d_skeleton_2012b_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 1, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c1_q_heli3d_skeleton_2012b(void
  *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc1_q_heli3d_skeleton_2012bInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc1_q_heli3d_skeleton_2012bInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_q_heli3d_skeleton_2012b
    ((SFc1_q_heli3d_skeleton_2012bInstanceStruct*) chartInstanceVar);
  initialize_c1_q_heli3d_skeleton_2012b
    ((SFc1_q_heli3d_skeleton_2012bInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_q_heli3d_skeleton_2012b(void *chartInstanceVar)
{
  enable_c1_q_heli3d_skeleton_2012b((SFc1_q_heli3d_skeleton_2012bInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_q_heli3d_skeleton_2012b(void *chartInstanceVar)
{
  disable_c1_q_heli3d_skeleton_2012b((SFc1_q_heli3d_skeleton_2012bInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_q_heli3d_skeleton_2012b(void *chartInstanceVar)
{
  sf_c1_q_heli3d_skeleton_2012b((SFc1_q_heli3d_skeleton_2012bInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c1_q_heli3d_skeleton_2012b(void
  *chartInstanceVar)
{
  ext_mode_exec_c1_q_heli3d_skeleton_2012b
    ((SFc1_q_heli3d_skeleton_2012bInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_q_heli3d_skeleton_2012b
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_q_heli3d_skeleton_2012b
    ((SFc1_q_heli3d_skeleton_2012bInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_q_heli3d_skeleton_2012b();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_q_heli3d_skeleton_2012b(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_q_heli3d_skeleton_2012b();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_q_heli3d_skeleton_2012b
    ((SFc1_q_heli3d_skeleton_2012bInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_q_heli3d_skeleton_2012b
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_q_heli3d_skeleton_2012b(S);
}

static void sf_opaque_set_sim_state_c1_q_heli3d_skeleton_2012b(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_q_heli3d_skeleton_2012b(S, st);
}

static void sf_opaque_terminate_c1_q_heli3d_skeleton_2012b(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_q_heli3d_skeleton_2012bInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_q_heli3d_skeleton_2012b
      ((SFc1_q_heli3d_skeleton_2012bInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_q_heli3d_skeleton_2012b_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_q_heli3d_skeleton_2012b
    ((SFc1_q_heli3d_skeleton_2012bInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_q_heli3d_skeleton_2012b(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_q_heli3d_skeleton_2012b
      ((SFc1_q_heli3d_skeleton_2012bInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c1_q_heli3d_skeleton_2012b_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S1x2'varName','path'{{T\"is_active_c1_q_heli3d_skeleton_2012b\",T\"is_active_c1_q_heli3d_skeleton_2012b\"},{T\"is_c1_q_heli3d_skeleton_2012b\",T\"is_c1_q_heli3d_skeleton_2012b\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x4'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"int32\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 4, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 3547959876U, 876003160U, 768275747U,
    427145602U };

  return checksum;
}

static void mdlSetWorkWidths_c1_q_heli3d_skeleton_2012b(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_q_heli3d_skeleton_2012b_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1179509603U));
  ssSetChecksum1(S,(2176514934U));
  ssSetChecksum2(S,(422826828U));
  ssSetChecksum3(S,(1976958261U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_q_heli3d_skeleton_2012b(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_q_heli3d_skeleton_2012b(SimStruct *S)
{
  SFc1_q_heli3d_skeleton_2012bInstanceStruct *chartInstance;
  chartInstance = (SFc1_q_heli3d_skeleton_2012bInstanceStruct *)malloc(sizeof
    (SFc1_q_heli3d_skeleton_2012bInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_q_heli3d_skeleton_2012bInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_q_heli3d_skeleton_2012b;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_q_heli3d_skeleton_2012b;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_q_heli3d_skeleton_2012b;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_q_heli3d_skeleton_2012b;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_q_heli3d_skeleton_2012b;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_q_heli3d_skeleton_2012b;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_q_heli3d_skeleton_2012b;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_q_heli3d_skeleton_2012b;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_q_heli3d_skeleton_2012b;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_q_heli3d_skeleton_2012b;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_q_heli3d_skeleton_2012b;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c1_q_heli3d_skeleton_2012b;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_q_heli3d_skeleton_2012b_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_q_heli3d_skeleton_2012b(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_q_heli3d_skeleton_2012b(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_q_heli3d_skeleton_2012b(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_q_heli3d_skeleton_2012b_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
