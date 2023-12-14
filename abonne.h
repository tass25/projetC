#ifndef PROJET_C_ABONNE_H
#define PROJET_C_ABONNE_H


#include "utility.h"

void initialiser_liste_abonne(Liste_Abonne*LAB); //done
void Saisir_Abonne(Abonne *A);//done
void Afficher_Abonne(Abonne A);//done
void AjoutAbonne(Liste_Abonne *LAB,Abonne A);//done
void remplire_liste_Abonne(Liste_Abonne *LAB,int n);//done
void Afficher_liste_Abonne(Liste_Abonne LAB);//done
void Modifier_Abonne(Liste_Abonne *LAB,int x);//done
void Supprimer_Abonne(Liste_Abonne *LAB,int x);//done
Noeud1 *Chercher_Abonne(Liste_Abonne LAB,int ident);//done
void Emprunter_Livre(Liste_Abonne LAB,Liste_Livre *Disponible,Liste_Livre *Emprunte,Liste_Livre* En_Reparation,Abonne *A,int x,int ident);
void Envoyer_Livre_Reparation(Liste_Livre *Disponible,Liste_Livre *Emprunte,Liste_Livre* En_Reparation,Abonne *A,int x);
void Rendre_Livre(Liste_Abonne LAB,Liste_Livre *Disponible,Liste_Livre *Emprunte,Liste_Livre* En_Reparation,Abonne *A,int x,int ident);

#endif //PROJET_C_BOOKS_H
