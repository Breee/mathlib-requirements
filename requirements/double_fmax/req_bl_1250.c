#include "../includes/verify.h"
#include "../includes/math_functions_double.h"

double fmax_double(double x, double y) {

 if (__fpclassifyd(x) == 0)
   return y;
 if (__fpclassifyd(y) == 0)
   return x;

 return x > y ? x : y;
}

int main()
{
	// REQ-BL-1250
	double x = NAN; // NAN
	double y = NAN; // NAN

  // REQ-BL-1250: The fmax and fmaxf procedures shall return NaN, if the arguments x and y are NaN.
	if (isnan_double(x) && isnan_double(y)) {
    __VERIFIER_precond_reach();

    double res = fmax_double(x, y);

    if (!isnan_double(res))	{
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
