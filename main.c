#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "abonne.h" // Include your header files for abonne and books
#include "books.h"
#include "utility.h"
#define ENTER 13
#define BKSP 8
void rootMenu() ;


void reset()
{
    system("cls");
    box(30,7,50,7);
    remove("data.dat");
    remove("issue.dat");
    gotoxy(36,10);
    printf("Reset Successful");
    gotoxy(36,12);
    printf("Press Any Key To Continue.....");
    getch();
    return rootMenu();
}
void settings()
{
    system("cls");
    box(23, 4, 71, 18);
    h_line(23, 6, 71);
    box(23, 23, 71, 2);
    gotoxy(50, 5);
    printf("Settings");

    char items[3][100] = {"1. Reset", "2. Goto root Memu", "3. Close Application"};

    gotoxy(25, 24);
    printf("Use Up/Down Arrows keys for Navigation.");

    int s = selector(26, 8, 12, items);

    switch (s)
    {
    case 1:
        reset();
        break;
    case 2:
        rootMenu();
        break;
    case 3:
        exit(0);
        break;
    }
}
void book_management() {
    Liste_Livre Disponible, En_Reparation;
    initialiser_liste_Livre(&Disponible);
    initialiser_liste_Livre(&En_Reparation);
    chargerLivresDepuisFichier(&Disponible, &En_Reparation);

    system("cls");
    box(23, 4, 71, 26);
    h_line(23, 6, 71);
    box(23, 26, 71, 2);
    gotoxy(52, 5);
    printf("Book Management");
    
    char items[10][100] = {
        "1. Ajouter un livre", 
        "2. Afficher un livre", 
        "3. Supprimer un livre",
        "4. Chercher un livre",
        "5. Modifier l'année de publication",
        "6. Modifier le titre",
        "7. Modifier l'auteur",
        "8. Afficher les livres par année",
        "9. retour au menu principale",
        "10.Quitter",
    };

    gotoxy(25, 27);
    printf("Use Up/Down Arrows keys for Navigation.");

    int s = selector(26, 8, 20, items);

    int code, annee;
    Livre l;
system("cls");
    switch (s) {
          
        case 1: 
            saisir_livre(&l);
            Ajouter_Livre_list(&Disponible, l);
            printf("Press Any To Continue.....");
            getch();
            return book_management() ;
            break;
        case 2:
            printf("Entrez le code du livre à afficher: ");
            scanf("%d", &code);
            Afficher_Livre(code);
             printf("Press Any To Continue.....");
            getch();
            return book_management() ;
            break;
        case 3:
            printf("Entrez le code du livre à supprimer: ");
            scanf("%d", &code);
            Supprimer_Livre(code);
             printf("Press Any To Continue.....");
            getch();
            return book_management() ;
            break;
        case 4:
            printf("Entrez le code du livre à chercher: ");
            scanf("%d", &code);
            Chercher_Livre(Disponible, En_Reparation, code) ? printf("Livre trouvé.\n") : printf("Livre non trouvé.\n");
             printf("Press Any To Continue.....");
            getch();
            return book_management() ;
            break;
        case 5:
            printf("Entrez le code du livre pour modifier l'année de publication: ");
            scanf("%d", &code);
            Modifier_Annee_publication(&Disponible, &En_Reparation, code);
             printf("Press Any To Continue.....");
            getch();
            return book_management() ;
            break;
        case 6:
            printf("Entrez le code du livre pour modifier le titre: ");
            scanf("%d", &code);
            Modifier_Titre(&Disponible, &En_Reparation, code);
             printf("Press Any To Continue.....");
            getch();
            return book_management() ;
            break;
        case 7:
            printf("Entrez le code du livre pour modifier l'auteur: ");
            scanf("%d", &code);
            Modifier_Auteur(&Disponible, &En_Reparation, code);
            printf("Press Any To Continue.....");
            getch();
            return book_management() ;
            break;
        case 8:
            printf("Entrez l'année pour afficher les livres: ");
            scanf("%d", &annee);
            Afficher_Livres_Par_Annee(annee);
            printf("Press Any To Continue.....");
            getch();
            return book_management() ;
            break;
        case 9:
             rootMenu();
        case 10:
            printf("Fin du programme.\n");
            exit(0);

    }
}


void abonne_management() {
    Liste_Abonne listeAbonnes;
    initialiser_liste_abonne(&listeAbonnes);
    chargerAbonnesDepuisFichier(&listeAbonnes);

    system("cls");
    box(23, 4, 71, 26);
    h_line(23, 6, 71);
    box(23, 26, 71, 2);
    gotoxy(52, 5);
    printf("Gestion des Abonnés");

    char items[10][100] = {
        "1. Ajouter un abonné",
        "2. Afficher les abonnés",
        "3. Modifier un abonné",
        "4. Supprimer un abonné",
        "5. Retour au menu principal",
        "6. Quitter"
    };

    gotoxy(25, 27);
    printf("Utilisez les flèches Haut/Bas pour la navigation.");

    int choix;
    int identifiant, codeLivre;
    Abonne abonne;

    choix = selector(26, 8, 20, items);

    system("cls");
    switch (choix) {
        case 1:
            Saisir_Abonne(&abonne);
            AjoutAbonne(&listeAbonnes, abonne);
             printf("Press Any To Continue.....");
            getch();
            return abonne_management() ;
            break;
        case 2:
            Afficher_liste_Abonne(listeAbonnes);
             printf("Press Any To Continue.....");
            getch();
            return abonne_management() ;
            break;
        case 3:
            printf("Entrez l'identifiant de l'abonné à modifier: ");
            scanf("%d", &identifiant);
            Modifier_Abonne(&listeAbonnes, identifiant);
             printf("Press Any To Continue.....");
            getch();
            return abonne_management() ;
            break;
        case 4:
            printf("Entrez l'identifiant de l'abonné à supprimer: ");
            scanf("%d", &identifiant);
            Supprimer_Abonne(&listeAbonnes, identifiant);
            break;
             printf("Press Any To Continue.....");
            getch();
            return abonne_management() ;
            case 5 :
            rootMenu();
            break;
        case 6:
            printf("Fin du programme.\n");
            exit(0);
            break;

    }

}


void userMenu() {
    // Placeholder function for the user menu functionality
    printf("Welcome to User Menu\n");
}

void rootMenu() {
    system("cls");
    system("color 6");
    char ch;
    box(6, 1, 105, 2);
    textcolor(3);
    box(23, 4, 71, 4);
    gotoxy(33, 5);
    printf("Current Date     :     ");
    gotoxy(33, 7);
    printf("Current Time     :     ");
    textcolor(6);
    box(23, 9, 71, 14);
    h_line(23, 11, 71);
    h_line(23, 21, 71);
    gotoxy(47, 2);
    printf("Welcome To Tesnime's Library");
    gotoxy(54, 10);
    printf("Root Menu");
    char items[4][100] = {"1. Book Management", "2. subscriber management", "3. Settings", "4. Close Application"};
    gotoxy(25, 22);
    printf("Use Up/Down Arrows keys for Navigation.");
     int s = menu_selector(26, 13, 19, items);
    switch (s)
    {
    case 1:
        return book_management();
        break;
    case 2:
        return abonne_management();
        break;
    case 3:
        return settings();
        break;
    case 4:
        getch();
        break;
    }
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


void main()
{
    SetConsoleTitle("LIBRARY MANAGEMENT SYSTEM BY TESNIME");
    system("cls");
    system("color 9");
    splash_s(24, 5, 71, 20);
    password(30, 15);
    loader(29, 20, 54);
    
}

