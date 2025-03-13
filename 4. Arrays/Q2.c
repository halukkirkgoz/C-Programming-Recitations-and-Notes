#include <stdio.h>

#define SIZE 12    // Total number of elements
#define COLUMNS 3  // Number of columns in the matrix

// Function declarations
void ReadArray(int [], int);
void PrintMatrix(int [], int, int);

int main(void) {
	int a[SIZE];  // Array to hold the numbers

	// Read numbers into the array
	ReadArray(a, SIZE);

	// Print the numbers in matrix form with given number of columns
	PrintMatrix(a, SIZE, COLUMNS);

	return 0;
}

// Function to read the array
void ReadArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("Enter an integer number %d: ", i + 1);
		scanf("%d%*c", &arr[i]);
	}
}

// Function to print the matrix
void PrintMatrix(int arr[], int size, int columns) {
	int sum_row = 0;
	int sum_column[COLUMNS] = {0};  // Array to store column sums

	printf("\n");  // Ensure there's a newline at the beginning

	for (int i = 0; i < size; i++) {
		printf("%3d ", arr[i]);
		sum_row += arr[i];

		// Check if the current element is the last in the row
		if ((i + 1) % columns == 0) {
			printf("| %3d\n", sum_row);  // Move to the next line after each row
			sum_row = 0;
		}

		// Add the current number to the respective column sum
		sum_column[i % columns] += arr[i];
	}

	printf("-------------\n");  // Line separator before printing column sums
	for (int i = 0; i < columns; i++) {
		printf("%3d ", sum_column[i]);  // Print each column's sum
	}

	printf("\n");  // Ensure there's a newline at the end
}