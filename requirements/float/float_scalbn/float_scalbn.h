#include "../float_copysign/float_copysign.h"

static const float two25_scalbn = 3.355443200e+07,
twom25_scalbn = 2.9802322388e-08,
huge_scalbn = 1.0e+30,
tiny_scalbn = 1.0e-30;

float scalbnf (float x, int n) {
 __int32_t k,ix;
 __uint32_t hx;

 do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
 hx = ix&0x7fffffff;
        k = hx>>23;
 if (((hx)==0))
     return x;
        if (!((hx)<0x7f800000L))
     return x+x;
        if (((hx)<0x00800000L)) {
     x *= two25_scalbn;
     do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
     k = ((ix&0x7f800000)>>23) - 25;
            if (n< -50000) return tiny_scalbn*x;
        }
        k = k+n;
        if (k > (0x7f7fffffL>>23)) return huge_scalbn*copysign_float(huge_scalbn,x);
        if (k > 0)
     {do { ieee_float_shape_type sf_u; sf_u.word = ((ix&0x807fffff)|(k<<23)); (x) = sf_u.value; } while (0); return x;}
        if (k < -22) {
            if (n > 50000)
  return huge_scalbn*copysign_float(huge_scalbn,x);
     else return tiny_scalbn*copysign_float(tiny_scalbn,x);
        }
        k += 25;
 do { ieee_float_shape_type sf_u; sf_u.word = ((ix&0x807fffff)|(k<<23)); (x) = sf_u.value; } while (0);
        return x*twom25_scalbn;
}
