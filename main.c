#include <stdio.h>
#include <stdlib.h>
#include "abonne.h" // Include your header files for abonne and books
#include "books.h"
#include "utility.h"
/*
int main() {
    Liste_Abonne listeAbonnes;
    initialiser_liste_abonne(&listeAbonnes);

    // Load existing subscribers
    chargerAbonnesDepuisFichier(&listeAbonnes);

    Liste_Livre listeDisponible;
    Liste_Livre listeEnReparation;

    // Initialize other lists similar to listeAbonnes if needed

    int choix, identifiant, codeLivre;

    while (1) {
        printf("\nMenu de Gestion de Bibliotheque\n");
        printf("1. Ajouter un abonne\n");
        printf("2. Afficher les abonnes\n");
        printf("3. Modifier un abonne\n");
        printf("4. Supprimer un abonne\n");
        printf("5. Envoyer un livre en reparation\n");
        printf("6. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        getchar(); // To consume the newline character after scanf

        switch (choix) {
            case 1: {
                Abonne a;
                Saisir_Abonne(&a);
                AjoutAbonne(&listeAbonnes, a);
                break;
            }
            case 2: {
                Afficher_liste_Abonne(listeAbonnes);
                break;
            }
            case 3: {
                printf("Entrez l'identifiant de l'abonne a modifier: ");
                scanf("%d", &identifiant);
                Modifier_Abonne(&listeAbonnes, identifiant);
                break;
            }
            case 4: {
                printf("Entrez l'identifiant de l'abonne a supprimer: ");
                scanf("%d", &identifiant);
                Supprimer_Abonne(&listeAbonnes, identifiant);
                break;
            }
            
    
            case 5: {
                printf("Entrez le code du livre a envoyer en reparation: ");
                scanf("%d", &codeLivre);
                Envoyer_Livre_Reparation(&listeDisponible, &listeEnReparation, NULL, codeLivre);  // Pass NULL if Abonne not needed
                break;
            }
            case 6: {
                printf("Fin du programme.\n");
                sauvegarderAbonnesDansFichier(&listeAbonnes); // Save current state before exiting
                return 0;
            }
            default: {
                printf("Choix non valide. Veuillez réessayer.\n");
            }
        }
    }

    return 0;
}

int main() {
    Liste_Livre Disponible,En_Reparation;
    initialiser_liste_Livre(&Disponible);
    
    initialiser_liste_Livre(&En_Reparation);

    // Load books from file into the lists at the start
    chargerLivresDepuisFichier(&Disponible, &En_Reparation);

    int choix, code;

    while (1) {
        printf("\nMenu de Gestion de Bibliothèque\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher un livre\n");
        printf("3. Supprimer un livre\n");
        printf("4. Chercher un livre\n");
        printf("5. Modifier l'année de publication\n");
        printf("6. Modifier le titre\n");
        printf("7. Modifier l'auteur\n");
        printf("8. Afficher les livres par année\n");
        printf("9. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: {
                Livre l;
                saisir_livre(&l);
                Ajouter_Livre_list(&Disponible, l); // Assuming new books are always available
                break;
            }
            case 2: {
                printf("Entrez le code du livre à afficher: ");
                scanf("%d", &code);
                Afficher_Livre(code);
                break;
            }
            case 3: {
                printf("Entrez le code du livre à supprimer: ");
                scanf("%d", &code);
                Supprimer_Livre(&Disponible, code); // Assuming the book is in the available list
                break;
            }
            case 4: {
                printf("Entrez le code du livre à chercher: ");
                scanf("%d", &code);
                if (Chercher_Livre(Disponible, En_Reparation, code)) {
                    printf("Livre trouvé.\n");
                } else {
                    printf("Livre non trouvé.\n");
                }
                break;
            }
            case 5: {
                printf("Entrez le code du livre pour modifier l'année de publication: ");
                scanf("%d", &code);
                Modifier_Annee_publication(&Disponible,  &En_Reparation, code);
                break;
            }
            case 6: {
                printf("Entrez le code du livre pour modifier le titre: ");
                scanf("%d", &code);
                Modifier_Titre(&Disponible,  &En_Reparation, code);
                break;
            }
            case 7: {
                printf("Entrez le code du livre pour modifier l'auteur: ");
                scanf("%d", &code);
                Modifier_Auteur(&Disponible,  &En_Reparation, code);
                break;
            }
            case 8: {
                int annee;
                printf("Entrez l'année pour afficher les livres: ");
                scanf("%d", &annee);
                Afficher_Livres_Par_Annee(Disponible,  En_Reparation, annee);
                break;
            }
            case 9: {
                printf("Fin du programme.\n");
                return 0;
            }
            default:
                printf("Choix non valide, veuillez réessayer.\n");
        }
    }

    return 0;
}

*/



#define ENTER 13
#define BKSP 8


void book_management() {
    Liste_Livre Disponible, En_Reparation;
    initialiser_liste_Livre(&Disponible);
    initialiser_liste_Livre(&En_Reparation);
    chargerLivresDepuisFichier(&Disponible, &En_Reparation);

    system("cls");
    box(23, 4, 71, 18);
    h_line(23, 6, 71);
    box(23, 23, 71, 2);
    gotoxy(52, 5);
    printf("Book Management");
    
    char items[9][100] = {
        "1. Ajouter un livre", 
        "2. Afficher un livre", 
        "3. Supprimer un livre",
        "4. Chercher un livre",
        "5. Modifier l'année de publication",
        "6. Modifier le titre",
        "7. Modifier l'auteur",
        "8. Afficher les livres par année",
        "9. Quitter"
    };

    gotoxy(25, 24);
    printf("Use Up/Down Arrows keys for Navigation.");

    int s = selector(26, 8, 20, items);

    int code, annee;
    Livre l;

    switch (s) {
        case 1: 
            saisir_livre(&l);
            Ajouter_Livre_list(&Disponible, l);
            break;
        case 2:
            printf("Entrez le code du livre à afficher: ");
            scanf("%d", &code);
            Afficher_Livre(code);
            break;
        case 3:
            printf("Entrez le code du livre à supprimer: ");
            scanf("%d", &code);
            Supprimer_Livre(&Disponible, code);
            break;
        case 4:
            printf("Entrez le code du livre à chercher: ");
            scanf("%d", &code);
            Chercher_Livre(Disponible, En_Reparation, code) ? printf("Livre trouvé.\n") : printf("Livre non trouvé.\n");
            break;
        case 5:
            printf("Entrez le code du livre pour modifier l'année de publication: ");
            scanf("%d", &code);
            Modifier_Annee_publication(&Disponible, &En_Reparation, code);
            break;
        case 6:
            printf("Entrez le code du livre pour modifier le titre: ");
            scanf("%d", &code);
            Modifier_Titre(&Disponible, &En_Reparation, code);
            break;
        case 7:
            printf("Entrez le code du livre pour modifier l'auteur: ");
            scanf("%d", &code);
            Modifier_Auteur(&Disponible, &En_Reparation, code);
            break;
        case 8:
            printf("Entrez l'année pour afficher les livres: ");
            scanf("%d", &annee);
            Afficher_Livres_Par_Annee(Disponible, En_Reparation, annee);
            break;
        case 9:
            printf("Fin du programme.\n");
            exit(0);
        default:
            printf("Choix non valide, veuillez réessayer.\n");
    }
}


void subscriber_management() {
    Liste_Abonne listeAbonnes;
    initialiser_liste_abonne(&listeAbonnes);
    chargerAbonnesDepuisFichier(&listeAbonnes);

    Liste_Livre listeDisponible, listeEnReparation;
    initialiser_liste_Livre(&listeDisponible);
    initialiser_liste_Livre(&listeEnReparation);

    system("cls");
    box(23, 4, 71, 16);
    h_line(23, 6, 71);
    box(23, 21, 71, 2);
    gotoxy(51, 5);
    printf("Subscriber Management");

    char items[6][100] = {
        "1. Add Subscriber", 
        "2. View Subscribers", 
        "3. Edit Subscriber", 
        "4. Delete Subscriber", 
        "5. Send Book for Repair", 
        "6. Quit"
    };

    gotoxy(25, 22);
    printf("Use Up/Down Arrows keys for Navigation.");
    int s = selector(26, 8, 18, items);

    int identifiant, codeLivre;
    Abonne a;

    switch (s) {
        case 1:
            Saisir_Abonne(&a);
            AjoutAbonne(&listeAbonnes, a);
            break;
        case 2:
            Afficher_liste_Abonne(listeAbonnes);
            break;
        case 3:
            printf("Enter the ID of the subscriber to edit: ");
            scanf("%d", &identifiant);
            Modifier_Abonne(&listeAbonnes, identifiant);
            break;
        case 4:
            printf("Enter the ID of the subscriber to delete: ");
            scanf("%d", &identifiant);
            Supprimer_Abonne(&listeAbonnes, identifiant);
            break;
        case 5:
            printf("Enter the book code to send for repair: ");
            scanf("%d", &codeLivre);
            Envoyer_Livre_Reparation(&listeDisponible, &listeEnReparation, NULL, codeLivre);
            break;
        case 6:
            printf("Exiting the subscriber management...\n");
            return;
        default:
            printf("Invalid choice. Please try again.\n");
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
    char items[4][26] = {"1. Book Management", "2. subscriber management", "3. Settings", "4. Close Application"};
    gotoxy(25, 22);
    printf("Use Up/Down Arrows keys for Navigation.");
     int s = menu_selector(26, 13, 19, items);
    switch (s)
    {
    case 1:
        return book_management();
        break;
    case 2:
        return subscriber_management();
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

