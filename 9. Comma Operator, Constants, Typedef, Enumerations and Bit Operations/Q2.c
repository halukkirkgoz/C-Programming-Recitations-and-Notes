#include <stdio.h>

// Enum type for months
enum Month {
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

// Function declarations
void read(int *, enum Month *);
void nextDay(int *, enum Month *);
void printDay(int, enum Month);

int main(void) {
	int day;
	enum Month month;

	// Read the current day and month from the user
	read(&day, &month);

	// Print the current day and month
	printf("The current day is: ");
	printDay(day, month);

	// Calculate and print the next day
	nextDay(&day, &month);
	printf("The next day is: ");
	printDay(day, month);

	return 0;
}

// Function to ask the user for the day and month and return the values using pointers
void read(int *day, enum Month *month) {
	printf("Enter the current day and month (as integers): ");
	scanf("%d%d%*c", day, (int *)month);  // Casting enum to int for user input
}

// Function to calculate the next day
void nextDay(int *day, enum Month *month) {
	// Array to hold the number of days in each month (not considering leap year)
	int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// Increment the day
	(*day)++;

	// Check if the day exceeds the number of days in the current month
	if (*day > days_in_month[*month]) {
		*day = 1;  // Reset day to 1
		(*month)++;  // Move to the next month
		if (*month > Dec) {  // If the month exceeds December, reset to January
			*month = Jan;
		}
	}
}

// Function to print the day and month
void printDay(int day, enum Month month) {
	// Array to hold month names corresponding to enum values
	const char *month_names[] = {
		"Invalid", "January", "February", "March", "April", "May", "June", "July",
		"August", "September", "October", "November", "December"
	};

	printf("%s %d\n", month_names[month], day);
}