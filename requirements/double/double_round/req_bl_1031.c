#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_round.h"

int main() {

  /*
   * REQ-BL-1031//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The round and roundf procedures shall return NaN , if the argument x is NaN .
   */

	double x = NAN;

  if(isnan_double(x)){

    __VERIFIER_precond_reach();

    double res = round_double(x);

    // result shall be NAN
    if(!isnan_double(res)){
      __VERIFIER_error();
      return 1;
    }

  }

	return 0;
}
