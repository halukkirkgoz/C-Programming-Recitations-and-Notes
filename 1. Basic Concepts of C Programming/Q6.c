#include <stdio.h>

int main(void) {
	int hh, mm;
	float ss;

	printf("Enter hours: ");
	scanf("%d%*c", &hh);

	printf("Enter minutes: ");
	scanf("%d%*c", &mm);

	printf("Enter seconds: ");
	scanf("%f%*c", &ss);

	printf("The entered time is: %d hours %d minutes and %.2f seconds\n", hh, mm, ss);

	return 0;
}
