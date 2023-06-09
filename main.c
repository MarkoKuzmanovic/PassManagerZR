#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

//MASTER PASSWORD JE "Masterpass"

//1
// 2
// 6
int main() {
	char masterPassword[100] = "Masterpass";

	printf("Enter the master password: ");
	char enteredPassword[100];
	scanf("%s", enteredPassword);

	if (strcmp(enteredPassword, masterPassword) != 0) {
		printf("Invalid master password. Access denied.\n");
		return 0;
	}

	Password* passwords = NULL;
	int numPasswords = 0;

	loadPasswords(&passwords, &numPasswords);

	// 8

	int choice;
	do {
		printf("\nPassword Manager Menu:\n");
		printf("1. Add Password\n");
		printf("2. Update Password\n");
		printf("3. Delete Password\n");
		printf("4. Display Passwords\n");
		printf("5. Sort Passwords\n");
		printf("6. Search Password\n");
		printf("7. Save and Quit\n");
		printf("Enter your choice: ");
		char choiceStr[10];
		scanf("%s", choiceStr);

		choice = atoi(choiceStr);

		if (choice == 0 && choiceStr[0] != '0') {
			while (getchar() != '\n');  
		}

		switch (choice) {
		case 1:
			addPassword(&passwords, &numPasswords);
			break;
		case 2:
			updatePassword(passwords, numPasswords);
			break;
		case 3:
			deletePassword(&passwords, &numPasswords);
			break;
		case 4:
			displayPasswords(passwords, numPasswords);
			break;
		case 7:
			savePasswords(passwords, numPasswords);
			printf("Passwords saved successfully. Exiting...\n");
			break;
		case 5:
			qsort(passwords, numPasswords, sizeof(Password), comparePasswords); // 20
			printf("Passwords sorted successfully.\n");
            break;
		case 6:
			searchPasswords(passwords, numPasswords);
			break;

		default:
			printf("Invalid choice. Please try again.\n");
			break;
		}
	} while (choice != 7);


	// 15
	free(passwords);

	return 0;
}
