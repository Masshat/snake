/**
@brief sdlJeu.h a les entetes des fonctions du module.
@author Roberto Medina Bonilla & Yoann Jouvent
@file src/sdlJeu.h
@version 1.0
@date 2012/06/07
*/
#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "jeu.h"


typedef struct
{
	Jeu jeu;
	SDL_Surface* surface_ecran, *surface_snake,*surface_mur,*surface_nourriture,* surface_texte, *surface_instruction;
	SDL_Surface *surface_titre, *surface_choix0, *surface_choix1, *surface_choix2, *surface_choix3, *surface_choix4, *surface_m_score;
	SDL_Rect pos_titre, pos_choix1, pos_choix2, pos_choix3, pos_choix4, pos_choix0, pos_score,  pos_instruction, pos_m_score;
    TTF_Font* police, *police_menu, *police_titre;
    int flag_jeu,flag_instruction;
} sdlJeu;

/**@brief Initialise le jeu et ses composantes et les fonts avec quelques textes
@param [in,out] pSdlJeu est un pointeur sur la structure sdlJeu
@return none\n
Example code block
@code
sdljeuInit(&sdlJeu);
@endcode
*/
void sdljeuInit(sdlJeu *pSdlJeu);

/**@brief Boucle d'événements pour le menu du jeu
@param [in,out] pSdlJeu est un pointeur sur la structure sdlJeu
@return none\n
Example code block
@code
sdlMenu(&sdlJeu);
@endcode
*/
void sdlMenu(sdlJeu *pSdlJeu);

/**@brief Boucle d'événements pour le jeu
@param [in,out] pSdlJeu est un pointeur sur la structure sdlJeu
@return none\n
Example code block
@code
sdljeuBoucle(&sdlJeu);
@endcode
*/
void sdljeuBoucle(sdlJeu *pSdlJeu);

/**@brief Procédure qui libère le jeu et ses composantes et les surfaces allouées par SDL
@param [in,out] pSdlJeu est un pointeur sur la structure sdlJeu
@return none\n
Example code block
@code
sdljeuDetruit(&sdlJeu);
@endcode
*/
void sdljeuDetruit(sdlJeu *pSdlJeu);


#endif

