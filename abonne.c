#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.c"

void initialiser_liste_abonne(Liste_Abonne*LAB)
{LAB->tete1=NULL;
}
// Input a subscriber's data
void Saisir_Abonne(Abonne *A) {
    printf("Donnez le Nom de l'Abonne:\n");
    scanf("%s", A->Nom);
    printf("Donnez son Identifiant\n");
    scanf("%d", &A->id);
    A->pointeur = NULL;
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
    Noeud1 *nouveau = malloc(sizeof(Noeud1));
    nouveau->AB = A;
    nouveau->suivant = NULL;
    if (LAB->tete1 == NULL) {
        LAB->tete1 = nouveau;
    } else {
        Noeud1 *current = LAB->tete1;
        while (current->suivant != NULL) {
            current = current->suivant;
        }
        current->suivant = nouveau;
    }
    sauvegarderAbonnesDansFichier(LAB); // Save the updated list to the file
}

// Fill the subscriber list with 'n' new subscribers
void remplire_liste_Abonne(Liste_Abonne *LAB, int n) {
    Abonne A;
    for (int i = 0; i < n; i++) {
        printf(" Saisie de l'Abonne /%d/\n", i + 1);
        Saisir_Abonne(&A);
        AjoutAbonne(LAB, A);
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

// Search for a subscriber in the list
Noeud1 *Chercher_Abonne(Liste_Abonne LAB, int ident) {
    Noeud1 *i = LAB.tete1;
    while (i != NULL && i->AB.id != ident) {
        i = i->suivant;
    }
    return i; // Returns NULL if not found
}

// Borrow a book
void Emprunter_Livre(Liste_Abonne LAB, Liste_Livre *Disponible, Liste_Livre *Emprunte, Liste_Livre *En_Reparation, Abonne *A, int x, int ident) {
    Noeud *livreNode;
    Noeud1 *abonneNode;
    int livreFound;

    livreFound = Chercher_Livre(*Disponible, *Emprunte, *En_Reparation, x);
    livreNode = Recherche_livre(*Disponible, *Emprunte, *En_Reparation, x);
    abonneNode = Chercher_Abonne(LAB, ident);

    if (livreFound != 1) {
        printf("\t----Ce Livre n'Existe Pas Dans La Liste DISPONIBLE !!---\n");
    } else if (abonneNode->AB.pointeur != NULL) {
        printf("\t\t\t** L'Abonne a deja un Livre **\n");
    } else {
        livreNode->valeur.Etat = EMPRUNTE; // Assuming 0 is available, 1 is borrowed
        Ajouter_Livre_list(Emprunte, livreNode->valeur);
        Supprimer_Livre(Disponible, livreNode->valeur.Code);
        abonneNode->AB.pointeur = &livreNode->valeur;
        *A = abonneNode->AB;

        // Save the updated lists to the file
        sauvegarderLivresDansFichier(Disponible, "Disponible.txt");
        sauvegarderLivresDansFichier(Emprunte, "Emprunte.txt");
        sauvegarderAbonnesDansFichier(&LAB); // Assuming you have a function to handle saving subscribers
    }
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




