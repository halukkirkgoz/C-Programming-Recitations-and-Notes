#include <stdio.h>

// Function declarations
void hello(void);
void sum(int, int);
void goodbye(void);

int main(void) {
	int num1, num2;

	// Call hello to introduce the program
	hello();

	// Repeat 5 times to ask the user to solve 5 sums
	for (int i = 0; i < 5; i++) {
		// Ask the user for two numbers
		printf("Enter 2 numbers < 100: ");
		scanf("%d%d%*c", &num1, &num2);

		// Ask the user for the sum of these two numbers
		sum(num1, num2);
	}

	// Call goodbye to thank the user
	goodbye();

	return 0;
}

// Function to welcome the user and explain the program
void hello(void) {
	printf("Welcome, this program will ask you to solve 5 sums.\n\n");
}

// Function to simulate the sum request
void sum(int num1, int num2) {
    int user_sum;
    
	// Get the user's answer to the sum
	printf("What is the sum of %d and %d? ", num1, num2);
	scanf("%d%*c", &user_sum);

	// Check if the user's answer is correct or not
	if (user_sum == (num1 + num2)) {
		printf("According to you, the sum of %d and %d equals %d. That is correct.\n\n", num1, num2, user_sum);
	} else {
		printf("According to you, the sum of %d and %d equals %d. That is not correct.\n\n", num1, num2, user_sum);
	}
}

// Function to thank the user for their cooperation
void goodbye(void) {
	printf("Thanks for your cooperation.\n");
}
