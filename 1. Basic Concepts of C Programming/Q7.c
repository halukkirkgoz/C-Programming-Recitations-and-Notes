#include <stdio.h>

int main(void) {
    char firstName[100], lastName[100];

    printf("Enter your first name: ");
    scanf("%[^\n]%*c", firstName);  // Read the first name with spaces

    printf("Enter your last name: ");
    scanf("%[^\n]%*c", lastName);  // Read the last name with spaces

    printf("The entered name is: %s %s\n", firstName, lastName);

    return 0;
}

// %[^\n]: This tells scanf to read everything up to but not including the newline.