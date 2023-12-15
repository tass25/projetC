#include "abonne.h"  // Include the header file for abonne.c
#include "books.h"   // Include the header file for books.c if necessary
#include<stdio.h>
int main() {
    // Initializations
    Liste_Abonne listeAbonnes;
    Liste_Livre listeDisponible, listeEmprunte, listeEnReparation;

    initialiser_liste_abonne(&listeAbonnes);
    initialiser_liste_Livre(&listeDisponible);  // Assuming these functions are defined in books.c
    initialiser_liste_Livre(&listeEmprunte);
    initialiser_liste_Livre(&listeEnReparation);

    int choix;
    int identifiant;  // For storing subscriber ID
    int bookCode;     // For storing book code

    do {
        printf("\n---- Menu de Test ----\n");
        printf("1. Ajouter un abonne\n");
        printf("2. Afficher les abonnes\n");
        printf("3. Modifier un abonne\n");
        printf("4. Supprimer un abonne\n");
        printf("5. Emprunter un livre\n");
        printf("6. Rendre un livre\n");
        printf("7. Envoyer un livre en reparation\n");
        printf("8. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

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
                printf("Entrez l'identifiant de l'abonne: ");
                scanf("%d", &identifiant);
                printf("Entrez le code du livre a emprunter: ");
                scanf("%d", &bookCode);
                Emprunter_Livre(listeAbonnes, &listeDisponible, &listeEmprunte, &listeEnReparation, NULL, bookCode, identifiant);
                break;
            }
            case 6: {
                printf("Entrez l'identifiant de l'abonne: ");
                scanf("%d", &identifiant);
                printf("Entrez le code du livre a rendre: ");
                scanf("%d", &bookCode);
                Rendre_Livre(listeAbonnes, &listeDisponible, &listeEmprunte, &listeEnReparation, NULL, bookCode, identifiant);
                break;
            }
            case 7: {
                printf("Entrez le code du livre a envoyer en reparation: ");
                scanf("%d", &bookCode);
                Envoyer_Livre_Reparation(&listeDisponible, &listeEmprunte, &listeEnReparation, NULL, bookCode);
                break;
            }
            case 8: {
                printf("Fin du programme.\n");
                break;
            }
            default: {
                printf("Choix non valide, veuillez réessayer.\n");
                break;
            }
        }
    } while (choix != 8);

    return 0;
}
