#ifndef __CARTE_H__
#define __CARTE_H__


typedef enum { COEUR, PIQUE, CARREAU, TREFFLE } Couleur;

typedef struct {
	Couleur couleur;
	int valeur;
} Carte;


typedef Carte Element;


#endif