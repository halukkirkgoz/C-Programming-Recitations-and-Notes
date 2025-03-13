#include <stdio.h>

int main(void) {
    float R1, R2, Req;

    // Ask the user to enter the values of R1 and R2
    printf("Enter the value of R1 (in ohms): ");
    scanf("%f", &R1);
    printf("Enter the value of R2 (in ohms): ");
    scanf("%f", &R2);

    // Handle the case where either R1 or R2 is zero
    if (R1 == 0) {
        Req = R2;  // If R1 is 0, Req = R2
    } else if (R2 == 0) {
        Req = R1;  // If R2 is 0, Req = R1
    } else {
        // Otherwise, calculate using the parallel resistance formula
        Req = (R1 * R2) / (R1 + R2);
    }

    // Print the equivalent resistance
    printf("The equivalent resistance is: %.2f ohms\n", Req);

    return 0;
}
