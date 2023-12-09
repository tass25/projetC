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

void menu() {
    printf("Welcome to the main menu.\n");
}

void menu2() {
    printf("Welcome to the secondary menu.\n");
}

void password() {
    system("cls");
    fflush(stdin);

    char pwd[255];
    char code[255] = {"Alkaison"};
    int i = 0;
    char ch;

    printf("--------------------\n");
    printf(">>> Login First <<<\n");
    printf("--------------------\n\n");

    printf("Enter your password. Hit ENTER to confirm.\n");
    printf("Password:");

    while (1) {
        ch = getch(); // get key

        if (ch == ENTER || ch == TAB) {
            pwd[i] = '\0';
            break;
        } else if (ch == BKSP) {
            if (i > 0) {
                i--;
                printf("\b \b"); // for backspace
            }
        } else {
            pwd[i++] = ch;
            printf("* \b"); // to replace password character with *
        }
    }

    fflush(stdin);

    // Verifies the password
    if (strcmp(code, pwd) == 0) {
        printf("\nCorrect Password!\n");
        Sleep(2000);
        menu(); // Enter the root menu if the password is correct
    } else {
        printf("\nInvalid Password!\n");
        Sleep(2000);
        menu2(); // Enter the user menu if the password is incorrect
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
    password();

}

//mazel user menu w root menu 
//etude de cas(contextuealisation ) 
//les fonctionalités
