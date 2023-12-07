#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>  // For getch() and getche()
#define ENTER 13
#define TAB 9
#define BKSP 8

void password() {
    system("cls");
    fflush(stdin);

    char code[] = "tesnime";
    char pwd[255];
    int i = 0;
    int passTerminator = 1;

    printf("--------------------\n");
    printf(">>> Login First <<<\n");
    printf("--------------------\n\n");

    printf("Enter your password and press ENTER to confirm.\n");
    printf("Password: ");

    while (1) {
        char ch = getch();

        if (ch == '\r') {  // taa return 
            pwd[i] = '\0';
            break;
        } else if (ch == '\b') {  // Backspace
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            if (i < 255 - 1) {
                pwd[i++] = ch;
                printf("*");
            }
        }
    }

    fflush(stdin);

    if (strcmp(code, pwd) == 0) {
        printf("\nCorrect Password!\n");
        Sleep(2000);
        // menu eli mazel ma tkhdmch 
    } else {
        printf("\nInvalid Password!\n");
        if (passTerminator ==3) {
            printf("Maximum login attempts reached. Exiting...\n");
            Sleep(2000);
            exit(0);
        } else {
            passTerminator++;
            Sleep(2000);
            password();
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

int main() {
    password();
    
}


//etude de cas(contextuealisation ) 
//les fonctionalités
