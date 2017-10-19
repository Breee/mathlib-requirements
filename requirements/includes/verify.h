#include <stdio.h>

/*
* Defines for the different tools.
*/

#if defined(INFER)

void __VERIFIER_error() { printf("ERROR"); }

extern float __infer_nondet_float();
extern double __infer_nondet_double();

float __VERIFIER_nondet_float() { return __infer_nondet_float(); }

double __VERIFIER_nondet_double() { return __infer_nondet_double(); }

#elif defined(CBMC) || defined(ULTIMATE) || defined(UAUTOMIZER) ||             \
    defined(UKOJAK) || defined(UTAIPAN) || defined(CPACHECKER)

extern void __VERIFIER_error() __attribute__((__noreturn__));
extern float __VERIFIER_nondet_float();
extern float __VERIFIER_nondet_double();

#elif defined(FRAMAC)

void __VERIFIER_error() {
  // Frama_C_dump_each();
  //@ assert \false;
}

float __VERIFIER_nondet_float();

double __VERIFIER_nondet_double();

#elif defined(CLANG)

void __VERIFIER_error() {
  *(int *)0 = 0; // Nullpointer, segfault.
}

float __VERIFIER_nondet_float();
double __VERIFIER_nondet_double();

#elif defined(COVERITY)

void __VERIFIER_error() {
  *(int *)0 = 0; // Nullpointer, segfault.
}

float __VERIFIER_nondet_float() {
  float x;
  return x;
}

double __VERIFIER_nondet_double() {
  double x;
  return x;
}

#elif defined(CWITNESS)

float float_values[2] = {0.0, 0.1};
double double_values[2] = {0.0, 0.1};
int idx = 0;

void __VERIFIER_error() { printf("Error"); }

float __VERIFIER_nondet_float() {
  float rtr = float_values[idx];
  idx++;
  return rtr;
}

double __VERIFIER_nondet_double() {
  double rtr = double_values[idx];
  idx++;
  return rtr;
}

#else

void __VERIFIER_error() {
  *(int *)0 = 0; // Nullpointer, segfault.
}

float __VERIFIER_nondet_float() {
  float x;
  return x;
}

double __VERIFIER_nondet_double() {
  double x;
  return x;
}

#endif

void __VERIFIER_precond_reach() {
#if defined(CHECK_PRECOND)
  __VERIFIER_error();
#endif
}
