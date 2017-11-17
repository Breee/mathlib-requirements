#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_atan2.h"

int main()
{
  float x = __VERIFIER_nondet_float();
  float y = __VERIFIER_nondet_float();
  float res = __ieee754_atan2f(y, x);
 	return res;
}
