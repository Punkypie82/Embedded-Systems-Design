/*
 * Code generation for system model 'Verification'
 *
 * Model                      : Verification
 * Model version              : 1.5
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Tue Aug 19 04:33:05 2025
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "Verification.h"
#include "rtwtypes.h"
#include "Verification_private.h"
#include <math.h>
#include "rt_assert.h"

P_Verification_T Verification_P = {
  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Computed Parameter: Assertion_Enabled
   * Referenced by: '<Root>/Assertion'
   */
  true,

  /* Computed Parameter: Assertion1_Enabled
   * Referenced by: '<Root>/Assertion1'
   */
  true
};

/* Output and update for referenced model: 'Verification' */
void Verification(RT_MODEL_Verification_T * const Verification_M, const real_T
                  rtu_aircraft1_position[2], const real_T
                  rtu_aircraft2_position[2])
{
  boolean_T b;
  if (rtmIsMajorTimeStep(Verification_M)) {
    /* MATLAB Function: '<Root>/safezone' incorporates:
     *  Constant: '<Root>/Constant'
     */
    if ((fabs(rtu_aircraft1_position[0] - rtu_aircraft2_position[0]) <
         rtP_MIN_SEP_KM) && (fabs(rtu_aircraft1_position[1] -
          rtu_aircraft2_position[1]) < rtP_MIN_SEP_KM)) {
      b = true;
    } else {
      b = false;
    }

    /* Assertion: '<Root>/Assertion' incorporates:
     *  MATLAB Function: '<Root>/safezone'
     */
    utAssert(!b);

    /* Assertion: '<Root>/Assertion1' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    utAssert(Verification_P.Constant1_Value != 0.0);
  }
}

/* Model initialize function */
void Verification_initialize(const char_T **rt_errorStatus, RTWSolverInfo
  *rt_solverInfo, RT_MODEL_Verification_T *const Verification_M)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Verification_M, 0,
                sizeof(RT_MODEL_Verification_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(Verification_M, rt_errorStatus);

  /* initialize RTWSolverInfo */
  Verification_M->solverInfo = (rt_solverInfo);

  /* Set the Timing fields to the appropriate data in the RTWSolverInfo */
  rtmSetSimTimeStepPointer(Verification_M, rtsiGetSimTimeStepPtr
    (Verification_M->solverInfo));
  Verification_M->Timing.stepSize0 = (rtsiGetStepSize(Verification_M->solverInfo));
}
