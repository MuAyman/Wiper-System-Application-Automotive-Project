/*
 * WiperSystem.h
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

#ifndef RTW_HEADER_WiperSystem_h_
#define RTW_HEADER_WiperSystem_h_
#ifndef WiperSystem_COMMON_INCLUDES_
#define WiperSystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* WiperSystem_COMMON_INCLUDES_ */

#include "WiperSystem_types.h"
#include <math.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S21>/StepUp' */
typedef struct {
  real_T Merge;                        /* '<S24>/Merge' */
} B_StepUp_WiperSystem_T;

/* Block states (default storage) for system '<S21>/StepUp' */
typedef struct {
  real_T ResettableDelay_DSTATE;       /* '<S24>/Resettable Delay' */
  boolean_T icLoad;                    /* '<S24>/Resettable Delay' */
} DW_StepUp_WiperSystem_T;

/* Block signals for system '<S21>/StepDown' */
typedef struct {
  real_T Merge;                        /* '<S23>/Merge' */
} B_StepDown_WiperSystem_T;

/* Block states (default storage) for system '<S21>/StepDown' */
typedef struct {
  real_T ResettableDelay_DSTATE;       /* '<S23>/Resettable Delay' */
  boolean_T icLoad;                    /* '<S23>/Resettable Delay' */
} DW_StepDown_WiperSystem_T;

/* Block signals (default storage) */
typedef struct {
  real_T FromWs[3];                    /* '<S2>/FromWs' */
  real_T Merge;                        /* '<S13>/Merge' */
  B_StepDown_WiperSystem_T StepDown_p; /* '<S13>/StepDown' */
  B_StepUp_WiperSystem_T StepUp_p;     /* '<S13>/StepUp' */
  B_StepDown_WiperSystem_T StepDown;   /* '<S21>/StepDown' */
  B_StepUp_WiperSystem_T StepUp;       /* '<S21>/StepUp' */
} B_WiperSystem_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T ResettableDelay_DSTATE;       /* '<S8>/Resettable Delay' */
  real_T UnitDelay_DSTATE;             /* '<S12>/Unit Delay' */
  real_T ResettableDelay_DSTATE_h;     /* '<S11>/Resettable Delay' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S2>/FromWs' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S2>/FromWs' */

  boolean_T icLoad;                    /* '<S8>/Resettable Delay' */
  boolean_T icLoad_i;                  /* '<S11>/Resettable Delay' */
  DW_StepDown_WiperSystem_T StepDown_p;/* '<S13>/StepDown' */
  DW_StepUp_WiperSystem_T StepUp_p;    /* '<S13>/StepUp' */
  DW_StepDown_WiperSystem_T StepDown;  /* '<S21>/StepDown' */
  DW_StepUp_WiperSystem_T StepUp;      /* '<S21>/StepUp' */
} DW_WiperSystem_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [0 0.40 0.45 0.50 0.55 0.60 0.65 0.70]
   * Referenced by: '<S5>/1-D Lookup Table'
   */
  real_T uDLookupTable_tableData[8];

  /* Expression: [0 1 2 3 4 5 6 7]
   * Referenced by: '<S5>/1-D Lookup Table'
   */
  real_T uDLookupTable_bp01Data[8];
} ConstP_WiperSystem_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T WiperMotPWMDutyCyc;           /* '<Root>/WiperMotPWMDutyCyc' */
  real_T WiperActv;                    /* '<Root>/WiperActv' */
} ExtY_WiperSystem_T;

/* Real-time Model Data Structure */
struct tag_RTM_WiperSystem_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_WiperSystem_T WiperSystem_B;

/* Block states (default storage) */
extern DW_WiperSystem_T WiperSystem_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_WiperSystem_T WiperSystem_Y;

/* Constant parameters (default storage) */
extern const ConstP_WiperSystem_T WiperSystem_ConstP;

/* Model entry point functions */
extern void WiperSystem_initialize(void);
extern void WiperSystem_step(void);
extern void WiperSystem_terminate(void);

/* Real-time Model object */
extern RT_MODEL_WiperSystem_T *const WiperSystem_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'WiperSystem'
 * '<S1>'   : 'WiperSystem/Model'
 * '<S2>'   : 'WiperSystem/Signal Builder'
 * '<S3>'   : 'WiperSystem/Model/RainSnsrWiperMot'
 * '<S4>'   : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode'
 * '<S5>'   : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto'
 * '<S6>'   : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/High'
 * '<S7>'   : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Low'
 * '<S8>'   : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Smoothing'
 * '<S9>'   : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/off'
 * '<S10>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Signal Sample and Hold'
 * '<S11>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Smoothing'
 * '<S12>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Signal Sample and Hold/Discrete'
 * '<S13>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Smoothing/Change Speed'
 * '<S14>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Smoothing/Change Speed/Keep'
 * '<S15>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Smoothing/Change Speed/StepDown'
 * '<S16>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Smoothing/Change Speed/StepUp'
 * '<S17>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Smoothing/Change Speed/StepDown/not yet'
 * '<S18>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Smoothing/Change Speed/StepDown/reached'
 * '<S19>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Smoothing/Change Speed/StepUp/not yet'
 * '<S20>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Auto/Smoothing/Change Speed/StepUp/reached'
 * '<S21>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Smoothing/Change Speed'
 * '<S22>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Smoothing/Change Speed/Keep'
 * '<S23>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Smoothing/Change Speed/StepDown'
 * '<S24>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Smoothing/Change Speed/StepUp'
 * '<S25>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Smoothing/Change Speed/StepDown/not yet'
 * '<S26>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Smoothing/Change Speed/StepDown/reached'
 * '<S27>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Smoothing/Change Speed/StepUp/not yet'
 * '<S28>'  : 'WiperSystem/Model/RainSnsrWiperMot/Select Mode/Smoothing/Change Speed/StepUp/reached'
 */
#endif                                 /* RTW_HEADER_WiperSystem_h_ */
