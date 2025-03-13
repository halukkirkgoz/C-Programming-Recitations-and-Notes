#include <stdio.h>

// Function declaration
double calculateY(double);

int main(void) {
    
    // Print table header
    printf("  x     |    y\n");
    printf("----------------\n");

    // Loop through x values from -5 to 5 with a step of 0.5
    for (double x = -5.0; x <= 5.0; x += 0.5) {
        double y = calculateY(x);  // Calculate the corresponding y value

        // Print the x and y values in the table
        printf("%5.2lf   |  %5.2lf\n", x, y);
    }

    return 0;
}

// Function to calculate y = 2x^2 + 2x - 3
double calculateY(double x) {
    return 2 * x * x + 2 * x - 3;  // Equation: y = 2x^2 + 2x - 3
}
