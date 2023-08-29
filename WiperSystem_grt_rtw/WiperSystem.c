/*
 * WiperSystem.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "WiperSystem".
 *
 * Model version              : 1.28
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Tue Aug 29 08:50:36 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "WiperSystem.h"
#include "rtwtypes.h"
#include "WiperSystem_private.h"
#include <string.h>

/* Block signals (default storage) */
B_WiperSystem_T WiperSystem_B;

/* Block states (default storage) */
DW_WiperSystem_T WiperSystem_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_WiperSystem_T WiperSystem_Y;

/* Real-time model */
static RT_MODEL_WiperSystem_T WiperSystem_M_;
RT_MODEL_WiperSystem_T *const WiperSystem_M = &WiperSystem_M_;
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
  (WiperSystem_M->Timing.TaskCounters.TID[1])++;
  if ((WiperSystem_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [1.0s, 0.0s] */
    WiperSystem_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S24>/not yet'
 *    '<S23>/not yet'
 *    '<S16>/not yet'
 *    '<S15>/not yet'
 *    '<S4>/Low'
 *    '<S4>/High'
 *    '<S4>/off'
 */
void WiperSystem_notyet(real_T rtu_In1, real_T *rty_Out1)
{
  /* SignalConversion generated from: '<S27>/In1' */
  *rty_Out1 = rtu_In1;
}

/*
 * Output and update for action system:
 *    '<S24>/reached'
 *    '<S23>/reached'
 *    '<S16>/reached'
 *    '<S15>/reached'
 */
void WiperSystem_reached(real_T rtu_req, real_T *rty_DownPWM)
{
  /* SignalConversion generated from: '<S28>/req' */
  *rty_DownPWM = rtu_req;
}

/*
 * System initialize for action system:
 *    '<S21>/StepUp'
 *    '<S13>/StepUp'
 */
void WiperSystem_StepUp_Init(B_StepUp_WiperSystem_T *localB,
  DW_StepUp_WiperSystem_T *localDW)
{
  /* InitializeConditions for Delay: '<S24>/Resettable Delay' */
  localDW->icLoad = true;

  /* SystemInitialize for Merge: '<S24>/Merge' */
  localB->Merge = 0.0;
}

/*
 * Output and update for action system:
 *    '<S21>/StepUp'
 *    '<S13>/StepUp'
 */
void WiperSystem_StepUp(real_T rtu_req, real_T rtu_prev, real_T *rty_UpPWM,
  B_StepUp_WiperSystem_T *localB, DW_StepUp_WiperSystem_T *localDW)
{
  /* Delay: '<S24>/Resettable Delay' */
  if (localDW->icLoad) {
    localDW->ResettableDelay_DSTATE = rtu_prev;
  }

  /* If: '<S24>/If prev reaches req' incorporates:
   *  Constant: '<S24>/Constant'
   *  Delay: '<S24>/Resettable Delay'
   *  Sum: '<S24>/Add1'
   */
  if (localDW->ResettableDelay_DSTATE + 0.01 < rtu_req) {
    /* Outputs for IfAction SubSystem: '<S24>/not yet' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    WiperSystem_notyet(localDW->ResettableDelay_DSTATE + 0.01, &localB->Merge);

    /* End of Outputs for SubSystem: '<S24>/not yet' */
  } else {
    /* Outputs for IfAction SubSystem: '<S24>/reached' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    WiperSystem_reached(rtu_req, &localB->Merge);

    /* End of Outputs for SubSystem: '<S24>/reached' */
  }

  /* End of If: '<S24>/If prev reaches req' */

  /* SignalConversion generated from: '<S24>/UpPWM' */
  *rty_UpPWM = localB->Merge;

  /* Update for Delay: '<S24>/Resettable Delay' */
  localDW->icLoad = false;
  localDW->ResettableDelay_DSTATE = localB->Merge;
}

/*
 * System initialize for action system:
 *    '<S21>/StepDown'
 *    '<S13>/StepDown'
 */
void WiperSystem_StepDown_Init(B_StepDown_WiperSystem_T *localB,
  DW_StepDown_WiperSystem_T *localDW)
{
  /* InitializeConditions for Delay: '<S23>/Resettable Delay' */
  localDW->icLoad = true;

  /* SystemInitialize for Merge: '<S23>/Merge' */
  localB->Merge = 0.0;
}

/*
 * Output and update for action system:
 *    '<S21>/StepDown'
 *    '<S13>/StepDown'
 */
void WiperSystem_StepDown(real_T rtu_req, real_T rtu_prev, real_T *rty_DownPWM,
  B_StepDown_WiperSystem_T *localB, DW_StepDown_WiperSystem_T *localDW)
{
  /* Delay: '<S23>/Resettable Delay' */
  if (localDW->icLoad) {
    localDW->ResettableDelay_DSTATE = rtu_prev;
  }

  /* If: '<S23>/If prev reaches req' incorporates:
   *  Constant: '<S23>/Constant'
   *  Delay: '<S23>/Resettable Delay'
   *  Sum: '<S23>/Add'
   */
  if (localDW->ResettableDelay_DSTATE - 0.01 > rtu_req) {
    /* Outputs for IfAction SubSystem: '<S23>/not yet' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    WiperSystem_notyet(localDW->ResettableDelay_DSTATE - 0.01, &localB->Merge);

    /* End of Outputs for SubSystem: '<S23>/not yet' */
  } else {
    /* Outputs for IfAction SubSystem: '<S23>/reached' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    WiperSystem_reached(rtu_req, &localB->Merge);

    /* End of Outputs for SubSystem: '<S23>/reached' */
  }

  /* End of If: '<S23>/If prev reaches req' */

  /* SignalConversion generated from: '<S23>/DownPWM' */
  *rty_DownPWM = localB->Merge;

  /* Update for Delay: '<S23>/Resettable Delay' */
  localDW->icLoad = false;
  localDW->ResettableDelay_DSTATE = localB->Merge;
}

/*
 * Output and update for action system:
 *    '<S21>/Keep'
 *    '<S13>/Keep'
 */
void WiperSystem_Keep(real_T rtu_prev, real_T *rty_KeepPWM)
{
  /* SignalConversion generated from: '<S22>/prev' */
  *rty_KeepPWM = rtu_prev;
}

/* Model step function */
void WiperSystem_step(void)
{
  real_T rtb_Merge;
  real_T rtb_Switch;
  if (WiperSystem_M->Timing.TaskCounters.TID[1] == 0) {
    /* FromWorkspace: '<S2>/FromWs' */
    {
      real_T *pDataValues = (real_T *) WiperSystem_DW.FromWs_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *) WiperSystem_DW.FromWs_PWORK.TimePtr;
      int_T currTimeIndex = WiperSystem_DW.FromWs_IWORK.PrevIndex;
      real_T t = (((WiperSystem_M->Timing.clockTick1+
                    WiperSystem_M->Timing.clockTickH1* 4294967296.0)) * 1.0);
      if (t >= pTimeValues[25]) {
        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 3; ++elIdx) {
            (&WiperSystem_B.FromWs[0])[elIdx] = pDataValues[25];
            pDataValues += 26;
          }
        }
      } else {
        /* Get index */
        if (t <= pTimeValues[0]) {
          currTimeIndex = 0;
        } else if (t >= pTimeValues[25]) {
          currTimeIndex = 24;
        } else {
          if (t < pTimeValues[currTimeIndex]) {
            while (t < pTimeValues[currTimeIndex]) {
              currTimeIndex--;
            }
          } else {
            while (t >= pTimeValues[currTimeIndex + 1]) {
              currTimeIndex++;
            }
          }
        }

        WiperSystem_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

        /* Post output */
        {
          real_T t1 = pTimeValues[currTimeIndex];
          real_T t2 = pTimeValues[currTimeIndex + 1];
          if (t1 == t2) {
            if (t < t1) {
              {
                int_T elIdx;
                for (elIdx = 0; elIdx < 3; ++elIdx) {
                  (&WiperSystem_B.FromWs[0])[elIdx] = pDataValues[currTimeIndex];
                  pDataValues += 26;
                }
              }
            } else {
              {
                int_T elIdx;
                for (elIdx = 0; elIdx < 3; ++elIdx) {
                  (&WiperSystem_B.FromWs[0])[elIdx] = pDataValues[currTimeIndex
                    + 1];
                  pDataValues += 26;
                }
              }
            }
          } else {
            real_T f1 = (t2 - t) / (t2 - t1);
            real_T f2 = 1.0 - f1;
            real_T d1;
            real_T d2;
            int_T TimeIndex = currTimeIndex;

            {
              int_T elIdx;
              for (elIdx = 0; elIdx < 3; ++elIdx) {
                d1 = pDataValues[TimeIndex];
                d2 = pDataValues[TimeIndex + 1];
                (&WiperSystem_B.FromWs[0])[elIdx] = (real_T) rtInterpolate(d1,
                  d2, f1, f2);
                pDataValues += 26;
              }
            }
          }
        }
      }
    }
  }

  /* S-Function (fcgen): '<S1>/Ts = 10e-3' incorporates:
   *  SubSystem: '<S1>/RainSnsrWiperMot'
   */
  /* SwitchCase: '<S4>/Switch Case' incorporates:
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant3'
   *  Constant: '<S4>/Constant4'
   */
  switch ((int32_T)WiperSystem_B.FromWs[0]) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S4>/Auto' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Lookup_n-D: '<S5>/1-D Lookup Table' */
    rtb_Merge = look1_binlg(WiperSystem_B.FromWs[2],
      WiperSystem_ConstP.uDLookupTable_bp01Data,
      WiperSystem_ConstP.uDLookupTable_tableData, 7U);

    /* Switch: '<S12>/Switch' incorporates:
     *  DataTypeConversion: '<S12>/Data Type Conversion'
     *  UnitDelay: '<S12>/Unit Delay'
     */
    if (rtb_Merge != 0.0) {
      rtb_Switch = rtb_Merge;
    } else {
      rtb_Switch = WiperSystem_DW.UnitDelay_DSTATE;
    }

    /* End of Switch: '<S12>/Switch' */

    /* Delay: '<S11>/Resettable Delay' */
    if (WiperSystem_DW.icLoad_i) {
      WiperSystem_DW.ResettableDelay_DSTATE_h = rtb_Switch;
    }

    /* If: '<S13>/If' incorporates:
     *  Delay: '<S11>/Resettable Delay'
     */
    if (rtb_Switch > WiperSystem_DW.ResettableDelay_DSTATE_h) {
      /* Outputs for IfAction SubSystem: '<S13>/StepUp' incorporates:
       *  ActionPort: '<S16>/StepUp'
       */
      WiperSystem_StepUp(rtb_Switch, WiperSystem_DW.ResettableDelay_DSTATE_h,
                         &WiperSystem_B.Merge, &WiperSystem_B.StepUp_p,
                         &WiperSystem_DW.StepUp_p);

      /* End of Outputs for SubSystem: '<S13>/StepUp' */
    } else if (rtb_Switch < WiperSystem_DW.ResettableDelay_DSTATE_h) {
      /* Outputs for IfAction SubSystem: '<S13>/StepDown' incorporates:
       *  ActionPort: '<S15>/StepDown'
       */
      WiperSystem_StepDown(rtb_Switch, WiperSystem_DW.ResettableDelay_DSTATE_h,
                           &WiperSystem_B.Merge, &WiperSystem_B.StepDown_p,
                           &WiperSystem_DW.StepDown_p);

      /* End of Outputs for SubSystem: '<S13>/StepDown' */
    } else {
      /* Outputs for IfAction SubSystem: '<S13>/Keep' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      WiperSystem_Keep(WiperSystem_DW.ResettableDelay_DSTATE_h,
                       &WiperSystem_B.Merge);

      /* End of Outputs for SubSystem: '<S13>/Keep' */
    }

    /* End of If: '<S13>/If' */

    /* SignalConversion generated from: '<S5>/AutoPWM' */
    rtb_Merge = WiperSystem_B.Merge;

    /* Update for UnitDelay: '<S12>/Unit Delay' */
    WiperSystem_DW.UnitDelay_DSTATE = rtb_Switch;

    /* Update for Delay: '<S11>/Resettable Delay' */
    WiperSystem_DW.icLoad_i = false;
    WiperSystem_DW.ResettableDelay_DSTATE_h = WiperSystem_B.Merge;

    /* End of Outputs for SubSystem: '<S4>/Auto' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S4>/Low' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    WiperSystem_notyet(0.4, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S4>/Low' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S4>/High' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    WiperSystem_notyet(0.7, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S4>/High' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S4>/off' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    WiperSystem_notyet(0.0, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S4>/off' */
    break;
  }

  /* End of SwitchCase: '<S4>/Switch Case' */

  /* Delay: '<S8>/Resettable Delay' */
  if (WiperSystem_DW.icLoad) {
    WiperSystem_DW.ResettableDelay_DSTATE = rtb_Merge;
  }

  /* If: '<S21>/If' incorporates:
   *  Delay: '<S8>/Resettable Delay'
   */
  if (rtb_Merge > WiperSystem_DW.ResettableDelay_DSTATE) {
    /* Outputs for IfAction SubSystem: '<S21>/StepUp' incorporates:
     *  ActionPort: '<S24>/StepUp'
     */
    WiperSystem_StepUp(rtb_Merge, WiperSystem_DW.ResettableDelay_DSTATE,
                       &rtb_Switch, &WiperSystem_B.StepUp,
                       &WiperSystem_DW.StepUp);

    /* End of Outputs for SubSystem: '<S21>/StepUp' */
  } else if (rtb_Merge < WiperSystem_DW.ResettableDelay_DSTATE) {
    /* Outputs for IfAction SubSystem: '<S21>/StepDown' incorporates:
     *  ActionPort: '<S23>/StepDown'
     */
    WiperSystem_StepDown(rtb_Merge, WiperSystem_DW.ResettableDelay_DSTATE,
                         &rtb_Switch, &WiperSystem_B.StepDown,
                         &WiperSystem_DW.StepDown);

    /* End of Outputs for SubSystem: '<S21>/StepDown' */
  } else {
    /* Outputs for IfAction SubSystem: '<S21>/Keep' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    WiperSystem_Keep(WiperSystem_DW.ResettableDelay_DSTATE, &rtb_Switch);

    /* End of Outputs for SubSystem: '<S21>/Keep' */
  }

  /* End of If: '<S21>/If' */

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S3>/off'
   */
  if (WiperSystem_B.FromWs[1] > 0.0) {
    rtb_Merge = 0.0;
  } else {
    rtb_Merge = rtb_Switch;
  }

  /* Outport: '<Root>/WiperMotPWMDutyCyc' incorporates:
   *  Gain: '<S3>/MaxPWM'
   *  Switch: '<S3>/Switch1'
   */
  WiperSystem_Y.WiperMotPWMDutyCyc = 255.0 * rtb_Merge;

  /* Outport: '<Root>/WiperActv' incorporates:
   *  Outport: '<Root>/WiperMotPWMDutyCyc'
   *  Switch: '<S3>/Switch'
   */
  WiperSystem_Y.WiperActv = (WiperSystem_Y.WiperMotPWMDutyCyc > 0.0);

  /* Update for Delay: '<S8>/Resettable Delay' */
  WiperSystem_DW.icLoad = false;
  WiperSystem_DW.ResettableDelay_DSTATE = rtb_Switch;

  /* End of Outputs for S-Function (fcgen): '<S1>/Ts = 10e-3' */
  if (WiperSystem_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [1.0s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.0, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    WiperSystem_M->Timing.clockTick1++;
    if (!WiperSystem_M->Timing.clockTick1) {
      WiperSystem_M->Timing.clockTickH1++;
    }
  }

  rate_scheduler();
}

/* Model initialize function */
void WiperSystem_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)WiperSystem_M, 0,
                sizeof(RT_MODEL_WiperSystem_T));

  /* block I/O */
  (void) memset(((void *) &WiperSystem_B), 0,
                sizeof(B_WiperSystem_T));

  /* states (dwork) */
  (void) memset((void *)&WiperSystem_DW, 0,
                sizeof(DW_WiperSystem_T));

  /* external outputs */
  (void)memset(&WiperSystem_Y, 0, sizeof(ExtY_WiperSystem_T));

  /* Start for FromWorkspace: '<S2>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 1.0, 2.0, 2.0, 3.0, 3.0, 4.0, 4.0,
      5.0, 5.0, 6.0, 6.0, 7.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 14.0,
      15.0, 15.0, 16.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 2.0, 2.0, 2.0, 2.0, 3.0, 3.0,
      3.0, 3.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
      1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 2.0,
      3.0, 4.0, 5.0, 6.0, 7.0, 7.0, 7.0, 7.0, 7.0 } ;

    WiperSystem_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    WiperSystem_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    WiperSystem_DW.FromWs_IWORK.PrevIndex = 0;
  }

  /* SystemInitialize for S-Function (fcgen): '<S1>/Ts = 10e-3' incorporates:
   *  SubSystem: '<S1>/RainSnsrWiperMot'
   */
  /* InitializeConditions for Delay: '<S8>/Resettable Delay' */
  WiperSystem_DW.icLoad = true;

  /* SystemInitialize for IfAction SubSystem: '<S4>/Auto' */
  /* InitializeConditions for UnitDelay: '<S12>/Unit Delay' */
  WiperSystem_DW.UnitDelay_DSTATE = 0.0;

  /* InitializeConditions for Delay: '<S11>/Resettable Delay' */
  WiperSystem_DW.icLoad_i = true;

  /* SystemInitialize for IfAction SubSystem: '<S13>/StepUp' */
  WiperSystem_StepUp_Init(&WiperSystem_B.StepUp_p, &WiperSystem_DW.StepUp_p);

  /* End of SystemInitialize for SubSystem: '<S13>/StepUp' */

  /* SystemInitialize for IfAction SubSystem: '<S13>/StepDown' */
  WiperSystem_StepDown_Init(&WiperSystem_B.StepDown_p,
    &WiperSystem_DW.StepDown_p);

  /* End of SystemInitialize for SubSystem: '<S13>/StepDown' */

  /* SystemInitialize for Merge: '<S13>/Merge' */
  WiperSystem_B.Merge = 0.0;

  /* End of SystemInitialize for SubSystem: '<S4>/Auto' */

  /* SystemInitialize for IfAction SubSystem: '<S21>/StepUp' */
  WiperSystem_StepUp_Init(&WiperSystem_B.StepUp, &WiperSystem_DW.StepUp);

  /* End of SystemInitialize for SubSystem: '<S21>/StepUp' */

  /* SystemInitialize for IfAction SubSystem: '<S21>/StepDown' */
  WiperSystem_StepDown_Init(&WiperSystem_B.StepDown, &WiperSystem_DW.StepDown);

  /* End of SystemInitialize for SubSystem: '<S21>/StepDown' */

  /* SystemInitialize for Outport: '<Root>/WiperMotPWMDutyCyc' incorporates:
   *  Outport: '<S3>/WiperMotPWMDutyCyc'
   */
  WiperSystem_Y.WiperMotPWMDutyCyc = 0.0;

  /* SystemInitialize for Outport: '<Root>/WiperActv' incorporates:
   *  Outport: '<S3>/WiperActv'
   */
  WiperSystem_Y.WiperActv = 0.0;

  /* End of SystemInitialize for S-Function (fcgen): '<S1>/Ts = 10e-3' */
}

/* Model terminate function */
void WiperSystem_terminate(void)
{
  /* (no terminate code required) */
}
