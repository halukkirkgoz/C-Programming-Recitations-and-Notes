#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMER_NUMBER_LENGTH 10
#define MAX_NAME_LENGTH 100
#define MAX_ADDRESS_LENGTH 100

// Define struct for customer names
struct CustomerName {
	char customerNumber[MAX_CUSTOMER_NUMBER_LENGTH];
	char name[MAX_NAME_LENGTH];
};

// Define struct for customer addresses
struct CustomerAddress {
	char customerNumber[MAX_CUSTOMER_NUMBER_LENGTH];
	char address[MAX_ADDRESS_LENGTH];
};

// Function declarations
void readCustomerNames(struct CustomerName *, int);
void readCustomerAddresses(struct CustomerAddress *, int);
void printCustomerData(struct CustomerName *, struct CustomerAddress *, int);

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <number of customers>\n", argv[0]);
		return EXIT_FAILURE;
	}

	int n = atoi(argv[1]);
	if (n <= 0) {
		printf("Please enter a positive integer for the number of customers.\n");
		return EXIT_FAILURE;
	}

	// Dynamically allocate memory for customer data
	struct CustomerName *names = (struct CustomerName *)malloc(n * sizeof(struct CustomerName));
	struct CustomerAddress *addresses = (struct CustomerAddress *)malloc(n * sizeof(struct CustomerAddress));

	if (names == NULL || addresses == NULL) {
		printf("Memory allocation failed!\n");
		return EXIT_FAILURE;
	}

	// Read customer names and addresses
	readCustomerNames(names, n);
	readCustomerAddresses(addresses, n);

	// Print customer data
	printCustomerData(names, addresses, n);

	// Free dynamically allocated memory
	free(names);
	free(addresses);

	return EXIT_SUCCESS;
}

// Function to read customer names and numbers
void readCustomerNames(struct CustomerName *names, int n) {
	printf("Enter a list of %d customer numbers and corresponding names:\n", n);
	for (int i = 0; i < n; i++) {
		printf("Customer %d:\n", i + 1);

		printf("Enter customer number: ");
		fgets(names[i].customerNumber, MAX_CUSTOMER_NUMBER_LENGTH, stdin);
		names[i].customerNumber[strcspn(names[i].customerNumber, "\n")] = '\0'; // Remove newline character

		printf("Enter customer name: ");
		fgets(names[i].name, MAX_NAME_LENGTH, stdin);
		names[i].name[strcspn(names[i].name, "\n")] = '\0'; // Remove newline character
	}
}

// Function to read customer addresses
void readCustomerAddresses(struct CustomerAddress *addresses, int n) {
	printf("\nEnter a list of %d customer numbers and corresponding addresses (customer numbers must match names above):\n", n);
	for (int i = 0; i < n; i++) {
		printf("Customer %d:\n", i + 1);

		printf("Enter customer number: ");
		fgets(addresses[i].customerNumber, MAX_CUSTOMER_NUMBER_LENGTH, stdin);
		addresses[i].customerNumber[strcspn(addresses[i].customerNumber, "\n")] = '\0'; // Remove newline character

		printf("Enter customer address: ");
		fgets(addresses[i].address, MAX_ADDRESS_LENGTH, stdin);
		addresses[i].address[strcspn(addresses[i].address, "\n")] = '\0'; // Remove newline character
	}
}

// Function to print all customer data
void printCustomerData(struct CustomerName *names, struct CustomerAddress *addresses, int n) {
	printf("\nAll customer data:\n");
	for (int i = 0; i < n; i++) {
		// For each customer, find the matching address
		for (int j = 0; j < n; j++) {
			if (strcmp(names[i].customerNumber, addresses[j].customerNumber) == 0) {
				printf("%-3s %-15s %-10s\n", names[i].customerNumber, names[i].name, addresses[j].address);
				break;
			}
		}
	}
}