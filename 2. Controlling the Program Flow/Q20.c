#include <stdio.h>

int main(void) {
	// Loop to print 22 lines
	for (int i = 0; i < 22; i++) {
		// Loop to print 40 black rectangles in each line
		for (int j = 0; j < 40; j++) {
			printf("%c", 219);  // ASCII code for a black rectangle
		}
		// After printing 40 rectangles, move to the next line
		printf("\n");
	}

	return 0;
}
