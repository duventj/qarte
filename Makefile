CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
SRC= base/liste.c base/paquet.c base/carte.c base/poker.c base/joueur.c \
     modes_jeu/cinq_cartes.c \
     main.c
EXEC=qarte
OBJ= $(SRC:.c=.o)

all: $(EXEC)
	$(CC) -o $^ $(LDFLAGS) $(OBJ)

$(EXEC): $(OBJ)
# 	$(CC) -o $@ $^ $(LDFLAGS)
	make -C base
	make -C modes_jeu
	make -C qt_gui


# all: $(EXEC)
# 
# qarte: $(OBJ)
# 	$(CC) -o $@ $^ $(LDFLAGS)
# 
# #main.o: utils.h
# 
# %.o: %.c utils.h
# 	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	make -C base clean
	make -C modes_jeu clean
	make -C qt_gui clean
	rm -rf *.o *~ $(EXEC)
