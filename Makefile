CC 			= gcc
LD 			= gcc

#JEU	= regression
JEU	= graphique
#OS	= WIN32
OS	= LINUX

ifeq ($(JEU),regression)
	SRCS = snake.c terrain.c snkreg.c nourriture.c liste.c cellule.c
	FINAL_TARGET = regression
	DEFINE = -D$(OS)
else
	SRCS = snake.c terrain.c jeu.c sdlJeu.c main.c nourriture.c liste.c cellule.c
	FINAL_TARGET = snake_gfx
	DEFINE = -D$(OS) -DJEU_SDL
endif

ifeq ($(JEU)$(OS),texteLINUX)
	LIBS = -lncurses
endif

ifeq ($(JEU)$(OS),graphiqueLINUX)
	LIBS = -lSDL -lSDL_ttf
endif


LDFLAGS  			=
CFLAGS 			= $(DEFINE)  -Wall -pedantic -ansi -ggdb   #-O2   # pour optimiser
INCLUDE_DIR 		= -I/usr/include -Isrc  -I/usr/include/SDL

OBJ_DIR 		= bin
SRC_DIR 		= src
BIN_DIR 		= bin



default: $(BIN_DIR)/$(FINAL_TARGET)


$(BIN_DIR)/$(FINAL_TARGET): $(SRCS:%.c=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS) $(LIB_DIR) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $(INCLUDE_DIR) $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/$(FINAL_TARGET)
