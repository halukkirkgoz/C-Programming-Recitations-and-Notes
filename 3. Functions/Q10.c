#include <stdio.h>

// Function declarations
int isLeapYear(int);
int numberOfDays(int, int);

int main(void) {
    int month, year;

    // Read the year and month from the user
    printf("Enter the year: ");
    scanf("%d%*c", &year);
    printf("Enter the month (1-12): ");
    scanf("%d%*c", &month);

    // Calculate and print the number of days in the specified month of the specified year
    int days = numberOfDays(month, year);
    if (days != -1) {
        printf("Month %d of %d has %d days.\n", month, year, days);
    } else {
        printf("Invalid month entered.\n");
    }

    return 0; 
}

// Function to determine if a given year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return 1; // Leap year
    } else {
        return 0; // Not a leap year
    }
}

// Function to calculate the number of days in a given month of a specific year
int numberOfDays(int month, int year) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else if (month == 2) {
        if (isLeapYear(year)) {
            return 29;
        } else {
            return 28;
        }
    } else {
        return -1; // Invalid month
    }
}