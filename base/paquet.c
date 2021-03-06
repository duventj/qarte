#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "utils.h"
#include "paquet.h"
#include "carte.h"

int conventionCarte(const Paquet * paq, unsigned int pos)
{  
  Carte* c;
  Couleur col;
  unsigned int val;
  int tmp;
  
  c=copieCarte(paq, pos);
  col=c->couleur;
  val=c->valeur;
  tmp=(int)col*100+(int)val;
  
  return tmp;
}

Carte* copieCarte(const Paquet * paq, unsigned int pos)
{  
  return (Carte*)copieElement(paq, pos);
}

void initPaquet(Paquet * paq)
{
  initialise(paq);
 
 }

void pushPaquet(Paquet * paq, Carte* c)
{
  ajoutEnTete(c,paq);
   
}

Carte* popPaquet(Paquet * paq)
{
  Carte* c;
  
 c = deniereCartePaquet(paq);/* paq->last->info;*/
 suppressionEnTete((Liste*) paq); 
 
 return c;
}


unsigned int nbElementsPaquet(const Paquet * paq)
{
  return nbElements(paq);
}



void videPaquet(Paquet * paq)
{
  videListe(paq);
}


void testamentPaquet(Paquet * paq)
{
  testament(paq);
}


void melangerPaquet(Paquet * paq)
{
	unsigned int i, pos, temp;
/*	Element* e; */
	Cellule* c;

 srand((uint)time(0));
 temp=(uint)(nbElementsPaquet(paq)/2);
 for (i=0;i< 3*temp; i++)
	{
	 pos = (uint)rand()%temp; 
	 c=enleveCellule ( paq, pos);
	 ajouteCellule( paq, c);
	}
#ifdef DEBUG
printf("nb cartes apres melange : %d \n", nbElementsPaquet(paq));
affichageListeGaucheDroite(paq);
printf("1ere carte : %d %d\n", paq->prem->info->couleur, paq->prem->info->valeur);
#endif
 }
 
 void echangeCellule ( Paquet* paq1, unsigned int pos, Paquet* paq2 )
 {
   assert( paq1 != NULL && paq2 != NULL);
   assert( pos <= nbElementsPaquet(paq1) );

   ajouteCellule ( paq2, enleveCellule ( paq1, pos) );
 
 }
 
