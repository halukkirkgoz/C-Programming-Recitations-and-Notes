#include <stdio.h>

#define DAYS_IN_WEEK 7  // Number of days in a week

// Function declarations
void readTemperatures(float [], int);
float calculateMeanTemperature(float [], int);
void printWarmerDays(float [], int, float);

int main(void) {
    float temperature[DAYS_IN_WEEK];  // Array to store temperatures
    float meanTemperature, limit;

    // Read temperatures for the week
    readTemperatures(temperature, DAYS_IN_WEEK);

    // Calculate the mean temperature
    meanTemperature = calculateMeanTemperature(temperature, DAYS_IN_WEEK);

    // Print the mean temperature
    printf("The mean temperature for this week is %.2f\n\n", meanTemperature);

    // Ask for the temperature limit
    printf("Enter the temperature limit: ");
    scanf("%f%*c", &limit);

    // Print the days warmer than the temperature limit
    printWarmerDays(temperature, DAYS_IN_WEEK, limit);

    return 0;
}

// Function to read temperatures for each day
void readTemperatures(float temperature[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter temperature for day %d: ", i);
        scanf("%f%*c", &temperature[i]);
    }
}

// Function to calculate the mean temperature
float calculateMeanTemperature(float temperature[], int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += temperature[i];
    }
    return sum / size;
}

// Function to print the days with temperature warmer than the limit
void printWarmerDays(float temperature[], int size, float limit) {
    int found = 0;  // Flag to check if any warmer days are found
    
    printf("Days with temperatures warmer than %.2f°C:\n", limit);
    
    for (int i = 0; i < size; i++) {
        if (temperature[i] > limit) {
            printf("Day %d: %.2f°C\n", i, temperature[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No days were warmer than %.2f°C this week.\n", limit);
    }
}
