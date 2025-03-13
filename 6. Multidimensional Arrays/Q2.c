#include <stdio.h>

#define ROWS 3
#define COLUMNS 10

// Function declarations
void ReadRow(int [][COLUMNS], int, int);
void Calculate(int [][COLUMNS], int, int);
void PrintMatrix(int [][COLUMNS], int, int);

int main(void) {
	int matrix[ROWS][COLUMNS];

	// Read the first ROWS-1 rows of integers
	ReadRow(matrix, ROWS, COLUMNS);

	// Calculate the sum for the ROWSth row
	Calculate(matrix, ROWS, COLUMNS);

	// Print the full matrix
	printf("\nTable:\n");
	PrintMatrix(matrix, ROWS, COLUMNS);

	return 0;
}

// Function to read the first ROWS-1 rows of integers
void ReadRow(int matrix[][COLUMNS], int maxRow, int maxCol) {
	printf("Enter %d x %d integers:\n", maxRow - 1, maxCol);

	for(int row = 0; row < maxRow - 1; row++) {
		for(int column = 0; column < maxCol; column++) {
			scanf("%d%*c", &matrix[row][column]);
		}
	}
}

// Function to calculate the sum of corresponding elements from the first ROWS-1 rows and store in the ROWSth row
void Calculate(int matrix[][COLUMNS], int maxRow, int maxCol) {
	int sum;

	for(int column = 0; column < maxCol; column++) {
		sum = 0;
		for(int row=0; row < maxRow - 1; row++) {
			sum += matrix[row][column];
		}
		matrix[maxRow - 1][column] = sum;
	}
}

// Function to print the matrix
void PrintMatrix(int matrix[][COLUMNS], int maxRow, int maxCol) {
	for (int row = 0; row < maxRow; row++) {
		for (int column = 0; column < maxCol; column++) {
			printf("%3d ", matrix[row][column]); // Print the element with space formatting for alignment
		}
		printf("\n"); // New line after each row
	}
}