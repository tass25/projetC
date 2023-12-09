
#ifndef PROJET_C_BOOKS_H
#define PROJET_C_BOOKS_H


#include "utility.h"

void initialiser_liste_Livre(Liste_Livre *L);           //done
void saisir_livre(Livre *L);                           //done
void Ajouter_Livre_list(Liste_Livre *l, Livre L);     //done
Noeud *chercher_Liste(Liste_Livre l, int code);      //done
void Afficher_Livre(int code);                      // done
int chercher_Livre_Dans_Fichier(Livre *L, int code); //done
int Chercher_Livre(Liste_Livre Disponible, Liste_Livre Emprunte, Liste_Livre En_Reparation, int code);//done
Noeud *Recherche_livre(Liste_Livre Disponible, Liste_Livre Emprunte, Liste_Livre En_Reparation, int code);//done
void Modifier_Annee_publication(Liste_Livre *Disponible, Liste_Livre *Emprunte, Liste_Livre *En_Reparation, int xx);//done
void Modifier_Titre(Liste_Livre *Disponible, Liste_Livre *Emprunte, Liste_Livre *En_Reparation, int xx);//done
void Modifier_Auteur(Liste_Livre *Disponible, Liste_Livre *Emprunte, Liste_Livre *En_Reparation, int xx);//done
void remplire_liste_Disponible(Liste_Livre *Disponible, int n); //done
void Afficher_Livre_Par_Annee(Liste_Livre Disponible, Liste_Livre Emprunte, Liste_Livre En_Reparation, int anne);
void Supprimer_Livre(Liste_Livre *l, int x);           //done


#endif //PROJET_C_BOOKS_H
