#ifndef __c3_plant_block_swing_catch_h__
#define __c3_plant_block_swing_catch_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c3_ResolvedFunctionInfo
#define typedef_c3_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c3_ResolvedFunctionInfo;

#endif                                 /*typedef_c3_ResolvedFunctionInfo*/

#ifndef typedef_SFc3_plant_block_swing_catchInstanceStruct
#define typedef_SFc3_plant_block_swing_catchInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
} SFc3_plant_block_swing_catchInstanceStruct;

#endif                                 /*typedef_SFc3_plant_block_swing_catchInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c3_plant_block_swing_catch_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_plant_block_swing_catch_get_check_sum(mxArray *plhs[]);
extern void c3_plant_block_swing_catch_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
