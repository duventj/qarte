CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
SRC= cinq_cartes.c
OBJ= $(SRC:.c=.o)

all: $(OBJ)

%.o: %.c utils.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf *.o *~ 

