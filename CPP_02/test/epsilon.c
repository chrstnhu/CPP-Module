// https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html

// compile : cc test.c -lm (Lie la bibliothèque mathématique (libm))
#include <stdio.h>
#include <math.h>
#include <ieee754.h>

#define EPSILON 2.220446049250313e-16
#define LOG2_10 3.321928095
#define flt_zero(x) (fabs(x) < EPSILON)

int max_digs_rt = 3; /* maximum # of 0's right of decimal before using
						scientific notation */
int max_digs_lf = 5; /* max # of digits left of decimal */

void print_real(double r, int width, int dec)
{
	int mag;
	double fpart, temp;
	char format[8];
	char num_format[3] = {'l', 0, 0};
	union ieee754_double *dl;

	dl = (union ieee754_double *)&r;
	mag = (dl->ieee.exponent - IEEE754_DOUBLE_BIAS) / LOG2_10;
	if (r == 0)
		mag = 0;
	if ((mag > max_digs_lf - 1) || (mag < -max_digs_rt))
	{
		num_format[1] = 'e';
		temp = r / pow(10, mag);	/* see if number will have a decimal */
		fpart = temp - floor(temp); /* when written in scientific notation */
	}
	else
	{
		num_format[1] = 'f';
		fpart = r - floor(r);
	}
	if (flt_zero(fpart))
		dec = 0;
	if (width == 0)
	{
		snprintf(format, 8, "%%.%d%s", dec, num_format);
	}
	else
	{
		snprintf(format, 8, "%%%d.%d%s", width, dec, num_format);
	}
	printf(format, r);
}

int main()
{
	double numbers[] = {0.0, 1.0, 0.5, 3.0, 1e6, 1e-5};
	int num_elements = sizeof(numbers) / sizeof(numbers[0]);

	for (int i = 0; i < num_elements; i++)
	{
		print_real(numbers[i], 0, 6);
		printf("\n");
	}
	return 0;
}
