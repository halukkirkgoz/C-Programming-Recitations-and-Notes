#include <stdio.h>

#define ROWS 10
#define COLUMNS 10

// Function declarations
void ReadMatrix(int [][COLUMNS], int, int);
void SwapMinMax(int [][COLUMNS], int, int);
void PrintMatrix(int [][COLUMNS], int, int);

int main(void) {
	int matrix[ROWS][COLUMNS];

	// Read the matrix elements
	ReadMatrix(matrix, ROWS, COLUMNS);

	// Print the original matrix
	printf("\nMatrix before Swapping:\n");
	PrintMatrix(matrix, ROWS, COLUMNS);

	// Find the minimum and maximum and swap them
	SwapMinMax(matrix, ROWS, COLUMNS);

	// Print the matrix after swapping
	printf("\nMatrix after Min-Max Swapping:\n");
	PrintMatrix(matrix, ROWS, COLUMNS);

	return 0;
}

// Function to read the matrix elements
void ReadMatrix(int matrix[][COLUMNS], int maxRow, int maxCol) {
	printf("Enter the elements of a %d x %d matrix:\n", maxRow, maxCol);

	for(int row = 0; row < maxRow; row++) {
		for(int column = 0; column < maxCol; column++) {
			scanf("%d%*c", &matrix[row][column]);
		}
	}
}

// Function to find the minimum and maximum elements in the array and swap them
void SwapMinMax(int matrix[][COLUMNS], int maxRow, int maxCol) {
	int min = matrix[0][0], max = matrix[0][0];
	int min_r = 0, min_c = 0, max_r = 0, max_c = 0;

	// Find the minimum and maximum elements and their positions
	for(int row = 0; row < maxRow; row++) {
		for(int column = 0; column < maxCol; column++) {
			if(matrix[row][column] < min) {
				min = matrix[row][column];
				min_r = row;
				min_c = column;
			}

			if(matrix[row][column] > max) {
				max = matrix[row][column];
				max_r = row;
				max_c = column;
			}
		}
	}

	// Swap the minimum and maximum elements
	matrix[max_r][max_c] = min;
	matrix[min_r][min_c] = max;
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