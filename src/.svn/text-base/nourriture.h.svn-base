/**
@brief nourriture.h a les entêtes pour le module nourriture
@author Roberto Medina Bonilla & Yoann Jouvent
@file src/nourriture.h
@version 1.0
@date 2012/06/07
*/
#ifndef __NOURRITURE_H
#define __NOURRITURE_H


#include "terrain.h"

typedef struct
{
    int x;
    int y;
    char n;
}Nourriture;

/**@brief Place la nourriture aléatoirement sur le terrain en testant si celle-ci n'est pas placée sur un mur
@param [in] pTer est un pointeur sur terrain
@param [in,out] pNour est un pointeur sur nourriture
@return none\n
Example code block
@code
nourPosition(&ter,&nour);
@endcode
*/
void nourPosition(const Terrain *pTer,Nourriture *pNour);

/**@brief Retourne le caractère de la nourriture
@param [in] pNour est un pointeur sur nourriture
@return caractère\n
Example code block
@code
char c;
c=nourGetChar(&nour);
@endcode
*/
char nourGetChar(const Nourriture *pNour);

/**@brief Retourne la composante en x de la nourriture
@param [in] pNour est un pointeur sur nourriture
@return entier\n
Example code block
@code
int x;
x=nourGetX(&nour);
@endcode
*/
int nourGetX(const Nourriture *pNour);

/**@brief Retourne la composante en y de la nourriture
@param [in] pNour est un pointeur sur nourriture
@return entier\n
Example code block
@code
int y;
y=nourGetY(&nour);
@endcode
*/
int nourGetY(const Nourriture *pNour);

#endif
