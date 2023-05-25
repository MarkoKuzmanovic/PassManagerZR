#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "functions.h"

// 10

void addPassword(Password passwords[], int* numPasswords) { 
	Password newPwd;
	printf("Enter website: ");
	scanf("%s", newPwd.website);
	printf("Enter username: ");
	scanf("%s", newPwd.username);
	printf("Enter password: ");
	scanf("%s", newPwd.password);
	printf("Enter description: ");
	scanf("%s", newPwd.description);

	passwords[*numPasswords] = newPwd;
	(*numPasswords)++;


	printf("Password added successfully.\n");
}

void updatePassword(Password passwords[], int* numPasswords) {
	if (numPasswords == 0) {
		printf("No passwords stored.\n");
		return;
	}

	char website[MAX_LENGTH];
	printf("Enter website for the password you want to update: ");
	scanf("%s", website);

	int i;
	for (i = 0; i < numPasswords; i++) {
		if (strcmp(passwords[i].website, website) == 0) {
			printf("Enter new password ");
			scanf("%s", passwords[i].password);
			printf("Password updated");
			return;
		}

	}

	printf("Password not found!\n");

}

void deletePassword(Password passwords[], int* numPasswords) {
	if (numPasswords == 0) {
		printf("No passwords stored.\n");
		return;
	}

	char website[MAX_LENGTH];
	printf("Enter website for the password you want to delete: ");
	scanf("%s", website);
	
	int i;
	for (i = 0; i < *numPasswords; i++){
		if (strcmp(passwords[i].website, website) == 0) {
			(*numPasswords)--;
			for (int j = i; j < *numPasswords; j++) {
				passwords[j] = passwords[j + 1];

			}
			printf("Password deleted.\n");
			return;
		}
	

	}

	printf("Password not found.\n");

}

void displayPassword(Password passwords[], int numPasswords) {
	if (numPasswords == 0) {
		printf("No passwords stored.\n");
		return;
	}

	printf("Stored Passwords:\n");
	for (int i = 0; i < numPasswords; i++) {
		printf("Website: %s\n", passwords[i].website);
		printf("Username: %s\n", passwords[i].username);
		printf("Password: %s\n", passwords[i].password);
		printf("Description: %s\n", passwords[i].description);
		printf("---------------------------\n");
	}
}
