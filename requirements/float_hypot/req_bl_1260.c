#include "../includes/verify.h"
#include "../includes/math_functions_float.h"

float __ieee754_hypotf(float x, float y) {
float a=x,b=y,t1,t2,y1,y2,w;
__int32_t j,k,ha,hb;

do { ieee_float_shape_type gf_u; gf_u.value = (x); (ha) = gf_u.word; } while (0);
ha &= 0x7fffffffL;
do { ieee_float_shape_type gf_u; gf_u.value = (y); (hb) = gf_u.word; } while (0);
hb &= 0x7fffffffL;
if(hb > ha) {a=y;b=x;j=ha; ha=hb;hb=j;} else {a=x;b=y;}
do { ieee_float_shape_type sf_u; sf_u.word = (ha); (a) = sf_u.value; } while (0);
do { ieee_float_shape_type sf_u; sf_u.word = (hb); (b) = sf_u.value; } while (0);
if((ha-hb)>0xf000000L) {return a+b;}
k=0;
if(ha > 0x58800000L) {
   if(!((ha)<0x7f800000L)) {
       w = a+b;
       if(((ha)==0x7f800000L)) w = a;
       if(((hb)==0x7f800000L)) w = b;
       return w;
   }

   ha -= 0x22000000L; hb -= 0x22000000L; k += 68;
   do { ieee_float_shape_type sf_u; sf_u.word = (ha); (a) = sf_u.value; } while (0);
   do { ieee_float_shape_type sf_u; sf_u.word = (hb); (b) = sf_u.value; } while (0);
}
if(hb < 0x26800000L) {
    if(((hb)==0)) {
        return a;
    } else if(((hb)<0x00800000L)) {
 do { ieee_float_shape_type sf_u; sf_u.word = (0x7e800000L); (t1) = sf_u.value; } while (0);
 b *= t1;
 a *= t1;
 k -= 126;
    } else {
        ha += 0x22000000;
 hb += 0x22000000;
 k -= 68;
 do { ieee_float_shape_type sf_u; sf_u.word = (ha); (a) = sf_u.value; } while (0);
 do { ieee_float_shape_type sf_u; sf_u.word = (hb); (b) = sf_u.value; } while (0);
    }
}

w = a-b;
if (w>b) {
    do { ieee_float_shape_type sf_u; sf_u.word = (ha&0xfffff000L); (t1) = sf_u.value; } while (0);
    t2 = a-t1;
    w = __ieee754_sqrtf(t1*t1-(b*(-b)-t2*(a+t1)));
} else {
    a = a+a;
    do { ieee_float_shape_type sf_u; sf_u.word = (hb&0xfffff000L); (y1) = sf_u.value; } while (0);
    y2 = b - y1;
    do { ieee_float_shape_type sf_u; sf_u.word = (ha+0x00800000L); (t1) = sf_u.value; } while (0);
    t2 = a - t1;
    w = __ieee754_sqrtf(t1*y1-(w*(-w)-(t1*y2+t2*b)));
}
if(k!=0) {
    do { ieee_float_shape_type sf_u; sf_u.word = (0x3f800000L+(k<<23)); (t1) = sf_u.value; } while (0);
    return t1*w;
} else return w;
}


int main() {


  /* REQ-BL-1260:
   * The hypot and hypotf procedures shall compute the length of
   * the hypotenuse of a rightangled triangle with sides of length x and y .
   */
  float x = __VERIFIER_nondet_float();
  float y = __VERIFIER_nondet_float();

  // TODO: precondition
  if(0) {
		return 0;
	}

	__VERIFIER_precond_reach();

	float res = __ieee754_hypotf(x, y);

  // TODO: postcondition
	if(0)	{
		__VERIFIER_error();
		return 1;
	}

	return 0;
}