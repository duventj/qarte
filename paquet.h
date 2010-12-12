#ifndef __PAQUET_H__
#define __PAQUET_H__

/* macro liees au module liste */
#include "liste.h"

#define deniereCartePaquet(x) x->last->info
#define premiereCartePaquet(x) x->prem->info


typedef Liste Paquet;


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
* @param[out] uint nombre de cartes
*/
unsigned int nbElementsPaquet(const Paquet * paq);

/*
 */
void videPaquet(Paquet * paq);

/*
 */
void testamentPaquet(Paquet * paq);


#endif