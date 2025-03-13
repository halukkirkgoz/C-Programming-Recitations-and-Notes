#include <stdio.h>
#include <string.h>

#define MAXSTRING 100

// Function declarations
void Read(char *);
void Print(char *, char *, char *);

int main(void) {
	char word[MAXSTRING];
	char smallest, largest;
	int again = 1;

	while (again) {
		// Read the word
		Read(word);

		// Print the converted word and find smallest and largest
		Print(word, &smallest, &largest);

		// Ask if the user wants to input another word
		printf("\nagain? (1=yes, 0=no): ");
		scanf("%d%*c", &again);
	}

	return 0;
}

// Function to read a word (ensure the word has at least 2 characters)
void Read(char *word) {
	do {
		printf("Enter a word or a series of letters: ");
		fgets(word, MAXSTRING, stdin);
		// Remove newline character if it is read by fgets
		word[strcspn(word, "\n")] = '\0';
	} while (strlen(word) < 2); // Ensure the word has at least 2 characters
}

// Function to print the converted word and find the smallest and largest letter
void Print(char *word, char *smallest, char *largest) {
	// Print the first two characters
	printf("\n%c%c", word[0], word[1]);

	// Loop through the word, comparing the i-th character with the (i+1)-th character
	for (int i = 1; word[i] != '\0'; i++) {
		// Compare current character with the next one
		if (word[i] > word[i - 1]) {
			printf("%c", word[i]); // Print the larger character
		} else {
			printf("%c", word[i - 1]); // Print the larger character
		}
	}

	// Find the smallest and largest letters in the word
	*smallest = word[0];
	*largest = word[0];

	for (int i = 1; word[i] != '\0'; i++) {
		if (word[i] < *smallest) {
			*smallest = word[i];
		}
		if (word[i] > *largest) {
			*largest = word[i];
		}
	}

	// Print the smallest and largest letters
	printf("\nlargest = %c and smallest = %c\n", *largest, *smallest);
}