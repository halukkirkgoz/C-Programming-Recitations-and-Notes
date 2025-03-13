#include <stdio.h>

#define ROWS 10
#define COLUMNS 10

// Function declarations
void FillMatrix(int [][COLUMNS], int, int);
void PrintMatrix(int [][COLUMNS], int, int);

int main(void) {
	int matrix[ROWS][COLUMNS]; // Declare a ROWS x COLUMNS matrix

	// Fill the matrix with the appropriate values
	FillMatrix(matrix, ROWS, COLUMNS);

	// Print the matrix
	PrintMatrix(matrix, ROWS, COLUMNS);

	return 0;
}

// Function to fill the matrix
void FillMatrix(int matrix[][COLUMNS], int maxRow, int maxCol) {
	int num;

	// Loop through each row and column to fill the matrix
	for (int row = 0; row < maxRow; row++) {
		num = row + 1;
		for (int column = 0; column < maxCol; column++) {
			matrix[row][column] = num;
			num = num + row + 1;
		}
	}
}

// Function to print the matrix
void PrintMatrix(int matrix[][COLUMNS], int maxRow, int maxCol) {
	// Loop through each row and column to print the matrix
	for (int row = 0; row < maxRow; row++) {
		for (int column = 0; column < maxCol; column++) {
			printf("%3d ", matrix[row][column]); // Print the element with space formatting for alignment
		}
		printf("\n"); // New line after each row
	}
}