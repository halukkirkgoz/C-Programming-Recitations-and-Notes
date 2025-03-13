#include <stdio.h>

#define MAX 100

// Function declarations
int ReadArray(int []);
void PrintArray(int [], int);
double CalcMean(int [], int);
int findMax(int [], int);

int main(void) {
	int row[MAX];  // Array to store up to 100 integers
	int size;

	// Call the function to read numbers
	size = ReadArray(row);

	// Call the function to print the entered numbers
	PrintArray(row, size);

    // Calculate the mean and print it
    if (size > 0) {
        double mean = CalcMean(row, size);
        printf("The mean value of the entered numbers is: %.2f\n", mean);
    } else {
        printf("No numbers were entered, so the mean cannot be calculated.\n");
    }

    // Find the maximum value and print it
    if (size > 0) {
        int max = findMax(row, size);
        printf("The maximum value entered is: %d\n", max);
    } else {
        printf("No numbers were entered, so the maximum cannot be determined.\n");
    }

	return 0;
}

// Function to read integers and store them in the array
int ReadArray(int arr[]) {
	int count = 0;
	int num;

	while(1) {
		printf("Enter an integer number: ");
		scanf("%d%*c", &num);

		// Stop if the user enters 999
		if (num == 999) {
			break;
		}

		// Store the number in the array if it's not 999
		if (count < MAX) {
			arr[count] = num;
			count++;
		} else {
			printf("Array is full, cannot store more numbers.\n");
			break;
		}
	}

	return count;
}

// Function to print the integers from the array
void PrintArray(int arr[], int size) {
	printf("\nThe numbers you entered are:\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Function to calculate the mean of the entered integers
double CalcMean(int row[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += row[i];
    }

    return (double)sum / size;  // Return the mean as a double
}

// Function to find the maximum value of the entered integers
int findMax(int row[], int size) {
    int max = row[0];

    for (int i = 1; i < size; i++) {
        if (row[i] > max) {
            max = row[i];
        }
    }

    return max;
}