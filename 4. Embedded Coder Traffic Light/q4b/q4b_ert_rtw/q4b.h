/*
 * File: q4b.h
 *
 * Code generated for Simulink model 'q4b'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Apr 23 19:38:50 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef q4b_h_
#define q4b_h_
#ifndef q4b_COMMON_INCLUDES_
#define q4b_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* q4b_COMMON_INCLUDES_ */

#include "q4b_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T count;                        /* '<Root>/Chart' */
  real_T pcount;                       /* '<Root>/Chart' */
} B_q4b_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_q4b;            /* '<Root>/Chart' */
  uint8_T is_c3_q4b;                   /* '<Root>/Chart' */
} DW_q4b_T;

/* Parameters (default storage) */
struct P_q4b_T_ {
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_q4b_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_q4b_T q4b_P;

/* Block signals (default storage) */
extern B_q4b_T q4b_B;

/* Block states (default storage) */
extern DW_q4b_T q4b_DW;

/* Model entry point functions */
extern void q4b_initialize(void);
extern void q4b_step(void);
extern void q4b_terminate(void);

/* Real-time Model object */
extern RT_MODEL_q4b_T *const q4b_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 */

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
 * '<Root>' : 'q4b'
 * '<S1>'   : 'q4b/Chart'
 */
#endif                                 /* q4b_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
