#include <stdio.h>
#include <errno.h>

#define SOURCE "text.txt"
#define DESTINATION "copy.txt"

int main(void) {
	FILE *sourceFile, *destFile;   // Declare file pointers
	char line[256];                // Buffer to store each line from the file

	// Open the source file in read mode
	sourceFile = fopen(SOURCE, "r");
	if (sourceFile == NULL) {
		fprintf(stderr, "The file \"%s\" cannot be opened: ", SOURCE);
		perror("");  // This will print the system's error message.
		return 1;
	}

	// Open the destination file in write mode (creates new file or overwrites existing)
	destFile = fopen(DESTINATION, "w");
	if (destFile == NULL) {
		fprintf(stderr, "The file \"%s\" cannot be opened: ", DESTINATION);
		perror("");  // This will print the system's error message.
		fclose(sourceFile); // Close the source file before exiting
		return 1;
	}

	// Read the source file line by line and write to the destination file
	while (fgets(line, sizeof(line), sourceFile) != NULL) {
		// Write each line to the destination file
		fputs(line, destFile);
	}

	// Close both files
	fclose(sourceFile);
	fclose(destFile);

    printf("File copied successfully!\n");

	return 0;
}