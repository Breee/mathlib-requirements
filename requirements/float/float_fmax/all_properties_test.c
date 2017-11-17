#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_fmax.h"

int main(){
  float x = __VERIFIER_nondet_float();
	float y = __VERIFIER_nondet_float();
  float res = fmax_float(x, y);
	return res;
}
