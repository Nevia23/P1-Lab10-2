#ifndef PARTITA_H
#define PARTITA_H

#include <stdio.h>
#include <string.h>
#include "board.h"
#include "giocatore.h"

/*
    Gioca una partita di tris. I parametri della funzione sono la board, e  due puntatori a funzioni che indicano il tipo di giocatore,
    se umano o computer. In particolare le funzioni indicano come la prossima mossa debba essere scelta, sono disponibili in giocatore.h.
 */

void carica_partita (char mod[], char board[], char *turno);

void sovrascrivi_partita (char mod[], char board[], char turno);

void aggiorna_partita(int x, int y, char simbolo);

void gioca (char mod[], char board[], char turno);

/*
 * PRE board ha dimensione BOARD_SIZE
 * POST Una partita completa di tris è stata giocata (vedere dettagli sotto)
 */
/*
    Struttura di gioca()
    1) leggetevi le funzioni a disposizione in board.h ed utilizzatele!

    2) La funzione gioca ha la seguente struttura: finché la partita non è finita (ovvero finché uno dei due giocatori ha vinto o non 
    sono possibili ulteriori mosse perché la board è statà riempita) si fa effettuare una mossa ad uno dei due giocatori (bisogna mantenere
    l'informazione su chi debba scegliere la mossa ad ogni turno): 

        2.1) la mossa viene selezionata utilizzando le funzioni indicate dai puntatori p1 e p2; si deve poi controllare che la mossa sia 
        valida (altrimenti ne deve essere richiesta un'altra)

        2.2) si effettua la mossa modificando la board e stampandola

    Una volta usciti dal ciclo sopra, si controlla se è perché uno dei due giocatori ha vinto (si stampa un messaggio di vittoria) o se non
    sono possibili altre mosse (si stampa che la partita è finita in parità).
 */


/* Una volta che avrete visto il comando typedef a lezione, potete provare a rimpiazzare la funzione gioca sopra con le righe sotto (per adesso ignoratele) */
//typedef usato per evitare di scrivere il tipo di un puntatore a void funzione(char [], int*, int*)
//typedef void(*strategy_t)(char [], int*, int*);
//void gioca(char board[], strategy_t p1, strategy_t p2);

#endif