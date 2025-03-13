#include <stdio.h>

int main(void) {
	int num1, num2;

	printf("Enter 2 integer numbers: ");
	scanf("%d%d%*c", &num1, &num2);
	printf("Integer quotient = %d\n", num1 / num2);
	printf("Remainder = %d\n", num1 % num2);
	printf("Quotient = %.2f\n", (float) num1 / num2);

	return 0;
}