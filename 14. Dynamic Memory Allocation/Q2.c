#include <stdio.h>
#include <stdlib.h>

// Function declarations
void fillMatrix(int **, int, int);
void printMatrix(int **, int, int);

int main(void) {
	int rows, cols;

	// Ask user for the number of rows and columns
	printf("Enter the number of rows and columns for the matrix: ");
	scanf("%d%d%*c", &rows, &cols);

	// Dynamically allocate memory for the matrix (array of pointers to rows)
	// Allocate memory for 'rows' pointers to int
	int **matrix = (int **)malloc(rows * sizeof(int *));

	// Allocate memory for 'cols' integers for each row of the matrix
	for (int i = 0; i < rows; i++) {
		matrix[i] = (int *)malloc(cols * sizeof(int));
	}

	// Fill the matrix with values
	fillMatrix(matrix, rows, cols);

	// Print the matrix
	printMatrix(matrix, rows, cols);

	// Free the dynamically allocated memory
	for (int i = 0; i < rows; i++) {
		free(matrix[i]);
	}
	free(matrix);

	return 0;
}

void fillMatrix(int **matrix, int rows, int cols) {
	// Fill the matrix with (row + 1) * (col + 1)
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = (i + 1) * (j + 1);
		}
	}
}

void printMatrix(int **matrix, int rows, int cols) {
	// Print the matrix
	printf("\nThe matrix contains following elements:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%-3d ", matrix[i][j]);
		}
		printf("\n");
	}
}