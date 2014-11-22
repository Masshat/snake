/**
@brief jeu.h a toutes les entetes des fonctions pour le module jeu.
@author Roberto Medina Bonilla & Yoann Jouvent
@file src/jeu.h
@version 1.0
@date 2012/06/07
*/

#ifndef _JEU_H
#define _JEU_H

#include "snake.h"
#include "terrain.h"
#include "nourriture.h"

typedef struct
{
	Terrain ter;
	Snake snk;
	Nourriture nour;
	int niveau;
	char max_score [7];
	char instruction[60];

} Jeu;

/**@brief Initialise le jeu
@param [in,out] pJeu est un pointeur sur jeu qui va etre initialise
@return none\n
Example code block
@code
jeuInit(&jeu);
@endcode
*/
void jeuInit(Jeu *pJeu);

/**@brief Libère le jeu et ses composantes
@param [in,out] pJeu est un pointeur sur jeu qui va etre libere
@return none\n
Example code block
@code
jeuLibere(&jeu);
@endcode
@warning Jeu doit etre initialise
*/
void jeuLibere(Jeu *pJeu);

/**@brief Renvoie un pointeur sur le terrain du jeu
@param [in,out] pJeu est un pointeur
@return Pointeur sur Terrain\n
Example code block
@code
pTer=jeuGetTerrainPtr(&jeu);
@endcode
@warning Jeu doit etre initisalise
*/
Terrain *jeuGetTerrainPtr(Jeu *pJeu);

/**@brief Renvoie un pointeur sur le snake du jeu
@param [in,out] pJeu est un pointeur
@return Pointeur sur Snake\n
Example code block
@code
pSnk=jeuGetSnakePtr(&jeu);
@endcode
@warning Jeu doit etre initisalise
*/
Snake *jeuGetSnakePtr(Jeu *pJeu);

/**@brief Renvoie un pointeur sur la nourriture
@param [in,out] pJeu est un pointeur
@return Pointeur sur Nourriture\n
Example code block
@code
pNour=jeuGetNourPtr(&jeu);
@endcode
@warning Jeu doit etre initisalise
*/
Nourriture *jeuGetNourPtr(Jeu *pJeu);

/**@brief Renvoie les donnees du terrain sans les modifier
@param [in] pJeu est un pointeur
@return Pointeur sur Terrain\n
Example code block
@code
pTer=jeuGetConstTerrainPtr(&jeu);
@endcode
@warning Jeu doit etre initisalise
*/
const Terrain *jeuGetConstTerrainPtr(const Jeu *pJeu);

/**@brief Renvoie les donnees du snake sans les modifier
@param [in] pJeu est un pointeur
@return Pointeur sur Snake\n
Example code block
@code
pSnk=jeuGetConstSnakePtr(&jeu);
@endcode
@warning Jeu doit etre initisalise
*/
const Snake *jeuGetConstSnakePtr(const Jeu *pJeu);

/**@brief Renvoie les donnees de la nourriture sans les modifier
@param [in] pJeu est un pointeur
@return Pointeur sur Nourriture\n
Example code block
@code
pNour=jeuGetConstNourPtr(&jeu);
@endcode
@warning Jeu doit etre initisalise
*/
const Nourriture *jeuGetConstNourPtr(const Jeu *pJeu);

/**@brief Recupere l'action faite par l'utilisateur
@param  [in] pJeu est un pointeur
@param [out] touche est un caractere
@return none\n
Example code block
@code
jeuActionClavier(&jeu,touche);
@endcode
@warning Jeu doit etre initisalise
*/
void jeuActionClavier(Jeu *pJeu, const char touche);

/**@brief Teste le score de l'utilisateur et change de niveau
@param [in,out] pJeu est un pointeur
@return none\n
Example code block
@code
jeuChangeNiveau(&jeu);
@endcode
@warning Jeu doit etre initisalise
*/
void jeuChangeNiveau(Jeu *pJeu);

/**@brief Fait avancer le snake du jeu tant que la direction de celui-ci ne change pas
@param [in,out] pJeu est un pointeur
@return none\n
Example code block
@code
jeuAvance(&jeu);
@endcode
@warning Jeu doit etre initisalise
*/
void jeuAvance(Jeu *pJeu);

/**@brief Renvoie le niveau du jeu
@param [in] pJeu est un pointeur
@return none\n
Example code block
@code
niv=jeuGetNiveau(&jeu);
@endcode
@warning Jeu doit etre initisalise
*/
const int jeuGetNiveau (const Jeu *pJeu);

/**@brief Change le niveau du jeu
@param [in] pJeu est un pointeur
@param [in] n est un entier
@return none\n
Example code block
@code
jeuSetNiveau(&jeu,2);
jeuSetNiveau(&jeu,5);
@endcode
@warning Jeu doit etre initisalise
*/
void jeuSetNiveau (Jeu *pJeu,const int n);

/**@brief Renvoie un entier quand on perd
@param [in,out] pJeu est un pointeur
@return Entier\n
Example code block
@code
perdu=jeuPerdre(&jeu);
@endcode
@warning Jeu doit etre initisalise
*/
int jeuPerdre (Jeu *pJeu);

/**@brief A partir d'un fichier on remplit le tableau de la structure Jeu pour obtenir le score
@param [in,out] pJeu est un pointeur
@param [in] monFic est le nom du fichier
@return none\n
Example code block
@code
jeuGetScore(data/maxscore.txt,&jeu);
@endcode
@warning Jeu doit etre initisalise
*/
void jeuGetScore (const char * monFic, Jeu *pJeu);

/**@brief A partir d'un fichier on remplit le tableau de la structure Jeu pour obtenir le score
@param [in,out] pJeu est un pointeur
@param [in,out] monFic est le nom du fichier
@return none\n
Example code block
@code
jeuSetScore(data/maxscore.txt,&jeu);
@endcode
@warning Jeu doit etre initisalise
*/
void jeuSetScore (char* monFic, const Jeu *pJeu);

/**@brief A partir d'un fichier on remplit le tableau des instructions du jeu
@param [in,out] pJeu est un pointeur
@param [in] monFic est le nom du fichier
@return none\n
Example code block
@code
jeuInstruction(data/instruction.txt,&jeu);
@endcode
@warning Jeu doit etre initisalise
*/
void jeuInstruction(const char * monFic,Jeu *pJeu);

#endif
