#include <stdio.h>

#define SIZE 10

// Function declarations
void readArray(int [], int);
void swapWithMin(int arr[], int size);
void printArray(int arr[], int size);

int main(void) {
	int arr[SIZE]; // Declare an array of integers
	int size = SIZE; // Size of the array

	// Call the functions
	readArray(arr, size);  // Read the array elements
	printf("\nArray before swapping:\n");
	printArray(arr, size);  // Print the array before swapping
	swapWithMin(arr, size); // Swap the first element with the minimum value
	printf("\nArray after swapping:\n");
	printArray(arr, size);  // Print the array after swapping

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

// Function to swap the first integer with the minimum value in the array
void swapWithMin(int arr[], int size) {
	int minIndex = 0; // Assume first element is the minimum initially
	for (int i = 1; i < size; i++) {
		if (arr[i] < arr[minIndex]) {
			minIndex = i;
		}
	}

	// Swap the first element with the minimum element
	int temp = arr[0];
	arr[0] = arr[minIndex];
	arr[minIndex] = temp;
}

// Function to print the array
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}