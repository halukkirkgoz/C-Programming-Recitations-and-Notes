#include <stdio.h>
#include <string.h>

#define SIZE 100

// Function declarations
void readWord(char[], int, const char[]);
void concatenateWords(char[], char[], char[], char[]);

int main(void) {
	char word1[SIZE], word2[SIZE], word3[SIZE];  // Arrays to store the words
	char result[SIZE * 3];  // Array to store the concatenated result

	// Read three words separately
	readWord(word1, SIZE, "Enter the first word: ");
	readWord(word2, SIZE, "Enter the second word: ");
	readWord(word3, SIZE, "Enter the third word: ");

	// Concatenate the words into the result string
	concatenateWords(word1, word2, word3, result);

	// Print the content of the 4th string (concatenated result)
	printf("\n%s\n", result);

	return 0;
}

// Function to read a word
void readWord(char word[], int size, const char prompt[]) {
	printf("%s", prompt);
	fgets(word, size, stdin);

	// Remove the newline character if present
	word[strcspn(word, "\n")] = '\0';
}

// Function to concatenate three words with spaces
void concatenateWords(char word1[], char word2[], char word3[], char result[]) {
	// Combine the words with spaces
	snprintf(result, SIZE * 3, "%s %s %s", word1, word2, word3);
}
