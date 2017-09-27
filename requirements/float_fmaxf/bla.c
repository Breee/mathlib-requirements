#include <stdio.h>
#include <math.h>

int main()
{
	float f;
	void* p = &f;
	unsigned long *up = (unsigned long*) p;
	*up = 0x7fc00000UL;

	printf("%f\n", f);

	return 0;
}
