/**
@brief cellule.h a toutes les entetes des fonctions pour le module cellule.
@author Roberto Medina Bonilla & Yoann Jouvent
@file src/cellule.h
@version 1.0
@date 2012/03/26
*/
#ifndef _CELLULE_H
#define _CELLULE_H

struct sCellule
{
    char info ;
    int x, y;
    struct sCellule * suivant ;
};
typedef struct sCellule Cellule;

/**@brief Renvoie le caractère de la cellule
@param [in] pC est un pointeur sur la structure Cellule
@return Caractère\n
Example code block
@code
c=celGetInfo(temp);
@endcode
*/
char celGetInfo(const Cellule *pC);

/**@brief Renvoie la composante en X de la cellule
@param [in] pC est un pointeur sur la structure Cellule
@return Entier\n
Example code block
@code
X=celGetX(temp);
@endcode
*/
int celGetX(const Cellule *pC);

/**@brief Renvoie la composante en Y de la cellule
@param [in] pC est un pointeur sur la structure Cellule
@return Entier\n
Example code block
@code
Y=celGetY(temp);
@endcode
*/
int celGetY(const Cellule *pC);

/**@brief Modifie le caractère de la Cellule par le caractère passé en paramètre
@param [in,out] pC est un pointeur sur la structure Cellule
@param [in] cChange est un caractère
@return none\n
Example code block
@code
celSetInfo(temp,'g');
@endcode
*/
void celSetInfo(Cellule *pC, const char cChange);

/**@brief Modifie la composante en X de la Cellule par l'entier passé en paramètre
@param [in,out] pC est un pointeur sur la structure Cellule
@param [in] xChange est un entier
@return none\n
Example code block
@code
celSetX(temp,5);
@endcode
*/
void celSetX(Cellule *pC, const int xChange);

/**@brief Modifie la composante en Y de la Cellule par l'entier passé en paramètre
@param [in,out] pC est un pointeur sur la structure Cellule
@param [in] yChange est un entier
@return none\n
Example code block
@code
celSetY(temp,8);
@endcode
*/
void celSetY(Cellule *pC, const int yChange);

/**@brief Fait pointer le champ suivant dans Cellule sur l'autre Cellule passée en paramètre
@param [in,out] pC1 est un pointeur sur la structure Cellule
@param [in,out] pC2 est un pointeur sur la structure Cellule
@return none\n
Example code block
@code
celSetY(temp,&cellule);
@endcode
*/
void celPointer (Cellule *pC1, Cellule *pC2);

#endif
