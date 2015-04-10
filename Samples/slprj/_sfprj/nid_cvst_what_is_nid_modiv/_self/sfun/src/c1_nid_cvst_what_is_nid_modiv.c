/* Include files */

#include <stddef.h>
#include "blas.h"
#include "nid_cvst_what_is_nid_modiv_sfun.h"
#include "c1_nid_cvst_what_is_nid_modiv.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "nid_cvst_what_is_nid_modiv_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[7] = { "idx", "nargin", "nargout", "u",
  "x", "y", "z" };

/* Function Declarations */
static void initialize_c1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance);
static void initialize_params_c1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance);
static void enable_c1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance);
static void disable_c1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance);
static void set_sim_state_c1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance, const mxArray
   *c1_st);
static void finalize_c1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance);
static void sf_c1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance);
static void initSimStructsc1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance);
static void registerMessagesc1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_nid_cvst_what_is_nid_modivInstanceStruct *
  chartInstance, const mxArray *c1_z, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_d_emlrt_marshallIn
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance, const mxArray
   *c1_b_is_active_c1_nid_cvst_what_is_nid_modiv, const char_T *c1_identifier);
static uint8_T c1_e_emlrt_marshallIn
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_nid_cvst_what_is_nid_modivInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_nid_cvst_what_is_nid_modiv = 0U;
}

static void initialize_params_c1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance)
{
}

static void enable_c1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  uint8_T c1_d_hoistedGlobal;
  uint8_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T *c1_x;
  real_T *c1_f_y;
  real_T *c1_z;
  c1_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_f_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(4), FALSE);
  c1_hoistedGlobal = *c1_x;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_f_y;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *c1_z;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = chartInstance->c1_is_active_c1_nid_cvst_what_is_nid_modiv;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_x;
  real_T *c1_y;
  real_T *c1_z;
  c1_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_x = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "x");
  *c1_y = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "y");
  *c1_z = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
    "z");
  chartInstance->c1_is_active_c1_nid_cvst_what_is_nid_modiv =
    c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
    "is_active_c1_nid_cvst_what_is_nid_modiv");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_nid_cvst_what_is_nid_modiv(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance)
{
}

static void sf_c1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance)
{
  int32_T c1_i0;
  int32_T c1_i1;
  real_T c1_u[60];
  uint32_T c1_debug_family_var_map[7];
  real_T c1_idx;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 3.0;
  real_T c1_x;
  real_T c1_y;
  real_T c1_z;
  real_T *c1_b_x;
  real_T *c1_b_y;
  real_T *c1_b_z;
  real_T (*c1_b_u)[60];
  c1_b_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_u = (real_T (*)[60])ssGetInputPortSignal(chartInstance->S, 0);
  c1_b_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_b_x, 0U);
  for (c1_i0 = 0; c1_i0 < 60; c1_i0++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_u)[c1_i0], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_b_y, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_b_z, 3U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i1 = 0; c1_i1 < 60; c1_i1++) {
    c1_u[c1_i1] = (*c1_b_u)[c1_i1];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_idx, 0U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_u, 3U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_x, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_y, 5U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_z, 6U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  CV_EML_IF(0, 1, 0, TRUE);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_idx = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  c1_x = c1_u[2];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_y = c1_u[22];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
  c1_z = c1_u[42];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -15);
  _SFD_SYMBOL_SCOPE_POP();
  *c1_b_x = c1_x;
  *c1_b_y = c1_y;
  *c1_b_z = c1_z;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_nid_cvst_what_is_nid_modivMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance)
{
}

static void registerMessagesc1_nid_cvst_what_is_nid_modiv
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance;
  chartInstance = (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_nid_cvst_what_is_nid_modivInstanceStruct *
  chartInstance, const mxArray *c1_z, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_z), &c1_thisId);
  sf_mex_destroy(&c1_z);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
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
  const mxArray *c1_z;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance;
  chartInstance = (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *)
    chartInstanceVoid;
  c1_z = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_z), &c1_thisId);
  sf_mex_destroy(&c1_z);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  real_T c1_b_inData[60];
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  real_T c1_u[60];
  const mxArray *c1_y = NULL;
  SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance;
  chartInstance = (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i2 = 0;
  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    for (c1_i4 = 0; c1_i4 < 20; c1_i4++) {
      c1_b_inData[c1_i4 + c1_i2] = (*(real_T (*)[60])c1_inData)[c1_i4 + c1_i2];
    }

    c1_i2 += 20;
  }

  c1_i5 = 0;
  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    for (c1_i7 = 0; c1_i7 < 20; c1_i7++) {
      c1_u[c1_i7 + c1_i5] = c1_b_inData[c1_i7 + c1_i5];
    }

    c1_i5 += 20;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 3, 1, 20, 3),
                FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_nid_cvst_what_is_nid_modiv_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[7];
  c1_ResolvedFunctionInfo (*c1_b_info)[7];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i8;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[7])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "length";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  (*c1_b_info)[0].fileTimeLo = 1303128206U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  (*c1_b_info)[1].name = "eml_index_class";
  (*c1_b_info)[1].dominantType = "";
  (*c1_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c1_b_info)[1].fileTimeLo = 1323148978U;
  (*c1_b_info)[1].fileTimeHi = 0U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  (*c1_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  (*c1_b_info)[2].name = "eml_int_forloop_overflow_check";
  (*c1_b_info)[2].dominantType = "";
  (*c1_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  (*c1_b_info)[2].fileTimeLo = 1346492340U;
  (*c1_b_info)[2].fileTimeHi = 0U;
  (*c1_b_info)[2].mFileTimeLo = 0U;
  (*c1_b_info)[2].mFileTimeHi = 0U;
  (*c1_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  (*c1_b_info)[3].name = "intmax";
  (*c1_b_info)[3].dominantType = "char";
  (*c1_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  (*c1_b_info)[3].fileTimeLo = 1311237316U;
  (*c1_b_info)[3].fileTimeHi = 0U;
  (*c1_b_info)[3].mFileTimeLo = 0U;
  (*c1_b_info)[3].mFileTimeHi = 0U;
  (*c1_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  (*c1_b_info)[4].name = "coder.internal.indexIntRelop";
  (*c1_b_info)[4].dominantType = "";
  (*c1_b_info)[4].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  (*c1_b_info)[4].fileTimeLo = 1326706722U;
  (*c1_b_info)[4].fileTimeHi = 0U;
  (*c1_b_info)[4].mFileTimeLo = 0U;
  (*c1_b_info)[4].mFileTimeHi = 0U;
  (*c1_b_info)[5].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass";
  (*c1_b_info)[5].name = "eml_float_model";
  (*c1_b_info)[5].dominantType = "char";
  (*c1_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  (*c1_b_info)[5].fileTimeLo = 1326706396U;
  (*c1_b_info)[5].fileTimeHi = 0U;
  (*c1_b_info)[5].mFileTimeLo = 0U;
  (*c1_b_info)[5].mFileTimeHi = 0U;
  (*c1_b_info)[6].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass";
  (*c1_b_info)[6].name = "intmin";
  (*c1_b_info)[6].dominantType = "char";
  (*c1_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  (*c1_b_info)[6].fileTimeLo = 1311237318U;
  (*c1_b_info)[6].fileTimeHi = 0U;
  (*c1_b_info)[6].mFileTimeLo = 0U;
  (*c1_b_info)[6].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 7), FALSE);
  for (c1_i8 = 0; c1_i8 < 7; c1_i8++) {
    c1_r0 = &c1_info[c1_i8];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i8);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i8);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance;
  chartInstance = (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i9;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i9, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i9;
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
  SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance;
  chartInstance = (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_d_emlrt_marshallIn
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance, const mxArray
   *c1_b_is_active_c1_nid_cvst_what_is_nid_modiv, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_nid_cvst_what_is_nid_modiv), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_nid_cvst_what_is_nid_modiv);
  return c1_y;
}

static uint8_T c1_e_emlrt_marshallIn
  (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_nid_cvst_what_is_nid_modivInstanceStruct *
  chartInstance)
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

void sf_c1_nid_cvst_what_is_nid_modiv_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(192749583U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1251976778U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2069468335U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1332147989U);
}

mxArray *sf_c1_nid_cvst_what_is_nid_modiv_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("RcNGiOsLoGIPEwTSaIpUgB");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_nid_cvst_what_is_nid_modiv_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_nid_cvst_what_is_nid_modiv(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[6],T\"x\",},{M[1],M[5],T\"y\",},{M[1],M[7],T\"z\",},{M[8],M[0],T\"is_active_c1_nid_cvst_what_is_nid_modiv\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_nid_cvst_what_is_nid_modiv_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance;
    chartInstance = (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _nid_cvst_what_is_nid_modivMachineNumber_,
           1,
           1,
           1,
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
          init_script_number_translation
            (_nid_cvst_what_is_nid_modivMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _nid_cvst_what_is_nid_modivMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _nid_cvst_what_is_nid_modivMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"x");
          _SFD_SET_DATA_PROPS(1,1,1,0,"u");
          _SFD_SET_DATA_PROPS(2,2,0,1,"y");
          _SFD_SET_DATA_PROPS(3,2,0,1,"z");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,168);
        _SFD_CV_INIT_EML_IF(0,1,0,44,62,89,119);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          unsigned int dimVector[3];
          dimVector[0]= 1;
          dimVector[1]= 20;
          dimVector[2]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_x;
          real_T *c1_y;
          real_T *c1_z;
          real_T (*c1_u)[60];
          c1_z = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_u = (real_T (*)[60])ssGetInputPortSignal(chartInstance->S, 0);
          c1_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_x);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_u);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_y);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_z);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _nid_cvst_what_is_nid_modivMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "HW7ytTe6NGNwaPQKspI9JD";
}

static void sf_opaque_initialize_c1_nid_cvst_what_is_nid_modiv(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_nid_cvst_what_is_nid_modivInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_nid_cvst_what_is_nid_modiv
    ((SFc1_nid_cvst_what_is_nid_modivInstanceStruct*) chartInstanceVar);
  initialize_c1_nid_cvst_what_is_nid_modiv
    ((SFc1_nid_cvst_what_is_nid_modivInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_nid_cvst_what_is_nid_modiv(void
  *chartInstanceVar)
{
  enable_c1_nid_cvst_what_is_nid_modiv
    ((SFc1_nid_cvst_what_is_nid_modivInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_nid_cvst_what_is_nid_modiv(void
  *chartInstanceVar)
{
  disable_c1_nid_cvst_what_is_nid_modiv
    ((SFc1_nid_cvst_what_is_nid_modivInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_nid_cvst_what_is_nid_modiv(void
  *chartInstanceVar)
{
  sf_c1_nid_cvst_what_is_nid_modiv
    ((SFc1_nid_cvst_what_is_nid_modivInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_nid_cvst_what_is_nid_modiv
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_nid_cvst_what_is_nid_modiv
    ((SFc1_nid_cvst_what_is_nid_modivInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_nid_cvst_what_is_nid_modiv();/* state var info */
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

extern void sf_internal_set_sim_state_c1_nid_cvst_what_is_nid_modiv(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_nid_cvst_what_is_nid_modiv();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_nid_cvst_what_is_nid_modiv
    ((SFc1_nid_cvst_what_is_nid_modivInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_nid_cvst_what_is_nid_modiv
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_nid_cvst_what_is_nid_modiv(S);
}

static void sf_opaque_set_sim_state_c1_nid_cvst_what_is_nid_modiv(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_nid_cvst_what_is_nid_modiv(S, st);
}

static void sf_opaque_terminate_c1_nid_cvst_what_is_nid_modiv(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_nid_cvst_what_is_nid_modivInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_nid_cvst_what_is_nid_modiv_optimization_info();
    }

    finalize_c1_nid_cvst_what_is_nid_modiv
      ((SFc1_nid_cvst_what_is_nid_modivInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_nid_cvst_what_is_nid_modiv
    ((SFc1_nid_cvst_what_is_nid_modivInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_nid_cvst_what_is_nid_modiv(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_nid_cvst_what_is_nid_modiv
      ((SFc1_nid_cvst_what_is_nid_modivInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_nid_cvst_what_is_nid_modiv(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_nid_cvst_what_is_nid_modiv_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1804212328U));
  ssSetChecksum1(S,(457497164U));
  ssSetChecksum2(S,(2555297736U));
  ssSetChecksum3(S,(1283386133U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_nid_cvst_what_is_nid_modiv(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_nid_cvst_what_is_nid_modiv(SimStruct *S)
{
  SFc1_nid_cvst_what_is_nid_modivInstanceStruct *chartInstance;
  chartInstance = (SFc1_nid_cvst_what_is_nid_modivInstanceStruct *)utMalloc
    (sizeof(SFc1_nid_cvst_what_is_nid_modivInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_nid_cvst_what_is_nid_modivInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_nid_cvst_what_is_nid_modiv;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_nid_cvst_what_is_nid_modiv;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_nid_cvst_what_is_nid_modiv;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_nid_cvst_what_is_nid_modiv;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_nid_cvst_what_is_nid_modiv;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_nid_cvst_what_is_nid_modiv;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_nid_cvst_what_is_nid_modiv;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_nid_cvst_what_is_nid_modiv;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_nid_cvst_what_is_nid_modiv;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_nid_cvst_what_is_nid_modiv;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_nid_cvst_what_is_nid_modiv;
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

void c1_nid_cvst_what_is_nid_modiv_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_nid_cvst_what_is_nid_modiv(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_nid_cvst_what_is_nid_modiv(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_nid_cvst_what_is_nid_modiv(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_nid_cvst_what_is_nid_modiv_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
