#include <stdio.h>

// Function declarations
void Read(int *, int *);
int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);

int main(void) {
	int a, b;
	int choice;

	// Function pointer to store the operation function
	int (*operation)(int, int);

	// Read two integers
	Read(&a, &b);

	// Ask the user to choose an operand
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

	// Use a switch to assign the correct function to the function pointer
	switch (choice) {
	case 0:
		operation = add;
		break;
	case 1:
		operation = subtract;
		break;
	case 2:
		operation = multiply;
		break;
	case 3:
		operation = divide;
		break;
	}

	// Call the function using the function pointer and print the result
	int result = (*operation)(a, b);
	printf("\nThe result of this operation is: %d\n", result);

	return 0;
}

// Function to read two integers from the user
void Read(int *a, int *b) {
	printf("Enter 2 integer numbers: ");
	scanf("%d%d%*c", a, b);
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