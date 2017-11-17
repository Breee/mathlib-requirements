#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_asin.h"


int main() {
  double x = __VERIFIER_nondet_double();
  double res = __ieee754_asin(x);
	return res;
}
