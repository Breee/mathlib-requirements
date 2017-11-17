#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_hypot.h"

int main() {
  double x = __VERIFIER_nondet_double();
  double y = __VERIFIER_nondet_double();
  double res = __ieee754_hypot(x, y);
	return res;
}
