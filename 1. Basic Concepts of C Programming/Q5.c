#include <stdio.h>

int main(void) {
	float num1, num2, quotient;

	printf("Enter 2 real numbers: ");
	scanf("%f%f%*c", &num1, &num2);
	quotient = num1 / num2;
	printf("The quotient is: %.20f\n", quotient);

	return 0;
}