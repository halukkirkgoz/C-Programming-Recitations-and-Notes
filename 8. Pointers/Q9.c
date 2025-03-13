#include <stdio.h>

// Function declarations
void Read(int *, int *);
int Choose(void);
int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);

int main(void) {
	int a, b;

	// Array of function pointers for operations
	int (*operations[4])(int, int) = {add, subtract, multiply, divide};

	// Read two integers
	Read(&a, &b);

	// Get the user's choice of operation
	int choice = Choose();

	// Call the selected operation using the function pointer array
	int result = (*operations[choice])(a, b);

	// Print the result
	printf("\nThe result of this operation is: %d\n", result);

	return 0;
}

// Function to read two integers from the user
void Read(int *a, int *b) {
	printf("Enter 2 integer numbers: ");
	scanf("%d%d%*c", a, b);
}

// Function to ask the user to choose an operation
int Choose(void) {
	int choice;
	do {
		printf("Choose an operand and enter your choice (0-3):\n");
		printf("0 - addition\n");
		printf("1 - subtraction\n");
		printf("2 - multiplication\n");
		printf("3 - division\n");
		scanf("%d%*c", &choice);

		// Validate input
		if (choice < 0 || choice > 3) {
			printf("\nInvalid choice. Please select a number between 0 and 3.\n");
		}
	} while (choice < 0 || choice > 3);

	return choice;  // Return the user's choice
}

// Function definitions for each operation
int add(int a, int b) {
	return a + b;
}

int subtract(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

int divide(int a, int b) {
	if (b != 0) {
		return a / b; // Perform integer division
	} else {
		printf("Error: Division by zero is not allowed.\n");
		return 0;
	}
}