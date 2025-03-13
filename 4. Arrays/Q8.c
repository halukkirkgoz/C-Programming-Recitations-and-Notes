#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROLL_TIMES 400

// Function declarations
void simulateRolls(int, int []);
void printOccurrences(int []);

int main(void) {
    // Declare an array to store the occurrences of sums from 2 to 12
    int occurrences[13] = {0};  // Index 0 and 1 will be unused as sums start from 2
    
    // Seed the random number generator
    srand(time(0));
    
    // Simulate ROLL_TIMES rolls of 2 dice
    simulateRolls(ROLL_TIMES, occurrences);
    
    // Print the occurrences of each sum
    printOccurrences(occurrences);
    
    return 0;
}

// Function to simulate rolling two dice and calculate occurrences of sums
void simulateRolls(int rolls, int occurrences[]) {
    for (int i = 0; i < rolls; i++) {
        // Simulate two dice rolls and sum the results
        int die1 = rand() % 6 + 1;  // Random number between 1 and 6 for the first die
        int die2 = rand() % 6 + 1;  // Random number between 1 and 6 for the second die
        
        int sum = die1 + die2;  // Sum of the dice
        
        // Increment the count for the corresponding sum
        occurrences[sum]++;
    }
}

// Function to print the occurrences of each sum
void printOccurrences(int occurrences[]) {
    printf("Occurrences of each sum from 2 to 12 after %d rolls:\n", ROLL_TIMES);
    for (int i = 2; i <= 12; i++) {
        printf("Sum %2d: %2d times\n", i, occurrences[i]);
    }
}