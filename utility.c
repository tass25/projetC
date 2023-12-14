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
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

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
        if (strcmp(pass, "tesnime") == 0) {
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
        return 0;
    }
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    char temp[TAILLE_CHAINE];
    while (fgets(temp, TAILLE_CHAINE, file) != NULL) {
        // Splitting the line to extract title
        char *found = strstr(temp, title);
        if (found != NULL && (found == temp || *(found - 1) == ',')) {
            fclose(file);
            return 0; // Title already exists
        }
    }
    fclose(file);
    return 1;
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
    if (strlen(name) == 0 || strlen(name) > TAILLE_CHAINE) {
        return 0; // Check for empty or too long name
    }
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i])) {
            return 0; // Check if each character is a letter
        }
    }
    return 1; // Name is valid
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

void delay(int mseconds)
{
    clock_t target=clock();
    while(clock()<target+mseconds);
}

void splash_s(int x, int y, int l, int h)
{
    for (int i = 0; i < h; i++)
    {
        gotoxy(x, y + i);
        printf("\xDB");
        delay(5);
    }
    for (int i = 0; i < l - 2; i++)
    {
        printf("\xDB");
        delay(3);
    }
    for (int i = y + h; i > y; i--)
    {
        gotoxy(x + l - 1, i - 1);
        printf("\xDB");
        delay(5);
    }
    for (int i = x + l - 2; i > x; i--)
    {
        gotoxy(i, y);
        printf("\xDB");
        delay(3);
    }
    char a[11] = "Welcome to";
    gotoxy(55, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%c", a[i]);
        delay(8);
    }
    char b[27] = "tayyyyyyyyyyyyyyyyyyyyyy";
    gotoxy(47, 11);
    for (int i = 0; i < 26; i++)
    {
        printf("%c", b[i]);
        delay(8);
    }
}
void box(int a, int c,int l,int h)
{
    gotoxy(a,c);
    printf("%c",218);
    for (int i = 0; i < l; i++)
    {
        printf("%c",196);
    }
    printf("%c\n",191);

    for (int i = 0,y=c+1; i < h; i++,y++)
    {
        gotoxy(a,y);
        printf("%c",179);
        gotoxy(a+l+1,y);
        printf("%c",179);
    }
    gotoxy(a,c+h);
    printf("%c",192);
    for (int i = 0; i < l; i++)
    {
        printf("%c",196);
    }
    printf("%c\n",217);
}

void loader(int x,int y,int z)
{
    box(x,y,z,2);
    gotoxy(x+z/2-3,y-1);
    //gotoxy(x-+40,y-1);       dont know how but it prints at good location, must try
    printf("Loading...");
    //gotoxy(x+1,y+1);
    float j = 100.00/z;
    for (int i = 1; i <= z; i++,j+=100.00/z)
    {
        gotoxy(x+i,y+1);
        printf("\xDB");
        gotoxy(x+z+5,y+1);
        printf("%2d%%",(int)j);
        delay(10);
    }
    gotoxy(x+3,y+3);
}



//mazel user menu w root menu 
//etude de cas(contextuealisation ) 
//les fonctionalités
