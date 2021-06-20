#include <math.h>

void someCalc(double a, double b, double *c)
{
	*c = sqrt(pow(a,2) + pow(b,2));
}

void processSomeArray(double inArrayA[1024], double inArrayB[1024], double outArray[1024])
{
	for (int i = 0; i < 1024; i++)
	{
#pragma HLS PIPELINE
		someCalc(inArrayA[i], inArrayB[i], &outArray[i]);
	}
}

// Divide algorithm http://en.wikipedia.org/wiki/Division_algorithm
void divide(unsigned char N, unsigned char D, unsigned char *Q, unsigned char *R)
{
	// Check if D is not zero
	if (D != 0)
	{
		// Initialize Q and R (Pointers)
		*Q = 0;
		*R = 0;

		// Count from 7 downto 0
		for (int i = 7; i >= 0; i--)
		{
			// Shift left R by one
			*R = *R << 1;

			// Get the i bit of N (http://en.wikipedia.org/wiki/Bit_manipulation)
			// Get the value N(i)
			char iBitN = (N & ( 1 << i )) >> i;

			// Set the LSB of R to the value in iBitN
			// R(0) := N(i)
			*R ^= (-iBitN ^ (*R)) & (1 << 0);

			if ((*R) >= D)
			{
				// Subtract R
				*R = *R - D;

				// Set the i bit of Q
				*Q |= 1 << i;
			}
		}
	}
}
