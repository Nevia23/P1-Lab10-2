CC = gcc
OBJ = board.o giocatore.o partita.o main.c

%.o: %.c
	${CC} -c $< -o $@

main: ${OBJ}
	${CC} ${OBJ} -o $@

clear:
	rm *.o main