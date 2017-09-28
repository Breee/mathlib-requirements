#include "../../includes/verify.h"
#include "../../includes/math_functions_float.h"
#include "float_round.h"

int main() {

  /*
   * REQ-BL-1032//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The round and roundf procedures shall return the argument, if the argument x is +-0 or +-Inf .
   */

	float x = __VERIFIER_nondet_float();

  if(x == 0.0f || x == -0.0f || isinf_float(x)){

    __VERIFIER_precond_reach();

    float res = round_float(x);

    // result shall be x
    if(res != x){
      __VERIFIER_error();
      return 1;
    }

  }

	return 0;
}
