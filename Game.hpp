#ifndef GAME
#define GAME

#include "Globals.hpp"
#include "Board.hpp"

class Game{
private:
    static int get_move_id(int input);
public:
    static bool player_turn(Board& board, int input);
    static bool computer_turn(Board& board);
};

#endif