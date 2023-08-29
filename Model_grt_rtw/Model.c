/*
 * Model.c
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

#include "Model.h"
#include "rtwtypes.h"
#include "Model_private.h"
#include <string.h>

/* Block signals (default storage) */
B_Model_T Model_B;

/* Block states (default storage) */
DW_Model_T Model_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Model_T Model_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Model_T Model_Y;

/* Real-time model */
static RT_MODEL_Model_T Model_M_;
RT_MODEL_Model_T *const Model_M = &Model_M_;
static void rate_scheduler(void);
real_T look1_binlg(real_T u0, const real_T bp0[], const real_T table[], uint32_T
                   maxIndex)
{
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  /* Binary Search */
  bpIdx = maxIndex >> 1U;
  iLeft = 0U;
  iRght = maxIndex;
  while (iRght - iLeft > 1U) {
    if (u0 < bp0[bpIdx]) {
      iRght = bpIdx;
    } else {
      iLeft = bpIdx;
    }

    bpIdx = (iRght + iLeft) >> 1U;
  }

  real_T yL_0d0;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[iLeft];
  return (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]) * (table[iLeft + 1U]
    - yL_0d0) + yL_0d0;
}

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Model_M->Timing.TaskCounters.TID[1])++;
  if ((Model_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [1.0s, 0.0s] */
    Model_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S23>/not yet'
 *    '<S22>/not yet'
 *    '<S15>/not yet'
 *    '<S14>/not yet'
 *    '<S3>/Low'
 *    '<S3>/High'
 *    '<S3>/off'
 */
void Model_notyet(real_T rtu_In1, real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S26>/In1' */
  *rty_Out1 = rtu_In1;
}

/*
 * Output and update for action system:
 *    '<S23>/reached'
 *    '<S22>/reached'
 *    '<S15>/reached'
 *    '<S14>/reached'
 */
void Model_reached(real_T rtu_req, real_T *rty_DownPWM)
{
  /* SignalConversion generated from: '<S27>/req' */
  *rty_DownPWM = rtu_req;
}

/*
 * System initialize for action system:
 *    '<S20>/StepUp'
 *    '<S12>/StepUp'
 */
void Model_StepUp_Init(B_StepUp_Model_T *localB, DW_StepUp_Model_T *localDW)
{
  /* InitializeConditions for Delay: '<S23>/Resettable Delay' */
  localDW->icLoad = true;

  /* SystemInitialize for Merge: '<S23>/Merge' */
  localB->Merge = 0.0;
}

/*
 * Output and update for action system:
 *    '<S20>/StepUp'
 *    '<S12>/StepUp'
 */
void Model_StepUp(real_T rtu_req, real_T rtu_prev, real_T *rty_UpPWM,
                  B_StepUp_Model_T *localB, DW_StepUp_Model_T *localDW)
{
  /* Delay: '<S23>/Resettable Delay' */
  if (localDW->icLoad) {
    localDW->ResettableDelay_DSTATE = rtu_prev;
  }

  /* If: '<S23>/If prev reaches req' incorporates:
   *  Constant: '<S23>/Constant'
   *  Delay: '<S23>/Resettable Delay'
   *  Sum: '<S23>/Add1'
   */
  if (localDW->ResettableDelay_DSTATE + 0.01 < rtu_req) {
    /* Outputs for IfAction SubSystem: '<S23>/not yet' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    Model_notyet(localDW->ResettableDelay_DSTATE + 0.01, &localB->Merge);

    /* End of Outputs for SubSystem: '<S23>/not yet' */
  } else {
    /* Outputs for IfAction SubSystem: '<S23>/reached' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    Model_reached(rtu_req, &localB->Merge);

    /* End of Outputs for SubSystem: '<S23>/reached' */
  }

  /* End of If: '<S23>/If prev reaches req' */

  /* SignalConversion generated from: '<S23>/UpPWM' */
  *rty_UpPWM = localB->Merge;

  /* Update for Delay: '<S23>/Resettable Delay' */
  localDW->icLoad = false;
  localDW->ResettableDelay_DSTATE = localB->Merge;
}

/*
 * System initialize for action system:
 *    '<S20>/StepDown'
 *    '<S12>/StepDown'
 */
void Model_StepDown_Init(B_StepDown_Model_T *localB, DW_StepDown_Model_T
  *localDW)
{
  /* InitializeConditions for Delay: '<S22>/Resettable Delay' */
  localDW->icLoad = true;

  /* SystemInitialize for Merge: '<S22>/Merge' */
  localB->Merge = 0.0;
}

/*
 * Output and update for action system:
 *    '<S20>/StepDown'
 *    '<S12>/StepDown'
 */
void Model_StepDown(real_T rtu_req, real_T rtu_prev, real_T *rty_DownPWM,
                    B_StepDown_Model_T *localB, DW_StepDown_Model_T *localDW)
{
  /* Delay: '<S22>/Resettable Delay' */
  if (localDW->icLoad) {
    localDW->ResettableDelay_DSTATE = rtu_prev;
  }

  /* If: '<S22>/If prev reaches req' incorporates:
   *  Constant: '<S22>/Constant'
   *  Delay: '<S22>/Resettable Delay'
   *  Sum: '<S22>/Add'
   */
  if (localDW->ResettableDelay_DSTATE - 0.01 > rtu_req) {
    /* Outputs for IfAction SubSystem: '<S22>/not yet' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    Model_notyet(localDW->ResettableDelay_DSTATE - 0.01, &localB->Merge);

    /* End of Outputs for SubSystem: '<S22>/not yet' */
  } else {
    /* Outputs for IfAction SubSystem: '<S22>/reached' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    Model_reached(rtu_req, &localB->Merge);

    /* End of Outputs for SubSystem: '<S22>/reached' */
  }

  /* End of If: '<S22>/If prev reaches req' */

  /* SignalConversion generated from: '<S22>/DownPWM' */
  *rty_DownPWM = localB->Merge;

  /* Update for Delay: '<S22>/Resettable Delay' */
  localDW->icLoad = false;
  localDW->ResettableDelay_DSTATE = localB->Merge;
}

/*
 * Output and update for action system:
 *    '<S20>/Keep'
 *    '<S12>/Keep'
 */
void Model_Keep(real_T rtu_prev, real_T *rty_KeepPWM)
{
  /* SignalConversion generated from: '<S21>/prev' */
  *rty_KeepPWM = rtu_prev;
}

/* Model step function */
void Model_step(void)
{
  real_T rtb_Merge;
  real_T rtb_Switch;

  /* S-Function (fcgen): '<S1>/Ts = 10e-3' incorporates:
   *  SubSystem: '<S1>/RainSnsrWiperMot'
   */
  /* SwitchCase: '<S3>/Switch Case' incorporates:
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant3'
   *  Constant: '<S3>/Constant4'
   *  Inport: '<Root>/WiperMod'
   */
  switch ((int32_T)Model_U.WiperMod) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S3>/Auto' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Lookup_n-D: '<S4>/1-D Lookup Table' incorporates:
     *  Inport: '<Root>/WiperSpdReq'
     */
    rtb_Merge = look1_binlg(Model_U.WiperSpdReq,
      Model_ConstP.uDLookupTable_bp01Data, Model_ConstP.uDLookupTable_tableData,
      7U);

    /* Switch: '<S11>/Switch' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion'
     *  UnitDelay: '<S11>/Unit Delay'
     */
    if (rtb_Merge != 0.0) {
      rtb_Switch = rtb_Merge;
    } else {
      rtb_Switch = Model_DW.UnitDelay_DSTATE;
    }

    /* End of Switch: '<S11>/Switch' */

    /* Delay: '<S10>/Resettable Delay' */
    if (Model_DW.icLoad_i) {
      Model_DW.ResettableDelay_DSTATE_h = rtb_Switch;
    }

    /* If: '<S12>/If' incorporates:
     *  Delay: '<S10>/Resettable Delay'
     */
    if (rtb_Switch > Model_DW.ResettableDelay_DSTATE_h) {
      /* Outputs for IfAction SubSystem: '<S12>/StepUp' incorporates:
       *  ActionPort: '<S15>/StepUp'
       */
      Model_StepUp(rtb_Switch, Model_DW.ResettableDelay_DSTATE_h, &Model_B.Merge,
                   &Model_B.StepUp_p, &Model_DW.StepUp_p);

      /* End of Outputs for SubSystem: '<S12>/StepUp' */
    } else if (rtb_Switch < Model_DW.ResettableDelay_DSTATE_h) {
      /* Outputs for IfAction SubSystem: '<S12>/StepDown' incorporates:
       *  ActionPort: '<S14>/StepDown'
       */
      Model_StepDown(rtb_Switch, Model_DW.ResettableDelay_DSTATE_h,
                     &Model_B.Merge, &Model_B.StepDown_p, &Model_DW.StepDown_p);

      /* End of Outputs for SubSystem: '<S12>/StepDown' */
    } else {
      /* Outputs for IfAction SubSystem: '<S12>/Keep' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      Model_Keep(Model_DW.ResettableDelay_DSTATE_h, &Model_B.Merge);

      /* End of Outputs for SubSystem: '<S12>/Keep' */
    }

    /* End of If: '<S12>/If' */

    /* SignalConversion generated from: '<S4>/AutoPWM' */
    rtb_Merge = Model_B.Merge;

    /* Update for UnitDelay: '<S11>/Unit Delay' */
    Model_DW.UnitDelay_DSTATE = rtb_Switch;

    /* Update for Delay: '<S10>/Resettable Delay' */
    Model_DW.icLoad_i = false;
    Model_DW.ResettableDelay_DSTATE_h = Model_B.Merge;

    /* End of Outputs for SubSystem: '<S3>/Auto' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S3>/Low' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    Model_notyet(0.4, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S3>/Low' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S3>/High' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    Model_notyet(0.7, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S3>/High' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S3>/off' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    Model_notyet(0.0, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S3>/off' */
    break;
  }

  /* End of SwitchCase: '<S3>/Switch Case' */

  /* Delay: '<S7>/Resettable Delay' */
  if (Model_DW.icLoad) {
    Model_DW.ResettableDelay_DSTATE = rtb_Merge;
  }

  /* If: '<S20>/If' incorporates:
   *  Delay: '<S7>/Resettable Delay'
   */
  if (rtb_Merge > Model_DW.ResettableDelay_DSTATE) {
    /* Outputs for IfAction SubSystem: '<S20>/StepUp' incorporates:
     *  ActionPort: '<S23>/StepUp'
     */
    Model_StepUp(rtb_Merge, Model_DW.ResettableDelay_DSTATE, &rtb_Switch,
                 &Model_B.StepUp, &Model_DW.StepUp);

    /* End of Outputs for SubSystem: '<S20>/StepUp' */
  } else if (rtb_Merge < Model_DW.ResettableDelay_DSTATE) {
    /* Outputs for IfAction SubSystem: '<S20>/StepDown' incorporates:
     *  ActionPort: '<S22>/StepDown'
     */
    Model_StepDown(rtb_Merge, Model_DW.ResettableDelay_DSTATE, &rtb_Switch,
                   &Model_B.StepDown, &Model_DW.StepDown);

    /* End of Outputs for SubSystem: '<S20>/StepDown' */
  } else {
    /* Outputs for IfAction SubSystem: '<S20>/Keep' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    Model_Keep(Model_DW.ResettableDelay_DSTATE, &rtb_Switch);

    /* End of Outputs for SubSystem: '<S20>/Keep' */
  }

  /* End of If: '<S20>/If' */

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<S2>/off'
   *  Inport: '<Root>/RainSnsrErr'
   */
  if (Model_U.RainSnsr > 0.0) {
    rtb_Merge = 0.0;
  } else {
    rtb_Merge = rtb_Switch;
  }

  /* Outport: '<Root>/WiperMotPWMDutyCyc' incorporates:
   *  Gain: '<S2>/MaxPWM'
   *  Switch: '<S2>/Switch1'
   */
  Model_Y.WiperMotPWMDutyCyc = 255.0 * rtb_Merge;

  /* Outport: '<Root>/WiperActv' incorporates:
   *  Outport: '<Root>/WiperMotPWMDutyCyc'
   *  Switch: '<S2>/Switch'
   */
  Model_Y.WiperActv = (Model_Y.WiperMotPWMDutyCyc > 0.0);

  /* Update for Delay: '<S7>/Resettable Delay' */
  Model_DW.icLoad = false;
  Model_DW.ResettableDelay_DSTATE = rtb_Switch;

  /* End of Outputs for S-Function (fcgen): '<S1>/Ts = 10e-3' */
  rate_scheduler();
}

/* Model initialize function */
void Model_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Model_M, 0,
                sizeof(RT_MODEL_Model_T));

  /* block I/O */
  (void) memset(((void *) &Model_B), 0,
                sizeof(B_Model_T));

  /* states (dwork) */
  (void) memset((void *)&Model_DW, 0,
                sizeof(DW_Model_T));

  /* external inputs */
  (void)memset(&Model_U, 0, sizeof(ExtU_Model_T));

  /* external outputs */
  (void)memset(&Model_Y, 0, sizeof(ExtY_Model_T));

  /* SystemInitialize for S-Function (fcgen): '<S1>/Ts = 10e-3' incorporates:
   *  SubSystem: '<S1>/RainSnsrWiperMot'
   */
  /* InitializeConditions for Delay: '<S7>/Resettable Delay' */
  Model_DW.icLoad = true;

  /* SystemInitialize for IfAction SubSystem: '<S3>/Auto' */
  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
  Model_DW.UnitDelay_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S10>/Resettable Delay' */
  Model_DW.icLoad_i = true;

  /* SystemInitialize for IfAction SubSystem: '<S12>/StepUp' */
  Model_StepUp_Init(&Model_B.StepUp_p, &Model_DW.StepUp_p);

  /* End of SystemInitialize for SubSystem: '<S12>/StepUp' */

  /* SystemInitialize for IfAction SubSystem: '<S12>/StepDown' */
  Model_StepDown_Init(&Model_B.StepDown_p, &Model_DW.StepDown_p);

  /* End of SystemInitialize for SubSystem: '<S12>/StepDown' */

  /* SystemInitialize for Merge: '<S12>/Merge' */
  Model_B.Merge = 0.0;

  /* End of SystemInitialize for SubSystem: '<S3>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S20>/StepUp' */
  Model_StepUp_Init(&Model_B.StepUp, &Model_DW.StepUp);

  /* End of SystemInitialize for SubSystem: '<S20>/StepUp' */

  /* SystemInitialize for IfAction SubSystem: '<S20>/StepDown' */
  Model_StepDown_Init(&Model_B.StepDown, &Model_DW.StepDown);

  /* End of SystemInitialize for SubSystem: '<S20>/StepDown' */

  /* SystemInitialize for Outport: '<Root>/WiperMotPWMDutyCyc' incorporates:
   *  Outport: '<S2>/WiperMotPWMDutyCyc'
   */
  Model_Y.WiperMotPWMDutyCyc = 0.0;

  /* SystemInitialize for Outport: '<Root>/WiperActv' incorporates:
   *  Outport: '<S2>/WiperActv'
   */
  Model_Y.WiperActv = 0.0;

  /* End of SystemInitialize for S-Function (fcgen): '<S1>/Ts = 10e-3' */
}

/* Model terminate function */
void Model_terminate(void)
{
  /* (no terminate code required) */
}
