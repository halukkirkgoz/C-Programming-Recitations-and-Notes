#include <stdio.h>

#define PI 3.141592653589793  // Define π as a constant

int main(void) {
	double radius, area;

	printf("Enter the radius of the circle: ");
	scanf("%lf%*c", &radius);

	// The surface area of the circle (Area = π * r^2)
	area = PI * radius * radius;

	printf("The surface area of the circle is: %.6lf\n", area);

	return 0;
}