#ifndef STATE
#define STATE

#include <unordered_map>

#include "Globals.hpp"

class State{
public:
    std::unordered_map<int,State*> vectors;
    State(Board board){};

    Board board;
 
    bool add_vector(int value, State* state){
        this->vectors.insert(std::make_pair<>(value,state));
        return true;
    };
    //bool get_state(int input, State* next_states[]);
};

#endif