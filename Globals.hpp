#ifndef GLOBALS
#define GLOBALS

#include <string>

const int BOARD_SIZE = 5;
const int POSSIBLE_MOVES = 2;
const int COMPUTER_THINK_TIME = 2;
const int DELAY_TIME = 1;

struct Global_strings{
    const std::string computer_name = "Odin";
    const std::string prompt = "1 or 2? ";
    const std::string prompt_error = "Invalid response";
};

#endif