#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_log.h"

int main() {
  double x = __VERIFIER_nondet_double();
  double res = __ieee754_log(x);
	return res;
}
