#include <stdio.h>

int main(void) {
    int startHour, startMinute, startSecond;
    int endHour, endMinute, endSecond;
    int totalStartSeconds, totalEndSeconds, timeDifference;

    // Read the start time (hours, minutes, seconds)
    printf("Enter start time (hour minute second): ");
    scanf("%d%d%d%*c", &startHour, &startMinute, &startSecond);

    // Read the end time (hours, minutes, seconds)
    printf("Enter end time (hour minute second): ");
    scanf("%d%d%d%*c", &endHour, &endMinute, &endSecond);

    // Convert start time and end time into total seconds since midnight
    totalStartSeconds = startHour * 3600 + startMinute * 60 + startSecond;
    totalEndSeconds = endHour * 3600 + endMinute * 60 + endSecond;

    // If the start time is later than the end time, assume the start time is from the previous day
    if (totalStartSeconds > totalEndSeconds) {
        totalStartSeconds -= 24 * 3600; // Subtract 24 hours in seconds
    }

    // Calculate the time difference in seconds
    timeDifference = totalEndSeconds - totalStartSeconds;

    // Convert the time difference back into hours, minutes, and seconds
    int hours = timeDifference / 3600;
    int minutes = (timeDifference % 3600) / 60;
    int seconds = timeDifference % 60;

    // Print the result
    printf("Time difference: %02d hours %02d minutes %02d seconds\n", hours, minutes, seconds);

    return 0;
}
