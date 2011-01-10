/**
 * \file paquet.h
 * \brief module de definitions des paquets de carte, utilise comme un tas
 * \author moimeme
 * \version 0.1
 * \date Janvier 2011
 */
#ifndef __PAQUET_H__
#define __PAQUET_H__

#include "utils.h"
/* macro liees au module liste */
#include "liste.h"
#include "carte.h"




/**
 * \struct Paquet
 * \brief Un paquet est une liste doublement chainnee
 * \brief utilise pour les mains et pour le jeu de cartes
 */
typedef Liste Paquet;

/**
 * \todo Voir si ya encore besoin de ces maro et les enlever
*/
#define deniereCartePaquet(x) x->last->info
#define premiereCartePaquet(x) x->prem->info


/*!
* @fn Carte* copieCarte(const Paquet * paq, unsigned int pos);
* @brief renvoit un pointeur de carte
*/
int conventionCarte(const Paquet * paq, unsigned int pos);

/*!
* @fn Carte* copieCarte(const Paquet * paq, unsigned int pos);
* @brief renvoit un pointeur de carte
*/
Carte* copieCarte(const Paquet * paq, unsigned int pos);

/*!
* @fn void echangeCellule ( Paquet* paq1, unsigned int pos, Paquet* paq2 );
* @brief donne la carte a la position pos de paq1 a la fin de paq2
*/
void echangeCellule ( Paquet* paq1, unsigned int pos, Paquet* paq2 );

/*!
* @fn void melangerPaquet(Paquet *);
* @brief melange un paquet
* @param[in] paquet*
*/
void melangerPaquet(Paquet * paq);

/*!
* @fn void pushPaquet(Paquet *, Carte*);
* @brief Ajoute une carte au dessus du paquet
* @param[in] paquet*
* @param[in] carte*
*/
void pushPaquet(Paquet *, Carte*);


/*!
* @fn Carte* popPaquet(Paquet *, Carte*);
* @brief Enleve la carte du dessus
* @param[in] Paquet*
* @param[out] Carte*
*/
Carte* popPaquet(Paquet *);

/*!
* @fn void initPaquet(Paquet * paq);
* @brief initialise un paquet de carte
* @param[in] Paquet*
*/
void initPaquet(Paquet * paq);


/*!
* @fn unsigned int nbElementsPaquet(const Paquet * paq);
* @brief renvoit le nombre de carte dans le paquet
* @param[in] Paquet*
*/
unsigned int nbElementsPaquet(const Paquet * paq);

/*
 */
void videPaquet(Paquet * paq);

/*
 */
void testamentPaquet(Paquet * paq);


void initPaquet(Paquet * );




#endif