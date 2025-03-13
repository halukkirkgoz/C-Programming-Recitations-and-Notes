#include <stdio.h>
#include <errno.h>

#define FILE_1 "numbers1.txt"
#define FILE_2 "numbers2.txt"
#define FILE_3 "merged_numbers.txt"

int main(void) {
	FILE *file1, *file2, *file3;   // Declare file pointers
	int num1, num2;
	int file1_end = 0, file2_end = 0;

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

	// Open the output file in write mode
	file3 = fopen(FILE_3, "w");
	if (file3 == NULL) {
		fprintf(stderr, "The file \"%s\" cannot be opened: ", FILE_3);
		perror("");  // This will print the system's error message.
		fclose(file1); // Close the first file before exiting
		fclose(file2); // Close the second file before exiting
		return 1;
	}

	// Read the first number from both files (if available)
	file1_end = fscanf(file1, "%d", &num1);
	file2_end = fscanf(file2, "%d", &num2);

	// Continue until both files are fully read
	while (file1_end != EOF || file2_end != EOF) {
		if (file1_end == EOF) {
			// If file1 is done, write from file2 to the output file
			fprintf(file3, "%d ", num2);
			file2_end = fscanf(file2, "%d", &num2); // Get next number from file2
		} else if (file2_end == EOF) {
			// If file2 is done, write from file1 to the output file
			fprintf(file3, "%d ", num1);
			file1_end = fscanf(file1, "%d", &num1); // Get next number from file1
		} else {
			// Compare the two numbers and write the smaller one to the output file
			if (num1 <= num2) {
				fprintf(file3, "%d ", num1);
				file1_end = fscanf(file1, "%d", &num1); // Get next number from file1
			} else {
				fprintf(file3, "%d ", num2);
				file2_end = fscanf(file2, "%d", &num2); // Get next number from file2
			}
		}
	}

	// Close all the files
	fclose(file1);
	fclose(file2);
	fclose(file3);

	return 0;
}