#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.c"

void initialiser_liste_abonne(Liste_Abonne*LAB)
{LAB->tete1=NULL;
}

void chargerAbonnesDepuisFichier(Liste_Abonne *LAB) {
    FILE *file = fopen("library.txt", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    Abonne tempAbonne;
    while (fscanf(file, "%d,%[^\n]\n", &tempAbonne.id, tempAbonne.Nom) == 2) {
        tempAbonne.pointeur = NULL; // Assuming no book is borrowed initially
        AjoutAbonne(LAB, tempAbonne);
    }

    fclose(file);
}
