#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STREET_LENGTH 100
#define MAX_POSTAL_CODE_LENGTH 10
#define MAX_TOWN_LENGTH 50
#define MAX_PHONE_LENGTH 15

// Define the structure "Address"
typedef struct {
	char streetAndNr[MAX_STREET_LENGTH];
	char postalCode[MAX_POSTAL_CODE_LENGTH];
	char town[MAX_TOWN_LENGTH];
	char phoneNr[MAX_PHONE_LENGTH];
} Address;

// Define the structure "Student"
typedef struct {
	char name[MAX_NAME_LENGTH];
	Address homeAddress;
	Address schoolAddress;
} Student;

// Function declarations
void readAddress(Address *);
void printAddress(Address);
void readStudent(Student *);
void printStudent(Student);

int main(void) {
	Student student; // Declare a Student

	// Read student data
	printf("Enter student details:\n");
	readStudent(&student);

	// Print student data
	printf("\nStudent details:\n");
	printStudent(student);

	return 0;
}

// Function to read an Address
void readAddress(Address *address) {
	printf("Street and Number: ");
	fgets(address->streetAndNr, sizeof(address->streetAndNr), stdin);
	address->streetAndNr[strcspn(address->streetAndNr, "\n")] = '\0'; // Remove newline character

	printf("Postal Code: ");
	fgets(address->postalCode, sizeof(address->postalCode), stdin);
	address->postalCode[strcspn(address->postalCode, "\n")] = '\0'; // Remove newline character

	printf("Town: ");
	fgets(address->town, sizeof(address->town), stdin);
	address->town[strcspn(address->town, "\n")] = '\0'; // Remove newline character

	printf("Phone Number: ");
	fgets(address->phoneNr, sizeof(address->phoneNr), stdin);
	address->phoneNr[strcspn(address->phoneNr, "\n")] = '\0'; // Remove newline character
}

// Function to print an Address
void printAddress(Address address) {
	printf("Address:\n");
	printf("  Street and Number: %s\n", address.streetAndNr);
	printf("  Postal Code: %s\n", address.postalCode);
	printf("  Town: %s\n", address.town);
	printf("  Phone Number: %s\n", address.phoneNr);
}

// Function to read a Student
void readStudent(Student *student) {
	printf("Name: ");
	fgets(student->name, sizeof(student->name), stdin);
	student->name[strcspn(student->name, "\n")] = '\0'; // Remove newline character

	printf("Home Address:\n");
	readAddress(&(student->homeAddress));

	printf("School Address:\n");
	readAddress(&(student->schoolAddress));
}

// Function to print a Student
void printStudent(Student student) {
	printf("Name: %s\n", student.name);
	printf("Home ");
	printAddress(student.homeAddress);
	printf("School ");
	printAddress(student.schoolAddress);
}
