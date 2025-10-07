/*
 * File: q4a.h
 *
 * Code generated for Simulink model 'q4a'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Apr 25 12:01:29 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. Traceability
 * Validation result: Not run
 */

#ifndef q4a_h_
#define q4a_h_
#ifndef q4a_COMMON_INCLUDES_
#define q4a_COMMON_INCLUDES_
#include <stdbool.h>
#include <stdint.h>
#endif                                 /* q4a_COMMON_INCLUDES_ */

/* External inputs (root inport signals with default storage) */
typedef struct {
  float In1;                           /* '<Root>/In1' */
  float In2;                           /* '<Root>/In2' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  float Out1;                          /* '<Root>/Out1' */
} ExtY;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void q4a_initialize(void);
extern void q4a_step(void);

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
 * '<Root>' : 'q4a'
 */

/*-
 * Requirements for '<Root>': q4a

 */
#endif                                 /* q4a_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
