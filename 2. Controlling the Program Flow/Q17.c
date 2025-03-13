#include <stdio.h>

int main(void) {
    // Iterate from -3 to 25, incrementing by 2
    for (int i = -3; i <= 25; i += 2) {
        printf("%d", i); // Print the current number
        if (i != 25) { // Check if it's not the last number
            printf(", "); // Print a comma and space
        }
    }

    return 0;
}