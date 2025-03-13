#include <stdio.h>

// Function declaration
double exponentiation(double base, int exponent);

int main(void) {
    double base, result;
    int exponent;

    // Read the base and exponent from the user
    printf("Enter the base: ");
    scanf("%lf%*c", &base);
    
    printf("Enter the exponent: ");
    scanf("%d%*c", &exponent);

    // Call the exponentiation function
    result = exponentiation(base, exponent);

    // Print the result
    printf("%.2lf raised to the power of %d is %.2lf\n", base, exponent, result);

    return 0;
}

// Function definition for exponentiation
double exponentiation(double base, int exponent) {
    double result = 1.0;

    // Handle the case where exponent is 0
    if (exponent == 0) {
        return 1.0;  // Any number raised to the power of 0 is 1
    }

    // If exponent is positive
    if (exponent > 0) {
        for (int i = 1; i <= exponent; i++) {
            result *= base;
        }
    } 
    // If exponent is negative
    else {
        for (int i = 1; i <= -exponent; i++) {
            result *= base;
        }
        result = 1.0 / result;  // For negative exponents, take the reciprocal
    }

    return result;
}