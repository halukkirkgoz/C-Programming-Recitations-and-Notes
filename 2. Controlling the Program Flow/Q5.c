#include <stdio.h>

int main(void) {
    float number;

    // Prompt the user to enter a real number
    printf("Enter a real number: ");
    scanf("%f%*c", &number);

    // Check if the number is positive, zero, or negative
    if (number > 0) {
        printf("The number %.2f is positive.\n", number);
    } else if (number == 0) {
        printf("The number is zero.\n");
    } else {
        printf("The number %.2f is negative.\n", number);
    }

    return 0;
}