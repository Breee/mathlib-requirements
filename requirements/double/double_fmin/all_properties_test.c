#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_fmin.h"

int main(){
  double x = __VERIFIER_nondet_double();
  double y = __VERIFIER_nondet_double();
  double res = fmin_double(x, y);
	return res;
}
