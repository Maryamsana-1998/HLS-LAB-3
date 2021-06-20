#include <stdio.h>
void divide(unsigned char N, unsigned char D, unsigned char *Q, unsigned char *R);

int main()
{
	// Initialize inputs
	unsigned char N = 8;
	unsigned char D = 3;
	unsigned char Q, R;

	divide(N, D, &Q, &R);
	printf("Division of %d/%d is : <Q:%d R:%d>\n",N,D,Q,R);

	// Now divide 4 by 2
	N = 4;D = 2;
	divide(N, D, &Q, &R);
	printf("Division of %d/%d is : <Q:%d R:%d>\n",N,D,Q,R);

	return 0;
}
