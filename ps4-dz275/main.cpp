//  ---------------------------------------------------------------------------
//  Main progrom for consensus simulation.                             main.cpp
//  Created by Ding Zhou on Oct 26, 2018
// ----------------------------------------------------------------------------
#include "tools.hpp"
#include "simulator.hpp"

void run( int argc, char* argv[] );
// print error message
void printErr();
// safely convert c-style string to int
int safe_atoi( char* str, bool& flag );

// ----------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
    //banner();
    run(argc, argv);
    //bye();
    return 0;
}

/*
 * Start the consensus simulation
 */
void run( int argc, char* argv[] ) {
    int numOne, numAgents, rounds, result;
    unsigned int seed;
    bool flag;

    if (argc != 4 && argc != 3) {
        printErr(); return ;
    }

    numAgents = safe_atoi( argv[1], flag );
    if (!flag) {
        printErr(); return ;
    }

    numOne = safe_atoi( argv[2], flag );
    if (!flag) {
        printErr(); return ;
    }

    if (numAgents < numOne) {
        printErr(); return ;
    }

    if (argc == 4) {
        seed = (unsigned int) safe_atoi( argv[3], flag );
        if (!flag) {
            printErr(); return ;
        }
    } else {
        seed = (unsigned int) time(0);
    }
    
    Simulator sm(numAgents, numOne, seed);
    
    result = sm.run( rounds );
    cout << numAgents << " " << numOne << " " << seed << " "
        << rounds << " " << result << endl;
}

// print error message for invalid parameters
inline void printErr() {
    cout << "usage: > consensus numAgents numOne [seed]" << endl
         << "       all parameters should all be integers." << endl
         << "       numOne should not be greater than numAgents." << endl;
}

// safetly convert string to int
int safe_atoi( char* str, bool& flag ) {
    char* end;
    int ret = (int) strtol( str, &end, 10 );
    flag = *end == '\0';
    return ret;
}
