//
// Created by labou on 06/12/2023.
//

#ifndef PROJET_C_UTILITY_H
#define PROJET_C_UTILITY_H

#define TAILLE_CHAINE 30  
extern char*Tab_Etat[2];

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


void hidecursor();
void h_line(int x,int y, int l);
void textcolor(int color);
void gotoxy(int x,int y);
void delay(int mseconds);
void splash_s(int x, int y, int l, int h);
void box(int a, int c,int l,int h);
void loader(int x,int y,int z);
int menu_selector(int x, int y1, int y2, char (*items)[100]);
int validTitle(char *title);
int validCode(int code);
int validName(char *name);
int validYear(int year);
int validState(int state);
int selector(int x, int y1, int y2, char (*items)[100]);

//void sauvegarderAbonnesDansFichier(Liste_Abonne *LAB);
//void chargerAbonnesDepuisFichier(Liste_Abonne *LAB);
#endif //PROJET_C_UTILITY_H
