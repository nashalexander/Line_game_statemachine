#include "Game.hpp"
#include "State_tree.hpp"

int Game::player_turn(Board &board, int input){
    //sanitize input to move
}

int Game::computer_turn(Board &board){
    State_tree state_tree(board);
    int result = state_tree.next_move(&board);//TODO:
    return result;
}