#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define TAILLE_CHAINE 100
#define EMPRUNTE 1
#define DISPONIBLE 2
#define REPARATION 3
char *NOM_ETAT[3] = {"1 EMPRUNTE","2 DISPONIBLE","3 REPARATION"};



typedef struct
            { int code;
              char tit[TAILLE_CHAINE];
              char aut[TAILLE_CHAINE];
              int anpub;
              int etat;

            }livre;


typedef struct Noeudl
              { livre valeur;
                 struct Noeudl *next;
              }Noeudl;




typedef struct
{
    char nom[30];
    int id;
    livre *pointeur;
}Abonne;

typedef struct NoeudA
              { Abonne valeur;
                struct NoeudA *next;
              }NoeudA;


typedef struct
{  Noeudl*  Disp;
   Noeudl*  Emp ;
   Noeudl*  Rep ;
   NoeudA*  Abo;
}Bibliotheque;
//---------------------fonction initliste---------------------------------------------------------//
void initBiblio(Bibliotheque *B)
{
     B->Disp=NULL;
     B->Emp=NULL;
     B->Rep=NULL;
     B->Abo=NULL;
}

//---------------------------------------------------------------saisir livre-----------------------//
void saisirlivre(livre *l)
{
  printf("saisir le code \n");
  scanf("%d",&l->code);
  printf("donner le titre \n");
  scanf("%s",l->tit);
  printf("donner l'auteur \n");
  scanf("%s",l->aut);
  printf("saisir l'anne de publication\n");
  scanf("%d",&l->anpub);
 printf("Decrire l etat d'un livre : \n - 1 s'il est emprunte\n - 2 s'il est disponible \n - 3 s'il est en reparation \n ");
 scanf("%d",&l->etat);

}
//---------------------------------------affficher livre------------------------------------------------//
void affichlivre(livre l)
{
     char *NOM_ETAT[3] = {"1 EMPRUNTE","2 DISPONIBLE","3 EN_REPARATION"};

            {
            printf("\t***************************************\n");
            printf("\t* -Le code de livre   : %d             \n",l.code);
            printf("\t* -Le titre           : %s             \n",l.tit);
            printf("\t* -Auteur             : %s            \n",l.aut);
            printf("\t* -Etat               : %s              \n",NOM_ETAT[l.etat]);
            printf("\t* -Annee publication  : %d            \n",l.anpub);
            printf("\t****************************************\n");
            }
    }
//--------------------------------------ajouter livre----------------------------------------//
void ajouterlivreDisp(Bibliotheque *B,livre l)
{ Noeudl *nouveau;
  nouveau=(Noeudl*)malloc(sizeof(Noeudl));

   l.etat==2;
    nouveau->valeur=l;
    nouveau->next=B->Disp;
    B->Disp=nouveau;


}
//--------------------------------------ajouter livre----------------------------------------//
void ajouterlivreRep(Bibliotheque *B,livre l)
{ Noeudl *nouveau;
  nouveau=(Noeudl*)malloc(sizeof(Noeudl));
    l.etat==3;
    nouveau->valeur=l;
    nouveau->next=B->Rep;
    B->Rep=nouveau;



}
//--------------------------------------ajouter livreemp----------------------------------------//

void ajouterlivreEmp(Bibliotheque *B,livre l)
{Noeudl *nouveau;
  nouveau=(Noeudl*)malloc(sizeof(Noeudl));

   l.etat==1;
    nouveau->valeur=l;
    nouveau->next=B->Emp;
    B->Emp=nouveau;

}
//-----------------------------saisir liste livre Disponible-----------------------------------------------//
void saisirlistedisponible(Bibliotheque *B,int n)
{livre l;
 int i;

 for(i=0;i<n;i++)
 {saisirlivre(&l);
  ajouterlivreDisp(B,l);
  }
}



//-----------------------------------------afficher liste livre Disponible------------------------------------//
void affichlisteDisp(Bibliotheque B)
{ Noeudl *p;
 p=B.Disp;
 while((p!=NULL)&&(p->valeur.etat==2))
 {  affichlivre(p->valeur);
    p=p->next;
  }
 }
//--------------------------------saisir lister empruntes-----------------------------------------------//
void saisirlisteEmp(Bibliotheque *B,int n)
{livre l;
 int i;

 for(i=0;i<n;i++)
 {saisirlivre(&l);
  ajouterlivreEmp(B,l);
  }
}


//-----------------------------------------afficher liste livre Empruntee-----------------------------------//
void affichlisteEmp(Bibliotheque B)
{ Noeudl *p;
 p=B.Emp;
 while((p!=NULL)&&(p->valeur.etat==1))
 {  affichlivre(p->valeur);
    p=p->next;
  }
 }
//-----------------------------saisir liste livre Reparation-----------------------------------------------//
void saisirlisteRep(Bibliotheque *B,int n)
{livre l;
 int i;

 for(i=0;i<n;i++)
 {saisirlivre(&l);
  ajouterlivreRep(B,l);
  }
}


//-----------------------------------------afficher liste livre reparation-----------------------------------//
void affichlisteRep(Bibliotheque B)
{ Noeudl *p;
 p=B.Rep;
 while((p!=NULL)&&(p->valeur.etat==3))
 {  affichlivre(p->valeur);
    p=p->next;
  }
 }

//----------------------------------------recherche Code Livre------------------------------------------//
int recherherLivre(Bibliotheque B,int cd)
{ Noeudl *p1,*p2,*p3;
   p1=B.Emp;
   p2=B.Disp;
   p3=B.Rep;
   int trouve=0;

   while((p2!=NULL)||(p1!=NULL)||(p3!=NULL))
   {if(p2->valeur.code==cd)
      trouve=1;
      else
        if(p1->valeur.code==cd)
      trouve=2;
     else
        if(p2->valeur.code==cd)
      trouve=3;
      p2=p2->next;
      p1=p1->next;
      p3=p3->next;
      }
      return(trouve);
      }

//-------------------------------------affiche livre annee------------------------------------------//
void affichLivreAnne(Bibliotheque B,int an)
{  Noeudl *p1,*p2,*p3;
    p1=B.Emp;
     p2=B.Disp;
     p3=B.Rep;

  while(p1!=NULL)
  { if(p2->valeur.anpub==an)
       {
       printf("livre:%s\n",p1->valeur);
       p1=p1->next;
       }
   }
  while(p2!=NULL)
 {
   if(p2->valeur.anpub==an)
      {  printf("livre:%s\n",p2->valeur);
       p2=p2->next;
      }
}
  while(p3!=NULL)
  {
   if(p3->valeur.anpub==an)
       { printf("livre:%s\n",p3->valeur);
       p3=p3->next;
       }
}
}
//-------------------------------------modifier code-----------------------------------------//

void ModifierAnne(Bibliotheque *B,int an)
{ Noeudl* p1,*p2,*p3;

 p1=B->Emp;
 p2=B->Disp;
 p3=B->Rep;


  p1->valeur.anpub=an;
    p2->valeur.anpub=an;
    p3->valeur.anpub=an;
    printf("la valeur que vous avez saisie a ete modifie\n");

}
//-------------------------------------------supprimer Livre-------------------------------------//
void SupprimerLivre(Bibliotheque *B,int cd)
{Noeudl *i,*j,*tete;
livre l;

int test=0;
  switch(l.code)
  { case 1:if(B->Disp->valeur.code==cd)
          {  i=B->Disp;
              B->Disp=i->next;
              free(i);
              test=1;
             }
             else
             tete=B->Disp;
             break;
    case 2:if(B->Emp->valeur.code==cd)
            {i=B->Emp;
              B->Emp=i->next;
              free(i);
              test=1;
              }
              else
              tete=B->Emp;
              break;
    case 3:if(B->Rep->valeur.code==cd)
            {i=B->Rep;
             B->Rep=i->next;
             free(i);
             test=1;
             }
             else
             tete=B->Rep;
             break;
  }
  if(test==0)
  {i=tete;
   j=tete->next;
   while((j!=NULL)&&(j->valeur.code==cd))
     {i=j;
       j=j->next;
     }
     if(j==NULL)
      printf("le livre n'existe pas\n");
      else
      {i->next=j->next;
       free(j);
       }
  }
}
//-----------------------------rendre Livre-----------------------------------------------------//
void RendreLivre(Bibliotheque *B,livre l,Abonne A,int cd)
{   Noeudl *p,*precedent,*disponible;

       if( recherherLivre(*B,cd)==2)
         {
         disponible=(Noeudl*)malloc(sizeof(Noeudl));
         if(B->Emp->valeur.code==cd)
             {
              p=B->Emp;
              B->Emp=B->Emp->next;
              disponible=p;
              free(p);
              B->Abo->valeur.pointeur=NULL;
              }
              }
       else
       {precedent=B->Emp;
       p=B->Emp->next;
       while(p->valeur.code!=cd)
         {precedent=p;
         p=p->next;
         }
         precedent->next=p->next;
         disponible=p;
         free(p);
         B->Abo->valeur.pointeur=NULL;
         disponible->valeur.etat=1;
         disponible->next=B->Disp->next;
         B->Disp=disponible;
       }
       }

//---------------------------------------Emprunter Livre------------------------------------//
void EmprunteLivre(Bibliotheque *B,livre l,Abonne *A,int cd,livre *pointeur)
{ Noeudl *p,*precedent,*emp;
  //  B->Abo->valeur->pointeur=NULL;
  if( recherherLivre(*B,cd)==1)
  {

   emp=(Noeudl*)malloc(sizeof(Noeudl));
     if(B->Disp->valeur.code==cd)
       {  p=B->Disp;
          B->Disp=B->Disp->next;
          emp=p;
         // B->Abo->valeur->pointeur=B->Emp;
          free(p);
         }
         else
         {precedent=B->Disp;
           p=B->Disp->next;
           while(p->valeur.code!=cd)
           {precedent=p;
           p=p->next;
           }
           precedent->next=p->next;
           emp=p;
         //  B->Abo->valeur->pointeur=B->Emp;
           free(p);
           emp->valeur.etat=0;
           emp->next=B->Emp->next;
           B->Emp=emp;
           }
     }
     else
     printf("livre n'existe pas dans cette liste\n");
}

//---------------------------------------Envoyee Livre------------------------------------//
void EnvoyerLivre(Bibliotheque *B,livre l,Abonne *A,int cd,livre *pointeur)
{ Noeudl *p,*precedent,*rep;

  if( recherherLivre(*B,cd)==2)
  {
   rep=(Noeudl*)malloc(sizeof(Noeudl));
     if(B->Disp->valeur.code==cd)
       {  p=B->Disp;
          B->Disp=B->Disp->next;

          rep=p;
         B->Abo->valeur.pointeur=NULL;
         free(p);
         }
         else
         {precedent=B->Disp;
           p=B->Disp->next;
           while(p->valeur.code!=cd)
           {precedent=p;
           p=p->next;
           }
           precedent->next=p->next;
           rep=p;
            B->Abo->valeur.pointeur=NULL;
           free(p);
           rep->valeur.etat=1;
           rep->next=B->Rep->next;
           B->Rep=rep;
           }
     }
     else
     printf("livre n'existe pas dans cette liste\n");
}

//--------------------------------------menu_gerer_livre--------------------------------------//
void menu_gerer_livre(Bibliotheque *B)
{
livre l;
int ch,n,i,an,cd;
Abonne A;
livre pointeur;

do
{
  printf("saisir le nombre de livre\n");
  scanf("%d",&n);
}while(n<0);

do{

  {printf("******************************************************************\n");
  printf("     1-saisir une liste de livre disponible                       *\n");
  printf("     2-afficher la liste des livres  disponible                   *\n");
  printf("     3-saisir une liste de livre emprunte                         *\n");
  printf("     4-afficher la liste des livres  empruntes                    *\n");
  printf("     5-saisir une liste de livre en reparation                    *\n");
  printf("     6-afficher la liste des livres  en reparatiion               *\n");
  printf("     7-Modifier le code  d'un livre  donnee                       *\n");
  printf("     8-afficher un livre a une annee donnee                       *\n");
  printf("     9-Supprimer un livre selon son code                          *\n");
  printf("     10-Rendre un livre                                           *\n");
  printf("     11-Emprunter un liver                                        *\n");
  printf("     12-Envoyer un liver                                          *\n");
  printf("     13-Retour au menu principale                                 *\n");
  printf("     0-quitter                                                    *\n");
  printf("*******************************************************************\n");
  printf("Entrer votre choix:\n");
  scanf("%d",&ch);
  switch(ch)
  { case 1:saisirlistedisponible(B,n);
           break;
    case 2: affichlisteDisp(*B);
           break;

    case 3:saisirlisteEmp(B,n);
           break;
    case 4:affichlisteEmp(*B);
           break;

    case 5:saisirlisteRep(B,n);
           break;
    case 6:affichlisteRep(*B);
           break;

    case 7:printf("saisir la nouvelle annee\n");
             scanf("%d",&an);
             ModifierAnne(B,an);
            break;


    case 8:printf("saisir l'annee de publication\n");
           scanf("%d",&an);
           affichLivreAnne(*B,an);
           break;


    case 9:printf("donner le code du livre\n");
            scanf("%d",&cd);
            SupprimerLivre(B,cd);
            break;
    case 10:printf("donner le code du livre\n");
            scanf("%d",&cd);
            RendreLivre(B,l,A,cd);
            break;
    case 11:printf("donner le code du livre\n");
            scanf("%d",&cd);
            EmprunteLivre(B,l,&A,cd,&pointeur);
            break;
    case 12:printf("donner le code du livre\n");
            scanf("%d",&cd);
            EnvoyerLivre(B,l,&A,cd,&pointeur);
            break;
    }
}
}while(ch!=0);
}
//-------------------------------------saisie abonne-----------------------------------------//
void saisirAbonne(Abonne *A)
{
printf("saisir le nom \n");
scanf("%s",&A->nom);
printf("saisir l'identifiant\n");
scanf("%d",&A->id);
}


//--------------------------------------ajouter abonne---------------------------------------//
void ajouterAbonne(Bibliotheque *B,Abonne A)
{ NoeudA* newA;
  newA=(NoeudA*)malloc(sizeof(NoeudA));
  printf("saisir les valeurs d'un abonne\n");
  newA->valeur=A;
  newA->next=B->Abo;
  B->Abo=newA;

}
//-------------------------affiche abonne-------------------------------------------------//

void affichabonne(Abonne A)
{  int choix;

            {
            printf("\t***************************************\n");
            printf("\t* - Le nom de l'abonne    : %s           \n",A.nom);
            printf("\t* - L'identifiant      : %d            \n",A.id);
            printf("\t****************************************\n");

            }
    }


//-------------------------------saisir liste abonne--------------------------------------//

void saisirlistAbonne(Bibliotheque *B,int n)
{ Abonne A;
 int i;

 for(i=0;i<n;i++)
{ saisirAbonne(&A);
  ajouterAbonne(B,A);
  }
}
//---------------------affich liste abonne-----------------------------------------------------//
void affichlisteAbonne(Bibliotheque B)
{ NoeudA *p;
 p=B.Abo;
 while(p!=NULL)
 {  affichabonne(p->valeur);
    p=p->next;
  }
 }
 //---------------------------recherche-----------------------------------------------------------------//
NoeudA* rechercheidentifiant(Bibliotheque B,int ident)
{NoeudA *p;
 p=B.Abo;
 while((p!=NULL)&&(p->valeur.id!=ident))
  p=p->next;
 return(p);
}
//----------------------------------------supprimer Abonne---------------------------------------------//
void supprimerabonne(Bibliotheque *B,Abonne A,int ident)
{ NoeudA* i,*j;

  if(i!=NULL)
    if(i->valeur.id==ident)
        {i=B->Abo;
          B->Abo=i->next;
          free(i);
          }
          else
          {i=B->Abo->next;
           j=B->Abo;
           while((i!=NULL)&&(i->valeur.id!=ident))
            {j=i;
            i=i->next;
            }
            if(i!=NULL)
             {j->next=i->next;
             free(i);
             }
             }
            else
            printf("%d n'existe pas\n");


}




//---------------------------------------menu_gerer_anonne-----------------------------------------//

void menu_gerer_abonne(Bibliotheque *B)
{ Abonne A;
  int c,n,i,ident;
  NoeudA * trouve;
   printf("le nombre d'abonne\n");
   scanf("%d",&n);

do
{


  printf("******************************************************************\n");
  printf("     1-Saisir une liste  d'abonnes                               *\n");
  printf("     2-Afficher la liste des abonnes                             *\n");
  printf("     3-Recherche de l'identifiant d'un abonne                    *\n");
  printf("     4-Supprimer un abonne de la liste                           *\n");
  printf("     0-Quitter                                                   *\n");
  printf("******************************************************************\n");
  printf("Entrer votre choix:\n");
  scanf("%d",&c);
 switch(c)
 { case 1:
         saisirlistAbonne(B,n);
          break;
   case 2: affichlisteAbonne(*B);
         break;
   case 3:printf("donner l'identifiant d'un abonne\n");
          scanf("%d",&ident);
          trouve=rechercheidentifiant(*B,ident);
          if(trouve!=NULL)
            printf("%d existe \n");
            else
            printf("%d n'existe pas\n");
            break;

   case 4:printf("donner l'identifiant d'un abonne\n");
          scanf("%d",&ident);
          supprimerabonne(B,A,ident);
          break;
   case 5:printf("VOTRE CHOIX EST INVALIDE\n");
          break;
}

}while(c!=0);
}


//----------------------------------------main---------------------------------------------//
int main()
{ Bibliotheque B;
livre l;
Abonne A;
int choix=0,an,n,i,c;
initBiblio(&B);
do
{
 system("cls");
  system("COLOR C");
{ printf("******************************************************************************\n");
 printf("1-Menu pour la gestion des livres                                             *\n");
 printf("2-Menu pour la gestion des abonnes                                            *\n");
 printf("3-Retour au menu principal                                                    *\n");
 printf("0-Quitter                                                                     *\n");
 printf("saisir voter choix                                                            *\n");
 printf("******************************************************************************\n");
 scanf("%d",&choix);
  switch(choix)
  { case 1:menu_gerer_livre(&B);
         break;
    case 2: menu_gerer_abonne(&B);
         break;
         getch();
    case 3:printf("********Retour au menu principal********************\n");
           break;
    case 0:printf("************ Quitter**************\n");
          break;
  }
}
}while(choix!=0);


}



