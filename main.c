#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "paquet.h"
#include "poker.h"
#include "joueur.h"


int main(int argc, char ** argv)
{
  
 Joueur joueur;
 Paquet jeu;
 
 
 initJoueur(&joueur);
 initPaquet(&jeu);
 
 creerJeu(&jeu);
 melangerPaquet(&jeu);
 
 donner( &jeu, &joueur, 5);
#ifdef DEBUG
printf("nb cartes apres donne 5 cartes : %d \n", nbElementsPaquet(&jeu));
affichageListeGaucheDroite( &joueur.main );
/*popMain(&joueur , 1, &jeu);
printf("nb cartes apres popmain : %d \n", nbElementsPaquet(&jeu));
affichageListeGaucheDroite( &joueur.main );*/
#endif


 calcul_qualite_main(&joueur);
 printf("qualite main : %d\n",joueur.qualite);

 testamentPaquet(&jeu);
 testamentJoueur(&joueur);

 return 0;
  
}