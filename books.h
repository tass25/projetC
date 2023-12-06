//
// Created by labou on 06/12/2023.
//

#ifndef PROJET_C_BOOKS_H
#define PROJET_C_BOOKS_H


#include "utility.h"  // Include this if it contains common structures like Livre, Date, etc.

void initialiser_liste_Livre(Liste_Livre *L);
void saisir_livre(Livre *L);
void Ajouter_Livre_list(Liste_Livre *l, Livre L);
Noeud *chercher_Liste(Liste_Livre l, int code);
void Afficher_Livre(Livre L);
int Chercher_Livre(Liste_Livre Disponible, Liste_Livre Emprunte, Liste_Livre En_Reparation, int x);
Noeud *Recherche_livre(Liste_Livre Disponible, Liste_Livre Emprunte, Liste_Livre En_Reparation, int code);
void Modifier_Annee_publication(Liste_Livre *Disponible, Liste_Livre *Emprunte, Liste_Livre *En_Reparation, int xx);
void Modifier_Titre(Liste_Livre *Disponible, Liste_Livre *Emprunte, Liste_Livre *En_Reparation, int xx);
void Modifier_Auteur(Liste_Livre *Disponible, Liste_Livre *Emprunte, Liste_Livre *En_Reparation, int xx);
void remplire_liste_Disponible(Liste_Livre *Disponible, int n);
void Afficher_Livre_Par_Annee(Liste_Livre Disponible, Liste_Livre Emprunte, Liste_Livre En_Reparation, int anne);
void Supprimer_Livre(Liste_Livre *l, int x);


#endif //PROJET_C_BOOKS_H
