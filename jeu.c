#include <stdlib.h> 
#include <assert.h>


#include "jeu.h"




void creerJeu(Paquet* jeu)
{
	uint i,j;
	Couleur col;

 assert(jeu != NULL);
 
 if (nbElementsPaquet(jeu) != 0)
	videPaquet(jeu);

 for (j=0;j<4;i++)
	{
	 if (j==0) col = PIQUE;
	 if (j==1) col = TREFFLE;
	 if (j==2) col = CARREAU;
	 if (j==3) col = COEUR;
	 for ( i = 1 ; i < 14; i++)
		pushPaquet(jeu, creerCarte(col, i));
	 }
 }


void donner(Paquet* jeu, Joueur* joueur, uint n)
{
	uint i;
	Carte* c;

 for (i=0;i<n;i++)
	{
	 c=popPaquet(jeu);
	 pushMain(joueur, c);
	 }
 }