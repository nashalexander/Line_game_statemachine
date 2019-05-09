#include "Game.hpp"
#include "State_tree.hpp"
#include <iostream>//FIXME: error checking

int Game::get_move_id(int input){
    if(input == 1)return 0;
    else if(input == 2)return 1;
    //TODO: else throw error
}

void Game::player_turn(Board &board, int input){
    int move_id = get_move_id(input);
    bool is_valid = board.make_move(move_id);
    if(!is_valid)std::cout<<"INVALID MOVE"<<std::endl;//FIXME: erro checking
}

void Game::computer_turn(Board &board){
    State_tree state_tree(board);
    //state_tree.next_move(&board);//TODO:
}