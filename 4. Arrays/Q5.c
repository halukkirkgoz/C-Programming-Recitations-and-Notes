#include <stdio.h>

#define SIZE 5

// Function declarations
void ReadArray(int[], int);
void PrintArray(int[], int[], int);

int main(void) {
	int a[SIZE];
	int b[SIZE];

	ReadArray(a, SIZE);
	ReadArray(b, SIZE);

	PrintArray(a, b, SIZE);

	return 0;
}

void ReadArray(int x[], int length) {
	printf("Enter %d ordered integer numbers: ", length);

	for (int i = 0; i < length; i++) {
		scanf("%d%*c", &x[i]);
	}
}

void PrintArray(int a[], int b[], int length) {
	int i = 0, j = 0;

	printf("\nMerging the 2 lists results in:\n");

	// Merge the two arrays into one sorted array
	while (i < length && j < length) {
		if (a[i] < b[j]) {
			printf("%d ", a[i]);
			i++;
		} else {
			printf("%d ", b[j]);
			j++;
		}
	}

	// If elements are left in array a
	while (i < length) {
		printf("%d ", a[i]);
		i++;
	}

	// If elements are left in array b
	while (j < length) {
		printf("%d ", b[j]);
		j++;
	}

	printf("\n");
}