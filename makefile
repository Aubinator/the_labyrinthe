CC = cc
LIB = -lSDL -lSDLmain -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
OUT = Jeu
SRC = *.c
all:
	$(CC) $(SRC) $(LIB) -o $(OUT)

l: all
	./$(OUT)
