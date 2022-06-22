#include "partita.h"
#include "board.h"
#include "giocatore.h"
#include <stdio.h>

void carica_partita (char mod[], char board[], char *turno) {

    FILE *fp = fopen ("cache", "r");

    char ch = fgetc (fp);

    if (ch == '0') {
        strcpy (mod, "1vs1");
    } else {
        strcpy (mod, "1vsCPU");
    }

    ch = fgetc(fp);

    if (ch == '1') {
        *turno = 1;
    } else {
        *turno = 2;
    }

    int i;
    for (i = 0; i < 9; i++) {
        board[i] = fgetc (fp);
    }

    fclose (fp);
}

void sovrascrivi_partita (char mod[], char board[], char turno) {

    FILE *fp;

    if (strcmp (mod, "1vs1") == 0) {
        fputc ('0', fp);
    } else {
        fputc ('1', fp);
    }

    if (turno == 1) {}

}

void aggiorna_partita(int x, int y, char simbolo) {

}

void gioca(char mod[], char board[], char turno) {

    void (*p1)(int *x, int *y) = scegli_mossa_utente;
    void (*p2)(int *x, int *y);

    if (strcmp (mod, "1vs1") == 0) {
        p2 = scegli_mossa_utente;
    } else {
        p2 = scegli_mossa_computer;
    }

    int mossa_x, mossa_y;

    while (board_vincente(board)==0 && board_riempita(board)==0) {
        if (turno == 1) {
            p1(&mossa_x, &mossa_y);

            while (mossa_ammissibile (board, mossa_x, mossa_y) == 0) {
                p1(&mossa_x, &mossa_y);
            }

            effettua_mossa (board, mossa_x, mossa_y, SIMB_X);
            aggiorna_mossa (mossa_x, mossa_y, SIMB_X);

            turno = 2;
        } else {
            p2(&mossa_x, &mossa_y);

            while (mossa_ammissibile (board, mossa_x, mossa_y) == 0) {
                p2(&mossa_x, &mossa_y);
            }

            effettua_mossa (board, mossa_x, mossa_y, SIMB_O);
            aggiorna_mossa (mossa_x, mossa_y, SIMB_O);

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