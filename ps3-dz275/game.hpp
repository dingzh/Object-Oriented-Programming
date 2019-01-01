// ============================================================================
// Name: ThinkADot Game Class                               File: thinkadot.hpp
// Author:  Ding Zhou
// Modified Oct 6, 2018
// ============================================================================
#ifndef GAME_HPP
#define GAME_HPP

#include "thinkadot.hpp"
#include <iostream>

class Game {
private:
    static std::string drop;
    static std::string reset;
    static void printHelp() ;
    static void printErr()  ;
public:
    Game() = default;
    static void play() ;
};

#endif // GAME_HPP

