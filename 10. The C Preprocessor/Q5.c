#include <stdio.h>

// Macro definition for IS_CAPITAL to check if a character is a capital letter
#define IS_CAPITAL(c) ((c) >= 'A' && (c) <= 'Z' ? 1 : 0)

// Macro definition for IS_SMALL to check if a character is a small letter
#define IS_SMALL(c) ((c) >= 'a' && (c) <= 'z' ? 1 : 0)

// Macro definition for IS_LETTER to check if a character is a letter (capital or small)
#define IS_LETTER(c) (IS_CAPITAL(c) || IS_SMALL(c))

int main(void) {
	char ch;

	// Test character
	printf("Enter a character: ");
	scanf("%c%*c", &ch); // Read a character from the user

	// Test the IS_LETTER macro
	printf("Is %c a letter? %d\n", ch, IS_LETTER(ch));

	return 0;
}