#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_DIFF_LINES 10

// Function declaration
void compare_files(const char *, const char *);

int main(int argc, char *argv[]) {
	// Check if the correct number of command line arguments is provided
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
		return EXIT_FAILURE;
	}

	// Call the compare_files function with the provided arguments
	compare_files(argv[1], argv[2]);

	return EXIT_SUCCESS;
}

// Function to compare two text files
void compare_files(const char *file1, const char *file2) {

	FILE *f1 = fopen(file1, "r");
	if (f1 == NULL) {
		fprintf(stderr, "The file \"%s\" cannot be opened: ", file1);
		perror("");  // This will print the system's error message.
		exit(EXIT_FAILURE);
	}

	FILE *f2 = fopen(file2, "r");
	if (f2 == NULL) {
		fprintf(stderr, "The file \"%s\" cannot be opened: ", file2);
		perror("");  // This will print the system's error message.
		fclose(f1);
		exit(EXIT_FAILURE);
	}

	char line1[MAX_LINE_LENGTH];
	char line2[MAX_LINE_LENGTH];
	int line_number = 1;
	int diff_count = 0;

	// Read lines from both files and compare them
	while (fgets(line1, sizeof(line1), f1) != NULL && fgets(line2, sizeof(line2), f2) != NULL) {
		if (strcmp(line1, line2) != 0) {
			// Print the differing line and its line number
			printf("Difference at line %d:\n", line_number);
			printf("File 1: %s", line1);
			printf("File 2: %s\n", line2);
			diff_count++;
		}
		line_number++;

		// Stop if more than 10 differing lines are found
		if (diff_count >= MAX_DIFF_LINES) {
			break;
		}
	}

	// Check for any remaining lines in either file
	while (fgets(line1, sizeof(line1), f1) != NULL) {
		printf("Difference at line %d:\n", line_number);
		printf("File 1: %s", line1);
		line_number++;
		diff_count++;
		if (diff_count >= MAX_DIFF_LINES) {
			break;
		}
	}

	while (fgets(line2, sizeof(line2), f2) != NULL) {
		printf("Difference at line %d:\n", line_number);
		printf("File 2: %s", line2);
		line_number++;
		diff_count++;
		if (diff_count >= MAX_DIFF_LINES) {
			break;
		}
	}

	// Check if any differences were found
	if (diff_count == 0) {
		printf("The files are identical.\n");
	}

	// Close the files
	fclose(f1);
	fclose(f2);
}