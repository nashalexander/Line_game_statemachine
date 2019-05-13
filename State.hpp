#ifndef STATE
#define STATE

#include <unordered_map>
#include <memory>

#include "Globals.hpp"

class State{
private:

public:
    Board board;//TODO: make getter so this can be private
    std::unordered_map<int,std::shared_ptr<State>> vectors;


    State(Board board);
    bool add_vector(int value, std::shared_ptr<State> state);
    std::shared_ptr<State> get_next_state(int input);
};

#endif