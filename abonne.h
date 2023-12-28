#ifndef PROJET_C_ABONNE_H
#define PROJET_C_ABONNE_H


#include "utility.h"

void initialiser_liste_abonne(Liste_Abonne* LAB);//
void Saisir_Abonne(Abonne *A);//
void sauvegarderAbonnesDansFichier(Liste_Abonne *LAB);//
void Afficher_Abonne(Abonne A);//
void AjoutAbonne(Liste_Abonne *LAB, Abonne A);//
void remplire_liste_Abonne(Liste_Abonne *LAB, int n);//
void Afficher_liste_Abonne(Liste_Abonne LAB);//
void Supprimer_Livre_De_Liste(Liste_Livre *l, int x);//
Noeud1 *Chercher_Abonne(Liste_Abonne LAB, int ident);//
void Modifier_Abonne(Liste_Abonne *LAB, int x);//
void Supprimer_Abonne(Liste_Abonne *LAB, int x);//
void Envoyer_Livre_Reparation(Liste_Livre *Disponible, Liste_Livre *En_Reparation, Abonne *A, int x);//
void chargerAbonnesDepuisFichier(Liste_Abonne *LAB);//
int idExisteDeja(Liste_Abonne *LAB, int id); //


#endif //PROJET_C_BOOKS_H
