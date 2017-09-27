#include "../includes/verify.h"
#include "../includes/math_functions_float.h"
#include <float.h>

static const float atanhi[] = {
  4.6364760399e-01,
  7.8539812565e-01,
  9.8279368877e-01,
  1.5707962513e+00,
};


static const float atanlo[] = {
  5.0121582440e-09,
  3.7748947079e-08,
  3.4473217170e-08,
  7.5497894159e-08,
};


static const float aT[] = {
  3.3333334327e-01,
 -2.0000000298e-01,
  1.4285714924e-01,
 -1.1111110449e-01,
  9.0908870101e-02,
 -7.6918758452e-02,
  6.6610731184e-02,
 -5.8335702866e-02,
  4.9768779427e-02,
 -3.6531571299e-02,
  1.6285819933e-02,
};



float atan_float(float x){
 float w,s1,s2,z;
 __int32_t ix,hx,id;

 do { ieee_float_shape_type gf_u; gf_u.value = (x); (hx) = gf_u.word; } while (0);
 ix = hx&0x7fffffff;
 if(ix>=0x50800000) {
     if(((ix)>0x7f800000L))
  return x+x;
     if(hx>0) return atanhi[3]+atanlo[3];
     else return -atanhi[3]-atanlo[3];
 } if (ix < 0x3ee00000) {
     if (ix < 0x31000000) {
  if(huge+x>one) return x;
     }
     id = -1;
 } else {
 x = fabsf(x);
 if (ix < 0x3f980000) {
     if (ix < 0x3f300000) {
  id = 0; x = ((float)2.0*x-one)/((float)2.0+x);
     } else {
  id = 1; x = (x-one)/(x+one);
     }
 } else {
     if (ix < 0x401c0000) {
  id = 2; x = (x-(float)1.5)/(one+(float)1.5*x);
     } else {
  id = 3; x = -(float)1.0/x;
     }
 }}

 z = x*x;
 w = z*z;

 s1 = z*(aT[0]+w*(aT[2]+w*(aT[4]+w*(aT[6]+w*(aT[8]+w*aT[10])))));
 s2 = w*(aT[1]+w*(aT[3]+w*(aT[5]+w*(aT[7]+w*aT[9]))));
 if (id<0) return x - x*(s1+s2);
 else {
     z = atanhi[id] - ((x*(s1+s2) - atanlo[id]) - x);
     return (hx<0)? -z:z;
 }
}

typedef union floattobit
{
	float fvalue;
	unsigned int i;
} floattobit;

typedef enum {
	UNDEF,
	UNSIGNEDCHAR,
	CHAR,
	UNSIGNEDINT,
	INT,
	FLOAT,
	DOUBLE,
	LONGDOUBLE,
} TYPE;

void printTypeValue(void *mem, TYPE t)
{
	switch (t)
	{
		case UNDEF:
			printf("Undefined value\n");
			break;
		case UNSIGNEDCHAR:
			printf("<%i> : unsigned char\n", (int)(*(unsigned char*) mem));
			break;
		case CHAR:
			printf("<%i> : char\n", (int)(*(char*) mem));
			break;
		case UNSIGNEDINT:
			printf("%u : unsigned int\n", *(unsigned int *) mem);
			break;
		case INT:
			printf("%i : int\n", *(int *) mem);
			break;
		case FLOAT:
			printf("%.*f : float\n", DECIMAL_DIG, *(float *) mem);
			break;
		case DOUBLE:
			printf("%.*lf : double\n", DECIMAL_DIG, *(double *) mem);
			break;
		case LONGDOUBLE:
			printf("%.*Lg : long double\n", DECIMAL_DIG, *(long double *) mem);
			break;
		default:
			printf("Unknown type: %i\n", t);
	}
}

void printMemory(void* mem, int size, TYPE t)
{
	unsigned char *memory = mem;
	int i = 0;

	printTypeValue(mem, t);

	i = 0;
	while (i < size)
	{
		if (i < 10) {
			printf(" %i|", i);
		}
		else
		{
			printf("%i|", i);
		}
		i++;
	}
	printf("\n");
	i = 0;

	while (i < size)
	{
		printf("%02x|", memory[i]);
		i++;
	}
	printf("\n\n");
}

int main() {
  float x = __VERIFIER_nondet_float();

  x = INFINITY;
  /* REQ-BL-0621:
   * The atan and atanf procedures shall return +-pi/2 if the argument is +-Inf.
   */

   // x is not +-inf we don't want to continue
   if (isinf_float(x)) {

     __VERIFIER_precond_reach();
     __VERIFIER_assume(x == INFINITY);
     float res = atan_float(x);
     // if x is +-inf the result shall be +-pi/2
     float mpi = +M_PI/2.0f;

     double dmpi = M_PI;
     double fmpi = (float)M_PI;

     printMemory(&dmpi, sizeof(double), DOUBLE);
     printMemory(&fmpi, sizeof(double), DOUBLE);

     if (res != ((float)M_PI/2.0f)) {
       __VERIFIER_error();
 	printf("\n");

       printMemory(&(res), sizeof(float), FLOAT);
       printMemory(&(mpi), sizeof(float), FLOAT);

    	 return 1;
     }
 	 }

 	return 0;
}
