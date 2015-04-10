/* Include files */

#include "nid_cvst_what_is_nid_modiv_sfun.h"
#include "nid_cvst_what_is_nid_modiv_sfun_debug_macros.h"
#include "c2_nid_cvst_what_is_nid_modiv.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _nid_cvst_what_is_nid_modivMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void nid_cvst_what_is_nid_modiv_initializer(void)
{
}

void nid_cvst_what_is_nid_modiv_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_nid_cvst_what_is_nid_modiv_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==2) {
    c2_nid_cvst_what_is_nid_modiv_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_nid_cvst_what_is_nid_modiv_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3693740692U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3209177242U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4221547023U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2656172470U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1403105206U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4287773642U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(555895852U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(58055110U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_nid_cvst_what_is_nid_modiv_get_check_sum(mxArray
            *plhs[]);
          sf_c2_nid_cvst_what_is_nid_modiv_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2258810623U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(298339321U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2587732746U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4083304268U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(498945743U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3332827787U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3465261191U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2327916972U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_nid_cvst_what_is_nid_modiv_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(aiChksum, "rNeoFONQCZqvqdSev2uyeB") == 0) {
          extern mxArray
            *sf_c2_nid_cvst_what_is_nid_modiv_get_autoinheritance_info(void);
          plhs[0] = sf_c2_nid_cvst_what_is_nid_modiv_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_nid_cvst_what_is_nid_modiv_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        extern const mxArray
          *sf_c2_nid_cvst_what_is_nid_modiv_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_nid_cvst_what_is_nid_modiv_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_nid_cvst_what_is_nid_modiv_third_party_uses_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(tpChksum, "8BbNvsO0fIqCUzO3siz4DB") == 0) {
          extern mxArray *sf_c2_nid_cvst_what_is_nid_modiv_third_party_uses_info
            (void);
          plhs[0] = sf_c2_nid_cvst_what_is_nid_modiv_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void nid_cvst_what_is_nid_modiv_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _nid_cvst_what_is_nid_modivMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"nid_cvst_what_is_nid_modiv","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _nid_cvst_what_is_nid_modivMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _nid_cvst_what_is_nid_modivMachineNumber_,0);
}

void nid_cvst_what_is_nid_modiv_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_nid_cvst_what_is_nid_modiv_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "nid_cvst_what_is_nid_modiv", "nid_cvst_what_is_nid_modiv");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_nid_cvst_what_is_nid_modiv_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
