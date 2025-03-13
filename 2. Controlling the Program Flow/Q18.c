#include <stdio.h>

int main(void) {
    int number;

    // Ask the user to enter an integer number
    printf("Enter an integer number: ");
    scanf("%d%*c", &number);

    // Print the multiplication table for the entered number
    printf("The table of multiplication of %d is:\n", number);
    for (int i = 1; i <= 20; i++) {
        printf("%d x %d = %d\n", i, number, i * number);
    }

    return 0;
}