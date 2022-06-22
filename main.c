#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "board.h"
#include "partita.h"
#include "giocatore.h"

int main(int argc, char *argv[]) {

    srand(1);

    if(argc!=2){
        printf("Selezionare una modalità di gioco (1vs1 o 1vscpu)\n");
        return -1;
    }
    //strcmp è definita in string.h e confronta due stringhe, restituisce 0 se sono uguali. L'abbiamo implementata come funzione ricorsiva in un laboratorio passato
    if(strcmp(argv[1], "1vs1")!=0 && strcmp(argv[1],"1vscpu")!=0){
        printf("Errore, modalità di gioco non esiste (1vs1 o 1vscpu)\n");
        return -1;
    }
    char continua = 's'; //indica la volontà del giocatore di continuare a giocare

    char board[9];
    reset_board(board);

    while(continua == 's'){
        print_board(board);

        if(strcmp(argv[1], "1vs1")==0) {
            gioca(board, scegli_mossa_utente, scegli_mossa_utente);
        } else {
            gioca(board, scegli_mossa_utente, scegli_mossa_computer);
        }
        reset_board(board);

        printf("Altra partita? (s/n)\n");
        scanf(" %c%*c", &continua);
    }
}