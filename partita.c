#include "partita.h"
#include "board.h"
#include "giocatore.h"
#include <stdio.h>

void gioca(char board[], void(*p1)(int *x, int *y), void(*p2)(int *x, int *y)) {

    int turno = 1;
    int mossa_x, mossa_y;

    while (board_vincente(board)==0 && board_riempita(board)==0) {
        if (turno == 1) {
            p1(&mossa_x, &mossa_y);

            while (mossa_ammissibile (board, mossa_x, mossa_y) == 0) {
                p1(&mossa_x, &mossa_y);
            }

            effettua_mossa (board, mossa_x, mossa_y, SIMB_X);
            
            turno = 2;
        } else {
            p2(&mossa_x, &mossa_y);

            while (mossa_ammissibile (board, mossa_x, mossa_y) == 0) {
                p2(&mossa_x, &mossa_y);
            }

            effettua_mossa (board, mossa_x, mossa_y, SIMB_O);

            turno = 1;
        }

        print_board (board);
    }

    if (board_riempita (board) == 1) {
        printf("Parità\n");
        return;
    }

    if (board_vincente (board) == 1) {
        printf("Ha vinto il giocatore %d\n", (turno%2)+1);
        return;
    }
}