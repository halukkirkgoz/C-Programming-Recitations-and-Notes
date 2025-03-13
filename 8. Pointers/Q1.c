#include <stdio.h>

// Function declaration
void ReadValues(double *, double *, double *);

int main(void) {
    // Declare three variables of type double
    double var1, var2, var3;

    // Call ReadValues to read the values of the variables
    ReadValues(&var1, &var2, &var3);

    // Print the values of the three variables
    printf("Value 1: %.2lf\n", var1);
    printf("Value 2: %.2lf\n", var2);
    printf("Value 3: %.2lf\n", var3);

    return 0;
}

// Function definition for reading values into three double variables
void ReadValues(double *a, double *b, double *c) {
    // Read the values for a, b, and c from user input
    printf("Enter value 1: ");
    scanf("%lf%*c", a);

    printf("Enter value 2: ");
    scanf("%lf%*c", b);

    printf("Enter value 3: ");
    scanf("%lf%*c", c);
}