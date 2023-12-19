#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
//l'initialisation d'une liste des livres
void initialiser_liste_Livre(Liste_Livre*L)
{L->tete=NULL;}

void saisir_livre(Livre *L) {
    printf("Saisir le titre du Livre:\n");
    scanf("%s", L->Titre);
    while (!validTitle(L->Titre)) {
        printf("Titre invalide ou déjà existant. Réessayez:\n");
        scanf("%s", L->Titre);
    }

    int inputStatus;
    printf("Saisir son code:\n");
    inputStatus = scanf("%d", &L->Code);
    while (!validCode(L->Code) || inputStatus != 1) {
        while(getchar() != '\n'); // Clear the input buffer
        printf("Code invalide ou déjà existant. Réessayez:\n");
        inputStatus = scanf("%d", &L->Code);
    }

    printf("Saisir le nom de son auteur:\n");
    scanf("%29s", L->Auteur);
    while (!validName(L->Auteur)) {
        printf("Nom d'auteur invalide. Réessayez:\n");
        scanf("%s", L->Auteur);
    }

    int inp;
    printf("Saisir son Annee de publication:\n");
    inp = scanf("%d", &L->Annee_Publication.annee);
    while (!validYear(L->Annee_Publication.annee) || inp != 1) {
        while(getchar() != '\n'); // Clear the input buffer
        printf("Année de publication invalide. Réessayez:\n");
        inp = scanf("%d", &L->Annee_Publication.annee);
    }

    printf("Donnez l'etat (0: , 1: DISPONIBLE, 2: EN_REPARATION):\n");
    scanf("%d", &L->Etat);
    while (!validState(L->Etat)) {
        printf("État invalide. Réessayez:\n");
        scanf("%d", &L->Etat);
    }
    // Write the book to books.txt
    FILE *file = fopen("books.txt", "a+");
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

void chargerLivresDepuisFichier(Liste_Livre *Disponible, Liste_Livre *En_Reparation) {
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    Livre tempLivre;
    while (fscanf(file, "%d,%[^,],%[^,],%d,%d\n", &tempLivre.Code, tempLivre.Titre, tempLivre.Auteur, &tempLivre.Annee_Publication.annee, &tempLivre.Etat) == 5) {
        switch (tempLivre.Etat) {
            case 0: // DISPONIBLE
                Ajouter_Livre_list(Disponible, tempLivre);
                break;
            case 1: // EN_REPARATION
                Ajouter_Livre_list(En_Reparation, tempLivre);
                break;
        }
    }
    fclose(file);
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
Noeud *chercher_Liste(Liste_Livre l, int code) {
    // First, try finding the book in the in-memory list
    Noeud *current = l.tete;
    while (current != NULL) {
        if (current->valeur.Code == code) {
            return current;  // Book found in the list
        }
        current = current->suivant;
    }

    // If not found in the list, check the books.txt file
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return NULL;
    }

    Livre tempLivre;
    while (fscanf(file, "%d,%[^,],%[^,],%d,%d\n", &tempLivre.Code, tempLivre.Titre, tempLivre.Auteur, &tempLivre.Annee_Publication.annee, &tempLivre.Etat) == 5) {
        if (tempLivre.Code == code) {
            fclose(file);
            Noeud *newNode = malloc(sizeof(Noeud));
            newNode->valeur = tempLivre;
            newNode->suivant = NULL;
            return newNode;  // Return a new node with the book details
        }
    }

    fclose(file);
    return NULL;  // Book not found in the file either
}

int chercher_Livre_Dans_Fichier(Livre *L, int code) {
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 0;
    }

    int found = 0;
    while (fscanf(file, "%d,%[^,],%[^,],%d,%d\n", &L->Code, L->Titre, L->Auteur, &L->Annee_Publication.annee, &L->Etat) == 5) {
        if (L->Code == code) {
            found = 1;
            break;
        }
    }

    fclose(file);
    return found;
}
void Afficher_Livre(int code) {
    Livre L;
    if (chercher_Livre_Dans_Fichier(&L, code)) {
        printf("\nInformations sur le livre:\n");
        printf("Code: %d\n", L.Code);
        printf("Titre: %s\n", L.Titre);
        printf("Auteur: %s\n", L.Auteur);
        printf("Annee de Publication: %d\n", L.Annee_Publication.annee);
        printf("Etat: ");

        switch (L.Etat) {
            case DISPONIBLE:
                printf("Disponible\n");
                break;
            case EN_REPARATION:
                printf("En Reparation\n");
                break;
            default:
                printf("Etat Inconnu\n");
                break;
        }
    } else {
        printf("Livre avec le code %d non trouvé dans le fichier.\n", code);
    }
}

int Chercher_Livre(Liste_Livre Disponible, Liste_Livre En_Reparation, int code) {
    // Search in Disponible
    if (chercher_Liste(Disponible, code) != NULL) return 1; // Found in Available

    // Search in En_Reparation
    if (chercher_Liste(En_Reparation, code) != NULL) return 3; // Found in Under Repair

    return 0; // Not found
}


Noeud *Recherche_livre(Liste_Livre Disponible, Liste_Livre En_Reparation, int code) {
    Noeud *foundNode;

    // Search in the 'Disponible' list
    foundNode = chercher_Liste(Disponible, code);
    if (foundNode != NULL) return foundNode; // Book found in the available list

    // Search in the 'En_Reparation' list
    foundNode = chercher_Liste(En_Reparation, code);
    return foundNode; // Return the found node or NULL if not found in any list
}

void Modifier_Annee_publication(Liste_Livre *Disponible, Liste_Livre *En_Reparation, int code) {
    // Search for the book in the lists
    Noeud *bookNode = Recherche_livre(*Disponible,*En_Reparation, code);

    // Open the original and temporary files
    FILE *file = fopen("books.txt", "r");
    FILE *tempFile = fopen("temp_books.txt", "w");
    Livre tempLivre;

    // Check if the book was found and if files are opened successfully
    if (bookNode != NULL && file != NULL && tempFile != NULL) {
        int newYear;
        printf("Enter new publication year: ");
        scanf("%d", &newYear);  // Get new publication year from user

        // Read from "books.txt" and write to "temp_books.txt"
        while (fscanf(file, "%d,%[^,],%[^,],%d,%d\n", &tempLivre.Code, tempLivre.Titre, tempLivre.Auteur, &tempLivre.Annee_Publication.annee, &tempLivre.Etat) == 5) {
            // Check if the current book is the one to update
            if (tempLivre.Code == code && validYear(newYear)) {
                tempLivre.Annee_Publication.annee = newYear;  // Update the publication year
            }
            // Write the (updated) book information to the temporary file
            fprintf(tempFile, "%d,%s,%s,%d,%d\n", tempLivre.Code, tempLivre.Titre, tempLivre.Auteur, tempLivre.Annee_Publication.annee, tempLivre.Etat);
        }

        // Close both files after reading and writing
        fclose(file);
        fclose(tempFile);

        // Now copy the contents of the updated temporary file back to the original file
        file = fopen("books.txt", "w");
        tempFile = fopen("temp_books.txt", "r");
        char ch;
        while ((ch = fgetc(tempFile)) != EOF) {
            fputc(ch, file);  // Copy character by character
        }
        // Close the files after copying
        fclose(file);
        fclose(tempFile);
        printf("Publication year updated successfully.\n");
    } else {
        // Error handling if book not found or file operation failed
        printf("Error updating publication year.\n");
        if (file) fclose(file);
        if (tempFile) fclose(tempFile);
    }
}

void Modifier_Titre(Liste_Livre *Disponible, Liste_Livre *, Liste_Livre *En_Reparation, int code) {
    // Search for the book in the lists
    Noeud *bookNode = Recherche_livre(*Disponible, *, *En_Reparation, code);

    // Open the original and temporary files
    FILE *file = fopen("books.txt", "r");
    FILE *tempFile = fopen("temp_books.txt", "w");
    Livre tempLivre;

    // Check if the book was found and if files are opened successfully
    if (bookNode != NULL && file != NULL && tempFile != NULL) {
        char newTitle[TAILLE_CHAINE];
        printf("Enter new title: ");
        scanf("%s", newTitle);  // Get new title from user

        // Read from "books.txt" and write to "temp_books.txt"
        while (fscanf(file, "%d,%[^,],%[^,],%d,%d\n", &tempLivre.Code, tempLivre.Titre, tempLivre.Auteur, &tempLivre.Annee_Publication.annee, &tempLivre.Etat) == 5) {
            // Check if the current book is the one to update
            if (tempLivre.Code == code) {
                strcpy(tempLivre.Titre, newTitle);  // Update the title
            }
            // Write the (updated) book information to the temporary file
            fprintf(tempFile, "%d,%s,%s,%d,%d\n", tempLivre.Code, tempLivre.Titre, tempLivre.Auteur, tempLivre.Annee_Publication.annee, tempLivre.Etat);
        }

        // Close both files after reading and writing
        fclose(file);
        fclose(tempFile);

        // Now copy the contents of the updated temporary file back to the original file
        file = fopen("books.txt", "w");
        tempFile = fopen("temp_books.txt", "r");
        char ch;
        while ((ch = fgetc(tempFile)) != EOF) {
            fputc(ch, file);  // Copy character by character
        }
        // Close the files after copying
        fclose(file);
        fclose(tempFile);
        printf("Title updated successfully.\n");
    } else {
        // Error handling if book not found or file operation failed
        printf("Error updating title.\n");
        if (file) fclose(file);
        if (tempFile) fclose(tempFile);
    }
}



void Modifier_Auteur(Liste_Livre *Disponible, Liste_Livre *, Liste_Livre *En_Reparation, int code) {
    // Search for the book in the lists
    Noeud *bookNode = Recherche_livre(*Disponible, *, *En_Reparation, code);

    // Open the original and temporary files
    FILE *file = fopen("books.txt", "r");
    FILE *tempFile = fopen("temp_books.txt", "w");
    Livre tempLivre;

    // Check if the book was found and if files are opened successfully
    if (bookNode != NULL && file != NULL && tempFile != NULL) {
        char newAuthor[TAILLE_CHAINE];
        printf("Enter new author name: ");
        scanf("%s", newAuthor);  // Get new author name from user

        // Read from "books.txt" and write to "temp_books.txt"
        while (fscanf(file, "%d,%[^,],%[^,],%d,%d\n", &tempLivre.Code, tempLivre.Titre, tempLivre.Auteur, &tempLivre.Annee_Publication.annee, &tempLivre.Etat) == 5) {
            // Check if the current book is the one to update
            if (tempLivre.Code == code) {
                strcpy(tempLivre.Auteur, newAuthor);  // Update the author
            }
            // Write the (updated) book information to the temporary file
            fprintf(tempFile, "%d,%s,%s,%d,%d\n", tempLivre.Code, tempLivre.Titre, tempLivre.Auteur, tempLivre.Annee_Publication.annee, tempLivre.Etat);
        }

        // Close both files after reading and writing
        fclose(file);
        fclose(tempFile);

        // Now copy the contents of the updated temporary file back to the original file
        file = fopen("books.txt", "w");
        tempFile = fopen("temp_books.txt", "r");
        char ch;
        while ((ch = fgetc(tempFile)) != EOF) {
            fputc(ch, file);  // Copy character by character
        }
        // Close the files after copying
        fclose(file);
        fclose(tempFile);
        printf("Author updated successfully.\n");
    } else {
        // Error handling if book not found or file operation failed
        printf("Error updating author.\n");
        if (file) fclose(file);
        if (tempFile) fclose(tempFile);
    }
}

void remplire_liste_Disponible(Liste_Livre *Disponible, int n) {
    int i;
    Livre L;

    // No need to set Disponible->tete = NULL here to preserve existing list contents

    for (i = 0; i < n; i++) {
        printf(" Saisie du Livre /%d/\n", i + 1);

        // Get book details from user
        saisir_livre(&L);

        // Check if a book with the same code already exists in the list
        if (chercher_Liste(*Disponible, L.Code) == NULL) {
            // Add the book to the list if it doesn't exist
            Ajouter_Livre_list(Disponible, L);
        } else {
            printf("Un livre avec le code %d existe déjà.\n", L.Code);
        }
    }
}

void Afficher_Livres_Par_Annee(Liste_Livre Disponible, Liste_Livre , Liste_Livre En_Reparation, int anne) {
    Noeud *current;
    int count;

    // Display available books from the specified year
    current = Disponible.tete;
    count = 1;
    printf("La Liste Des Livres Disponibles Parus A L'Annee %d Est :\n", anne);
    if (current == NULL) {
        printf("\t----La Liste Est Vide !!!---\n");
    } else {
        while (current != NULL) {
            if (current->valeur.Annee_Publication.annee == anne) {
                printf("Le Livre Num /%d/ :\n", count);
                Afficher_Livre(current->valeur.Code); // Call Afficher_Livre with the book code
                count++;
            }
            current = current->suivant;
        }
    }
    printf("\n");

    // Display borrowed books from the specified year
    current = .tete;
    count = 1;
    printf("La Liste Des Livres s Parus A L'Annee %d Est :\n", anne);
    if (current == NULL) {
        printf("\t----La Liste Est Vide !!!---\n");
    } else {
        while (current != NULL) {
            if (current->valeur.Annee_Publication.annee == anne) {
                printf("Le Livre Num /%d/ :\n", count);
                Afficher_Livre(current->valeur.Code);
                count++;
            }
            current = current->suivant;
        }
    }
    printf("\n");

    // Display books under repair from the specified year
    current = En_Reparation.tete;
    count = 1;
    printf("La Liste Des Livres En Reparation Parus A L'Annee /%d/ Est :\n\n", anne);
    if (current == NULL) {
        printf("\t----La Liste Est Vide !!!---\n");
    } else {
        while (current != NULL) {
            if (current->valeur.Annee_Publication.annee == anne) {
                printf("Le Livre Num /%d/ :\n", count);
                Afficher_Livre(current->valeur.Code);
                count++;
            }
            current = current->suivant;
        }
    }
    printf("\n");
}


void sauvegarderLivresDansFichier(Liste_Livre *liste) {
    FILE *file = fopen("books.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    Noeud *current = liste->tete;
    while (current != NULL) {
        fprintf(file, "%d, %s, %s, %d\n", current->valeur.Code, current->valeur.Titre, current->valeur.Auteur, current->valeur.Etat);
        current = current->suivant;
    }

    fclose(file);
}
/*int main() {
    Liste_Livre Disponible, , En_Reparation;
    initialiser_liste_Livre(&Disponible);
    initialiser_liste_Livre(&);
    initialiser_liste_Livre(&En_Reparation);

    // Load books from file into the lists at the start
    chargerLivresDepuisFichier(&Disponible, &, &En_Reparation);

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
                if (Chercher_Livre(Disponible, , En_Reparation, code)) {
                    printf("Livre trouvé.\n");
                } else {
                    printf("Livre non trouvé.\n");
                }
                break;
            }
            case 5: {
                printf("Entrez le code du livre pour modifier l'année de publication: ");
                scanf("%d", &code);
                Modifier_Annee_publication(&Disponible, &, &En_Reparation, code);
                break;
            }
            case 6: {
                printf("Entrez le code du livre pour modifier le titre: ");
                scanf("%d", &code);
                Modifier_Titre(&Disponible, &, &En_Reparation, code);
                break;
            }
            case 7: {
                printf("Entrez le code du livre pour modifier l'auteur: ");
                scanf("%d", &code);
                Modifier_Auteur(&Disponible, &, &En_Reparation, code);
                break;
            }
            case 8: {
                int annee;
                printf("Entrez l'année pour afficher les livres: ");
                scanf("%d", &annee);
                Afficher_Livres_Par_Annee(Disponible, , En_Reparation, annee);
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





//fseek : important 
//fprintf : permet d'ecrire dans le file : fprintf(f,"expression",arg1,arg2....) eq tekho ml memoire w t7othom fl fichier 
//fscanf : bch nekho ml fichier w nakra fl variable taii eq nhotohom fl memoire   
//c=fgetc (f) eq taa scanf : bch nakra char ml file  w nhot fl variable 
//fputc(c,f) eq putchar(printf (%c,x)  => t7ot ll variable c fl file 
//gets(s) eq de scanf("%s",s) 
//fgets(s,taille, f)
//
