#include <stdio.h>
#include <string.h>

#define MAX_PERSONS 3
#define MAX_NAME_LENGTH 50
#define MAX_TOWN_LENGTH 50

// Define the structure "Person"
typedef struct {
	char name[MAX_NAME_LENGTH];
	char hometown[MAX_TOWN_LENGTH];
} Person;

// Function declarations
void readPerson(Person *);
int searchTown(Person [], int, Person *);

int main(void) {
	Person persons[MAX_PERSONS]; // Array to store persons

	// Read details of MAX_PERSONS persons
	printf("Enter the details of %d persons:\n", MAX_PERSONS);
	for (int i = 0; i < MAX_PERSONS; i++) {
		readPerson(&persons[i]);
	}

	// Ask for the name to search for
	Person searchPerson;
	printf("\nEnter the name of the person you want to search for: ");
	fgets(searchPerson.name, sizeof(searchPerson.name), stdin);
	searchPerson.name[strcspn(searchPerson.name, "\n")] = '\0'; // Remove newline character

	// Search for the town of the specified person
	if (searchTown(persons, MAX_PERSONS, &searchPerson)) {
		printf("This person lives in %s.\n", searchPerson.hometown);
	} else {
		printf("Person not found.\n");
	}

	return 0;
}

// Function to read a Person's details
void readPerson(Person *person) {
	printf("Enter name: ");
	fgets(person->name, sizeof(person->name), stdin);
	person->name[strcspn(person->name, "\n")] = '\0'; // Remove newline character

	printf("Enter town or city: ");
	fgets(person->hometown, sizeof(person->hometown), stdin);
	person->hometown[strcspn(person->hometown, "\n")] = '\0'; // Remove newline character
}

// Function to search for the town of a person by name
int searchTown(Person persons[], int count, Person *person) {
	for (int i = 0; i < count; i++) {
		if (strcmp(persons[i].name, person->name) == 0) {
			strcpy(person->hometown, persons[i].hometown); // Fill hometown if found
			return 1; // Person found
		}
	}
	return 0; // Person not found
}
