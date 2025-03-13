#include <stdio.h>
#include <limits.h>

int main(void) {
	short int number1;
	printf("Enter an integer number: ");
	scanf("%hd%*c", &number1);
	printf("The entered number is: %hd\n", number1);

	printf("\nShort int occupies: %zu Bytes (%hd to %hd)", sizeof(short int), SHRT_MIN, SHRT_MAX);
	printf("\nInt occupies: %zu Bytes (%d to %d)", sizeof(int), INT_MIN, INT_MAX);
	printf("\nLong int occupies: %zu Bytes (%ld to %ld)", sizeof(long int), LONG_MIN, LONG_MAX);

	return 0;
}

// %*c:  This tells scanf to read and discard one character, doesn't store it in the variable.

/*
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    // Integer limits and sizes
    printf("Integer type limits and sizes:\n");
    printf("==============================\n");
    printf("char:               %zu bytes (from %d to %d)\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("short:              %zu bytes (from %d to %d)\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("int:                %zu bytes (from %d to %d)\n", sizeof(int), INT_MIN, INT_MAX);
    printf("long:               %zu bytes (from %ld to %ld)\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("long long:          %zu bytes (from %lld to %lld)\n", sizeof(long long), LLONG_MIN, LLONG_MAX);

    // Unsigned integer limits
    printf("unsigned char:      %zu bytes (from 0 to %d)\n", sizeof(unsigned char), UCHAR_MAX);
    printf("unsigned short:     %zu bytes (from 0 to %d)\n", sizeof(unsigned short), USHRT_MAX);
    printf("unsigned int:       %zu bytes (from 0 to %u)\n", sizeof(unsigned int), UINT_MAX);
    printf("unsigned long:      %zu bytes (from 0 to %lu)\n", sizeof(unsigned long), ULONG_MAX);
    printf("unsigned long long: %zu bytes (from 0 to %llu)\n", sizeof(unsigned long long), ULLONG_MAX);

    // Floating-point limits and sizes
    printf("\nFloating point type limits and sizes:\n");
    printf("=====================================\n");
    printf("float:        %zu bytes (from %e to %e)\n", sizeof(float), FLT_MIN, FLT_MAX);
    printf("double:       %zu bytes (from %e to %e)\n", sizeof(double), DBL_MIN, DBL_MAX);
    printf("long double:  %zu bytes (from %Le to %Le)\n", sizeof(long double), LDBL_MIN, LDBL_MAX);

    return 0;
}
*/