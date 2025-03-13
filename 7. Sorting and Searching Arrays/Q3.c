#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10
#define MAX_LENGTH 100

// Function declarations
void readNames(char [][MAX_LENGTH], int);
void bubbleSort(char [][MAX_LENGTH], int);
void printNames(char [][MAX_LENGTH], int);

int main(void) {
	char names[MAX_SIZE][MAX_LENGTH]; // Array to store names, assuming max length of 100 characters for each name
	int size;

	// Ask the user for the number of names
	do {
		printf("Enter the number of names you want to sort [1...%d]: ", MAX_SIZE);
		scanf("%d%*c", &size);
	} while (size < 1 || size > MAX_SIZE);

	// Call functions
	readNames(names, size);   // Read names
	bubbleSort(names, size);  // Sort names using bubble sort
	printf("\nNames after sorting:\n");
	printNames(names, size);  // Print the sorted names

	return 0;
}

// Function to read a list of names
void readNames(char names[][MAX_LENGTH], int size) {
	printf("\nEnter %d names:\n", size);
	for (int i = 0; i < size; i++) {
		printf("Enter name %d: ", i + 1);
		fgets(names[i], MAX_LENGTH, stdin);
		names[i][strcspn(names[i], "\n")] = '\0';  // Remove newline character from the input
	}
}

// Function to perform the bubble sort on the names
void bubbleSort(char names[][MAX_LENGTH], int size) {
	int swapped;  // To track whether a swap was made

	for (int i = 0; i < size - 1; i++) {
		swapped = 0;  // Reset swapped flag for each pass

		for (int j = 0; j < size - 1 - i; j++) {
			// Compare the names lexicographically using strcmp
			if (strcmp(names[j], names[j + 1]) > 0) {
				// Swap names[j] and names[j + 1]
				char temp[MAX_LENGTH];
				strcpy(temp, names[j]);
				strcpy(names[j], names[j + 1]);
				strcpy(names[j + 1], temp);
				swapped = 1;  // A swap was made
			}
		}

		// If no two names were swapped by inner loop, the array is sorted
		if (!swapped) {
			break;
		}
	}
}

// Function to print the list of names after sorting
void printNames(char names[][MAX_LENGTH], int size) {
	for (int i = 0; i < size; i++) {
		printf("%s\n", names[i]);
	}
	printf("\n");
}