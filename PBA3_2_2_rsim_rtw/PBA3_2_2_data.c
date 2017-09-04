/*
 * PBA3_2_2_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PBA3_2_2".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Sep 04 20:40:32 2017
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PBA3_2_2.h"
#include "PBA3_2_2_private.h"

/* Block parameters (auto storage) */
P rtP = {
  10.0,                                /* Variable: M
                                        * Referenced by: '<Root>/Constant'
                                        */
  0.1,                                 /* Variable: c
                                        * Referenced by: '<Root>/Gain3'
                                        */
  9.81,                                /* Variable: g
                                        * Referenced by: '<Root>/Gain'
                                        */
  1.0,                                 /* Variable: l
                                        * Referenced by:
                                        *   '<Root>/Gain1'
                                        *   '<Root>/Gain4'
                                        *   '<Root>/Gain5'
                                        *   '<Root>/Gain7'
                                        */
  80.0,                                /* Variable: m
                                        * Referenced by:
                                        *   '<Root>/Constant'
                                        *   '<Root>/Gain'
                                        *   '<Root>/Gain2'
                                        *   '<Root>/Gain4'
                                        *   '<Root>/Gain8'
                                        */
  0.01,                                /* Variable: rho
                                        * Referenced by:
                                        *   '<Root>/Gain1'
                                        *   '<Root>/Gain8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  0.0                                  /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
};
