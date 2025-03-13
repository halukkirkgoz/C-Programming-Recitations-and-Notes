#include <stdio.h>

// Function declaration
void printNibbles(short int);

int main(void) {
	short int num;

	// Prompt the user for input
	printf("Enter an integer: ");
	scanf("%hd%*c", &num);

	// Print the nibbles of the integer
	printNibbles(num);

	return 0;
}

// Function to extract and print the nibbles of a short int
void printNibbles(short int num) {
	// Use bitwise operations to extract the 4 nibbles
	for (int i = 3; i >= 0; i--) {  // Start from the leftmost nibble
		// Extract the nibble by shifting the bits to the right and masking with 0xF (decimal 15)
		int nibble = (num >> (i * 4)) & 0xF;
		printf("%d ", nibble);  // Print the nibble in decimal
	}
	printf("\n");
}
