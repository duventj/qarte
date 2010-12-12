#ifndef __JOUEUR_H__
#define __JOUEUR_H__

#include "paquet.h"

typedef struct {
	char* nom;
	unsigned int credit;
	Paquet main;
} Joueur;

void pushMain(Joueur* , Carte*);

#endif