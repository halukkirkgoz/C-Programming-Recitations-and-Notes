#include <stdio.h>

// Macro definition for TOLOWER to convert uppercase letter to lowercase
#define TOLOWER(c) ((c) >= 'A' && (c) <= 'Z' ? (c) + ('a' - 'A') : (c))

int main(void) {
	char ch;

	// Prompt the user to enter characters
	printf("Enter characters, end with 0: ");

	// Loop to read and process each character until '0' is entered
	while (1) {
		ch = getchar(); // Read a character

		if (ch == '0') { // Stop if the user enters '0'
			break;
		}

		// Use the TOLOWER macro to convert the character if necessary
		ch = TOLOWER(ch);

		// Print the character (converted to lowercase if applicable)
		printf("%c ", ch);
	}

	printf("\n");
	return 0;
}
