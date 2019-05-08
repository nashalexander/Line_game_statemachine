#ifndef STATE_TREE
#define STATE_TREE

#include <vector>

#include "Globals.hpp"
#include "State.hpp"

class State_tree{
private:
    std::vector<State> tree;
    void generate_tree(Board current_board);
public:
    State_tree(Board board);
};

#endif