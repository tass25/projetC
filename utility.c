#include "utility.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
char*Tab_Etat[2]={" DISPONIBLE","EN_REPARATION"};

#define TAB 9

#define ENTER 13
#define BKSP 8
#define MAX_PASSWORD_LENGTH 20   // Define maximum password length

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void h_line(int x,int y, int l)
{
    gotoxy(x,y);
    printf("%c",195);
    for (int i = 0; i < l; i++)
    {
        printf("%c",196);
    }
    printf("%c",180);
}



void textcolor(int color)
{
    static int __BACKGROUND;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            color + (__BACKGROUND << 4));
}
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
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
    char b[27] = "WELCOME TO THE WORLD OF MAGIC";
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
int menu_selector(int x, int y1, int y2, char (*items)[100])
{
    hidecursor();
    int s = 1, n = (y2 - y1) / 2 + 1;
    char ch;

    //time
    time_t mytime = time(NULL);
    char *time_str = ctime(&mytime);
    time_str[strlen(time_str) - 1] = '\0';
    // printf("Current Time : %s\n", time_str);
    //date
    char da[12];
    for(int i=0;i<11;i++)
    {
        if(i<7)
        {
            da[i]=time_str[i+4];
        }
        else
        {
            da[i]=time_str[i+50];
        }
    }
    da[12]='\0';
    textcolor(3);
    gotoxy(56,5);
    printf("%s",da);
    textcolor(6);

    char hr[3], mi[3], sec[3];

    for (int i = 0; i < 2; i++)
    {
        hr[i] = time_str[i + 11];
        sec[i] = time_str[i + 17];
        mi[i] = time_str[i + 14];
    }
    hr[3] = '\0';
    int h = atoi(hr);
    mi[3] = '\0';
    int m = atoi(mi);
    sec[3] = '\0';
    int seco = atoi(sec);

    for (int i = 1, j = y1 + 2; i < n; i++) //here we are skipping first element bcz it will be printed after this loop
    {
        gotoxy(31, j);
        printf("%s", items + i); //items can aslo be printed without derefrencing here
        j += 2;
    }

    textcolor(3);
    gotoxy(x, y1);
    printf("\xDB\xDB\xB2");
    gotoxy(x + 5, y1);
    printf("%s", *(items + 0)); //first item is printed here with different color

    int se = y1; //se = vertical axis position for selector to be printed

    gotoxy(56, 7);
    printf("%02d : %02d : %02d", h, m, s);
    while (1)
    {
        if (seco == 60)
        {
            m++;
            seco = 0;
            gotoxy(61, 7);
            printf("%02d : %02d", m, seco);
        }
        if (m == 60)
        {
            h++;
            m = 0;
            gotoxy(56, 7);
            printf("%02d : %02d : %02d", h, m, seco);
        }
        delay(500);
        // sleep(1);
        seco++;
        gotoxy(66, 7);
        printf("%02d", seco);

        if (kbhit())
        {
            ch = getch();
            if (ch == 13)
            {
                textcolor(6);
                // printf("%d", s);
                return s;
            }
            ch = getch(); //reason of second getch() is that arrow keys give 2 output to getch() function, and 1st is common for all and second is according to their respective arrows.

            if (ch == 80) //down
            {
                textcolor(6);
                gotoxy(x, se);
                printf("     %s", *(items + s - 1));
                if (se == y2) //if 'se' is at last element
                {
                    s = 1;
                    se = y1;
                }
                else
                {
                    s++;
                    se += 2;
                }
                textcolor(3);
                gotoxy(x, se);
                printf("\xDB\xDB\xB2  %s", *(items + s - 1));
                // gotoxy(1,1); // for removing the pointer from screen for visual purpose
                //continue;
            }
            else if (ch == 72) //up
            {
                textcolor(6);
                gotoxy(x, se);
                printf("     %s", *(items + s - 1));
                if (se == y1)
                {
                    s = n;
                    se = y2;
                }
                else
                {
                    s--;
                    se -= 2;
                }
                textcolor(3);
                gotoxy(x, se);
                printf("\xDB\xDB\xB2  %s", *(items + s - 1));
                // gotoxy(1,1); // for removing the pointer from screen for visual purpose
                //continue;
            }
        }
        delay(500);
        // it can be removed if you want to use sleep instaed of delay.
        if (kbhit())
        {
            ch = getch();
            if (ch == 13)
            {
                textcolor(6);
                // printf("%d", s);
                return s;
            }
            ch = getch(); //reason of second getch() is that arrow keys give 2 output to getch() function, and 1st is common for all and second is according to their respective arrows.

            if (ch == 80) //down
            {
                textcolor(6);
                gotoxy(x, se);
                printf("     %s", *(items + s - 1));
                if (se == y2) //if 'se' is at last element
                {
                    s = 1;
                    se = y1;
                }
                else
                {
                    s++;
                    se += 2;
                }
                textcolor(3);
                gotoxy(x, se);
                printf("\xDB\xDB\xB2  %s", *(items + s - 1));
                // gotoxy(1,1); // for removing the pointer from screen for visual purpose
                //continue;
            }
            else if (ch == 72) //up
            {
                textcolor(6);
                gotoxy(x, se);
                printf("     %s", *(items + s - 1));
                if (se == y1)
                {
                    s = n;
                    se = y2;
                }
                else
                {
                    s--;
                    se -= 2;
                }
                textcolor(3);
                gotoxy(x, se);
                printf("\xDB\xDB\xB2  %s", *(items + s - 1));
                // gotoxy(1,1); // for removing the pointer from screen for visual purpose
                //continue;
            }
        }//can be deleted till here.
    }
}





int selector(int x, int y1, int y2, char (*items)[100])
{
    hidecursor();
    int displayedItems = (y2 - y1) / 2 + 1; // Number of items that can be displayed at once
    int totalItems = 10; // Total items in your array (you might need to adjust this based on your actual number of items)
    int s = 0, topItem = 0;
    char ch;

    while (1)
    {
        // Display the items
        for (int i = topItem, j = y1; i < totalItems && i < topItem + displayedItems; ++i, j += 2)
        {
            textcolor((i == s) ? 3 : 6);
            gotoxy(x, j);
            printf("%s", items[i]);
        }

        ch = getch();
        if (ch == 13) // Enter key
        {
            textcolor(6);
            return s + 1;
        }

        ch = getch(); // For arrow keys

        if (ch == 80 && s < totalItems - 1) // Down arrow key
        {
            s++;
            if (s >= topItem + displayedItems)
            {
                topItem++;
            }
        }
        else if (ch == 72 && s > 0) // Up arrow key
        {
            s--;
            if (s < topItem)
            {
                topItem--;
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
    if ( state == DISPONIBLE || state == EN_REPARATION) {
        return 1; 
    }
    return 0; 
}




//mazel user menu w root menu 
//etude de cas(contextuealisation ) 
//les fonctionalités
