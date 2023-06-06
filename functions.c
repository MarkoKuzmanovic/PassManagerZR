#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// 4
// 7 

static inline int getNextPasswordId(Password* passwords, int numPasswords) {

	int maxId = 0;
	for (int i = 0; i < numPasswords; i++) {
		if (passwords[i].id > maxId) {
			maxId = passwords[i].id;
		}
	}
	return maxId + 1;
}

// 13

void addPassword(Password** passwords, int* numPasswords) {

	Password newPass;

	printf("Enter website: ");
	scanf("%s", newPass.website);

	printf("Enter username: ");
	scanf("%s", newPass.username);

	printf("Enter password: ");
	scanf("%s", newPass.password);

	newPass.id = getNextPasswordId(*passwords, *numPasswords);

	
	Password* expandedPasswords = realloc(*passwords, (*numPasswords + 1) * sizeof(Password));
	if (expandedPasswords == NULL) {
		printf("Memory allocation error.\n");
		return;
	}

	
	*passwords = expandedPasswords;


	(*passwords)[*numPasswords] = newPass;
	(*numPasswords)++;

	printf("Password added successfully!\n");
}

// 9

void updatePassword(Password* passwords, int numPasswords) {
	// 14
	char* website = malloc(100 * sizeof(char));
	if (website == NULL) {
		printf("Memory allocation error.\n");
		return;
	}

	printf("Enter the website for the password you want to update: ");
	scanf("%s", website);


	// 21
	int foundIndex = -1;
	for (int i = 0; i < numPasswords; i++) {
		if (strcmp(passwords[i].website, website) == 0) {
			foundIndex = i;
			break;
		}
	}
		
	free(website); 

	if (foundIndex == -1) {
		printf("Password not found for the specified website.\n");
		return;
	}


	printf("Enter the new password: ");
	scanf("%s", passwords[foundIndex].password);

	printf("Password updated successfully!\n");
}


void deletePassword(Password** passwords, int* numPasswords) {
	
	char website[100];

	printf("Enter the website for the password you want to delete: ");
	scanf("%s", website);

	int foundIndex = -1;
	for (int i = 0; i < *numPasswords; i++) {
		if (strcmp((*passwords)[i].website, website) == 0) {
			foundIndex = i;
			break;
		}
	}

	if (foundIndex == -1) {
		printf("Password not found for the specified website.\n");
		return;
	}

	
	for (int i = foundIndex; i < *numPasswords - 1; i++) {
		(*passwords)[i] = (*passwords)[i + 1];
	}


	Password* reducedPasswords = realloc(*passwords, (*numPasswords - 1) * sizeof(Password));
	if (reducedPasswords == NULL && *numPasswords > 1) {
		printf("Memory allocation error.\n");
		return;
	}

	
	*passwords = reducedPasswords;
	(*numPasswords)--;

	printf("Password deleted successfully!\n");
}





// 11

void displayPasswords(const Password* passwords, int numPasswords) {
	
	printf("Stored Passwords:\n");

	if (numPasswords == 0) {
		printf("No passwords found.\n");
		return;
	}

	for (int i = 0; i < numPasswords; i++) {
		printf("Website: %s\n", passwords[i].website);
		printf("Username: %s\n", passwords[i].username);
		printf("Password: %s\n", passwords[i].password);
		printf("ID: %d\n", passwords[i].id);
		printf("---------------\n");
	}
}

void loadPasswords(Password** passwords, int* numPasswords) {

	FILE* file = fopen("passwords.txt", "r");
	if (file == NULL) {
		printf("Error opening file.\n");
		return;
	}

	int initialSize = 10;
	int capacity = initialSize;
	int count = 0;
	Password* tempPasswords = malloc(capacity * sizeof(Password));

	if (tempPasswords == NULL) {
		printf("Memory allocation error.\n");
		fclose(file);
		return;
	}

	Password password;

	while (fscanf(file, "%99s %99s %99s %d", password.website, password.username, password.password, &password.id) == 4) {
		if (count == capacity) {
			capacity *= 2;
			Password* expandedPasswords = realloc(tempPasswords, capacity * sizeof(Password));
			if (expandedPasswords == NULL) {
				printf("Memory allocation error.\n");
				fclose(file);
				free(tempPasswords);
				return;
			}
			tempPasswords = expandedPasswords;
		}

		tempPasswords[count] = password;
		count++;
	}

	fclose(file);

	*passwords = malloc(count * sizeof(Password));
	if (*passwords == NULL) {
		printf("Memory allocation error.\n");
		free(tempPasswords);
		return;
	}

	memcpy(*passwords, tempPasswords, count * sizeof(Password));
	*numPasswords = count;

	free(tempPasswords);
}

// 16
void savePasswords(const Password* passwords, int numPasswords) {

	FILE* file = fopen("passwords.txt", "w");
	if (file == NULL) {
		printf("Error opening file.\n");
		return;
	}

	for (int i = 0; i < numPasswords; i++) {
		fprintf(file, "%s %s %s %d\n", passwords[i].website, passwords[i].username, passwords[i].password, passwords[i].id);
	}

	fclose(file);
}
