#include "State_tree.hpp"

State_tree::State_tree(Board board){
    this->generate_tree(board);
}

void State_tree::generate_tree(Board current_board){
    // Create root state
    this->tree.push_back(State(current_board));
    
    for(int i; i < this->tree.size() ; i++){//TODO: change to standard loop for vector modification
    //TODO: flip value for player turn
        if(this->tree[i].board.result == 0){
            for(int move=0 ; move<POSSIBLE_MOVES ; move++){
                Board new_board = this->tree[i].board;
                bool move_valid = new_board.make_move(move);
                if(move_valid){
                    State new_state(new_board);
                    new_state.add_vector(move,&this->tree[i]);
                    this->tree.push_back(new_state);
                }
            }
        }
    }


    
}
