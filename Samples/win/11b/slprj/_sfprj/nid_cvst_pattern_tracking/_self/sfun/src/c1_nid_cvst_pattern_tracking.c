/* Include files */

#include <stddef.h>
#include "blas.h"
#include "nid_cvst_pattern_tracking_sfun.h"
#include "c1_nid_cvst_pattern_tracking.h"
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
static const char * c1_debug_family_names[9] = { "m", "n", "X", "Y", "nargin",
  "nargout", "I", "Centroid2", "XYZ" };

/* Function Declarations */
static void initialize_c1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void initialize_params_c1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void enable_c1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void disable_c1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void set_sim_state_c1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance, const mxArray
   *c1_st);
static void finalize_c1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void sf_c1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void initSimStructsc1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void registerMessagesc1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_b_emlrt_marshallIn
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_c_emlrt_marshallIn
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance, const mxArray
   *c1_b_is_active_c1_nid_cvst_pattern_tracking, const char_T *c1_identifier);
static uint8_T c1_d_emlrt_marshallIn
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_nid_cvst_pattern_tracking = 0U;
}

static void initialize_params_c1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
}

static void enable_c1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_u;
  const mxArray *c1_b_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(1), FALSE);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_nid_cvst_pattern_tracking;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  const mxArray *c1_u;
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  chartInstance->c1_is_active_c1_nid_cvst_pattern_tracking =
    c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "is_active_c1_nid_cvst_pattern_tracking");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_nid_cvst_pattern_tracking(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
}

static void sf_c1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
  int32_T c1_i0;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  static uint8_T c1_I[921600];
  int32_T c1_i4;
  real_T c1_Centroid2[1000];
  int32_T c1_i5;
  static real_T c1_XYZ[921600];
  uint32_T c1_debug_family_var_map[9];
  real_T c1_m;
  real_T c1_n;
  real_T c1_X;
  real_T c1_Y;
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 0.0;
  int32_T c1_i6;
  static uint8_T c1_u[921600];
  const mxArray *c1_y = NULL;
  int32_T c1_i7;
  static char_T c1_cv0[3] = { 'o', 'f', 'f' };

  char_T c1_b_u[3];
  const mxArray *c1_b_y = NULL;
  int32_T c1_b_n;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  int32_T c1_i8;
  static char_T c1_cv1[2] = { 'o', 'n' };

  char_T c1_c_u[2];
  const mxArray *c1_c_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  int32_T c1_i9;
  char_T c1_f_u[2];
  const mxArray *c1_f_y = NULL;
  int32_T c1_i10;
  static char_T c1_cv2[2] = { 'X', ':' };

  char_T c1_g_u[2];
  const mxArray *c1_g_y = NULL;
  real_T c1_h_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_i_u;
  const mxArray *c1_i_y = NULL;
  int32_T c1_i11;
  static char_T c1_cv3[3] = { ' ', 'Y', ':' };

  char_T c1_j_u[3];
  const mxArray *c1_j_y = NULL;
  real_T c1_k_u;
  const mxArray *c1_k_y = NULL;
  real_T c1_l_u;
  const mxArray *c1_l_y = NULL;
  int32_T c1_i12;
  static char_T c1_cv4[3] = { ' ', 'Z', ':' };

  char_T c1_m_u[3];
  const mxArray *c1_m_y = NULL;
  real_T c1_n_u;
  const mxArray *c1_n_y = NULL;
  real_T c1_o_u;
  const mxArray *c1_o_y = NULL;
  int32_T c1_i13;
  char_T c1_p_u[3];
  const mxArray *c1_p_y = NULL;
  real_T (*c1_b_XYZ)[921600];
  real_T (*c1_b_Centroid2)[1000];
  uint8_T (*c1_b_I)[921600];
  c1_b_XYZ = (real_T (*)[921600])ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_Centroid2 = (real_T (*)[1000])ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_I = (uint8_T (*)[921600])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i0 = 0; c1_i0 < 921600; c1_i0++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c1_b_I)[c1_i0], 0U);
  }

  for (c1_i1 = 0; c1_i1 < 1000; c1_i1++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_Centroid2)[c1_i1], 1U);
  }

  for (c1_i2 = 0; c1_i2 < 921600; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_XYZ)[c1_i2], 2U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i3 = 0; c1_i3 < 921600; c1_i3++) {
    c1_I[c1_i3] = (*c1_b_I)[c1_i3];
  }

  for (c1_i4 = 0; c1_i4 < 1000; c1_i4++) {
    c1_Centroid2[c1_i4] = (*c1_b_Centroid2)[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 921600; c1_i5++) {
    c1_XYZ[c1_i5] = (*c1_b_XYZ)[c1_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_m, 0U, c1_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_n, 1U, c1_d_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_X, 2U, c1_d_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Y, 3U, c1_d_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 4U, c1_d_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 5U, c1_d_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_I, 6U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Centroid2, 7U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_XYZ, 8U, c1_sf_marshallOut);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  c1_m = 500.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  for (c1_i6 = 0; c1_i6 < 921600; c1_i6++) {
    c1_u[c1_i6] = c1_I[c1_i6];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 3, 0U, 1U, 0U, 3, 480, 640, 3),
                FALSE);
  sf_mex_call_debug("image", 0U, 1U, 14, c1_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  for (c1_i7 = 0; c1_i7 < 3; c1_i7++) {
    c1_b_u[c1_i7] = c1_cv0[c1_i7];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 3),
                FALSE);
  sf_mex_call_debug("axis", 0U, 1U, 14, c1_b_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_n = 1.0;
  c1_b_n = 0;
  while (c1_b_n < 500) {
    c1_n = 1.0 + (real_T)c1_b_n;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
    if (CV_EML_IF(0, 1, 0, c1_Centroid2[(int32_T)(real_T)
                  _SFD_EML_ARRAY_BOUNDS_CHECK("Centroid2", (int32_T)
          _SFD_INTEGER_CHECK("n", c1_n), 1, 500, 1, 0) - 1] != -1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
      c1_x = c1_Centroid2[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
        "Centroid2", (int32_T)_SFD_INTEGER_CHECK("n", c1_n), 1, 500, 1, 0) - 1];
      c1_X = c1_x;
      c1_b_x = c1_X;
      c1_X = c1_b_x;
      c1_X = muDoubleScalarRound(c1_X);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
      c1_c_x = c1_Centroid2[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
        "Centroid2", (int32_T)_SFD_INTEGER_CHECK("n", c1_n), 1, 500, 1, 0) + 499];
      c1_Y = c1_c_x;
      c1_d_x = c1_Y;
      c1_Y = c1_d_x;
      c1_Y = muDoubleScalarRound(c1_Y);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
      for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
        c1_c_u[c1_i8] = c1_cv1[c1_i8];
      }

      c1_c_y = NULL;
      sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_c_u, 10, 0U, 1U, 0U, 2, 1, 2),
                    FALSE);
      sf_mex_call_debug("hold", 0U, 1U, 14, c1_c_y);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
      c1_d_u = c1_X;
      c1_d_y = NULL;
      sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c1_e_u = c1_Y;
      c1_e_y = NULL;
      sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      for (c1_i9 = 0; c1_i9 < 2; c1_i9++) {
        c1_f_u[c1_i9] = ' ';
      }

      c1_f_y = NULL;
      sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_f_u, 10, 0U, 1U, 0U, 2, 1, 2),
                    FALSE);
      for (c1_i10 = 0; c1_i10 < 2; c1_i10++) {
        c1_g_u[c1_i10] = c1_cv2[c1_i10];
      }

      c1_g_y = NULL;
      sf_mex_assign(&c1_g_y, sf_mex_create("y", c1_g_u, 10, 0U, 1U, 0U, 2, 1, 2),
                    FALSE);
      c1_h_u = c1_XYZ[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("XYZ",
        (int32_T)_SFD_INTEGER_CHECK("Y", c1_Y), 1, 480, 1, 0) + 480 * ((int32_T)
                        (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("XYZ", (int32_T)
        _SFD_INTEGER_CHECK("X", c1_X), 1, 640, 2, 0) - 1)) - 1];
      c1_h_y = NULL;
      sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c1_i_u = 3.0;
      c1_i_y = NULL;
      sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      for (c1_i11 = 0; c1_i11 < 3; c1_i11++) {
        c1_j_u[c1_i11] = c1_cv3[c1_i11];
      }

      c1_j_y = NULL;
      sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_j_u, 10, 0U, 1U, 0U, 2, 1, 3),
                    FALSE);
      c1_k_u = c1_XYZ[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("XYZ",
        (int32_T)_SFD_INTEGER_CHECK("Y", c1_Y), 1, 480, 1, 0) + 480 * ((int32_T)
                        (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("XYZ", (int32_T)
        _SFD_INTEGER_CHECK("X", c1_X), 1, 640, 2, 0) - 1)) + 307199];
      c1_k_y = NULL;
      sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c1_l_u = 3.0;
      c1_l_y = NULL;
      sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      for (c1_i12 = 0; c1_i12 < 3; c1_i12++) {
        c1_m_u[c1_i12] = c1_cv4[c1_i12];
      }

      c1_m_y = NULL;
      sf_mex_assign(&c1_m_y, sf_mex_create("y", c1_m_u, 10, 0U, 1U, 0U, 2, 1, 3),
                    FALSE);
      c1_n_u = c1_XYZ[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("XYZ",
        (int32_T)_SFD_INTEGER_CHECK("Y", c1_Y), 1, 480, 1, 0) + 480 * ((int32_T)
                        (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("XYZ", (int32_T)
        _SFD_INTEGER_CHECK("X", c1_X), 1, 640, 2, 0) - 1)) + 614399];
      c1_n_y = NULL;
      sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_n_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c1_o_u = 3.0;
      c1_o_y = NULL;
      sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_o_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      sf_mex_call_debug("text", 0U, 3U, 14, c1_d_y, 14, c1_e_y, 14,
                        sf_mex_call_debug("horzcat", 1U, 7U, 14, c1_f_y, 14,
        c1_g_y, 14, sf_mex_call_debug("num2str", 1U, 2U, 14, c1_h_y, 14, c1_i_y),
        14, c1_j_y, 14, sf_mex_call_debug("num2str", 1U, 2U, 14, c1_k_y, 14,
        c1_l_y), 14, c1_m_y, 14, sf_mex_call_debug("num2str", 1U, 2U, 14, c1_n_y,
        14, c1_o_y)));
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
      for (c1_i13 = 0; c1_i13 < 3; c1_i13++) {
        c1_p_u[c1_i13] = c1_cv0[c1_i13];
      }

      c1_p_y = NULL;
      sf_mex_assign(&c1_p_y, sf_mex_create("y", c1_p_u, 10, 0U, 1U, 0U, 2, 1, 3),
                    FALSE);
      sf_mex_call_debug("hold", 0U, 1U, 14, c1_p_y);
    }

    c1_b_n++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  sf_mex_call_debug("drawnow", 0U, 0U);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -23);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_nid_cvst_pattern_trackingMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
}

static void registerMessagesc1_nid_cvst_pattern_tracking
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  static real_T c1_b_inData[921600];
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  static real_T c1_u[921600];
  const mxArray *c1_y = NULL;
  SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc1_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i14 = 0;
  for (c1_i15 = 0; c1_i15 < 3; c1_i15++) {
    c1_i16 = 0;
    for (c1_i17 = 0; c1_i17 < 640; c1_i17++) {
      for (c1_i18 = 0; c1_i18 < 480; c1_i18++) {
        c1_b_inData[(c1_i18 + c1_i16) + c1_i14] = (*(real_T (*)[921600])
          c1_inData)[(c1_i18 + c1_i16) + c1_i14];
      }

      c1_i16 += 480;
    }

    c1_i14 += 307200;
  }

  c1_i19 = 0;
  for (c1_i20 = 0; c1_i20 < 3; c1_i20++) {
    c1_i21 = 0;
    for (c1_i22 = 0; c1_i22 < 640; c1_i22++) {
      for (c1_i23 = 0; c1_i23 < 480; c1_i23++) {
        c1_u[(c1_i23 + c1_i21) + c1_i19] = c1_b_inData[(c1_i23 + c1_i21) +
          c1_i19];
      }

      c1_i21 += 480;
    }

    c1_i19 += 307200;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 3, 480, 640, 3),
                FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  real_T c1_b_inData[1000];
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  real_T c1_u[1000];
  const mxArray *c1_y = NULL;
  SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc1_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i24 = 0;
  for (c1_i25 = 0; c1_i25 < 2; c1_i25++) {
    for (c1_i26 = 0; c1_i26 < 500; c1_i26++) {
      c1_b_inData[c1_i26 + c1_i24] = (*(real_T (*)[1000])c1_inData)[c1_i26 +
        c1_i24];
    }

    c1_i24 += 500;
  }

  c1_i27 = 0;
  for (c1_i28 = 0; c1_i28 < 2; c1_i28++) {
    for (c1_i29 = 0; c1_i29 < 500; c1_i29++) {
      c1_u[c1_i29 + c1_i27] = c1_b_inData[c1_i29 + c1_i27];
    }

    c1_i27 += 500;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 500, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  static uint8_T c1_b_inData[921600];
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  static uint8_T c1_u[921600];
  const mxArray *c1_y = NULL;
  SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc1_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i30 = 0;
  for (c1_i31 = 0; c1_i31 < 3; c1_i31++) {
    c1_i32 = 0;
    for (c1_i33 = 0; c1_i33 < 640; c1_i33++) {
      for (c1_i34 = 0; c1_i34 < 480; c1_i34++) {
        c1_b_inData[(c1_i34 + c1_i32) + c1_i30] = (*(uint8_T (*)[921600])
          c1_inData)[(c1_i34 + c1_i32) + c1_i30];
      }

      c1_i32 += 480;
    }

    c1_i30 += 307200;
  }

  c1_i35 = 0;
  for (c1_i36 = 0; c1_i36 < 3; c1_i36++) {
    c1_i37 = 0;
    for (c1_i38 = 0; c1_i38 < 640; c1_i38++) {
      for (c1_i39 = 0; c1_i39 < 480; c1_i39++) {
        c1_u[(c1_i39 + c1_i37) + c1_i35] = c1_b_inData[(c1_i39 + c1_i37) +
          c1_i35];
      }

      c1_i37 += 480;
    }

    c1_i35 += 307200;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 3, 0U, 1U, 0U, 3, 480, 640, 3),
                FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc1_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_nid_cvst_pattern_trackingInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc1_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_nid_cvst_pattern_tracking_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[2];
  c1_ResolvedFunctionInfo (*c1_b_info)[2];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i40;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[2])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "round";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c1_b_info)[0].fileTimeLo = 1343812384U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c1_b_info)[1].name = "eml_scalar_round";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  (*c1_b_info)[1].fileTimeLo = 1307633238U;
  (*c1_b_info)[1].fileTimeHi = 0U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 2), FALSE);
  for (c1_i40 = 0; c1_i40 < 2; c1_i40++) {
    c1_r0 = &c1_info[c1_i40];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i40);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i40);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc1_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_b_emlrt_marshallIn
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i41;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i41, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i41;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc1_nid_cvst_pattern_trackingInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_c_emlrt_marshallIn
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance, const mxArray
   *c1_b_is_active_c1_nid_cvst_pattern_tracking, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_nid_cvst_pattern_tracking), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_nid_cvst_pattern_tracking);
  return c1_y;
}

static uint8_T c1_d_emlrt_marshallIn
  (SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_nid_cvst_pattern_trackingInstanceStruct
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

void sf_c1_nid_cvst_pattern_tracking_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1729877005U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(277880789U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(484845858U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1028712944U);
}

mxArray *sf_c1_nid_cvst_pattern_tracking_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Zjv41m3dTJCq2ifGYHfNF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(480);
      pr[1] = (double)(640);
      pr[2] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(480);
      pr[1] = (double)(640);
      pr[2] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_nid_cvst_pattern_tracking_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_nid_cvst_pattern_tracking(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c1_nid_cvst_pattern_tracking\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_nid_cvst_pattern_tracking_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
    chartInstance = (SFc1_nid_cvst_pattern_trackingInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _nid_cvst_pattern_trackingMachineNumber_,
           1,
           1,
           1,
           3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"I");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Centroid2");
          _SFD_SET_DATA_PROPS(2,1,1,0,"XYZ");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,524);
        _SFD_CV_INIT_EML_IF(0,1,0,260,281,-1,510);
        _SFD_CV_INIT_EML_FOR(0,1,0,244,256,514);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[3];
          dimVector[0]= 480;
          dimVector[1]= 640;
          dimVector[2]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 500;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[3];
          dimVector[0]= 480;
          dimVector[1]= 640;
          dimVector[2]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          uint8_T (*c1_I)[921600];
          real_T (*c1_Centroid2)[1000];
          real_T (*c1_XYZ)[921600];
          c1_XYZ = (real_T (*)[921600])ssGetInputPortSignal(chartInstance->S, 2);
          c1_Centroid2 = (real_T (*)[1000])ssGetInputPortSignal(chartInstance->S,
            1);
          c1_I = (uint8_T (*)[921600])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_I);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_Centroid2);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_XYZ);
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
  return "aSO3nIcM5zqEImZLJlrAxF";
}

static void sf_opaque_initialize_c1_nid_cvst_pattern_tracking(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_nid_cvst_pattern_trackingInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_nid_cvst_pattern_tracking
    ((SFc1_nid_cvst_pattern_trackingInstanceStruct*) chartInstanceVar);
  initialize_c1_nid_cvst_pattern_tracking
    ((SFc1_nid_cvst_pattern_trackingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_nid_cvst_pattern_tracking(void *chartInstanceVar)
{
  enable_c1_nid_cvst_pattern_tracking
    ((SFc1_nid_cvst_pattern_trackingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_nid_cvst_pattern_tracking(void
  *chartInstanceVar)
{
  disable_c1_nid_cvst_pattern_tracking
    ((SFc1_nid_cvst_pattern_trackingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_nid_cvst_pattern_tracking(void
  *chartInstanceVar)
{
  sf_c1_nid_cvst_pattern_tracking((SFc1_nid_cvst_pattern_trackingInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_nid_cvst_pattern_tracking
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_nid_cvst_pattern_tracking
    ((SFc1_nid_cvst_pattern_trackingInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_nid_cvst_pattern_tracking();/* state var info */
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

extern void sf_internal_set_sim_state_c1_nid_cvst_pattern_tracking(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_nid_cvst_pattern_tracking();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_nid_cvst_pattern_tracking
    ((SFc1_nid_cvst_pattern_trackingInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_nid_cvst_pattern_tracking
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_nid_cvst_pattern_tracking(S);
}

static void sf_opaque_set_sim_state_c1_nid_cvst_pattern_tracking(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_nid_cvst_pattern_tracking(S, st);
}

static void sf_opaque_terminate_c1_nid_cvst_pattern_tracking(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_nid_cvst_pattern_trackingInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_nid_cvst_pattern_tracking_optimization_info();
    }

    finalize_c1_nid_cvst_pattern_tracking
      ((SFc1_nid_cvst_pattern_trackingInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_nid_cvst_pattern_tracking
    ((SFc1_nid_cvst_pattern_trackingInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_nid_cvst_pattern_tracking(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_nid_cvst_pattern_tracking
      ((SFc1_nid_cvst_pattern_trackingInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_nid_cvst_pattern_tracking(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_nid_cvst_pattern_tracking_optimization_info();
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
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1677549946U));
  ssSetChecksum1(S,(2242087588U));
  ssSetChecksum2(S,(3248086844U));
  ssSetChecksum3(S,(788644411U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_nid_cvst_pattern_tracking(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_nid_cvst_pattern_tracking(SimStruct *S)
{
  SFc1_nid_cvst_pattern_trackingInstanceStruct *chartInstance;
  chartInstance = (SFc1_nid_cvst_pattern_trackingInstanceStruct *)utMalloc
    (sizeof(SFc1_nid_cvst_pattern_trackingInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_nid_cvst_pattern_trackingInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_nid_cvst_pattern_tracking;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_nid_cvst_pattern_tracking;
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

void c1_nid_cvst_pattern_tracking_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_nid_cvst_pattern_tracking(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_nid_cvst_pattern_tracking(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_nid_cvst_pattern_tracking(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_nid_cvst_pattern_tracking_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
