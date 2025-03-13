#include <stdio.h>

// Function declaration
void printBinary(short int);

int main(void) {
	short int num1 = 23043;   // Example input: 23043
	short int num2 = -24523;  // Example input: -24523

	printf("Binary representation of %hd: ", num1);
	printBinary(num1);

	printf("Binary representation of %hd: ", num2);
	printBinary(num2);

	return 0;
}

void printBinary(short int num) {
	unsigned short int mask = 0x8000;  // A mask to isolate each bit (starting from the most significant bit)

	// Iterate over all 16 bits (since short int is typically 16 bits)
	for (int i = 0; i < 16; i++) {
		// Print '1' or '0' based on whether the bit is set
		printf("%d", (num & mask) ? 1 : 0);

		// Shift the mask to the right to check the next bit
		num <<= 1;

		// Print a space every 4 bits for better readability
		if ((i + 1) % 4 == 0 && i != 15) {
			printf(" ");
		}
	}
	printf("\n");
}