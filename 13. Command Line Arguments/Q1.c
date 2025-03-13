#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

// Function declaration
void copy_file(const char *, const char *);

int main(int argc, char *argv[]) {
	// Check if the correct number of command line arguments is provided
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
		return EXIT_FAILURE;
	}

	// Call the copy_file function with the provided arguments
	copy_file(argv[1], argv[2]);

	printf("File copied from %s to %s successfully.\n", argv[1], argv[2]);
	return EXIT_SUCCESS;
}

void copy_file(const char *source, const char *destination) {
	FILE *sourceFile, *destFile;   // Declare file pointers
	char line[MAX_LINE_LENGTH];    // Buffer to store each line from the file

	// Open the source file in read mode
	sourceFile = fopen(source, "r");
	if (sourceFile == NULL) {
		fprintf(stderr, "The file \"%s\" cannot be opened: ", source);
		perror("");  // This will print the system's error message.
		exit(EXIT_FAILURE);
	}

	// Open the destination file in write mode (creates new file or overwrites existing)
	destFile = fopen(destination, "w");
	if (destFile == NULL) {
		fprintf(stderr, "The file \"%s\" cannot be opened: ", destination);
		perror("");  // This will print the system's error message.
		fclose(sourceFile); // Close the source file before exiting
		exit(EXIT_FAILURE);
	}

	// Read the source file line by line and write to the destination file
	while (fgets(line, sizeof(line), sourceFile) != NULL) {
		// Write each line to the destination file
		fputs(line, destFile);
	}

	// Close both files
	fclose(sourceFile);
	fclose(destFile);
}
