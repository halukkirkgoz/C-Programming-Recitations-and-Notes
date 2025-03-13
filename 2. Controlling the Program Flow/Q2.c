#include <stdio.h>

int main(void) {
    int number;

    // Prompt the user to enter an integer
    printf("Enter an integer: ");
    scanf("%d%*c", &number);

    // Check if the number is even or odd
    if (number % 2 == 0) {
        printf("The number %d is even.\n", number);
    } else {
        printf("The number %d is odd.\n", number);
    }

    return 0;
}