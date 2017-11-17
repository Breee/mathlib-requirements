#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_pow.h"

int main() {
	float x = __VERIFIER_nondet_float();
  float y = __VERIFIER_nondet_float();
  float res = __ieee754_powf(x,y);
	return res;
}
