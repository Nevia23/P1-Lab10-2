#ifndef GIOCATORE_H
#define GIOCATORE_H

void scegli_mossa_utente(int *x, int *y);
/*
 * POST x,y contengono le coordinate della prossima mossa scelta dall'utente, dove (0,0) indica la casella più in alto a sinistra e 0<=*x<BOARD_LATO, 0<=*y<BOARD_LATO
 */

void scegli_mossa_computer(int *x, int *y);
/*
 * POST x,y contengono le coordinate della prossima mossa scelta casualmente dal computer, dove (0,0) indica la casella più in alto a sinistra e 0<=*x<BOARD_LATO, 0<=*y<BOARD_LATO. 
 */
/* Notate che potete usare la costante BOARD_LATO nel vostro codice. */

#endif