#include <stdlib.h> 
#include <stdio.h> 
#include <assert.h>


#include "poker.h"
#include "carte.h"
#include "paquet.h"

#define DEBUG


/*!
* @fn SJeu* descriptionHand(Paquet *);
* @brief Donne la description de la mai
* @param[in-out] paquet* jeu de carte a melanger
*/
sQualite qualiteJeu(const Paquet * main_joueur)
{
  uint i,j,tmp,tmp1;
  uint map[4][14],color_identique[4], valeur_identique[14] ;
  Carte* c;
  Couleur col;
  sQualite qualite; 
  
/* init map et compteurs*/
  for (i=0;i<4;i++)
  {
    color_identique[i]=0;
    for (j=0;j<14;j++)
    {
      valeur_identique[j]=0;
      map[i][j]=0;
    }
  }

/*! \todo � separer pour l'IA (cartographie + trie)
*/
/* cartographie des cartes par rapport au jeu */  
  j = nbElementsPaquet(main_joueur);
  printf("NB elem : %d\n",j);
  for (i=1; i <= j ; i++)
  {
    c=copieCarte(main_joueur, i);
    col=c->couleur;
    tmp=c->valeur;
    map[col][tmp-1] ++;
    printf ("couleur %d  - valeur %d , %d\n",col,tmp,map[col][tmp-1]);  
  }
  
#ifdef DEBUG
/* affiche map */
  for (i=0;i<4;i++)
  {
    printf("%d :",i);
    for (j=0;j<14;j++)
      printf(" %d -",map[i][j]);
    printf("\n");
  }
#endif

/*! \todo on peut surement tout faire en un passage
*/
/*trie des donnees*/
  for (i=0;i<4;i++)
    for (j=0; j<14 ; j++)
    {
      color_identique[i] += map[i][j];
      valeur_identique[j] += map[i][j];
    }
#ifdef DEBUG
 printf("\n");
 for (i=0;i<4;i++) printf("%d\n",color_identique[i]);
 printf("   ");
 for (i=0;i<14;i++) printf(" %d -",valeur_identique[i]);
 printf("\n");
#endif
/* Calcul de la valeur de la main  */
/* Couleur et quinte flush */
  for(i=0;i<4;i++)
  {
    if (color_identique[i] == 5)
    {
      qualite = COULEUR ;
      /* verif quinte flush  */
      tmp=0;
      for(j=0;j<14;j++)
	if(map[i][j] !=0)
	  tmp++;
	else 
	  tmp=0;
      if (tmp>=5)
	qualite = QUINTE_FLUSH;
      return qualite;
    }
  }
/* Full brelan paire double paire  */
  tmp=0;
  for(i=0;i<14;i++)
  {
    if (valeur_identique[i] == 4)
    {
     return qualite=CARRE;
    }
    else if (valeur_identique[i] == 3)
    {
     /* verif full ou brelan  */
     tmp+=3;
    }
    else if (valeur_identique[i] == 2)
    {
     /* verif full ou brelan  */
     tmp+=2;
    }
  }

  switch(tmp) 
  {
    case (6) : 		/* pour le hold'em */
      qualite=FULL;
      return qualite ;
      break;
    case (5) : 
      qualite=FULL;
      return qualite ;
      break;
    case (4) : 
      qualite=DEUX_PAIRES;
      return qualite ;
      break;
    case (3) : 
      qualite=BRELAN;
      return qualite ;
      break;
    case (2) : 
      qualite=PAIRE;
      return qualite ;
      break;
  }
/* quinte (pas de paire -> on recupere l'ago de la quinte flush)*/
/*! \todo � separer pour mettre phus haut (prioritaire par rapport au return des mains plus faibles
*/
  tmp=0;
  for(j=0;j<14;j++)
  {
    tmp1=0;
    for(i=0;i<4;i++)
      tmp1+=map[i][j];
    if(tmp1==0)
      tmp=0;
    else tmp++;
    if(tmp>=5)
      return qualite = QUINTE ;
  }
  
/* Trop tard pour bluffer... */
  return CARTE_HAUTE;
}


void creerJeu(Paquet* jeu)
{
	uint i,j;
	Couleur col;

 assert(jeu != NULL);
 
 if (nbElementsPaquet(jeu) != 0)
	videPaquet(jeu);

 for (j=0;j<4;j++)
	{
	 if (j==0) col = PIQUE;
	 if (j==1) col = TREFFLE;
	 if (j==2) col = CARREAU;
	 if (j==3) col = COEUR;
	 for ( i = 1 ; i < 14; i++)
	   pushPaquet(jeu, creerCarte(col, i));
	 }
#ifdef DEBUG
printf("nb cartes creees : %d \n", nbElementsPaquet(jeu));
#endif
 }


