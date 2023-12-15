#ifndef PROJET_C_ABONNE_H
#define PROJET_C_ABONNE_H


#include "utility.h"

void initialiser_liste_abonne(Liste_Abonne* LAB);
void Saisir_Abonne(Abonne *A);
void sauvegarderAbonnesDansFichier(Liste_Abonne *LAB);
void Afficher_Abonne(Abonne A);
void AjoutAbonne(Liste_Abonne *LAB, Abonne A);
void remplire_liste_Abonne(Liste_Abonne *LAB, int n);
void Afficher_liste_Abonne(Liste_Abonne LAB);
Noeud1 *Chercher_Abonne(Liste_Abonne LAB, int ident);
void Modifier_Abonne(Liste_Abonne *LAB, int x);
void Supprimer_Abonne(Liste_Abonne *LAB, int x);
void handleBookBorrowing(Liste_Livre *Disponible, Liste_Livre *Emprunte, int bookCode);
void Emprunter_Livre(Liste_Abonne LAB, Liste_Livre *Disponible, Liste_Livre *Emprunte, Liste_Livre *En_Reparation, Abonne *A, int bookCode, int ident);
void sauvegarderEtatDesLivres(Liste_Livre *Disponible, Liste_Livre *Emprunte, Liste_Livre *En_Reparation);
void Envoyer_Livre_Reparation(Liste_Livre *Disponible, Liste_Livre *Emprunte, Liste_Livre *En_Reparation, Abonne *A, int x);
void Rendre_Livre(Liste_Abonne LAB, Liste_Livre *Disponible, Liste_Livre *Emprunte, Liste_Livre *En_Reparation, Abonne *A, int x, int ident);




#endif //PROJET_C_BOOKS_H
