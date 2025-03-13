#include <stdio.h>

#define SIZE 100

// Function declarations
void readName(char [], int);
void printName(char []);

int main(void) {
	char name[SIZE];  // Array to store the name

	// Call the function to read the name
	readName(name, SIZE);

	// Call the function to print the name
	printName(name);

	return 0;
}

// Function to read a name
void readName(char name[], int size) {
	printf("Enter your name: ");
	fgets(name, size, stdin);  // Reads a line of input, including spaces

	// Remove the newline character if present
	for (int i = 0; name[i] != '\0'; i++) {
		if (name[i] == '\n') {
			name[i] = '\0';  // Replace newline with null terminator
			break;
		}
	}
}

// Function to print the name
void printName(char name[]) {
	printf("Hello, %s\n", name);
}
