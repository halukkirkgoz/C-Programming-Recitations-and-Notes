#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

// Function declaration
void ConvertToMorse(char);

// Morse code array for the letters A-Z
const char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

int main(void) {
	char word[MAX_WORD_LENGTH]; // Buffer to store the word

	// Prompt the user for a word
	printf("Enter a word: ");
	fgets(word, MAX_WORD_LENGTH, stdin);

	// Remove the newline character if it exists
	size_t len = strlen(word);
	if (len > 0 && word[len - 1] == '\n') {
		word[len - 1] = '\0';
	}

	// Print the word in Morse code
	printf("Morse code: ");

	// Loop through each character in the word and convert it to Morse code
	for (int i = 0; word[i] != '\0'; i++) {
		if (isalpha(word[i])) {
			// Convert and print the character only if it's an alphabet letter
			ConvertToMorse(word[i]);
		}
		// If the character is not a letter, do nothing (ignore it)
	}

	// Print a newline for better output formatting
	printf("\n");

	return 0;
}

// Function to convert a letter to its corresponding Morse code
void ConvertToMorse(char letter) {
	// Convert the letter to uppercase to simplify the comparison
	letter = toupper(letter);

	// Ensure the letter is between 'A' and 'Z'
	if (letter >= 'A' && letter <= 'Z') {
		int index = letter - 'A';  // Calculate the index (0-25)
		printf("%s ", morse[index]);
	}
}