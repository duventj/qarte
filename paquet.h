#ifndef __PAQUET_H__
#define __PAQUET_H__

#include "utils.h"

/* macro liees au module liste */
#include "liste.h"

#define deniereCartePaquet(x) x->last->info
#define premiereCartePaquet(x) x->prem->info


typedef Liste Paquet;


/*!
* @fn void echangeElement ( Paquet* paq1, unsigned int pos, Paquet* paq2 );
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