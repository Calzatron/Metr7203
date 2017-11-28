/*
 * Helicopter_Simulink_Model_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Helicopter_Simulink_Model".
 *
 * Model version              : 1.14
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed Oct 25 14:31:05 2017
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Helicopter_Simulink_Model.h"
#include "Helicopter_Simulink_Model_private.h"

/* Block parameters (auto storage) */
P rtP = {
  /*  Variable: A
   * Referenced by:
   *   '<Root>/A'
   *   '<Root>/State-Space'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.2303958542095543,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0 },

  /*  Variable: B
   * Referenced by:
   *   '<Root>/B'
   *   '<Root>/State-Space'
   */
  { 0.0, 0.0, 0.0, 0.085794874947817359, 0.58101432973052292, 0.0, 0.0, 0.0, 0.0,
    0.085794874947817359, -0.58101432973052292, 0.0 },

  /*  Variable: C
   * Referenced by:
   *   '<Root>/C'
   *   '<Root>/State-Space'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 },

  /*  Variable: C_0
   * Referenced by: '<Root>/C_0'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Variable: K_i
   * Referenced by: '<Root>/Ki'
   */
  { 8.5943669269623513, 8.5943669269623388, -8.594366926962417,
    8.5943669269624241 },

  /*  Variable: K_r
   * Referenced by: '<Root>/Kr'
   */
  { 19.296513291742293, 19.29651329174234, -25.942402888878416,
    25.94240288887843 },

  /*  Variable: K_sf
   * Referenced by: '<Root>/State-feedback'
   */
  { 19.29651329174229, 19.296513291742343, 33.54283978208624,
    -33.542839782086247, -25.942402888878419, 25.942402888878437,
    16.181659169266826, 16.181659169266872, 12.249916225653168,
    -12.249916225653175, -39.139113102805808, 39.139113102805837 },

  /*  Variable: L
   * Referenced by: '<Root>/Gain2'
   */
  { 49.074320495248415, -2.2842403711137891, 4.0997928030222459,
    696.45575939623666, 71.838812116389391, 22.574604511512945,
    7.0566831238595764, 57.352608354792039, 2.23954052223196, 99.065365050504454,
    985.985874720492, 179.2434775506585, -3.23472146004509, 6.22915224936693,
    49.573071149959404, 30.420227330620982, 148.73459122892805,
    747.11174872927074 },
  -0.0002,                             /* Expression: -0.0002
                                        * Referenced by: '<Root>/Sensor Noise'
                                        */
  0.0002,                              /* Expression: 0.0002
                                        * Referenced by: '<Root>/Sensor Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Sensor Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/State-Space'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  0.3,                                 /* Expression: 0.3
                                        * Referenced by: '<Root>/Step'
                                        */
  30.0,                                /* Expression: 30
                                        * Referenced by: '<Root>/Step1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  -0.3,                                /* Expression: -0.3
                                        * Referenced by: '<Root>/Step1'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Step2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step2'
                                        */
  0.8,                                 /* Expression: 0.8
                                        * Referenced by: '<Root>/Step2'
                                        */
  30.0,                                /* Expression: 30
                                        * Referenced by: '<Root>/Step3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step3'
                                        */
  -0.8,                                /* Expression: -0.8
                                        * Referenced by: '<Root>/Step3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  0.7,                                 /* Expression: 0.7
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  -0.7                                 /* Expression: -0.7
                                        * Referenced by: '<Root>/Integrator1'
                                        */
};
