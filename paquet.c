

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