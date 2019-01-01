//  ---------------------------------------------------------------------------
//  Main program for blockchain                                       main.cpp
//  Created by Ding Zhou on Dec 1, 2018
// ----------------------------------------------------------------------------
#include "tools.hpp"
#include "Driver.hpp"

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
 * Start driver for blockchain
 */
void run() {
    Driver driver;
    driver.start();
}

