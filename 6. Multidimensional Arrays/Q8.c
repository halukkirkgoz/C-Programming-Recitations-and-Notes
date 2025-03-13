#include <stdio.h>

// Constants for the maximum number of parts and tests
#define MAX_PARTS 20
#define MAX_TESTS 10

// Function declarations
int ReadNumber(const char [], int, int);
void ReadTestResults(int [MAX_PARTS][MAX_TESTS], int, int);
void PrintResultsPerPart(int [MAX_PARTS][MAX_TESTS], int, int);
void PrintResultsPerTest(int [MAX_PARTS][MAX_TESTS], int, int);

int main(void) {
	int N, M;

	// Read the number of parts N and tests M
	N = ReadNumber("How many parts did you test?", 1, MAX_PARTS);
	M = ReadNumber("How many tests did you run?", 1, MAX_TESTS);

	// Declare a matrix to hold the test results
	int results[MAX_PARTS][MAX_TESTS] = {0};

	// Read the test results for all parts
	printf("\nEnter the test results (end with 0 0 0):\n");
	ReadTestResults(results, N, M);

	// Print the results per part
	PrintResultsPerPart(results, N, M);

	// Print the results per test
	PrintResultsPerTest(results, N, M);

	return 0;
}

// Function to read a valid number within a given range
int ReadNumber(const char prompt[], int min, int max) {
	int value;
	while (1) {
		printf("%s ", prompt);
		if (scanf("%d%*c", &value) != 1 || value < min || value > max) {
			printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
		} else {
			break;
		}
	}
	return value;
}

// Function to read the test results for all parts
void ReadTestResults(int results[MAX_PARTS][MAX_TESTS], int N, int M) {
	int partNumber, testNumber, result;

	// Read test results until 0 0 0 is entered
	while (1) {
		scanf("%d%d%d%*c", &partNumber, &testNumber, &result);

		if (partNumber == 0 && testNumber == 0 && result == 0) {
			break;
		}

		// Ensure part and test numbers are within valid ranges
		if (partNumber > 0 && partNumber <= N && testNumber > 0 && testNumber <= M) {
			results[partNumber - 1][testNumber - 1] = result;
		}
	}
}

// Function to print results per part
void PrintResultsPerPart(int results[MAX_PARTS][MAX_TESTS], int N, int M) {
	printf("\nResults per part:\n");
	printf("part number tests  assessment\n");
	printf("            1 2 3           \n");
	printf("----------------------------\n");

	for (int i = 0; i < N; i++) {
		int smallErrors = 0, fatalErrors = 0;

		// Count the errors for the part
		for (int j = 0; j < M; j++) {
			if (results[i][j] == 1) {
				smallErrors++;
			} else if (results[i][j] == 3) {
				fatalErrors++;
			}
		}

		// Print the result for the part
		printf("%-11d ", i + 1);
		for (int j = 0; j < M; j++) {
			printf("%d ", results[i][j]);
		}

		// Print the assessment
		if (fatalErrors > 0 || smallErrors >= 3) {
			printf(" rejected\n");
		} else {
			printf(" accepted\n");
		}
	}
}

// Function to print results per test
void PrintResultsPerTest(int results[MAX_PARTS][MAX_TESTS], int N, int M) {
	printf("\nResults per test:\n");
	printf("test        failures\n");
	printf("        none small fatal\n");
	printf("-------------------------\n");

	for (int j = 0; j < M; j++) {
		int none = 0, small = 0, fatal = 0;

		// Count the number of failures, small errors, and fatal errors for each test
		for (int i = 0; i < N; i++) {
			if (results[i][j] == 0) {
				none++;
			} else if (results[i][j] == 1) {
				small++;
			} else if (results[i][j] == 3) {
				fatal++;
			}
		}

		// Print the results for the test
		printf("%-8d%-5d%-6d%-6d\n", j + 1, none, small, fatal);
	}
}
