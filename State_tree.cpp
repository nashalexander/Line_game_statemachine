#include "State_tree.hpp"

State_tree::State_tree(Board board){
    this->generate_tree(board);
}

void State_tree::generate_tree(Board current_board){

    std::vector<std::shared_ptr<State>> tree;

    this->root_state = std::make_shared<State>(current_board);
    tree.push_back(this->root_state);

    for(int i=0 ; i < tree.size() ; i++){
        if(tree[i]->board.result == 0){
            for(int move=0 ; move<POSSIBLE_MOVES ; move++){
                Board new_board = tree[i]->board;
                bool move_valid = new_board.make_move(move);
                if(move_valid){
                    std::shared_ptr<State> new_state = std::make_shared<State>(new_board);
                }
            }
        }
    }




// **********************************************************************************
#if 0
    // Create root state
    this->tree.push_back(State(current_board));
    
    for(int i=0; i < this->tree.size() ; i++){//TODO: change to standard loop for vector modification
    //TODO: flip value for player turn
        if(this->tree[i].board.result == 0){
            for(int move=0 ; move<POSSIBLE_MOVES ; move++){
                Board new_board = this->tree[i].board;
                bool move_valid = new_board.make_move(move);
                if(move_valid){
                    State new_state(new_board);
                    this->tree.push_back(new_state);
                    this->tree[i].add_vector(move,&this->tree.back());
                }
            }
        }
    }

#endif
    
}
