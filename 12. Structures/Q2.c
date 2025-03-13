#include <stdio.h>
#include <string.h>

#define N 5  // Number of persons

// Define the structure "Date"
typedef struct {
	unsigned short int day;
	char month[20];
	unsigned int year;
} Date;

// Define the structure "Person"
typedef struct {
	char firstname[50];
	char lastname[50];
	Date dateOfBirth;
	Date enrollmentDate;
} Person;

// Function declarations
void readPerson(Person *);
void printPerson(Person);
void readDate(Date *);
void printDate(Date);

int main(void)
{
	Person persons[N]; // Declare an array of N persons

	printf("Enter %d names (first name and surname) and their dates:\n", N);

	// Read the data of N persons
	for(int i=0; i < N; i++) {
		printf("\nEnter details for person %d:\n", i + 1);
		readPerson(&persons[i]);
	}

	// Print the data of N persons
	printf("\nThe %d entered names and their dates are:\n", N);
	for (int i = 0; i < N; i++) {
		printPerson(persons[i]);
	}

	return 0;
}

// Function to read the data of 1 Person
void readPerson(Person *person) {
	printf("First Name: ");
	fgets(person->firstname, sizeof(person->firstname), stdin);
	person->firstname[strcspn(person->firstname, "\n")] = '\0'; // Remove newline character

	printf("Last Name: ");
	fgets(person->lastname, sizeof(person->lastname), stdin);
	person->lastname[strcspn(person->lastname, "\n")] = '\0'; // Remove newline character

	// Read date of birth
	printf("Date of Birth:\n");
	readDate(&(person->dateOfBirth));

	// Read enrollment date
	printf("Enrollment Date:\n");
	readDate(&(person->enrollmentDate));
}

// Function to print the data of 1 Person
void printPerson(Person person) {
	printf("Name: %s %s\n", person.firstname, person.lastname);
	printf("Date of Birth: ");
	printDate(person.dateOfBirth);
	printf("Enrollment Date: ");
	printDate(person.enrollmentDate);
}

// Function to read a Date
void readDate(Date *date) {
	printf("Day: ");
	scanf("%hu%*c", &(date->day));

	printf("Month: ");
	fgets(date->month, sizeof(date->month), stdin);
	date->month[strcspn(date->month, "\n")] = '\0'; // Remove newline character

	printf("Year: ");
	scanf("%u%*c", &(date->year));
}

// Function to print a Date
void printDate(Date date) {
	printf("%hu %s %u\n", date.day, date.month, date.year);
}