#include <stdio.h>

// Function declarations
void Read(double *, double *);  
void Swap(double *, double *);  
void Print(double, double); 

int main(void) {
    // Declare two variables of type double
    double number1, number2;

    // Read the two numbers from the user
    Read(&number1, &number2);
    
    // Print the original values
    printf("Before swapping:\n");
    Print(number1, number2);
    
    // Swap the numbers
    Swap(&number1, &number2);

    // Print the swapped values
    printf("\nAfter swapping:\n");
    Print(number1, number2);

    return 0;
}

// Function to read two numbers from the user
void Read(double *a, double *b) {
    printf("Enter two numbers: ");
    scanf("%lf%lf%*c", a, b);
}

// Function to swap the values of two numbers
void Swap(double *a, double *b) {
    *a = *a + *b;  // Now a holds the sum of a and b
    *b = *a - *b;  // Now b holds the original value of a
    *a = *a - *b;  // Now a holds the original value of b
}

// Function to print the values of two numbers
void Print(double a, double b) {
    printf("Number 1: %.2lf\n", a);
    printf("Number 2: %.2lf\n", b);
}