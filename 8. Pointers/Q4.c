#include <stdio.h>

#define DAYS_IN_WEEK 7

// Function declarations
void Read(float [][DAYS_IN_WEEK]);
void Print(float [][DAYS_IN_WEEK], const char *[]);
void Calculate(float [][DAYS_IN_WEEK], int *, int *, int *, int *);

int main(void) {
	// Array to store day and night temperatures
	float temperatures[2][DAYS_IN_WEEK];

	// Array to store day names
	const char *daysOfWeek[DAYS_IN_WEEK] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

	// Indexes for minimum and maximum temperatures
	int minDayIdx, maxDayIdx, minNightIdx, maxNightIdx;

	// Read temperatures
	Read(temperatures);

	// Print the temperatures
	Print(temperatures, daysOfWeek);

	// Calculate and print the minimum and maximum temperatures with the days
	Calculate(temperatures, &minDayIdx, &maxDayIdx, &minNightIdx, &maxNightIdx);

	// Printing results for Min and Max
	printf("\nMin:\n");
	printf("\tNight: %s = %5.1f\n", daysOfWeek[minNightIdx], temperatures[1][minNightIdx]);
	printf("\tDay:   %s = %5.1f\n", daysOfWeek[minDayIdx], temperatures[0][minDayIdx]);
	printf("\nMax:\n");
	printf("\tNight: %s = %5.1f\n", daysOfWeek[maxNightIdx], temperatures[1][maxNightIdx]);
	printf("\tDay:   %s = %5.1f\n", daysOfWeek[maxDayIdx], temperatures[0][maxDayIdx]);

	return 0;
}

// Function to read temperatures for both day and night for each day of the week
void Read(float temperatures[2][DAYS_IN_WEEK]) {
	printf("Enter the temperatures for the full week:\n");

	for (int i = 0; i < DAYS_IN_WEEK; i++) {
		printf("\nDay %d (Mon=0, Tue=1, ..., Sun=6):\n", i);
		printf("Day temperature: ");
		scanf("%f%*c", &temperatures[0][i]);  // Day temperature
		printf("Night temperature: ");
		scanf("%f%*c", &temperatures[1][i]);  // Night temperature
	}
}

// Function to print the temperatures of the entire week
void Print(float temperatures[2][DAYS_IN_WEEK], const char *daysOfWeek[DAYS_IN_WEEK]) {
	// Print headers
	printf("\nTemperatures for the week:\n");
	printf("         ");
	for (int i = 0; i < DAYS_IN_WEEK; i++) {
		printf("%8s", daysOfWeek[i]);
	}
	printf("\n");

	// Print Day temperatures
	printf("Day      ");
	for (int i = 0; i < DAYS_IN_WEEK; i++) {
		printf("%8.1f", temperatures[0][i]);
	}
	printf("\n");

	// Print Night temperatures
	printf("Night    ");
	for (int i = 0; i < DAYS_IN_WEEK; i++) {
		printf("%8.1f", temperatures[1][i]);
	}
	printf("\n");
}

// Function to calculate the minimum and maximum temperatures for day and night
void Calculate(float temperatures[2][DAYS_IN_WEEK], int *minDayIdx, int *maxDayIdx, int *minNightIdx, int *maxNightIdx) {
	*minDayIdx = 0;
	*maxDayIdx = 0;
	*minNightIdx = 0;
	*maxNightIdx = 0;

	for (int i = 1; i < DAYS_IN_WEEK; i++) {
		// Day temperatures
		if (temperatures[0][i] < temperatures[0][*minDayIdx]) {
			*minDayIdx = i;
		}
		if (temperatures[0][i] > temperatures[0][*maxDayIdx]) {
			*maxDayIdx = i;
		}

		// Night temperatures
		if (temperatures[1][i] < temperatures[1][*minNightIdx]) {
			*minNightIdx = i;
		}
		if (temperatures[1][i] > temperatures[1][*maxNightIdx]) {
			*maxNightIdx = i;
		}
	}
}