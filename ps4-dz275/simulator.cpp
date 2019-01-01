// ============================================================================
// Name: Consensus Simulation Class Implementation          File: simulator.cpp
// Author:  Ding Zhou
// Modified Oct 26, 2018
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

// class constructor
Simulator::Simulator( int numAgents, int numOne, unsigned int seed ):
        numAgents(numAgents), numOne(numOne) {

    srand( seed );
    
    // allocating raw memory
    void* rawMemory = operator new[]( numAgents * sizeof( Agent ) );
    agents = static_cast<Agent*>( rawMemory );

    //using placement new to construct objects
    for (int i = 0; i < numOne; ++i) {
        new (agents+i) Agent( 1 );
    }
    for (int i = numOne; i < numAgents; ++i) {
        new (agents+i) Agent( 0 );
    }
}

// move constructor
Simulator::Simulator( Simulator&& sm ) {
    numAgents = sm.numAgents;
    numOne = sm.numOne;
    agents = sm.agents;

    sm.numOne = 0;
    sm.numAgents = 0;
    sm.agents = nullptr;
}

// assignment
Simulator& Simulator::operator=( Simulator&& sm ) {
    if (agents != nullptr) {
        operator delete[]( agents );
    }

    numAgents = sm.numAgents;
    sm.numAgents = 0;

    numOne = sm.numOne;
    sm.numOne = 0;

    agents = sm.agents;
    sm.agents = nullptr; 

    return *this;
}

// run simulation return consensus reached and write total rounds
int Simulator::run( int& rounds ) {
    rounds = 0;
    
    while (numOne != 0 && numOne != numAgents) {
        int sender, receiver;
        int s_ch, r_ch;

        ++rounds;
        tie( sender, receiver ) = selectPair( numAgents );
        s_ch = agents[sender].choice();
        r_ch = agents[receiver].choice();
        
        if (s_ch == r_ch) continue;

        agents[receiver].update(s_ch);
        if (s_ch == 1) {
            ++numOne;
        } else {
            --numOne;
        }
    }
    return numOne == 0 ? 0 : 1;
}

