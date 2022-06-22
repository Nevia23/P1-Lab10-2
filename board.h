#ifndef BOARD_H
#define BOARD_H

 /*
  * Funzioni di stampa e gestione del board del gioco tris.
  */


// BOARD_SIZE indica il numero totale di caselle del gioco
#define BOARD_SIZE 9
#define BOARD_LATO 3
#define SIMB_X 'X'
#define SIMB_O 'O'
#define CASELLA_VUOTA ' ' 


int board_riempita(char board[]);
    /* 
        POST Restituisce 
                1 se tutte le caselle hanno un simbolo diverso da CASELLA_VUOTA (lo spazio)
                0 altrimenti
    */


int board_vincente(char board[]); 
    /* 
        POST Restituisce 
                1 se uno dei due giocatori ha vinto (si hanno 3 simboli uguali su una riga, una colonna o su una diagonale)
                0 altrimenti
    */


void effettua_mossa(char board[], int x, int y, char simbolo_giocatore);
    /*
        POST board cambiata aggiungendo la mossa (x,y) se ammissibile.  
    */


/*
    L'utente inserisce le coordinate bidimensionali x,y della mossa,
    board[] è un vettore unidimensionale. 
    Una mossa è ammissibile se le coordinate sono all'interno 
    delle dimensioni della board (BOARD_LATO x BOARD_LATO) e 
    la casella non è già stata selezionata da un altro giocatore. 
*/
int mossa_ammissibile(char board[], int x, int y);
    /*
        PRE board è un array di dimensione BOARD_SIZE
        POST restituisce 1 se la mossa è ammissibile, 0 altrimenti
     */


/*  Una partita termina se uno dei due giocatori ha vinto oppure se
    non sono possibili ulteriori mosse */
int partita_terminata(char board[]);
    /*
     * POST restituisce 
                1 se la partita è terminata
                0 altrimenti
     */


void print_board(char board[]);
    /*
     * PRE: board ha dimensione BOARD_SIZE
     * POST Stampata a video la schermata del gioco tris in accordo con i valori specificati in board
     */


void reset_board(char board[]); 
    /*
     * PRE: board ha dimensione BOARD_SIZE
     * POST per ogni i tale che 0<=i<BOARD_SIZE si ha board[i]=CASELLA_VUOTA
     */


int tris_in_colonna(char board[], int num_col);
    /* 
        POST restituisce 
                1 se la colonna num_col è non vuota e con tutti i simboli uguali
                0 altrimenti
    */


int tris_in_diagonali(char board[]);
    /* 
        POST Restituisce 
                1 se una delle due diagonali della board è non vuota e con tutti i simboli uguali
                0 altrimenti
    */


int tris_in_riga(char board[], int num_riga);
    /* 
        POST Restituisce 
                1 se la riga num_riga è non vuota e con tutti i simboli uguali
                0 altrimenti
    */


#endif