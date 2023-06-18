#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// 3
// 10
typedef struct {
	char website[100];
	char username[100];
	char password[100];
	int id;
} Password;

// 5
// 12
static inline int getNextPasswordId(Password* passwords, int numPasswords);

int comparePasswords(const void* a, const void* b);

void searchPasswords(const Password* passwords, int numPasswords);

void addPassword(Password** passwords, int* numPasswords);

void updatePassword(Password* passwords, int numPasswords);

void deletePassword(Password** passwords, int* numPasswords);

void displayPasswords(const Password* passwords, int numPasswords);

void loadPasswords(Password** passwords, int* numPasswords);

void savePasswords(const Password* passwords, int numPasswords);

#endif
