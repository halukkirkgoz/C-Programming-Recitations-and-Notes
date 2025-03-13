#include <stdio.h>

int main(void) {
	int n;
	unsigned long long factorial = 1; // Use unsigned long long for large results

	// Read input from user
	printf("Enter a natural number n: ");
	scanf("%d%*c", &n);

	// Check if the number is non-negative
	if (n < 0) {
		printf("Factorial is not defined for negative numbers.\n");
	} else {
		// Calculate the factorial
		for (int i = 1; i <= n; i++) {
			factorial *= i; // Multiply factorial by i at each step
		}

		// Print the result
		printf("Factorial of %d is %llu\n", n, factorial);
	}
	
	return 0;
}