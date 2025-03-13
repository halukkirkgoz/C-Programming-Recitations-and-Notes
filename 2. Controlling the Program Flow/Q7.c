#include <stdio.h>

int main(void) {
    int speed, speedLimit;

    // Print the warning message
    printf("Be aware! Speeding is heavily fined!\n");

    // Ask the user for their speed and the speed limit
    printf("Enter your speed: ");
    scanf("%d%*c", &speed);
    printf("Enter the speed limit: ");
    scanf("%d%*c", &speedLimit);

    // Check if the user is speeding
    if (speed > speedLimit) {
        // Calculate the fine
        int excessSpeed = speed - speedLimit;
        float fine = 100 + (2.5 * excessSpeed);

        // Print the results
        printf("Your speed is %d km/h over the speed limit.\n", excessSpeed);
        printf("Your fine amounts to %.1f euro.\n", fine);
    }

    return 0;
}
