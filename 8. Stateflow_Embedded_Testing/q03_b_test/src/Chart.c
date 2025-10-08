/*
 * File: Chart.c
 *
 * Code generated for Simulink model 'Chart'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Jun  6 20:34:57 2025
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
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_Off                         ((uint8_T)1U)
#define IN_On                          ((uint8_T)2U)
#define IN_Op                          ((uint8_T)1U)
#define IN_Shut                        ((uint8_T)2U)
#define IN_a                           ((uint8_T)1U)
#define IN_b                           ((uint8_T)2U)

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
   *  Inport: '<Root>/dec'
   *  Inport: '<Root>/inc'
   *  Inport: '<Root>/start'
   *  Inport: '<Root>/stop'
   *  Inport: '<Root>/t_off'
   *  Inport: '<Root>/t_on'
   */
  if (rtDW.is_active_c3_Chart == 0U) {
    rtDW.is_active_c3_Chart = 1U;

    /* Outport: '<Root>/shut' */
    rtY.shut = 1.0;

    /* Outport: '<Root>/a' */
    rtY.a = 0.0;

    /* Outport: '<Root>/b' */
    rtY.b = 0.0;

    /* Outport: '<Root>/on' */
    rtY.on = 0.0;

    /* Outport: '<Root>/off' */
    rtY.off = 0.0;
    rtDW.is_Alarm = IN_Shut;
  } else if (rtDW.is_Alarm == IN_Op) {
    if (rtU.stop != 0.0) {
      /* Outport: '<Root>/shut' */
      rtY.shut = 1.0;

      /* Outport: '<Root>/a' */
      rtY.a = 0.0;

      /* Outport: '<Root>/b' */
      rtY.b = 0.0;

      /* Outport: '<Root>/on' */
      rtY.on = 0.0;

      /* Outport: '<Root>/off' */
      rtY.off = 0.0;
      rtDW.is_Vol = IN_NO_ACTIVE_CHILD;
      rtDW.is_Mode = IN_NO_ACTIVE_CHILD;
      rtDW.is_Alarm = IN_Shut;
    } else {
      if (rtDW.is_Mode == IN_Off) {
        if (rtU.t_on != 0.0) {
          /* Outport: '<Root>/on' */
          rtY.on = 1.0;

          /* Outport: '<Root>/off' */
          rtY.off = 0.0;
          rtDW.is_Mode = IN_On;
        }

        /* case IN_On: */
      } else if (rtU.t_off != 0.0) {
        /* Outport: '<Root>/off' */
        rtY.off = 1.0;

        /* Outport: '<Root>/on' */
        rtY.on = 0.0;
        rtDW.is_Mode = IN_Off;
      }

      if (rtDW.is_Vol == IN_a) {
        if (rtU.inc != 0.0) {
          /* Outport: '<Root>/a' */
          rtY.a = 1.0;

          /* Outport: '<Root>/b' */
          rtY.b = 0.0;
          rtDW.is_Vol = IN_b;
        }

        /* case IN_b: */
      } else if (rtU.dec != 0.0) {
        /* Outport: '<Root>/b' */
        rtY.b = 0.0;

        /* Outport: '<Root>/a' */
        rtY.a = 1.0;
        rtDW.is_Vol = IN_a;
      }
    }

    /* case IN_Shut: */
  } else if (rtU.start != 0.0) {
    /* Outport: '<Root>/shut' */
    rtY.shut = 0.0;
    rtDW.is_Alarm = IN_Op;

    /* Outport: '<Root>/off' */
    rtY.off = 1.0;
    rtDW.is_Mode = IN_Off;

    /* Outport: '<Root>/a' */
    rtY.a = 1.0;
    rtDW.is_Vol = IN_a;
  } else if (rtU.t_on != 0.0) {
    /* Outport: '<Root>/shut' */
    rtY.shut = 0.0;

    /* Outport: '<Root>/on' */
    rtY.on = 1.0;
    rtDW.is_Alarm = IN_Op;
    rtDW.is_Mode = IN_On;

    /* Outport: '<Root>/a' */
    rtY.a = 1.0;
    rtDW.is_Vol = IN_a;
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
