/**
@brief snake.h a toutes les entetes des fonctions pour le module snake.
@author Roberto Medina Bonilla & Yoann Jouvent
@file src/snake.h
@version 1.0
@date 2012/06/07
*/

#ifndef __SNAKE_H
#define __SNAKE_H

#include "liste.h"
#include "terrain.h"
#include "nourriture.h"

typedef struct
{
    Liste *snkListe;
    int taille,germ,posGermX, posGermY,score,vies;
    char dir;
} Snake;

/**@brief Initialise le snake avec une taille et une position initiale et le score à 0
@param [in,out] pSnk est un pointeur sur la structure Snake
@return none\n
Example code block
@code
snkInit(&snk);
@endcode
*/
void snkInit(Snake *pSnk);

/**@brief Initialise le snake après avoir perdu une vie
@param [in,out] pSnk est un pointeur sur la structure Snake
@return none\n
Example code block
@code
snkInitPerdu(&snk);
@endcode
*/
void snkInitPerdu(Snake *pSnk);

/**@brief Libere la place allouée par le snake
@param [in,out] pSnk est un pointeur sur la structure Snake
@return none\n
Example code block
@code
snkLibere(&snk);
@endcode
*/
void snkLibere(Snake *pSnk);

/**@brief Retourne la composantes en X du Snake
@param [in] pSnk est un pointeur sur la structure Snake
@return Entier\n
Example code block
@code
posX=snkGetX(&snk);
@endcode
*/
const int snkGetX(const Snake *pSnk);

/**@brief Retourne la composantes en Y du Snake
@param [in] pSnk est un pointeur sur la structure Snake
@return Entier\n
Example code block
@code
posY=snkGetY(&snk);
@endcode
*/
const int snkGetY(const Snake *pSnk);

/**@brief Retourne la taille du Snake
@param [in] pSnk est un pointeur sur la structure Snake
@return Entier\n
Example code block
@code
taille=snkGetTaille(&snk);
@endcode
*/
const int snkGetTaille (const Snake *pSnk);

/**@brief Retourne le score du Snake
@param [in] pSnk est un pointeur sur la structure Snake
@return Entier\n
Example code block
@code
score=snkGetScore(&snk);
@endcode
*/
const int snkGetScore (const Snake *pSnk);

/**@brief Retourne la direction du Snake
@param [in] pSnk est un pointeur sur la structure Snake
@return Caratere\n
Example code block
@code
dir=snkGetDir(&snk);
@endcode
*/
const char snkGetDir(const Snake*pSnk);

/**@brief Retourne le nombre de vies restant
@param [in] pSnk est un pointeur sur la structure Snake
@return Entier\n
Example code block
@code
vies=snkGetVies(&snk);
@endcode
*/
const int snkGetVies(const Snake*pSnk);

/**@brief Incrémente de 1 la taille du Snake
@param [in,out] pSnk est un pointeur sur la structure Snake
@return none\n
Example code block
@code
snkSetTaille(&snk);
@endcode
*/
void snkSetTaille (Snake *pSnk);

/**@brief Dirige le Snake à gauche si possible et teste si il a mangé ou s'il doit grandir
@param [in,out] pSnk est un pointeur sur la structure Snake
@param [in] pTer est un pointeur sur la structure Terrain
@param [in,out] pNour est un pointeur sur la structure Nourriture
@return none\n
Example code block
@code
snkGauche(&snk,&ter,&nour);
@endcode
*/
void snkGauche(Snake *pSnk, const Terrain *pTer, Nourriture *pNour);

/**@brief Dirige le Snake à droite si possible et teste si il a mangé ou s'il doit grandir
@param [in,out] pSnk est un pointeur sur la structure Snake
@param [in] pTer est un pointeur sur la structure Terrain
@param [in,out] pNour est un pointeur sur la structure Nourriture
@return none\n
Example code block
@code
snkGauche(&snk,&ter,&nour);
@endcode
*/
void snkDroite(Snake *pSnk, const Terrain *pTer, Nourriture *pNour);

/**@brief Dirige le Snake vers le haut si possible et teste si il a mangé ou s'il doit grandir
@param [in,out] pSnk est un pointeur sur la structure Snake
@param [in] pTer est un pointeur sur la structure Terrain
@param [in,out] pNour est un pointeur sur la structure Nourriture
@return none\n
Example code block
@code
snkHaut(&snk,&ter,&nour);
@endcode
*/
void snkHaut(Snake *pSnk, const Terrain *pTer, Nourriture *pNour);

/**@brief Dirige le Snake vers le bas si possible et teste si il a mangé ou s'il doit grandir
@param [in,out] pSnk est un pointeur sur la structure Snake
@param [in] pTer est un pointeur sur la structure Terrain
@param [in,out] pNour est un pointeur sur la structure Nourriture
@return none\n
Example code block
@code
snkBas(&snk,&ter,&nour);
@endcode
*/
void snkBas(Snake *pSnk, const Terrain *pTer, Nourriture *pNour);

/**@brief Rajoute une queue au Snake à gauche de l'ancienne queue
@param [in,out] pSnk est un pointeur sur la structure Snake
@return none\n
Example code block
@code
snkAjoutQueue(&snk);
@endcode
*/
void snkAjoutQueue(Snake *pSnk);

/**@brief Renvoie la position de la tête du Snake
@param [in] pSnk est un pointeur sur la structure Snake
@return none\n
Example code block
@code
snkGetCharXY(&snk);
@endcode
*/
const char snkGetCharXY(const Snake *pSnk);

/**@brief Rajoute des queues au snake en fonction de la taille de celui-ci
@param [in,out] pSnk est un pointeur sur la structure Snake
@return none\n
Example code block
@code
snkCreation(&snk);
@endcode
*/
void snkCreation(Snake *pSnk);

#endif
