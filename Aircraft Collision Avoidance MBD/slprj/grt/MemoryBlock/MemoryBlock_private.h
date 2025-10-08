/*
 * MemoryBlock_private.h
 *
 * Code generation for model "MemoryBlock".
 *
 * Model version              : 1.4
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Tue Aug 19 04:32:58 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef MemoryBlock_private_h_
#define MemoryBlock_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "MemoryBlock.h"
#include "MemoryBlock_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

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

extern P_MemoryBlock_T MemoryBlock_P;

#endif                                 /* MemoryBlock_private_h_ */
