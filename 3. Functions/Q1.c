#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

// Function declaration
double calculateSine(double);

int main(void) {
    double angleDegrees;

    // Input: Prompt user to enter an angle in degrees
    printf("Enter an angle in degrees: ");
    scanf("%lf%*c", &angleDegrees);

    // Calculate and print the sine of the angle
    double sineValue = calculateSine(angleDegrees);
    printf("The sine of %.2lf degrees is: %.4lf\n", angleDegrees, sineValue);

    return 0;
}

// Function to calculate sine of an angle in degrees
double calculateSine(double degrees) {
    // Convert degrees to radians
    double radians =  degrees * (M_PI / 180.0);
    
    // Return the sine of the angle in radians
    return sin(radians);  
}