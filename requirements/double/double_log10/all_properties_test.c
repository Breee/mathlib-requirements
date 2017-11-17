#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_log10.h"

int main() {
  double x = __VERIFIER_nondet_double();
  double res = __ieee754_log10(x);
	return res;
}
