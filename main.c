#include <stdio.h>
#include <stdlib.h>
#include "abonne.h" // Include your header files for abonne and books
#include "books.h"
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

void main()
{
    SetConsoleTitle("LIBRARY MANAGEMENT SYSTEM BY TESNIME");
    system("cls");
    system("color 9");
    splash_s(24, 5, 71, 20);
    password(30, 15);
    loader(29, 20, 54);
}

