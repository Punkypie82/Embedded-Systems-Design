/*
 * Code generation for system model 'ScenarioManager1'
 * For more details, see corresponding source file ScenarioManager1.c
 *
 */

#ifndef ScenarioManager1_h_
#define ScenarioManager1_h_
#ifndef ScenarioManager1_COMMON_INCLUDES_
#define ScenarioManager1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#endif                                 /* ScenarioManager1_COMMON_INCLUDES_ */

#include "ScenarioManager1_types.h"

/* Real-time Model Data Structure */
struct tag_RTM_ScenarioManager1_T {
  const char_T **errorStatus;
};

typedef struct {
  RT_MODEL_ScenarioManager1_T rtm;
} MdlrefDW_ScenarioManager1_T;

/* Model block global parameters (default storage) */
extern real_T rtP_AIRCRAFT1_GOAL[2];   /* Variable: AIRCRAFT1_GOAL
                                        * Referenced by: '<Root>/Constant1'
                                        */
extern real_T rtP_AIRCRAFT1_START[2];  /* Variable: AIRCRAFT1_START
                                        * Referenced by: '<Root>/Constant'
                                        */
extern real_T rtP_AIRCRAFT2_GOAL[2];   /* Variable: AIRCRAFT2_GOAL
                                        * Referenced by: '<Root>/Constant3'
                                        */
extern real_T rtP_AIRCRAFT2_START[2];  /* Variable: AIRCRAFT2_START
                                        * Referenced by: '<Root>/Constant2'
                                        */

/* Model reference registration function */
extern void ScenarioManager1_initialize(const char_T **rt_errorStatus,
  RT_MODEL_ScenarioManager1_T *const ScenarioManager1_M);
extern void ScenarioManager1_Init(real_T rty_start_position_aircraft1[2], real_T
  rty_goal_position_aircraft1[2], real_T rty_start_position_aircraft2[2], real_T
  rty_goal_position_aircraft2[2]);
extern void ScenarioManager1(real_T rty_start_position_aircraft1[2], real_T
  rty_goal_position_aircraft1[2], real_T rty_start_position_aircraft2[2], real_T
  rty_goal_position_aircraft2[2]);

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
 * '<Root>' : 'ScenarioManager1'
 */
#endif                                 /* ScenarioManager1_h_ */
