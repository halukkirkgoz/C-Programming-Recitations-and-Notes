#include <stdio.h>

// Function declarations
void Read(int *, int *);
void CalcPrint(int, int);

int main(void) {
	int number, limit;

	while (1) {
		// Read the number and limit
		Read(&number, &limit);

		// If both number and limit are 0, terminate the program
		if (number == 0 && limit == 0) {
			printf("Thanks!\n");
			break;
		}

		// Calculate and print the multiplication table and sum of even/odd products
		CalcPrint(number, limit);
	}

	return 0;
}

// Function to read the number and limit
void Read(int *number, int *limit) {
	printf("Enter the number you want to use for the table of multiplication: ");
	scanf("%d%*c", number);
	printf("Enter the limit: ");
	scanf("%d%*c", limit);
}

// Function to calculate the multiplication table and sum even and odd products
void CalcPrint(int number, int limit) {
	int sumEven = 0, sumOdd = 0;

	// Print the table of multiplication
	printf("\n");
	for (int i = 1; number * i <= limit; i++) {
		int product = number * i;
		printf("%d\n", product);

		// Sum even and odd products
		if (product % 2 == 0) {
			sumEven += product;
		} else {
			sumOdd += product;
		}
	}

	// Print the results
	printf("\nThe sum of the even numbers is %d\n", sumEven);
	printf("The sum of the odd numbers is %d\n\n", sumOdd);
}
