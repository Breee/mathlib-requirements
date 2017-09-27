#include "../../libs/newlib/libm/common/fdlibm.h"
#include <stdio.h>
#include <math.h>


/*
* Defines for the different tools.
*/

#if defined(INFER)

#include "/opt/infer-linux64-v0.12.0/infer/models/c/src/infer_builtins.h"

void __VERIFIER_error() {
	int *x;
	int y;
	y = *x;
}

float __VERIFIER_nondet_float() {
	return __infer_nondet_float() ;
}

double __VERIFIER_nondet_double() {
	return __infer_nondet_double() ;
}

#elif defined(CBMC) || defined(ULTIMATE)

  extern void __VERIFIER_error();
  extern float __VERIFIER_nondet_float();
  extern float __VERIFIER_nondet_double();

#elif defined(FRAMAC)

  void __VERIFIER_error(){
	  //@ assert \false;
  }

  //@ assigns \result \from \nothing;
  float __VERIFIER_nondet_float();

  //@ assigns \result \from \nothing;
  double __VERIFIER_nondet_double();

#elif defined(CLANG)

  extern void clang_analyzer_warnIfReached();

  void __VERIFIER_error() {
	  clang_analyzer_warnIfReached();
  }

  float __VERIFIER_nondet_float();
  double __VERIFIER_nondet_double();


#elif defined(COVERITY)

#elif defined(CWITNESS)

float float_values[2] = {0.0,0.1};
double double_values[2] = {0.0,0.1};
int idx  = 0;

void __VERIFIER_error(){
	printf("Error");
}

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

void __VERIFIER_error(){
	printf("Error");
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
#if defined (CHECK_PRECOND)
	__VERIFIER_error();
#endif
}
