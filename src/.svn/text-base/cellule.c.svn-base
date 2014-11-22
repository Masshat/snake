/**
@brief cellule.c a toutes les implémentations du module cellule.
@author Roberto Medina Bonilla & Yoann Jouvent
@file src/cellule.c
@version 1.0
@date 2012/03/26
*/
#include <stdlib.h>
#include "cellule.h"

/*---------------Acceseurs et mutateurs pour info---------------------*/
char celGetInfo (const Cellule *pC)
{
    return pC->info;
}

void celSetInfo (Cellule *pC, const char cChange)
{
    pC->info=cChange;
}

/*----------------Acceseurs et mutateurs pour x-----------------------*/
int celGetX (const Cellule *pC)
{
    return pC->x;
}

void celSetX (Cellule *pC, const int xChange)
{
    pC->x=xChange;
}

/*----------------Acceseurs et mutateurs pour y----------------------*/
int celGetY (const Cellule *pC)
{
    return pC->y;
}

void celSetY (Cellule *pC, const int yChange)
{
    pC->y=yChange;
}

/*Fait pointeur le champ suivant de pC1 sur pC2*/
void celPointer (Cellule *pC1, Cellule *pC2)
{
    pC1->suivant=pC2;
}
