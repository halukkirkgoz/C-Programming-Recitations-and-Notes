#include <stdio.h>

int main(void) {
    int n, sum = 0;

    // Ask the user to enter an integer number
    printf("Enter an integer number: ");
    scanf("%d%*c", &n);

    // Calculate the sum of numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        sum += i; // Add i to the sum
    }

    // Print the result
    printf("The sum of numbers from 1 to %d is: %d\n", n, sum);

    return 0;
}
