double __ieee754_pow(double x, double y) {
 double z,ax,z_h,z_l,p_h,p_l;
 double y1,t1,t2,r,s,t,u,v,w;
 __int32_t i,j,k,yisint,n;
 __int32_t hx,hy,ix,iy;
 __uint32_t lx,ly;

 do { ieee_double_shape_type ew_u; ew_u.value = (x); (hx) = ew_u.parts.msw; (lx) = ew_u.parts.lsw; } while (0);
 do { ieee_double_shape_type ew_u; ew_u.value = (y); (hy) = ew_u.parts.msw; (ly) = ew_u.parts.lsw; } while (0);
 ix = hx&0x7fffffff; iy = hy&0x7fffffff;

 if((iy|ly)==0) return one;

 if(ix > 0x7ff00000 || ((ix==0x7ff00000)&&(lx!=0)) ||
    iy > 0x7ff00000 || ((iy==0x7ff00000)&&(ly!=0))) {
     if(((ix-0x3ff00000)|lx)==0) return one;
     else return nan("");
 }

 yisint = 0;
 if(hx<0) {
     if(iy>=0x43400000) yisint = 2;
     else if(iy>=0x3ff00000) {
  k = (iy>>20)-0x3ff;
  if(k>20) {
      j = ly>>(52-k);
      if((j<<(52-k))==ly) yisint = 2-(j&1);
  } else if(ly==0) {
      j = iy>>(20-k);
      if((j<<(20-k))==iy) yisint = 2-(j&1);
  }
     }
 }

 if(ly==0) {
     if (iy==0x7ff00000) {
         if(((ix-0x3ff00000)|lx)==0)
      return one;
         else if (ix >= 0x3ff00000)
      return (hy>=0)? y: zero;
         else
      return (hy<0)?-y: zero;
     }
     if(iy==0x3ff00000) {
  if(hy<0) return one/x; else return x;
     }
     if(hy==0x40000000) return x*x;
     if(hy==0x3fe00000) {
  if(hx>=0)
  return __ieee754_sqrt(x);
     }
 }

 ax = fabs(x);

 if(lx==0) {
     if(ix==0x7ff00000||ix==0||ix==0x3ff00000){
  z = ax;
  if(hy<0) z = one/z;
  if(hx<0) {
      if(((ix-0x3ff00000)|yisint)==0) {
   z = (z-z)/(z-z);
      } else if(yisint==1)
   z = -z;
  }
  return z;
     }
 }

 if(((((__uint32_t)hx>>31)-1)|yisint)==0) return (x-x)/(x-x);


 if(iy>0x41e00000) {
     if(iy>0x43f00000){
  if(ix<=0x3fefffff) return (hy<0)? huge*huge:tiny*tiny;
  if(ix>=0x3ff00000) return (hy>0)? huge*huge:tiny*tiny;
     }

     if(ix<0x3fefffff) return (hy<0)? huge*huge:tiny*tiny;
     if(ix>0x3ff00000) return (hy>0)? huge*huge:tiny*tiny;


     t = ax-1;
     w = (t*t)*(0.5-t*(0.3333333333333333333333-t*0.25));
     u = ivln2_h*t;
     v = t*ivln2_l-w*ivln2;
     t1 = u+v;
     do { ieee_double_shape_type sl_u; sl_u.value = (t1); sl_u.parts.lsw = (0); (t1) = sl_u.value; } while (0);
     t2 = v-(t1-u);
 } else {
     double s2,s_h,s_l,t_h,t_l;
     n = 0;

     if(ix<0x00100000)
  {ax *= two53; n -= 53; do { ieee_double_shape_type gh_u; gh_u.value = (ax); (ix) = gh_u.parts.msw; } while (0); }
     n += ((ix)>>20)-0x3ff;
     j = ix&0x000fffff;

     ix = j|0x3ff00000;
     if(j<=0x3988E) k=0;
     else if(j<0xBB67A) k=1;
     else {k=0;n+=1;ix -= 0x00100000;}
     do { ieee_double_shape_type sh_u; sh_u.value = (ax); sh_u.parts.msw = (ix); (ax) = sh_u.value; } while (0);


     u = ax-bp[k];
     v = one/(ax+bp[k]);
     s = u*v;
     s_h = s;
     do { ieee_double_shape_type sl_u; sl_u.value = (s_h); sl_u.parts.lsw = (0); (s_h) = sl_u.value; } while (0);

     t_h = zero;
     do { ieee_double_shape_type sh_u; sh_u.value = (t_h); sh_u.parts.msw = (((ix>>1)|0x20000000)+0x00080000+(k<<18)); (t_h) = sh_u.value; } while (0);
     t_l = ax - (t_h-bp[k]);
     s_l = v*((u-s_h*t_h)-s_h*t_l);

     s2 = s*s;
     r = s2*s2*(L1+s2*(L2+s2*(L3+s2*(L4+s2*(L5+s2*L6)))));
     r += s_l*(s_h+s);
     s2 = s_h*s_h;
     t_h = 3.0+s2+r;
     do { ieee_double_shape_type sl_u; sl_u.value = (t_h); sl_u.parts.lsw = (0); (t_h) = sl_u.value; } while (0);
     t_l = r-((t_h-3.0)-s2);

     u = s_h*t_h;
     v = s_l*t_h+t_l*s;

     p_h = u+v;
     do { ieee_double_shape_type sl_u; sl_u.value = (p_h); sl_u.parts.lsw = (0); (p_h) = sl_u.value; } while (0);
     p_l = v-(p_h-u);
     z_h = cp_h*p_h;
     z_l = cp_l*p_h+p_l*cp+dp_l[k];

     t = (double)n;
     t1 = (((z_h+z_l)+dp_h[k])+t);
     do { ieee_double_shape_type sl_u; sl_u.value = (t1); sl_u.parts.lsw = (0); (t1) = sl_u.value; } while (0);
     t2 = z_l-(((t1-t)-dp_h[k])-z_h);
 }

 s = one;
 if(((((__uint32_t)hx>>31)-1)|(yisint-1))==0)
     s = -one;


 y1 = y;
 do { ieee_double_shape_type sl_u; sl_u.value = (y1); sl_u.parts.lsw = (0); (y1) = sl_u.value; } while (0);
 p_l = (y-y1)*t1+y*t2;
 p_h = y1*t1;
 z = p_l+p_h;
 do { ieee_double_shape_type ew_u; ew_u.value = (z); (j) = ew_u.parts.msw; (i) = ew_u.parts.lsw; } while (0);
 if (j>=0x40900000) {
     if(((j-0x40900000)|i)!=0)
  return s*huge*huge;
     else {
  if(p_l+ovt>z-p_h) return s*huge*huge;
     }
 } else if((j&0x7fffffff)>=0x4090cc00 ) {
     if(((j-0xc090cc00)|i)!=0)
  return s*tiny*tiny;
     else {
  if(p_l<=z-p_h) return s*tiny*tiny;
     }
 }



 i = j&0x7fffffff;
 k = (i>>20)-0x3ff;
 n = 0;
 if(i>0x3fe00000) {
     n = j+(0x00100000>>(k+1));
     k = ((n&0x7fffffff)>>20)-0x3ff;
     t = zero;
     do { ieee_double_shape_type sh_u; sh_u.value = (t); sh_u.parts.msw = (n&~(0x000fffff>>k)); (t) = sh_u.value; } while (0);
     n = ((n&0x000fffff)|0x00100000)>>(20-k);
     if(j<0) n = -n;
     p_h -= t;
 }
 t = p_l+p_h;
 do { ieee_double_shape_type sl_u; sl_u.value = (t); sl_u.parts.lsw = (0); (t) = sl_u.value; } while (0);
 u = t*lg2_h;
 v = (p_l-(t-p_h))*lg2+t*lg2_l;
 z = u+v;
 w = v-(z-u);
 t = z*z;
 t1 = z - t*(P1+t*(P2+t*(P3+t*(P4+t*P5))));
 r = (z*t1)/(t1-two)-(w+z*w);
 z = one-(r-z);
 do { ieee_double_shape_type gh_u; gh_u.value = (z); (j) = gh_u.parts.msw; } while (0);
 j += (n<<20);
 if((j>>20)<=0) z = scalbn_double(z,(int)n);
 else do { ieee_double_shape_type sh_u; sh_u.value = (z); sh_u.parts.msw = (j); (z) = sh_u.value; } while (0);
 return s*z;
}
