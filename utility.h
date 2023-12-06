//
// Created by labou on 06/12/2023.
//

#ifndef PROJET_C_UTILITY_H
#define PROJET_C_UTILITY_H

#define TAILLE_CHAINE 30  
char*Tab_Etat[3]={"EMPRUNTE"," DISPONIBLE","EN_REPARATION"};

#define EMPRUNTE 0
#define DISPONIBLE 1
#define EN_REPARATION 2
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

// struct du livre
typedef struct {
    int Code;
    char Titre[TAILLE_CHAINE];
    char Auteur[TAILLE_CHAINE];
    Date Annee_Publication;
    int Etat;
} Livre;

// struct des abonne  
typedef struct {
    char Nom[TAILLE_CHAINE];
    int id;
    Livre *pointeur;
} Abonne;

// LL du livre
typedef struct N {
    Livre valeur;
    struct N *suivant;
} Noeud;

// LL des abonés
typedef struct N1 {
    Abonne AB;
    struct N1 *suivant;
} Noeud1;

// liste des livre
typedef struct {
    Noeud *tete;
} Liste_Livre;

//  liste des Abonnes
typedef struct {
    Noeud1 *tete1;
} Liste_Abonne;


int validDate(int jour, int mois, int annee);
int validTitle(char *title) ;
int validCode(int code);// ll code mtaa kol book 
int validName(char *name);// esm ll author 
int validYear(int year) ;//year of publishing 
int validState(int state);//state of livre
void password();

#endif //PROJET_C_UTILITY_H
