#include <stdio.h>

int main(void) {
    float number;

    // Prompt the user to enter a real number
    printf("Enter a real number: ");
    scanf("%f%*c", &number);

    // Check if the number lies in the range [5, 10[
    if (number >= 5 && number < 10) {
        printf("The number %.2f lies in the range [5, 10[.\n", number);
    } else {
        printf("The number %.2f does not lie in the range [5, 10[.\n", number);
    }

    return 0;
}