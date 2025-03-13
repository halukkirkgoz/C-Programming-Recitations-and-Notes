#include <stdio.h>

int main(void) {
    int euros, cents, totalCents, remainingCents;
    
    // Declare variables for each denomination
    int notes_500, notes_200, notes_100, notes_50, notes_20, notes_10, notes_5;
    int coins_2, coins_1, coin_50, coin_20, coin_10, coin_5, coin_2, coin_1;

    // Ask user for the amount in euros and cents
    printf("Enter the amount in euros (e.g., 13578.78): ");
    scanf("%d.%d", &euros, &cents);

    // Convert the entire amount to cents
    totalCents = euros * 100 + cents;
    remainingCents = totalCents;

    // Calculate the number of 500 euro notes (50000 cents)
    notes_500 = remainingCents / 50000;
    remainingCents %= 50000;

    // Calculate the number of 200 euro notes (20000 cents)
    notes_200 = remainingCents / 20000;
    remainingCents %= 20000;

    // Calculate the number of 100 euro notes (10000 cents)
    notes_100 = remainingCents / 10000;
    remainingCents %= 10000;

    // Calculate the number of 50 euro notes (5000 cents)
    notes_50 = remainingCents / 5000;
    remainingCents %= 5000;

    // Calculate the number of 20 euro notes (2000 cents)
    notes_20 = remainingCents / 2000;
    remainingCents %= 2000;

    // Calculate the number of 10 euro notes (1000 cents)
    notes_10 = remainingCents / 1000;
    remainingCents %= 1000;

    // Calculate the number of 5 euro notes (500 cents)
    notes_5 = remainingCents / 500;
    remainingCents %= 500;

    // Calculate the number of 2 euro coins (200 cents)
    coins_2 = remainingCents / 200;
    remainingCents %= 200;

    // Calculate the number of 1 euro coins (100 cents)
    coins_1 = remainingCents / 100;
    remainingCents %= 100;

    // Calculate the number of 50 cent coins
    coin_50 = remainingCents / 50;
    remainingCents %= 50;

    // Calculate the number of 20 cent coins
    coin_20 = remainingCents / 20;
    remainingCents %= 20;

    // Calculate the number of 10 cent coins
    coin_10 = remainingCents / 10;
    remainingCents %= 10;

    // Calculate the number of 5 cent coins
    coin_5 = remainingCents / 5;
    remainingCents %= 5;

    // Calculate the number of 2 cent coins
    coin_2 = remainingCents / 2;
    remainingCents %= 2;

    // Calculate the number of 1 cent coins
    coin_1 = remainingCents / 1;

    // Output the result
    printf("\nBreakdown of the amount %d.%02d euros:\n", euros, cents);
    printf("500 euro notes: %d\n", notes_500);
    printf("200 euro notes: %d\n", notes_200);
    printf("100 euro notes: %d\n", notes_100);
    printf("50 euro notes: %d\n", notes_50);
    printf("20 euro notes: %d\n", notes_20);
    printf("10 euro notes: %d\n", notes_10);
    printf("5 euro notes: %d\n", notes_5);
    printf("2 euro coins: %d\n", coins_2);
    printf("1 euro coins: %d\n", coins_1);
    printf("50 cent coins: %d\n", coin_50);
    printf("20 cent coins: %d\n", coin_20);
    printf("10 cent coins: %d\n", coin_10);
    printf("5 cent coins: %d\n", coin_5);
    printf("2 cent coins: %d\n", coin_2);
    printf("1 cent coins: %d\n", coin_1);

    return 0;
}
