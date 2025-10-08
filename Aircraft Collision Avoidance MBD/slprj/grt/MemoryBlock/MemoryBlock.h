/*
 * Code generation for system model 'MemoryBlock'
 * For more details, see corresponding source file MemoryBlock.c
 *
 */

#ifndef MemoryBlock_h_
#define MemoryBlock_h_
#ifndef MemoryBlock_COMMON_INCLUDES_
#define MemoryBlock_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#endif                                 /* MemoryBlock_COMMON_INCLUDES_ */

#include "MemoryBlock_types.h"
#include <string.h>

/* Block states (default storage) for model 'MemoryBlock' */
typedef struct {
  real_T Memory_PreviousInput[2];      /* '<Root>/Memory' */
  real_T Memory1_PreviousInput[2];     /* '<Root>/Memory1' */
} DW_MemoryBlock_f_T;

/* Parameters (default storage) */
struct P_MemoryBlock_T_ {
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<Root>/Memory1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_MemoryBlock_T {
  const char_T **errorStatus;
};

typedef struct {
  DW_MemoryBlock_f_T rtdw;
  RT_MODEL_MemoryBlock_T rtm;
} MdlrefDW_MemoryBlock_T;

/* Model reference registration function */
extern void MemoryBlock_initialize(const char_T **rt_errorStatus,
  RT_MODEL_MemoryBlock_T *const MemoryBlock_M, DW_MemoryBlock_f_T *localDW);
extern void MemoryBlock_Init(DW_MemoryBlock_f_T *localDW);
extern void MemoryBlock_Reset(DW_MemoryBlock_f_T *localDW);
extern void MemoryBlock(const real_T rtu_position_in[2], const real_T
  rtu_trajectory_in[2], real_T rty_position_out[2], real_T rty_trajectory_out[2],
  DW_MemoryBlock_f_T *localDW);

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
 * '<Root>' : 'MemoryBlock'
 */
#endif                                 /* MemoryBlock_h_ */
