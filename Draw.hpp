#ifndef DRAW
#define DRAW

#include "Globals.hpp"

class Draw{
public:
    static void print_rules(Global_strings str_glob,bool player_turn);
    static void print_board(Board board);
    static int prompt(Global_strings str_glob,bool player_turn);
};

#endif