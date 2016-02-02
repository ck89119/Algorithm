#include<stdio.h>

float Q_rsqrt(float x) {
	long i;
	float halfx, y;
	const float threehalfs = 1.5F;

	halfx = x * 0.5F;
	y = x;
	i = *(long *) &y;                       // evil floating point bit level hacking
	i = 0x5f3759df - (i >> 1);               // what the fuck?
	y = * (float *) &i;
  y = y * (threehalfs - (halfx * y * y));   // 1st iteration
  /*y = y * (threehalfs - (halfx * y * y));   // 2nd iteration, this can be removed*/

	return y;
}


int main() {
  printf("%f\n", Q_rsqrt(0.01));
  return 0;
}
