#include <stdio.h>
#include <math.h>

int main(void) {
	float side1, side2, hypotenuse;

	// Ask the user to enter the lengths of the three sides
	printf("Enter the lengths of the sides (side1 side2 hypotenuse), enter 0 for the side to calculate: ");
	scanf("%f%f%f%*c", &side1, &side2, &hypotenuse);

	// Check which side is 0 and calculate the missing side
	if (side1 == 0 && side2 != 0 && hypotenuse != 0) {
		// side1 is missing, calculate it using the Pythagorean theorem
		side1 = sqrt(hypotenuse * hypotenuse - side2 * side2);
		printf("The length of side1 is: %.2f\n", side1);
	} else if (side1 != 0 && side2 == 0 && hypotenuse != 0) {
		// side2 is missing, calculate it using the Pythagorean theorem
		side2 = sqrt(hypotenuse * hypotenuse - side1 * side1);
		printf("The length of side2 is: %.2f\n", side2);
	} else if (side1 != 0 && side2 != 0 && hypotenuse == 0) {
		// hypotenuse is missing, calculate it using the Pythagorean theorem
		hypotenuse = sqrt(side1 * side1 + side2 * side2);
		printf("The length of the hypotenuse is: %.2f\n", hypotenuse);
	} else {
		printf("Invalid sides for calcuation.\n");
	}

	return 0;
}

