/**
@brief snkreg.c fait les tests de regression pour le snake et le terrain
@author Roberto Medina Bonilla & Yoann Jouvent
@file src/snkreg.c
@version 1.0
@date 2012/06/07
*/
#include "snake.h"
#include <assert.h>
#include <stdio.h>

/*Main qui fait le test de regression pour le snake*/
int main (int argc, char** argv)
{
    Snake snk;
    Terrain ter;
    Nourriture nour;

    /*------------------Tests pour l'initialisation du terrain----------------*/

    printf("********Tests pour le terrain:***********\n\n");
    printf("\tInitialisation:\n\n");
    terAfficheDepuisFichier("data/snkLevel1.txt",&ter);
    assert(ter.dimx==30 && ter.dimy==12);
    printf("Terrain initialisé avec la bonne taille.\n");
    assert(ter.tab[0][0]=='.');
    printf("Le terrain a les bons caractères dans son tableau.\n");

    nourPosition(&ter,&nour);

    /*------------------Tests de l'initialisation du snake----------------*/

    printf("\n\n********Tests pour le snake:***********\n\n");
    printf("\tInitialisation:\n\n");
    snkInit(&snk);
    assert(snk.taille==4);
    printf("Le snake initialisé a la bonne taille.\n");
    assert(snk.germ==0 && snk.posGermX==0 && snk.posGermY==0);
    printf("Germination à 0, le snake ne croit pas.\n");
    assert(snk.score==0);
    printf("Score à 0.\n");
    assert(snk.dir=='n');
    printf("Pas de direction pour le snake.\n");
    assert(snk.vies==5);
    printf("5 vies pour l'initialisation du snake.\n");

    /*Tests d'initialisation de la liste contenue dans le snake*/
    printf("\nPour la liste dans la structure snake:\n");
    assert(snk.snkListe->adPremiere==snk.snkListe->adDerniere);
    printf("La liste pointe sur le premier élément qui est le dernier aussi.\n");
    assert(snk.snkListe->adPremiere->x==5 && snk.snkListe->adPremiere->y == 5);
    printf("La premiere cellule est bien placée.\n");
    assert(snk.snkListe->adPremiere->suivant==NULL);
    printf("La premiere cellule pointe bien sur NULL.\n");

    /*Test pour rajouter une tête à gauche (Pas de test pour les autres direction l'algo est le même)*/
    printf("\n\tAjout d'une tête:\n\n");
    lisAjoutTeteDroite(snk.snkListe);
    assert(snk.snkListe->adPremiere!=snk.snkListe->adDerniere);
    printf("AdPremiere et adDerniere pointent sur deux cellules.\n");
    assert(snk.snkListe->adPremiere->x==6);
    printf("Nouvelle tête mise au bon endroit.\n");
    assert(snk.snkListe->adDerniere->x==5);
    printf("AdDerniere pointe sur la bonne cellule.\n");

    /*Test pour rajouter une queue*/
    printf("\n\tAjout d'une queue:\n\n");
    lisAjoutQueue(snk.snkListe);
    assert(snk.snkListe->adDerniere->x==4);
    printf("La queue a été mise au bon endroit.\n");

    /*Tests de libération*/
    terLibere(&ter);

    snkLibere(&snk);

    printf("\n*********Fin des tests de regression.**********\n");

    return 0;
}
