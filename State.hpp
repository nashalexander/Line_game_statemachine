#ifndef STATE
#define STATE

#include <unordered_map>

class State{
public:
    std::unordered_map<int,State*> vectors;
    State(Board board);

    Board board;
 
    bool add_vector(int value, State* state);
    //bool get_state(int input, State* next_states[]);
};

bool State::add_vector(int value, State* state)
{
    this->vectors.insert(std::make_pair<>(value,state));
    return true;
}



#endif