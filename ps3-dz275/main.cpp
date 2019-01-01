//  ---------------------------------------------------------------------------
//  Main program for tad.                                        main.cpp
//  Created by Ding Zhou on Oct 6, 2018
// ----------------------------------------------------------------------------
#include "tools.hpp"
#include "game.hpp"

void run();

// ----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    banner();
    run();
    bye();
    return 0;
}

/*
 * Start the Think-A-Dot game.
 */
void run() {
    Game::play();
}

