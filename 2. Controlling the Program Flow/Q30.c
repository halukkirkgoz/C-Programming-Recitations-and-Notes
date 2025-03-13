#include <stdio.h>

int main(void) {
	int n;

	// Ask the user to input a positive integer
	printf("Enter a positive integer: ");
	scanf("%d%*c", &n);

	if (n <= 0) {
		printf("Please enter a positive integer.\n");
		return 1;
	}

	// Try to find and print all consecutive integer sequences that sum to n
	for (int start = 1; start < n; start++) {
		int sum = 0;
		int end = start;

		// Find the sum of consecutive numbers starting from 'start'
		while (sum < n) {
			sum += end;
			end++;
		}

		// If the sum equals n, print the sequence
		if (sum == n) {
			printf("Sequence: ");
			for (int i = start; i < end; i++) {
				printf("%d ", i);
			}
			printf("\n");
		}
	}

	return 0;
}
