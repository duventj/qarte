#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "paquet.h"
#include "jeu.h"
#include "joueur.h"


int main()
{
  
 Joueur joueur;
 Paquet jeu;
 
 
 initJoueur(&joueur);
 initPaquet(&jeu);
 
 creerJeu(&jeu);
 melangerPaquet(&jeu);
 
 donner( &jeu, &joueur, 5);
#ifdef DEBUG
printf("nb cartes apres melange : %d \n", nbElementsPaquet(&jeu));
affichageListeGaucheDroite( &joueur.main );
popMain(&joueur , 1, &jeu);
printf("nb cartes apres melange : %d \n", nbElementsPaquet(&jeu));
affichageListeGaucheDroite( &joueur.main );
#endif

 testamentPaquet(&jeu);
 testamentJoueur(&joueur);

 return 0;
  
}