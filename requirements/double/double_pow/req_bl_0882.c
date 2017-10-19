#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_pow.h"

int main() {

  /*
   * REQ-BL-0882//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The pow and powf procedures shall return +0, if the argument x is +Inf and the argument y < 0.
   */

	double x = 1.0/0.0; // INF
  double y = __VERIFIER_nondet_double();

  if(y < 0.0){

    __VERIFIER_precond_reach();

    double res = __ieee754_pow(x, y);

    // result shall be +0
    if(!(res == 0.0 && __signbit_double(res) == 0)){
      __VERIFIER_error();
      return 1;
    }
  }

	return 0;
}
