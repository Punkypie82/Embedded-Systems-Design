/*
 * File: Chart.c
 *
 * Code generated for Simulink model 'Chart'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Apr 25 12:34:52 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Chart.h"
#include "rtwtypes.h"

/* Named constants for Chart: '<Root>/Chart' */
#define IN_cargreen_pedred             ((uint8_T)1U)
#define IN_carred_pedgreen             ((uint8_T)2U)
#define IN_carred_pedred               ((uint8_T)3U)
#define IN_caryellow_pedred            ((uint8_T)4U)
#define IN_pending_pedred              ((uint8_T)5U)

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
void Chart_step(void)
{
  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/p'
   *  Outport: '<Root>/count'
   *  Outport: '<Root>/pcount'
   */
  if (rtDW.is_active_c3_Chart == 0U) {
    rtDW.is_active_c3_Chart = 1U;

    /* Outport: '<Root>/count' */
    rtY.count = 0.0;

    /* Outport: '<Root>/pcount' */
    rtY.pcount = 0.0;

    /* Outport: '<Root>/SR' */
    rtY.SR = 1.0;

    /* Outport: '<Root>/PG' */
    rtY.PG = 1.0;
    rtDW.is_c3_Chart = IN_carred_pedgreen;
  } else {
    switch (rtDW.is_c3_Chart) {
     case IN_cargreen_pedred:
      if (rtY.count < 60.0) {
        rtY.count++;
        rtDW.is_c3_Chart = IN_cargreen_pedred;
      } else if ((rtU.p != 0.0) && (rtY.count >= 60.0)) {
        rtY.count = 0.0;

        /* Outport: '<Root>/SY' */
        rtY.SY = 1.0;

        /* Outport: '<Root>/SG' */
        rtY.SG = 0.0;
        rtDW.is_c3_Chart = IN_caryellow_pedred;
      }
      break;

     case IN_carred_pedgreen:
      if (rtY.pcount >= 55.0) {
        /* Outport: '<Root>/count' */
        rtY.count++;

        /* Outport: '<Root>/PR' */
        rtY.PR = 1.0;

        /* Outport: '<Root>/PG' */
        rtY.PG = 0.0;
        rtDW.is_c3_Chart = IN_carred_pedred;
      } else {
        /* Outport: '<Root>/count' */
        rtY.count++;
        rtY.pcount++;
        rtDW.is_c3_Chart = IN_carred_pedgreen;
      }
      break;

     case IN_carred_pedred:
      if (rtY.count >= 60.0) {
        rtY.count++;

        /* Outport: '<Root>/SG' */
        rtY.SG = 1.0;

        /* Outport: '<Root>/SR' */
        rtY.SR = 0.0;
        rtDW.is_c3_Chart = IN_cargreen_pedred;
      } else {
        rtY.count++;
        rtDW.is_c3_Chart = IN_carred_pedred;
      }
      break;

     case IN_caryellow_pedred:
      if (rtY.pcount >= 5.0) {
        /* Outport: '<Root>/count' */
        rtY.count = 0.0;
        rtY.pcount = 0.0;

        /* Outport: '<Root>/SR' */
        rtY.SR = 1.0;

        /* Outport: '<Root>/PG' */
        rtY.PG = 1.0;

        /* Outport: '<Root>/SY' */
        rtY.SY = 0.0;

        /* Outport: '<Root>/PR' */
        rtY.PR = 0.0;
        rtDW.is_c3_Chart = IN_carred_pedgreen;
      } else {
        /* Outport: '<Root>/count' */
        rtY.count++;
        rtDW.is_c3_Chart = IN_caryellow_pedred;
      }
      break;

     default:
      /* case IN_pending_pedred: */
      if (rtY.count >= 60.0) {
        rtY.count = 0.0;

        /* Outport: '<Root>/SY' */
        rtY.SY = 1.0;

        /* Outport: '<Root>/SG' */
        rtY.SG = 0.0;
        rtDW.is_c3_Chart = IN_caryellow_pedred;
      } else {
        rtY.count++;
        rtDW.is_c3_Chart = IN_pending_pedred;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void Chart_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
