#include "../../includes/verify.h"
#include "../../includes/math_functions_double.h"
#include "double_fmax.h"

int main()
{
	// REQ-BL-1250
	double x = 0.0/0.0;
	double y = 0.0/0.0;

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
