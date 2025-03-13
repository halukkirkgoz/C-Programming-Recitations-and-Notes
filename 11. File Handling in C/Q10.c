#include <stdio.h>
#include <string.h>
#include <errno.h>

#define FILENAME "people_data.txt"
#define MAX_NAME_LENGTH 100

int main(void) {
	FILE *file;
	int numPeople;
	char name[MAX_NAME_LENGTH];
	int age;
    char searchName[MAX_NAME_LENGTH];

	// Asking for the number of people
	printf("For how many people do you want to enter data: ");
	scanf("%d%*c", &numPeople);

	// Open the file to write the data
	file = fopen(FILENAME, "w");
	if (file == NULL) {
		fprintf(stderr, "The file \"%s\" cannot be opened: ", FILENAME);
		perror("");  // This will print the system's error message.
		return 1;
	}

	// Collecting data from the user and writing to the file
	for (int i = 0; i < numPeople; i++) {
		printf("Enter name of person and age: ");
		scanf("%s%d%*c", name, &age);  // Names do not contain spaces

		// Write the data to the file
		fprintf(file, "%s %d\n", name, age);
	}

	// Close the file after writing
	fclose(file);

	// Ask the user to search for a name in the file
	printf("\nEnter a name to search: ");
	scanf("%s%*c", searchName);

	// Open the file to search for the name
	file = fopen(FILENAME, "r");
	if (file == NULL) {
		fprintf(stderr, "The file \"%s\" cannot be opened: ", FILENAME);
		perror("");  // This will print the system's error message.
		return 1;
	}

	// Search for the name and print the corresponding age
	int found = 0;
	while (fscanf(file, "%s %d", name, &age) != EOF) {
		if (strcmp(name, searchName) == 0) {
			printf("The age of %s is: %d\n", name, age);
			found = 1;
			break;
		}
	}

	if (!found) {
		printf("Name '%s' not found in the file.\n", searchName);
	}

	// Close the file after searching
	fclose(file);

	return 0;
}