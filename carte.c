#include "carte.h"
#include <assert.h>
#include <stdlib.h> 



Carte* creerCarte(Couleur col, unsigned int nb)
{
	Carte* carte;

 assert(nb>0 && nb<14);

 carte=(Carte*)malloc(sizeof(Carte));
 carte->couleur = col;
 carte->valeur = nb;

 return carte;
 }



void supprimerCarte(Carte* carte)
{
 free(carte);
 }
