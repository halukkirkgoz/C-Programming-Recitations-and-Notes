#include <stdio.h>

int main(void) {
    int number, minimum;

    // Ask the user to enter the first number
    printf("Enter number 1: ");
    scanf("%d%*c", &number);
    
    // Initialize the minimum with the first number
    minimum = number; 
    
    // Ask the user to enter the second number
    printf("Enter number 2: ");
    scanf("%d%*c", &number);
    
    if(number <= minimum) {
        minimum = number;
    }
    
    // Ask the user to enter the third number
    printf("Enter number 3: ");
    scanf("%d%*c", &number);
    
    if(number <= minimum) {
       minimum = number;
    }
    
    // Ask the user to enter the fourth number
    printf("Enter number 4: ");
    scanf("%d%*c", &number);
    
    if(number <= minimum) {
        minimum = number;
    }
    
    // Ask the user to enter the fifth number
    printf("Enter number 5: ");
    scanf("%d%*c", &number);
    
    if(number <= minimum) {
        minimum = number;
    }
    
    // Print the minimum number
    printf("The minimum of entered numbers: %d\n", minimum);

    return 0;
}