#include <time.h>
#include "paquet.h"


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
	uint i,pos;
	Element* e;

/* srand((int)time(0));*/
 for (i=0;i< nbElementsPaquet(paq)/2; i++)
	{
	 e=popPaquet(paq);
	 pos = (uint)rand()%42;
	 insererElement(e, paq, pos);
	 }
 }