#include <stdio.h>

// Function declarations
void empty_square(void);
void filled_square(void);

int main(void) {
	int choice;

	while(1) {
		// Display the menu
		printf("Choose an option:\n");
		printf("\t1. Draw an empty square\n");
		printf("\t2. Draw a filled square\n");
		printf("\t3. Stop\n");
		printf("Enter your choice: ");
		scanf("%d%*c", &choice);

		// If the user chooses option 3, stop the program
		if (choice == 3) {
			printf("Thanks for playing with us!\n");
			break;
		}

		// Handle the choices
		switch (choice) {
		case 1:
			empty_square();
			break;
		case 2:
			filled_square();
			break;
		default:
			printf("Enter a valid choice: 1, 2 or 3!\n\n");
			break;
		}
	}

	return 0;
}

// Function to draw a filled square of size 10
void filled_square(void) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%c", 219);
		}
		printf("\n");
	}
	printf("\n");
}

// Function to draw an empty square of size 10
void empty_square(void) {
	// Print the top row
	for (int i = 0; i < 10; i++) {
		printf("%c", 219);
	}
	printf("\n");

	// Print the middle rows
	for (int i = 0; i < 8; i++) {
		printf("%c", 219); // Print left border
		for (int j = 0; j < 8; j++) {
			printf(" "); // Print empty space
		}
		printf("%c\n", 219); // Print right border
	}

	// Print the bottom row
	for (int i = 0; i < 10; i++) {
		printf("%c", 219);
	}
	printf("\n\n");
}