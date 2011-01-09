

#include "../base/poker.h"


void jouer_cinq_cartes(unsigned int compteur)
{
  
 Joueur joueur;
 Paquet jeu;
 
 
 initJoueur(&joueur);
 initPaquet(&jeu);
 
 creerJeu(&jeu);  /* cree un jeu de 52 carte (complet) */
 melangerPaquet(&jeu);

 donner( &jeu, &joueur, 5);
/* afficher();
 changer();
 */
 calcul_qualite_main(&joueur);

 testamentPaquet(&jeu);
 testamentJoueur(&joueur);

}