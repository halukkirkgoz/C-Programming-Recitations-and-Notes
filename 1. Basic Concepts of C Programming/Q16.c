#include <stdio.h>

int main(void) {
    int number, hundreds, tens, ones;
    
    printf("Enter an integer number with 3 digits: ");
    scanf("%d%*c", &number);
    
    hundreds = number / 100;
    tens = (number / 10) % 10;
    ones = number % 10;
    
    printf("The number printed backward is: %d%d%d\n", ones, tens, hundreds);

    return 0;
}