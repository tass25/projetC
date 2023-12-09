#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>  // For getch() and getche()
#define ENTER 13
#define TAB 9
#define BKSP 8

#define MAX_PASSWORD_LENGTH 20   // Define maximum password length
#define MAX_ATTEMPTS 3           // Define maximum login attempts

// Function to clear the screen
void clearScreen() {
    system("cls");
}

// Placeholder for root menu functionality
void rootMenu() {
    // Root menu implementation
}

// Placeholder for user menu functionality
void userMenu() {
    // User menu implementation
}

// Function for handling password entry and verification
void password() {
    clearScreen();
    fflush(stdin);  // Clear the input buffer

    char code[] = "tesnime";  // Default password
    char pwd[MAX_PASSWORD_LENGTH];  // Buffer for user-entered password
    int attemptCount = 0;  // Count of login attempts

    printf("--------------------\n");
    printf(">>> Login First <<<\n");
    printf("--------------------\n\n");

    while (attemptCount < MAX_ATTEMPTS) {
        int i = 0;
        printf("Enter your password and press ENTER to confirm.\n");
        printf("Password: ");

        while (1) {
            char ch = getch();  // Get character without echoing it
            if (ch == '\r' && i > 0) {  // Enter key pressed and at least one character entered
                pwd[i] = '\0';  // Null terminate the string
                break;
            } else if (ch == '\b' && i > 0) {  // Backspace pressed and there are characters to erase
                i--;
                printf("\b \b");  // Erase the last character on the console
            } else if (ch >= 32 && ch <= 126 && i < MAX_PASSWORD_LENGTH - 1) {  // Printable character entered and buffer not full
                pwd[i++] = ch;  // Store character in the password buffer
                printf("*");  // Print an asterisk for each character entered
            }
        }

        fflush(stdin);  // Clear the input buffer after password entry

        if (strcmp(code, pwd) == 0) {  // Check if entered password matches the default password
            printf("\nCorrect Password!\n");
            Sleep(2000);  // Wait for 2 seconds
            rootMenu();  // Enter the root menu
            return;
        } else {
            printf("\nInvalid Password!\n");
            attemptCount++;  // Increment the attempt count
            if (attemptCount == MAX_ATTEMPTS) {  // Check if maximum attempts are reached
                printf("Maximum login attempts reached. Exiting...\n");
                Sleep(2000);  // Wait for 2 seconds before exiting
                exit(0);  // Exit the program
            } else {
                Sleep(2000);  // Wait for 2 seconds before next attempt
                clearScreen();  // Clear the screen for next attempt
            }
        }
    }

    userMenu();  // Enter the user menu if maximum attempts not reached
}


int validTitle(char *title) {
    if (strlen(title) == 0 || strlen(title) >= TAILLE_CHAINE) {
        return 0; // Invalid title length
    }
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    char temp[TAILLE_CHAINE];
    while (fscanf(file, "%*[^,],%[^,],%*d,%*[^,],%*d\n", temp) == 1) {
        if (strcmp(temp, title) == 0) {
            fclose(file);
            return 0; // Title already exists 
        }
    }
    fclose(file);
    return 1; // Valid and unique title
}

int validCode(int code) {
    if (code <= 0) {
        return 0; // Invalid code
    }
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    int tempCode;
    while (fscanf(file, "%d,%*[^,],%*[^,],%*d\n", &tempCode) == 1) {
        if (tempCode == code) {
            fclose(file);
            return 0; // Code already exists
        }
    }
    fclose(file);
    return 1; // Valid and unique code
}

int validName(char *name) {
    if (strlen(name) > 0 && strlen(name) <= TAILLE_CHAINE) {
        return 1; 
    }
    return 0; 
}
int validYear(int year) {
    int currentYear = 2023 ;
    if (year >= 1900 && year <= currentYear) {
        return 1; 
    }
    return 0; 
}
int validState(int state) {
    if (state == EMPRUNTE || state == DISPONIBLE || state == EN_REPARATION) {
        return 1; 
    }
    return 0; 
}

int main() {
    password();
    
}

//mazel user menu w root menu 
//etude de cas(contextuealisation ) 
//les fonctionalités
