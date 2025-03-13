#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>

// Function declarations
double rand01(void);
double approximatePi(long int);

int main(void) {
	// Seed the random number generator
	srand(time(NULL));

	long int numPoints = 100000; // Number of points to generate
	double piApproximation = approximatePi(numPoints);

	// Output the result
	printf("Approximation of Pi using %ld points: %.6f\n", numPoints, piApproximation);
	printf("Actual value of Pi: %.6f\n", M_PI);

	return 0;
}

// Function to generate a floating-point random number in the range [0, 1]
double rand01(void) {
	return (double) rand() / RAND_MAX;
}

// Function to approximate pi
double approximatePi(long int numPoints) {
	long int pointsInsideCircle = 0;

	// Generate random points and check if they are inside the circle
	for (long int i = 0; i < numPoints; i++) {
		double x = rand01();
		double y = rand01();

		// Check if the point is inside the circle (x^2 + y^2 < 1)
		if (x * x + y * y < 1) {
			pointsInsideCircle++;
		}
	}

	// Estimate pi using the ratio of points inside the circle to total points
	return 4.0 * pointsInsideCircle / numPoints;
}