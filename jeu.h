#ifndef __JEU_H__
#define __JEU_H__

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
  	QUINTE_FLUSH,
	} Hand;

typedef struct {
	int rang, rang_b;
	Couleur couleur;
	Hand hand;
} HandDesc;
	
/*
 */
handDesc *descriptionHand(Paquet *);

/*
 */
int *compareHand(Paquet **tabHand, int *nbHand);

#endif
