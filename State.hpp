#ifndef STATE
#define STATE

#include <unordered_map>
#include <memory>

#include "Board.hpp"
#include "State.hpp"

class State{
public:
    Board board;
    //TODO: make for : each work while being private
    std::unordered_map<int,std::shared_ptr<State>> vectors;

    State(Board board);
    bool add_vector(int value, std::shared_ptr<State> state);
    std::shared_ptr<State> get_next_state(int input) const;
};

#endif