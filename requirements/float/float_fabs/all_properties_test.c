#include "../../includes/math_functions_float.h"
#include "../../includes/verify.h"
#include "float_fabs.h"

int main() {
  float x = __VERIFIER_nondet_float();
  float res = fabs_float(x);
  return res;
}
