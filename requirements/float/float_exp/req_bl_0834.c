#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_exp.h"

int main() {

  /* REQ-BL-0834
   * The exp and expf procedures shall return the argument if the argument x is +Inf .
   */

  float x = INFINITY;
	float res = __ieee754_expf(x);

  // x is +inf, the result shall be x
  if (res != x) {
  	__VERIFIER_error();
  	return 1;
  }

	return 0;
}
