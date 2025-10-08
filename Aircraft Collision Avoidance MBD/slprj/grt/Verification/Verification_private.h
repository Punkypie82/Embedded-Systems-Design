/*
 * Verification_private.h
 *
 * Code generation for model "Verification".
 *
 * Model version              : 1.5
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Tue Aug 19 04:33:05 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Verification_private_h_
#define Verification_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Verification.h"
#include "Verification_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        ((rtmGetSimTimeStep((rtm))) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        ((rtmGetSimTimeStep((rtm))) == MINOR_TIME_STEP)
#endif

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         (*((rtm)->Timing.simTimeStep))
#endif

#ifndef rtmGetSimTimeStepPointer
#define rtmGetSimTimeStepPointer(rtm)  (rtm)->Timing.simTimeStep
#endif

#ifndef rtmSetSimTimeStepPointer
#define rtmSetSimTimeStepPointer(rtm, val) ((rtm)->Timing.simTimeStep = (val))
#endif

extern P_Verification_T Verification_P;

#endif                                 /* Verification_private_h_ */
