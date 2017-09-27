#include "../includes/verify.h"
#include "../includes/math_functions_float.h"

static const float ln2_hi = 6.9313812256e-01,
ln2_lo = 9.0580006145e-06,
Lg1 = 6.6666668653e-01,
Lg2 = 4.0000000596e-01,
Lg3 = 2.8571429849e-01,
Lg4 = 2.2222198546e-01,
Lg5 = 1.8183572590e-01,
Lg6 = 1.5313838422e-01,
Lg7 = 1.4798198640e-01;

static const float ivln10 = 4.3429449201e-01,
log10_2hi = 3.0102920532e-01,
log10_2lo = 7.9034151668e-07;


float __ieee754_logf(float x) {
 float hfsq,f,s,z,R,w,t1,t2,dk;
 __int32_t k,ix,i,j;

 do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);

 k=0;
 if (((ix&0x7fffffff)==0))
     return -two25/zero;
        if (ix<0) return (x-x)/zero;
 if (!((ix)<0x7f800000L)) return x+x;
 if (((ix)<0x00800000L)) {
     k -= 25; x *= two25;
     do { ieee_float_shape_type gf_u; gf_u.value = (x); (ix) = gf_u.word; } while (0);
 }
 k += (ix>>23)-127;
 ix &= 0x007fffff;
 i = (ix+(0x95f64<<3))&0x800000;
 do { ieee_float_shape_type sf_u; sf_u.word = (ix|(i^0x3f800000)); (x) = sf_u.value; } while (0);
 k += (i>>23);
 f = x-(float)1.0;
 if((0x007fffff&(15+ix))<16) {
           if(f==zero) { if(k==0) return zero; else {dk=(float)k;
                                return dk*ln2_hi+dk*ln2_lo;}}
     R = f*f*((float)0.5-(float)0.33333333333333333*f);
     if(k==0) return f-R; else {dk=(float)k;
           return dk*ln2_hi-((R-dk*ln2_lo)-f);}
 }
  s = f/((float)2.0+f);
 dk = (float)k;
 z = s*s;static const float,
ivln10 = 4.3429449201e-01,
log10_2hi = 3.0102920532e-01,
log10_2lo = 7.9034151668e-07;

 t1= w*(Lg2+w*(Lg4+w*Lg6));
 t2= z*(Lg1+w*(Lg3+w*(Lg5+w*Lg7)));
 i |= j;
 R = t2+t1;
 if(i>0) {
     hfsq=(float)0.5*f*f;
     if(k==0) return f-(hfsq-s*(hfsq+R)); else
       return dk*ln2_hi-((hfsq-(s*(hfsq+R)+dk*ln2_lo))-f);
 } else {
     if(k==0) return f-s*(f-R); else
       return dk*ln2_hi-((s*(f-R)-dk*ln2_lo)-f);
 }
}

float __ieee754_log10f(float x) {
 float y,z;
 __int32_t i,k,hx;

 do { ieee_float_shape_type gf_u; gf_u.value = (x); (hx) = gf_u.word; } while (0);

        k=0;
        if (((hx&0x7fffffff)==0))
            return -two25/zero;
        if (hx<0) return (x-x)/zero;
 if (!((hx)<0x7f800000L)) return x+x;
        if (((hx)<0x00800000L)) {
            k -= 25; x *= two25;
     do { ieee_float_shape_type gf_u; gf_u.value = (x); (hx) = gf_u.word; } while (0);
        }
 k += (hx>>23)-127;
 i = ((__uint32_t)k&0x80000000)>>31;
        hx = (hx&0x007fffff)|((0x7f-i)<<23);
        y = (float)(k+i);
 do { ieee_float_shape_type sf_u; sf_u.word = (hx); (x) = sf_u.value; } while (0);
 z = y*log10_2lo + ivln10*__ieee754_logf(x);
 return z+y*log10_2hi;
}

int main()
{

  /* REQ-BL-0971
   * The log10 and log10f procedures shall return NaN , if the argument x is NaN .
   */

  float x = NAN;
  
  if (isnan_float(x)) {
    __VERIFIER_precond_reach();

    float res = __ieee754_log10f(x);

    // x is NAN, result shall be NAN
    if (!isnan_float(res)) {
      __VERIFIER_error();
      return 1;
    }
	}

	return 0;
}
