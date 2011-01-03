#ifndef __JOUEUR_H__
#define __JOUEUR_H__

#include "paquet.h"

typedef struct {
	char* nom;
	unsigned int credit;
	Paquet main;
} Joueur;


/*!
* @fn void popMain(Joueur* , jeu*);
* @brief Rend une cartes de la main du joueur j
*/
void popMain(Joueur* , unsigned int, Paquet*);

/*!
* @fn void pushMain(Joueur* , jeu*);
* @brief Donner ajoute une cartes dans la main du joueur j
* @param[in] paquet* jeu de carte
* @param[out] Joueur* joueur a qui donner la carte
*/
void pushMain(Joueur* , Paquet*);

/*!
* @fn void initJoueur(Joueur*);
* @param[in] Joueur* joueur a initialiser
*/
void initJoueur(Joueur*);

/*!
* @fn void testamentJoueur(Joueur*);
* @brief termine la session d'un joueur j
* @param[in] Joueur* joueur a qui donner les cartes
*/
void testamentJoueur(Joueur*);

#endif