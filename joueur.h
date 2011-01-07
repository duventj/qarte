/**
 * \file joueur.h
 * \brief module de definitions des joueurs
 * \author moimeme
 * \version 0.1
 * \date Janvier 2011
 */
#ifndef __JOUEUR_H__
#define __JOUEUR_H__

#include "paquet.h"
#include "poker.h"

typedef struct {
	char* nom;
	unsigned int credit;
	Paquet main;
	sQualite  qualite;
} Joueur;


/*!
* @fn compareJoueurs(Joueur *, Joueur *);
* @brief Retourne 0 si les deux jeux sont egaux -> pot partage
* @brief          >0 si le premier jeu est superieur
* @brief          <0 si le deuxieme jeu est superieur
* @param[in-out] paquet* jeu de carte a melanger
*/
int compareJoueurs(Joueur *, Joueur *);

/*!
* @fn void calcul_qualite_main(Joueur* );
* @brief Rend une cartes de la main du joueur j
*/
void calcul_qualite_main(Joueur* );

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
* @fn void donner(Paquet* jeu, Joueur* joueur, unsigned int n);
* @brief Donner n cartes 
* @param[in] paquet* jeu de carte
* @param[in-out] Joueur* joueur a qui donner les cartes
* @param[in] uint nombre de cartes a donner
*/
void donner(Paquet* , Joueur*, uint );

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