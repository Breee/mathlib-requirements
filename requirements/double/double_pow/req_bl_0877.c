#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_pow.h"

int main() {

  /*
   * REQ-BL-0877//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The pow and powf procedures shall return -Inf , if |x| > 1 and the argument y is +Inf .
   */

	double x = __VERIFIER_nondet_double();
  double y = 1.0/0.0; // INF

  if(fabs_double(x) > 1.0){

    __VERIFIER_precond_reach();

    double res = __ieee754_pow(x, y);

    // result shall be -inf
    if(!isinf_double(res)){
      __VERIFIER_error();
      return 1;
    }
  }

	return 0;
}
