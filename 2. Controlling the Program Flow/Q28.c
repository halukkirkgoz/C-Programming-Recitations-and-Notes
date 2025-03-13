#include <stdio.h>

int main(void) {
	int num, min, max, min_pos, max_pos;

	// Read the first number and initialize min and max to that number
	printf("Enter 10 numbers:\n");
	printf("Enter number 1: ");
	scanf("%d%*c", &num);
	min = max = num; // Initialize min and max to the first number
	min_pos = max_pos = 1; // The first number is at position 1

	// Loop to read the remaining 9 numbers
	for (int i = 2; i <= 10; i++) {
		printf("Enter number %d: ", i);
		scanf("%d%*c", &num);

		// Update min and max if necessary and also store the positions
		if (num < min) {
			min = num;
			min_pos = i; // Update position of min
		}
		if (num > max) {
			max = num;
			max_pos = i; // Update position of max
		}
	}

	// Print the results
	printf("Minimum value: %d at position %d\n", min, min_pos);
	printf("Maximum value: %d at position %d\n", max, max_pos);

	return 0;
}