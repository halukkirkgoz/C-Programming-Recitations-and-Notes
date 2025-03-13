#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100
#define N 6

// Function declarations
void sortNames(char [][SIZE], int);
void removePunctuationAndSpaces(char []);
void toUpperCase(char []);
int customCompare(const char [], const char []);

int main(void) {
	char names[N][SIZE];

	// Read N names from the user
	for (int i = 0; i < N; i++) {
		printf("Enter name %d: ", i + 1);
		fgets(names[i], SIZE, stdin);

		// Remove the newline character if present
		names[i][strcspn(names[i], "\n")] = '\0';
	}

	// Sort the names alphabetically using the custom comparison
	sortNames(names, N);

	// Print the names in alphabetical order
	printf("\nNames in alphabetical order:\n");
	for (int i = 0; i < N; i++) {
		printf("%s\n", names[i]);
	}

	return 0;
}

// Function to compare two strings after converting them to uppercase and removing punctuation and spaces
int customCompare(const char str1[], const char str2[]) {
	char copy1[SIZE], copy2[SIZE];

	// Copy the original strings to temporary arrays
	strcpy(copy1, str1);
	strcpy(copy2, str2);

	// Remove punctuation and spaces, and convert to uppercase
	removePunctuationAndSpaces(copy1);
	removePunctuationAndSpaces(copy2);
	toUpperCase(copy1);
	toUpperCase(copy2);

	// Compare the modified strings using strcmp
	return strcmp(copy1, copy2);
}

// Function to remove punctuation and spaces from a string
void removePunctuationAndSpaces(char str[]) {
	int i = 0, j = 0;
	while (str[i] != '\0') {
		// Check if the character is a letter or number (ignores punctuation and spaces)
		if (isalnum((unsigned char)str[i])) {
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';  // Null-terminate the modified string
}

// Function to convert a string to uppercase
void toUpperCase(char str[]) {
	for (int i = 0; str[i] != '\0'; i++) {
		str[i] = toupper((unsigned char)str[i]);
	}
}

// Function to sort the names alphabetically using Bubble Sort
void sortNames(char names[][SIZE], int n) {
	char temp_name[SIZE];

	// Bubble Sort algorithm for sorting strings
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (customCompare(names[i], names[j]) > 0) {
				// Swap the names if they are in the wrong order
				strcpy(temp_name, names[i]);
				strcpy(names[i], names[j]);
				strcpy(names[j], temp_name);
			}
		}
	}
}
