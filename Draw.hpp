#ifndef DRAW
#define DRAW

#include "Globals.hpp"

class Draw{
public:
    static void print_rules(Global_strings str_glob,bool player_turn);
    static void print_board(Board board);
    static void print_turn_start(Global_strings str_glob,bool player_turn);
    static int  player_prompt(Global_strings str_glob);
    static void print_endgame(Global_strings str_glob,int result);
    static void print_error_input();
};

#endif