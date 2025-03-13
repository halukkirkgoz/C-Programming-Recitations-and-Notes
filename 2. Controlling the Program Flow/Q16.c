#include <stdio.h>
#include <math.h>

int main(void) {
	double a, b, c, discriminant, root1, root2;

	// Input coefficients from the user
	printf("Enter the coefficients a, b, and c for the quadratic equation ax^2 + bx + c = 0:\n");
	printf("a: ");
	scanf("%lf", &a);
	printf("b: ");
	scanf("%lf", &b);
	printf("c: ");
	scanf("%lf", &c);

	// Case when a is 0 (equation is not quadratic)
	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				printf("The equation has infinite solutions.\n");
			} else {
				printf("The equation has no solution.\n");
			}
		} else {
			// Linear equation bx + c = 0, solve for x
			double root = -c / b;
			printf("This is a linear equation. The root is: %.2f\n", root);
		}
	} else {
		// Compute the discriminant
		discriminant = b * b - 4 * a * c;

		// Check the discriminant and find the roots
		if (discriminant > 0) {
			root1 = (-b + sqrt(discriminant)) / (2 * a);
			root2 = (-b - sqrt(discriminant)) / (2 * a);
			printf("The equation has two real roots: %.2f and %.2f\n", root1, root2);
		} else if (discriminant == 0) {
			root1 = -b / (2 * a);
			printf("The equation has one real root: %.2f\n", root1);
		} else {
			printf("The equation has no real roots.\n");
		}
	}

	return 0;
}