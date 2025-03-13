#include <stdio.h>

int main(void) {
	int num;

	// Ask the user to enter a number within the interval [-2, 4.5[
	while(1) {
		printf("Enter an integer number in the interval [-2, 4.5[: ");
		scanf("%d%*c", &num);

		// Check if the number is within the valid range
		if (num >= -2 && num < 5) {
			// If valid, print the number and break out of the loop
			printf("You entered: %d\n", num);
			break;
		} else {
			// If not in range, prompt the user again
			printf("Invalid number! The number must be in the specified range.\n");
		}
	}
    
	return 0;
}