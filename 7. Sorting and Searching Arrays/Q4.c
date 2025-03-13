#include <stdio.h>

#define SIZE 10

// Function declarations
void insertionSort(int [], int);
void printArray(int [], int);

int main(void) {
	int arr[SIZE];  // Array to hold integers
	int size = 0; // Current size of the array

	// Read the first integer
	printf("Enter the first integer: ");
	scanf("%d%*c", &arr[size]);
	size++;  // Increment size
	printArray(arr, size); // Print the current state of the array

	// Repeatedly read the next integer and insert it into the sorted list
	for (int i = 1; i < SIZE; i++) {
		int num;
		printf("Enter the next integer: ");
		scanf("%d%*c", &num);

		arr[size] = num;  // Add the number to the array
		size++;  // Increment the size of the array

		insertionSort(arr, size);  // Sort the array using insertion sort
		printArray(arr, size);  // Print the current state of the array
	}

	return 0;
}

// Function to read and insert elements one by one into the sorted list
void insertionSort(int arr[], int size) {
	int i, j, key;

	// Start from the second element (index 1)
	for (i = 1; i < size; i++) {
		key = arr[i]; // Current element to be inserted
		j = i - 1;

		// Shift elements of arr[0...i-1], that are greater than key,
		// to one position ahead of their current position
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}

		// Insert the key at the correct position
		arr[j + 1] = key;
	}
}

// Function to print the array
void printArray(int arr[], int size) {
	printf("Sorted list of integers:\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}