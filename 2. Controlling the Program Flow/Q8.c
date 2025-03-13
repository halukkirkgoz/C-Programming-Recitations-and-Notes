#include <stdio.h>

int main(void) {
    float weight, height, bmi;

    // Ask the user for their weight and height
    printf("Enter your weight in kg: ");
    scanf("%f%*c", &weight);
    
    printf("Enter your height in meters: ");
    scanf("%f%*c", &height);

    // Calculate the BMI using the formula
    bmi = weight / (height * height);

    // Print the BMI value
    printf("Your BMI is: %.2f\n", bmi);

    // Determine and print the BMI category
    if (bmi < 18.5) {
        printf("You are underweight.\n");
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        printf("You have a normal weight.\n");
    } else if (bmi >= 25 && bmi <= 29.9) {
        printf("You are overweight.\n");
    } else {
        printf("You are obese.\n");
    }

    return 0;
}
