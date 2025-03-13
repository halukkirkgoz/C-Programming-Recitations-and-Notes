#include <stdio.h>
#include <errno.h>

#define FILENAME "text.txt"
#define LINES_PER_CHUNK 20

int main(void) {
	FILE *file;            // Declare a file pointer
	char line[256];        // Buffer to store each line from the file
	int linesPrinted = 0;

	// Open the file in read mode
	file = fopen(FILENAME, "r");

	// Check if the file opened successfully
	if (file == NULL) {
		fprintf(stderr, "The file \"%s\" cannot be opened: ", FILENAME);
		perror("");  // This will print the system's error message.
		return 1;
	}

	// Read the file and print it in chunks of LINES_PER_CHUNK lines
	while (fgets(line, sizeof(line), file) != NULL) {
		// Print the current line
		printf("%s", line);
		linesPrinted++;

		// When LINES_PER_CHUNK lines have been printed, ask the user to press Enter to continue
		if (linesPrinted == LINES_PER_CHUNK) {
			printf("\nPress Enter to continue to the next %d lines...\n", LINES_PER_CHUNK);
			getchar();  // Wait for the user to hit Enter

			linesPrinted = 0;  // Reset the line counter for the next chunk
		}
	}

	// Close the file after reading
	fclose(file);

	return 0;
}