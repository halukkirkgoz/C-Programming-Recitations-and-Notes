#include <stdio.h>

// Function declaration
short int pseudoRandomNumber(void);

int main(void) {
    // Call the pseudo-random number generator 10 times and print the results
    for (int i = 0; i < 10; i++) {
        printf("Random number %d: %hd\n", i + 1, pseudoRandomNumber());
    }
    return 0;
}

// Function to generate a pseudo-random number using the provided algorithm
short int pseudoRandomNumber(void) {
    // Static seed initialized to 3254 (can be any non-zero value)
    static short int seed = 3254;

    // XOR the 14th and 13th bits
    short int xorResult = ((seed >> 14) & 0x1) ^ ((seed >> 13) & 0x1);

    // Shift the seed left by 1 bit and insert the result of XOR at the rightmost bit
    seed = (seed << 1) | xorResult;

    // Ensure that the leftmost bit (bit 15) remains 0, so we mask with 0x7FFF (binary: 0111 1111 1111 1111)
    seed &= 0x7FFF;

    // Return the pseudo-random number
    return seed;
}