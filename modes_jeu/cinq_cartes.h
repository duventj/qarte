#ifndef __CINQ_CARTES_H__
#define __CINQ_CARTES_H__


#include "poker.h"
#include "joueur.h"


#define MAX_CARDS 5
#define MAX_RUN 2



#ifdef __cplusplus
 extern "C" {
 #endif



void jouer_cinq_cartes(Paquet* , Joueur*);


 #ifdef __cplusplus
 }
 #endif


#endif