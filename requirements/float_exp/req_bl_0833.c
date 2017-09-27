#include "../includes/verify.h"
#include "../includes/math_functions_float.h"

static const float halF[2] = {0.5,-0.5,},
twom100 = 7.8886090522e-31,
ln2HI[2] ={ 6.9313812256e-01,
      -6.9313812256e-01,},
ln2LO[2] ={ 9.0580006145e-06,
      -9.0580006145e-06,},
invln2 = 1.4426950216e+00;

float __ieee754_expf(float x) {
 float y,hi,lo,c,t;
 __int32_t k = 0,xsb,sx;
 __uint32_t hx;

 do { ieee_float_shape_type gf_u; gf_u.value = (x); (sx) = gf_u.word; } while (0);
 xsb = (sx>>31)&1;
 hx = sx & 0x7fffffff;
        if(((hx)>0x7f800000L))
            return x+x;
        if(((hx)==0x7f800000L))
     return (xsb==0)? x:0.0;
 if(sx > 0x42b17217)
     return huge*huge;
 if(sx < 0 && hx > 0x42cff1b5)
     return twom100*twom100;


 if(hx > 0x3eb17218) {
     if(hx < 0x3F851592) {
  hi = x-ln2HI[xsb]; lo=ln2LO[xsb]; k = 1-xsb-xsb;
     } else {
  k = invln2*x+halF[xsb];
  t = k;
  hi = x - t*ln2HI[0];
  lo = t*ln2LO[0];
     }
     x = hi - lo;
 }
 else if(hx < 0x31800000) {
     if(huge+x>one) return one+x;
 }

 t = x*x;
 c = x - t*(P1+t*(P2+t*(P3+t*(P4+t*P5))));
 if(k==0) return one-((x*c)/(c-(float)2.0)-x);
 else y = one-((lo-(x*c)/((float)2.0-c))-hi);
 if(k >= -125) {
     __uint32_t hy;
     do { ieee_float_shape_type gf_u; gf_u.value = (y); (hy) = gf_u.word; } while (0);
     do { ieee_float_shape_type sf_u; sf_u.word = (hy+(k<<23)); (y) = sf_u.value; } while (0);
     return y;
 } else {
     __uint32_t hy;
     do { ieee_float_shape_type gf_u; gf_u.value = (y); (hy) = gf_u.word; } while (0);
     do { ieee_float_shape_type sf_u; sf_u.word = (hy+((k+100)<<23)); (y) = sf_u.value; } while (0);
     return y*twom100;
 }
}

int main()
{

  /* REQ-BL-0833
   * The exp and expf procedures shall return +0 if the argument x is -Inf .
   */

  float x = -INFINITY;
 	float res = __ieee754_expf(x);

   // x is +inf, the result shall be x
   if (res != +0.0f) {
   	__VERIFIER_error();
   	return 1;
   }

	return 0;
}
