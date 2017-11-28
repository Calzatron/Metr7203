/* Include files */

#include "plant_block_swing_catch_working_v0_sfun.h"
#include "plant_block_swing_catch_working_v0_sfun_debug_macros.h"
#include "c1_plant_block_swing_catch_working_v0.h"
#include "c3_plant_block_swing_catch_working_v0.h"
#include "c5_plant_block_swing_catch_working_v0.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _plant_block_swing_catch_working_v0MachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void plant_block_swing_catch_working_v0_initializer(void)
{
}

void plant_block_swing_catch_working_v0_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_plant_block_swing_catch_working_v0_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_plant_block_swing_catch_working_v0_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_plant_block_swing_catch_working_v0_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_plant_block_swing_catch_working_v0_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

unsigned int sf_plant_block_swing_catch_working_v0_process_testpoint_info_call
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
  if (!strcmp(machineName, "plant_block_swing_catch_working_v0")) {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray
          *sf_c1_plant_block_swing_catch_working_v0_get_testpoint_info(void);
        plhs[0] = sf_c1_plant_block_swing_catch_working_v0_get_testpoint_info();
        break;
      }

     case 3:
      {
        extern mxArray
          *sf_c3_plant_block_swing_catch_working_v0_get_testpoint_info(void);
        plhs[0] = sf_c3_plant_block_swing_catch_working_v0_get_testpoint_info();
        break;
      }

     case 5:
      {
        extern mxArray
          *sf_c5_plant_block_swing_catch_working_v0_get_testpoint_info(void);
        plhs[0] = sf_c5_plant_block_swing_catch_working_v0_get_testpoint_info();
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

unsigned int sf_plant_block_swing_catch_working_v0_process_check_sum_call( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(225434918U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3185328147U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4058442713U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3378978689U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3670043127U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3838276096U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1857917138U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(962957004U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_plant_block_swing_catch_working_v0_get_check_sum
            (mxArray *plhs[]);
          sf_c1_plant_block_swing_catch_working_v0_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_plant_block_swing_catch_working_v0_get_check_sum
            (mxArray *plhs[]);
          sf_c3_plant_block_swing_catch_working_v0_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_plant_block_swing_catch_working_v0_get_check_sum
            (mxArray *plhs[]);
          sf_c5_plant_block_swing_catch_working_v0_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2150923104U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1225982459U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3886974127U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3860626108U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_plant_block_swing_catch_working_v0_autoinheritance_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "fy9nIPjt8SPEEwys4AWZL") == 0) {
          extern mxArray
            *sf_c1_plant_block_swing_catch_working_v0_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c1_plant_block_swing_catch_working_v0_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "FPE6Pft4t1iGnHD6AB6OHC") == 0) {
          extern mxArray
            *sf_c3_plant_block_swing_catch_working_v0_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c3_plant_block_swing_catch_working_v0_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "B22lCBWxfyguqqmqNd0VpD") == 0) {
          extern mxArray
            *sf_c5_plant_block_swing_catch_working_v0_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c5_plant_block_swing_catch_working_v0_get_autoinheritance_info();
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

unsigned int
  sf_plant_block_swing_catch_working_v0_get_eml_resolved_functions_info( int
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
          *sf_c1_plant_block_swing_catch_working_v0_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_plant_block_swing_catch_working_v0_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_plant_block_swing_catch_working_v0_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_plant_block_swing_catch_working_v0_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_plant_block_swing_catch_working_v0_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_plant_block_swing_catch_working_v0_get_eml_resolved_functions_info
          ();
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

unsigned int sf_plant_block_swing_catch_working_v0_third_party_uses_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        if (strcmp(tpChksum, "Z2LNFB4NbMpOxy0VWHVE9G") == 0) {
          extern mxArray
            *sf_c1_plant_block_swing_catch_working_v0_third_party_uses_info(void);
          plhs[0] =
            sf_c1_plant_block_swing_catch_working_v0_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "qo4PAMhYobIORWoIzWe5oE") == 0) {
          extern mxArray
            *sf_c3_plant_block_swing_catch_working_v0_third_party_uses_info(void);
          plhs[0] =
            sf_c3_plant_block_swing_catch_working_v0_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "e1151AUIvQqoZyMZqNkE1E") == 0) {
          extern mxArray
            *sf_c5_plant_block_swing_catch_working_v0_third_party_uses_info(void);
          plhs[0] =
            sf_c5_plant_block_swing_catch_working_v0_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void plant_block_swing_catch_working_v0_debug_initialize(struct
  SfDebugInstanceStruct* debugInstance)
{
  _plant_block_swing_catch_working_v0MachineNumber_ =
    sf_debug_initialize_machine(debugInstance,
    "plant_block_swing_catch_working_v0","sfun",0,3,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _plant_block_swing_catch_working_v0MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _plant_block_swing_catch_working_v0MachineNumber_,0);
}

void plant_block_swing_catch_working_v0_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_plant_block_swing_catch_working_v0_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "plant_block_swing_catch_working_v0", "plant_block_swing_catch_working_v0");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_plant_block_swing_catch_working_v0_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
