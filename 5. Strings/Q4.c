#include <stdio.h>
#include <string.h>

#define SIZE 100

// Function declaration
void printWords(char []);

int main(void) {
	char str[SIZE];

	printf("Enter a string: ");
	fgets(str, sizeof(str), stdin);

	// Remove the newline character if present
	str[strcspn(str, "\n")] = '\0';

	// Print each word on a new line
	printWords(str);

	return 0;
}

void printWords(char str[]) {
	const char delimiters[] = " \t\n,.;:!?-_";
	char *word = strtok(str, delimiters);

	// Tokenize the string by spaces and common punctuation
	while (word != NULL) {
		printf("%s\n", word);  // Print the word
		word = strtok(NULL, delimiters);  // Get the next word
	}
}
