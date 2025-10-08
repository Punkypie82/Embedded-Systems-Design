/*
 * Code generation for system model 'MemoryBlock'
 *
 * Model                      : MemoryBlock
 * Model version              : 1.4
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Tue Aug 19 04:32:58 2025
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "MemoryBlock.h"
#include "rtwtypes.h"
#include "MemoryBlock_private.h"
#include <string.h>

P_MemoryBlock_T MemoryBlock_P = {
  /* Expression: 0
   * Referenced by: '<Root>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Memory1'
   */
  0.0
};

/* System initialize for referenced model: 'MemoryBlock' */
void MemoryBlock_Init(DW_MemoryBlock_f_T *localDW)
{
  /* InitializeConditions for Memory: '<Root>/Memory' */
  localDW->Memory_PreviousInput[0] = MemoryBlock_P.Memory_InitialCondition;

  /* InitializeConditions for Memory: '<Root>/Memory1' */
  localDW->Memory1_PreviousInput[0] = MemoryBlock_P.Memory1_InitialCondition;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  localDW->Memory_PreviousInput[1] = MemoryBlock_P.Memory_InitialCondition;

  /* InitializeConditions for Memory: '<Root>/Memory1' */
  localDW->Memory1_PreviousInput[1] = MemoryBlock_P.Memory1_InitialCondition;
}

/* System reset for referenced model: 'MemoryBlock' */
void MemoryBlock_Reset(DW_MemoryBlock_f_T *localDW)
{
  /* InitializeConditions for Memory: '<Root>/Memory' */
  localDW->Memory_PreviousInput[0] = MemoryBlock_P.Memory_InitialCondition;

  /* InitializeConditions for Memory: '<Root>/Memory1' */
  localDW->Memory1_PreviousInput[0] = MemoryBlock_P.Memory1_InitialCondition;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  localDW->Memory_PreviousInput[1] = MemoryBlock_P.Memory_InitialCondition;

  /* InitializeConditions for Memory: '<Root>/Memory1' */
  localDW->Memory1_PreviousInput[1] = MemoryBlock_P.Memory1_InitialCondition;
}

/* Output and update for referenced model: 'MemoryBlock' */
void MemoryBlock(const real_T rtu_position_in[2], const real_T
                 rtu_trajectory_in[2], real_T rty_position_out[2], real_T
                 rty_trajectory_out[2], DW_MemoryBlock_f_T *localDW)
{
  /* Memory: '<Root>/Memory' */
  rty_position_out[0] = localDW->Memory_PreviousInput[0];

  /* Memory: '<Root>/Memory1' */
  rty_trajectory_out[0] = localDW->Memory1_PreviousInput[0];

  /* Update for Memory: '<Root>/Memory' */
  localDW->Memory_PreviousInput[0] = rtu_position_in[0];

  /* Update for Memory: '<Root>/Memory1' */
  localDW->Memory1_PreviousInput[0] = rtu_trajectory_in[0];

  /* Memory: '<Root>/Memory' */
  rty_position_out[1] = localDW->Memory_PreviousInput[1];

  /* Memory: '<Root>/Memory1' */
  rty_trajectory_out[1] = localDW->Memory1_PreviousInput[1];

  /* Update for Memory: '<Root>/Memory' */
  localDW->Memory_PreviousInput[1] = rtu_position_in[1];

  /* Update for Memory: '<Root>/Memory1' */
  localDW->Memory1_PreviousInput[1] = rtu_trajectory_in[1];
}

/* Model initialize function */
void MemoryBlock_initialize(const char_T **rt_errorStatus,
  RT_MODEL_MemoryBlock_T *const MemoryBlock_M, DW_MemoryBlock_f_T *localDW)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(MemoryBlock_M, rt_errorStatus);

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(DW_MemoryBlock_f_T));
}
