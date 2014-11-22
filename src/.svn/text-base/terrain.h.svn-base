/**
@brief terrain.h a toutes les entetes des fonctions pour le module terrain.
@author Roberto Medina Bonilla & Yoann Jouvent
@file src/terrain.h
@version 1.0
@date 2012/06/07
*/
#ifndef _TERRAIN_H
#define _TERRAIN_H

typedef struct
{
	int dimx;
	int dimy;
	char **tab;
} Terrain;

/**@brief Libere la place allouee pour le terrain
@param [in,out] pTer est un pointeur sur terrain
@return none\n
Example code block
@code
terLibere(&ter);
@endcode
*/
void terLibere(Terrain *pTer);

/**@brief Teste si la position passee en parametre est valide (pas un # ou dehors des dimentions)
@param [in] pTer est un pointeur sur terrain
@param [in] x est un entier
@param [in] y est un entier
@return Entier\n
Example code block
@code
terEstPositionPersoValide(&ter,12,34);
@endcode
*/
int terEstPositionPersoValide(const Terrain *pTer, const int x, const int y);

/**@brief Retourne le caractere du terrain de la position passee en parametre
@param [in] pTer est un pointeur sur terrain
@param [in] x est un entier
@param [in] y est un entier
@return Caractere\n
Example code block
@code
terGetXY(&ter,3,14);
@endcode
*/
const char terGetXY(const Terrain *pTer, const int x, const int y);

/**@brief On remplace le caractère de la position donnee par le caractère passé en paramètre
@param [in,out] pTer est un pointeur sur terrain
@param [in] x est un entier
@param [in] y est un entier
@param [in] val est un caractère
@return none\n
Example code block
@code
terSetXY(&ter,15,4,'^');
@endcode
*/
void terSetXY(Terrain *pTer, const int x, const int y, const char val);

/**@brief Renvoie la longueur du terrain
@param [in] pTer est un pointeur sur terrain
@return Entier\n
Example code block
@code
longueur=getDimX(&ter);
@endcode
*/
const int getDimX(const Terrain *pTer);

/**@brief Renvoie la largeur du terrain
@param [in] pTer est un pointeur sur terrain
@return Entier\n
Example code block
@code
largeur=getDimY(&ter);
@endcode
*/
const int getDimY(const Terrain *pTer);

/**@brief Remplit le tableau de caractères du terrain à partir d'un fichier
@param [in] Fic est un fichier texte
@param [in,out] pTer est un pointeur sur terrain
@return none\n
Example code block
@code
terSetXY("data/snkLevel2.txt",&ter);
@endcode
*/
void terAfficheDepuisFichier(const char *Fic,Terrain *pTer);


#endif
