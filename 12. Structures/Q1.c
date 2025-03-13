#include <stdio.h>
#include <string.h>

#define N 5  // Number of persons

// Define the structure "Person"
typedef struct {
	char firstname[50];
	char lastname[50];
} Person;

// Function declarations
void readPerson(Person *);
void printPerson(Person);

int main(void)
{
	Person persons[N]; // Declare an array of N persons

	printf("Enter %d names (first name and surname):\n", N);

	// Read the data of N persons
	for(int i=0; i < N; i++) {
		printf("\nEnter details for person %d:\n", i + 1);
		readPerson(&persons[i]);
	}

	// Print the data of N persons
	printf("\nThe %d entered names are:\n", N);
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
}

// Function to print the data of 1 Person
void printPerson(Person person) {
	printf("Name: %s %s\n", person.firstname, person.lastname);
}