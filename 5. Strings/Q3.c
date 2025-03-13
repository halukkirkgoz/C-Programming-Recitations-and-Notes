#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

// Function declaration
int isPalindrome(char []);

int main(void) {
    char str[SIZE], temp[SIZE];

    printf("Enter a word or sentence: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Copy the original string for display
    strncpy(temp, str, sizeof(str));

    // Check if the string is a palindrome
    printf("The sentence '%s' is %s\n", temp, isPalindrome(str) ? "a palindrome" : "not a palindrome");

    return 0;
}

int isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    // Compare characters from both ends moving toward the center
    while (left < right) {
        // Skip non-alphabetical characters
        if (!isalpha(str[left])) {
            left++;
        } else if (!isalpha(str[right])) {
            right--;
        } else {
            // Convert both characters to lowercase for comparison
            if (tolower(str[left]) != tolower(str[right])) {
                return 0;  // Return 0 (false) if not a palindrome
            }
            left++;
            right--;
        }
    }

    return 1;  // Return 1 (true) if it is a palindrome
}