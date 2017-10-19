#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_exp.h"

int main() {
  /* REQ-BL-0831
   * The exp and expf procedures shall return NaN if the argument x is NaN .
   */

  float x = 0.0f / 0.0f; // NAN
  float res = __ieee754_expf(x);

  // x is NAN, the result shall be x
  if (!isnan_float(res)) {
    __VERIFIER_error();
    return 1;
  }

  return 0;
}
