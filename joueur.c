#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "joueur.h"
#include "paquet.h"


/*!
* @fn void calcul_qualite_main(Joueur* );
* @brief Rend une cartes de la main du joueur j
*/
void calcul_qualite_main(Joueur* j)
{
  j->qualite = qualiteJeu(&j->main);
  
}

void popMain( Joueur* j, unsigned int pos, Paquet* paq)
{
  assert(j != NULL && paq !=NULL);
  assert( pos <= nbElementsPaquet(&j->main) );
  
  echangeCellule ( &j->main, pos, paq );

}

void pushMain(Joueur* j, Paquet* jeu )
{
    Cellule* c;
  
  assert( j != NULL && jeu != NULL );
  
  c=enleveCellule ( jeu, 0);
  ajouteCellule( &(j->main), c);
}

void donner(Paquet* jeu, Joueur* joueur, uint n)
{
	uint i;
 for (i=0;i<n;i++)
   {
     pushMain(joueur, jeu);
   }
}

void initJoueur(Joueur* j)
{
  char tmp[100];
  printf("entrez votre nom : ");
  scanf("%s", tmp);
  j->nom=(char*)malloc((strlen(tmp)+1)*sizeof(char));
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
  
 /*!
 * @todo sauvegarder le credit
 */
  testamentPaquet(&j->main);
  free(j->nom);

}