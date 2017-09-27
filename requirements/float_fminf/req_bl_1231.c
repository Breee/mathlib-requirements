#include "../includes/verify.h"
#include "../includes/math_functions_float.h"

float fmin_float(float x, float y) {
 if (__fpclassifyf(x) == 0)
   return y;
 if (__fpclassifyf(y) == 0)
   return x;

 return x < y ? x : y;
}

int main() {


  /* REQ-BL-1231:
  * The fmin and fminf procedures shall return the one argument
  * if only the other argument is NaN.
  */

  float x = __VERIFIER_nondet_float();
  float y = __VERIFIER_nondet_float();
  if ((isnan_float(x) && !isnan_float(y)) || (!isnan_float(x) && isnan_float(y))) {

    __VERIFIER_precond_reach();

    float res = fmin_float(x, y);

    // x is NAN and y is not NAN, the result shall be y
    if (isnan_float(x) && !isnan_float(y) && res != y)	{
      __VERIFIER_error();
      return 1;
    }

    // y is NAN and x is not NAN, the result shall be x
    if (!isnan_float(x) && isnan_float(y) && res != x)	{
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
