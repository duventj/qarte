CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=qarte
SRC= liste.c paquet.c carte.c jeu.c joueur.c
OBJ= $(SRC:.c=.o)

all: $(EXEC)

qarte: $(OBJ)
#	$(CC) -o $@ $^ $(LDFLAGS)

#main.o: hello.h

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm *.o

