#include "../includes/verify.h"
#include "../includes/math_functions_double.h"


static const double ln2_hi = 6.93147180369123816490e-01,
ln2_lo = 1.90821492927058770002e-10,
two54 = 1.80143985094819840000e+16,
Lg1 = 6.666666666666735130e-01,
Lg2 = 3.999999999940941908e-01,
Lg3 = 2.857142874366239149e-01,
Lg4 = 2.222219843214978396e-01,
Lg5 = 1.818357216161805012e-01,
Lg6 = 1.531383769920937332e-01,
Lg7 = 1.479819860511658591e-01;

static const double ivln10 = 4.34294481903251816668e-01,
log10_2hi = 3.01029995663611771306e-01,
log10_2lo = 3.69423907715893078616e-13;


static const double zero = 0.0;

double __ieee754_log(double x) {
 double hfsq,f,s,z,R,w,t1,t2,dk;
 __int32_t k,hx,i,j;
 __uint32_t lx;

 do { ieee_double_shape_type ew_u; ew_u.value = (x); (hx) = ew_u.parts.msw; (lx) = ew_u.parts.lsw; } while (0);

 k=0;
 if (hx < 0x00100000) {
     if (((hx&0x7fffffff)|lx)==0)
  return -two54/zero;
     if (hx<0) return (x-x)/zero;
     k -= 54; x *= two54;
     do { ieee_double_shape_type gh_u; gh_u.value = (x); (hx) = gh_u.parts.msw; } while (0);
 }
 if (hx >= 0x7ff00000) return x+x;
 k += (hx>>20)-1023;
 hx &= 0x000fffff;
 i = (hx+0x95f64)&0x100000;
 do { ieee_double_shape_type sh_u; sh_u.value = (x); sh_u.parts.msw = (hx|(i^0x3ff00000)); (x) = sh_u.value; } while (0);
 k += (i>>20);
 f = x-1.0;
 if((0x000fffff&(2+hx))<3) {
          if(f==zero) { if(k==0) return zero; else {dk=(double)k;
                               return dk*ln2_hi+dk*ln2_lo;}}
     R = f*f*(0.5-0.33333333333333333*f);
     if(k==0) return f-R; else {dk=(double)k;
           return dk*ln2_hi-((R-dk*ln2_lo)-f);}
 }
  s = f/(2.0+f);
 dk = (double)k;
 z = s*s;
 i = hx-0x6147a;
 w = z*z;
 j = 0x6b851-hx;
 t1= w*(Lg2+w*(Lg4+w*Lg6));
 t2= z*(Lg1+w*(Lg3+w*(Lg5+w*Lg7)));
 i |= j;
 R = t2+t1;
 if(i>0) {
     hfsq=0.5*f*f;
     if(k==0) return f-(hfsq-s*(hfsq+R)); else
       return dk*ln2_hi-((hfsq-(s*(hfsq+R)+dk*ln2_lo))-f);
 } else {
     if(k==0) return f-s*(f-R); else
       return dk*ln2_hi-((s*(f-R)-dk*ln2_lo)-f);
 }
}

 double __ieee754_log10(double x){
 double y,z;
 __int32_t i,k,hx;
 __uint32_t lx;

 do { ieee_double_shape_type ew_u; ew_u.value = (x); (hx) = ew_u.parts.msw; (lx) = ew_u.parts.lsw; } while (0);

        k=0;
        if (hx < 0x00100000) {
            if (((hx&0x7fffffff)|lx)==0)
                return -two54/zero;
            if (hx<0) return (x-x)/zero;
            k -= 54; x *= two54;
     do { ieee_double_shape_type gh_u; gh_u.value = (x); (hx) = gh_u.parts.msw; } while (0);
        }
 if (hx >= 0x7ff00000) return x+x;
 k += (hx>>20)-1023;
 i = ((__uint32_t)k&0x80000000)>>31;
        hx = (hx&0x000fffff)|((0x3ff-i)<<20);
        y = (double)(k+i);
 do { ieee_double_shape_type sh_u; sh_u.value = (x); sh_u.parts.msw = (hx); (x) = sh_u.value; } while (0);
 z = y*log10_2lo + ivln10*__ieee754_log(x);
 return z+y*log10_2hi;
}

int main() {

  /* REQ-BL-0960
   * The log10 and log10f procedures shall return -Inf if the argument x is +-0.
   */

  double x = __VERIFIER_nondet_double();

  // if x is not +-0 we stop
  if (x == 0.0 || x == -0.0) {

    	__VERIFIER_precond_reach();

    	double res = __ieee754_log10(x);

      // x is +-0, the result shall be -inf
    	if (!isinf_double(res)) {
    		__VERIFIER_error();
    		return 1;
    	}

	}

	return 0;
}
