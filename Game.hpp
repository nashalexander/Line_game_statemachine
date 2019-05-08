#ifndef GAME
#define GAME

#include "Globals.hpp"

class Game
{
public:
    static int player_turn(Board& board, int input);
    static int computer_turn(Board& board);
};

#endif