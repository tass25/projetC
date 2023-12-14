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








