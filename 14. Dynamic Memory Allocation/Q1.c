#include <stdio.h>
#include <stdlib.h>

// Function declarations
void readArray(int **, int);
void calculate(int **, int, int *, int *, int *);

int main(void) {
	int n;

	// Input matrix dimension
	printf("What is the matrix dimension? ");
	scanf("%d%*c", &n);

	// Dynamically allocate memory for the matrix (array of pointers to rows)
	// Allocate memory for 'n' pointers to int
	int **matrix = (int **)malloc(n * sizeof(int *));

	// Allocate memory for 'n' integers for each row of the matrix
	for (int i = 0; i < n; i++) {
		matrix[i] = (int *)malloc(n * sizeof(int));
	}

	// Read the matrix
	readArray(matrix, n);

	// Variables to hold diagonal sums and the maximum element
	int sumDiagonal1, sumDiagonal2, maxElement;

	// Calculate diagonal sums and maximum element
	calculate(matrix, n, &sumDiagonal1, &sumDiagonal2, &maxElement);

	// Print the results
	printf("\nThe diagonal top left to bottom right sums up to %d\n", sumDiagonal1);
	printf("The diagonal bottom left to top right sums up to %d\n", sumDiagonal2);
	printf("The maximum number in the matrix is %d\n", maxElement);

	// Free dynamically allocated memory
	for (int i = 0; i < n; i++) {
		free(matrix[i]);
	}
	free(matrix);

	return 0;
}

void readArray(int **matrix, int n) {
	printf("Enter the matrix:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d%*c", &matrix[i][j]);
		}
	}
}

void calculate(int **matrix, int n, int *sumDiagonal1, int *sumDiagonal2, int *maxElement) {
	*sumDiagonal1 = 0;  // Top left to bottom right
	*sumDiagonal2 = 0;  // Bottom left to top right
	*maxElement = matrix[0][0]; // Start with the first element as the maximum

	for (int i = 0; i < n; i++) {
		*sumDiagonal1 += matrix[i][i];  // Diagonal from top left to bottom right
		*sumDiagonal2 += matrix[i][n - i - 1];  // Diagonal from bottom left to top right

		// Find the maximum element in the matrix
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] > *maxElement) {
				*maxElement = matrix[i][j];
			}
		}
	}
}