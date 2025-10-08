/*
 * rt_assert.h
 *
 * Code generation for model "Verification".
 *
 * Model version              : 1.5
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Tue Aug 19 04:33:05 2025
 */

#ifndef rt_assert_h_
#define rt_assert_h_

/*=========*
 * Asserts *
 *=========*/
#ifndef utAssert
#if defined(DOASSERTS)
#if !defined(PRINT_ASSERTS)
#include <assert.h>
#define utAssert(exp)                  assert(exp)
#else
#include <stdio.h>

static void _assert(char_T *statement, char_T *file, int line)
{
  printf("%s in %s on line %d\n", statement, file, line);
}

#define utAssert(_EX)                  ((_EX) ? (void)0 : _assert(#_EX, __FILE__, __LINE__))
#endif

#else
#define utAssert(exp)                                            /* do nothing */
#endif
#endif
#endif                                 /* rt_assert_h_ */
