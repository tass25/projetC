//
// Created by labou on 06/12/2023.
//

#ifndef PROJET_C_UTILITY_H
#define PROJET_C_UTILITY_H

#define TAILLE_CHAINE 30  // Assuming this is a constant used across your program for string sizes
char*Tab_Etat[3]={"EMPRUNTE"," DISPONIBLE","EN_REPARATION"};

// Commonly used state definitions for books
#define EMPRUNTE 0
#define DISPONIBLE 1
#define EN_REPARATION 2

// Definition of a Date structure
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

// Definition of a Livre (Book) structure
typedef struct {
    int Code;
    char Titre[TAILLE_CHAINE];
    char Auteur[TAILLE_CHAINE];
    Date Annee_Publication;
    int Etat;
} Livre;

// Definition of an Abonne (Subscriber) structure
typedef struct {
    char Nom[TAILLE_CHAINE];
    int id;
    Livre *pointeur;
} Abonne;

// Node structure for a linked list of Livre
typedef struct N {
    Livre valeur;
    struct N *suivant;
} Noeud;

// Node structure for a linked list of Abonne
typedef struct N1 {
    Abonne AB;
    struct N1 *suivant;
} Noeud1;

// Structure for a list of Livre
typedef struct {
    Noeud *tete;
} Liste_Livre;

// Structure for a list of Abonne
typedef struct {
    Noeud1 *tete1;
} Liste_Abonne;

// You can also add common utility functions here if needed
// Example: Function to validate date input
int validateDate(int jour, int mois, int annee);


#endif //PROJET_C_UTILITY_H
