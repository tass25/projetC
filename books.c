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
}
