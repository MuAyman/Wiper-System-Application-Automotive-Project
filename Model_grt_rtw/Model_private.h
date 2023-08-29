/*
 * Model_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Model".
 *
 * Model version              : 1.28
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Tue Aug 29 08:49:59 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Model_private_h_
#define RTW_HEADER_Model_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Model.h"
#include "Model_types.h"

extern real_T look1_binlg(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void Model_notyet(real_T rtu_In1, real_T *rty_Out1);
extern void Model_reached(real_T rtu_req, real_T *rty_DownPWM);
extern void Model_StepUp_Init(B_StepUp_Model_T *localB, DW_StepUp_Model_T
  *localDW);
extern void Model_StepUp(real_T rtu_req, real_T rtu_prev, real_T *rty_UpPWM,
  B_StepUp_Model_T *localB, DW_StepUp_Model_T *localDW);
extern void Model_StepDown_Init(B_StepDown_Model_T *localB, DW_StepDown_Model_T *
  localDW);
extern void Model_StepDown(real_T rtu_req, real_T rtu_prev, real_T *rty_DownPWM,
  B_StepDown_Model_T *localB, DW_StepDown_Model_T *localDW);
extern void Model_Keep(real_T rtu_prev, real_T *rty_KeepPWM);

#endif                                 /* RTW_HEADER_Model_private_h_ */
