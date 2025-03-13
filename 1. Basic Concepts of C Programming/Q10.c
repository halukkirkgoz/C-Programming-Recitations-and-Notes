#include <stdio.h>

int main(void) {
    int num;
    int sum = 0;

    // Prompt and read the 5 numbers one by one
    printf("Enter first number: ");
    scanf("%d%*c", &num);
    sum += num;

    printf("Enter second number: ");
    scanf("%d%*c", &num);
    sum += num;

    printf("Enter third number: ");
    scanf("%d%*c", &num);
    sum += num;

    printf("Enter fourth number: ");
    scanf("%d%*c", &num);
    sum += num;

    printf("Enter fifth number: ");
    scanf("%d%*c", &num);
    sum += num;

    // Calculate and print the mean
    printf("The mean of the entered numbers is %.2f\n", (float) sum / 5);

    return 0;
}
