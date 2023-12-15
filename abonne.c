#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "books.h"
void initialiser_liste_abonne(Liste_Abonne*LAB)
{LAB->tete1=NULL;
}
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

void Saisir_Abonne(Liste_Abonne *LAB, Abonne *A) {
    // Temporary variable to store the name
    char tempName[TAILLE_CHAINE];

    printf("Donnez le Nom de l'Abonne:\n");
    scanf("%29s", tempName); // Read the name with a limit of 29 characters
    while (!validName(tempName)) { // Validate the name
        printf("Nom invalide. Réessayez:\n");
        scanf("%29s", tempName);
    }
    strcpy(A->Nom, tempName); // Copy the valid name to the structure

    int idUnique;
    do {
        printf("Donnez son Identifiant:\n");
        scanf("%d", &A->id); // Read the ID
        while (getchar() != '\n'); // Clear the input buffer

        idUnique = !idExisteDeja(LAB, A->id);
        if (!idUnique) {
            printf("Un abonne avec l'identifiant %d existe deja. Veuillez saisir un autre identifiant.\n", A->id);
        }
    } while (!idUnique);

    A->pointeur = NULL;
}



// Save the current state of subscribers into library.txt
void sauvegarderAbonnesDansFichier(Liste_Abonne *LAB) {
    FILE *file = fopen("library.txt", "w");
    if (file == NULL) {
        perror("Erreur lors de l'écriture du fichier");
        return;
    }
    Noeud1 *current = LAB->tete1;
    while (current != NULL) {
        if (fprintf(file, "%d,%s\n", current->AB.id, current->AB.Nom) < 0) {
            perror("Erreur lors de l'écriture dans le fichier");
            break;
        }
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
    if (!nouveau) {
        perror("Erreur d'allocation mémoire");
        return;
    }
    nouveau->AB = A;
    nouveau->suivant = LAB->tete1;
    LAB->tete1 = nouveau;

    // Update the file
    FILE *file = fopen("library.txt", "a");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        free(nouveau);
        return;
    }
    fprintf(file, "%d,%s\n", A.id, A.Nom);
    fclose(file);
}




// Fill the subscriber list with 'n' new subscribers
void remplire_liste_Abonne(Liste_Abonne *LAB, int n) {
    Abonne A;
    int idAlreadyExists;

    for (int i = 0; i < n; i++) {
        do {
            printf("Saisie de l'Abonne /%d/\n", i + 1);
            Saisir_Abonne(LAB, &A);

            // Check if the ID already exists
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
    Noeud1 *i = LAB.tete1;
    while (i != NULL && i->AB.id != ident) {
        i = i->suivant;
    }
    return i; // Returns NULL if not found
}

// Modify a subscriber's data
void Modifier_Abonne(Liste_Abonne *LAB, int x) {
    Noeud1 *i = Chercher_Abonne(*LAB, x);
    if (i != NULL) {
        printf("Donner le Nouveau Nom de Votre Abonne :\n ");
        scanf("%s", i->AB.Nom);
        sauvegarderAbonnesDansFichier(LAB); // Save changes to the file
    } else {
        printf("L'abonne avec l'identifiant %d n'existe pas.\n", x);
    }
}

// Remove a subscriber from the list
void Supprimer_Abonne(Liste_Abonne *LAB, int x) {
    Noeud1 *current = LAB->tete1, *previous = NULL;
    while (current != NULL && current->AB.id != x) {
        previous = current;
        current = current->suivant;
    }
    if (current != NULL) {
        if (previous == NULL) {
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
void handleBookBorrowing(Liste_Livre *Disponible, Liste_Livre *Emprunte, int bookCode) {
    // Check if the book is in the 'Disponible' list
    Noeud *bookNode = chercher_Liste(*Disponible, bookCode);
    
    if (!bookNode) {
        printf("Livre non disponible.\n");
        return;
    }

    // Update the book status to EMPRUNTE and add it to the 'Emprunte' list
    Livre borrowedBook = bookNode->valeur;
    borrowedBook.Etat = EMPRUNTE;
    Ajouter_Livre_list(Emprunte, borrowedBook);
    
    // Remove the book from the 'Disponible' list
    Supprimer_Livre(Disponible, bookCode);

    // Save the updated book lists
    sauvegarderLivresDansFichier(Disponible);
    sauvegarderLivresDansFichier(Emprunte);
}



// Borrow a book
void Emprunter_Livre(Liste_Abonne LAB, Liste_Livre *Disponible, Liste_Livre *Emprunte, int bookCode, int ident) {
    Noeud1 *abonneNode = Chercher_Abonne(LAB, ident);
    Noeud *livreNode = chercher_Liste(*Disponible, bookCode);

    if (!abonneNode || !livreNode || abonneNode->AB.pointeur != NULL) {
        printf("Abonne non disponible ou a deja un livre.\n");
        return;
    }

    // Mettre à jour le pointeur du livre de l'abonné
    abonneNode->AB.pointeur = &livreNode->valeur;

    // Déplacer le livre de la liste Disponible à Emprunte
    handleBookBorrowing(Disponible, Emprunte, bookCode);

    // Enregistrez les modifications
    sauvegarderAbonnesDansFichier(&LAB);
}


void sauvegarderEtatDesLivres(Liste_Livre *Disponible, Liste_Livre *Emprunte, Liste_Livre *En_Reparation) {
    FILE *file = fopen("books.txt", "w");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    // Save 'Disponible' list
    Noeud *current = Disponible->tete;
    while (current != NULL) {
        fprintf(file, "%d,%s,%s,%d,%d\n", current->valeur.Code, current->valeur.Titre, current->valeur.Auteur, current->valeur.Annee_Publication.annee, DISPONIBLE);
        current = current->suivant;
    }

    // Save 'Emprunte' list
    current = Emprunte->tete;
    while (current != NULL) {
        fprintf(file, "%d,%s,%s,%d,%d\n", current->valeur.Code, current->valeur.Titre, current->valeur.Auteur, current->valeur.Annee_Publication.annee, EMPRUNTE);
        current = current->suivant;
    }

    // Save 'En_Reparation' list
    current = En_Reparation->tete;
    while (current != NULL) {
        fprintf(file, "%d,%s,%s,%d,%d\n", current->valeur.Code, current->valeur.Titre, current->valeur.Auteur, current->valeur.Annee_Publication.annee, EN_REPARATION);
        current = current->suivant;
    }

    fclose(file);
}



// Send a book for repair
void Envoyer_Livre_Reparation(Liste_Livre *Disponible, Liste_Livre *Emprunte, Liste_Livre* En_Reparation, Abonne *A, int x) {
    Noeud *book_node = Recherche_livre(*Disponible, *Emprunte, *En_Reparation, x);
    if (book_node == NULL) {
        printf("\t----Livre introuvable.---\n");
        return;
    }

    if (book_node->valeur.Etat == EN_REPARATION) {
        printf("\t----Ce livre est déjà en réparation.---\n");
        return;
    }

    // Move the book to 'En_Reparation' and update its state
    Supprimer_Livre(Disponible, book_node->valeur.Code);
    Supprimer_Livre(Emprunte, book_node->valeur.Code);
    book_node->valeur.Etat = EN_REPARATION;
    Ajouter_Livre_list(En_Reparation, book_node->valeur);
    if (A && A->pointeur == &book_node->valeur) {
        A->pointeur = NULL;
    }

    // Save changes to the files
    sauvegarderEtatDesLivres(Disponible, Emprunte, En_Reparation);
}

// Return a book
void Rendre_Livre(Liste_Abonne LAB, Liste_Livre *Disponible, Liste_Livre *Emprunte, Liste_Livre* En_Reparation, Abonne *A, int x, int ident) {
    Noeud *book_node = Recherche_livre(*Disponible, *Emprunte, *En_Reparation, x);
    Noeud1 *subscriber_node = Chercher_Abonne(LAB, ident);
    if (book_node == NULL || subscriber_node == NULL) {
        printf("\t----Livre ou abonné introuvable.---\n");
        return;
    }

    if (book_node->valeur.Etat != EMPRUNTE) {
        printf("\t----Ce livre n'a pas été emprunté.---\n");
        return;
    }

    // Update the book's state and the subscriber's borrowed book pointer
    book_node->valeur.Etat = DISPONIBLE;
    subscriber_node->AB.pointeur = NULL;

    // Move the book from 'Emprunte' to 'Disponible'
    Supprimer_Livre(Emprunte, book_node->valeur.Code);
    Ajouter_Livre_list(Disponible, book_node->valeur);

    // Save changes to the files
    sauvegarderEtatDesLivres(Disponible, Emprunte, En_Reparation);
}



