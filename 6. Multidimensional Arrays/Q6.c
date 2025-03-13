#include <stdio.h>
#include <string.h>

#define SIZE 3
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

// Function to read names from the user until "end" is entered or SIZE names are entered
void ReadNames(char names[][MAX_NAME_LENGTH], int size, int length) {
	char name[MAX_NAME_LENGTH];
	int i = 0;

	printf("Enter up to %d names. Type 'end' to stop:\n", size);

	while (i < size) {
		printf("Enter name %d: ", i + 1);

		// Read the name using fgets to allow for spaces in names
		fgets(name, MAX_NAME_LENGTH, stdin);

		// Remove the trailing newline character if it exists
		size_t len = strlen(name);
		if (len > 0 && name[len - 1] == '\n') {
			name[len - 1] = '\0';
		}

		// Check if the entered name is "end" to stop the loop
		if (strcmp(name, "end") == 0) {
			break;
		}

		// Copy the name into the array
		strcpy(names[i], name);
		i++;
	}
}

// Function to print the names
void PrintNames(char names[][MAX_NAME_LENGTH], int size) {
	printf("\nThe names in the array are:\n");
	for (int i = 0; i < size; i++) {
		printf("%s\n", names[i]);
	}
}