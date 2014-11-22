/**
@brief liste.c a le code des fonctions pour le module liste.
@author Roberto Medina Bonilla & Yoann Jouvent
@file src/liste.c
@version 1.0
@date 2012/06/07
*/
#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

/*Initialise la liste avec une cellule, a l'aide de celInit*/
void lisInit (Liste *pL)
{
    pL->adPremiere=(Cellule*)malloc(sizeof(Cellule));
    pL->adDerniere=pL->adPremiere;
    pL->adPremiere->info = '*';
    pL->adPremiere->x=5;
    pL->adPremiere->y=5;
    pL->adPremiere->suivant = NULL;
}

/*Remet le snake en position (5,5)*/
void lisInitPerdu(Liste *pL)
{
    Cellule *temp;
    temp = pL->adPremiere;
    pL->adPremiere->x=5;
    pL->adPremiere->y=5;
    while (temp != NULL)
    {
       temp->suivant->x=temp->x-1;
       temp->suivant->y=temp->y;
    }
}

/*Libere l'espace alloué par la liste*/
void lisLibere(Liste *pL)
{
    Cellule * temp;
    while (pL->adPremiere!=NULL)
    {
        temp=pL->adPremiere;
        pL->adPremiere=pL->adPremiere->suivant;
        free(temp);
    }
}

/*Ajout une cellule en tete a gauche*/
void lisAjoutTeteGauche(Liste *pL)
{
    Cellule * temp;
    temp = (Cellule*)malloc (sizeof(Cellule));
    celPointer(temp, pL->adPremiere);
    celSetInfo(temp,'*');
    celSetX(temp,pL->adPremiere->x - 1);
    celSetY(temp,pL->adPremiere->y);

    pL->adPremiere = temp;
}

/*Ajout une cellule en tete a droite*/
void lisAjoutTeteDroite(Liste *pL)
{
    Cellule * temp;
    temp = (Cellule*)malloc (sizeof(Cellule));
    celPointer(temp, pL->adPremiere);
    celSetInfo(temp,'*');
    celSetX(temp,pL->adPremiere->x + 1);
    celSetY(temp,pL->adPremiere->y);

    pL->adPremiere = temp;
}

/*Ajout une cellule en tete en haut*/
void lisAjoutTeteHaut(Liste *pL)
{
    Cellule * temp;
    temp = (Cellule*)malloc (sizeof(Cellule));
    celPointer(temp, pL->adPremiere);
    celSetInfo(temp,'*');
    celSetX(temp,pL->adPremiere->x);
    celSetY(temp,pL->adPremiere->y-1);

    pL->adPremiere = temp;
}

/*Ajout une cellule en tete en bas*/
void lisAjoutTeteBas(Liste *pL)
{
    Cellule * temp;
    temp = (Cellule*)malloc (sizeof(Cellule));
    celPointer(temp, pL->adPremiere);
    celSetInfo(temp,'*');
    celSetX(temp,pL->adPremiere->x);
    celSetY(temp,pL->adPremiere->y+1);

    pL->adPremiere = temp;
}

/*Ajout une queue a la fin de la liste; les tests pour positionner sont à faire*/
void lisAjoutQueuePos(Liste *pL, const int i, const int j)
{
    Cellule * temp;
    temp = (Cellule*)malloc (sizeof(Cellule));
    temp->suivant = NULL;
    celSetInfo(temp,'*');
    celSetX(temp,i);
    celSetY(temp,j);

    celPointer(pL->adDerniere,temp);
    pL->adDerniere = temp;
}

void lisAjoutQueue(Liste *pL)
{
    Cellule * temp;
    temp = (Cellule*)malloc (sizeof(Cellule));
    temp->suivant = NULL;
    celSetInfo(temp,'*');
    celSetX(temp,pL->adDerniere->x-1);
    celSetY(temp,pL->adDerniere->y);
    celPointer(pL->adDerniere,temp);
    pL->adDerniere = temp;
}

/*Supprime la tete su snake*/
void lisSuppTete(Liste *pL)
{
    Cellule *temp;
    temp = pL->adPremiere;
    pL->adPremiere = pL->adPremiere->suivant;
    free(temp);
}

/*Supprime la queue du snake*/
void lisSuppQueue(Liste *pL)
{
    Cellule *temp;
    temp = pL->adPremiere;
    while (temp->suivant->suivant!=NULL)
    {
        temp=temp->suivant;
    }
    free(temp->suivant);
    pL->adDerniere=temp;
    pL->adDerniere->suivant=NULL;
}

Cellule* lisGetTete(Liste *pL)
{
    return pL->adPremiere;
}

Cellule* lisGetQueue(Liste *pL)
{
    return pL->adDerniere;
}

Cellule* lisSuivant(Liste *pL)
{
    return pL->adPremiere->suivant;
}
