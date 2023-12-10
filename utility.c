#include "utility.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define TAB 9

#define ENTER 13
#define BKSP 8
#define MAX_PASSWORD_LENGTH 20   // Define maximum password length

void rootMenu() {
    // Placeholder function for the root menu functionality
    printf("Welcome to Root Menu\n");
}

void userMenu() {
    // Placeholder function for the user menu functionality
    printf("Welcome to User Menu\n");
}

void password(int x, int y) {
    int i = 0, attempts = 0;  // Initialize counter for password characters and attempts
    const int maxAttempts = 2;  // Maximum allowed attempts
    char ch, pass[15], t[17] = "Enter Password: ";  // Password input buffer and prompt text

    while (attempts < maxAttempts) {  // Loop until maximum attempts are reached
        i = 0;  // Reset the password character counter for each attempt
        gotoxy(x, y);  // Position the cursor using gotoxy function
        printf("%s", t);  // Display the password prompt
        while (1) {  // Infinite loop to capture password input
            ch = getch();  // Get a character without echoing it
            if (ch == BKSP) {  // Check if backspace is pressed
                if (i > 0) {  // Check if there are characters to erase
                    i--;  // Decrease character count
                    printf("\b \b");  // Erase a character from console
                }
            } else if (ch == ENTER) {  // Check if enter key is pressed
                pass[i] = '\0';  // Null-terminate the password string
                break;  // Exit the password input loop
            } else if (i < 14) {  // Check for password length limit (excluding null terminator)
                pass[i] = ch;  // Store the character in password buffer
                printf("*");  // Print an asterisk for each character entered
                i++;  // Increment character count
            }
        }

        // Check if entered password matches the predefined password
        if (strcmp(pass, "Developer-dk") == 0) {
            system("color A");  // Change console color to indicate correct password
            printf("\nCorrect Password\n");
            rootMenu();  // Call the root menu function
            return;  // Exit the password function
        } else {
            system("color 4");  // Change console color to indicate incorrect password
            printf("\nIncorrect Password. ");
            attempts++;  // Increment the attempt counter
            if (attempts < maxAttempts) {
                printf("Try again...\n");  // Prompt to try again if attempts are left
            } else {
                printf("Redirecting to User Menu...\n");  // Inform about redirection
                userMenu();  // Call the user menu function
                return;  // Exit the password function
            }
        }
    }
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

void main() {
    system("color 9");
    password(30,15);

}

//mazel user menu w root menu 
//etude de cas(contextuealisation ) 
//les fonctionalités
