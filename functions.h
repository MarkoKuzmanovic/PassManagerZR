#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_LENGTH 100

// 3
// 2
// 10
typedef struct {
	char website[MAX_LENGTH];
	char username[MAX_LENGTH];
	char password[MAX_LENGTH];
	char description[MAX_LENGTH]; //12




}Password;

void addPassword(Password passwords[], int* numPasswords);
void updatePassword(Password passwords[], int* numPasswords);
void deletePassword(Password passwords[], int* numPasswords);
void displayPassword(Password passwords[], int* numPasswords);


#endif

