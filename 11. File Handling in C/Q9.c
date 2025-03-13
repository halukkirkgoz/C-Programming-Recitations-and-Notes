#include <stdio.h>
#include <string.h>
#include <errno.h>

#define FILENAME "text.txt"

int main(void) {
	FILE *file;
	char pattern[100];
	char line[256];
	int lineNumber = 1;

	// Prompt user for the pattern to search
	printf("Enter the pattern to search for: ");
	fgets(pattern, sizeof(pattern), stdin);
	pattern[strcspn(pattern, "\n")] = '\0';

	// Open the file in read mode
	file = fopen(FILENAME, "r");
	if (file == NULL) {
		fprintf(stderr, "The file \"%s\" cannot be opened: ", FILENAME);
		perror("");  // This will print the system's error message.
		return 1;
	}

	// Read each line and search for the pattern
	while (fgets(line, sizeof(line), file) != NULL) {
		// Check if the pattern is present in the current line
		if (strstr(line, pattern) != NULL) {
			// Print the line number and the line containing the pattern
			printf("Line %d: %s", lineNumber, line);
		}
		lineNumber++;
	}

	// Close the file
	fclose(file);

	return 0;
}