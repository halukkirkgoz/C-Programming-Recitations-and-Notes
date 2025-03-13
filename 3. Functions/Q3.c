#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

// Function declarations
double calculateHypotenuse(double, double);
double calculateAngle(double, double);

int main(void) {
    double a, b, c, angle1, angle2;

    // Input: Prompt user to enter the lengths of the two sides a and b
    printf("Enter the lengths of the two sides a and b of the right-angled triangle: ");
    scanf("%lf%lf%*c", &a, &b);

    // Calculate the hypotenuse using Pythagoras' theorem
    c = calculateHypotenuse(a, b);

    // Calculate the acute angles in degrees
    angle1 = calculateAngle(a, b); // Angle opposite to side a
    angle2 = 90.0 - angle1;        // The other acute angle is complementary to angle1

    // Output the results
    printf("The length of the hypotenuse is: %.2f\n", c);
    printf("The two acute angles are: %.0f° and %.0f°\n", angle1, angle2);

    return 0;
}

// Function to calculate the hypotenuse of a right-angled triangle
double calculateHypotenuse(double a, double b) {
    return sqrt(a * a + b * b); // Pythagorean theorem
    // return hypot(a, b);
}

// Function to calculate the angle in degrees given the opposite and adjacent sides
double calculateAngle(double opposite, double adjacent) {
    return atan(opposite / adjacent) * (180.0 / M_PI); // arctan converts radians to degrees
    // return atan2(opposite, adjacent) * (180.0 / M_PI); // arctan converts radians to degrees
}