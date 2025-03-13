#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6
#define MAX_NUM 42
#define MIN_NUM 1

// Function declarations
void generateUniqueRandomNumbers(int [], int, int, int);
void printArray(int [], int);

int main(void) {
	int arr[SIZE] = {0};

	srand(time(NULL));  // Seed the random number generator

	// Generate 6 unique random numbers between 1 and 42
	generateUniqueRandomNumbers(arr, SIZE, MIN_NUM, MAX_NUM);

	// Print the generated unique random numbers
	printArray(arr, SIZE);

	return 0;
}

// Function to generate unique random numbers
void generateUniqueRandomNumbers(int arr[], int size, int min, int max) {
	int num;

	for (int i = 0; i < size; i++) {
		do {
			num = rand() % (max - min + 1) + min;  // Generate a random number between min and max
			int isDuplicate = 0;

			// Check if the number already exists in the array
			for (int j = 0; j < i; j++) {
				if (arr[j] == num) {
					isDuplicate = 1;  // Found a duplicate, break the loop
					break;
				}
			}

			if (!isDuplicate) {
				arr[i] = num;  // Assign the unique number to the array
			}

		} while (arr[i] == 0);  // If the number is still 0 (not assigned), generate a new one
	}
}

// Function to print the array
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
