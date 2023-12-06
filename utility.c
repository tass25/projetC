#include "utility.h"
#include <stdio.h>
#include<stdlib.h>
    
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
