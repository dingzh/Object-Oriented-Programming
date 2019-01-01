// ============================================================================
// Name: Blockchain Simulation Class Implementation         File: simulator.cpp
// Author:  Ding Zhou
// Modified Dec 8, 2018
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

Simulator::Simulator( Population& p, double probExtend ): probExtend(probExtend), p(p) {
    numAgents = p.size();
}

// util fuction to generate rand double in range [0,1)
double Simulator::dRandom() {
    return random()/(RAND_MAX+1.0);
}

// select a pair in agents out of n
pair<int, int> Simulator::selectPair(int n) {
    int first = uRandom( n );
    int second = uRandom( n - 1 );
    if (second >= first) ++second;
    
    return {first, second};
}

// run simulation return consensus reached and write total rounds
void Simulator::run( int maxRounds ) {

    // keep sending message until consensus
    while (maxRounds--) {
        bool extend = dRandom() < probExtend;

        if (extend) {
            int receiver = uRandom(numAgents);
            p.extend( receiver );
        } else {
            auto [sender, receiver] = selectPair( numAgents );
            p.sendMessage( sender, receiver );
        }
    }
}

