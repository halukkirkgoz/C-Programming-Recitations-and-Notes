#include <stdio.h>

int main(void) {
	int limit, num, sum = 0;

	// Ask the user to enter the limit
	printf("Enter the limit: ");
	scanf("%d%*c", &limit);

	printf("Enter an integer number: ");
	scanf("%d%*c", &num);
	sum += num; // Add the entered number to the sum

	// Repeatedly ask for integers until the sum reaches or exceeds the limit
	while (sum < limit) {
		printf("Enter an integer number: ");
		scanf("%d%*c", &num);
		sum += num; // Add the entered number to the sum
	}

	// Print a message when the sum reaches or exceeds the limit
	printf("The limit of %d is reached or exceeded!\n", limit);

	return 0;
}
