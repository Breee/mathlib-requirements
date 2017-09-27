#include "../includes/verify.h"
#include "../includes/math_functions_double.h"

double __ieee754_hypot(double x, double y) {
double a=x,b=y,t1,t2,y1,y2,w;
__int32_t j,k,ha,hb;

do { ieee_double_shape_type gh_u; gh_u.value = (x); (ha) = gh_u.parts.msw; } while (0);
ha &= 0x7fffffff;
do { ieee_double_shape_type gh_u; gh_u.value = (y); (hb) = gh_u.parts.msw; } while (0);
hb &= 0x7fffffff;
if(hb > ha) {a=y;b=x;j=ha; ha=hb;hb=j;} else {a=x;b=y;}
do { ieee_double_shape_type sh_u; sh_u.value = (a); sh_u.parts.msw = (ha); (a) = sh_u.value; } while (0);
do { ieee_double_shape_type sh_u; sh_u.value = (b); sh_u.parts.msw = (hb); (b) = sh_u.value; } while (0);
if((ha-hb)>0x3c00000) {return a+b;}
k=0;
if(ha > 0x5f300000) {
   if(ha >= 0x7ff00000) {
       __uint32_t low;
       w = a+b;
       do { ieee_double_shape_type gl_u; gl_u.value = (a); (low) = gl_u.parts.lsw; } while (0);
       if(((ha&0xfffff)|low)==0) w = a;
       do { ieee_double_shape_type gl_u; gl_u.value = (b); (low) = gl_u.parts.lsw; } while (0);
       if(((hb^0x7ff00000)|low)==0) w = b;
       return w;
   }

   ha -= 0x25800000; hb -= 0x25800000; k += 600;
   do { ieee_double_shape_type sh_u; sh_u.value = (a); sh_u.parts.msw = (ha); (a) = sh_u.value; } while (0);
   do { ieee_double_shape_type sh_u; sh_u.value = (b); sh_u.parts.msw = (hb); (b) = sh_u.value; } while (0);
}
if(hb < 0x20b00000) {
    if(hb <= 0x000fffff) {
        __uint32_t low;
 do { ieee_double_shape_type gl_u; gl_u.value = (b); (low) = gl_u.parts.lsw; } while (0);
 if((hb|low)==0) return a;
 t1=0;
 do { ieee_double_shape_type sh_u; sh_u.value = (t1); sh_u.parts.msw = (0x7fd00000); (t1) = sh_u.value; } while (0);
 b *= t1;
 a *= t1;
 k -= 1022;
    } else {
        ha += 0x25800000;
 hb += 0x25800000;
 k -= 600;
 do { ieee_double_shape_type sh_u; sh_u.value = (a); sh_u.parts.msw = (ha); (a) = sh_u.value; } while (0);
 do { ieee_double_shape_type sh_u; sh_u.value = (b); sh_u.parts.msw = (hb); (b) = sh_u.value; } while (0);
    }
}

w = a-b;
if (w>b) {
    t1 = 0;
    do { ieee_double_shape_type sh_u; sh_u.value = (t1); sh_u.parts.msw = (ha); (t1) = sh_u.value; } while (0);
    t2 = a-t1;
    w = __ieee754_sqrt(t1*t1-(b*(-b)-t2*(a+t1)));
} else {
    a = a+a;
    y1 = 0;
    do { ieee_double_shape_type sh_u; sh_u.value = (y1); sh_u.parts.msw = (hb); (y1) = sh_u.value; } while (0);
    y2 = b - y1;
    t1 = 0;
    do { ieee_double_shape_type sh_u; sh_u.value = (t1); sh_u.parts.msw = (ha+0x00100000); (t1) = sh_u.value; } while (0);
    t2 = a - t1;
    w = __ieee754_sqrt(t1*y1-(w*(-w)-(t1*y2+t2*b)));
}
if(k!=0) {
    __uint32_t high;
    t1 = 1.0;
    do { ieee_double_shape_type gh_u; gh_u.value = (t1); (high) = gh_u.parts.msw; } while (0);
    do { ieee_double_shape_type sh_u; sh_u.value = (t1); sh_u.parts.msw = (high+(k<<20)); (t1) = sh_u.value; } while (0);
    return t1*w;
} else return w;
}


int main() {


  /* REQ-BL-1260:
   * The hypot and hypotf procedures shall compute the length of
   * the hypotenuse of a rightangled triangle with sides of length x and y .
   */
  double x = __VERIFIER_nondet_double();
  double y = __VERIFIER_nondet_double();

  // TODO: precondition
  if(0) {
		return 0;
	}

	__VERIFIER_precond_reach();

	double res = __ieee754_hypot(x, y);

  // TODO: postcondition
	if(0)	{
		__VERIFIER_error();
		return 1;
	}

	return 0;
}
