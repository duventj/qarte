#include <stdlib.h> 
#include <stdio.h> 
#include <assert.h>


#include "jeu.h"
#include "joueur.h"




void creerJeu(Paquet* jeu)
{
	uint i,j;
	Couleur col;

 assert(jeu != NULL);
 
 if (nbElementsPaquet(jeu) != 0)
	videPaquet(jeu);

 for (j=0;j<4;j++)
	{
	 if (j==0) col = PIQUE;
	 if (j==1) col = TREFFLE;
	 if (j==2) col = CARREAU;
	 if (j==3) col = COEUR;
	 for ( i = 1 ; i < 14; i++)
	   pushPaquet(jeu, creerCarte(col, i));
	 }
#ifdef DEBUG
printf("nb cartes creees : %d \n", nbElementsPaquet(jeu));
#endif
 }


void donner(Paquet* jeu, Joueur* joueur, uint n)
{
	uint i;
printf("donner");
 for (i=0;i<n;i++)
   {
     pushMain(joueur, jeu);
   }
}