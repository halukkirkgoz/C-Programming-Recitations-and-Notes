#include <stdio.h>

// Macro definition for MAX2 to find the maximum of two values
#define MAX2(a, b) ((a) > (b) ? (a) : (b))

// Macro definition for MAX3 to find the maximum of three values
#define MAX3(a, b, c) (MAX2(MAX2(a, b), c))

int main(void) {
	// Test values
	int num1 = 20;
	int num2 = 10;
	int num3 = -5;

	// Using the MAX3 macro to find the maximum of num1, num2, and num3
	int maximum = MAX3(num1, num2, num3);

	// Print the result
	printf("The maximum of %d, %d, and %d = %d\n", num1, num2, num3, maximum);

	return 0;
}
