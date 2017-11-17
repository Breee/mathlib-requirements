#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_exp.h"

int main() {
  double x = __VERIFIER_nondet_double();
 	double res = __ieee754_exp(x);
	return res;
}
