//  ---------------------------------------------------------------------------
//  Main progrom for consensus2 simulation.                            main.cpp
//  Created by Ding Zhou on Dec 8, 2018
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
    int numAgents, maxRounds;
    double probNak, probFickle, probExtend;
    bool flag;
    unsigned int seed;

    if (argc != 6 && argc != 7) {
        printErr(); return ;
    }

    // parse numAgents
    numAgents = safe_atoi( argv[1], flag );
    if (!flag || numAgents <= 0) {
        printErr(); return ;
    }

    maxRounds = safe_atoi( argv[2], flag );
    if (!flag || maxRounds < 0) {
        printErr(); return ;
    }

    probNak = safe_atof( argv[3], flag );
    if (!flag || probNak > 1.0 || probNak < 0.0) {
        printErr(); return ;
    }
    
    probFickle = safe_atof( argv[4], flag );
    if (!flag || probFickle > 1.0 || probFickle < 0.0) {
        printErr(); return ;
    }

    double probCrowd = probNak + probFickle;
    if (probCrowd < 0.0 || probCrowd > 1.0) {
        printErr(); return ;
    }

    probExtend = safe_atof( argv[5], flag );
    if (!flag || probExtend > 1.0 || probExtend < 0.0) {
        printErr(); return ;
    }
    // parse seed
    if (argc == 7) {
        seed = (unsigned int) safe_atoi( argv[6], flag );
        if (!flag) {
            printErr(); return ;
        }
    } else {
        seed = (unsigned int) time(0);
    }

    srand(seed);
    Population pop( numAgents, probNak, probFickle );

    cout << "numAgents: " << numAgents << endl;
    cout << "maxRounds: " << maxRounds << endl;
    cout << "probNak: " << probNak << endl;
    cout << "probExtend: " << probExtend << endl;
    cout << "seed: " << seed << endl;
    pop.printStats( cout );

    // run simulation
    Simulator sm(pop, probExtend);
    sm.run(maxRounds);
    cout << pop << endl;
}

// print error message for invalid parameters
inline void printErr() {
    cout << "usage: > blockchain numAgents maxRounds probNak probFickle probExtend [seed]" << endl;
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
