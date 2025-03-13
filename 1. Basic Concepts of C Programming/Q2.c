#include <stdio.h>

int main(void) {
    int num1, num2;

    printf("Enter 2 integer numbers: ");
    scanf("%d%d%*c", &num1, &num2);
    printf("The entered numbers are %d and %d\n", num1, num2);

    return 0;
}
