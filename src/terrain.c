/**
@brief terrain.c a le code des fonctions pour le module terrain.
@author Roberto Medina Bonilla & Yoann Jouvent
@file src/terrain.c
@version 1.0
@date 2012/06/07
*/
#include "terrain.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

/* Libere la memoire alloue pour creer le terrain */
void terLibere(Terrain *pTer)
{
	int x;
    for (x=0; x<pTer->dimx; x++)
    {
        free(pTer->tab[x]);
    }
	free(pTer->tab);

	pTer->dimx = 0;
	pTer->dimy = 0;
	pTer->tab = NULL;
}


/* Valide la position de l'objet sur le terrain */
int terEstPositionPersoValide(const Terrain *pTer, const int x, const int y)
{
	if (x>=0 && x<pTer->dimx && y>=0 && y<pTer->dimy && pTer->tab[x][y]!='#')
		return 1;
	else
		return 0;
}

/* Retourne le tableau de dimension x et y */
const char terGetXY(const Terrain *pTer, const int x, const int y)
{
	assert( x>=0) ;
	assert( y>=0) ;
	assert( x<pTer->dimx ) ;
	assert( y<pTer->dimy ) ;
	return pTer->tab[x][y];
}

/* Change la valeur du pointeur */
void terSetXY(Terrain *pTer, const int x, const int y, const char val)
{
	assert( x>=0) ;
	assert( y>=0) ;
	assert( x<pTer->dimx ) ;
	assert( y<pTer->dimy ) ;
	pTer->tab[x][y] = val;
}

/*Renvoie la longueur du terrain*/
const int getDimX(const Terrain *pTer)
{
	return pTer->dimx;
}

/*Renvoir la largeur du terrain*/
const int getDimY(const Terrain *pTer)
{
	return pTer->dimy;
}

/*A partir d'un fichier va remplir le tableau contenu dans la structure Terran*/
void terAfficheDepuisFichier (const char * Fic,Terrain *pTer)
{
    int i,j;
    char tmp;
    char monFic2[64];
    FILE * FicA;
    FicA = fopen (Fic,"r");
    if(FicA == NULL)
    {
        sprintf( monFic2, "../%s", Fic);
        FicA = fopen (monFic2,"r");
    }
    if(FicA == NULL)
    {
        printf("Terrain: Impossible d'ouvrir le fichier \n");
        exit(EXIT_FAILURE);
    }

    pTer->dimx = 30;
    pTer->dimy = 12;


    pTer->tab = (char **)malloc(sizeof(char *)*pTer->dimx);
    for (i=0; i<pTer->dimx; i++)
    {
        pTer->tab[i] = (char *)malloc(sizeof(char)*pTer->dimy);
    }
    for(i=0;i<pTer->dimy;i++)
    {
        for(j=0;j<pTer->dimx;j++)
        {
            fscanf(FicA,"%c",&pTer->tab[j][i]);
        }
        fscanf(FicA,"%c",&tmp);
        fscanf(FicA,"%c",&tmp);
    }
    if(feof(FicA))
    {
        printf("Terrain: Fin de fichier \n");
    }
    else
    {
        printf("Terrain: Pas de probleme \n");
    }

}

