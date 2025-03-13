#include <stdio.h>

#define SIZE 10

// Function declarations
void readArray(int [], int);
void bubbleSort(int arr[], int size);
void printArray(int arr[], int size);

int main(void) {
	int arr[SIZE]; // Declare an array of integers
	int size = SIZE; // Size of the array

	// Call the functions
	readArray(arr, size);  // Read the array elements
	printf("\nArray before sorting:\n");
	printArray(arr, size);  // Print the array before sorting
	bubbleSort(arr, size);  // Sort the array using bubble sort
	printf("\nArray after sorting:\n");
	printArray(arr, size);  // Print the array after sorting

	return 0;
}

// Function to read integers into the array
void readArray(int arr[], int size) {
	printf("Enter %d integers:\n", size);
	for (int i = 0; i < size; i++) {
		printf("Enter element %d: ", i + 1);
		scanf("%d%*c", &arr[i]);
	}
}

// Function to perform the bubble sort on the array
void bubbleSort(int arr[], int size) {
	int swapped;  // To track whether a swap was made

	for(int i = 0; i < size - 1; i++) {
		swapped = 0; // Reset swapped flag for each pass

		for(int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// Swap arr[j] and arr[j + 1]
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1; // A swap was made
			}
		}

		// If no two elements were swapped by inner loop, then the array is sorted
		if (!swapped) {
			break;
		}
	}
}

// Function to print the array
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}