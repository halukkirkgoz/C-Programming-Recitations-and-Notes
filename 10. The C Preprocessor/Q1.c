#include <stdio.h>

// Macro definition for MIN to find the smaller of two values
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void) {
	// Test values
	int num1 = -9;
	int num2 = 10;

	// Using the MIN macro to find the smaller of num1 and num2
	int minimum = MIN(num1, num2);

	// Print the result
	printf("The minimum of %d and %d = %d\n", num1, num2, minimum);

	return 0;
}