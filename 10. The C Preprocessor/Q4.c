#include <stdio.h>

// Macro definition for IS_CAPITAL to check if a character is a capital letter
#define IS_CAPITAL(c) ((c) >= 'A' && (c) <= 'Z' ? 1 : 0)

// Macro definition for IS_SMALL to check if a character is a small letter
#define IS_SMALL(c) ((c) >= 'a' && (c) <= 'z' ? 1 : 0)

int main(void) {
    char ch;

    // Test character
    printf("Enter a character: ");
    scanf("%c%*c", &ch); // Read a character from the user

    // Test the IS_CAPITAL and IS_SMALL macros
    printf("Is %c a capital letter? %d\n", ch, IS_CAPITAL(ch));
    printf("Is %c a small letter? %d\n", ch, IS_SMALL(ch));

    return 0;
}
