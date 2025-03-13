#include <stdio.h>
#include <errno.h>

#define FILE_1 "file1.txt"
#define FILE_2 "file2.txt"

// Function declaration
void printFileContent(FILE *);

int main(void) {
	FILE *file1, *file2;   // Declare file pointers

	// Open the first file in read mode
	file1 = fopen(FILE_1, "r");
	if (file1 == NULL) {
		fprintf(stderr, "The file \"%s\" cannot be opened: ", FILE_1);
		perror("");  // This will print the system's error message.
		return 1;
	}

	// Open the second file in read mode
	file2 = fopen(FILE_2, "r");
	if (file2 == NULL) {
		fprintf(stderr, "The file \"%s\" cannot be opened: ", FILE_2);
		perror("");  // This will print the system's error message.
		fclose(file1); // Close the first file before exiting
		return 1;
	}

	// Print the content of the first file
	printf("Content of file1.txt:\n");
	printFileContent(file1);

	// Print the content of the second file
	printf("\n\nContent of file2.txt:\n");
	printFileContent(file2);

	// Close both files
	fclose(file1);
	fclose(file2);

	return 0;
}

void printFileContent(FILE *file) {
	char line[256];     // Buffer to store each line from the file

	// Read and print each line from the file
	while (fgets(line, sizeof(line), file) != NULL) {
		// Write each line to the screen
		printf("%s", line);
	}
}