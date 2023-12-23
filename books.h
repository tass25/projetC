
#ifndef PROJET_C_BOOKS_H
#define PROJET_C_BOOKS_H


#include "utility.h"

void initialiser_liste_Livre(Liste_Livre *L);
void saisir_livre(Livre *L);
void Ajouter_Livre_list(Liste_Livre *l, Livre L);
void Supprimer_Livre(int x) ;
void chargerLivresDepuisFichier(Liste_Livre *Disponible, Liste_Livre *En_Reparation);
Noeud *chercher_Liste(Liste_Livre l, int code);
int chercher_Livre_Dans_Fichier(Livre *L, int code);
void Afficher_Livre(int code);
int Chercher_Livre(Liste_Livre Disponible, Liste_Livre En_Reparation, int code);
Noeud *Recherche_livre(Liste_Livre Disponible, Liste_Livre En_Reparation, int code);
void Modifier_Annee_publication(Liste_Livre *Disponible, Liste_Livre *En_Reparation, int code);
void Modifier_Titre(Liste_Livre *Disponible, Liste_Livre *En_Reparation, int code);
void Modifier_Auteur(Liste_Livre *Disponible, Liste_Livre *En_Reparation, int code);
void remplire_liste_Disponible(Liste_Livre *Disponible, int n);
void Afficher_Livres_Par_Annee(int anne);
void sauvegarderLivresDansFichier(Liste_Livre *liste);
#endif //PROJET_C_BOOKS_H
