#include <iostream>
#include <unordered_map>
#include <vector>
#include <string.h>
#include <memory>

#include "Globals.hpp"
#include "Game.hpp"
#include "Draw.hpp"

#if 0
struct Node{
    char id;
    std::unordered_map<int,std::vector<int>> vectors;
};
#endif

int main(int argc, char *argv[]){
    Global_strings str_glob;
    std::shared_ptr<Board> current_board = std::make_shared<Board>();

    int player_input = 0;

    if(strcmp(argv[1],"-f") == 0){
        current_board->is_playerturn = true;
    }

    Draw::print_rules(str_glob,current_board->is_playerturn);
    Draw::print_board(*current_board);

    while(current_board->result == 0){
        player_input = Draw::prompt(str_glob,current_board->is_playerturn);

        if(current_board->is_playerturn){
            Game::player_turn(*current_board,player_input);
        }
        else{
            Game::computer_turn(*current_board);
        }

        Draw::print_board(*current_board);
    }
    
    Draw::print_endgame(str_glob,current_board->result);
    //if (game_result == 1) std::cout << "Player wins!" << std::endl;
    //else if (game_result == -1) std::cout << computer_name << " wins!" << std::endl;

    return current_board->result;
}

#if 0
    int num_states = 3;
    Node states[num_states];
    
    states[0].id = 'a';
    std::vector<int> arr = {2,2};
    states[0].vectors.insert(std::pair<int,std::vector<int>>(2,arr));
 
    states[1].id = 'b';
    states[1].vectors = {{1,NULL,{2,NULL};
    states[2].id = 'c';
    states[2].vectors = {{1,NULL,{2,NULL};

    char test_input[] = {1,2,1};
    int num_tests = sizeof(test_input)/sizeof(test_input[0]);

    int current_state = 0;
    std::cout << states[current_state].id << std::endl;
    for(int i = 0 ; i < num_tests ; i++)
    {
        current_state = states[current_state].vectors.find(test_input[i])->second[0];
        std::cout << states[current_state].id << std::endl;
    }
#endif