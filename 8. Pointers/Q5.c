#include <stdio.h>
#include <string.h>

#define MAXSTRING 100

// Function declaration
void print_string(char *);

int main(void) {
    char s1[MAXSTRING], s2[MAXSTRING];

    // Copy the strings to s1 and s2
    strcpy(s1, "Mary, Mary, quite contrary.\n");
    strcpy(s2, "How does your garden grow?\n");

    // Print each string using print_string
    print_string(s1);
    print_string(s2);

    // Concatenate s2 to s1 and print the resulting string
    strcat(s1, s2);
    print_string(s1);

    return 0;
}

// Function to print a string character by character
void print_string(char *c) {
    // Iterate through each character of the string
    while (*c != '\0') {
        putchar((int)*c);  // Print the current character
        c++;               // Move to the next character
    }
}