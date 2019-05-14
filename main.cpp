#include <iostream>
#include <unordered_map>
#include <vector>
#include <string.h>
#include <memory>
#include <chrono>
#include <thread>

#include "Globals.hpp"
#include "Board.hpp"
#include "Game.hpp"
#include "Draw.hpp"

int main(int argc, char *argv[]){
    Global_strings str_glob;
    std::shared_ptr<Board> current_board = std::make_shared<Board>();
    
    // Check commmand line options
    if(argc > 1){
        if(strcmp(argv[1],"-f") == 0){
            current_board->set_turn(true);
        }
        else if(strcmp(argv[1],"-h") == 0){
            Draw::print_help();
            return 0;
        }
    }

    Draw::print_rules();
    Draw::print_board(*current_board);

    // Main game loop
    while(current_board->get_result() == 0){
        Draw::print_turn_start(str_glob,current_board->is_playerturn());
        
        if(current_board->is_playerturn()){
            int player_input = Draw::player_prompt(str_glob);
            bool valid_move = Game::player_turn(*current_board,player_input);
            if(!valid_move) Draw::print_error_input();
        }
        else{
            std::this_thread::sleep_for(std::chrono::seconds(COMPUTER_THINK_TIME));
            bool valid_move = Game::computer_turn(*current_board);
            if(!valid_move){
                Draw::print_error_input();
                return -1;
            }
        }

        Draw::print_board(*current_board);
        std::this_thread::sleep_for(std::chrono::seconds(DELAY_TIME));

    }
    
    Draw::print_endgame(str_glob,current_board->get_result());
    
    return 0;
}