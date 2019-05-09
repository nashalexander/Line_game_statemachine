#ifndef GLOBALS
#define GLOBALS

#include <string>

const int BOARD_SIZE = 5;
const int POSSIBLE_MOVES = 2;


struct Board{//TODO: make class
private:
    int get_move_value(int move_id){
        if(move_id == 0) return 1;
        else if(move_id == 1) return 2;
        //else throw error
    }

public:
    bool spaces[BOARD_SIZE] = {0};//TODO: getter and setter
    int result = 0;//TODO: getter and setter
    bool is_playerturn = false;//TODO: getter and setter

    bool make_move(int move){
        int move_value = get_move_value(move);
        int win_value;
        

        // Find first empty spot on the board
        int end_space=0;
        while(this->spaces[end_space]){
            end_space++;
        }
        // Check if move is invalid
        if(end_space > (BOARD_SIZE - move_value))
            return false;

        // Play move
        for(int curr_space=0 ; curr_space<move_value ; curr_space++){
            this->spaces[end_space+curr_space] = true;
        }

        // Update status
        if(spaces[BOARD_SIZE - 1]){
            if(this->is_playerturn) result = 1;
            else result = -1;
        }
        else{
            is_playerturn = !is_playerturn;
        }
        return true;
    }
};


struct Global_strings{
    std::string computer_name = "Odin";
    std::string prompt = "1 or 2? ";
    std::string prompt_error = "Invalid response";
};

#endif