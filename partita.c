#include "partita.h"

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
        *turno = 0;
    } else {
        *turno = 1;
    }

    int i;
    for (i = 0; i < 9; i++) {
        board[i] = fgetc (fp);
    }

    fclose (fp);
}

void sovrascrivi_partita (char mod[], char board[], char turno) {

    FILE *fp = fopen("cache", "w");

    if (strcmp (mod, "1vs1") == 0) {
        fputc ('0', fp);
    } else {
        fputc ('1', fp);
    }

    if (turno == 0) {
        fputc ('0', fp);
    } else {
        fputc ('1', fp);
    }

    int i;

    for (i = 0; i < BOARD_SIZE; i++) {
        fputc (board[i], fp);
    }

    fclose (fp);
}

void aggiorna_partita(int x, int y, char simbolo) {

    FILE *fp = fopen ("cache", "r+");

    int pos = 2 + (x * BOARD_LATO) + y;

    fseek (fp, pos, SEEK_SET);
    fputc (simbolo, fp);

    fclose (fp);
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
        if (turno == 0) {
            p1(&mossa_x, &mossa_y);

            while (mossa_ammissibile (board, mossa_x, mossa_y) == 0) {
                p1(&mossa_x, &mossa_y);
            }

            effettua_mossa (board, mossa_x, mossa_y, SIMB_X);
            aggiorna_partita (mossa_x, mossa_y, SIMB_X);

            turno = 1;
        } else {
            p2(&mossa_x, &mossa_y);

            while (mossa_ammissibile (board, mossa_x, mossa_y) == 0) {
                p2(&mossa_x, &mossa_y);
            }

            effettua_mossa (board, mossa_x, mossa_y, SIMB_O);
            aggiorna_partita (mossa_x, mossa_y, SIMB_O);

            turno = 0;
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