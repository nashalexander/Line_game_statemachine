#include "State.hpp"

State::State(Board board){
    this->board = board;
};

bool State::add_vector(int value, std::shared_ptr<State> state){
    this->vectors.insert(std::make_pair<>(value,state));
    return true;
};

std::shared_ptr<State> State::get_next_state(int input) const{
    try{
        return vectors.at(input);
    }
    catch (const std::out_of_range& e){
        return NULL;
    }
};