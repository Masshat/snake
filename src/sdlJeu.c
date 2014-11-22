/**
@brief sdlJeu.c a le code des fonctions pour le module sdlJeu.
@author Roberto Medina Bonilla & Yoann Jouvent
@file src/sdlJeu.c
@version 1.0
@date 2012/06/07
*/
#include <assert.h>
#include "sdlJeu.h"

const int TAILLE_SPRITE=32;

SDL_Surface *SDL_load_image(const char* filename );

void SDL_apply_surface( SDL_Surface* source, SDL_Surface* destination, int x, int y );


/*Fonction qui initialise le jeu Sdl et les différentes composantes*/
void sdljeuInit(sdlJeu *pSdlJeu)
{
	int dimx, dimy;
/*------------------------------------------------ Partie dédiée aux textes en TTF ------------------------------------------------*/

	jeuInit(&(pSdlJeu->jeu));

    /*Chargement des polices et initialisation de TTF*/
    TTF_Init();
    pSdlJeu->police = TTF_OpenFont("data/Anasthesia.ttf", 32);
    pSdlJeu->police_menu = TTF_OpenFont("data/Mashed.ttf", 32);
    pSdlJeu->police_titre = TTF_OpenFont("data/Mashed.ttf", 60);



/*---------------------------------------------Initialisation du jeu et des surfaces du snake-------------------------------*/

	assert( SDL_Init( SDL_INIT_EVERYTHING )!= -1 );

    /*Initialisation des flags pour la liberation des espaces*/
    pSdlJeu->flag_jeu=0;
    pSdlJeu->flag_instruction=0;

    /*Initialisation de l'écran*/
	dimx = getDimX( jeuGetConstTerrainPtr(&(pSdlJeu->jeu)) );
	dimy = getDimY( jeuGetConstTerrainPtr(&(pSdlJeu->jeu)) );
	dimx = dimx * TAILLE_SPRITE;
	dimy = dimy * TAILLE_SPRITE+50;
	pSdlJeu->surface_ecran = SDL_SetVideoMode(dimx, dimy, 32, SDL_SWSURFACE );
	assert( pSdlJeu->surface_ecran!=NULL);
	SDL_WM_SetCaption( "Snake", NULL );


	pSdlJeu->surface_snake = SDL_load_image("data/vert1.bmp");
	if (pSdlJeu->surface_snake==NULL)
		pSdlJeu->surface_snake = SDL_load_image("../data/vert1.bmp");
	assert( pSdlJeu->surface_snake!=NULL);

	pSdlJeu->surface_mur = SDL_load_image("data/mur1.bmp");
	if (pSdlJeu->surface_mur==NULL)
		pSdlJeu->surface_mur = SDL_load_image("../data/mur1.bmp");
	assert( pSdlJeu->surface_mur!=NULL);

    pSdlJeu->surface_nourriture = SDL_load_image("data/pomme.bmp");
	if (pSdlJeu->surface_mur==NULL)
		pSdlJeu->surface_mur = SDL_load_image("../data/pomme.bmp");
	assert( pSdlJeu->surface_mur!=NULL);
}

/*Fonction qui affiche les éléments du jeu*/
void sdljeuAff(sdlJeu *pSdlJeu)
{
	int x,y,i;
    Cellule *temp;
	const Terrain *pTer = jeuGetConstTerrainPtr(&(pSdlJeu->jeu));
	const Snake *pSnk = jeuGetConstSnakePtr(&(pSdlJeu->jeu));
	const Nourriture *pNour = jeuGetConstNourPtr(&(pSdlJeu->jeu));
	temp=pSnk->snkListe->adPremiere;

	/* Remplir l'écran de blanc */
	SDL_FillRect( pSdlJeu->surface_ecran, &pSdlJeu->surface_ecran->clip_rect, SDL_MapRGB( pSdlJeu->surface_ecran->format, 0xFF, 0xFF, 0xFF ) );

	for (x=0;x<getDimX(pTer);++x)
		for (y=0;y<getDimY(pTer);++y)
			if (terGetXY(pTer,x,y)=='#')
				SDL_apply_surface(  pSdlJeu->surface_mur, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, y*TAILLE_SPRITE);

	/* Copier le sprite de Snake sur l'écran */
	for (i=0;i<snkGetTaille(pSnk);i++)
	{
	   SDL_apply_surface(  pSdlJeu->surface_snake, pSdlJeu->surface_ecran, celGetX(temp)*TAILLE_SPRITE,  celGetY(temp)*TAILLE_SPRITE );
	   temp=temp->suivant;
	}

	SDL_apply_surface(  pSdlJeu->surface_nourriture, pSdlJeu->surface_ecran, nourGetX(pNour)*TAILLE_SPRITE,nourGetY(pNour)*TAILLE_SPRITE );
}

/*Fonction intermédiaire pour l'affichage des instructions*/
void sdlInstructionAff(sdlJeu *pSdlJeu)
{
    SDL_FillRect( pSdlJeu->surface_ecran, &pSdlJeu->surface_ecran->clip_rect, SDL_MapRGB( pSdlJeu->surface_ecran->format, 0xFF, 0xFF, 0xFF ) );
}

/*Boucle qui affiche les instructions tant qu'on n'a pas quitté*/
void sdlInstruction(sdlJeu *pSdlJeu)
{
    /*Variables utilisées pour l'affichage de texte*/
	SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
    SDL_Event event;
    int continue_boucle = 1;
    char i[7];
    sdlInstructionAff(pSdlJeu);

    /*Initialisation des surfaces textes pour les instructions*/
    jeuInstruction("data/instruction.txt",&(pSdlJeu->jeu));
    pSdlJeu->surface_instruction = TTF_RenderText_Shaded(pSdlJeu->police,pSdlJeu->jeu.instruction,couleurNoire,couleurBlanche);
    sprintf(i,"Retour");
    pSdlJeu->surface_choix4 = TTF_RenderText_Shaded(pSdlJeu->police_menu, i, couleurNoire, couleurBlanche);

    /* tant que ce n'est pas la fin ... */
	while ( continue_boucle == 1 )
	{
		/* tant qu'il y a des evenements à traiter : cette boucle n'est pas bloquante */
		while ( SDL_PollEvent( &event ) )
		{
			/* Si l'utilisateur a cliqué sur la croix de fermeture */
			if ( event.type == SDL_QUIT )
			        continue_boucle = 0;

            if ( event.type == SDL_KEYDOWN )
			{
				switch ( event.key.keysym.sym )
				{
                    case SDLK_r:
                        continue_boucle = 0;
                    break;
                    default: printf("Choix non traité par le programme\n");
                }
            }

        }
        pSdlJeu->pos_choix4.x = 50;
        pSdlJeu->pos_choix4.y = 400;
        pSdlJeu->pos_instruction.x = 0;
        pSdlJeu->pos_instruction.y = 200;

        SDL_BlitSurface(pSdlJeu->surface_choix4, NULL, pSdlJeu->surface_ecran, &(pSdlJeu->pos_choix4));
        SDL_BlitSurface(pSdlJeu->surface_instruction, NULL, pSdlJeu->surface_ecran, &(pSdlJeu->pos_instruction));

        SDL_Flip( pSdlJeu->surface_ecran );
	}
}

/*Procédure qui initialise les éléments du menu*/
void sdlMenuAff(sdlJeu *pSdlJeu)
{
    SDL_FillRect( pSdlJeu->surface_ecran, &pSdlJeu->surface_ecran->clip_rect, SDL_MapRGB( pSdlJeu->surface_ecran->format, 0xFF, 0xFF, 0xFF ) );
}

/*Boucle qui affiche le menu tant qu'on n'a pas choisi une option*/
void sdlMenu (sdlJeu *pSdlJeu)
{
    SDL_Event event;
	int continue_boucle = 1;
    /*Variables utilisées pour l'affichage de texte*/
	SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255}, couleurVerte = {10,150,50}, couleurRouge = {150,0,50};
	char t[20],c0[15],c1[15],c2[15],c3[15];

    sdlMenuAff(pSdlJeu);
	assert( SDL_Flip( pSdlJeu->surface_ecran )!=-1 );


    /*Initialisation des surfaces pour le menu*/
    sprintf(t, "Snake");
    pSdlJeu->surface_titre = TTF_RenderText_Shaded(pSdlJeu->police_titre, t, couleurVerte, couleurBlanche);
    sprintf(c1, "j: Jouer");
    pSdlJeu->surface_choix1 = TTF_RenderText_Shaded(pSdlJeu->police_menu, c1, couleurNoire, couleurBlanche);
    sprintf(c2, "i: Instructions");
    pSdlJeu->surface_choix2 = TTF_RenderText_Shaded(pSdlJeu->police_menu, c2, couleurNoire, couleurBlanche);
    sprintf(c3, "Meilleur score");
    pSdlJeu->surface_choix3 = TTF_RenderText_Shaded(pSdlJeu->police_menu, c3, couleurNoire, couleurBlanche);
    sprintf(c0, "q: Quitter");
    pSdlJeu->surface_choix0 = TTF_RenderText_Shaded(pSdlJeu->police_menu, c0, couleurNoire, couleurBlanche);
    pSdlJeu->surface_m_score = TTF_RenderText_Shaded(pSdlJeu->police_menu, pSdlJeu->jeu.max_score, couleurRouge, couleurBlanche);

	/* tant que ce n'est pas la fin ... */
	while ( continue_boucle == 1 )
	{
		/* tant qu'il y a des evenements à traiter : cette boucle n'est pas bloquante */
		while ( SDL_PollEvent( &event ) )
		{
			/* Si l'utilisateur a cliqué sur la croix de fermeture */
			if ( event.type == SDL_QUIT )
				continue_boucle = 0;

            if ( event.type == SDL_KEYDOWN )
			{
				switch ( event.key.keysym.sym )
				{
                    case SDLK_j:
                        continue_boucle = 0;
                        pSdlJeu->flag_jeu = 1;
                        sdljeuBoucle(pSdlJeu);
                    break;
                    case SDLK_i:
                        pSdlJeu->flag_instruction=1;
                        sdlInstruction(pSdlJeu);
                    break;
                    case SDLK_q:
                        continue_boucle = 0;
                    break;
                    default: printf("Choix non traité par le programme\n");
                }
            }
        }



		/* on affiche le jeu sur le buffer caché */
		sdlMenuAff(pSdlJeu);

        /*Positionnement des surfaces pour le menu*/
        pSdlJeu->pos_titre.x = 400;
        pSdlJeu->pos_titre.y = 0;
        pSdlJeu->pos_choix1.x = 300;
        pSdlJeu->pos_choix1.y = 100;
        pSdlJeu->pos_choix2.x = 300;
        pSdlJeu->pos_choix2.y = 200;
        pSdlJeu->pos_choix3.x = 300;
        pSdlJeu->pos_choix3.y = 300;
        pSdlJeu->pos_choix0.x = 300;
        pSdlJeu->pos_choix0.y = 400;
        pSdlJeu->pos_m_score.x =580;
        pSdlJeu->pos_m_score.y =300;

        /*Affichage des textes en ttf*/
        SDL_BlitSurface(pSdlJeu->surface_titre, NULL, pSdlJeu->surface_ecran, &(pSdlJeu->pos_titre));
        SDL_BlitSurface(pSdlJeu->surface_choix1, NULL, pSdlJeu->surface_ecran, &(pSdlJeu->pos_choix1));
        SDL_BlitSurface(pSdlJeu->surface_choix2, NULL, pSdlJeu->surface_ecran, &(pSdlJeu->pos_choix2));
        SDL_BlitSurface(pSdlJeu->surface_choix3, NULL, pSdlJeu->surface_ecran, &(pSdlJeu->pos_choix3));
        SDL_BlitSurface(pSdlJeu->surface_choix0, NULL, pSdlJeu->surface_ecran, &(pSdlJeu->pos_choix0));
        SDL_BlitSurface( pSdlJeu->surface_m_score, NULL, pSdlJeu->surface_ecran, &(pSdlJeu->pos_m_score));

		/* on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans a boucle) */
		SDL_Flip( pSdlJeu->surface_ecran );
	}

    SDL_CloseAudio();

}

/*Boucle d'événemts pour le jeu, on sort si on quitte ou si on perd*/
void sdljeuBoucle(sdlJeu *pSdlJeu)
{
	SDL_Event event;
	int continue_boucle = 1;
	/*Variables pour l'affichage du score*/
    SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
    int score,vies,niveau;
    char t[60];

	sdljeuAff(pSdlJeu);
	assert( SDL_Flip( pSdlJeu->surface_ecran )!=-1 );

    /*Initialisation du texte*/
    score=snkGetScore(jeuGetConstSnakePtr(&(pSdlJeu->jeu)));
    vies=snkGetVies(jeuGetConstSnakePtr(&(pSdlJeu->jeu)));
    niveau=jeuGetNiveau(&(pSdlJeu->jeu));
    sprintf(t, "score : %u  niveau %u  vies: %u", score,niveau,vies);
    pSdlJeu->surface_texte = TTF_RenderText_Shaded(pSdlJeu->police, t, couleurNoire, couleurBlanche);

	/* tant que ce n'est pas la fin ... */
	while ( continue_boucle == 1 )
	{
	    if (jeuPerdre(&(pSdlJeu->jeu)))
        {
            jeuSetScore("data/max_score.txt",&(pSdlJeu->jeu));
            snkLibere(&(pSdlJeu->jeu.snk));
            terLibere(&(pSdlJeu->jeu.ter));
            continue_boucle = 0;
            jeuInit(&(pSdlJeu->jeu));
            sdlMenu(pSdlJeu);
        }
        /* tant qu'il y a des evenements à traiter : cette boucle n'est pas bloquante */
		while ( SDL_PollEvent( &event ) )
		{
			/* Si l'utilisateur a cliqué sur la croix de fermeture */
			if ( event.type == SDL_QUIT )
				continue_boucle = 0;

			/* Si l'utilisateur a appuyé sur une touche */
			if ( event.type == SDL_KEYDOWN )
			{
				switch ( event.key.keysym.sym )
				{
				case SDLK_UP:
                    jeuActionClavier( &(pSdlJeu->jeu), 'h');
					break;
				case SDLK_DOWN:
					jeuActionClavier( &(pSdlJeu->jeu), 'b');
					break;
				case SDLK_LEFT:
					jeuActionClavier( &(pSdlJeu->jeu), 'g');
					break;
				case SDLK_RIGHT:
					jeuActionClavier( &(pSdlJeu->jeu), 'd');
					break;
				default: break;
				}
			}
		}

        score=snkGetScore(jeuGetConstSnakePtr(&(pSdlJeu->jeu)));
        vies=snkGetVies(jeuGetConstSnakePtr(&(pSdlJeu->jeu)));
        niveau=jeuGetNiveau(&(pSdlJeu->jeu));
        sprintf(t, "score : %u   niveau %u   vies: %u", score,niveau,vies);
        pSdlJeu->surface_texte = TTF_RenderText_Shaded(pSdlJeu->police, t, couleurNoire, couleurBlanche);


        /*Permet de fixer la vitesse du snake, elle augmente au fur et à mesure*/
		SDL_Delay(120-jeuGetNiveau(&(pSdlJeu->jeu))*5);

        /*Fait avancer le snake tant qu'on n'a pas fini*/
		jeuAvance(&(pSdlJeu->jeu));

		/* on affiche le jeu sur le buffer caché */
		sdljeuAff(pSdlJeu);

        /*Positionnement des textes en ttf*/
		pSdlJeu->pos_score.x = 200;
        pSdlJeu->pos_score.y = getDimY( jeuGetConstTerrainPtr(&(pSdlJeu->jeu)) )*TAILLE_SPRITE;
        SDL_BlitSurface(pSdlJeu->surface_texte, NULL, pSdlJeu->surface_ecran, &(pSdlJeu->pos_score)); /* Blit du texte contenant le temps */

		/* on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans a boucle) */
		SDL_Flip( pSdlJeu->surface_ecran);
	}
}

/*Procédure chargée de libérer les surfaces textes et le jeu*/
void sdljeuDetruit( sdlJeu *pSdlJeu)
{
    TTF_CloseFont(pSdlJeu->police);
    TTF_CloseFont(pSdlJeu->police_menu);
    TTF_CloseFont(pSdlJeu->police_titre);

	SDL_FreeSurface( pSdlJeu->surface_titre);
	SDL_FreeSurface( pSdlJeu->surface_choix0);
	SDL_FreeSurface( pSdlJeu->surface_choix1);
	SDL_FreeSurface( pSdlJeu->surface_choix2);
	SDL_FreeSurface( pSdlJeu->surface_choix3);
	SDL_FreeSurface( pSdlJeu->surface_m_score);
	if (pSdlJeu->flag_instruction==1)
	{
        SDL_FreeSurface(pSdlJeu->surface_choix4);
        SDL_FreeSurface(pSdlJeu->surface_instruction);
	}
	if (pSdlJeu->flag_jeu == 1)
	{
        SDL_FreeSurface(pSdlJeu->surface_texte);
        SDL_FreeSurface( pSdlJeu->surface_snake );
        SDL_FreeSurface( pSdlJeu->surface_mur );
        SDL_FreeSurface( pSdlJeu->surface_nourriture );
    }

    jeuLibere(&(pSdlJeu->jeu));


    /* Uninitialization */
    TTF_Quit();
	SDL_Quit();
}


/*Charge la surface pour les éléments du jeu*/
SDL_Surface *SDL_load_image(const char* filename )
{
	/* Temporary storage for the image that's loaded */
	SDL_Surface* loadedImage = NULL;

	/* The optimized image that will be used */
	SDL_Surface* optimizedImage = NULL;

	/* Load the image */
	loadedImage = SDL_LoadBMP( filename );

	/* If nothing went wrong in loading the image */
	if ( loadedImage != NULL )
	{
		/* Create an optimized image */
		optimizedImage = SDL_DisplayFormat( loadedImage );

		/* Free the old image */
		SDL_FreeSurface( loadedImage );
	}

	/* Return the optimized image */
	return optimizedImage;
}


void SDL_apply_surface( SDL_Surface* source, SDL_Surface* destination, int x, int y )
{
	/* Make a temporary rectangle to hold the offsets */
	SDL_Rect offset;

	/* Give the offsets to the rectangle */
	offset.x = x;
	offset.y = y;

	/* Blit the surface */
	SDL_BlitSurface( source, NULL, destination, &offset );
}
