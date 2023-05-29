#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "functions.h"


// 6

void addPassword(Password passwords[], int* numPasswords) {
	Password newPwd;
	printf("Enter website: ");
	fgets(newPwd.website, MAX_LENGTH, stdin);
	newPwd.website[strcspn(newPwd.website, "\n")] = '\0'; // Remove trailing newline

	printf("Enter username: ");
	fgets(newPwd.username, MAX_LENGTH, stdin);
	newPwd.username[strcspn(newPwd.username, "\n")] = '\0'; // Remove trailing newline

	printf("Enter password: ");
	fgets(newPwd.password, MAX_LENGTH, stdin);
	newPwd.password[strcspn(newPwd.password, "\n")] = '\0'; // Remove trailing newline

	printf("Enter description: ");
	fgets(newPwd.description, MAX_LENGTH, stdin);
	newPwd.description[strcspn(newPwd.description, "\n")] = '\0'; // Remove trailing newline

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
	for (i = 0; i < *numPasswords; i++) {    // 4 
		if (strcmp(passwords[i].website, website) == 0) {
			(*numPasswords)--;
			for (int j = i; j < *numPasswords; j++) { //9
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
	printf("\n");
	printf("Stored Passwords:\n");
	printf("\n");
	for (int i = 0; i < numPasswords; i++) {
		printf("Website: %s\n", passwords[i].website);
		printf("Username: %s\n", passwords[i].username);
		printf("Password: %s\n", passwords[i].password);
		printf("Description: %s\n", passwords[i].description);
		printf("---------------------------\n");
	}
}

// 10

int savePasswords(const char* filename, Password passwords[], int numPasswords) {
	FILE* file = fopen(filename, "w");  
	if (file == NULL) {
		return 0; 
	}

	for (int i = 0; i < numPasswords; i++) {
		fprintf(file, "%s %s %s %s\n", passwords[i].website, passwords[i].username,
			passwords[i].password, passwords[i].description);
	}

	fclose(file);
	return 1; 
}

int loadPasswords(const char* filename, Password passwords[], int* numPasswords) {
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		return 0;
	}

	*numPasswords = 0;

	while (fscanf(file, "%s %s %s %s", passwords[*numPasswords].website, passwords[*numPasswords].username,
		passwords[*numPasswords].password, passwords[*numPasswords].description) == 4) {
		(*numPasswords)++;
	}

	fclose(file);
	return 1; 
}