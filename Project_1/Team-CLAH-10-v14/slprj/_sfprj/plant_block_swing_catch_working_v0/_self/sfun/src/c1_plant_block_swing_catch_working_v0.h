#ifndef __c1_plant_block_swing_catch_working_v0_h__
#define __c1_plant_block_swing_catch_working_v0_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc1_plant_block_swing_catch_working_v0InstanceStruct
#define typedef_SFc1_plant_block_swing_catch_working_v0InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_plant_block_swing_catch_working_v0InstanceStruct;

#endif                                 /*typedef_SFc1_plant_block_swing_catch_working_v0InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_plant_block_swing_catch_working_v0_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_plant_block_swing_catch_working_v0_get_check_sum(mxArray *
  plhs[]);
extern void c1_plant_block_swing_catch_working_v0_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
