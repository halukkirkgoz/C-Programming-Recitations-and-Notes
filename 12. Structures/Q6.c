#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define FILENAME "people.dat"

// Define the structure "Person"
typedef struct {
	char name[MAX_NAME_LENGTH];
	int age;
	float salary;
} Person;

// Function declarations
void writePeopleToFile(int);
void searchPersonInFile(const char *);

int main(void) {
	int numberOfPeople;

	// Ask the user how many people they want to enter
	printf("How many people do you want to enter? ");
	scanf("%d%*c", &numberOfPeople);

	// Write people data to the file
	writePeopleToFile(numberOfPeople);

	// Ask for a name to search
	char searchName[MAX_NAME_LENGTH];
	printf("\nWhat's the name of the person you want to search for: ");
	fgets(searchName, sizeof(searchName), stdin);
	searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline character

	// Search for the person's age and salary
	searchPersonInFile(searchName);

	return EXIT_SUCCESS;
}

// Function to write people data to a file
void writePeopleToFile(int count) {
	FILE *file;  // Declare a file pointer

	// Open file in binary write mode
	file = fopen(FILENAME, "wb");
	if (file == NULL) {
		fprintf(stderr, "The file \"%s\" cannot be opened: ", FILENAME);
		perror("");  // This will print the system's error message.
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < count; i++) {
		Person person;

		printf("Enter name: ");
		fgets(person.name, sizeof(person.name), stdin);
		person.name[strcspn(person.name, "\n")] = '\0'; // Remove newline character

		printf("Enter age: ");
		scanf("%d%*c", &person.age);
		printf("Enter salary: ");
		scanf("%f%*c", &person.salary);

		// Write the structure to the file
		fwrite(&person, sizeof(Person), 1, file);
	}

	fclose(file); // Close the file
}

// Function to search for a person's age and salary by name
void searchPersonInFile(const char *name) {
	FILE *file;  // Declare a file pointer

	// Open file in binary read mode
	file = fopen(FILENAME, "rb");
	if (file == NULL) {
		fprintf(stderr, "The file \"%s\" cannot be opened: ", FILENAME);
		perror("");  // This will print the system's error message.
		exit(EXIT_FAILURE);
	}

	Person person;
	int found = 0;
	while (fread(&person, sizeof(Person), 1, file)) {
		if (strcmp(person.name, name) == 0) {
			printf("Name: %s\nAge: %d\nSalary: %.2f\n\n", person.name, person.age, person.salary);
			found = 1;
			break; // Stop searching after finding the person
		}
	}

	if (!found) {
		printf("Person not found.\n");
	}

	fclose(file); // Close the file
}