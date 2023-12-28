#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "books.h"
// Initialise une liste d'abonnés en mettant la tête de la liste à NULL.
void initialiser_liste_abonne(Liste_Abonne*LAB)
{LAB->tete1=NULL;
}
// Vérifie si un identifiant existe déjà dans la liste d'abonnés.
int idExisteDeja(Liste_Abonne *LAB, int id) {
    Noeud1 *current = LAB->tete1;
    while (current != NULL) {
        if (current->AB.id == id) {
            return 1; // ID trouvé
        }
        current = current->suivant;
    }
    return 0; // ID non trouvé
}
// Saisit les informations d'un abonné depuis l'entrée standard.
void Saisir_Abonne(Abonne *A) {
    char tempName[TAILLE_CHAINE];

    // Input and validate the name of the abonné
    printf("Donnez le Nom de l'Abonne:\n");
    scanf("%29s", tempName);  // Read the name with a limit of 29 characters
    while (!validName(tempName)) {  // Validate the name
        printf("Nom invalide. Réessayez:\n");
        scanf("%29s", tempName);
    }
    strcpy(A->Nom, tempName);  // Copy the valid name to the Abonne structure

    // Input the ID of the abonné
    printf("Donnez son Identifiant:\n");
    while (scanf("%d", &A->id) != 1) {  // Validate the ID
        printf("Identifiant invalide. Réessayez:\n");
        while (getchar() != '\n');  // Clear the input buffer
    }

    A->pointeur = NULL;  // Initialize the pointer to NULL
}
//la fonction  prend un pointeur vers une 'Liste_Abonne'.
void sauvegarderAbonnesDansFichier(Liste_Abonne *LAB) {
    FILE *file = fopen("library.txt", "w");
    if (file == NULL) {    // Vérifie si l'ouverture du fichier a échoué. Si oui, affiche une erreur et sort de la fonction.
        perror("Erreur lors de l'écriture du fichier");
        return;
    }    // Initialise 'current' au début de la liste d'abonnés pour parcourir la liste.
    Noeud1 *current = LAB->tete1;
    while (current != NULL) {
        if (fprintf(file, "%d,%s\n", current->AB.id, current->AB.Nom) < 0) {
            perror("Erreur lors de l'écriture dans le fichier");
            break;
        }  // Passe à l'abonné suivant dans la liste.
        current = current->suivant;
    }
    fclose(file);
}

// Display a subscriber's data
void Afficher_Abonne(Abonne A) {
    printf("\t \t____________________________\n");
    printf("\t\tLE NOM :%s\n", A.Nom);
    printf("\t\tL'IDENTIFIANT :%d\n", A.id);
    if (A.pointeur == NULL)
        printf("\t\t\t** Aucun Livre Emprunter **\n");
    else
        printf("\t\t\t** Il a un Livre Emprunte **\n");
    printf("\t\t____________________________\n");
}

// Add a subscriber to the list
void AjoutAbonne(Liste_Abonne *LAB, Abonne A) {
    // Check for existing ID directly in this function
    for (Noeud1 *current = LAB->tete1; current != NULL; current = current->suivant) {
        if (current->AB.id == A.id) {
            printf("Un abonne avec l'identifiant %d existe deja.\n", A.id);
            return; // Exit if ID already exists
        }
    }

    // Proceed with adding the new subscriber
    Noeud1 *nouveau = malloc(sizeof(Noeud1));
    if (!nouveau) {    // Vérifie si l'allocation de mémoire a échoué. Si oui, affiche une erreur et sort de la fonction.
        perror("Erreur d'allocation mémoire");
        return;
    }    // Affecte les données de l'abonné au nouveau noeud.
    nouveau->AB = A;
    nouveau->suivant = LAB->tete1;    // Insère le nouveau noeud au début de la liste.
    LAB->tete1 = nouveau;

    // Update the file using sauvegarderAbonnesDansFichier to maintain consistency
    sauvegarderAbonnesDansFichier(LAB);
}

// Fill the subscriber list with 'n' new subscribers
void remplire_liste_Abonne(Liste_Abonne *LAB, int n) {
    Abonne A;
    int idAlreadyExists;

    for (int i = 0; i < n; i++) {
        do {
            printf("Saisie de l'Abonne /%d/\n", i + 1);
            Saisir_Abonne( &A);

            // Vérifie si l'identifiant existe déjà dans la liste d'abonnés.
            idAlreadyExists = idExisteDeja(LAB, A.id);
            if (idAlreadyExists) {
                printf("Un abonne avec l'identifiant %d existe deja. Veuillez saisir à nouveau.\n", A.id);
            }
        } while (idAlreadyExists); // Loop until a unique ID is entered

        AjoutAbonne(LAB, A); // Add the subscriber only if the ID is unique
    }
}

// Display the entire list of subscribers
void Afficher_liste_Abonne(Liste_Abonne LAB) {
    Noeud1 *i = LAB.tete1;
    if (i == NULL)
        printf("\t  ---La Liste Des Abonnes Est Vide !!---\n");
    else {
        while (i != NULL) {
            Afficher_Abonne(i->AB);
            i = i->suivant;
        }
    }
}

// Search for a subscriber in the list
Noeud1 *Chercher_Abonne(Liste_Abonne LAB, int ident) {
        // Initialise un pointeur 'i' au début de la liste des abonnés.
    Noeud1 *i = LAB.tete1;
    while (i != NULL && i->AB.id != ident) {    // Boucle tant que 'i' n'est pas NULL et que l'identifiant de l'abonné courant n'est pas égal à 'ident'.
        i = i->suivant;
    }
    return i; // Returns NULL if not found
}

// Modify a subscriber's data
void Modifier_Abonne(Liste_Abonne *LAB, int x) {    // Recherche l'abonné avec l'identifiant 'x' dans la liste 'LAB' et stocke le résultat dans 'i'.
    Noeud1 *i = Chercher_Abonne(*LAB, x);
        // Vérifie si l'abonné a été trouvé.
    if (i != NULL) {
        printf("Donner le Nouveau Nom de Votre Abonne :\n ");
        scanf("%s", i->AB.Nom);
        sauvegarderAbonnesDansFichier(LAB); // Save changes to the file
    } else {
        printf("L'abonne avec l'identifiant %d n'existe pas.\n", x);
    }
}

// Remove a subscriber from the list
void Supprimer_Abonne(Liste_Abonne *LAB, int x) {    // 'current' pour parcourir la liste, 'previous' pour garder trace du nœud précédent.
    Noeud1 *current = LAB->tete1, *previous = NULL;
    while (current != NULL && current->AB.id != x) {    // Parcours la liste jusqu'à trouver l'abonné ou atteindre la fin de la liste.
        previous = current;
        current = current->suivant;
    }    // Vérifie si l'abonné a été trouvé.
    if (current != NULL) {// Si trouvé, le retire de la liste.
        if (previous == NULL) {// Cas où l'abonné est en tête de liste.
            LAB->tete1 = current->suivant;
        } else {
            previous->suivant = current->suivant;
        }
        free(current);
        sauvegarderAbonnesDansFichier(LAB); // Save changes to the file
    } else {
        printf("L'abonne avec l'identifiant %d n'existe pas.\n", x);
    }
}
void Supprimer_Livre_De_Liste(Liste_Livre *l, int x) {
    Noeud *current = l->tete, *previous = NULL;    // 'current' pour parcourir la liste, 'previous' pour le nœud précédent.
    while (current != NULL && current->valeur.Code != x) {    // Cherche le livre avec le code 'x' dans la liste.
        previous = current;
        current = current->suivant;
    }

    if (current == NULL) return; // Book not found in the list

    if (previous == NULL) {// Si le livre est en tête de liste.
        l->tete = current->suivant;
    } else {
        previous->suivant = current->suivant;
    }
    free(current);
}

// Send a book for repair
void Envoyer_Livre_Reparation(Liste_Livre *Disponible, Liste_Livre *En_Reparation, Abonne *A, int x) {
    Noeud *book_node = Recherche_livre(*Disponible, *En_Reparation, x); // Search in 'Disponible' list
    if (book_node == NULL) {
        printf("\t----Livre introuvable.---\n");
        return;
    }

    if (book_node->valeur.Etat == EN_REPARATION) {
        printf("\t----Ce livre est déjà en réparation.---\n");
        return;
    }

    // Update the book's state
    book_node->valeur.Etat = EN_REPARATION;

    // Add the updated book to 'En_Reparation' list
    Ajouter_Livre_list(En_Reparation, book_node->valeur);

    // Nullify the pointer if the book is associated with an Abonne
    if (A && A->pointeur == &book_node->valeur) {
        A->pointeur = NULL;
    }

    // Remove the book from 'Disponible' list
    Supprimer_Livre_De_Liste(Disponible, x);

    // Update the file to reflect the changes
    Supprimer_Livre(x); // Assuming this updates the file directly
}


void chargerAbonnesDepuisFichier(Liste_Abonne *LAB) {
    FILE *file = fopen("library.txt", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    Abonne temp;
    while (fscanf(file, "%d,%29s", &temp.id, temp.Nom) == 2) {
        temp.pointeur = NULL; // Assuming no borrowed book info is stored
        if (!idExisteDeja(LAB, temp.id)) { // Ajoute uniquement si l'ID n'existe pas déjà
            AjoutAbonne(LAB, temp);
        }
    }
    fclose(file);
}



