#include <stdio.h>
#include <stdlib.h>
#include "abonne.h" // Include your header files for abonne and books
#include "books.h"

int main() {
    Liste_Abonne listeAbonnes;
    initialiser_liste_abonne(&listeAbonnes);

    // Load existing subscribers
    chargerAbonnesDepuisFichier(&listeAbonnes);

    Liste_Livre listeDisponible;
    Liste_Livre listeEmprunte;
    Liste_Livre listeEnReparation;

    // Initialize other lists similar to listeAbonnes if needed

    int choix, identifiant, codeLivre;

    while (1) {
        printf("\nMenu de Gestion de Bibliotheque\n");
        printf("1. Ajouter un abonne\n");
        printf("2. Afficher les abonnes\n");
        printf("3. Modifier un abonne\n");
        printf("4. Supprimer un abonne\n");
        //printf("5. Emprunter un livre\n");
        //printf("6. Rendre un livre\n");
        printf("7. Envoyer un livre en reparation\n");
        printf("8. Quitter\n");
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
                Envoyer_Livre_Reparation(&listeDisponible, &listeEmprunte, &listeEnReparation, NULL, codeLivre);  // Pass NULL if Abonne not needed
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
