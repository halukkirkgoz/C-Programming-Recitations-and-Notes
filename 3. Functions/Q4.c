#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int secretNumber, userGuess, guessCount = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number between 1 and 100
    secretNumber = rand() % 100 + 1;

    printf("Welcome to the guessing game!\n");
    printf("I have selected a number between 1 and 100. Try to guess it!\n\n");

    // Keep asking the user for guesses until they get it right
    do {
        // Ask the user for their guess
        printf("Enter your guess: ");
        scanf("%d%*c", &userGuess);

        guessCount++;

        // Give feedback on the guess
        if (userGuess > secretNumber) {
            printf("Too high! Try again.\n");
        } else if (userGuess < secretNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("\nCongratulations! You've found the number.\n");
            printf("It took you %d guesses to find the secret number.\n", guessCount);
        }
    } while (userGuess != secretNumber);

    return 0;
}