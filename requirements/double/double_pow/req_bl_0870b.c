#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_pow.h"

int main() {

  /*
   * REQ-BL-0870//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The pow and powf procedures shall return NaN if
   *   the argument y is NaN and x is not 1, or
   *   the argument x is NaN and y is not +-0 .
   */

	double x = 0.0/0.0; // NAN
  double y = __VERIFIER_nondet_double();

  if(y != 0.0 && y != -0.0){
    __VERIFIER_precond_reach();

    double res = __ieee754_pow(x,y);

    // result shall be NAN
    if(!isnan_double(res)){
      __VERIFIER_error();
      return 1;
    }
  }

	return 0;
}
