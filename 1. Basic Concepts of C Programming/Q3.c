#include <stdio.h>

int main(void) {
    float num1, num2;

    printf("Enter 2 real numbers: ");
    scanf("%f%f%*c", &num1, &num2);
    printf("The sum of %.2f and %.2f is %.2f\n", num1, num2, num1 + num2);
    printf("The product of %.2f and %.2f is %.2f\n", num1, num2, num1 * num2);
    
    return 0;
}