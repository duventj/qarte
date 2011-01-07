/**
 * \file jeu.h
 * \brief module liees aux regles du poker en general
 * \author moimeme
 * \version 0.1
 * \date Janvier 2011
 */
#ifndef __POKER_H__
#define __POKER_H__
#include "utils.h"

/**
 * \struct PMain
 * \brief Qualite de la main par ordre croissant
 */
typedef enum { 
	CARTE_HAUTE,
  	PAIRE, 
  	DEUX_PAIRES, 
  	BRELAN, 
  	QUINTE,
  	COULEUR,
  	FULL,
  	CARRE,
  	QUINTE_FLUSH
	} sQualite ; /* qualite de la main */


#include "paquet.h"
#include "joueur.h"


/*!
* @fn qualiteMain *descriptionHand(Paquet *);
* @brief Donne la description de la mai
* @param[in-out] paquet* jeu de carte a melanger
*/
sQualite qualiteJeu(const Paquet *);


/*!
* @fn void creerJeu(Paquet* jeu);
* @brief Cree un jeu de carte
* @param[in-out] paquet* jeu de carte a creer
*/
void creerJeu(Paquet* jeu);



#endif
