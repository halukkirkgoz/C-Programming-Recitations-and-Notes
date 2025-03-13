#include <stdio.h>

int main(void) {
	int num, sum = 0, count = 0;

	printf("Enter numbers (999 to stop):\n");

	// Loop to keep reading numbers until 999 is entered
	while (1) {
		printf("Enter a number: ");
		scanf("%d%*c", &num);

		if (num == 999) {
			break;  // Stop reading when 999 is entered
		}

		sum += num;  // Add the number to sum
		count++;      // Increment the count of valid numbers
	}

	if (count > 0) {
		// Calculate and print the mean
		printf("Sum of entered numbers: %d\n", sum);
		printf("Mean of entered numbers: %.2f\n", sum / (float)count);
	} else {
		printf("No valid numbers entered.\n");
	}

	return 0;
}
