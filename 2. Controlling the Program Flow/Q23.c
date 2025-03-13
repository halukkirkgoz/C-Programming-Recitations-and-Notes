#include <stdio.h>

int main(void) {
	int num;

	// Loop to repeatedly ask for numbers until 0 is entered
	while (1) {
		printf("Enter an integer number in the interval [-30, 30] (enter 0 to quit): ");
		scanf("%d%*c", &num);

		if (num < -30 || num > 30) {
			// If the input is outside the range [-30, 30]
			printf("Invalid input! Please enter an integer in the interval [-30, 30].\n");
			continue;
		}

		// If number is 0, exit the loop
		if (num == 0) {
			break;
		}

		// Print the bar graph for the entered number
		// Total width of the graph (61 characters: 30 for the left side, 30 for the right side, 1 for the middle)
		char bar[61] = {0};
		int middle = 30; // Middle point of the bar graph (index 30)

		// Place the middle as a vertical bar
		bar[middle] = '|';

		// Fill the bar based on the number
		if (num < 0) {
			// Negative number: Draw * symbols from middle to the left
			for (int i = middle - 1; i >= middle + num; i--) {
				bar[i] = '*';
			}
		} else if (num > 0) {
			// Positive number: Draw * symbols from middle to the right
			for (int i = middle + 1; i < middle + num + 1; i++) {
				bar[i] = '*';
			}
		}

		// Fill the remaining space with dots
		for (int i = 0; i < 61; i++) {
			if (bar[i] == 0) {
				bar[i] = '.';
			}
		}

		// Print the bar graph
		printf("%s\n", bar);

		// Print the entered number at the end
		printf("number: %d\n", num);
	}

	return 0;
}