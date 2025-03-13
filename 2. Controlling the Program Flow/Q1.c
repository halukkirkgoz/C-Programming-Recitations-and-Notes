#include <stdio.h>

int main(void) {
    int number;

    // Prompt the user to enter an integer
    printf("Enter an integer: ");
    scanf("%d%*c", &number);

    // Check if the number is positive, negative, or zero
    if (number > 0) {
        printf("The number %d is positive.\n", number);
    } else {
        printf("The number %d is not positive.\n", number);
    }
    
    return 0;
}