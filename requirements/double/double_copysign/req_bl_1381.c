#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_copysign.h"


int main() {

  /*
   * REQ-BL-1381:
   * The copysign and copysignf procedures shall return NaN if the argument x is NaN .
   */

  double x = 0.0/0.0; // NAN
  double y = __VERIFIER_nondet_double();
  __VERIFIER_precond_reach();
  double res = copysign_double(x, y);

  // x is NAN, y can be any, the result shall be NAN
  if (!isnan_double(res)){
  	__VERIFIER_error();
  	return 1;
  }
	return 0;
}
