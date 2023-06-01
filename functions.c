#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "functions.h"


// 6
// 7
// 11
static inline int getNextPasswordId() {
	static int passwordId = 0;

	return passwordId++;
}


void addPassword(Password passwords[], int* numPasswords) {
	if (passwords == NULL || numPasswords == NULL) {
		printf("Invalid parameters in addPassword().\n");
		return;
	}
	Password newPwd;
	printf("Enter website: ");
	fgets(newPwd.website, MAX_LENGTH, stdin);
	newPwd.website[strcspn(newPwd.website, "\n")] = '\0';

	printf("Enter username: ");
	fgets(newPwd.username, MAX_LENGTH, stdin);
	newPwd.username[strcspn(newPwd.username, "\n")] = '\0';

	printf("Enter password: ");
	fgets(newPwd.password, MAX_LENGTH, stdin);
	newPwd.password[strcspn(newPwd.password, "\n")] = '\0';

	printf("Enter description: ");
	fgets(newPwd.description, MAX_LENGTH, stdin);
	newPwd.description[strcspn(newPwd.description, "\n")] = '\0';

	newPwd.id = getNextPasswordId();

	passwords[*numPasswords] = newPwd;
	(*numPasswords)++;

	printf("Password added successfully.\n");
}


void updatePassword(Password passwords[], int* numPasswords) {
	if (passwords == NULL || numPasswords == NULL) {
		printf("Invalid parameters in updatePassword().\n");
		return;
	}

	if (*numPasswords == 0) {
		printf("No passwords stored.\n");
		return;
	}

	char website[MAX_LENGTH];
	printf("Enter website for the password you want to update: ");
	scanf("%s", website);

	static int i; // 5

	for (i = 0; i < *numPasswords; i++) {
		if (strcmp(passwords[i].website, website) == 0) {
			printf("Enter new password: ");
			scanf("%s", passwords[i].password);
			printf("Password updated.\n");
			return;
		}
	}

	printf("Password not found!\n");
}


void deletePassword(Password passwords[], int* numPasswords) {
	if (passwords == NULL || numPasswords == NULL) {
		printf("Invalid parameters in deletePassword().\n");
		return;
	}

	if (*numPasswords == 0) {
		printf("No passwords stored.\n");
		return;
	}


	char website[MAX_LENGTH];
	printf("Enter website for the password you want to delete: ");
	fgets(website, MAX_LENGTH, stdin);
	website[strcspn(website, "\n")] = '\0'; // Remove trailing newline

	int i;
	for (i = 0; i < *numPasswords; i++) {
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


void displayPassword(const Password passwords[], int numPasswords) {
	if (passwords == NULL) {
		printf("Invalid parameters in displayPassword().\n");
		return;
	}

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



int savePasswords(FILE* file, const Password passwords[], int numPasswords) {
	if (file == NULL || passwords == NULL) {
		printf("Invalid parameters in savePasswords().\n");
		return 0;
	}

	for (int i = 0; i < numPasswords; i++) {
		fprintf(file, "%s %s %s %s\n", passwords[i].website, passwords[i].username,
			passwords[i].password, passwords[i].description);
	}

	return 1;
}


int loadPasswords(FILE* file, Password passwords[], int* numPasswords) {
	if (file == NULL || passwords == NULL || numPasswords == NULL) {
		printf("Invalid parameters in loadPasswords().\n");
		return 0;
	}

	*numPasswords = 0;

	char line[MAX_LENGTH * 4];

	while (fgets(line, sizeof(line), file)) {
		sscanf(line, "%s %s %s %[^\n]", passwords[*numPasswords].website, passwords[*numPasswords].username,
			passwords[*numPasswords].password, passwords[*numPasswords].description);
		(*numPasswords)++;
	}

	return 1;
}
