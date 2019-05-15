#include "Draw.hpp"
#include <iostream>
#include <limits>

void Draw::print_help(){
    std::cout << "ABOUT:" << "\n";
    Draw::print_rules();

    std::cout << "OPTIONS:" << "\n";
    std::cout << "-h : Print this dialog" << "\n";
    std::cout << "-f : Sets player to go first, computer goes first by default" << "\n";
}

void Draw::print_rules(){
    std::cout << "Be the first to the end of the board to win the game!"
              << "\n" << "Place 1 or 2 markers per turn" << "\n";
    
    std::cout << "\n";
}

void Draw::print_board(Board board){
    for(int i = 0 ; i < BOARD_SIZE ; i++){
        if(board[i])
            std::cout << "X ";
        else
            std::cout << "_ ";
    }

    std::cout << "\n" << "\n";
}

void Draw::print_turn_start(Global_strings str_glob,bool player_turn){
    if(player_turn) std::cout << "Player's turn!" << "\n";
    else std::cout << str_glob.computer_name << "'s turn!" << "\n";

    std::cout << "\n";
}

int Draw::player_prompt(Global_strings str_glob){
    int input = 0;

    while((input != 1) && (input != 2)){
        std::cout << str_glob.prompt;
        std::cin >> input;

        if((input != 1) && (input != 2)){
            std::cout << str_glob.prompt_error << "\n";

            // Necessary to allow an input re-attempt
            std::cin.clear();
            // Necessary to remove excess input characters from input stream
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::cout << "\n";
    return input;
}

void Draw::print_endgame(Global_strings str_glob,int result){
    if(result == 1){
        std::cout << "Player won!" << "\n";
    }
    else if(result == -1){
        std::cout << str_glob.computer_name << " won!" << "\n";
    }
        
    std::cout << "\n";
}

void Draw::print_error_input(){
    std::cout << "Invalid move, please try again." << "\n";
}