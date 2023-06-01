#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_LENGTH 100

// 3
// 2
// 10
typedef struct {
	int id;
	char website[MAX_LENGTH];
	char username[MAX_LENGTH];
	char password[MAX_LENGTH];
	char description[MAX_LENGTH];
} Password;

// 4

void addPassword(Password passwords[], int* numPasswords);
void updatePassword(Password passwords[], int* numPasswords);
void deletePassword(Password passwords[], int* numPasswords);
void displayPassword(const Password passwords[], int numPasswords);
int loadPasswords(FILE* file, Password passwords[], int* numPasswords);
int savePasswords(FILE* file, const Password passwords[], int numPasswords);
static inline int getNextPasswordId();


#endif