/**
@brief nourriture.c a le code pour le module nourriture
@author Roberto Medina Bonilla & Yoann Jouvent
@file src/nourriture.c
@version 1.0
@date 2012/06/07
*/
#include <stdlib.h>
#include "nourriture.h"
#include "terrain.h"

/*Procédure qui place aléatoirement la nourriture du snake*/
void nourPosition(const Terrain *pTer,Nourriture* nour)
{
    int i,j;
    i = rand()%(pTer->dimx);
    j = rand()%(pTer->dimy);
    while (pTer->tab[i][j]=='#')
    {
        i = rand()%(pTer->dimx);
        j = rand()%(pTer->dimy);
    }
    nour->x=i;
    nour->y=j;
    nour->n='0';
}

/*Renvoie le caractère de la structure nourriture*/
char nourGetChar(const Nourriture *nour)
{
    return nour->n;
}

/*Renvoie la composantes en x de la structure nourriture*/
int nourGetX(const Nourriture *nour)
{
    return nour->x;
}

/*Renvoie la composantes en y de la structure nourriture*/
int nourGetY(const Nourriture *nour)
{
    return nour->y;
}
