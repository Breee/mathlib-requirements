#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_atan2.h"

int main() {
   double x = __VERIFIER_nondet_double();
   double y = __VERIFIER_nondet_double();
   double res = __ieee754_atan2(y, x);
 	return res;
}
