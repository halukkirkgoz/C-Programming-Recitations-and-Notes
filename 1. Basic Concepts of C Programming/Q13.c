#include <stdio.h>

int main(void) {
    double U, R1, R2, I, V2;

    // Ask user for the input values (U, R1, R2)
    printf("Enter the applied voltage (U) in volts: ");
    scanf("%lf%*c", &U);

    printf("Enter the resistance of R1 in ohms: ");
    scanf("%lf%*c", &R1);

    printf("Enter the resistance of R2 in ohms: ");
    scanf("%lf%*c", &R2);

    // Calculate the current I using Ohm's law
    I = U / (R1 + R2);

    // Calculate the voltage V2 across resistor R2
    V2 = I * R2;

    // Output the results
    printf("\nThe current flowing through the circuit (I) is: %.2lf A\n", I);
    printf("The voltage across resistor R2 (V2) is: %.2lf V\n", V2);

    return 0;
}
