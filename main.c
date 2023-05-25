#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


// MASTERPASS JE "masterpasspass"


int main() {

	char masterPass[MAX_LENGTH];
	printf("Enter the Master Pass\n");
	scanf("%s", masterPass);
	
	if (strcmp(masterPass, "masterpasspass") != 0) {
		printf("Incorrect master pass\n");
		return 1;
	}

	// 1

	Password passwords[100];
	int numPasswords = 0;

	printf("Dobrodosli u Password Manager!\n");

	// 8

		int choice;
	do {
		printf("\nMenu Options:\n");
		printf("1. Add Password\n");
		printf("2. Update Password\n");
		printf("3. Delete Password\n");
		printf("4. Display Password\n");
		printf("5. Exit\n");
		printf("Enter your choice:    ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			addPassword(passwords, &numPasswords);
			break;
		case 2:
			updatePassword(passwords, numPasswords);
			break;
		case 3:
			deletePassword(passwords, &numPasswords);
			break;
		case 4:
			displayPassword(passwords, numPasswords);
			break;
		case 5:
			printf("Exiting the Password Manager. Goodbye!\n");
			break;
		default:
			printf("Invalid Choice");
			

		}




	} while (choice != 5);



	return 0;
}
