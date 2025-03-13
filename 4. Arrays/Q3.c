#include <stdio.h>

#define MAX 100

// Function declarations
int ReadArray(int []);
void PrintArray(int [], int);

int main(void) {
	int row[MAX];  // Array to store up to 100 integers
	int size;

	// Call the function to read numbers
	size = ReadArray(row);

	// Call the function to print the entered numbers
	PrintArray(row, size);

	return 0;
}

// Function to read integers and store them in the array
int ReadArray(int arr[]) {
	int count = 0;
	int num;

	while(1) {
		printf("Enter an integer number: ");
		scanf("%d%*c", &num);

		// Stop if the user enters 999
		if (num == 999) {
			break;
		}

		// Store the number in the array if it's not 999
		if (count < MAX) {
			arr[count] = num;
			count++;
		} else {
			printf("Array is full, cannot store more numbers.\n");
			break;
		}
	}

	return count;
}

// Function to print the integers from the array
void PrintArray(int arr[], int size) {
	printf("\nThe numbers you entered are:\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}