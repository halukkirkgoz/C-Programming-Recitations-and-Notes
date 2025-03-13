#include <stdio.h>

// Function declaration
int readnumber(int, int);

int main(void) {
    int lower, upper, number;

    // Ask the user for the lower and upper boundaries
    printf("Enter the lower boundary: ");
    scanf("%d%*c", &lower);

    printf("Enter the upper boundary: ");
    scanf("%d%*c", &upper);

    // Call the function to read a number within the user-defined range
    number = readnumber(lower, upper);

    // Output the number that was read
    printf("The number read is %d\n", number);

    return 0;
}

// Definition of the function
int readnumber(int lower_boundary, int upper_boundary) {
    int num;

    // Ask for a valid number within the boundaries until the input is correct
    do {
        printf("Enter a number between %d and %d: ", lower_boundary, upper_boundary);
        scanf("%d%*c", &num);

        // Check if the number is within the specified range
        if (num < lower_boundary || num > upper_boundary) {
            printf("Invalid input! Please enter a number between %d and %d.\n", lower_boundary, upper_boundary);
        }
    } while (num < lower_boundary || num > upper_boundary);  // Repeat if input is not valid

    return num;
}