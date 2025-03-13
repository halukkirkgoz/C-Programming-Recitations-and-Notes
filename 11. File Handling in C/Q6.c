#include <stdio.h>
#include <string.h>

int main(void) {
	char filename[100], extension[10], fullFilename[110];
	char text[256];
	FILE *file;

	// Prompt user for the file name and extension
	printf("Enter file name: ");
	fgets(filename, sizeof(filename), stdin);
	filename[strcspn(filename, "\n")] = '\0';

	printf("Enter file extension: ");
	fgets(extension, sizeof(extension), stdin);
	extension[strcspn(extension, "\n")] = '\0';

	// Create the full file name by combining the name and extension
	snprintf(fullFilename, sizeof(fullFilename), "%s.%s", filename, extension);

	// Prompt the user for the text to write to the file
	printf("Enter your text: ");
	fgets(text, sizeof(text), stdin);  // Read the text from user input
	text[strcspn(text, "\n")] = '\0';

	// Open the file in write mode (creates the file or overwrites if it exists)
	file = fopen(fullFilename, "w");

	if (file == NULL) {
		fprintf(stderr, "The file \"%s\" cannot be opened: ", fullFilename);
		perror("");  // This will print the system's error message.
		return 1;
	} else {
		printf("\nFile has been opened with success!\n");
	}

	// Write the text to the file
	fputs(text, file);
	printf("Text has been written\n");

	// Close the file
	fclose(file);
	printf("File closed\n");

	return 0;
}
