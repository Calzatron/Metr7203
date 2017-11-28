/* Include files */

#include "q_heli3d_skeleton_2012b_sfun.h"
#include "c1_q_heli3d_skeleton_2012b.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _q_heli3d_skeleton_2012bMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void q_heli3d_skeleton_2012b_initializer(void)
{
}

void q_heli3d_skeleton_2012b_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_q_heli3d_skeleton_2012b_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_q_heli3d_skeleton_2012b_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_q_heli3d_skeleton_2012b_process_testpoint_info_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char machineName[128];
  if (nrhs < 3 || !mxIsChar(prhs[0]) || !mxIsChar(prhs[1]))
    return 0;

  /* Possible call to get testpoint info. */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_testpoint_info"))
    return 0;
  mxGetString(prhs[1], machineName, sizeof(machineName)/sizeof(char));
  machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
  if (!strcmp(machineName, "q_heli3d_skeleton_2012b")) {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_q_heli3d_skeleton_2012b_get_testpoint_info(void);
        plhs[0] = sf_c1_q_heli3d_skeleton_2012b_get_testpoint_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }

    return 1;
  }

  return 0;

#else

  return 0;

#endif

}

unsigned int sf_q_heli3d_skeleton_2012b_process_check_sum_call( int nlhs,
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1324252664U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3091012561U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3105981865U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(437351586U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3030383482U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2759645701U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(91539799U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1698778109U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_q_heli3d_skeleton_2012b_get_check_sum(mxArray *plhs[]);
          sf_c1_q_heli3d_skeleton_2012b_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(784597580U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(508478511U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1608615269U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1082679159U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3654869386U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2338672722U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2117056500U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2965106415U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_q_heli3d_skeleton_2012b_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        if (strcmp(aiChksum, "Ks5rOroYG8DAxu8lInB9DE") == 0) {
          extern mxArray *sf_c1_q_heli3d_skeleton_2012b_get_autoinheritance_info
            (void);
          plhs[0] = sf_c1_q_heli3d_skeleton_2012b_get_autoinheritance_info();
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

unsigned int sf_q_heli3d_skeleton_2012b_get_eml_resolved_functions_info( int
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
     case 1:
      {
        extern const mxArray
          *sf_c1_q_heli3d_skeleton_2012b_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_q_heli3d_skeleton_2012b_get_eml_resolved_functions_info();
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

void q_heli3d_skeleton_2012b_debug_initialize(void)
{
  _q_heli3d_skeleton_2012bMachineNumber_ = sf_debug_initialize_machine(
    "q_heli3d_skeleton_2012b","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(_q_heli3d_skeleton_2012bMachineNumber_,0,
    0);
  sf_debug_set_machine_data_thresholds(_q_heli3d_skeleton_2012bMachineNumber_,0);
}

void q_heli3d_skeleton_2012b_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_q_heli3d_skeleton_2012b_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "q_heli3d_skeleton_2012b", "q_heli3d_skeleton_2012b");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_q_heli3d_skeleton_2012b_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
