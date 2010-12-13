#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "liste.h"

void afficheinfo(Element* e)
{
  printf("%p\n", (void*)e);
}

Cellule* enleveCellule(Liste * l, unsigned int position)
{
    Cellule* ret;
    unsigned int i=0;


    assert(position < nbElements(l));
    
    if (position == 0) 
    {
      ret = l->prem;
      l->prem = ret->suivant;
      l->prem->precedent = NULL;
      ret->precedent = ret->suivant = NULL;
     }
    else if (position == nbElements(l) - 1) 
    {
      ret = l->last;
      l->last = ret->precedent;
      l->last->suivant = NULL;
      ret->precedent = ret->suivant = NULL;
     }
     else
     {
       ret = l->prem;
       while ( i<position )
	 ret = ret->suivant;
       ret->precedent->suivant = ret->suivant;
       ret->suivant->precedent = ret->precedent;
     }
      
      return ret;
}

void insererElement(Element* e, Liste * l, unsigned int position)
{
	Cellule* c,* tmp;
	unsigned int i=0;

c = l->prem;
 while (i< position ) { c = c->suivant; i++;} ;

tmp = c->suivant;
c->suivant = (Cellule*)malloc(sizeof(Cellule));
c->suivant->suivant = tmp;
tmp-> precedent = c->suivant;
c->suivant->info=e;

 }

int rechercheElement(Element* e, const Liste *l)
{
	Cellule *c;
	unsigned int i=0;

c = l->prem;
 while ( c->info != e ) { i++; c = c->suivant;} ;

if (i > nbElements(l)) i=-1;

return i;
 }



void affectation(Liste * l1, const Liste * l2)
{
	Cellule *c;

c = l2->prem;
 while ( c!=NULL ) { ajoutEnQueue(c->info,l1); c = c->suivant;};

 }


void videListe(Liste * l)
{
 while ( l-> prem !=NULL ) {	suppressionEnTete(l);
				/* affichageListeDroiteGauche(&l);  */
			    } ;

 }

unsigned int nbElements(const Liste * l)
{
	Cellule *c;
	int i=0;

c = l->prem;
 while ( c!=NULL ) { i++; c = c->suivant;} ;

return i;
 }


void affichageListeDroiteGauche(const Liste * l)
{
	Cellule *c;

c = l->last;
 while ( c!=NULL ) { afficheinfo(c->info); c = c->precedent;};

 }


void affichageListeGaucheDroite(const Liste * l)
{
	Cellule *c;

c = l->prem;
 while ( c!=NULL ) { afficheinfo(c->info); c = c->suivant;};

 }

void suppressionEnTete(Liste * l)
{ 
	Cellule* tmp;


tmp = l->prem;
l->prem = tmp->suivant;

if (l->prem != NULL) 
	{ l->prem->precedent = NULL; 
	  }
else l->last = l->prem = NULL ;

free(tmp);

 }
void ajoutEnQueue(Element* e, Liste * l)
{
	Cellule * temp ;

 temp = l->last;
 l->last = (Cellule*)malloc(sizeof(Cellule));
 l->last->info = e;
 l->last->suivant = NULL;

if (temp != NULL) 
	{ l->last->precedent = temp;
	  l->last->precedent->suivant = l->last; }

else {	l->prem = l->last ;
	l->last->suivant=NULL; }
 }

void ajoutEnTete(Element* e,Liste * l)
{
	Cellule * temp ;

 temp = l->prem;
 l->prem = (Cellule*)malloc(sizeof(Cellule));
 l->prem->info = e;
 l->prem->precedent = NULL;

if (temp != NULL) 
	{ l->prem->suivant = temp;
	  l->prem->suivant->precedent = l->prem; }

else {	l->last = l->prem ;
	l->prem->suivant=NULL; }
 }

void initialise(Liste * l)
{ 
l->prem = NULL;
l->last = NULL;
 }

int estVide(const Liste * l)
{ 

if (l->prem != NULL) return 0;
else return 1;

}


void testament(Liste * l)
{ 
videListe(l);

 }
