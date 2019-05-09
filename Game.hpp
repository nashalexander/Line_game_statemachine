#ifndef GAME
#define GAME

#include "Globals.hpp"

class Game
{
private:
    static int get_move_id(int input);
public:
    static void player_turn(Board& board, int input);
    static void computer_turn(Board& board);
};

#endif