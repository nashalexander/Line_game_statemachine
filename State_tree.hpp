#ifndef STATE_TREE
#define STATE_TREE

#include <vector>
#include <memory>

#include "Globals.hpp"
#include "State.hpp"

class State_tree{
private:
    //std::vector<State> tree;
    std::shared_ptr<State> root_state;
    void generate_tree(Board current_board);
public:
    State_tree(Board board);
};

#endif