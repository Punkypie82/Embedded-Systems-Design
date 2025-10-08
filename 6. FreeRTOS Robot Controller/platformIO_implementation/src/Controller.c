
/*
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue May 13 23:10:08 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Controller.h"
#include "rtwtypes.h"

/* Named constants for Chart: '<Root>/Controller' */
#define IN_approach                    ((uint8_T)1U)
#define IN_idle                        ((uint8_T)2U)
#define IN_retreat                     ((uint8_T)3U)
#define IN_stay                        ((uint8_T)4U)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void Controller_step(void)
{
  /* Chart: '<Root>/Controller' incorporates:
   *  Inport: '<Root>/distance'
   *  Inport: '<Root>/ppm'
   *  Inport: '<Root>/threshold'
   */
  if (rtDW.is_active_c3_Controller == 0U) {
    rtDW.is_active_c3_Controller = 1U;
    rtDW.is_c3_Controller = IN_idle;
  } else {
    switch (rtDW.is_c3_Controller) {
     case IN_approach:
      if ((rtU.ppm <= 400.0) || (rtU.ppm >= rtU.threshold) || (rtU.distance <
           100.0)) {
        /* Outport: '<Root>/fan' */
        rtY.fan = 0.0;

        /* Outport: '<Root>/motor' */
        rtY.motor = -1.0;
        rtDW.is_c3_Controller = IN_retreat;
      } else if ((rtU.ppm < rtU.threshold) && ((rtU.distance > 100.0) &&
                  (rtU.distance < 110.0))) {
        /* Outport: '<Root>/motor' */
        rtY.motor = 0.0;
        rtDW.is_c3_Controller = IN_stay;
      }
      break;

     case IN_idle:
      if (rtU.ppm > 400.0) {
        /* Outport: '<Root>/fan' */
        rtY.fan = 1.0;

        /* Outport: '<Root>/motor' */
        rtY.motor = 1.0;
        rtDW.is_c3_Controller = IN_approach;
      }
      break;

     case IN_retreat:
      if (rtU.ppm <= 400.0) {
        /* Outport: '<Root>/fan' */
        rtY.fan = 0.0;

        /* Outport: '<Root>/motor' */
        rtY.motor = 0.0;
        rtDW.is_c3_Controller = IN_idle;
      } else if ((rtU.ppm < rtU.threshold) && (rtU.distance > 110.0)) {
        /* Outport: '<Root>/fan' */
        rtY.fan = 1.0;

        /* Outport: '<Root>/motor' */
        rtY.motor = 1.0;
        rtDW.is_c3_Controller = IN_approach;
      } else if ((rtU.ppm < rtU.threshold) && ((rtU.distance > 100.0) &&
                  (rtU.distance < 110.0))) {
        /* Outport: '<Root>/motor' */
        rtY.motor = 0.0;
        rtDW.is_c3_Controller = IN_stay;
      }
      break;

     default:
      /* case IN_stay: */
      if ((rtU.ppm <= 400.0) || (rtU.ppm >= rtU.threshold) || (rtU.distance <
           100.0)) {
        /* Outport: '<Root>/fan' */
        rtY.fan = 0.0;

        /* Outport: '<Root>/motor' */
        rtY.motor = -1.0;
        rtDW.is_c3_Controller = IN_retreat;
      } else if ((rtU.ppm < rtU.threshold) && (rtU.distance > 110.0)) {
        /* Outport: '<Root>/motor' */
        rtY.motor = 1.0;
        rtDW.is_c3_Controller = IN_approach;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Controller' */
}

/* Model initialize function */
void Controller_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */