#include <stdio.h>

int main(void) {
    int currentDay, currentMonth, currentYear;
    int birthDay, birthMonth, birthYear;
    int ageYears, ageMonths;

    // Read the current date (day, month, year)
    printf("Enter the current date (day month year): ");
    scanf("%d%d%d%*c", &currentDay, &currentMonth, &currentYear);

    // Read the birth date (day, month, year)
    printf("Enter your birth date (day month year): ");
    scanf("%d%d%d%*c", &birthDay, &birthMonth, &birthYear);

    // Calculate the age in years
    ageYears = currentYear - birthYear;

    // Calculate the age in months (adjust for months)
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        ageYears--;  // Adjust age if the current date is before the birthday in this year
        ageMonths = currentMonth - birthMonth + 12;
    } else {
        ageMonths = currentMonth - birthMonth;
    }

    // If the birth day hasn't occurred yet this year, subtract a month
    if (currentDay < birthDay) {
        ageMonths--;
    }

    // Print the calculated age
    printf("Your age is: %d years and %d months\n", ageYears, ageMonths);

    return 0;
}

/*
Examples: 08.03.2015
          25.01.1985
        -____________
        -17 days 2 months 30 years = 13 days 1 month 30 years
        
          06.01.2015
          25.01.1985
        -____________
        -19 days 0 months 30 years = -19 days 12 month 29 years
                                   =  11 days 11 month 29 years
                                  
          14.01.2015
          05.11.1985
        -____________
         9 days -10 months 30 years = 9 days 2 month 29 years
*/