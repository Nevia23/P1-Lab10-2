#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "board.h"
#include "partita.h"
#include "giocatore.h"

int main() {

    // inizializza il generatore di numeri random
    srand(1);

    char carica = 'n';

    while(1){
    	printf("Vuoi caricare una partita? (s/n) or (e)xit\n");
    	scanf(" %c%*c", &carica);
    	if (carica == 's' || carica == 'n')
    		break;
    	else if (carica == 'e')
    		return 1;
    }

    char modalita[10] = "1vsCPU";
    char board[BOARD_SIZE];
    char turno = 1;

    if (carica == 's') {
        carica_partita (modalita, board, &turno);
    } else {
        while(1) {
            printf("Selezionare una modalità di gioco (1vs1 o 1vsCPU) or (e)xit\n");
    		scanf("%s", &modalita);
            if (strcmp (modalita, "1vs1") == 0 || strcmp (modalita, "1vsCPU") == 0) {
                break;
            } else if (strcmp (modalita, "e") == 0) {
                return 1;
            }
        }
        reset_board (board);
        sovrascrivi_partita (modalita, board, turno);
    }

    char continua = 's'; //indica la volontà del giocatore di continuare a giocare

    while(continua == 's'){
        print_board(board);
        gioca (modalita, board, turno);
        reset_board(board);

        printf("Altra partita? (s/n)\n");
        scanf(" %c%*c", &continua);
    }
}