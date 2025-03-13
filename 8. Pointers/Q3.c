#include <stdio.h>

// Function declaration
void ConvertSeconds(int, int *, int *, int *);

int main(void) {
	// Declare variables to store the input seconds and the result
	int totalSeconds;
	int hours, minutes, seconds;

	// Read the number of seconds from the user
	printf("Enter a time in seconds: ");
	scanf("%d%*c", &totalSeconds);

	// Call the ConvertSeconds function to perform the conversion
	ConvertSeconds(totalSeconds, &hours, &minutes, &seconds);

	// Print the result in hours, minutes, and seconds
	printf("%d seconds is equivalent to %d hours, %d minutes, and %d seconds.\n", totalSeconds, hours, minutes, seconds);

	return 0;
}

// Function to convert total seconds into hours, minutes, and seconds
void ConvertSeconds(int totalSeconds, int *hours, int *minutes, int *seconds) {
	*hours = totalSeconds / 3600;
	*minutes = (totalSeconds % 3600) / 60;
	*seconds = totalSeconds % 60;
}