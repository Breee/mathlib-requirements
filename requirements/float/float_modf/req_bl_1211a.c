#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_modf.h"

int main() {

  /* REQ-BL-1211
   * The modf and modff procedures shall return ±0 and set the argument ∗iptr to
   * +-Inf , if the argument x is +-Inf .
   */

  float x = 1.0f / 0.0f; // INF
  float iptr = __VERIFIER_nondet_float();
  __VERIFIER_precond_reach();
  float res = modf_float(x, &iptr);

  // x is inf, *iptr is inf, result shall be -+0
  if (isinf_float(iptr) && !(res == 0.0f && __signbit_float(res) == 0)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
