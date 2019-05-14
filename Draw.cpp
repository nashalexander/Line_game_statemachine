#include "Draw.hpp"
#include <iostream>
#include <limits>

void Draw::print_help(){
    std::cout << "ABOUT:" << std::endl;
    Draw::print_rules();

    std::cout << "OPTIONS:" << std::endl;
    std::cout << "-h : Print this dialog" << std::endl;
    std::cout << "-f : Sets player to go first, computer goes first by default" << std::endl;
}

void Draw::print_rules(){
    std::cout << "Be the first to the end of the board to win the game!"
              << std::endl << "Place 1 or 2 markers per turn" << std::endl;
    
    std::cout << std::endl;
}

void Draw::print_board(Board board){
    for(int i = 0 ; i < BOARD_SIZE ; i++){
        if(board[i])
            std::cout << "X ";
        else
            std::cout << "_ ";
    }

    std::cout << std::endl << std::endl;
}

void Draw::print_turn_start(Global_strings str_glob,bool player_turn){
    if(player_turn) std::cout << "Player's turn!" << std::endl;
    else std::cout << str_glob.computer_name << "'s turn!" << std::endl;

    std::cout << std::endl;
}

int Draw::player_prompt(Global_strings str_glob){
    int input = 0;

    while((input != 1) && (input != 2)){
        std::cout << str_glob.prompt;
        std::cin >> input;

        if((input != 1) && (input != 2)){
            std::cout << str_glob.prompt_error << std::endl;

            // Necessary to allow an input re-attempt
            std::cin.clear();
            // Necessary to remove excess input characters from input stream
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::cout << std::endl;
    return input;
}

void Draw::print_endgame(Global_strings str_glob,int result){
    if(result == 1){
        std::cout << "Player won!" << std::endl;
    }
    else if(result == -1){
        std::cout << str_glob.computer_name << " won!" << std::endl;
    }
        
    std::cout << std::endl;
}

void Draw::print_error_input(){
    std::cout << "Invalid move, please try again." << std::endl;
}