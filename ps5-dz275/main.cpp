//  ---------------------------------------------------------------------------
//  Main progrom for consensus2 simulation.                            main.cpp
//  Created by Ding Zhou on Nov 10, 2018
// ----------------------------------------------------------------------------
#include "tools.hpp"
#include "simulator.hpp"

void run( int argc, char* argv[] );
// print error message
void printErr();
// safely convert c-style strings
int safe_atoi( char* str, bool& flag );
double safe_atof( char* str, bool& flag );

// ----------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
    banner();
    run(argc, argv);
    bye();
    return 0;
}

/*
 * Start the consensus simulation
 */
void run( int argc, char* argv[] ) {
    int numAgents;
    double probOne, probFickle;
    bool flag;
    unsigned int seed;

    if (argc != 4 && argc != 5) {
        printErr(); return ;
    }

    // parse numAgents
    numAgents = safe_atoi( argv[1], flag );
    if (!flag || numAgents <= 0) {
        printErr(); return ;
    }

    probFickle = safe_atof( argv[2], flag );
    if (!flag || probFickle > 1.0 || probFickle < 0.0) {
        printErr(); return ;
    } 
    probOne = safe_atof( argv[3], flag );
    if (!flag || probOne > 1.0 || probOne < 0.0) {
        printErr(); return ;
    }

    // parse seed
    if (argc == 5) {
        seed = (unsigned int) safe_atoi( argv[4], flag );
        if (!flag) {
            printErr(); return ;
        }
    } else {
        seed = (unsigned int) time(0);
    }

    cout << "Welcome to Consensus Simulator!" << endl;
    cout << "Using seed: " << seed << endl;
    cout.width(13); cout << right << "numAgents:";
    cout.width(7); cout << numAgents << endl;

    cout.width(13); cout << right << "probFickle:";
    cout.width(7); cout << probFickle << endl;

    cout.width(13); cout << right << "probOne:";
    cout.width(7); cout << probOne << endl;
    
    srand(seed);
    Population pop( numAgents, probFickle, probOne );
    Simulator sm(pop);
    
    cout << "Population statistics:" << endl;
    cout << pop;
    
    // run simulation and print result
    sm.run();
    cout << "Results of simulation:" << endl;
    cout.width(13); cout << right << "Rounds:";
    cout.width(7); cout << sm.numRounds() << endl;

    cout.width(13); cout << right << "Consensus:";
    cout.width(7); cout << sm.consensusValue() << endl;
}

// print error message for invalid parameters
inline void printErr() {
    cout << "usage: > consensus2 numAgents probFickle probOne [seed]" << endl;
}

// safely convert string to double
double safe_atof( char* str, bool& flag ) {
    char* end;
    double ret = strtod( str, &end );
    flag = *end == '\0';
    return ret;
}

// safely convert string to int
int safe_atoi( char* str, bool& flag ) {
    char* end;
    int ret = (int) strtol( str, &end, 10 );
    flag = *end == '\0';
    return ret;
}
