// ============================================================================
// Name: Consensus2 Simulation Class Implementation          File: simulator.cpp
// Author:  Ding Zhou
// Modified Nov 10, 2018
// ============================================================================
#include "simulator.hpp"

// uniformally sample one int from 0 to n-1, inclusive
int Simulator::uRandom( int n ) {
    long int usefulMax = RAND_MAX - ( (RAND_MAX - n) + 1) % n;
    long int r;
    do { r = random(); }
    while ( r > usefulMax );

    return r % n;
}

// select a pair in agents out of n
pair<int, int> Simulator::selectPair(int n) {
    int first = uRandom( n );
    int second = uRandom( n - 1 );
    if (second >= first) ++second;
    
    return {first, second};
}

// run simulation return consensus reached and write total rounds
void Simulator::run() {
    rounds = 0;

    // keep sending message until consensus
    while (!p.consensusReached()) {
        ++rounds;

        auto [sender, receiver] = selectPair( numAgents );
        p.sendMessage( sender, receiver );
    }
}

