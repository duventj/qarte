#ifndef __JEU_H__
#define __JEU_H__

#include "utils.h"
#include "joueur.h"
#include "paquet.h"


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
	} Hand;

typedef struct {
	int rang, rang_b;
	Couleur couleur;
	Hand hand;
} HandDesc;
	
/*
handDesc *descriptionHand(Paquet *);
 */

/*
int *compareHand(Paquet **tabHand, int *nbHand);
 */

/*!
* @fn void melangerJeu(Paquet* jeu);
* @brief Melange jeu de carte
* @param[in-out] paquet* jeu de carte a melanger
*/
void melangerJeu(Paquet* jeu);

/*!
* @fn void creerJeu(Paquet* jeu);
* @brief Cree un jeu de carte
* @param[in-out] paquet* jeu de carte a creer
*/
void creerJeu(Paquet* jeu);


/*!
* @fn void donner(Paquet* jeu, Joueur* joueur, unsigned int n);
* @brief Donner n cartes 
* @param[in] paquet* jeu de carte
* @param[in] Joueur* joueur a qui donner les cartes
* @param[in] uint nombre de cartes a donner
*/
void donner(Paquet* jeu, Joueur* joueur, uint n);


#endif
