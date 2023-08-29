/*
 * Model.h
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

#ifndef RTW_HEADER_Model_h_
#define RTW_HEADER_Model_h_
#ifndef Model_COMMON_INCLUDES_
#define Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Model_COMMON_INCLUDES_ */

#include "Model_types.h"
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S20>/StepUp' */
typedef struct {
  real_T Merge;                        /* '<S23>/Merge' */
} B_StepUp_Model_T;

/* Block states (default storage) for system '<S20>/StepUp' */
typedef struct {
  real_T ResettableDelay_DSTATE;       /* '<S23>/Resettable Delay' */
  boolean_T icLoad;                    /* '<S23>/Resettable Delay' */
} DW_StepUp_Model_T;

/* Block signals for system '<S20>/StepDown' */
typedef struct {
  real_T Merge;                        /* '<S22>/Merge' */
} B_StepDown_Model_T;

/* Block states (default storage) for system '<S20>/StepDown' */
typedef struct {
  real_T ResettableDelay_DSTATE;       /* '<S22>/Resettable Delay' */
  boolean_T icLoad;                    /* '<S22>/Resettable Delay' */
} DW_StepDown_Model_T;

/* Block signals (default storage) */
typedef struct {
  real_T Merge;                        /* '<S12>/Merge' */
  B_StepDown_Model_T StepDown_p;       /* '<S12>/StepDown' */
  B_StepUp_Model_T StepUp_p;           /* '<S12>/StepUp' */
  B_StepDown_Model_T StepDown;         /* '<S20>/StepDown' */
  B_StepUp_Model_T StepUp;             /* '<S20>/StepUp' */
} B_Model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T ResettableDelay_DSTATE;       /* '<S7>/Resettable Delay' */
  real_T UnitDelay_DSTATE;             /* '<S11>/Unit Delay' */
  real_T ResettableDelay_DSTATE_h;     /* '<S10>/Resettable Delay' */
  boolean_T icLoad;                    /* '<S7>/Resettable Delay' */
  boolean_T icLoad_i;                  /* '<S10>/Resettable Delay' */
  DW_StepDown_Model_T StepDown_p;      /* '<S12>/StepDown' */
  DW_StepUp_Model_T StepUp_p;          /* '<S12>/StepUp' */
  DW_StepDown_Model_T StepDown;        /* '<S20>/StepDown' */
  DW_StepUp_Model_T StepUp;            /* '<S20>/StepUp' */
} DW_Model_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [0 0.40 0.45 0.50 0.55 0.60 0.65 0.70]
   * Referenced by: '<S4>/1-D Lookup Table'
   */
  real_T uDLookupTable_tableData[8];

  /* Expression: [0 1 2 3 4 5 6 7]
   * Referenced by: '<S4>/1-D Lookup Table'
   */
  real_T uDLookupTable_bp01Data[8];
} ConstP_Model_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T WiperMod;                     /* '<Root>/WiperMod' */
  real_T RainSnsr;                     /* '<Root>/RainSnsrErr' */
  real_T WiperSpdReq;                  /* '<Root>/WiperSpdReq' */
} ExtU_Model_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T WiperMotPWMDutyCyc;           /* '<Root>/WiperMotPWMDutyCyc' */
  real_T WiperActv;                    /* '<Root>/WiperActv' */
} ExtY_Model_T;

/* Real-time Model Data Structure */
struct tag_RTM_Model_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_Model_T Model_B;

/* Block states (default storage) */
extern DW_Model_T Model_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Model_T Model_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Model_T Model_Y;

/* Constant parameters (default storage) */
extern const ConstP_Model_T Model_ConstP;

/* Model entry point functions */
extern void Model_initialize(void);
extern void Model_step(void);
extern void Model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Model_T *const Model_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('WiperSystem/Model')    - opens subsystem WiperSystem/Model
 * hilite_system('WiperSystem/Model/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'WiperSystem'
 * '<S1>'   : 'WiperSystem/Model'
 * '<S2>'   : 'WiperSystem/Model/RainSnsrWiperMot'
 * '<S3>'   : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode'
 * '<S4>'   : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto'
 * '<S5>'   : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/High'
 * '<S6>'   : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Low'
 * '<S7>'   : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Smoothing'
 * '<S8>'   : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/off'
 * '<S9>'   : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Signal Sample and Hold'
 * '<S10>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Smoothing'
 * '<S11>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Signal Sample and Hold/Discrete'
 * '<S12>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Smoothing/Change Speed'
 * '<S13>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Smoothing/Change Speed/Keep'
 * '<S14>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Smoothing/Change Speed/StepDown'
 * '<S15>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Smoothing/Change Speed/StepUp'
 * '<S16>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Smoothing/Change Speed/StepDown/not yet'
 * '<S17>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Smoothing/Change Speed/StepDown/reached'
 * '<S18>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Smoothing/Change Speed/StepUp/not yet'
 * '<S19>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Smoothing/Change Speed/StepUp/reached'
 * '<S20>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Smoothing/Change Speed'
 * '<S21>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Smoothing/Change Speed/Keep'
 * '<S22>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Smoothing/Change Speed/StepDown'
 * '<S23>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Smoothing/Change Speed/StepUp'
 * '<S24>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Smoothing/Change Speed/StepDown/not yet'
 * '<S25>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Smoothing/Change Speed/StepDown/reached'
 * '<S26>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Smoothing/Change Speed/StepUp/not yet'
 * '<S27>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Smoothing/Change Speed/StepUp/reached'
 */
#endif                                 /* RTW_HEADER_Model_h_ */
