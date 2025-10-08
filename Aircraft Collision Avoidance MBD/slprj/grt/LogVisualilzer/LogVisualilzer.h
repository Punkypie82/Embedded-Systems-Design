/*
 * Code generation for system model 'LogVisualilzer'
 * For more details, see corresponding source file LogVisualilzer.c
 *
 */

#ifndef LogVisualilzer_h_
#define LogVisualilzer_h_
#ifndef LogVisualilzer_COMMON_INCLUDES_
#define LogVisualilzer_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#endif                                 /* LogVisualilzer_COMMON_INCLUDES_ */

#include "LogVisualilzer_types.h"

/* Real-time Model Data Structure */
struct tag_RTM_LogVisualilzer_T {
  const char_T **errorStatus;
};

typedef struct {
  RT_MODEL_LogVisualilzer_T rtm;
} MdlrefDW_LogVisualilzer_T;

/* Model reference registration function */
extern void LogVisualilzer_initialize(const char_T **rt_errorStatus,
  RT_MODEL_LogVisualilzer_T *const LogVisualilzer_M);

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
 * '<Root>' : 'LogVisualilzer'
 */
#endif                                 /* LogVisualilzer_h_ */
