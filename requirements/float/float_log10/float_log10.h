#include "../float_log/float_log.h"

static const float two25_log10 = 3.3554432000e+07,
ivln10_log10 = 4.3429449201e-01,
log10_2hi_log10 = 3.0102920532e-01,
log10_2lo_log10 = 7.9034151668e-07;

static const float zero = 0.0;

float __ieee754_log10f(float x){
 float y,z;
 __int32_t i,k,hx;

 do { ieee_float_shape_type gf_u; gf_u.value = (x); (hx) = gf_u.word; } while (0);

        k=0;
        if (((hx&0x7fffffff)==0))
            return -two25_log10/zero;
        if (hx<0) return (x-x)/zero;
 if (!((hx)<0x7f800000L)) return x+x;
        if (((hx)<0x00800000L)) {
            k -= 25; x *= two25_log10;
     do { ieee_float_shape_type gf_u; gf_u.value = (x); (hx) = gf_u.word; } while (0);
        }
 k += (hx>>23)-127;
 i = ((__uint32_t)k&0x80000000)>>31;
        hx = (hx&0x007fffff)|((0x7f-i)<<23);
        y = (float)(k+i);
 do { ieee_float_shape_type sf_u; sf_u.word = (hx); (x) = sf_u.value; } while (0);
 z = y*log10_2lo_log10 + ivln10_log10*__ieee754_logf(x);
 return z+y*log10_2hi_log10;
}
