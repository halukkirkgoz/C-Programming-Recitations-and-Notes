#include <stdio.h>

int main(void) {
	float num1, num2, result;
	char operand;

	// Ask the user to enter the expression
	printf("Enter an expression (without spaces!): ");
	scanf("%f%c%f%*c", &num1, &operand, &num2);  // Read number1, operator, and number2

	// Perform the calculation based on the operand
	switch (operand) {
	case '+':
		result = num1 + num2;
		printf("%.2f %c %.2f = %.2f\n", num1, operand, num2, result);
		break;
	case '-':
		result = num1 - num2;
		printf("%.2f %c %.2f = %.2f\n", num1, operand, num2, result);
		break;
	case '*':
		result = num1 * num2;
		printf("%.2f %c %.2f = %.2f\n", num1, operand, num2, result);
		break;
	case '/':
		if (num2 != 0) {
			result = num1 / num2;
			printf("%.2f %c %.2f = %.2f\n", num1, operand, num2, result);
		} else {
			printf("Error: Division by zero is not allowed.\n");
		}
		break;
	default:
		printf("Invalid operand.\n");
		break;
	}

	return 0;
}