/**
 * \file carte.h
 * \brief module de definitions des cartes
 * \author moimeme
 * \version 0.1
 * \date Janvier 2011
 */
#ifndef __CARTE_H__
#define __CARTE_H__


typedef enum { COEUR, PIQUE, CARREAU, TREFFLE } Couleur;

typedef struct {
	Couleur couleur;
	unsigned int valeur;
} Carte;


typedef Carte Element;

Carte* creerCarte(Couleur, unsigned int);
void supprimerCarte(Carte*);

#endif