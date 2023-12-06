#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define TAILLE_CHAINE 30
#define EMPRUNTE 0
#define DISPONIBLE 1
#define EN_REPARATION 2
void menu_principale()
{
        system("COLOR C");
        printf("\n\n\n\n\n\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
    printf("\t\4\tBienVenue dans  la Gestion de la Bibliotheque      \4\n");
    printf("\t\4\t voulez vous :                                              \4\n");
    printf("\t\4\t1-Gerer les Livres                                          \4\n");
    printf("\t\4\t2-Gerer les Abonnes                                         \4\n");
    printf("\t\4\t3-Mise a Jour du bibliotheque                               \4\n");
    printf("\t\4\t4-Quitter                                                   \4\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
    printf("\t\4\tDonnez Votre Choix:                                         \4\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");

}
void menu_1()
{       system("COLOR 9");
        printf("\n\n\n\n\n\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
    printf("\t\4\tBienVenue dans la Gestion de la Bibliotheque       \4\n");
    printf("\t\4\t Gestion Livre:                                             \4\n");
    printf("\t\4\t                                                            \4\n");
    printf("\t\4\t1-ajouter un  livre                                         \4\n");
    printf("\t\4\t2-modifier un livre                                         \4\n");
    printf("\t\4\t3-supprimer un livre                                        \4\n");
    printf("\t\4\t4-Rechercher un livre                                       \4\n");
    printf("\t\4\t5-Afficher la liste des livres /Par Annee                   \4\n");
    printf("\t\4\t6-Retour  au menu principale                                \4\n");
    printf("\t\4\t7-Quitter                                                   \4\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
    printf("\t\4\tDonnez Votre Choix:                                         \4\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
}
void menu_2()
{       system("COLOR d");
    printf("\n\n\n\n\n\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
    printf("\t\4\tBienVenue dans la Gestion de la Bibliotheque       \4\n");
    printf("\t\4\t Gestion des Abonnes:                                       \4\n");
    printf("\t\4\t                                                            \4\n");
    printf("\t\4\t1-Ajouter un  Abonne                                        \4\n");
    printf("\t\4\t2-Modifier un Abonne                                        \4\n");
    printf("\t\4\t3-Supprimer un Abonne                                       \4\n");
    printf("\t\4\t4-Afficher la liste des Abonnes                             \4\n");
    printf("\t\4\t5-Emprunter un livre                                        \4\n");
    printf("\t\4\t6-Retouner au menu principale                               \4\n");
    printf("\t\4\t7-Quitter                                                   \4\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
    printf("\t\4\tDonnez Votre Choix:                                         \4\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
}
void menu_3()
{
 system("COLOR a");
 printf("\n\n\n\n\n\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
    printf("\t\4\tBienVenue dans la Gestion de la Bibliotheque       \4\n");
    printf("\t\4\t Mise A jour du Bibliotheque :                              \4\n");
    printf("\t\4\t                                                            \4\n");
    printf("\t\4\t1-Afficher la Liste des Livres: \5 EMPRUNTER                 \4\n");
    printf("\t\4\t                                \5 DISPONIBLE                \4\n");
    printf("\t\4\t                                \5 EN_REPARATION             \4\n");
    printf("\t\4\t2-Envoyer un Livre au Reparation                            \4\n");
    printf("\t\4\t3-Rendre un livre                                           \4\n");
    printf("\t\4\t4-Retouner au menu principale                               \4\n");
    printf("\t\4\t5-Quitter                                                   \4\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
    printf("\t\4\tDonnez Votre Choix:                                         \4\n");
    printf("\t\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");}
//----------------------------------------------------------------------------------------------------
char*Tab_Etat[3]={"EMPRUNTE"," DISPONIBLE","EN_REPARATION"};
typedef struct
{
    int jour;
    int mois;
    int annee;
}Date;
typedef struct
{
    int Code;
    char Titre[TAILLE_CHAINE];
    char Auteur[TAILLE_CHAINE];
    Date Annee_Publication;
    int Etat;
}Livre;

typedef struct
{
    char Nom[TAILLE_CHAINE];
    int id;
    Livre *pointeur;

}Abonne;
typedef struct N
{
    Livre valeur;
   struct N*suivant;
}Noeud;
typedef struct N1{
Abonne AB;
struct N1*suivant;
}Noeud1;
typedef struct
{
    Noeud*tete;

}Liste_Livre;
typedef struct
{
    Noeud1*tete1;
}Liste_Abonne;
//--------------------------------------------------------------
//l'initialisation de la liste des abonn�s
void initialiser_liste_abonne(Liste_Abonne*LAB)
{LAB->tete1=NULL;}
//l'initialisation d'une liste des livres
void initialiser_liste_Livre(Liste_Livre*L)
{L->tete=NULL;}
//----------------------------------------------------------------------------------------------------------------
void saisir_livre(Livre*L)
{
    printf("Saisir le titre du Livre:\n");
    scanf("%s",L->Titre);
    printf("Saisir son code:\n");
    scanf("%d",&L->Code);
    printf("Saisir le nom de son auteur:\n");
    scanf("%s",L->Auteur);
    printf("\n");
    printf("Saisir son Annee de publication:\n");
    printf("Donnez le jour:\n");
    scanf("%d",&L->Annee_Publication.jour);
    printf("Donnez le mois:\n");
    scanf("%d",&L->Annee_Publication.mois);
    printf("Donnez l'annee:\n");
    scanf("%d",&L->Annee_Publication.annee);
    do{
    printf("Donnez l'etat:\n");
    printf("0:EMPRUNTE\n");
    printf("1:DISPONIBLE\n");
    printf("2:EN_REPARATION\n");
    scanf("%d",&L->Etat);
    }while(L->Etat<0 || L->Etat>3);
    L->Etat=1;
}
//-----------------------------------------------------------------------------------------------------------
void Ajouter_Livre_list(Liste_Livre *l,Livre L)
{
  Noeud *nouveau,*i;
   nouveau=(Noeud*)malloc(sizeof(Noeud));
   nouveau->valeur=L;
   nouveau->suivant=NULL;
   if(l->tete==NULL)
   l->tete=nouveau;
   else
   {
       i=l->tete;
       while(i->suivant!=NULL)
       i=i->suivant;
       i->suivant=nouveau;}}
//-------------------------------------------------------------------------------------------------------------------
 //chercher un livre le resultat return
 Noeud *chercher_Liste(Liste_Livre l,int coode)
{
    Noeud*i;
    i=l.tete;
    while((i!=NULL)&&(i->valeur.Code!=coode))
     i=i->suivant;
     return i;
}
// l'affichage du livre :
void Afficher_Livre(Livre L)
{   int i=L.Etat;
    printf("______________________________________________\n");
    printf("Le Titre de ce Livre est : %s\n",L.Titre);
    printf("Son code est : %d\n",L.Code);
    printf("De l'auteur : %s\n",L.Auteur);
    printf("Il etait publie Le: %d/%d/%d           \n",L.Annee_Publication.jour,L.Annee_Publication.mois,L.Annee_Publication.annee);
    printf("L'etat de ce Livre est :%s \n",Tab_Etat[i]);
    printf("_____________________________________________\n");
}
//---------------------------------------------------------------------------------------------------------------
// Chercher un livre dans les listes des livres � partire de son code :
int Chercher_Livre(Liste_Livre Disponible,Liste_Livre Emprunte,Liste_Livre En_Reparation,int x)
{
    Noeud*i=Disponible.tete;
    while((i!=NULL)&&(i->valeur.Code!=x))
        i=i->suivant;
    if (i!=NULL)
        return 1;
    else
    {
        Noeud*i=Emprunte.tete;
        while((i!=NULL)&&(i->valeur.Code!=x))
            i=i->suivant;
        if (i!=NULL)
            return 2;
        else
        {
            Noeud*i=En_Reparation.tete;
            while((i!=NULL)&&(i->valeur.Code!=x))
                i=i->suivant;
            if (i!=NULL)
                return 3;
            else
                return 0;}}}
//-------------------------------------------------------------------------------------------------------------------------------------
 //rechercher un livre le resultar retunr un noeud  :

 Noeud*Recherche_livre( Liste_Livre Disponible,Liste_Livre Emprunte,Liste_Livre En_Reparation,int coode)
{
   Noeud*i,*j,*k;
   i=chercher_Liste(Disponible,coode);
   j=chercher_Liste(Emprunte,coode);
   k=chercher_Liste(En_Reparation,coode);
   if(i!=NULL)
   return i;
   if(j!=NULL)
   return j;
   if(k!=NULL)
   return k;
   if((i==NULL)&&(k==NULL)&&(j=NULL))
   return i;
}
//-------------------------------------------------------------------------------------------------------------
// modifier l'annee de publication
void Modifier_Annee_publication(Liste_Livre *Disponible,Liste_Livre *Emprunte,Liste_Livre *En_Reparation,int xx)
    {
      Noeud* n;
      int p ;

        p=Chercher_Livre(*Disponible,*Emprunte,*En_Reparation,xx);
   switch(p)
      {

      case 1 :{
             n=chercher_Liste(*Disponible,xx);
              printf("Entrer La Nouvelle Date\n");
              printf("Donnez le jour:\n");
              scanf("%d",&n->valeur.Annee_Publication.jour);
              printf("Donnez le mois:\n");
              scanf("%d",&n->valeur.Annee_Publication.mois);
              printf("Donnez l'annee:\n");
              scanf("%d",&n->valeur.Annee_Publication.annee);
              }
             break;

      case 2 :{
             n=chercher_Liste(*Emprunte,xx);
              printf("Entrer La Nouvelle Date\n");
              printf("Donnez le jour:\n");
              scanf("%d",&n->valeur.Annee_Publication.jour);
              printf("Donnez le mois:\n");
              scanf("%d",&n->valeur.Annee_Publication.mois);
              printf("Donnez l'annee:\n");
              scanf("%d",&n->valeur.Annee_Publication.annee);
              }

             break;

      case 3 :{
             n=chercher_Liste(*En_Reparation,xx);
              printf("Entrer La Nouvelle Date\n");
              printf("Donnez le jour:\n");
              scanf("%d",&n->valeur.Annee_Publication.jour);
              printf("Donnez le mois:\n");
              scanf("%d",&n->valeur.Annee_Publication.mois);
              printf("Donnez l'annee:\n");
              scanf("%d",&n->valeur.Annee_Publication.annee);
              }

             break;
      default:
             printf("Erreur !!\n");}}
//-------------------------------------------------------------------------------------------------------------
//Modifier le titre du livre :
void Modifier_Titre(Liste_Livre *Disponible,Liste_Livre *Emprunte,Liste_Livre *En_Reparation,int xx)
   {
     int p;
     Noeud *n;
   p=Chercher_Livre(*Disponible,*Emprunte,*En_Reparation,xx);
   switch(p)
     {
      case 1 :{
            n=chercher_Liste(*Disponible,xx);
            printf("Entrez le Nouveau Titre :\n");
             scanf("%s",n->valeur.Titre);
              }
             break;
      case 2 :{
             n=chercher_Liste(*Emprunte,xx);
             printf("Entrer Le Nouveau Titre :\n");
             scanf("%s",n->valeur.Titre);
              }
             break;
      case 3 :{
             n=chercher_Liste(*En_Reparation,xx);
             printf("Entrer Le Nouveau Titre :\n");
             scanf("%s",n->valeur.Titre);
             }
             break;
      default:
             printf("Erreur !!! \n");}}
//----------------------------------------------------------------------------------------------------------------
//Modifier l'auteur du livre:
void Modifier_Auteur(Liste_Livre *Disponible,Liste_Livre *Emprunte,Liste_Livre *En_Reparation,int xx)
  {
     int p;
     Noeud *n;
    p=Chercher_Livre(*Disponible,*Emprunte,*En_Reparation,xx);
   switch(p)
     {
      case 1 :{
             printf("Entrer Le Nouveau Nom d'Auteur :\n ");
             n=chercher_Liste(*Disponible,xx);
             scanf("%s",n->valeur.Auteur);
              }
             break;

      case 2 :{
             printf("Entrer Le Nouveau Nom d'Auteur :\n ");
             n=chercher_Liste(*Emprunte,xx);
             scanf("%s",n->valeur.Auteur );
              }
             break;

      case 3 :{
             printf("Entrer Le Nouveau Nom d'Auteur :\n ");
             n=chercher_Liste(*En_Reparation,xx);
             scanf("%s",n->valeur.Auteur);
              }
             break;
      default:
             printf("Erreur !!!\n");}}
//----------------------------------------------------------------------------------------------------
// fonction remplire la liste des livres disponible :
void remplire_liste_Disponible(Liste_Livre *Disponible,int n)
{ int i;
Livre L;
Disponible->tete=NULL;
for(i=0;i<n;i++)
{
   printf(" Saisie du Livre /%d/\n",i+1);
   saisir_livre(&L);
   Ajouter_Livre_list(Disponible,L);}}
//----------------------------------------------------------------------------------------------------
//Afficher la liste des livre disponible:
void Afficher_liste(Liste_Livre l)
{
    Noeud *i;
    i=l.tete;
    while(i!=NULL)
    {
        Afficher_Livre(i->valeur);
        i=i->suivant;
    }
}

//----------------------------------------------------------------------------------------------------
//Afficher les livres parus � une annee donn�e :
void Afficher_Livre_Par_Annee(Liste_Livre Disponible,Liste_Livre Emprunte,Liste_Livre En_Reparation,int anne)
{
    Noeud*i;
    int k=1;
    i=Disponible.tete;

    printf("la Liste Des Livres Disponibles Parus A L'Annee %d Est : \n",anne);
    if(i==NULL)
    printf("\t----La Liste Est Vide !!!---\n");
    else
    {
        while(i!=NULL)
        {
        if(i->valeur.Annee_Publication.annee==anne)
        {
        printf("Le Livre Num /%d/ : \n",k);
        Afficher_Livre(i->valeur);
        }
        i=i->suivant;
        k++;
        }
    }
    printf("\n\n");

    Noeud*j;
     k=1;
    j=Emprunte.tete;
    printf("La Liste Des Livres Empruntes Parus A l'Annee %d Est : \n",anne);
    if(j==NULL)
    printf("\t----la liste est vide !!!---\n");
    else
    {
        while(j!=NULL)
        {
        if(j->valeur.Annee_Publication.annee==anne)
        {
        printf("Le Livre Num /%d/ : \n",k);
        Afficher_Livre(j->valeur);
        }
        j=j->suivant;
        k++;
        }
    }
    printf("\n\n");

    Noeud*l;
    k=1;
    l=En_Reparation.tete;
    printf("La Liste Des Livres En_Reparation Parus A l'Annee /%d/ Est : \n\n",anne);
    if(l==NULL)
    printf("\t----la liste est vide !!!---\n");
    else
    {
        while(l!=NULL)
        {
            if(l->valeur.Annee_Publication.annee==anne)
            {
                printf("\n Le Livre Num /%d/ : \n",k);
                Afficher_Livre(l->valeur);
            }
            l=l->suivant;
            k++;
        }
    }
    printf("\n\n");}
//--------------------------------------------------------------------------------------------------------
// Supprimer un livre de la liste des livres apartire de son Code :

void Supprimer_Livre(Liste_Livre *l, int x)
{
    Noeud*i,*j;
    if(l->tete!=NULL)
    {
        if(l->tete->valeur.Code==x)
        {
            i=l->tete;
            l->tete=i->suivant;
            free(i);
        }
        else
        {
            i=l->tete->suivant;
            j=l->tete;
            while((i!=NULL)&&(i->valeur.Code!=x))
            {
                j=i;
                i=i->suivant;
            }
            if(i!=NULL)
            {
                j->suivant=i->suivant;
                free(i);
            }
            else
            printf ("\t----Cet Livre n'Existe Pas !!---\n");
        }
    }
    else
    printf("\t----La Liste Des Livre Est Vide!!---\n");}
//----------------------------------------------------------------------------------------------------------------------------
// la saisie d'un abonne :
void Saisir_Abonne(Abonne *A)
{
    printf("Donnez le Nom de l'Abonne:\n");
    scanf("%s", A->Nom);
    printf("Donnez son Identifiant\n");
    scanf("%d",&A->id);
    A->pointeur=NULL;
}
//----------------------------------------------------------------------------------------------------------------------------------------
// l'affichage d'un abonne :
void Afficher_Abonne(Abonne A)
{   printf("\t \t____________________________\n");
    printf("\t\tLE NOM :%s\n",A.Nom);
    printf("\t\tL'IDENTIFIANT :%d\n",A.id);
    if(A.pointeur==NULL)
    printf("\t\t\t** Aucun Livre Emprunter **\n");
    else
    printf("\t\t\t** Il a un Livre Emprunte **\n");
    printf("\t\t____________________________\n");
}
//---------------------------------------------------------------------------------------------------------------------------------
// l'ajout d'un nouveau abonn� � la liste des abonn�s
void AjoutAbonne(Liste_Abonne *LAB,Abonne A)
{
    Noeud1*n,*i;
    n=(Noeud1*)malloc(sizeof(Noeud1));
    n->AB=A;
    n->suivant=NULL;
    if(LAB->tete1==NULL)
    LAB->tete1=n;
    else
    {
        i=LAB->tete1;
        while(i->suivant!=NULL)
        i=i->suivant;
        i->suivant=n;}}
//-----------------------------------------------------------------------------------------------------------------------------------
//Remplire la liste des Abonnes :
void remplire_liste_Abonne(Liste_Abonne *LAB,int n)
{ int i;
Abonne A;
LAB->tete1=NULL;
for(i=0;i<n;i++)
{
   printf(" Saisie de l'Abonne /%d/\n",i+1);
   Saisir_Abonne(&A);
   AjoutAbonne(LAB,A);}}
//---------------------------------------------------------------------------------------------------------------------
// Afficher la liste des abonnes :
void Afficher_liste_Abonne(Liste_Abonne LAB)
{
    Noeud1 *i;
    i=LAB.tete1;
    if(i==NULL)
    printf("\t  ---La Liste Des Aonnes Est Vide !!---\n");
    while(i!=NULL)
    {
        Afficher_Abonne(i->AB);
        i=i->suivant;}}
//---------------------------------------------------------------------------------------------------------------------
 //Modifier un Abonne :
 void Modifier_Abonne(Liste_Abonne *LAB,int x)
 {
 Noeud1 *i,*j;
     if(LAB->tete1!=NULL)
    {
        if(LAB->tete1->AB.id==x)
        {
            printf("Donner le Nouveau Nom de Votre Abonne :\n ");
            scanf("%s",&LAB->tete1->AB.Nom);
        }
        else
        {
            j=LAB->tete1;
            i=LAB->tete1->suivant;
            while((i!=NULL)&&(i->AB.id!=x))
            {
                j=i;
                i=i->suivant;}
            if(i!=NULL)
            {
               printf("Donner le Nouveau Nom de Votre Abonne :\n ");
               scanf("%s",&i->AB.Nom);
            }
            else
            printf("l'Identifiant %d .. n'existe pas !!\n",x);}}
    else
    printf("La Liste des Abonnes est Vide !!!\n");}
//-------------------------------------------------------------------------------------------------------------------
//supprimer un Abonne de la liste des Abonnes :
void Supprimer_Abonne(Liste_Abonne *LAB,int x)
{
    Noeud1 *i,*j;
    if(LAB->tete1!=NULL)
    {
        if(LAB->tete1->AB.id==x)
        {
            i=LAB->tete1;
            LAB->tete1=LAB->tete1->suivant;
            free(i);
        }
        else
        {
            j=LAB->tete1;
            i=LAB->tete1->suivant;
            while((i!=NULL)&&(i->AB.id!=x))
            {
                j=i;
                i=i->suivant;
            }
            if(i!=NULL)
            {
                j->suivant=i->suivant;
                free(i);
            }
            else
            printf("l'Identifiant %d .. n'existe pas !!\n",x);}}
    else
    printf("La Liste des Abonnes est Vide !!!\n");
}
//----------------------------------------------------------------------------------------------------------------
 //Chercher un abonne le resultat retourner est de type noeud:
 Noeud1 *Chercher_Abonne(Liste_Abonne LAB,int ident)
{
    Noeud1*i;
    i=LAB.tete1;
    while((i!=NULL)&&(i->AB.id!=ident))
     i=i->suivant;
     return i;
}
//-------------------------------------------------------------------------------------------------------
void Emprunter_Livre(Liste_Abonne LAB,Liste_Livre *Disponible,Liste_Livre *Emprunte,Liste_Livre* En_Reparation,Abonne *A,int x,int ident)
    {
       Noeud* i;
       Noeud1 *j;
       int k;

       k=Chercher_Livre(*Disponible,*Emprunte,*En_Reparation,x);
       i= Recherche_livre(*Disponible,*Emprunte,*En_Reparation,x) ;
       j=Chercher_Abonne(LAB,ident);
       *A=j->AB;
       if(k!=1)

           printf ("\t----Ce Livre n'Existe Pas Dans La Liste DISPONIBLE !!---\n ") ;
      else
         {

           if(A->pointeur!=NULL)
           printf("\t\t\t** L'Abonne a un Livre  **\n");
           else
               {  i->valeur.Etat=0;
                  Ajouter_Livre_list(Emprunte,i->valeur);
                  Supprimer_Livre(Disponible,i->valeur.Code);
                  A->pointeur=&i->valeur;}}}
//-----------------------------------------------------------------------------------------------------------
//Envoyer un livre vers la liste de reparation :
void Envoyer_Livre_Reparation(Liste_Livre *Disponible,Liste_Livre *Emprunte,Liste_Livre* En_Reparation,Abonne *A,int x)
{
    Noeud *j;
    int i;
   i=Chercher_Livre(*Disponible,*Emprunte,*En_Reparation,x);
   j=Recherche_livre(*Disponible,*Emprunte,*En_Reparation,x) ;
   if(i==3)
   printf("\t----Ce Exist Deja dans la liste de Reparation--- \n");
   if(i==1)
   {
       j->valeur.Etat=2;
                  Ajouter_Livre_list(En_Reparation,j->valeur);
                  Supprimer_Livre(Disponible,j->valeur.Code);
   printf("\t----Le Livre Est Deplacer Dans La Listes de Reparation---\n");
   }
   if(i==2)
   {
                  j->valeur.Etat=2;
                  Ajouter_Livre_list(En_Reparation,j->valeur);
                  Supprimer_Livre(Emprunte,j->valeur.Code);
          A->pointeur=NULL;
   }
    if(i==0)
      printf("\t----Verifier Votre Code %d !!---\n",x);
}
//------------------------------------------------------------------------------------------------------------
void Rendre_Livre(Liste_Abonne LAB,Liste_Livre *Disponible,Liste_Livre *Emprunte,Liste_Livre* En_Reparation,Abonne *A,int x,int ident)
{
     Noeud *j;
     Noeud1 *k;
    int i;
   i=Chercher_Livre(*Disponible,*Emprunte,*En_Reparation,x);
   j=Recherche_livre(*Disponible,*Emprunte,*En_Reparation,x) ;
   k=Chercher_Abonne(LAB,ident);
    if(i==2)
    {
         j->valeur.Etat=1;
         Ajouter_Livre_list(Disponible,j->valeur);
         Supprimer_Livre(Emprunte,j->valeur.Code);
          k->AB.pointeur=NULL;}
    else
    printf("\t----Verifier le Code de Votre Livre !!---\n");}
int main()
{
   int choix,choix1,choix2,choix3,choice,n,i,c,champ,x,anne,m;
   char titre;
   Livre L;
   Abonne A;
   Liste_Livre l,Disponible,Emprunte,En_Reparation;
   Liste_Abonne LAB;
initialiser_liste_Livre(&Disponible);
initialiser_liste_Livre(&Emprunte);
initialiser_liste_Livre(&En_Reparation);
initialiser_liste_abonne(&LAB);
    menu_principale();
    scanf("%d",&choix);
     do
     {
    switch(choix)
         {
             case 1:
             { system("cls");
               menu_1();
               scanf("%d",&choix1);
               printf("\n");

            switch(choix1)
                 {
                  case 1:
                     { system("cls");
                       printf("  Donnez le nombre des livres @ ajouter : \n");
                       scanf("%d",&n);
                       remplire_liste_Disponible(&Disponible,n);

                       getch();
                       menu_1();
                     }break;
                  case 2:
                     {
                       system("cls");
                       printf("Donner le Code du Livre a Modifier :\n");
                       scanf("%d",&n);
                       c=Chercher_Livre(Disponible,Emprunte,En_Reparation,n);
                       if(c!=0)
                       {
                       printf("Choisir le Champ de Modification :\n");
                       printf("1:Le Titre\n2:Auteur\n3:Annee De Publication\n");
                       scanf("%d",&champ);
                       if(champ==1)
                       Modifier_Titre(&Disponible,&Emprunte,&En_Reparation,n);
                       if(champ==2)
                       Modifier_Auteur(&Disponible,&Emprunte,&En_Reparation,n);
                       if(champ==3)
                       Modifier_Annee_publication(&Disponible,&Emprunte,&En_Reparation,n);}
                       else
                       printf("Ce Code n'existe Pas !\n");
                       getch();
                       menu_1();
                         }break;
                  case 3:
                      {
                      printf("Donnez Le Code Du Livre Que Vous Voulez Le supprimer: \n");
                      scanf ("%d",&n);
                      x=Chercher_Livre(Disponible,Emprunte,En_Reparation,n);
                      if(x==1)
                      {
                      Supprimer_Livre(&Disponible,n);
                      printf("\t----Suppression avec succes---\n");
                      printf("\t\t\2\2\2\2\2\n");
                      }
                      if(x==2)
                      {
                      Supprimer_Livre(&Emprunte,n);
                      printf("\t----Suppression avec succes---\n");
                      printf("\t\t\2\2\2\2\2\n");
                      }
                      if(x==3)
                      {
                      Supprimer_Livre(&En_Reparation,n);
                      printf("\t----Suppression avec succes---\n");
                      printf("\t\t\2\2\2\2\2\n");
                      }
                      getch();
                       menu_1();
                       }break;
                  case 4:
                      {
                       printf("Donner Le Code Du Livre A Chercher :\n");
                       scanf("%d",&n);
                       m=Chercher_Livre(Disponible,Emprunte,En_Reparation,n);
                       if(m==1)
                       printf("\t** Le Livre Du Code %d EXISTE Dans La Liste DISPONIBLE .\n",n);
                       if(m==2)
                       printf("\t** Le Livre Du Code %d EXISTE Dans La Liste EMPRUNTER .\n",n);
                       if(m==3)
                       printf("\t** Le Livre Du Code %d EXISTE Dans La Liste EN_REPARATION .\n",n);
                       if(m==0)
                       printf("\t----Verifier Le Code Donnee !!!--- \n");
                       getch();

                       menu_1();
                      }break;
                  case 5:
                      {
                        printf("Donner L'Annee :\n");
                        scanf("%d",&n);

                        Afficher_Livre_Par_Annee(Disponible,Emprunte,En_Reparation,n);
                        getch();
                        menu_1();
                      }break;
                  case 6:
                      { system("cls");
                        menu_principale();
                        scanf("%d",&choix);
                        getch();
                      }break;
                  case 7:
                      {  system("cls");
                      system("COLOR E");
                      printf("\n\n\n\n\n\n\n\n\n");
                      printf("\t\t\t*******APPLICATION TERMINEE*******\n");
                      printf("\t\t\t  ****   A BIENTOT \1\1   *****\n");
                      printf("\7\7\7\7\7\7\7\7\7\7\7\7\7\7\7\7");
                      getch();
                      }break;}
             }break;
             case 2:
             {
               system("cls");
               menu_2();
               scanf("%d",&choix2);
               printf("\n");
               switch(choix2)
               {
                   case 1:{
                   system("cls");
                   printf("Donner le Nombre des Abonnes Que Vous voulez Ajouter :\n");
                   scanf("%d",&n);
                   remplire_liste_Abonne(&LAB,n);
                   getch();
                   menu_2();

                          }break;
                   case 2:{
                    system("cls");
                    printf("Donner l'Identifiant de l'Abonne A Modifier :\n");
                    scanf("%d",&n);
                    Modifier_Abonne(&LAB,n);
                    printf("\t\t----Modification avec Succes \2\2\2 ---\n");
                    getch();
                    menu_2();
                          }break;
                   case 3:{
                   system("cls");
                   printf("Donner l'Identifiant de l'Abonne A Supprimer :\n");
                   scanf("%d",&x);
                   Supprimer_Abonne(&LAB,x);
                   printf("\t----Suppression Finit Avec Succes ---\n");
                   printf("\t\t---------\2\2\2---------\n");
                   getch();
                   menu_2();
                          }break;
                   case 4:{
                       system("cls");
                       printf("\n\n\n\n");
                       printf("\t_______LA LISTE DES ABONNEES EST :_______\n\n\n");
                       Afficher_liste_Abonne(LAB);
                       getch();
                       menu_2();

                          }break;
                    case 5:{
                           printf("Donner Le Code Du Livre A Emprunter :\n");
                           scanf("%d",&x);
                           printf("Donner l'Identifiant de l'Abonne :\n");
                           scanf("%d",&n);
                           Emprunter_Livre(LAB,&Disponible,&Emprunte,&En_Reparation,&A,x,n);

                           getch();
                           menu_2();
                           }break;
                    case 6:{
                        system("cls");
                        menu_principale();
                        scanf("%d",&choix);
                        getch();
                           }break;
                    case 7:{
                            system("cls");
                            system("COLOR E");
                      printf("\n\n\n\n\n\n\n\n\n");
                      printf("\t\t\t*******APPLICATION TERMINEE*******\n");
                      printf("\t\t\t  ****   A BIENTOT \1\1   *****\n");
                      printf("\7\7\7\7\7\7\7\7\7\7\7\7\7\7\7\7");
                      getch();
                           }break;
              }
                 }break;
                case 3:{
                       system("cls");
                       menu_3();
                       scanf("%d",&choix3);
                       printf("\n");

                       switch(choix3)
                       {
                           case 1:{
                               system("cls");
                                  printf("Choisir la Liste que Vous Voulez Afficher:\n");
                                  printf("\t\6         Disponible     1\n");
                                  printf("\t\6\6        Emprunter      2\n");
                                  printf("\t\6\6\6       En_Reparation  3\n");
                                  scanf("%d",&n);
                                  if(n==1)
                                  Afficher_liste(Disponible);
                                  if(n==2)
                                  Afficher_liste(Emprunte);
                                  if(n==3)
                                  Afficher_liste(En_Reparation);
                                  getch();
                                  menu_3();
                                  }break;

                           case 2:{
                                 system("cls");
                                  printf("Donnez le Code que vous voulez Envoyer Au Reparation :\n");
                                  scanf("%d",&x);
                                  Envoyer_Livre_Reparation(&Disponible,&Emprunte,&En_Reparation,&A,x);
                                  printf("\t---- Envoi Avec Succes---\n");
                                  printf("\t\t----\2\2\2---\n");
                                  getch();
                                  menu_3();

                                  }break;
                           case 3:{
                                  system("cls");
                                  printf("Donner le Code du Livre a Rendre :\n");
                                  scanf("%d",&x);
                                  printf("Donner l'identifiant de l'abonne :\n");
                                  scanf("%d",&n);
                                  Rendre_Livre(LAB,&Disponible,&Emprunte,&En_Reparation,&A,x,n);
                                  printf("\t---- Rendre A la Liste Disponible Avec Succes---\n");
                                  printf("\t\t\t----\2\2\2---\n");
                                  getch();
                                  menu_3();
                                  }break;
                           case 4:{
                                  system("cls");
                        menu_principale();
                        scanf("%d",&choix);
                        getch();
                                  }break;
                           case 5:{
                                   system("cls");
                                  system("COLOR E");
                      printf("\n\n\n\n\n\n\n\n\n");
                      printf("\t\t\t*******APPLICATION TERMINEE*******\n");
                      printf("\t\t\t  ****   A BIENTOT \1\1   *****\n");
                      printf("\7\7\7\7\7\7\7\7\7\7\7\7\7\7\7\7");
                      getch();
                                  }break;}
                       }break;
                case 4:{
                            system("cls");
                            system("COLOR E");
                      printf("\n\n\n\n\n\n\n\n\n");
                      printf("\t\t\t*******APPLICATION TERMINEE*******\n");
                      printf("\t\t\t  ****   A BIENTOT \1\1   *****\n");
                      printf("\7\7\7\7\7\7\7\7\7\7\7\7\7\7\7\7");
                      getch();
                       }break;}
     }while(choix!=4 && choix1!=7 &&choix2!=7 &&choix3!=6);
    return 0;
    getch();}
    //adding the file system as RDB
    