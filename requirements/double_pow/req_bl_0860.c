#include "../includes/verify.h"
#include "../includes/math_functions_double.h"
#include "double_pow.h"

int main() {

  /*
  * REQ-BL-0860//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
  * The pow and powf procedures shall return NaN if the argument x is < 0 and finite,
  * and the argument y is a finite, non-integer value.
  */

	double x = __VERIFIER_nondet_double();
  double y = __VERIFIER_nondet_double();

  if(x < 0 && isfinite_double(x) && isfinite_double(y) && !isinteger_double(y)){
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
