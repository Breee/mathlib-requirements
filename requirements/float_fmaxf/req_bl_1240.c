#include "../includes/verify.h"
#include "../includes/math_functions_float.h"

float fmax_float(float x, float y) {
  if (__fpclassifyf(x) == 0) {
    return y;
  }

  if (__fpclassifyf(y) == 0) {
    return x;
  }
  return x > y ? x : y;
}

int main()
{

  /* REQ-BL-1240:
  * The fmax and fmaxf procedures shall determine the
  * maximum numeric value of the argument x and y.
  */

  float x = __VERIFIER_nondet_float();
	float y = __VERIFIER_nondet_float();

  // continue if x or y is not nan, both not nan, x and y not +-0 at the same time.
  // this IF-statement excludes the cases of the other requirements.
  if(!isnan_float(x) && !isnan_float(y)
     && ((x != -0.0f &&  y != +0.0f) || (x != +0.0f && y != -0.0f))) {

    __VERIFIER_precond_reach();

  	float res = fmax_float(x, y);

    // x is bigger than y, then the result should be x
  	if (x > y && res != x)	{
  		__VERIFIER_error();
  		return 1;
  	}

    // x is smaller or equal to y,  then the result shall be y
    if (x <= y && res != y )	{
  		__VERIFIER_error();
  		return 1;
  	}
  }

	return 0;
}
