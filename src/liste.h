/**
@brief liste.h a les entetes des fonctions pour le module liste.
@author Roberto Medina Bonilla & Yoann Jouvent
@file src/liste.h
@version 1.0
@date 2012/06/07
*/
#ifndef _LISTE_H
#define _LISTE_H

#include "cellule.h"

typedef struct sListe
{
    Cellule * adPremiere;
    Cellule * adDerniere;
}
Liste;

/**@brief Initialise la liste avec une cellule dans la position 5,5
@param [in,out] pL est un pointeur sur la structure Liste
@return none\n
Example code block
@code
lisInit(&snkListe);
@endcode
*/
void lisInit(Liste *pL);

/**@brief Libère la liste et toutes ses cellules
@param [in,out] pL est un pointeur sur la structure Liste
@return none\n
Example code block
@code
lisLibere(&snkListe);
@endcode
@warning La liste doit être initialisée
*/
void lisLibere(Liste *pL);

/**@brief Rajoute une tête à gauche position x-1
@param [in,out] pL est un pointeur sur la structure Liste
@return none\n
Example code block
@code
lisAjoutTeteGauche(&snkListe);
@endcode
@warning La liste doit être initialisée
*/
void lisAjoutTeteGauche(Liste *pL);

/**@brief Rajoute une tête à drotie position x+1
@param [in,out] pL est un pointeur sur la structure Liste
@return none\n
Example code block
@code
lisAjoutTeteDroite(&snkListe);
@endcode
@warning La liste doit être initialisée
*/
void lisAjoutTeteDroite(Liste *pL);

/**@brief Rajoute une tête en haut position y+1
@param [in,out] pL est un pointeur sur la structure Liste
@return none\n
Example code block
@code
lisAjoutTeteHaut(&snkListe);
@endcode
@warning La liste doit être initialisée
*/
void lisAjoutTeteHaut(Liste *pL);

/**@brief Rajoute une tête en bas position y-1
@param [in,out] pL est un pointeur sur la structure Liste
@return none\n
Example code block
@code
lisAjoutTeteBas(&snkListe);
@endcode
@warning La liste doit être initialisée
*/
void lisAjoutTeteBas(Liste *pL);

/**@brief Rajoute une queue à gauche de l'ancienne queue
@param [in,out] pL est un pointeur sur la structure Liste
@return none\n
Example code block
@code
lisAjoutQueue(&snkListe);
@endcode
@warning La liste doit être initialisée
*/
void lisAjoutQueue(Liste *pL);

/**@brief Rajoute une queue dans la position spécifiée par i et j
@param [in,out] pL est un pointeur sur la structure Liste
@param [in] i est un entier
@param [in] j est un entier
@return none\n
Example code block
@code
lisAjoutQueuepos(&snkListe,5,3);
@endcode
@warning La liste doit être initialisée
*/
void lisAjoutQueuePos(Liste *pL, const int i, const int j);

/**@brief Supprime la tête de la liste, le suivant va devenir la nouvelle tête
@param [in,out] pL est un pointeur sur la structure Liste
@return none\n
Example code block
@code
lisSuppTete(&snkListe);
@endcode
@warning La liste doit être initialisée
*/
void lisSuppTete(Liste *pL);

/**@brief Supprime la queue de la liste
@param [in,out] pL est un pointeur sur la structure Liste
@return none\n
Example code block
@code
lisSuppQueue(&snkListe);
@endcode
@warning La liste doit être initialisée
*/
void lisSuppQueue(Liste *pL);

/**@brief Renvoie un pointeur sur la tête de la liste
@param [in,out] pL est un pointeur sur la structure Liste
@return Cellule\n
Example code block
@code
Cellule * tete;
tete=lisGetTete(&snkListe);
@endcode
@warning La liste doit être initialisée
*/
Cellule* lisGetTete(Liste *pL);

/**@brief Renvoie un pointeur sur la queue de la liste
@param [in,out] pL est un pointeur sur la structure Liste
@return Cellule\n
Example code block
@code
Cellule * queue;
queue=lisGetQueue(&snkListe);
@endcode
@warning La liste doit être initialisée
*/
Cellule* lisGetQueue(Liste *pL);

/**@brief Renvoie un pointeur sur le suivant de la tête
@param [in,out] pL est un pointeur sur la structure Liste
@return none\n
Example code block
@code
lisSuivant(&snkListe);
@endcode
@warning La liste doit être initialisée
*/
Cellule* lisSuivant(Liste *pL);

#endif
