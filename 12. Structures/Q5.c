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
void readPeopleFromFile(void);

int main(void) {
	int numberOfPeople;

	// Ask the user how many people they want to enter
	printf("How many people do you want to enter? ");
	scanf("%d%*c", &numberOfPeople);

	// Write people data to the file
	writePeopleToFile(numberOfPeople);

	// Read and display the data from the file
	readPeopleFromFile();

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

// Function to read people data from a file
void readPeopleFromFile(void) {
	FILE *file;  // Declare a file pointer

	// Open file in binary read mode
	file = fopen(FILENAME, "rb");
	if (file == NULL) {
		fprintf(stderr, "The file \"%s\" cannot be opened: ", FILENAME);
		perror("");  // This will print the system's error message.
		exit(EXIT_FAILURE);
	}

	Person person;
	printf("\nData from the file:\n");
	while (fread(&person, sizeof(Person), 1, file)) {
		printf("Name: %s\nAge: %d\nSalary: %.2f\n\n", person.name, person.age, person.salary);
	}

	fclose(file); // Close the file
}
