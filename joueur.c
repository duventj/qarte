#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "joueur.h"
#include "paquet.h"




void pushMain(Joueur* j, Paquet* jeu )
{
    Cellule* c;
  
  assert( j != NULL && jeu != NULL );
  
  c=enleveCellule ( jeu, 0);
  ajouteCellule( &(j->main), c);
}

void initJoueur(Joueur* j)
{
  char tmp[100];
  printf("entrez votre nom : ");
  scanf("%s", tmp);
  j->nom=(char*)malloc(strlen(tmp)*sizeof(char));
  strcpy(j->nom, tmp);
  j->credit=0;
  initPaquet(&(j->main));
#ifdef DEBUG
printf("votre nom : %s\n", j->nom);
#endif
}
void testamentJoueur(Joueur* j)
{
  assert( j != NULL );
  
  testamentPaquet(&j->main);
  free(j->nom);
 /*!
 * @todo sauvegarder le credit
 */

}