#ifndef BOARD
#define BOARD

#include "Globals.hpp"

class Board{
private:
    bool spaces[BOARD_SIZE] = {0};
    int result = 0;
    bool playerturn = false;

    int get_move_value(int move_id);

public:
    bool make_move(int move);

    bool operator [](int i) const { return spaces[i]; }
    int get_result() const { return result; }
    bool is_playerturn() const { return playerturn; }
    void set_turn(bool playerturn){ this->playerturn = playerturn; }
};

#endif