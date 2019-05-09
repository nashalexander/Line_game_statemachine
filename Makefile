CC = g++

OBJ_NAME = line_game

OBJS_HEADERS = \
	Globals.hpp \
	Draw.hpp \
	Game.hpp \
	State_tree.hpp \
	State.hpp

OBJS_SOURCE= \
	main.cpp \
	Draw.cpp \
	Game.cpp \
	State_tree.cpp

CFLAGS = --std=c++11

all: $(OBJS_HEADERS) $(OBJS_SOURCE)
	$(CC) $(CFLAGS) $(OBJS_HEADERS) $(OBJS_SOURCE) -o $(OBJ_NAME)  
