#include <stdio.h>

#define SIZE 20

// Function declarations
void readNumbers(int [], int);
int removeDuplicates(int [], int);
void printArray(int [], int);

int main(void) {
    int arr[SIZE];
    int size = SIZE;

    // Read numbers into the array
    readNumbers(arr, size);

    // Remove duplicates from the array and get the new size
    size = removeDuplicates(arr, size);

    // Print the cleaned-up array
    printf("Following numbers are stored in the cleaned-up array:\n");
    printArray(arr, size);

    return 0;
}

// Function to read numbers into the array
void readNumbers(int arr[], int size) {
    printf("Enter a list of %d numbers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d%*c", &arr[i]);
    }
}

// Function to remove duplicates from the array
int removeDuplicates(int arr[], int size) {
    int newSize = size;

    // Iterate through each element of the array
    for (int i = 0; i < newSize; i++) {
        for (int j = i + 1; j < newSize; j++) {
            // If a duplicate is found
            if (arr[i] == arr[j]) {
                // Shift elements to the left to remove the duplicate
                for (int k = j; k < newSize - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                newSize--;  // Reduce the array size
                j--;  // Adjust the index after shifting
            }
        }
    }

    return newSize;  // Return the new size of the array
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
