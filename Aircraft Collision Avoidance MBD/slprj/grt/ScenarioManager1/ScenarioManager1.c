/*
 * Code generation for system model 'ScenarioManager1'
 *
 * Model                      : ScenarioManager1
 * Model version              : 1.20
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Tue Aug 19 04:33:01 2025
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "ScenarioManager1.h"
#include "rtwtypes.h"
#include "ScenarioManager1_private.h"

/* System initialize for referenced model: 'ScenarioManager1' */
void ScenarioManager1_Init(real_T rty_start_position_aircraft1[2], real_T
  rty_goal_position_aircraft1[2], real_T rty_start_position_aircraft2[2], real_T
  rty_goal_position_aircraft2[2])
{
  /* Start for Constant: '<Root>/Constant' */
  rty_start_position_aircraft1[0] = rtP_AIRCRAFT1_START[0];

  /* Start for Constant: '<Root>/Constant1' */
  rty_goal_position_aircraft1[0] = rtP_AIRCRAFT1_GOAL[0];

  /* Start for Constant: '<Root>/Constant2' */
  rty_start_position_aircraft2[0] = rtP_AIRCRAFT2_START[0];

  /* Start for Constant: '<Root>/Constant3' */
  rty_goal_position_aircraft2[0] = rtP_AIRCRAFT2_GOAL[0];

  /* Start for Constant: '<Root>/Constant' */
  rty_start_position_aircraft1[1] = rtP_AIRCRAFT1_START[1];

  /* Start for Constant: '<Root>/Constant1' */
  rty_goal_position_aircraft1[1] = rtP_AIRCRAFT1_GOAL[1];

  /* Start for Constant: '<Root>/Constant2' */
  rty_start_position_aircraft2[1] = rtP_AIRCRAFT2_START[1];

  /* Start for Constant: '<Root>/Constant3' */
  rty_goal_position_aircraft2[1] = rtP_AIRCRAFT2_GOAL[1];
}

/* Output and update for referenced model: 'ScenarioManager1' */
void ScenarioManager1(real_T rty_start_position_aircraft1[2], real_T
                      rty_goal_position_aircraft1[2], real_T
                      rty_start_position_aircraft2[2], real_T
                      rty_goal_position_aircraft2[2])
{
  /* Constant: '<Root>/Constant' */
  rty_start_position_aircraft1[0] = rtP_AIRCRAFT1_START[0];

  /* Constant: '<Root>/Constant1' */
  rty_goal_position_aircraft1[0] = rtP_AIRCRAFT1_GOAL[0];

  /* Constant: '<Root>/Constant2' */
  rty_start_position_aircraft2[0] = rtP_AIRCRAFT2_START[0];

  /* Constant: '<Root>/Constant3' */
  rty_goal_position_aircraft2[0] = rtP_AIRCRAFT2_GOAL[0];

  /* Constant: '<Root>/Constant' */
  rty_start_position_aircraft1[1] = rtP_AIRCRAFT1_START[1];

  /* Constant: '<Root>/Constant1' */
  rty_goal_position_aircraft1[1] = rtP_AIRCRAFT1_GOAL[1];

  /* Constant: '<Root>/Constant2' */
  rty_start_position_aircraft2[1] = rtP_AIRCRAFT2_START[1];

  /* Constant: '<Root>/Constant3' */
  rty_goal_position_aircraft2[1] = rtP_AIRCRAFT2_GOAL[1];
}

/* Model initialize function */
void ScenarioManager1_initialize(const char_T **rt_errorStatus,
  RT_MODEL_ScenarioManager1_T *const ScenarioManager1_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(ScenarioManager1_M, rt_errorStatus);
}
