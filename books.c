#include "books.h"
#include <stdio.h>
#include<stdlib.h>
    

//l'initialisation d'une liste des livres
void initialiser_liste_Livre(Liste_Livre*L)
{L->tete=NULL;}

void saisir_livre(Livre *L) {
    printf("Saisir le titre du Livre:\n");
    scanf("s", L->Titre);
    while (!validTitle(L->Titre)) {
        printf("Titre invalide ou déjà existant. Réessayez:\n");
        scanf("s", L->Titre);
    }

    printf("Saisir son code:\n");
    scanf("%d", &L->Code);
    while (!validCode(L->Code)) {
        printf("Code invalide ou déjà existant. Réessayez:\n");
        scanf("%d", &L->Code);
    }

    printf("Saisir le nom de son auteur:\n");
    scanf("%29s", L->Auteur);
    while (!validName(L->Auteur)) {
        printf("Nom d'auteur invalide. Réessayez:\n");
        scanf("s", L->Auteur);
    }

    printf("Saisir son Annee de publication:\n");
    scanf("%d", &L->Annee_Publication.annee);
    while (!validYear(L->Annee_Publication.annee)) {
        printf("Année de publication invalide. Réessayez:\n");
        scanf("%d", &L->Annee_Publication.annee);
    }

    printf("Donnez l'etat (0: EMPRUNTE, 1: DISPONIBLE, 2: EN_REPARATION):\n");
    scanf("%d", &L->Etat);
    while (!validState(L->Etat)) {
        printf("État invalide. Réessayez:\n");
        scanf("%d", &L->Etat);
    }
    // Write the book to books.txt
    FILE *file = fopen("books.txt", "a");
    if (file != NULL) {
        fprintf(file, "%d,%s,%s,%d,%d\n", L->Code, L->Titre, L->Auteur, L->Annee_Publication.annee, L->Etat);
        fclose(file);
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
}


//another function , another doumou3 , ekhtiyaraty mdamara hayaty :) 

void Ajouter_Livre_list(Liste_Livre *l, Livre L) {
    Noeud *nouveau = (Noeud *)malloc(sizeof(Noeud));
    nouveau->valeur = L;
    nouveau->suivant = NULL;

    if (l->tete == NULL) {
        l->tete = nouveau;
    } else {
        Noeud *current = l->tete;
        while (current->suivant != NULL) {
            current = current->suivant;
        }
        current->suivant = nouveau;
    }
}

//tir flaynnnnn 
void Supprimer_Livre(Liste_Livre *l, int x) {
    Noeud *current = l->tete, *previous = NULL;
    while (current != NULL && current->valeur.Code != x) {
        previous = current;
        current = current->suivant;
    }

    if (current == NULL) {
        printf("Livre non trouvé.\n");
        return;
    }

    if (previous == NULL) {
        l->tete = current->suivant;
    } else {
        previous->suivant = current->suivant;
    }
    free(current);

    // Use temp_books.txt for transaction
    FILE *file = fopen("books.txt", "r");
    FILE *tempFile = fopen("temp_books.txt", "w");
    if (file == NULL || tempFile == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    Livre tempLivre;
    while (fscanf(file, "%d,%[^,],%[^,],%d,%d\n", &tempLivre.Code, tempLivre.Titre, tempLivre.Auteur, &tempLivre.Annee_Publication.annee, &tempLivre.Etat) == 5) {
        if (tempLivre.Code != x) {
            fprintf(tempFile, "%d,%s,%s,%d,%d\n", tempLivre.Code, tempLivre.Titre, tempLivre.Auteur, tempLivre.Annee_Publication.annee, tempLivre.Etat);
        }
    }

    fclose(file);
    fclose(tempFile);

    // Now update books.txt from temp_books.txt
    file = fopen("books.txt", "w");
    tempFile = fopen("temp_books.txt", "r");
    if (file == NULL || tempFile == NULL) {
        printf("Erreur lors de la synchronisation des fichiers.\n");
        return;
    }

    while (fscanf(tempFile, "%d,%[^,],%[^,],%d,%d\n", &tempLivre.Code, tempLivre.Titre, tempLivre.Auteur, &tempLivre.Annee_Publication.annee, &tempLivre.Etat) == 5) {
        fprintf(file, "%d,%s,%s,%d,%d\n", tempLivre.Code, tempLivre.Titre, tempLivre.Auteur, tempLivre.Annee_Publication.annee, tempLivre.Etat);
    }

    fclose(file);
    fclose(tempFile);
}
