#include "../float_sqrt/float_sqrt.h"

static const float one_acos = 1.0000000000e+00,
pi = 3.1415925026e+00,
pio2_hi_acos = 1.5707962513e+00,
pio2_lo_acos = 7.5497894159e-08,
pS0_acos = 1.6666667163e-01,
pS1_acos = -3.2556581497e-01,
pS2_acos = 2.0121252537e-01,
pS3_acos = -4.0055535734e-02,
pS4_acos = 7.9153501429e-04,
pS5_acos = 3.4793309169e-05,
qS1_acos = -2.4033949375e+00,
qS2_acos = 2.0209457874e+00,
qS3_acos = -6.8828397989e-01,
qS4_acos = 7.7038154006e-02;


float __ieee754_acosf(float x) {
 float z,p,q,r,w,s,c,df;
 __int32_t hx,ix;
 do { ieee_float_shape_type gf_u; gf_u.value = (x); (hx) = gf_u.word; } while (0);
 ix = hx&0x7fffffff;
 if(ix==0x3f800000) {
     if(hx>0) return 0.0;
     else return pi+(float)2.0*pio2_lo_acos;
 } else if(ix>0x3f800000) {
     return (x-x)/(x-x);
 }
 if(ix<0x3f000000) {
     if(ix<=0x23000000) return pio2_hi_acos+pio2_lo_acos;
     z = x*x;
     p = z*(pS0_acos+z*(pS1_acos+z*(pS2_acos+z*(pS3_acos+z*(pS4_acos+z*pS5_acos)))));
     q = one_acos+z*(qS1_acos+z*(qS2_acos+z*(qS3_acos+z*qS4_acos)));
     r = p/q;
     return pio2_hi_acos - (x - (pio2_lo_acos-x*r));
 } else if (hx<0) {
     z = (one_acos+x)*(float)0.5;
     p = z*(pS0_acos+z*(pS1_acos+z*(pS2_acos+z*(pS3_acos+z*(pS4_acos+z*pS5_acos)))));
     q = one_acos+z*(qS1_acos+z*(qS2_acos+z*(qS3_acos+z*qS4_acos)));
     s = __ieee754_sqrtf(z);
     r = p/q;
     w = r*s-pio2_lo_acos;
     return pi - (float)2.0*(s+w);
 } else {
     __int32_t idf;
     z = (one_acos-x)*(float)0.5;
     s = __ieee754_sqrtf(z);
     df = s;
     do { ieee_float_shape_type gf_u; gf_u.value = (df); (idf) = gf_u.word; } while (0);
     do { ieee_float_shape_type sf_u; sf_u.word = (idf&0xfffff000); (df) = sf_u.value; } while (0);
     c = (z-df*df)/(s+df);
     p = z*(pS0_acos+z*(pS1_acos+z*(pS2_acos+z*(pS3_acos+z*(pS4_acos+z*pS5_acos)))));
     q = one_acos+z*(qS1_acos+z*(qS2_acos+z*(qS3_acos+z*qS4_acos)));
     r = p/q;
     w = r*s+c;
     return (float)2.0*(df+w);
 }
}
