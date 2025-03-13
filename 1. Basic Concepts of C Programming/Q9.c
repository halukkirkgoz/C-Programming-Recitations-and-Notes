#include <stdio.h>

int main(void) {
	int total_seconds, temp;
	int days, hours, minutes, seconds;

	printf("Enter a number of seconds: ");
	scanf("%d%*c", &total_seconds);
	
	// Save the original value of total_seconds for output in a temporary variable
	temp = total_seconds;

	// Calculate the number of days, hours, minutes, and seconds
	days = total_seconds / 86400;  // 1 day = 86400 seconds
	total_seconds %= 86400;  // Get the remaining seconds after calculating days

	hours = total_seconds / 3600;  // 1 hour = 3600 seconds
	total_seconds %= 3600;  // Get the remaining seconds after calculating hours

	minutes = total_seconds / 60;  // 1 minute = 60 seconds
	seconds = total_seconds % 60;  // Remaining seconds

	printf("%d sec = %d day(s) %d hour(s) %d minute(s) and %d second(s)\n", temp, days, hours, minutes, seconds);

	return 0;
}