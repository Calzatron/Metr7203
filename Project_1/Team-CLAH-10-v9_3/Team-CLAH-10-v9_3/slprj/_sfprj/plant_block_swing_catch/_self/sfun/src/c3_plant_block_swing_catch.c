/* Include files */

#include <stddef.h>
#include "blas.h"
#include "plant_block_swing_catch_sfun.h"
#include "c3_plant_block_swing_catch.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "plant_block_swing_catch_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_Catch                    ((uint8_T)1U)
#define c3_IN_ReSwing                  ((uint8_T)2U)
#define c3_IN_Rest                     ((uint8_T)3U)
#define c3_IN_Swing                    ((uint8_T)4U)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_e_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_f_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_g_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_h_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_i_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_j_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_k_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_l_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_m_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_n_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_o_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static const char * c3_p_debug_family_names[3] = { "nargin", "nargout",
  "evilsf_internal_predicateOutput" };

static boolean_T c3_dataWrittenToVector[4];

/* Function Declarations */
static void initialize_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance);
static void initialize_params_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance);
static void enable_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance);
static void disable_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance);
static void ext_mode_exec_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance);
static void set_sim_state_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance, const mxArray
   *c3_st);
static void c3_set_sim_state_side_effects_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance);
static void finalize_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance);
static void sf_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance);
static void c3_chartstep_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance);
static void initSimStructsc3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance);
static void registerMessagesc3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_plant_block_swing_catchInstanceStruct
  *chartInstance, const mxArray *c3_nargout, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_plant_block_swing_catchInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_c_emlrt_marshallIn
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn(SFc3_plant_block_swing_catchInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_e_emlrt_marshallIn(SFc3_plant_block_swing_catchInstanceStruct *
  chartInstance, const mxArray *c3_is_active_c3_plant_block_swing_catch, const
  char_T *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn(SFc3_plant_block_swing_catchInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static const mxArray *c3_g_emlrt_marshallIn
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier);
static const mxArray *c3_h_emlrt_marshallIn
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_updateDataWrittenToVector
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance, uint32_T
   c3_vectorIndex);
static void c3_errorIfDataNotWrittenToFcn
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance, uint32_T
   c3_vectorIndex, uint32_T c3_dataNumber);
static void init_dsm_address_info(SFc3_plant_block_swing_catchInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance)
{
  int32_T *c3_sfEvent;
  uint8_T *c3_is_active_c3_plant_block_swing_catch;
  uint8_T *c3_is_c3_plant_block_swing_catch;
  c3_is_c3_plant_block_swing_catch = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c3_is_active_c3_plant_block_swing_catch = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  *c3_is_active_c3_plant_block_swing_catch = 0U;
  *c3_is_c3_plant_block_swing_catch = c3_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance)
{
}

static void enable_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  uint8_T *c3_is_active_c3_plant_block_swing_catch;
  uint8_T *c3_is_c3_plant_block_swing_catch;
  int32_T *c3_sfEvent;
  c3_is_c3_plant_block_swing_catch = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c3_is_active_c3_plant_block_swing_catch = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (*c3_is_active_c3_plant_block_swing_catch == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, *c3_sfEvent);
  }

  if (*c3_is_c3_plant_block_swing_catch == c3_IN_Swing) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *c3_sfEvent);
  }

  if (*c3_is_c3_plant_block_swing_catch == c3_IN_Rest) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *c3_sfEvent);
  }

  if (*c3_is_c3_plant_block_swing_catch == c3_IN_Catch) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *c3_sfEvent);
  }

  if (*c3_is_c3_plant_block_swing_catch == c3_IN_ReSwing) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance)
{
  c3_update_debugger_state_c3_plant_block_swing_catch(chartInstance);
}

static const mxArray *get_sim_state_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_d_hoistedGlobal;
  real_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  uint8_T c3_e_hoistedGlobal;
  uint8_T c3_e_u;
  const mxArray *c3_f_y = NULL;
  uint8_T c3_f_hoistedGlobal;
  uint8_T c3_f_u;
  const mxArray *c3_g_y = NULL;
  real_T *c3_r;
  real_T *c3_x;
  real_T *c3_h_y;
  real_T *c3_z;
  uint8_T *c3_is_active_c3_plant_block_swing_catch;
  uint8_T *c3_is_c3_plant_block_swing_catch;
  c3_r = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_h_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_c3_plant_block_swing_catch = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c3_is_active_c3_plant_block_swing_catch = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(6), FALSE);
  c3_hoistedGlobal = *c3_r;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_x;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *c3_h_y;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = *c3_z;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = *c3_is_active_c3_plant_block_swing_catch;
  c3_e_u = c3_e_hoistedGlobal;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = *c3_is_c3_plant_block_swing_catch;
  c3_f_u = c3_f_hoistedGlobal;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance, const mxArray
   *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_r;
  real_T *c3_x;
  real_T *c3_y;
  real_T *c3_z;
  uint8_T *c3_is_active_c3_plant_block_swing_catch;
  uint8_T *c3_is_c3_plant_block_swing_catch;
  c3_r = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_c3_plant_block_swing_catch = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c3_is_active_c3_plant_block_swing_catch = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c3_u = sf_mex_dup(c3_st);
  *c3_r = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
    "r");
  *c3_x = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "x");
  *c3_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
    "y");
  *c3_z = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
    "z");
  *c3_is_active_c3_plant_block_swing_catch = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 4)), "is_active_c3_plant_block_swing_catch");
  *c3_is_c3_plant_block_swing_catch = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 5)), "is_c3_plant_block_swing_catch");
  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 6)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_plant_block_swing_catch(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance)
{
  int32_T *c3_sfEvent;
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  c3_set_sim_state_side_effects_c3_plant_block_swing_catch(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, *c3_sfEvent);
  *c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_plant_block_swing_catch(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_plant_block_swing_catchMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  uint32_T c3_b_debug_family_var_map[3];
  real_T c3_b_nargin = 0.0;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 1.0;
  boolean_T c3_b_out;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_f_hoistedGlobal;
  real_T c3_d_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_g_hoistedGlobal;
  real_T c3_e_u;
  const mxArray *c3_e_y = NULL;
  real_T c3_e_nargin = 0.0;
  real_T c3_e_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  real_T c3_h_hoistedGlobal;
  real_T c3_f_u;
  const mxArray *c3_f_y = NULL;
  real_T c3_i_hoistedGlobal;
  real_T c3_g_u;
  const mxArray *c3_g_y = NULL;
  real_T c3_g_nargin = 0.0;
  real_T c3_g_nargout = 1.0;
  boolean_T c3_d_out;
  real_T c3_h_nargin = 0.0;
  real_T c3_h_nargout = 0.0;
  real_T c3_j_hoistedGlobal;
  real_T c3_h_u;
  const mxArray *c3_h_y = NULL;
  real_T c3_k_hoistedGlobal;
  real_T c3_i_u;
  const mxArray *c3_i_y = NULL;
  real_T c3_l_hoistedGlobal;
  real_T c3_j_u;
  const mxArray *c3_j_y = NULL;
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 1.0;
  boolean_T c3_e_out;
  real_T c3_j_nargin = 0.0;
  real_T c3_j_nargout = 0.0;
  real_T c3_m_hoistedGlobal;
  real_T c3_k_u;
  const mxArray *c3_k_y = NULL;
  real_T c3_n_hoistedGlobal;
  real_T c3_l_u;
  const mxArray *c3_l_y = NULL;
  real_T c3_o_hoistedGlobal;
  real_T c3_m_u;
  const mxArray *c3_m_y = NULL;
  real_T c3_k_nargin = 0.0;
  real_T c3_k_nargout = 1.0;
  boolean_T c3_f_out;
  real_T c3_p_hoistedGlobal;
  real_T c3_l_nargin = 0.0;
  real_T c3_l_nargout = 1.0;
  boolean_T c3_g_out;
  boolean_T c3_b0;
  boolean_T c3_b1;
  real_T c3_m_nargin = 0.0;
  real_T c3_m_nargout = 0.0;
  real_T c3_q_hoistedGlobal;
  real_T c3_n_u;
  const mxArray *c3_n_y = NULL;
  real_T c3_r_hoistedGlobal;
  real_T c3_o_u;
  const mxArray *c3_o_y = NULL;
  real_T c3_n_nargin = 0.0;
  real_T c3_n_nargout = 1.0;
  boolean_T c3_h_out;
  real_T c3_o_nargin = 0.0;
  real_T c3_o_nargout = 0.0;
  real_T c3_s_hoistedGlobal;
  real_T c3_p_u;
  const mxArray *c3_p_y = NULL;
  real_T c3_t_hoistedGlobal;
  real_T c3_q_u;
  const mxArray *c3_q_y = NULL;
  real_T *c3_r_y;
  real_T *c3_x;
  real_T *c3_r;
  real_T *c3_z;
  uint8_T *c3_is_c3_plant_block_swing_catch;
  uint8_T *c3_is_active_c3_plant_block_swing_catch;
  real_T *c3_theta;
  real_T *c3_theta_dot;
  int32_T *c3_sfEvent;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  c3_r = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c3_theta_dot = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c3_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c3_r_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_c3_plant_block_swing_catch = (uint8_T *)ssGetDWork(chartInstance->S, 3);
  c3_is_active_c3_plant_block_swing_catch = (uint8_T *)ssGetDWork
    (chartInstance->S, 2);
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *c3_sfEvent);
  if (*c3_is_active_c3_plant_block_swing_catch == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, *c3_sfEvent);
    *c3_is_active_c3_plant_block_swing_catch = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *c3_sfEvent);
    *c3_is_c3_plant_block_swing_catch = c3_IN_Rest;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    *c3_x = 1.0;
    c3_updateDataWrittenToVector(chartInstance, 0U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
    sf_mex_printf("%s =\\n", "x");
    c3_hoistedGlobal = *c3_x;
    c3_u = c3_hoistedGlobal;
    c3_y = NULL;
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
    sf_mex_call_debug("disp", 0U, 1U, 14, c3_y);
    *c3_r_y = 0.0;
    c3_updateDataWrittenToVector(chartInstance, 1U);
    c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
    sf_mex_printf("%s =\\n", "y");
    c3_b_hoistedGlobal = *c3_r_y;
    c3_b_u = c3_b_hoistedGlobal;
    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), FALSE);
    sf_mex_call_debug("disp", 0U, 1U, 14, c3_b_y);
    *c3_z = 0.0;
    c3_updateDataWrittenToVector(chartInstance, 2U);
    *c3_r = 0.0;
    c3_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (*c3_is_c3_plant_block_swing_catch) {
     case c3_IN_Catch:
      CV_CHART_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, *c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_h_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_c_hoistedGlobal = *c3_theta;
      guard4 = FALSE;
      if (CV_EML_COND(1, 0, 0, c3_c_hoistedGlobal < 2.7475)) {
        guard4 = TRUE;
      } else {
        c3_d_hoistedGlobal = *c3_theta;
        if (CV_EML_COND(1, 0, 1, c3_d_hoistedGlobal > 3.5325)) {
          guard4 = TRUE;
        } else {
          CV_EML_MCDC(1, 0, 0, FALSE);
          CV_EML_IF(1, 0, 0, FALSE);
          c3_out = FALSE;
        }
      }

      if (guard4 == TRUE) {
        CV_EML_MCDC(1, 0, 0, TRUE);
        CV_EML_IF(1, 0, 0, TRUE);
        c3_out = TRUE;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_out) {
        if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 1;
          _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_o_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          c3_b_out = (*c3_theta_dot > 12.5);
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_b_out) {
            transitionList[numTransitions] = 5;
            numTransitions++;
          }

          _SFD_TRANSITION_CONFLICT_CHECK_END();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *c3_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *c3_sfEvent);
        *c3_is_c3_plant_block_swing_catch = c3_IN_Swing;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *c3_x = 0.0;
        c3_updateDataWrittenToVector(chartInstance, 0U);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
        sf_mex_printf("%s =\\n", "x");
        c3_e_hoistedGlobal = *c3_x;
        c3_c_u = c3_e_hoistedGlobal;
        c3_c_y = NULL;
        sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0),
                      FALSE);
        sf_mex_call_debug("disp", 0U, 1U, 14, c3_c_y);
        *c3_r_y = 1.0;
        c3_updateDataWrittenToVector(chartInstance, 1U);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
        sf_mex_printf("%s =\\n", "y");
        c3_f_hoistedGlobal = *c3_r_y;
        c3_d_u = c3_f_hoistedGlobal;
        c3_d_y = NULL;
        sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0),
                      FALSE);
        sf_mex_call_debug("disp", 0U, 1U, 14, c3_d_y);
        *c3_z = 0.0;
        c3_updateDataWrittenToVector(chartInstance, 2U);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 2U);
        sf_mex_printf("%s =\\n", "z");
        c3_g_hoistedGlobal = *c3_z;
        c3_e_u = c3_g_hoistedGlobal;
        c3_e_y = NULL;
        sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_e_u, 0, 0U, 0U, 0U, 0),
                      FALSE);
        sf_mex_call_debug("disp", 0U, 1U, 14, c3_e_y);
        *c3_r = 0.0;
        c3_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, *c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_i_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        c3_c_out = CV_EML_IF(5, 0, 0, *c3_theta_dot > 12.5);
        _SFD_SYMBOL_SCOPE_POP();
        if (c3_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, *c3_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *c3_sfEvent);
          *c3_is_c3_plant_block_swing_catch = c3_IN_ReSwing;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          *c3_x = 1.0;
          c3_updateDataWrittenToVector(chartInstance, 0U);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
          sf_mex_printf("%s =\\n", "x");
          c3_h_hoistedGlobal = *c3_x;
          c3_f_u = c3_h_hoistedGlobal;
          c3_f_y = NULL;
          sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_f_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          sf_mex_call_debug("disp", 0U, 1U, 14, c3_f_y);
          *c3_r_y = 0.0;
          c3_updateDataWrittenToVector(chartInstance, 1U);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
          sf_mex_printf("%s =\\n", "y");
          c3_i_hoistedGlobal = *c3_r_y;
          c3_g_u = c3_i_hoistedGlobal;
          c3_g_y = NULL;
          sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_g_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          sf_mex_call_debug("disp", 0U, 1U, 14, c3_g_y);
          *c3_z = 0.0;
          c3_updateDataWrittenToVector(chartInstance, 2U);
          *c3_r = 1.0;
          c3_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, *c3_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c3_sfEvent);
      break;

     case c3_IN_ReSwing:
      CV_CHART_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, *c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_j_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      c3_d_out = CV_EML_IF(6, 0, 0, *c3_theta_dot < 6.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c3_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, *c3_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *c3_sfEvent);
        *c3_is_c3_plant_block_swing_catch = c3_IN_Swing;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *c3_x = 0.0;
        c3_updateDataWrittenToVector(chartInstance, 0U);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
        sf_mex_printf("%s =\\n", "x");
        c3_j_hoistedGlobal = *c3_x;
        c3_h_u = c3_j_hoistedGlobal;
        c3_h_y = NULL;
        sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_h_u, 0, 0U, 0U, 0U, 0),
                      FALSE);
        sf_mex_call_debug("disp", 0U, 1U, 14, c3_h_y);
        *c3_r_y = 1.0;
        c3_updateDataWrittenToVector(chartInstance, 1U);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
        sf_mex_printf("%s =\\n", "y");
        c3_k_hoistedGlobal = *c3_r_y;
        c3_i_u = c3_k_hoistedGlobal;
        c3_i_y = NULL;
        sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_i_u, 0, 0U, 0U, 0U, 0),
                      FALSE);
        sf_mex_call_debug("disp", 0U, 1U, 14, c3_i_y);
        *c3_z = 0.0;
        c3_updateDataWrittenToVector(chartInstance, 2U);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 2U);
        sf_mex_printf("%s =\\n", "z");
        c3_l_hoistedGlobal = *c3_z;
        c3_j_u = c3_l_hoistedGlobal;
        c3_j_y = NULL;
        sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_j_u, 0, 0U, 0U, 0U, 0),
                      FALSE);
        sf_mex_call_debug("disp", 0U, 1U, 14, c3_j_y);
        *c3_r = 0.0;
        c3_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, *c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *c3_sfEvent);
      break;

     case c3_IN_Rest:
      CV_CHART_EVAL(0, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, *c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_e_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard3 = FALSE;
      if (CV_EML_COND(4, 0, 0, *c3_theta > 0.12)) {
        if (CV_EML_COND(4, 0, 1, *c3_theta_dot > 0.12)) {
          CV_EML_MCDC(4, 0, 0, TRUE);
          CV_EML_IF(4, 0, 0, TRUE);
          c3_e_out = TRUE;
        } else {
          guard3 = TRUE;
        }
      } else {
        guard3 = TRUE;
      }

      if (guard3 == TRUE) {
        CV_EML_MCDC(4, 0, 0, FALSE);
        CV_EML_IF(4, 0, 0, FALSE);
        c3_e_out = FALSE;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, *c3_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *c3_sfEvent);
        *c3_is_c3_plant_block_swing_catch = c3_IN_Swing;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *c3_x = 0.0;
        c3_updateDataWrittenToVector(chartInstance, 0U);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
        sf_mex_printf("%s =\\n", "x");
        c3_m_hoistedGlobal = *c3_x;
        c3_k_u = c3_m_hoistedGlobal;
        c3_k_y = NULL;
        sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_k_u, 0, 0U, 0U, 0U, 0),
                      FALSE);
        sf_mex_call_debug("disp", 0U, 1U, 14, c3_k_y);
        *c3_r_y = 1.0;
        c3_updateDataWrittenToVector(chartInstance, 1U);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
        sf_mex_printf("%s =\\n", "y");
        c3_n_hoistedGlobal = *c3_r_y;
        c3_l_u = c3_n_hoistedGlobal;
        c3_l_y = NULL;
        sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_l_u, 0, 0U, 0U, 0U, 0),
                      FALSE);
        sf_mex_call_debug("disp", 0U, 1U, 14, c3_l_y);
        *c3_z = 0.0;
        c3_updateDataWrittenToVector(chartInstance, 2U);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 2U, 2U);
        sf_mex_printf("%s =\\n", "z");
        c3_o_hoistedGlobal = *c3_z;
        c3_m_u = c3_o_hoistedGlobal;
        c3_m_y = NULL;
        sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_m_u, 0, 0U, 0U, 0U, 0),
                      FALSE);
        sf_mex_call_debug("disp", 0U, 1U, 14, c3_m_y);
        *c3_r = 0.0;
        c3_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U, *c3_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *c3_sfEvent);
      break;

     case c3_IN_Swing:
      CV_CHART_EVAL(0, 0, 4);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, *c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_g_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_k_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      guard2 = FALSE;
      if (CV_EML_COND(2, 0, 0, 2.7475 < *c3_theta)) {
        c3_p_hoistedGlobal = *c3_theta;
        if (CV_EML_COND(2, 0, 1, c3_p_hoistedGlobal < 3.5325)) {
          CV_EML_MCDC(2, 0, 0, TRUE);
          CV_EML_IF(2, 0, 0, TRUE);
          c3_f_out = TRUE;
        } else {
          guard2 = TRUE;
        }
      } else {
        guard2 = TRUE;
      }

      if (guard2 == TRUE) {
        CV_EML_MCDC(2, 0, 0, FALSE);
        CV_EML_IF(2, 0, 0, FALSE);
        c3_f_out = FALSE;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_f_out) {
        if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 2;
          _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_l_debug_family_names,
            c3_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_l_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_out, 2U,
            c3_b_sf_marshallOut, c3_b_sf_marshallIn);
          c3_b0 = (*c3_theta < 0.12);
          c3_b1 = (*c3_theta_dot < 0.12);
          c3_g_out = (c3_b0 && c3_b1);
          _SFD_SYMBOL_SCOPE_POP();
          if (c3_g_out) {
            transitionList[numTransitions] = 3;
            numTransitions++;
          }

          _SFD_TRANSITION_CONFLICT_CHECK_END();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *c3_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *c3_sfEvent);
        *c3_is_c3_plant_block_swing_catch = c3_IN_Catch;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
          c3_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_m_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *c3_x = 0.0;
        c3_updateDataWrittenToVector(chartInstance, 0U);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
        sf_mex_printf("%s =\\n", "x");
        c3_q_hoistedGlobal = *c3_x;
        c3_n_u = c3_q_hoistedGlobal;
        c3_n_y = NULL;
        sf_mex_assign(&c3_n_y, sf_mex_create("y", &c3_n_u, 0, 0U, 0U, 0U, 0),
                      FALSE);
        sf_mex_call_debug("disp", 0U, 1U, 14, c3_n_y);
        *c3_r_y = 0.0;
        c3_updateDataWrittenToVector(chartInstance, 1U);
        c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
        sf_mex_printf("%s =\\n", "y");
        c3_r_hoistedGlobal = *c3_r_y;
        c3_o_u = c3_r_hoistedGlobal;
        c3_o_y = NULL;
        sf_mex_assign(&c3_o_y, sf_mex_create("y", &c3_o_u, 0, 0U, 0U, 0U, 0),
                      FALSE);
        sf_mex_call_debug("disp", 0U, 1U, 14, c3_o_y);
        *c3_z = 1.0;
        c3_updateDataWrittenToVector(chartInstance, 2U);
        *c3_r = 0.0;
        c3_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, *c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_f_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_n_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_out, 2U, c3_b_sf_marshallOut,
          c3_b_sf_marshallIn);
        guard1 = FALSE;
        if (CV_EML_COND(3, 0, 0, *c3_theta < 0.12)) {
          if (CV_EML_COND(3, 0, 1, *c3_theta_dot < 0.12)) {
            CV_EML_MCDC(3, 0, 0, TRUE);
            CV_EML_IF(3, 0, 0, TRUE);
            c3_h_out = TRUE;
          } else {
            guard1 = TRUE;
          }
        } else {
          guard1 = TRUE;
        }

        if (guard1 == TRUE) {
          CV_EML_MCDC(3, 0, 0, FALSE);
          CV_EML_IF(3, 0, 0, FALSE);
          c3_h_out = FALSE;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c3_h_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, *c3_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *c3_sfEvent);
          *c3_is_c3_plant_block_swing_catch = c3_IN_Rest;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *c3_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
            c3_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_o_nargin, 0U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_o_nargout, 1U,
            c3_sf_marshallOut, c3_sf_marshallIn);
          *c3_x = 1.0;
          c3_updateDataWrittenToVector(chartInstance, 0U);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
          sf_mex_printf("%s =\\n", "x");
          c3_s_hoistedGlobal = *c3_x;
          c3_p_u = c3_s_hoistedGlobal;
          c3_p_y = NULL;
          sf_mex_assign(&c3_p_y, sf_mex_create("y", &c3_p_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          sf_mex_call_debug("disp", 0U, 1U, 14, c3_p_y);
          *c3_r_y = 0.0;
          c3_updateDataWrittenToVector(chartInstance, 1U);
          c3_errorIfDataNotWrittenToFcn(chartInstance, 1U, 1U);
          sf_mex_printf("%s =\\n", "y");
          c3_t_hoistedGlobal = *c3_r_y;
          c3_q_u = c3_t_hoistedGlobal;
          c3_q_y = NULL;
          sf_mex_assign(&c3_q_y, sf_mex_create("y", &c3_q_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          sf_mex_call_debug("disp", 0U, 1U, 14, c3_q_y);
          *c3_z = 0.0;
          c3_updateDataWrittenToVector(chartInstance, 2U);
          *c3_r = 0.0;
          c3_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, *c3_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *c3_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);
      *c3_is_c3_plant_block_swing_catch = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *c3_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c3_sfEvent);
}

static void initSimStructsc3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance)
{
}

static void registerMessagesc3_plant_block_swing_catch
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_plant_block_swing_catchInstanceStruct *chartInstance;
  chartInstance = (SFc3_plant_block_swing_catchInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_plant_block_swing_catchInstanceStruct
  *chartInstance, const mxArray *c3_nargout, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_plant_block_swing_catchInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_plant_block_swing_catchInstanceStruct *chartInstance;
  chartInstance = (SFc3_plant_block_swing_catchInstanceStruct *)
    chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_plant_block_swing_catchInstanceStruct *chartInstance;
  chartInstance = (SFc3_plant_block_swing_catchInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static boolean_T c3_c_emlrt_marshallIn
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b2;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b2, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b2;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_evilsf_internal_predicateOutput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_plant_block_swing_catchInstanceStruct *chartInstance;
  chartInstance = (SFc3_plant_block_swing_catchInstanceStruct *)
    chartInstanceVoid;
  c3_evilsf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_evilsf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_evilsf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_plant_block_swing_catch_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[4];
  c3_ResolvedFunctionInfo (*c3_b_info)[4];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i0;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_b_info = (c3_ResolvedFunctionInfo (*)[4])c3_info;
  (*c3_b_info)[0].context = "";
  (*c3_b_info)[0].name = "mrdivide";
  (*c3_b_info)[0].dominantType = "double";
  (*c3_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c3_b_info)[0].fileTimeLo = 1357919148U;
  (*c3_b_info)[0].fileTimeHi = 0U;
  (*c3_b_info)[0].mFileTimeLo = 1319701166U;
  (*c3_b_info)[0].mFileTimeHi = 0U;
  (*c3_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c3_b_info)[1].name = "rdivide";
  (*c3_b_info)[1].dominantType = "double";
  (*c3_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c3_b_info)[1].fileTimeLo = 1346481588U;
  (*c3_b_info)[1].fileTimeHi = 0U;
  (*c3_b_info)[1].mFileTimeLo = 0U;
  (*c3_b_info)[1].mFileTimeHi = 0U;
  (*c3_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c3_b_info)[2].name = "eml_scalexp_compatible";
  (*c3_b_info)[2].dominantType = "double";
  (*c3_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c3_b_info)[2].fileTimeLo = 1286789996U;
  (*c3_b_info)[2].fileTimeHi = 0U;
  (*c3_b_info)[2].mFileTimeLo = 0U;
  (*c3_b_info)[2].mFileTimeHi = 0U;
  (*c3_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c3_b_info)[3].name = "eml_div";
  (*c3_b_info)[3].dominantType = "double";
  (*c3_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c3_b_info)[3].fileTimeLo = 1313319010U;
  (*c3_b_info)[3].fileTimeHi = 0U;
  (*c3_b_info)[3].mFileTimeLo = 0U;
  (*c3_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4), FALSE);
  for (c3_i0 = 0; c3_i0 < 4; c3_i0++) {
    c3_r0 = &c3_info[c3_i0];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i0);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_plant_block_swing_catchInstanceStruct *chartInstance;
  chartInstance = (SFc3_plant_block_swing_catchInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn(SFc3_plant_block_swing_catchInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i1;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i1, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_plant_block_swing_catchInstanceStruct *chartInstance;
  chartInstance = (SFc3_plant_block_swing_catchInstanceStruct *)
    chartInstanceVoid;
  c3_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sfEvent), &c3_thisId);
  sf_mex_destroy(&c3_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_plant_block_swing_catchInstanceStruct *
  chartInstance, const mxArray *c3_is_active_c3_plant_block_swing_catch, const
  char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_is_active_c3_plant_block_swing_catch), &c3_thisId);
  sf_mex_destroy(&c3_is_active_c3_plant_block_swing_catch);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_plant_block_swing_catchInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static const mxArray *c3_g_emlrt_marshallIn
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  sf_mex_assign(&c3_y, c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), FALSE);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_h_emlrt_marshallIn
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), FALSE);
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_updateDataWrittenToVector
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance, uint32_T
   c3_vectorIndex)
{
  c3_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c3_vectorIndex, 0, 3, 1, 0)] = TRUE;
}

static void c3_errorIfDataNotWrittenToFcn
  (SFc3_plant_block_swing_catchInstanceStruct *chartInstance, uint32_T
   c3_vectorIndex, uint32_T c3_dataNumber)
{
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c3_dataNumber, c3_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c3_vectorIndex, 0, 3, 1,
    0)]);
}

static void init_dsm_address_info(SFc3_plant_block_swing_catchInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c3_plant_block_swing_catch_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2376365713U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(555196044U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3467334822U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3072929574U);
}

mxArray *sf_c3_plant_block_swing_catch_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("wbwDF0lKL5EqTEXtqdtPu");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_plant_block_swing_catch_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c3_plant_block_swing_catch(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[36],T\"r\",},{M[1],M[27],T\"x\",},{M[1],M[30],T\"y\",},{M[1],M[28],T\"z\",},{M[8],M[0],T\"is_active_c3_plant_block_swing_catch\",},{M[9],M[0],T\"is_c3_plant_block_swing_catch\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_plant_block_swing_catch_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_plant_block_swing_catchInstanceStruct *chartInstance;
    chartInstance = (SFc3_plant_block_swing_catchInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _plant_block_swing_catchMachineNumber_,
           3,
           4,
           7,
           6,
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
          init_script_number_translation(_plant_block_swing_catchMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_plant_block_swing_catchMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _plant_block_swing_catchMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"x");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,2,0,1,"z");
          _SFD_SET_DATA_PROPS(3,1,1,0,"theta");
          _SFD_SET_DATA_PROPS(4,1,1,0,"theta_dot");
          _SFD_SET_DATA_PROPS(5,2,0,1,"r");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_CH_SUBSTATE_COUNT(4);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
        }

        _SFD_CV_INIT_CHART(4,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(4,0,0,1,32,1,32);

        {
          static int condStart[] = { 1, 16 };

          static int condEnd[] = { 13, 32 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(4,0,0,1,32,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,32,1,32);

        {
          static int condStart[] = { 1, 16 };

          static int condEnd[] = { 13, 32 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,32,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,54,1,52);

        {
          static int condStart[] = { 1, 29 };

          static int condEnd[] = { 26, 54 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,54,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,54,1,52);

        {
          static int condStart[] = { 1, 29 };

          static int condEnd[] = { 26, 54 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,54,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,14,1,14);
        _SFD_TRANS_COV_WTS(0,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(4,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(4,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(3,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(3,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(1,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(5,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(5,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(6,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(6,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          real_T *c3_x;
          real_T *c3_y;
          real_T *c3_z;
          real_T *c3_theta;
          real_T *c3_theta_dot;
          real_T *c3_r;
          c3_r = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c3_theta_dot = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_theta = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c3_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c3_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_z);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_theta);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_theta_dot);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_r);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _plant_block_swing_catchMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "XhupTozdGcc8TRrNUbJAVF";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_plant_block_swing_catch_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 3, "dworkChecksum");
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

static void sf_opaque_initialize_c3_plant_block_swing_catch(void
  *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc3_plant_block_swing_catchInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc3_plant_block_swing_catchInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_plant_block_swing_catch
    ((SFc3_plant_block_swing_catchInstanceStruct*) chartInstanceVar);
  initialize_c3_plant_block_swing_catch
    ((SFc3_plant_block_swing_catchInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_plant_block_swing_catch(void *chartInstanceVar)
{
  enable_c3_plant_block_swing_catch((SFc3_plant_block_swing_catchInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_plant_block_swing_catch(void *chartInstanceVar)
{
  disable_c3_plant_block_swing_catch((SFc3_plant_block_swing_catchInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_plant_block_swing_catch(void *chartInstanceVar)
{
  sf_c3_plant_block_swing_catch((SFc3_plant_block_swing_catchInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c3_plant_block_swing_catch(void
  *chartInstanceVar)
{
  ext_mode_exec_c3_plant_block_swing_catch
    ((SFc3_plant_block_swing_catchInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_plant_block_swing_catch
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_plant_block_swing_catch
    ((SFc3_plant_block_swing_catchInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_plant_block_swing_catch();/* state var info */
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

extern void sf_internal_set_sim_state_c3_plant_block_swing_catch(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_plant_block_swing_catch();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_plant_block_swing_catch
    ((SFc3_plant_block_swing_catchInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_plant_block_swing_catch
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c3_plant_block_swing_catch(S);
}

static void sf_opaque_set_sim_state_c3_plant_block_swing_catch(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c3_plant_block_swing_catch(S, st);
}

static void sf_opaque_terminate_c3_plant_block_swing_catch(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_plant_block_swing_catchInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_plant_block_swing_catch_optimization_info();
    }

    finalize_c3_plant_block_swing_catch
      ((SFc3_plant_block_swing_catchInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_plant_block_swing_catch
    ((SFc3_plant_block_swing_catchInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_plant_block_swing_catch(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_plant_block_swing_catch
      ((SFc3_plant_block_swing_catchInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c3_plant_block_swing_catch_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S1x2'varName','path'{{T\"is_active_c3_plant_block_swing_catch\",T\"is_active_c3_plant_block_swing_catch\"},{T\"is_c3_plant_block_swing_catch\",T\"is_c3_plant_block_swing_catch\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x4'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size'{{T\"int32\",,,,,,,M[0],M[]},{T\"boolean\",,,,,,,M[0],M[]},{T\"uint8\",,,,,,,M[0],M[]},{T\"uint8\",,,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 4, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 4216956281U, 1510948965U, 1302673614U,
    623905539U };

  return checksum;
}

static void mdlSetWorkWidths_c3_plant_block_swing_catch(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_plant_block_swing_catch_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(270908627U));
  ssSetChecksum1(S,(2614416771U));
  ssSetChecksum2(S,(485058854U));
  ssSetChecksum3(S,(1121221516U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_plant_block_swing_catch(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_plant_block_swing_catch(SimStruct *S)
{
  SFc3_plant_block_swing_catchInstanceStruct *chartInstance;
  chartInstance = (SFc3_plant_block_swing_catchInstanceStruct *)utMalloc(sizeof
    (SFc3_plant_block_swing_catchInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_plant_block_swing_catchInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_plant_block_swing_catch;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_plant_block_swing_catch;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_plant_block_swing_catch;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_plant_block_swing_catch;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_plant_block_swing_catch;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_plant_block_swing_catch;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_plant_block_swing_catch;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_plant_block_swing_catch;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_plant_block_swing_catch;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_plant_block_swing_catch;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_plant_block_swing_catch;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c3_plant_block_swing_catch;
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

void c3_plant_block_swing_catch_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_plant_block_swing_catch(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_plant_block_swing_catch(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_plant_block_swing_catch(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_plant_block_swing_catch_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
