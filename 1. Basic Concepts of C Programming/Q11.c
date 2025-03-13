#include <stdio.h>

int main(void) {
    int amount, remaining_amount;
    
    // Declare variables for each denomination
    int notes_500, notes_200, notes_100, notes_50, notes_20, notes_10, notes_5;
    int coins_2, coins_1;

    // Ask user for the amount in euros
    printf("Enter the amount of money in euros: ");
    scanf("%d%*c", &amount);

    // Copy the amount to remainingAmount for calculation
    remaining_amount = amount;

    // Calculate the number of 500 euro notes
    notes_500 = remaining_amount / 500;
    remaining_amount %= 500;

    // Calculate the number of 200 euro notes
    notes_200 = remaining_amount / 200;
    remaining_amount %= 200;

    // Calculate the number of 100 euro notes
    notes_100 = remaining_amount / 100;
    remaining_amount %= 100;

    // Calculate the number of 50 euro notes
    notes_50 = remaining_amount / 50;
    remaining_amount %= 50;

    // Calculate the number of 20 euro notes
    notes_20 = remaining_amount / 20;
    remaining_amount %= 20;

    // Calculate the number of 10 euro notes
    notes_10 = remaining_amount / 10;
    remaining_amount %= 10;

    // Calculate the number of 5 euro notes
    notes_5 = remaining_amount / 5;
    remaining_amount %= 5;

    // Calculate the number of 2 euro coins
    coins_2 = remaining_amount / 2;
    remaining_amount %= 2;

    // Calculate the number of 1 euro coins
    coins_1 = remaining_amount / 1;

    // Output the result
    printf("\nBreakdown of the amount %d euros:\n", amount);
    printf("500 euro notes: %d\n", notes_500);
    printf("200 euro notes: %d\n", notes_200);
    printf("100 euro notes: %d\n", notes_100);
    printf("50 euro notes: %d\n", notes_50);
    printf("20 euro notes: %d\n", notes_20);
    printf("10 euro notes: %d\n", notes_10);
    printf("5 euro notes: %d\n", notes_5);
    printf("2 euro coins: %d\n", coins_2);
    printf("1 euro coins: %d\n", coins_1);

    return 0;
}
