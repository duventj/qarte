
#include "../base/poker.h"
#include "../base/joueur.h"


void jouer_cinq_cartes(Paquet* jeu, Joueur* joueur)
{ 
 initJoueur(joueur);
 initPaquet(jeu);
 
 creerJeu(jeu);  /* cree un jeu de 52 carte (complet) */
 melangerPaquet(jeu);

 donner( jeu, joueur, 5);
 calcul_qualite_main(joueur);
/* afficher();
 changer();
 */
}