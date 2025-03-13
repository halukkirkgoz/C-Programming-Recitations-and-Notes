#include <stdio.h>

int main(void) {
    int num1, num2, num3, num4, num5, num6;
    
    printf("Enter 6 integer numbers: ");
    scanf("%d%d%d%d%d%d%*c", &num1, &num2, &num3, &num4, &num5, &num6);
    
    printf("\n---------------\n");
    printf("|%5d |%5d |\n", num1, num2);
    printf("|-------------|\n");
    printf("|%5d |%5d |\n", num3, num4);
    printf("|-------------|\n");
    printf("|%5d |%5d |\n", num5, num6);
    printf("---------------\n");
    
    return 0;
}