#include <stdio.h>

int main(void) {
	float number;

	// Prompt the user to enter a real number
	printf("Enter a real number: ");
	scanf("%f%*c", &number);

	// Check condition A: 3 ≤ x < 8.5
	if (number >= 3 && number < 8.5) {
		printf("The number %.2f matches condition A.\n", number);
	} else {
		printf("The number %.2f doesn't match condition A.\n", number);
	}

	// Check condition B: x < 3 OR 5.4 < x ≤ 7.3 OR x > 13
	if (number < 3 || (number > 5.4 && number <= 7.3) || number > 13) {
		printf("The number %.2f matches condition B.\n", number);
	} else {
		printf("The number %.2f doesn't match condition B.\n", number);
	}

	// Check condition C: x ≠ 3 AND x < 9.75
	if (number != 3 && number < 9.75) {
		printf("The number %.2f matches condition C.\n", number);
	} else {
		printf("The number %.2f doesn't match condition C.\n", number);
	}

	return 0;
}