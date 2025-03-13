#include <stdio.h>

// Function declaration
short int rotate_left(short int);

int main(void) {
	short int values[] = {20480, 23043, -24523};
	int size = sizeof(values) / sizeof(values[0]);

	for (int i = 0; i < size; i++) {
		short int result = rotate_left(values[i]);
		printf("Input: %6hd, Output: %6hd\n", values[i], result);
	}

	return 0;
}

short int rotate_left(short int value) {
	// Treat the value as unsigned during the rotation to avoid sign extension
	unsigned short int u_value = (unsigned short int) value;

	// Perform the left rotation of 4 bits
	u_value = (u_value << 4) | (u_value >> (sizeof(short int) * 8 - 4));

	// Cast back to signed short int before returning
	return (short int) u_value;
}
