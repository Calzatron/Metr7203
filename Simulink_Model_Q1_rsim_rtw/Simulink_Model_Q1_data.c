/*
 * Simulink_Model_Q1_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Simulink_Model_Q1".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Jul 31 22:53:40 2017
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Simulink_Model_Q1.h"
#include "Simulink_Model_Q1_private.h"

/* Block parameters (auto storage) */
P rtP = {
  0.1,                                 /* Variable: Ki
                                        * Referenced by: '<Root>/Integral Gain'
                                        */
  0.5,                                 /* Variable: Kp
                                        * Referenced by: '<Root>/Proportional Gain'
                                        */
  200.0,                               /* Variable: Tm
                                        * Referenced by: '<Root>/Gain1'
                                        */
  0.35,                                /* Variable: beta
                                        * Referenced by: '<Root>/Vr3'
                                        */
  1200.0,                              /* Variable: m
                                        * Referenced by: '<Root>/Gain'
                                        */
  450.0,                               /* Variable: wm
                                        * Referenced by: '<Root>/Vr1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Vr2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/V_Reg'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/V_Reg'
                                        */
  20.0,                                /* Expression: 20
                                        * Referenced by: '<Root>/V_Reg'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  0.0                                  /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
};
