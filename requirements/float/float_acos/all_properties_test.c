#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_acos.h"

int main()
{

  float x = __VERIFIER_nondet_float();
  float res = __ieee754_acosf(x);

	return res;
}
