#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_fmin.h"

int main() {
  float x = __VERIFIER_nondet_float();
  float y = __VERIFIER_nondet_float();
  float res = fmin_float(x, y);
  return res;
}
