#include <stdio.h>
#include <string.h>

#define SIZE 10
#define MAX_NAME_LENGTH 50

// Function declarations
void ReadNames(char [][MAX_NAME_LENGTH], int, int);
void PrintNames(char [][MAX_NAME_LENGTH], int);

int main(void) {
	char names[SIZE][MAX_NAME_LENGTH];  // Array to store SIZE names, each with a max length of MAX_NAME_LENGTH characters

	// Read the names
	ReadNames(names, SIZE, MAX_NAME_LENGTH);

	// Print the names
	PrintNames(names, SIZE);

	return 0;
}

// Function to read names from the user
void ReadNames(char names[][MAX_NAME_LENGTH], int size, int length) {
	printf("Enter %d names:\n", size);
	for (int i = 0; i < size; i++) {
		printf("Name %d: ", i + 1);
		// Using fgets to read names with spaces and remove the trailing newline character
		fgets(names[i], length, stdin);

		// Remove the newline character if it exists
		size_t len = strlen(names[i]);
		if (len > 0 && names[i][len - 1] == '\n') {
			names[i][len - 1] = '\0';
		}
	}
}

// Function to print the names
void PrintNames(char names[][MAX_NAME_LENGTH], int size) {
	printf("\nThe names in the array are:\n");
	for (int i = 0; i < size; i++) {
		printf("%s\n", names[i]);
	}
}