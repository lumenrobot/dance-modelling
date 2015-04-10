/* Include files */

#include <stddef.h>
#include "blas.h"
#include "nid_cvst_pattern_tracking_sfun.h"
#include "c2_nid_cvst_pattern_tracking.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "nid_cvst_pattern_tracking_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[18] = { "m", "Ptemp", "Rate", "Th",
  "n", "X", "Y", "a", "b", "nargin", "nargout", "Area", "Centroid", "BBox",
  "Perimeter", "Depth", "CBox", "Centroid2" };

/* Function Declarations */
static void initialize_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void initialize_params_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void enable_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void disable_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void set_sim_state_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void finalize_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void sf_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void c2_chartstep_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void initSimStructsc2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void registerMessagesc2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance, const mxArray *c2_Centroid2, const char_T *c2_identifier,
  real_T c2_y[1000]);
static void c2_b_emlrt_marshallIn(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[1000]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance, const mxArray *c2_CBox, const char_T *c2_identifier, int32_T
  c2_y[2000]);
static void c2_d_emlrt_marshallIn(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  int32_T c2_y[2000]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_e_emlrt_marshallIn(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_f_emlrt_marshallIn(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[500]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[16]);
static real_T c2_power(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance, real_T c2_a);
static void c2_eml_scalar_eg(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance);
static real_T c2_rdivide(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance, real_T c2_x, real_T c2_y);
static real_T c2_sqrt(SFc2_nid_cvst_pattern_trackingInstanceStruct
                      *chartInstance, real_T c2_x);
static void c2_eml_error(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_g_emlrt_marshallIn
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_h_emlrt_marshallIn
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance, const mxArray
   *c2_b_is_active_c2_nid_cvst_pattern_tracking, const char_T *c2_identifier);
static uint8_T c2_i_emlrt_marshallIn
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sqrt(SFc2_nid_cvst_pattern_trackingInstanceStruct
                      *chartInstance, real_T *c2_x);
static void init_dsm_address_info(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_nid_cvst_pattern_tracking = 0U;
}

static void initialize_params_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
}

static void enable_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  int32_T c2_u[2000];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i1;
  real_T c2_b_u[1000];
  const mxArray *c2_c_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T (*c2_Centroid2)[1000];
  int32_T (*c2_CBox)[2000];
  c2_Centroid2 = (real_T (*)[1000])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_CBox = (int32_T (*)[2000])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(3), FALSE);
  for (c2_i0 = 0; c2_i0 < 2000; c2_i0++) {
    c2_u[c2_i0] = (*c2_CBox)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 6, 0U, 1U, 0U, 2, 500, 4),
                FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i1 = 0; c2_i1 < 1000; c2_i1++) {
    c2_b_u[c2_i1] = (*c2_Centroid2)[c2_i1];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 500, 2),
                FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_nid_cvst_pattern_tracking;
  c2_c_u = c2_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_u;
  int32_T c2_iv0[2000];
  int32_T c2_i2;
  real_T c2_dv0[1000];
  int32_T c2_i3;
  int32_T (*c2_CBox)[2000];
  real_T (*c2_Centroid2)[1000];
  c2_Centroid2 = (real_T (*)[1000])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_CBox = (int32_T (*)[2000])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                        "CBox", c2_iv0);
  for (c2_i2 = 0; c2_i2 < 2000; c2_i2++) {
    (*c2_CBox)[c2_i2] = c2_iv0[c2_i2];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
                      "Centroid2", c2_dv0);
  for (c2_i3 = 0; c2_i3 < 1000; c2_i3++) {
    (*c2_Centroid2)[c2_i3] = c2_dv0[c2_i3];
  }

  chartInstance->c2_is_active_c2_nid_cvst_pattern_tracking =
    c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
    "is_active_c2_nid_cvst_pattern_tracking");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_nid_cvst_pattern_tracking(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
}

static void sf_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  real_T (*c2_Depth)[307200];
  real_T (*c2_Perimeter)[500];
  real_T (*c2_b)[500];
  real_T (*c2_Centroid2)[1000];
  int32_T (*c2_CBox)[2000];
  real_T (*c2_a)[500];
  int32_T (*c2_BBox)[2000];
  real_T (*c2_Centroid)[1000];
  int32_T (*c2_Area)[500];
  c2_Depth = (real_T (*)[307200])ssGetInputPortSignal(chartInstance->S, 6);
  c2_Perimeter = (real_T (*)[500])ssGetInputPortSignal(chartInstance->S, 5);
  c2_b = (real_T (*)[500])ssGetInputPortSignal(chartInstance->S, 4);
  c2_Centroid2 = (real_T (*)[1000])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_CBox = (int32_T (*)[2000])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_a = (real_T (*)[500])ssGetInputPortSignal(chartInstance->S, 3);
  c2_BBox = (int32_T (*)[2000])ssGetInputPortSignal(chartInstance->S, 2);
  c2_Centroid = (real_T (*)[1000])ssGetInputPortSignal(chartInstance->S, 1);
  c2_Area = (int32_T (*)[500])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i4 = 0; c2_i4 < 500; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_Area)[c2_i4], 0U);
  }

  for (c2_i5 = 0; c2_i5 < 1000; c2_i5++) {
    _SFD_DATA_RANGE_CHECK((*c2_Centroid)[c2_i5], 1U);
  }

  for (c2_i6 = 0; c2_i6 < 2000; c2_i6++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_BBox)[c2_i6], 2U);
  }

  for (c2_i7 = 0; c2_i7 < 500; c2_i7++) {
    _SFD_DATA_RANGE_CHECK((*c2_a)[c2_i7], 3U);
  }

  for (c2_i8 = 0; c2_i8 < 2000; c2_i8++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_CBox)[c2_i8], 4U);
  }

  for (c2_i9 = 0; c2_i9 < 1000; c2_i9++) {
    _SFD_DATA_RANGE_CHECK((*c2_Centroid2)[c2_i9], 5U);
  }

  for (c2_i10 = 0; c2_i10 < 500; c2_i10++) {
    _SFD_DATA_RANGE_CHECK((*c2_b)[c2_i10], 6U);
  }

  for (c2_i11 = 0; c2_i11 < 500; c2_i11++) {
    _SFD_DATA_RANGE_CHECK((*c2_Perimeter)[c2_i11], 7U);
  }

  for (c2_i12 = 0; c2_i12 < 307200; c2_i12++) {
    _SFD_DATA_RANGE_CHECK((*c2_Depth)[c2_i12], 8U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_nid_cvst_pattern_tracking(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_nid_cvst_pattern_trackingMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
  int32_T c2_i13;
  int32_T c2_Area[500];
  int32_T c2_i14;
  real_T c2_Centroid[1000];
  int32_T c2_i15;
  int32_T c2_BBox[2000];
  int32_T c2_i16;
  real_T c2_a[500];
  int32_T c2_i17;
  real_T c2_b[500];
  int32_T c2_i18;
  real_T c2_Perimeter[500];
  int32_T c2_i19;
  static real_T c2_Depth[307200];
  uint32_T c2_debug_family_var_map[18];
  real_T c2_m;
  real_T c2_Ptemp[500];
  real_T c2_Rate[500];
  real_T c2_Th;
  real_T c2_n;
  real_T c2_X;
  real_T c2_Y;
  real_T c2_b_a[500];
  real_T c2_b_b[500];
  real_T c2_nargin = 7.0;
  real_T c2_nargout = 2.0;
  int32_T c2_CBox[2000];
  real_T c2_Centroid2[1000];
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_b_n;
  real_T c2_d0;
  int32_T c2_c_n;
  int32_T c2_i25;
  int32_T c2_d_n;
  int32_T c2_i26;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  int32_T c2_e_n;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_f_n;
  int32_T c2_g_n;
  int32_T c2_i29;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T (*c2_b_CBox)[2000];
  real_T (*c2_b_Centroid2)[1000];
  real_T (*c2_b_Depth)[307200];
  real_T (*c2_b_Perimeter)[500];
  real_T (*c2_c_b)[500];
  real_T (*c2_c_a)[500];
  int32_T (*c2_b_BBox)[2000];
  real_T (*c2_b_Centroid)[1000];
  int32_T (*c2_b_Area)[500];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c2_b_Depth = (real_T (*)[307200])ssGetInputPortSignal(chartInstance->S, 6);
  c2_b_Perimeter = (real_T (*)[500])ssGetInputPortSignal(chartInstance->S, 5);
  c2_c_b = (real_T (*)[500])ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_Centroid2 = (real_T (*)[1000])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_CBox = (int32_T (*)[2000])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_c_a = (real_T (*)[500])ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_BBox = (int32_T (*)[2000])ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_Centroid = (real_T (*)[1000])ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_Area = (int32_T (*)[500])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i13 = 0; c2_i13 < 500; c2_i13++) {
    c2_Area[c2_i13] = (*c2_b_Area)[c2_i13];
  }

  for (c2_i14 = 0; c2_i14 < 1000; c2_i14++) {
    c2_Centroid[c2_i14] = (*c2_b_Centroid)[c2_i14];
  }

  for (c2_i15 = 0; c2_i15 < 2000; c2_i15++) {
    c2_BBox[c2_i15] = (*c2_b_BBox)[c2_i15];
  }

  for (c2_i16 = 0; c2_i16 < 500; c2_i16++) {
    c2_a[c2_i16] = (*c2_c_a)[c2_i16];
  }

  for (c2_i17 = 0; c2_i17 < 500; c2_i17++) {
    c2_b[c2_i17] = (*c2_c_b)[c2_i17];
  }

  for (c2_i18 = 0; c2_i18 < 500; c2_i18++) {
    c2_Perimeter[c2_i18] = (*c2_b_Perimeter)[c2_i18];
  }

  for (c2_i19 = 0; c2_i19 < 307200; c2_i19++) {
    c2_Depth[c2_i19] = (*c2_b_Depth)[c2_i19];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 20U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_m, 0U, c2_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Ptemp, 1U, c2_g_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Rate, 2U, c2_g_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Th, 3U, c2_f_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_n, 4U, c2_f_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_X, 5U, c2_f_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Y, 6U, c2_f_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_a, MAX_uint32_T, c2_g_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_b, MAX_uint32_T, c2_g_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 9U, c2_f_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 10U, c2_f_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_Area, 11U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_Centroid, 12U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_BBox, 13U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_a, 7U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b, 8U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_Perimeter, 14U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_Depth, 15U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_CBox, 16U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Centroid2, 17U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_m = 500.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  for (c2_i20 = 0; c2_i20 < 500; c2_i20++) {
    c2_Ptemp[c2_i20] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i21 = 0; c2_i21 < 500; c2_i21++) {
    c2_Rate[c2_i21] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  for (c2_i22 = 0; c2_i22 < 2000; c2_i22++) {
    c2_CBox[c2_i22] = c2_BBox[c2_i22];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  for (c2_i23 = 0; c2_i23 < 500; c2_i23++) {
    c2_b_a[c2_i23] = 0.5 * c2_a[c2_i23];
  }

  _SFD_SYMBOL_SWITCH(7U, 7U);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i24 = 0; c2_i24 < 500; c2_i24++) {
    c2_b_b[c2_i24] = 0.5 * c2_b[c2_i24];
  }

  _SFD_SYMBOL_SWITCH(8U, 8U);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_Th = 150.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  c2_n = 1.0;
  c2_b_n = 0;
  while (c2_b_n < 500) {
    c2_n = 1.0 + (real_T)c2_b_n;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
    c2_d0 = 2.0 * (c2_power(chartInstance, c2_b_a[(int32_T)(real_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)_SFD_INTEGER_CHECK("n", c2_n), 1,
      500, 1, 0) - 1]) + c2_power(chartInstance, c2_b_b[(int32_T)(real_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("b", (int32_T)_SFD_INTEGER_CHECK("n", c2_n), 1,
      500, 1, 0) - 1])) - c2_rdivide(chartInstance, c2_power(chartInstance,
      c2_b_a[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
      _SFD_INTEGER_CHECK("n", c2_n), 1, 500, 1, 0) - 1] - c2_b_b[(int32_T)
      (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("b", (int32_T)_SFD_INTEGER_CHECK("n",
      c2_n), 1, 500, 1, 0) - 1]), 2.2);
    c2_b_sqrt(chartInstance, &c2_d0);
    c2_Ptemp[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Ptemp", (int32_T)
      _SFD_INTEGER_CHECK("n", c2_n), 1, 500, 1, 0) - 1] = 3.1415926535897931 *
      c2_d0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
    c2_Rate[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Rate", (int32_T)
      _SFD_INTEGER_CHECK("n", c2_n), 1, 500, 1, 0) - 1] = c2_rdivide
      (chartInstance, c2_Ptemp[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
        "Ptemp", (int32_T)_SFD_INTEGER_CHECK("n", c2_n), 1, 500, 1, 0) - 1],
       c2_Perimeter[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Perimeter",
        (int32_T)_SFD_INTEGER_CHECK("n", c2_n), 1, 500, 1, 0) - 1]);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
    guard3 = FALSE;
    if (CV_EML_COND(0, 1, 0, c2_rdivide(chartInstance, c2_Ptemp[(int32_T)(real_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("Ptemp", (int32_T)_SFD_INTEGER_CHECK("n",
            c2_n), 1, 500, 1, 0) - 1], c2_Perimeter[(int32_T)(real_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("Perimeter", (int32_T)_SFD_INTEGER_CHECK(
            "n", c2_n), 1, 500, 1, 0) - 1]) > 1.1)) {
      guard3 = TRUE;
    } else if (CV_EML_COND(0, 1, 1, c2_rdivide(chartInstance, c2_Ptemp[(int32_T)
                 (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Ptemp", (int32_T)
                  _SFD_INTEGER_CHECK("n", c2_n), 1, 500, 1, 0) - 1],
                 c2_Perimeter[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
                  "Perimeter", (int32_T)_SFD_INTEGER_CHECK("n", c2_n), 1, 500, 1,
      0) - 1]) < 0.9)) {
      guard3 = TRUE;
    } else {
      CV_EML_MCDC(0, 1, 0, FALSE);
      CV_EML_IF(0, 1, 0, FALSE);
    }

    if (guard3 == TRUE) {
      CV_EML_MCDC(0, 1, 0, TRUE);
      CV_EML_IF(0, 1, 0, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
      c2_c_n = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("CBox", (int32_T)
        _SFD_INTEGER_CHECK("n", c2_n), 1, 500, 1, 0) - 1;
      for (c2_i25 = 0; c2_i25 < 4; c2_i25++) {
        c2_CBox[c2_c_n + 500 * c2_i25] = -1;
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
    if (CV_EML_IF(0, 1, 1, (real_T)c2_Area[(int32_T)(real_T)
                  _SFD_EML_ARRAY_BOUNDS_CHECK("Area", (int32_T)
          _SFD_INTEGER_CHECK("n", c2_n), 1, 500, 1, 0) - 1] < c2_Th)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
      c2_d_n = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("CBox", (int32_T)
        _SFD_INTEGER_CHECK("n", c2_n), 1, 500, 1, 0) - 1;
      for (c2_i26 = 0; c2_i26 < 4; c2_i26++) {
        c2_CBox[c2_d_n + 500 * c2_i26] = -1;
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
    c2_x = c2_Centroid[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Centroid",
      (int32_T)_SFD_INTEGER_CHECK("n", c2_n), 1, 500, 1, 0) - 1];
    c2_X = c2_x;
    c2_b_x = c2_X;
    c2_X = c2_b_x;
    c2_X = muDoubleScalarRound(c2_X);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
    c2_c_x = c2_Centroid[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Centroid",
      (int32_T)_SFD_INTEGER_CHECK("n", c2_n), 1, 500, 1, 0) + 499];
    c2_Y = c2_c_x;
    c2_d_x = c2_Y;
    c2_Y = c2_d_x;
    c2_Y = muDoubleScalarRound(c2_Y);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
    guard1 = FALSE;
    if (CV_EML_COND(0, 1, 2, c2_X > 0.0)) {
      guard1 = TRUE;
    } else if (CV_EML_COND(0, 1, 3, c2_Y > 0.0)) {
      guard1 = TRUE;
    } else {
      CV_EML_MCDC(0, 1, 1, FALSE);
      CV_EML_IF(0, 1, 2, FALSE);
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(0, 1, 1, TRUE);
      CV_EML_IF(0, 1, 2, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
      guard2 = FALSE;
      if (CV_EML_COND(0, 1, 4, c2_Depth[((int32_T)(real_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("Depth", (int32_T)_SFD_INTEGER_CHECK("Y",
              c2_Y), 1, 480, 1, 0) + 480 * ((int32_T)(real_T)
             _SFD_EML_ARRAY_BOUNDS_CHECK("Depth", (int32_T)_SFD_INTEGER_CHECK(
               "X", c2_X), 1, 640, 2, 0) - 1)) - 1] == 0.0)) {
        guard2 = TRUE;
      } else if (CV_EML_COND(0, 1, 5, c2_Depth[((int32_T)(real_T)
                   _SFD_EML_ARRAY_BOUNDS_CHECK("Depth", (int32_T)
                    _SFD_INTEGER_CHECK("Y", c2_Y), 1, 480, 1, 0) + 480 *
                   ((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Depth",
          (int32_T)_SFD_INTEGER_CHECK("X", c2_X), 1, 640, 2, 0) - 1)) - 1] > 2.0))
      {
        guard2 = TRUE;
      } else {
        CV_EML_MCDC(0, 1, 2, FALSE);
        CV_EML_IF(0, 1, 3, FALSE);
      }

      if (guard2 == TRUE) {
        CV_EML_MCDC(0, 1, 2, TRUE);
        CV_EML_IF(0, 1, 3, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
        c2_e_n = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("CBox", (int32_T)
          _SFD_INTEGER_CHECK("n", c2_n), 1, 500, 1, 0) - 1;
        for (c2_i27 = 0; c2_i27 < 4; c2_i27++) {
          c2_CBox[c2_e_n + 500 * c2_i27] = -1;
        }
      }
    }

    c2_b_n++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
  for (c2_i28 = 0; c2_i28 < 1000; c2_i28++) {
    c2_Centroid2[c2_i28] = c2_Centroid[c2_i28];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_n = 1.0;
  c2_f_n = 0;
  while (c2_f_n < 500) {
    c2_n = 1.0 + (real_T)c2_f_n;
    CV_EML_FOR(0, 1, 1, 1);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
    if (CV_EML_IF(0, 1, 4, (real_T)c2_CBox[(int32_T)(real_T)
                  _SFD_EML_ARRAY_BOUNDS_CHECK("CBox", (int32_T)
          _SFD_INTEGER_CHECK("n", c2_n), 1, 500, 1, 0) - 1] == -1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 34);
      c2_g_n = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Centroid2",
        (int32_T)_SFD_INTEGER_CHECK("n", c2_n), 1, 500, 1, 0) - 1;
      for (c2_i29 = 0; c2_i29 < 2; c2_i29++) {
        c2_Centroid2[c2_g_n + 500 * c2_i29] = -1.0;
      }
    }

    c2_f_n++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 1, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -34);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i30 = 0; c2_i30 < 2000; c2_i30++) {
    (*c2_b_CBox)[c2_i30] = c2_CBox[c2_i30];
  }

  for (c2_i31 = 0; c2_i31 < 1000; c2_i31++) {
    (*c2_b_Centroid2)[c2_i31] = c2_Centroid2[c2_i31];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
}

static void registerMessagesc2_nid_cvst_pattern_tracking
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  real_T c2_b_inData[1000];
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  real_T c2_u[1000];
  const mxArray *c2_y = NULL;
  SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i32 = 0;
  for (c2_i33 = 0; c2_i33 < 2; c2_i33++) {
    for (c2_i34 = 0; c2_i34 < 500; c2_i34++) {
      c2_b_inData[c2_i34 + c2_i32] = (*(real_T (*)[1000])c2_inData)[c2_i34 +
        c2_i32];
    }

    c2_i32 += 500;
  }

  c2_i35 = 0;
  for (c2_i36 = 0; c2_i36 < 2; c2_i36++) {
    for (c2_i37 = 0; c2_i37 < 500; c2_i37++) {
      c2_u[c2_i37 + c2_i35] = c2_b_inData[c2_i37 + c2_i35];
    }

    c2_i35 += 500;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 500, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance, const mxArray *c2_Centroid2, const char_T *c2_identifier,
  real_T c2_y[1000])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Centroid2), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_Centroid2);
}

static void c2_b_emlrt_marshallIn(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[1000])
{
  real_T c2_dv1[1000];
  int32_T c2_i38;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 2, 500,
                2);
  for (c2_i38 = 0; c2_i38 < 1000; c2_i38++) {
    c2_y[c2_i38] = c2_dv1[c2_i38];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Centroid2;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[1000];
  int32_T c2_i39;
  int32_T c2_i40;
  int32_T c2_i41;
  SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c2_Centroid2 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Centroid2), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_Centroid2);
  c2_i39 = 0;
  for (c2_i40 = 0; c2_i40 < 2; c2_i40++) {
    for (c2_i41 = 0; c2_i41 < 500; c2_i41++) {
      (*(real_T (*)[1000])c2_outData)[c2_i41 + c2_i39] = c2_y[c2_i41 + c2_i39];
    }

    c2_i39 += 500;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_b_inData[2000];
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  int32_T c2_u[2000];
  const mxArray *c2_y = NULL;
  SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i42 = 0;
  for (c2_i43 = 0; c2_i43 < 4; c2_i43++) {
    for (c2_i44 = 0; c2_i44 < 500; c2_i44++) {
      c2_b_inData[c2_i44 + c2_i42] = (*(int32_T (*)[2000])c2_inData)[c2_i44 +
        c2_i42];
    }

    c2_i42 += 500;
  }

  c2_i45 = 0;
  for (c2_i46 = 0; c2_i46 < 4; c2_i46++) {
    for (c2_i47 = 0; c2_i47 < 500; c2_i47++) {
      c2_u[c2_i47 + c2_i45] = c2_b_inData[c2_i47 + c2_i45];
    }

    c2_i45 += 500;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 6, 0U, 1U, 0U, 2, 500, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance, const mxArray *c2_CBox, const char_T *c2_identifier, int32_T
  c2_y[2000])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_CBox), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_CBox);
}

static void c2_d_emlrt_marshallIn(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  int32_T c2_y[2000])
{
  int32_T c2_iv1[2000];
  int32_T c2_i48;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_iv1, 1, 6, 0U, 1, 0U, 2, 500,
                4);
  for (c2_i48 = 0; c2_i48 < 2000; c2_i48++) {
    c2_y[c2_i48] = c2_iv1[c2_i48];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_CBox;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y[2000];
  int32_T c2_i49;
  int32_T c2_i50;
  int32_T c2_i51;
  SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c2_CBox = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_CBox), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_CBox);
  c2_i49 = 0;
  for (c2_i50 = 0; c2_i50 < 4; c2_i50++) {
    for (c2_i51 = 0; c2_i51 < 500; c2_i51++) {
      (*(int32_T (*)[2000])c2_outData)[c2_i51 + c2_i49] = c2_y[c2_i51 + c2_i49];
    }

    c2_i49 += 500;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i52;
  int32_T c2_i53;
  int32_T c2_i54;
  static real_T c2_b_inData[307200];
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_i57;
  static real_T c2_u[307200];
  const mxArray *c2_y = NULL;
  SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i52 = 0;
  for (c2_i53 = 0; c2_i53 < 640; c2_i53++) {
    for (c2_i54 = 0; c2_i54 < 480; c2_i54++) {
      c2_b_inData[c2_i54 + c2_i52] = (*(real_T (*)[307200])c2_inData)[c2_i54 +
        c2_i52];
    }

    c2_i52 += 480;
  }

  c2_i55 = 0;
  for (c2_i56 = 0; c2_i56 < 640; c2_i56++) {
    for (c2_i57 = 0; c2_i57 < 480; c2_i57++) {
      c2_u[c2_i57 + c2_i55] = c2_b_inData[c2_i57 + c2_i55];
    }

    c2_i55 += 480;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 480, 640),
                FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i58;
  real_T c2_b_inData[500];
  int32_T c2_i59;
  real_T c2_u[500];
  const mxArray *c2_y = NULL;
  SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i58 = 0; c2_i58 < 500; c2_i58++) {
    c2_b_inData[c2_i58] = (*(real_T (*)[500])c2_inData)[c2_i58];
  }

  for (c2_i59 = 0; c2_i59 < 500; c2_i59++) {
    c2_u[c2_i59] = c2_b_inData[c2_i59];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 500, 1), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i60;
  int32_T c2_b_inData[500];
  int32_T c2_i61;
  int32_T c2_u[500];
  const mxArray *c2_y = NULL;
  SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i60 = 0; c2_i60 < 500; c2_i60++) {
    c2_b_inData[c2_i60] = (*(int32_T (*)[500])c2_inData)[c2_i60];
  }

  for (c2_i61 = 0; c2_i61 < 500; c2_i61++) {
    c2_u[c2_i61] = c2_b_inData[c2_i61];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 6, 0U, 1U, 0U, 2, 500, 1), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_e_emlrt_marshallIn(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d1;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d1, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i62;
  real_T c2_b_inData[500];
  int32_T c2_i63;
  real_T c2_u[500];
  const mxArray *c2_y = NULL;
  SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i62 = 0; c2_i62 < 500; c2_i62++) {
    c2_b_inData[c2_i62] = (*(real_T (*)[500])c2_inData)[c2_i62];
  }

  for (c2_i63 = 0; c2_i63 < 500; c2_i63++) {
    c2_u[c2_i63] = c2_b_inData[c2_i63];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 500), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_f_emlrt_marshallIn(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[500])
{
  real_T c2_dv2[500];
  int32_T c2_i64;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv2, 1, 0, 0U, 1, 0U, 1, 500);
  for (c2_i64 = 0; c2_i64 < 500; c2_i64++) {
    c2_y[c2_i64] = c2_dv2[c2_i64];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[500];
  int32_T c2_i65;
  SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c2_b = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b);
  for (c2_i65 = 0; c2_i65 < 500; c2_i65++) {
    (*(real_T (*)[500])c2_outData)[c2_i65] = c2_y[c2_i65];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_nid_cvst_pattern_tracking_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[16];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i66;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 16), FALSE);
  for (c2_i66 = 0; c2_i66 < 16; c2_i66++) {
    c2_r0 = &c2_info[c2_i66];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i66);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i66);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i66);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i66);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i66);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i66);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i66);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i66);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[16])
{
  c2_info[0].context = "";
  c2_info[0].name = "length";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[0].fileTimeLo = 1303128206U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "";
  c2_info[1].name = "power";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[1].fileTimeLo = 1348173930U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[2].name = "eml_scalar_eg";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[2].fileTimeLo = 1286800796U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[3].name = "eml_scalexp_alloc";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[3].fileTimeLo = 1352403260U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[4].name = "floor";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[4].fileTimeLo = 1343812380U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[5].name = "eml_scalar_floor";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[5].fileTimeLo = 1286800726U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c2_info[6].name = "eml_scalar_eg";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[6].fileTimeLo = 1286800796U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c2_info[7].name = "mtimes";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[7].fileTimeLo = 1289498092U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "";
  c2_info[8].name = "rdivide";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[8].fileTimeLo = 1346492388U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[9].name = "eml_scalexp_compatible";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c2_info[9].fileTimeLo = 1286800796U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[10].name = "eml_div";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[10].fileTimeLo = 1313329810U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context = "";
  c2_info[11].name = "sqrt";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[11].fileTimeLo = 1343812386U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[12].name = "eml_error";
  c2_info[12].dominantType = "char";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[12].fileTimeLo = 1343812358U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[13].name = "eml_scalar_sqrt";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c2_info[13].fileTimeLo = 1286800738U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context = "";
  c2_info[14].name = "round";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c2_info[14].fileTimeLo = 1343812384U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c2_info[15].name = "eml_scalar_round";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c2_info[15].fileTimeLo = 1307633238U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
}

static real_T c2_power(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance, real_T c2_a)
{
  real_T c2_b_a;
  real_T c2_ak;
  real_T c2_c_a;
  real_T c2_d_a;
  real_T c2_b;
  c2_b_a = c2_a;
  c2_eml_scalar_eg(chartInstance);
  c2_ak = c2_b_a;
  c2_c_a = c2_ak;
  c2_eml_scalar_eg(chartInstance);
  c2_d_a = c2_c_a;
  c2_b = c2_c_a;
  return c2_d_a * c2_b;
}

static void c2_eml_scalar_eg(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance)
{
}

static real_T c2_rdivide(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance, real_T c2_x, real_T c2_y)
{
  real_T c2_b_x;
  real_T c2_b_y;
  c2_b_x = c2_x;
  c2_b_y = c2_y;
  return c2_b_x / c2_b_y;
}

static real_T c2_sqrt(SFc2_nid_cvst_pattern_trackingInstanceStruct
                      *chartInstance, real_T c2_x)
{
  real_T c2_b_x;
  c2_b_x = c2_x;
  c2_b_sqrt(chartInstance, &c2_b_x);
  return c2_b_x;
}

static void c2_eml_error(SFc2_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance)
{
  int32_T c2_i67;
  static char_T c2_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[30];
  const mxArray *c2_y = NULL;
  int32_T c2_i68;
  static char_T c2_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c2_b_u[4];
  const mxArray *c2_b_y = NULL;
  for (c2_i67 = 0; c2_i67 < 30; c2_i67++) {
    c2_u[c2_i67] = c2_cv0[c2_i67];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c2_i68 = 0; c2_i68 < 4; c2_i68++) {
    c2_b_u[c2_i68] = c2_cv1[c2_i68];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c2_y, 14, c2_b_y));
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_g_emlrt_marshallIn
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i69;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i69, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i69;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_h_emlrt_marshallIn
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance, const mxArray
   *c2_b_is_active_c2_nid_cvst_pattern_tracking, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_nid_cvst_pattern_tracking), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_nid_cvst_pattern_tracking);
  return c2_y;
}

static uint8_T c2_i_emlrt_marshallIn
  (SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sqrt(SFc2_nid_cvst_pattern_trackingInstanceStruct
                      *chartInstance, real_T *c2_x)
{
  if (*c2_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  *c2_x = muDoubleScalarSqrt(*c2_x);
}

static void init_dsm_address_info(SFc2_nid_cvst_pattern_trackingInstanceStruct
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

void sf_c2_nid_cvst_pattern_tracking_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(873114006U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2542206523U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3285285069U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(900926447U);
}

mxArray *sf_c2_nid_cvst_pattern_tracking_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("bkM2ElTg88iXibGueVOo0F");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(500);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(500);
      pr[1] = (double)(2);
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
      pr[0] = (double)(500);
      pr[1] = (double)(4);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(500);
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
      pr[0] = (double)(500);
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
      pr[0] = (double)(500);
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
      pr[0] = (double)(480);
      pr[1] = (double)(640);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(500);
      pr[1] = (double)(4);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(500);
      pr[1] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_nid_cvst_pattern_tracking_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_nid_cvst_pattern_tracking(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"CBox\",},{M[1],M[14],T\"Centroid2\",},{M[8],M[0],T\"is_active_c2_nid_cvst_pattern_tracking\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_nid_cvst_pattern_tracking_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
    chartInstance = (SFc2_nid_cvst_pattern_trackingInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _nid_cvst_pattern_trackingMachineNumber_,
           2,
           1,
           1,
           9,
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
          init_script_number_translation
            (_nid_cvst_pattern_trackingMachineNumber_,chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _nid_cvst_pattern_trackingMachineNumber_,chartInstance->chartNumber,
             1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _nid_cvst_pattern_trackingMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Area");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Centroid");
          _SFD_SET_DATA_PROPS(2,1,1,0,"BBox");
          _SFD_SET_DATA_PROPS(3,1,1,0,"a");
          _SFD_SET_DATA_PROPS(4,2,0,1,"CBox");
          _SFD_SET_DATA_PROPS(5,2,0,1,"Centroid2");
          _SFD_SET_DATA_PROPS(6,1,1,0,"b");
          _SFD_SET_DATA_PROPS(7,1,1,0,"Perimeter");
          _SFD_SET_DATA_PROPS(8,1,1,0,"Depth");
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
        _SFD_CV_INIT_EML(0,1,1,5,0,0,0,2,0,6,3);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,728);
        _SFD_CV_INIT_EML_IF(0,1,0,308,367,-1,397);
        _SFD_CV_INIT_EML_IF(0,1,1,402,415,-1,445);
        _SFD_CV_INIT_EML_IF(0,1,2,515,530,-1,617);
        _SFD_CV_INIT_EML_IF(0,1,3,539,571,-1,609);
        _SFD_CV_INIT_EML_IF(0,1,4,665,681,-1,719);
        _SFD_CV_INIT_EML_FOR(0,1,0,187,199,625);
        _SFD_CV_INIT_EML_FOR(0,1,1,649,661,723);

        {
          static int condStart[] = { 311, 341 };

          static int condEnd[] = { 337, 367 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,311,367,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 518, 525 };

          static int condEnd[] = { 521, 530 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,518,530,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 542, 559 };

          static int condEnd[] = { 555, 571 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,542,571,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 500;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 500;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 500;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 500;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 500;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 500;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 500;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 500;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 480;
          dimVector[1]= 640;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          int32_T (*c2_Area)[500];
          real_T (*c2_Centroid)[1000];
          int32_T (*c2_BBox)[2000];
          real_T (*c2_a)[500];
          int32_T (*c2_CBox)[2000];
          real_T (*c2_Centroid2)[1000];
          real_T (*c2_b)[500];
          real_T (*c2_Perimeter)[500];
          real_T (*c2_Depth)[307200];
          c2_Depth = (real_T (*)[307200])ssGetInputPortSignal(chartInstance->S,
            6);
          c2_Perimeter = (real_T (*)[500])ssGetInputPortSignal(chartInstance->S,
            5);
          c2_b = (real_T (*)[500])ssGetInputPortSignal(chartInstance->S, 4);
          c2_Centroid2 = (real_T (*)[1000])ssGetOutputPortSignal
            (chartInstance->S, 2);
          c2_CBox = (int32_T (*)[2000])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_a = (real_T (*)[500])ssGetInputPortSignal(chartInstance->S, 3);
          c2_BBox = (int32_T (*)[2000])ssGetInputPortSignal(chartInstance->S, 2);
          c2_Centroid = (real_T (*)[1000])ssGetInputPortSignal(chartInstance->S,
            1);
          c2_Area = (int32_T (*)[500])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_Area);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_Centroid);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_BBox);
          _SFD_SET_DATA_VALUE_PTR(3U, *c2_a);
          _SFD_SET_DATA_VALUE_PTR(4U, *c2_CBox);
          _SFD_SET_DATA_VALUE_PTR(5U, *c2_Centroid2);
          _SFD_SET_DATA_VALUE_PTR(6U, *c2_b);
          _SFD_SET_DATA_VALUE_PTR(7U, *c2_Perimeter);
          _SFD_SET_DATA_VALUE_PTR(8U, *c2_Depth);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _nid_cvst_pattern_trackingMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "A0rhDr3eRRKoa5qGHNrnEG";
}

static void sf_opaque_initialize_c2_nid_cvst_pattern_tracking(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_nid_cvst_pattern_trackingInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_nid_cvst_pattern_tracking
    ((SFc2_nid_cvst_pattern_trackingInstanceStruct*) chartInstanceVar);
  initialize_c2_nid_cvst_pattern_tracking
    ((SFc2_nid_cvst_pattern_trackingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_nid_cvst_pattern_tracking(void *chartInstanceVar)
{
  enable_c2_nid_cvst_pattern_tracking
    ((SFc2_nid_cvst_pattern_trackingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_nid_cvst_pattern_tracking(void
  *chartInstanceVar)
{
  disable_c2_nid_cvst_pattern_tracking
    ((SFc2_nid_cvst_pattern_trackingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_nid_cvst_pattern_tracking(void
  *chartInstanceVar)
{
  sf_c2_nid_cvst_pattern_tracking((SFc2_nid_cvst_pattern_trackingInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_nid_cvst_pattern_tracking
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_nid_cvst_pattern_tracking
    ((SFc2_nid_cvst_pattern_trackingInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_nid_cvst_pattern_tracking();/* state var info */
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

extern void sf_internal_set_sim_state_c2_nid_cvst_pattern_tracking(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_nid_cvst_pattern_tracking();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_nid_cvst_pattern_tracking
    ((SFc2_nid_cvst_pattern_trackingInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_nid_cvst_pattern_tracking
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_nid_cvst_pattern_tracking(S);
}

static void sf_opaque_set_sim_state_c2_nid_cvst_pattern_tracking(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c2_nid_cvst_pattern_tracking(S, st);
}

static void sf_opaque_terminate_c2_nid_cvst_pattern_tracking(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_nid_cvst_pattern_trackingInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_nid_cvst_pattern_tracking_optimization_info();
    }

    finalize_c2_nid_cvst_pattern_tracking
      ((SFc2_nid_cvst_pattern_trackingInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_nid_cvst_pattern_tracking
    ((SFc2_nid_cvst_pattern_trackingInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_nid_cvst_pattern_tracking(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_nid_cvst_pattern_tracking
      ((SFc2_nid_cvst_pattern_trackingInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_nid_cvst_pattern_tracking(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_nid_cvst_pattern_tracking_optimization_info();
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
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1358414027U));
  ssSetChecksum1(S,(195257515U));
  ssSetChecksum2(S,(1229439735U));
  ssSetChecksum3(S,(1033021833U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_nid_cvst_pattern_tracking(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_nid_cvst_pattern_tracking(SimStruct *S)
{
  SFc2_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc2_nid_cvst_pattern_trackingInstanceStruct *)utMalloc
    (sizeof(SFc2_nid_cvst_pattern_trackingInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_nid_cvst_pattern_trackingInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_nid_cvst_pattern_tracking;
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

void c2_nid_cvst_pattern_tracking_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_nid_cvst_pattern_tracking(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_nid_cvst_pattern_tracking(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_nid_cvst_pattern_tracking(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_nid_cvst_pattern_tracking_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
