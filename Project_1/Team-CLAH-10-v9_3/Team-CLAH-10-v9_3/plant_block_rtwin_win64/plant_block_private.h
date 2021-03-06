/*
 * plant_block_private.h
 *
 * Code generation for model "plant_block".
 *
 * Model version              : 1.147
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Wed Aug 30 09:38:31 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_plant_block_private_h_
#define RTW_HEADER_plant_block_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern void ECPDSPDriver(SimStruct *rts);

/* private model entry point functions */
extern void plant_block_derivatives(void);

#endif                                 /* RTW_HEADER_plant_block_private_h_ */
