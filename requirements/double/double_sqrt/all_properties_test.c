#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_sqrt.h"


int main() {
  double x = __VERIFIER_nondet_double();
	double res = __ieee754_sqrt(x);
	return res;
}
