#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_round.h"

int main() {

  /*
   * REQ-BL-1031//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
   * The round and roundf procedures shall return NaN , if the argument x is NaN
   * .
   */

  float x = 0.0f / 0.0f; // NAN
  __VERIFIER_precond_reach();
  float res = round_float(x);

  // result shall be NAN
  if (!isnan_float(res)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
