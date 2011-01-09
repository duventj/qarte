CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=qarte
SRC= liste.c paquet.c carte.c poker.c joueur.c 
OBJ= $(SRC:.c=.o)


all: $(OBJ)

%.o: %.c utils.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf *.o *~ $(EXEC)

