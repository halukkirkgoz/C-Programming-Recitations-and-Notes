#include <stdio.h>

// Function declaration
void printBinary(unsigned char);

int main(void) {
	unsigned char registerValue;

	// Ask the user to input a number that fits in 1 byte (0 to 255)
	printf("Enter a byte (0-255): ");
	scanf("%hhu", &registerValue);  // %hhu for unsigned char input

	// Extract the "Synchronization Jump Width Bits" (bits 6 and 7)
	unsigned char sjw = (registerValue >> 6) & 0x03;  // Shift right by 6 and mask with 0x03 (11 in binary)

	// Extract the "Baud Rate Prescaler Bits" (bits 0 to 5)
	unsigned char brp = registerValue & 0x3F;  // Mask with 0x3F (111111 in binary) to get the lower 6 bits

	// Print the "Synchronization Jump Width Bits"
	printf("\nSynchronization Jump Width Bits (SJW):\n");
	printf("Hex: 0x%X\n", sjw);  // Print SJW in hexadecimal
	printf("Binary: ");
	printBinary(sjw);  // Print SJW in binary
	printf("\n");

	// Print the "Baud Rate Prescaler Bits"
	printf("\nBaud Rate Prescaler Bits (BRP):\n");
	printf("Hex: 0x%X\n", brp);  // Print BRP in hexadecimal
	printf("Binary: ");
	printBinary(brp);  // Print BRP in binary
	printf("\n");

	return 0;
}

void printBinary(unsigned char value) {
	for (int i = 7; i >= 0; i--) {
		printf("%d", (value >> i) & 0x1);  // Extract each bit and print
	}
}
