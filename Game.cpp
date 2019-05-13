#include "Game.hpp"
#include "State_tree.hpp"

int Game::get_move_id(int input){
    if(input == 1)return 0;
    else if(input == 2)return 1;
    //TODO: else throw error
}

bool Game::player_turn(Board &board, int input){
    int move_id = get_move_id(input);
    bool is_valid = board.make_move(move_id);
    return is_valid;
}

bool Game::computer_turn(Board &board){
    State_tree state_tree(board);
    return state_tree.make_move(board);
}