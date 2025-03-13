#include <stdio.h>

int main(void) {
	double b, result = 1.0;
	int n;

	// Read base and exponent from user
	printf("Enter the base (b): ");
	scanf("%lf", &b);

	printf("Enter the exponent (n): ");
	scanf("%d", &n);

	// Handle the case when exponent is 0
	if (n == 0) {
		result = 1.0; // Any number raised to the power of 0 is 1
	} else if (n > 0) {
		// For positive exponents, calculate b^n using a loop
		for (int i = 1; i <= n; i++) {
			result *= b; // Multiply result by base b
		}
	} else {
		// For negative exponents, calculate the reciprocal and apply the positive exponent
		for (int i = 1; i <= -n; i++) {
			result *= b; // Multiply result by base b for positive equivalent exponent
		}
		result = 1.0 / result; // Take reciprocal for negative exponent
	}

	// Print the result
	printf("%.2lf raised to the power of %d is %.2lf\n", b, n, result);

	return 0;
}