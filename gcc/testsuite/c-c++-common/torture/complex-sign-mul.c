/* Test complex arithmetic with signed zeros.  Pure complex
   multiplication.  */
/* { dg-do run } */
/* { dg-options "-std=gnu99" { target c } } */
/* { dg-additional-options "-mcmodel=small" { target ia16-*-* } } */

#include "complex-sign.h"

#define CHECK_MUL(TYPE, COPY, ZERO, ZEROI)			\
  do {								\
    CHECK_ARITH (TYPE, COPY, ZERO, ZEROI, *, +, +, +, +, +, +);	\
    CHECK_ARITH (TYPE, COPY, ZERO, ZEROI, *, +, +, +, -, +, +);	\
    CHECK_ARITH (TYPE, COPY, ZERO, ZEROI, *, +, +, -, +, -, +);	\
    CHECK_ARITH (TYPE, COPY, ZERO, ZEROI, *, +, +, -, -, +, -);	\
    CHECK_ARITH (TYPE, COPY, ZERO, ZEROI, *, +, -, +, +, +, +);	\
    CHECK_ARITH (TYPE, COPY, ZERO, ZEROI, *, +, -, +, -, +, -);	\
    CHECK_ARITH (TYPE, COPY, ZERO, ZEROI, *, +, -, -, +, +, +);	\
    CHECK_ARITH (TYPE, COPY, ZERO, ZEROI, *, +, -, -, -, -, +);	\
    CHECK_ARITH (TYPE, COPY, ZERO, ZEROI, *, -, +, +, +, -, +);	\
    CHECK_ARITH (TYPE, COPY, ZERO, ZEROI, *, -, +, +, -, +, +);	\
    CHECK_ARITH (TYPE, COPY, ZERO, ZEROI, *, -, +, -, +, +, -);	\
    CHECK_ARITH (TYPE, COPY, ZERO, ZEROI, *, -, +, -, -, +, +);	\
    CHECK_ARITH (TYPE, COPY, ZERO, ZEROI, *, -, -, +, +, +, -);	\
    CHECK_ARITH (TYPE, COPY, ZERO, ZEROI, *, -, -, +, -, -, +);	\
    CHECK_ARITH (TYPE, COPY, ZERO, ZEROI, *, -, -, -, +, +, +);	\
    CHECK_ARITH (TYPE, COPY, ZERO, ZEROI, *, -, -, -, -, +, +);	\
  } while (0)

void
check_mul_float (void)
{
#ifndef __SPU__
  CHECK_MUL (float, __builtin_copysignf, 0.0f, 0.0if);
#endif
}

void
check_mul_double (void)
{
  CHECK_MUL (double, __builtin_copysign, 0.0, 0.0i);
}

void
check_mul_long_double (void)
{
  CHECK_MUL (long double, __builtin_copysignl, 0.0l, 0.0il);
}

int
main (void)
{
  check_mul_float ();
  check_mul_double ();
  check_mul_long_double ();
  exit (0);
}
