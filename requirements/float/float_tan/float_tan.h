#include "../../includes/float_sin_cos_tan.h"

float tan_float(float x) {
float y[2],z=0.0;
__int32_t n,ix;

do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);


ix &= 0x7fffffff;
if(ix <= 0x3f490fda) return __kernel_tanf(x,z,1);


else if (!((ix)<0x7f800000L)) return x-x;


else {
    n = __ieee754_rem_pio2f(x,y);
    return __kernel_tanf(y[0],y[1],1-((n&1)<<1));

}
}
