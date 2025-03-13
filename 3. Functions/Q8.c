#include <stdio.h>

// Function declaration
int gcd(int, int);

int main(void) {
	int num1, num2, num3, result;

	// Read three integer numbers from the user
	printf("Enter three integers: ");
	scanf("%d%d%d%*c", &num1, &num2, &num3);

	if (num1 <= 0 || num2 <= 0 || num3 <= 0) {
		printf("All numbers must be positive integers.\n");
		return 1;
	} else {
		// Calculate the gcd of the three numbers using the property gcd(a, b, c) = gcd(a, gcd(b, c))
		result = gcd(num1, gcd(num2, num3));
	}

	// Print the result
	printf("The greatest common divisor of %d, %d, and %d is: %d\n", num1, num2, num3, result);

	return 0;
}

int gcd(int number1, int number2) {
	// Euclid's algorithm using subtraction (replacing larger number with their difference)
	while (number1 != number2) {
		if (number1 > number2) {
			number1 = number1 - number2;
		} else {
			number2 = number2 - number1;
		}
	}
	return number1;
}
