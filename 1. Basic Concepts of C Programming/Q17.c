#include <stdio.h>

int main(void) {
    int year;
    int a, b, c, d, e, f, g, h, i, k, l, m, day, month;
    
    // Ask the user for a year
    printf("Enter a year: ");
    scanf("%d%*c", &year);
    
    // Calculate the various parts of the algorithm
    a = year % 19;
    b = year / 100;
    c = year % 100;
    d = b / 4;
    e = b % 4;
    f = (b + 8) / 25;
    g = (b - f + 1) / 3;
    h = (19 * a + b - d - g + 15) % 30;
    i = c / 4;
    k = c % 4;
    l = (32 + 2 * e + 2 * i - h - k) % 7;
    m = (a + 11 * h + 22 * l) / 451;

    // Calculate the day and month of Easter
    month = (h + l - 7 * m + 114) / 31;
    day = 1 + (h + l - 7 * m + 114) % 31;

    // Print the calculated date of Easter
    printf("\nEaster in %d is on %d/%d.\n", year, day, month);
    
    return 0;
}
