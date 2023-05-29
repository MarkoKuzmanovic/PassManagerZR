#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// MASTER PASS JE "masterpasspass"


int main() {
    char masterPass[MAX_LENGTH];
    printf("Enter the Master Pass: ");
    scanf("%s", masterPass);
    getchar(); 

    if (strcmp(masterPass, "masterpasspass") != 0) {
        printf("Incorrect master pass\n");
        return 1;
    }

    Password passwords[100];
    int numPasswords = 0;

    if (!loadPasswords("passwords.txt", passwords, &numPasswords)) {  // 16
        printf("Failed to load passwords from file.\n");
    }


    printf("Welcome to the Password Manager!\n");

    // 1

    int choice;

    // 8

    do {
        printf("\nMenu Options:\n");
        printf("1. Add Password\n");
        printf("2. Update Password\n");
        printf("3. Delete Password\n");
        printf("4. Display Password\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        while (getchar() != '\n'); 

        switch (choice) {
        case 1:
            addPassword(passwords, &numPasswords);
            savePasswords("passwords.txt", passwords, numPasswords); 
            break;
        case 2:
            updatePassword(passwords, numPasswords);
            savePasswords("passwords.txt", passwords, numPasswords); 
            break;
        case 3:
            deletePassword(passwords, &numPasswords);
            savePasswords("passwords.txt", passwords, numPasswords); 
            break;
        case 4:
            displayPassword(passwords, numPasswords);
            break;
        case 5:
            printf("Exiting the Password Manager. Goodbye!\n");
            break;
        default:
            printf("Invalid Choice\n");
        }

    } while (choice != 5);

    return 0;
}