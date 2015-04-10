/* Include files */

#include <stddef.h>
#include "blas.h"
#include "nid_thesis_sfun.h"
#include "c2_nid_thesis.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "nid_thesis_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[15] = { "nargin", "nargout", "u",
  "Head_x", "Head_y", "Head_z", "RShld_x", "RShld_y", "RShld_z", "RElbw_x",
  "RElbw_y", "RElbw_z", "RWrst_x", "RWrst_y", "RWrst_z" };

/* Function Declarations */
static void initialize_c2_nid_thesis(SFc2_nid_thesisInstanceStruct
  *chartInstance);
static void initialize_params_c2_nid_thesis(SFc2_nid_thesisInstanceStruct
  *chartInstance);
static void enable_c2_nid_thesis(SFc2_nid_thesisInstanceStruct *chartInstance);
static void disable_c2_nid_thesis(SFc2_nid_thesisInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_nid_thesis(SFc2_nid_thesisInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_nid_thesis(SFc2_nid_thesisInstanceStruct *
  chartInstance);
static void set_sim_state_c2_nid_thesis(SFc2_nid_thesisInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_nid_thesis(SFc2_nid_thesisInstanceStruct *chartInstance);
static void sf_c2_nid_thesis(SFc2_nid_thesisInstanceStruct *chartInstance);
static void initSimStructsc2_nid_thesis(SFc2_nid_thesisInstanceStruct
  *chartInstance);
static void registerMessagesc2_nid_thesis(SFc2_nid_thesisInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_nid_thesisInstanceStruct *chartInstance,
  const mxArray *c2_RWrst_z, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_nid_thesisInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn(SFc2_nid_thesisInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn(SFc2_nid_thesisInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_nid_thesis, const char_T
  *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn(SFc2_nid_thesisInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_nid_thesisInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_nid_thesis(SFc2_nid_thesisInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_nid_thesis = 0U;
}

static void initialize_params_c2_nid_thesis(SFc2_nid_thesisInstanceStruct
  *chartInstance)
{
}

static void enable_c2_nid_thesis(SFc2_nid_thesisInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_nid_thesis(SFc2_nid_thesisInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_nid_thesis(SFc2_nid_thesisInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_nid_thesis(SFc2_nid_thesisInstanceStruct *
  chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_d_hoistedGlobal;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_e_hoistedGlobal;
  real_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_f_hoistedGlobal;
  real_T c2_f_u;
  const mxArray *c2_g_y = NULL;
  real_T c2_g_hoistedGlobal;
  real_T c2_g_u;
  const mxArray *c2_h_y = NULL;
  real_T c2_h_hoistedGlobal;
  real_T c2_h_u;
  const mxArray *c2_i_y = NULL;
  real_T c2_i_hoistedGlobal;
  real_T c2_i_u;
  const mxArray *c2_j_y = NULL;
  real_T c2_j_hoistedGlobal;
  real_T c2_j_u;
  const mxArray *c2_k_y = NULL;
  real_T c2_k_hoistedGlobal;
  real_T c2_k_u;
  const mxArray *c2_l_y = NULL;
  real_T c2_l_hoistedGlobal;
  real_T c2_l_u;
  const mxArray *c2_m_y = NULL;
  uint8_T c2_m_hoistedGlobal;
  uint8_T c2_m_u;
  const mxArray *c2_n_y = NULL;
  real_T *c2_Head_x;
  real_T *c2_Head_y;
  real_T *c2_Head_z;
  real_T *c2_RElbw_x;
  real_T *c2_RElbw_y;
  real_T *c2_RElbw_z;
  real_T *c2_RShld_x;
  real_T *c2_RShld_y;
  real_T *c2_RShld_z;
  real_T *c2_RWrst_x;
  real_T *c2_RWrst_y;
  real_T *c2_RWrst_z;
  c2_RWrst_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c2_RWrst_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c2_RWrst_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c2_RElbw_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_RElbw_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_RElbw_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_RShld_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_RShld_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_RShld_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_Head_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_Head_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_Head_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(13), FALSE);
  c2_hoistedGlobal = *c2_Head_x;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_Head_y;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *c2_Head_z;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = *c2_RElbw_x;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = *c2_RElbw_y;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  c2_f_hoistedGlobal = *c2_RElbw_z;
  c2_f_u = c2_f_hoistedGlobal;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  c2_g_hoistedGlobal = *c2_RShld_x;
  c2_g_u = c2_g_hoistedGlobal;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 6, c2_h_y);
  c2_h_hoistedGlobal = *c2_RShld_y;
  c2_h_u = c2_h_hoistedGlobal;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 7, c2_i_y);
  c2_i_hoistedGlobal = *c2_RShld_z;
  c2_i_u = c2_i_hoistedGlobal;
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 8, c2_j_y);
  c2_j_hoistedGlobal = *c2_RWrst_x;
  c2_j_u = c2_j_hoistedGlobal;
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_j_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 9, c2_k_y);
  c2_k_hoistedGlobal = *c2_RWrst_y;
  c2_k_u = c2_k_hoistedGlobal;
  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_k_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 10, c2_l_y);
  c2_l_hoistedGlobal = *c2_RWrst_z;
  c2_l_u = c2_l_hoistedGlobal;
  c2_m_y = NULL;
  sf_mex_assign(&c2_m_y, sf_mex_create("y", &c2_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 11, c2_m_y);
  c2_m_hoistedGlobal = chartInstance->c2_is_active_c2_nid_thesis;
  c2_m_u = c2_m_hoistedGlobal;
  c2_n_y = NULL;
  sf_mex_assign(&c2_n_y, sf_mex_create("y", &c2_m_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 12, c2_n_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_nid_thesis(SFc2_nid_thesisInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_Head_x;
  real_T *c2_Head_y;
  real_T *c2_Head_z;
  real_T *c2_RElbw_x;
  real_T *c2_RElbw_y;
  real_T *c2_RElbw_z;
  real_T *c2_RShld_x;
  real_T *c2_RShld_y;
  real_T *c2_RShld_z;
  real_T *c2_RWrst_x;
  real_T *c2_RWrst_y;
  real_T *c2_RWrst_z;
  c2_RWrst_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c2_RWrst_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c2_RWrst_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c2_RElbw_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_RElbw_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_RElbw_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_RShld_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_RShld_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_RShld_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_Head_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_Head_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_Head_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_Head_x = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    0)), "Head_x");
  *c2_Head_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    1)), "Head_y");
  *c2_Head_z = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    2)), "Head_z");
  *c2_RElbw_x = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 3)), "RElbw_x");
  *c2_RElbw_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 4)), "RElbw_y");
  *c2_RElbw_z = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 5)), "RElbw_z");
  *c2_RShld_x = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 6)), "RShld_x");
  *c2_RShld_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 7)), "RShld_y");
  *c2_RShld_z = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 8)), "RShld_z");
  *c2_RWrst_x = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 9)), "RWrst_x");
  *c2_RWrst_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 10)), "RWrst_y");
  *c2_RWrst_z = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 11)), "RWrst_z");
  chartInstance->c2_is_active_c2_nid_thesis = c2_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 12)),
     "is_active_c2_nid_thesis");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_nid_thesis(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_nid_thesis(SFc2_nid_thesisInstanceStruct *chartInstance)
{
}

static void sf_c2_nid_thesis(SFc2_nid_thesisInstanceStruct *chartInstance)
{
  int32_T c2_i0;
  int32_T c2_i1;
  real_T c2_u[60];
  uint32_T c2_debug_family_var_map[15];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 12.0;
  real_T c2_Head_x;
  real_T c2_Head_y;
  real_T c2_Head_z;
  real_T c2_RShld_x;
  real_T c2_RShld_y;
  real_T c2_RShld_z;
  real_T c2_RElbw_x;
  real_T c2_RElbw_y;
  real_T c2_RElbw_z;
  real_T c2_RWrst_x;
  real_T c2_RWrst_y;
  real_T c2_RWrst_z;
  real_T *c2_b_Head_x;
  real_T *c2_b_Head_y;
  real_T *c2_b_Head_z;
  real_T *c2_b_RShld_x;
  real_T *c2_b_RShld_y;
  real_T *c2_b_RShld_z;
  real_T *c2_b_RElbw_x;
  real_T *c2_b_RElbw_y;
  real_T *c2_b_RElbw_z;
  real_T *c2_b_RWrst_x;
  real_T *c2_b_RWrst_y;
  real_T *c2_b_RWrst_z;
  real_T (*c2_b_u)[60];
  c2_b_RWrst_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c2_b_RWrst_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c2_b_RWrst_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c2_b_RElbw_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_b_RElbw_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_b_RElbw_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c2_b_RShld_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c2_b_RShld_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c2_b_RShld_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_b_Head_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_Head_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_u = (real_T (*)[60])ssGetInputPortSignal(chartInstance->S, 0);
  c2_b_Head_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_b_Head_x, 0U);
  for (c2_i0 = 0; c2_i0 < 60; c2_i0++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_u)[c2_i0], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_b_Head_y, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_b_Head_z, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_b_RShld_x, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_b_RShld_y, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_b_RShld_z, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_b_RElbw_x, 7U);
  _SFD_DATA_RANGE_CHECK(*c2_b_RElbw_y, 8U);
  _SFD_DATA_RANGE_CHECK(*c2_b_RElbw_z, 9U);
  _SFD_DATA_RANGE_CHECK(*c2_b_RWrst_x, 10U);
  _SFD_DATA_RANGE_CHECK(*c2_b_RWrst_y, 11U);
  _SFD_DATA_RANGE_CHECK(*c2_b_RWrst_z, 12U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i1 = 0; c2_i1 < 60; c2_i1++) {
    c2_u[c2_i1] = (*c2_b_u)[c2_i1];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_u, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Head_x, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Head_y, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Head_z, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_RShld_x, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_RShld_y, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_RShld_z, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_RElbw_x, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_RElbw_y, 10U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_RElbw_z, 11U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_RWrst_x, 12U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_RWrst_y, 13U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_RWrst_z, 14U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  c2_Head_x = c2_u[3];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
  c2_Head_y = c2_u[23];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
  c2_Head_z = c2_u[43];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  c2_RShld_x = c2_u[8];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
  c2_RShld_y = c2_u[28];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
  c2_RShld_z = c2_u[48];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
  c2_RElbw_x = c2_u[9];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
  c2_RElbw_y = c2_u[29];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
  c2_RElbw_z = c2_u[49];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
  c2_RWrst_x = c2_u[10];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_RWrst_y = c2_u[30];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
  c2_RWrst_z = c2_u[50];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -33);
  _SFD_SYMBOL_SCOPE_POP();
  *c2_b_Head_x = c2_Head_x;
  *c2_b_Head_y = c2_Head_y;
  *c2_b_Head_z = c2_Head_z;
  *c2_b_RShld_x = c2_RShld_x;
  *c2_b_RShld_y = c2_RShld_y;
  *c2_b_RShld_z = c2_RShld_z;
  *c2_b_RElbw_x = c2_RElbw_x;
  *c2_b_RElbw_y = c2_RElbw_y;
  *c2_b_RElbw_z = c2_RElbw_z;
  *c2_b_RWrst_x = c2_RWrst_x;
  *c2_b_RWrst_y = c2_RWrst_y;
  *c2_b_RWrst_z = c2_RWrst_z;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_nid_thesisMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_nid_thesis(SFc2_nid_thesisInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc2_nid_thesis(SFc2_nid_thesisInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_nid_thesisInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_thesisInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_nid_thesisInstanceStruct *chartInstance,
  const mxArray *c2_RWrst_z, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_RWrst_z), &c2_thisId);
  sf_mex_destroy(&c2_RWrst_z);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_nid_thesisInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_RWrst_z;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_nid_thesisInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_thesisInstanceStruct *)chartInstanceVoid;
  c2_RWrst_z = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_RWrst_z), &c2_thisId);
  sf_mex_destroy(&c2_RWrst_z);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  real_T c2_b_inData[60];
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  real_T c2_u[60];
  const mxArray *c2_y = NULL;
  SFc2_nid_thesisInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_thesisInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i2 = 0;
  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    for (c2_i4 = 0; c2_i4 < 20; c2_i4++) {
      c2_b_inData[c2_i4 + c2_i2] = (*(real_T (*)[60])c2_inData)[c2_i4 + c2_i2];
    }

    c2_i2 += 20;
  }

  c2_i5 = 0;
  for (c2_i6 = 0; c2_i6 < 3; c2_i6++) {
    for (c2_i7 = 0; c2_i7 < 20; c2_i7++) {
      c2_u[c2_i7 + c2_i5] = c2_b_inData[c2_i7 + c2_i5];
    }

    c2_i5 += 20;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 3, 1, 20, 3),
                FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_nid_thesis_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_nid_thesisInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_thesisInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn(SFc2_nid_thesisInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i8;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i8, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i8;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_nid_thesisInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_thesisInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_nid_thesisInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_nid_thesis, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_nid_thesis), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_nid_thesis);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_nid_thesisInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_nid_thesisInstanceStruct *chartInstance)
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

void sf_c2_nid_thesis_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2436472252U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2936727831U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3564603502U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3760652766U);
}

mxArray *sf_c2_nid_thesis_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("rNeoFONQCZqvqdSev2uyeB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(20);
      pr[2] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,12,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_nid_thesis_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_nid_thesis(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[6],T\"Head_x\",},{M[1],M[5],T\"Head_y\",},{M[1],M[7],T\"Head_z\",},{M[1],M[11],T\"RElbw_x\",},{M[1],M[12],T\"RElbw_y\",},{M[1],M[13],T\"RElbw_z\",},{M[1],M[8],T\"RShld_x\",},{M[1],M[9],T\"RShld_y\",},{M[1],M[10],T\"RShld_z\",},{M[1],M[14],T\"RWrst_x\",}}",
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[15],T\"RWrst_y\",},{M[1],M[16],T\"RWrst_z\",},{M[8],M[0],T\"is_active_c2_nid_thesis\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 13, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_nid_thesis_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_nid_thesisInstanceStruct *chartInstance;
    chartInstance = (SFc2_nid_thesisInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _nid_thesisMachineNumber_,
           2,
           1,
           1,
           13,
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
          init_script_number_translation(_nid_thesisMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_nid_thesisMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _nid_thesisMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"Head_x");
          _SFD_SET_DATA_PROPS(1,1,1,0,"u");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Head_y");
          _SFD_SET_DATA_PROPS(3,2,0,1,"Head_z");
          _SFD_SET_DATA_PROPS(4,2,0,1,"RShld_x");
          _SFD_SET_DATA_PROPS(5,2,0,1,"RShld_y");
          _SFD_SET_DATA_PROPS(6,2,0,1,"RShld_z");
          _SFD_SET_DATA_PROPS(7,2,0,1,"RElbw_x");
          _SFD_SET_DATA_PROPS(8,2,0,1,"RElbw_y");
          _SFD_SET_DATA_PROPS(9,2,0,1,"RElbw_z");
          _SFD_SET_DATA_PROPS(10,2,0,1,"RWrst_x");
          _SFD_SET_DATA_PROPS(11,2,0,1,"RWrst_y");
          _SFD_SET_DATA_PROPS(12,2,0,1,"RWrst_z");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,640);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          unsigned int dimVector[3];
          dimVector[0]= 1;
          dimVector[1]= 20;
          dimVector[2]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          real_T *c2_Head_x;
          real_T *c2_Head_y;
          real_T *c2_Head_z;
          real_T *c2_RShld_x;
          real_T *c2_RShld_y;
          real_T *c2_RShld_z;
          real_T *c2_RElbw_x;
          real_T *c2_RElbw_y;
          real_T *c2_RElbw_z;
          real_T *c2_RWrst_x;
          real_T *c2_RWrst_y;
          real_T *c2_RWrst_z;
          real_T (*c2_u)[60];
          c2_RWrst_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 12);
          c2_RWrst_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 11);
          c2_RWrst_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 10);
          c2_RElbw_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
          c2_RElbw_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c2_RElbw_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c2_RShld_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c2_RShld_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c2_RShld_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c2_Head_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_Head_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_u = (real_T (*)[60])ssGetInputPortSignal(chartInstance->S, 0);
          c2_Head_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_Head_x);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_u);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_Head_y);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_Head_z);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_RShld_x);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_RShld_y);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_RShld_z);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_RElbw_x);
          _SFD_SET_DATA_VALUE_PTR(8U, c2_RElbw_y);
          _SFD_SET_DATA_VALUE_PTR(9U, c2_RElbw_z);
          _SFD_SET_DATA_VALUE_PTR(10U, c2_RWrst_x);
          _SFD_SET_DATA_VALUE_PTR(11U, c2_RWrst_y);
          _SFD_SET_DATA_VALUE_PTR(12U, c2_RWrst_z);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _nid_thesisMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "8BbNvsO0fIqCUzO3siz4DB";
}

static void sf_opaque_initialize_c2_nid_thesis(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_nid_thesisInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c2_nid_thesis((SFc2_nid_thesisInstanceStruct*)
    chartInstanceVar);
  initialize_c2_nid_thesis((SFc2_nid_thesisInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_nid_thesis(void *chartInstanceVar)
{
  enable_c2_nid_thesis((SFc2_nid_thesisInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_nid_thesis(void *chartInstanceVar)
{
  disable_c2_nid_thesis((SFc2_nid_thesisInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_nid_thesis(void *chartInstanceVar)
{
  sf_c2_nid_thesis((SFc2_nid_thesisInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_nid_thesis(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_nid_thesis
    ((SFc2_nid_thesisInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_nid_thesis();/* state var info */
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

extern void sf_internal_set_sim_state_c2_nid_thesis(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_nid_thesis();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_nid_thesis((SFc2_nid_thesisInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_nid_thesis(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_nid_thesis(S);
}

static void sf_opaque_set_sim_state_c2_nid_thesis(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_nid_thesis(S, st);
}

static void sf_opaque_terminate_c2_nid_thesis(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_nid_thesisInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_nid_thesis_optimization_info();
    }

    finalize_c2_nid_thesis((SFc2_nid_thesisInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_nid_thesis((SFc2_nid_thesisInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_nid_thesis(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_nid_thesis((SFc2_nid_thesisInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_nid_thesis(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_nid_thesis_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,12);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=12; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3427097759U));
  ssSetChecksum1(S,(263617435U));
  ssSetChecksum2(S,(2396429588U));
  ssSetChecksum3(S,(3492897606U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_nid_thesis(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_nid_thesis(SimStruct *S)
{
  SFc2_nid_thesisInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_thesisInstanceStruct *)utMalloc(sizeof
    (SFc2_nid_thesisInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_nid_thesisInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_nid_thesis;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_nid_thesis;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_nid_thesis;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_nid_thesis;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_nid_thesis;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_nid_thesis;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_nid_thesis;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_nid_thesis;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_nid_thesis;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_nid_thesis;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_nid_thesis;
  chartInstance->chartInfo.extModeExec = NULL;
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

void c2_nid_thesis_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_nid_thesis(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_nid_thesis(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_nid_thesis(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_nid_thesis_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
