#include <stdio.h>

int main(void) {
	int a, b;
	int temp1, temp2;

	// Read two positive integers
	printf("Enter 2 positive integer numbers: ");
	scanf("%d%d%*c", &a, &b);
	temp1 = a;
	temp2 = b;

	// Ensure that both numbers are positive
	if (a <= 0 || b <= 0) {
		printf("Both numbers must be positive integers.\n");
		return 1; // Exit the program with an error code
	}

	// Print the initial values
	printf("\n%3d   %-3d\n", a, b);

	// Euclid's algorithm using subtraction (replacing larger number with their difference)
	while (a != b) {
		if (a > b) {
			a = a - b;
		} else {
			b = b - a;
		}

		// Print the intermediate steps
		printf("%3d   %-3d\n", a, b);
	}

	// At this point, a and b are equal, so they are the GCD
	printf("\nThe gcd of %d and %d equals %d.\n", temp1, temp2, a);

	return 0;
}