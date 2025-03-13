#include <stdio.h>

#define MAX_SIZE 10  // Maximum dimension for the matrix

// Function declarations
void ReadMatrix(int [][MAX_SIZE], int n);
void TransposeMatrix(int [][MAX_SIZE], int [][MAX_SIZE], int);
void PrintMatrix(int [][MAX_SIZE], int);

int main(void) {
	int n;
	int matrix[MAX_SIZE][MAX_SIZE];
	int transpose[MAX_SIZE][MAX_SIZE];

	// Read the dimension of the square matrix
	printf("Enter the dimension of the square matrix (<= 10): ");
	scanf("%d%*c", &n);

	// Check if the dimension is valid
	if (n < 1 || n > 10) {
		printf("Invalid dimension. The matrix dimension must be between 1 and 10.\n");
		return 1; // Exit with error
	}

	// Read the matrix elements
	ReadMatrix(matrix, n);

	// Transpose the matrix
	TransposeMatrix(matrix, transpose, n);

	// Print the original matrix
	printf("\nOriginal Matrix:\n");
	PrintMatrix(matrix, n);

	// Print the transposed matrix
	printf("\nTransposed Matrix:\n");
	PrintMatrix(transpose, n);

	return 0;
}

// Function to read the matrix elements
void ReadMatrix(int matrix[][MAX_SIZE], int n) {
	printf("Enter the elements of a %d x %d matrix:\n", n, n);
	
	for(int row = 0; row < n; row++) {
		for(int column = 0; column < n; column++) {
			scanf("%d%*c", &matrix[row][column]);
		}
	}
}

// Function to transpose the matrix
void TransposeMatrix(int matrix[][MAX_SIZE], int transpose[][MAX_SIZE], int n) {
	for (int row = 0; row < n; row++) {
		for (int column = 0; column < n; column++) {
			transpose[column][row] = matrix[row][column];
		}
	}
}

// Function to print the matrix
void PrintMatrix(int matrix[][MAX_SIZE], int n) {
	for (int row = 0; row < n; row++) {
		for (int column = 0; column < n; column++) {
			printf("%3d ", matrix[row][column]); // Print the element with space formatting for alignment
		}
		printf("\n"); // New line after each row
	}
}