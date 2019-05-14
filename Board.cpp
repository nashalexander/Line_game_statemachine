#include "Board.hpp"

int Board::get_move_value(int move_id){
    if(move_id == 0) return 1;
    else if(move_id == 1) return 2;
    else return -1;
}

bool Board::make_move(int move){
    int win_value;
    int move_value = get_move_value(move);
    if(move_value == -1) return false;

    // Find first empty spot on the board
    int end_space=0;
    while(this->spaces[end_space]){
        end_space++;
    }
    // Check if move is invalid
    if(end_space > (BOARD_SIZE - move_value))
        return false;

    // Play move
    for(int curr_space=0 ; curr_space<move_value ; curr_space++){
        this->spaces[end_space+curr_space] = true;
    }

    // Update status
    if(spaces[BOARD_SIZE - 1]){
        if(this->playerturn) result = 1;
        else result = -1;
    }
    else{
        playerturn = !playerturn;
    }
    return true;
}