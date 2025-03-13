#include <stdio.h>
#include <errno.h>

#define FILENAME "text.txt"

int main(void) {
	FILE *file;          // Declare a file pointer
	char line[256];      // Buffer to store each line from the file
	int lineNumber = 0;  // Initialize line number

	// Open the file in read mode
	file = fopen(FILENAME, "r");

	// Check if the file opened successfully
	if (file == NULL) {
		fprintf(stderr, "The file \"%s\" cannot be opened: ", FILENAME);
		perror("");  // This will print the system's error message.
		return 1;
	}

	// Read the file line by line
	while (fgets(line, sizeof(line), file) != NULL) {
		// Print each line to the screen
		printf("%d  %s", ++lineNumber, line);
	}

	// Close the file after reading
	fclose(file);

	return 0;
}