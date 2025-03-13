#include <stdio.h>

int main(void) {
	float num, sum = 0;

	// Loop to read 10 numbers
	for (int count = 1; count <= 10; count++) {
		printf("Enter number %d: ", count);
		scanf("%f%*c", &num);
		sum += num; // Add the entered number to sum
	}

	// Calculate and print the mean
	printf("Sum of the 10 numbers: %.3f\n", sum);
	printf("Mean of the 10 numbers: %.3f\n", sum / 10.0);

	return 0;
}
