#include <stdio.h>

int main(void) {
    float num1, num2, num3, min, max, intermediate;

    // Read three numbers from the user
    printf("Enter three numbers: ");
    scanf("%f%f%f%*c", &num1, &num2, &num3);

    // Find the maximum, intermediate, and minimum values
    if (num1 > num2 && num1 > num3) {
        max = num1;
        if (num2 > num3) {
            intermediate = num2;
            min = num3;
        } else {
            intermediate = num3;
            min = num2;
        }
    } else if (num2 > num1 && num2 > num3) {
        max = num2;
        if (num1 > num3) {
            intermediate = num1;
            min = num3;
        } else {
            intermediate = num3;
            min = num1;
        }
    } else {
        max = num3;
        if (num1 > num2) {
            intermediate = num1;
            min = num2;
        } else {
            intermediate = num2;
            min = num1;
        }
    }

    // Print the numbers in ascending order
    printf("Numbers in ascending order: %.2f, %.2f, %.2f\n", min, intermediate, max);

    return 0;
}
