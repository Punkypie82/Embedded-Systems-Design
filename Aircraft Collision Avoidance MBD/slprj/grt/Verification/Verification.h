/*
 * Code generation for system model 'Verification'
 * For more details, see corresponding source file Verification.c
 *
 */

#ifndef Verification_h_
#define Verification_h_
#ifndef Verification_COMMON_INCLUDES_
#define Verification_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#endif                                 /* Verification_COMMON_INCLUDES_ */

#include "Verification_types.h"
#include <string.h>

/* Parameters (default storage) */
struct P_Verification_T_ {
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  boolean_T Assertion_Enabled;         /* Computed Parameter: Assertion_Enabled
                                        * Referenced by: '<Root>/Assertion'
                                        */
  boolean_T Assertion1_Enabled;        /* Computed Parameter: Assertion1_Enabled
                                        * Referenced by: '<Root>/Assertion1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Verification_T {
  const char_T **errorStatus;
  RTWSolverInfo *solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize0;
    SimTimeStep *simTimeStep;
  } Timing;
};

typedef struct {
  RT_MODEL_Verification_T rtm;
} MdlrefDW_Verification_T;

/* Model block global parameters (default storage) */
extern real_T rtP_MIN_SEP_KM;          /* Variable: MIN_SEP_KM
                                        * Referenced by: '<Root>/Constant'
                                        */

/* Model reference registration function */
extern void Verification_initialize(const char_T **rt_errorStatus, RTWSolverInfo
  *rt_solverInfo, RT_MODEL_Verification_T *const Verification_M);
extern void Verification(RT_MODEL_Verification_T * const Verification_M, const
  real_T rtu_aircraft1_position[2], const real_T rtu_aircraft2_position[2]);

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
 * '<Root>' : 'Verification'
 * '<S1>'   : 'Verification/safezone'
 */
#endif                                 /* Verification_h_ */
