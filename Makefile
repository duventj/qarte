CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=qarte
SRC= liste.c paquet.c carte.c jeu.c joueur.c main.c
OBJ= $(SRC:.c=.o)

all: $(EXEC)

qarte: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

#main.o: utils.h

%.o: %.c utils.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf *.o *~ $(EXEC)

