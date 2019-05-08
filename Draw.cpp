#include "Draw.hpp"
#include <iostream>

void Draw::print_rules(Global_strings str_glob, bool player_turn){
    std::cout << "Be the first to the end of the board to win the game!"
              << std::endl << "Place 1 or 2 markers per turn" << std::endl;
    
    if(player_turn)
        std::cout << "Player goes first" << std::endl;
    else
        std::cout << str_glob.computer_name << " goes first" << std::endl;
    
    std::cout << std::endl;
}

void Draw::print_board(Board board){
    int board_size = sizeof(board.spaces)/sizeof(board.spaces[0]);

    for(int i = 0 ; i < board_size ; i++){
        if(board.spaces[i])
            std::cout << "_ ";
        else
            std::cout << "X ";
    }

    std::cout << std::endl;
}

int Draw::prompt(Global_strings str_glob,bool player_turn){
    int input = 0;
    if(player_turn){
        while((input != 1) || (input != 2)){
            std::cout << str_glob.prompt;
            std::cin >> input;
            if((input != 1) && (input != 2)){
                std::cout << str_glob.prompt_error << std::endl;
            }
        }
    }
    else{
        std::cout << str_glob.computer_name << str_glob.computer_prompt << std::endl;
    }

    std::cout << std::endl;
    return input;
}