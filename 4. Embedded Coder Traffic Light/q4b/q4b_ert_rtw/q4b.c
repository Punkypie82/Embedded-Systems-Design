/*
 * File: q4b.c
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

#include "q4b.h"
#include "rtwtypes.h"
#include "q4b_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define q4b_IN_cargreen_pedred         ((uint8_T)1U)
#define q4b_IN_carred_pedgreen         ((uint8_T)2U)
#define q4b_IN_carred_pedred           ((uint8_T)3U)
#define q4b_IN_caryellow_pedred        ((uint8_T)4U)
#define q4b_IN_pending_pedred          ((uint8_T)5U)

/* Block signals (default storage) */
B_q4b_T q4b_B;

/* Block states (default storage) */
DW_q4b_T q4b_DW;

/* Real-time model */
static RT_MODEL_q4b_T q4b_M_;
RT_MODEL_q4b_T *const q4b_M = &q4b_M_;

/* Model step function */
void q4b_step(void)
{
  real_T tmp;

  /* Chart: '<Root>/Chart' incorporates:
   *  Step: '<Root>/Step'
   */
  if (q4b_DW.is_active_c3_q4b == 0U) {
    q4b_DW.is_active_c3_q4b = 1U;
    q4b_B.count = 0.0;
    q4b_B.pcount = 0.0;
    q4b_DW.is_c3_q4b = q4b_IN_carred_pedgreen;
  } else {
    switch (q4b_DW.is_c3_q4b) {
     case q4b_IN_cargreen_pedred:
      if (q4b_B.count < 60.0) {
        q4b_B.count++;
        q4b_DW.is_c3_q4b = q4b_IN_cargreen_pedred;
      } else {
        if (q4b_M->Timing.t[0] < q4b_P.Step_Time) {
          /* Step: '<Root>/Step' */
          tmp = q4b_P.Step_Y0;
        } else {
          /* Step: '<Root>/Step' */
          tmp = q4b_P.Step_YFinal;
        }

        if ((tmp != 0.0) && (q4b_B.count >= 60.0)) {
          q4b_B.count = 0.0;
          q4b_DW.is_c3_q4b = q4b_IN_caryellow_pedred;
        }
      }
      break;

     case q4b_IN_carred_pedgreen:
      if (q4b_B.pcount >= 55.0) {
        q4b_B.count++;
        q4b_DW.is_c3_q4b = q4b_IN_carred_pedred;
      } else {
        q4b_B.count++;
        q4b_B.pcount++;
        q4b_DW.is_c3_q4b = q4b_IN_carred_pedgreen;
      }
      break;

     case q4b_IN_carred_pedred:
      if (q4b_B.count >= 60.0) {
        q4b_B.count++;
        q4b_DW.is_c3_q4b = q4b_IN_cargreen_pedred;
      } else {
        q4b_B.count++;
        q4b_DW.is_c3_q4b = q4b_IN_carred_pedred;
      }
      break;

     case q4b_IN_caryellow_pedred:
      if (q4b_B.pcount >= 5.0) {
        q4b_B.count = 0.0;
        q4b_B.pcount = 0.0;
        q4b_DW.is_c3_q4b = q4b_IN_carred_pedgreen;
      } else {
        q4b_B.count++;
        q4b_DW.is_c3_q4b = q4b_IN_caryellow_pedred;
      }
      break;

     default:
      /* case IN_pending_pedred: */
      if (q4b_B.pcount >= 60.0) {
        q4b_B.count = 0.0;
        q4b_DW.is_c3_q4b = q4b_IN_caryellow_pedred;
      } else {
        q4b_B.count++;
        q4b_DW.is_c3_q4b = q4b_IN_pending_pedred;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  q4b_M->Timing.t[0] =
    ((time_T)(++q4b_M->Timing.clockTick0)) * q4b_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [1.0s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.0, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    q4b_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void q4b_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&q4b_M->solverInfo, &q4b_M->Timing.simTimeStep);
    rtsiSetTPtr(&q4b_M->solverInfo, &rtmGetTPtr(q4b_M));
    rtsiSetStepSizePtr(&q4b_M->solverInfo, &q4b_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&q4b_M->solverInfo, (&rtmGetErrorStatus(q4b_M)));
    rtsiSetRTModelPtr(&q4b_M->solverInfo, q4b_M);
  }

  rtsiSetSimTimeStep(&q4b_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&q4b_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&q4b_M->solverInfo, false);
  rtsiSetSolverName(&q4b_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(q4b_M, &q4b_M->Timing.tArray[0]);
  q4b_M->Timing.stepSize0 = 1.0;
}

/* Model terminate function */
void q4b_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
