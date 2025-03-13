#include <stdio.h>

// Enum definition for months
enum t_month {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

// Function declarations
enum t_month lastMonth(enum t_month);
void printMonth(enum t_month);

int main(void) {
	// Print table header
	printf("Current Month | Previous Month\n");
	printf("------------------------------\n");

	// Loop through all 12 months
	for (enum t_month current = Jan; current <= Dec; current++) {
		enum t_month prev = lastMonth(current);  // Get the previous month

		// Print current month and previous month
		printMonth(current);
		printf(" | ");
		printMonth(prev);
		printf("\n");
	}

	return 0;
}

// Function to get the previous month
enum t_month lastMonth(enum t_month current) {
	if (current == Jan) {
		return Dec;  // December comes before January
	}
	return current - 1;  // Subtract 1 to get the previous month
}

// Function to print the month in string format
void printMonth(enum t_month month) {
	switch(month) {
	case Jan:
		printf("%-13s", "January");
		break;
	case Feb:
		printf("%-13s", "February");
		break;
	case Mar:
		printf("%-13s", "March");
		break;
	case Apr:
		printf("%-13s", "April");
		break;
	case May:
		printf("%-13s", "May");
		break;
	case Jun:
		printf("%-13s", "June");
		break;
	case Jul:
		printf("%-13s", "July");
		break;
	case Aug:
		printf("%-13s", "August");
		break;
	case Sep:
		printf("%-13s", "September");
		break;
	case Oct:
		printf("%-13s", "October");
		break;
	case Nov:
		printf("%-13s", "November");
		break;
	case Dec:
		printf("%-13s", "December");
		break;
	default:
		printf("%-13s", "Unknown");
		break;
	}
}
