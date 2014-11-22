/**
@brief ncursJeu.c fait l'affichage sur ncurses et gère la boucle d'évenements
@author Roberto Medina Bonilla & Yoann Jouvent
@file src/ncursJeu.c
@version 1.0
@date 2012/06/07
*/
#include <stdio.h>
#include <ncurses.h>

#include "jeu.h"

/*Procédure qui affiche les composantes du jeu*/
void ncursAff( WINDOW* win, const Jeu *pJeu)
{
	int x,y,i;

	Cellule *temp;

	const Terrain *pTer = jeuGetConstTerrainPtr(pJeu);
	const Snake *pSnk = jeuGetConstSnakePtr(pJeu);
	const Nourriture *pNour = jeuGetConstNourPtr(pJeu);
    temp=pSnk->snkListe->adPremiere;

	wclear(win);

	for(x=0;x<getDimX(pTer);++x)
		for(y=0;y<getDimY(pTer);++y)
			mvwprintw( win, y, x, "%c", terGetXY(pTer,x,y) );

    for(i=0;i<snkGetTaille(pSnk);i++)
    {
        mvwprintw( win, celGetY(temp), celGetX(temp), "%c", snkGetCharXY(pSnk));
        temp=temp->suivant;
    }
    mvwprintw( win, nourGetY(pNour), nourGetX(pNour), "%c", nourGetChar(pNour));
    static int l=0;
    mvwprintw( win, 13, 1," score : %u",snkGetScore(pSnk));
    l++;
    if (l>13) l=0;

	wmove( win, snkGetY(pSnk), snkGetX(pSnk));
}

/*Boucle dévénements pour le jeu*/
void ncursBoucle(Jeu *pJeu)
{
	WINDOW *win;
	int c;
	int continue_boucle;

	initscr();		/* passe l'écran texte en mode NCurses */
	clear();		/* efface l'écran */
	noecho();  	/* Lorsqu'une touche est préssée au clavier, elle n'apparait pasa à l'écran */
	cbreak();		/* un caractère est directement affiché, il ne passe pas dans un buffer */

	/* Creation d'une nouvelle fenetre en mode texte */
	/* => fenetre de dimension et position ( WIDTH, HEIGHT, STARTX,STARTY) */
	win = newwin( getDimY(jeuGetConstTerrainPtr(pJeu))+2, getDimX(jeuGetConstTerrainPtr(pJeu)), 10, 5 );
	keypad(win, TRUE);		/* pour que les flèches soient traitées (il faut le faire après création de la fenêtre) */

	halfdelay( 1 );
	/* notimeout(win,true); */
	/* wtimeout( win, 500 ); */
	nodelay(win,true);


	continue_boucle = 1;
	do
	{
		ncursAff( win, pJeu);

		c = wgetch(win);
		/* jeuActionClavier( jeu, 'd'); */
		switch(c)
		{
			case KEY_LEFT:
				jeuActionClavier( pJeu, 'g');
				break;
			case KEY_RIGHT:
				jeuActionClavier( pJeu, 'd');
				break;
			case KEY_UP:
				jeuActionClavier( pJeu, 'h');
				break;
			case KEY_DOWN:
				jeuActionClavier( pJeu, 'b');
				break;
			case 27: /* ECHAP */
				continue_boucle = 0;
				snkLibere(&(pJeu->snk));
				terLibere(&(pJeu->ter));
				break;
		}
	} while (continue_boucle==1);

	endwin();
}

