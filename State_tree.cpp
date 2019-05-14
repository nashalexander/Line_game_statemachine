#include "State_tree.hpp"

#ifdef DEBUG
#include <iostream>
#include "Draw.hpp"

void debug_print_state_tree(std::shared_ptr<State> state, int level=0){
    for(int i=0;i<level;i++)std::cout << " ";
    //std::cout << "-State: " << state << " result: " << state->board.result << " ";
    //for(std::pair<int,std::shared_ptr<State>> vector : state->vectors)
      //  std::cout << vector.second << " ";
    Draw::print_board(state->board);

    level++;
    for(std::pair<int,std::shared_ptr<State>> vector : state->vectors){
        debug_print_state_tree(vector.second,level);
    }
}
#endif

State_tree::State_tree(Board board){
    this->generate_tree(board);
}

void State_tree::generate_tree(Board current_board){
    std::vector<std::shared_ptr<State>> tree;

    this->root_state = std::make_shared<State>(current_board);
    tree.push_back(this->root_state);

    // tree vector expands in size as states are evaluated until all paths lead
    // to a win
    for(int i=0 ; i < tree.size() ; i++){

        // Evaluate state only if no one has won yet
        if(tree[i]->board.get_result() == 0){

            // Generate all possible next states
            for(int move_id=0 ; move_id<POSSIBLE_MOVES ; move_id++){
                Board new_board = tree[i]->board;
                bool move_valid = new_board.make_move(move_id);
                if(move_valid){
                    std::shared_ptr<State> new_state = std::make_shared<State>(new_board);
                    tree[i]->add_vector(move_id,new_state);
                    tree.push_back(new_state);
                }
            }
        }
    }
#ifdef DEBUG
    debug_print_state_tree(root_state);
#endif
}

bool State_tree::make_move(Board &board){
    double win_chance[POSSIBLE_MOVES] = {0};// Percentage
    int chosen_move = 0;

    // Test each possuble next move and decide best action
    for(int move_id=0 ; move_id<POSSIBLE_MOVES ; move_id++){
        int win_total = 0;
        int num_states = 0;
        std::shared_ptr<State> current_state = this->root_state->get_next_state(move_id);
        if(current_state == NULL) continue;// Skip if no next state

        this->eval_branch(*current_state,&win_total,&num_states);

        win_chance[move_id] = (double)win_total / (double)num_states;
#ifdef DEBUG
        std::cout<< win_total << ":" << num_states << ":" << win_chance[move_id] << std::endl;
#endif
        if(win_chance[move_id] > win_chance[chosen_move]) chosen_move = move_id;
    }

    bool is_valid = board.make_move(chosen_move);
    if(is_valid) return true;
    else return false;
}

// Recursive function to evaluate a state tree
void State_tree::eval_branch(State state,int *total_win_value,int *total_outcomes){
    if(state.board.get_result() != 0){
        (*total_outcomes)++;

        // Computer wins
        if(state.board.get_result() == -1) (*total_win_value)++;
    }
    else{
        for(std::pair<int,std::shared_ptr<State>> pair : state.vectors){
            this->eval_branch(*pair.second,total_win_value,total_outcomes);
        }
    }
}
