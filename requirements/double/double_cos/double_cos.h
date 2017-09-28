#include "../../includes/double_sin_cos_tan.h"

/*
 * Preprocessed code for the function libs/newlib/math/s_cos.c (Constants are defined in requrements/includes/math_constants_double.h)
 */

double cos_double(double x){
double y[2],z=0.0;
__int32_t n,ix;
do { ieee_double_shape_type gh_u; gh_u.value = (x); (ix) = gh_u.parts.msw; } while (0);


ix &= 0x7fffffff;
if(ix <= 0x3fe921fb) return __kernel_cos(x,z);


else if (ix>=0x7ff00000) return x-x;


else {
    n = __ieee754_rem_pio2(x,y);
    switch(n&3) {
 case 0: return __kernel_cos(y[0],y[1]);
 case 1: return -__kernel_sin(y[0],y[1],1);
 case 2: return -__kernel_cos(y[0],y[1]);
 default:
         return __kernel_sin(y[0],y[1],1);
    }
}
}
