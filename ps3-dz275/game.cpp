// ============================================================================
// Name: ThinkADot Game Class Implementation                File: thinkadot.cpp
// Author:  Ding Zhou
// Modified Oct 6, 2018
// ============================================================================
#include "game.hpp"
#include <cctype>
// classify command type
std::string Game::drop = "ABC";
std::string Game::reset = "LR";

// Play a tad game, play() handles interaction between user,
// and interacts with the think a dot machine object.
void Game::play() {
    char cmd;
    ThinkADot tad;

    std::cout << tad << std::endl;
    for (;;) {
        std::cout << "Enter command: ";
        std::cin >> cmd;
        cmd = toupper( cmd );
        
        size_t pos = drop.find_first_of( cmd );
        if (pos != std::string::npos) {
            char exit = tad.play( cmd );
            std::cout << "exit from hole "<< exit << std::endl;
            continue;
        }
        
        pos = reset.find_first_of( cmd );
        if (pos != std::string::npos) {
            tad.reset( cmd );
            std::cout << "all position rest to " << cmd <<std::endl;
            continue;
        }

        switch ( cmd ) {
            case 'P':
                std::cout << tad << std::endl;
                break;
            case 'H':
                printHelp();
                break;
            case 'Q':
                std::cout << "Goodbye." <<std::endl;
                return ;
            default:
                printErr();
        }
    }
}

// print help message
void Game::printHelp() {
    std::cout << "-------- Help Message --------" << std::endl;
    std::cout << "A,B,C: drop the ball in hole A, B, or C." << std::endl;
    std::cout << "       P,Q as the hole where the ball exits." << std::endl; 
    std::cout << "L,R  : reset all pointes to the left/right." << std::endl;
    std::cout << "P    : print machine state." << std::endl;
    std::cout << "H    : print this help message." << std::endl;
    std::cout << "Q    : exit." << std::endl;
    std::cout << "Commands are case insensitive." << std::endl;
}

// print error message when user input invalid command.
void Game::printErr() {
    std::cout << "Invalid command, enter H for help." << std::endl;
}
