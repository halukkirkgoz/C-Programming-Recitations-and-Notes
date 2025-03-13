#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

// Function declaration
double calculateSine(double);

int main(void) {

    // Print the table header
    printf("  x   |    sin(x)\n");
    printf("-----------------\n");
    
    // Loop through angles from 0 to 360 with steps of 30 degrees
    for (double angle = 0; angle <= 360; angle += 30) {
        // Calculate sine of the angle
        double sineValue = calculateSine(angle);
        
        // Print the angle and the corresponding sine value
        printf("%3.0lf   |   %7.4lf\n", angle, sineValue);
    }

    return 0;
}

// Function to calculate sine of an angle in degrees
double calculateSine(double degrees) {
    // Convert degrees to radians
    double radians =  degrees * (M_PI / 180.0);
    
    // Return the sine of the angle in radians
    return sin(radians);  
}