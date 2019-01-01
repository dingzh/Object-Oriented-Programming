// ============================================================================
// Name: Consensus Simulator                                File: simulator.cpp
// Author:  Ding Zhou
// Modified Oct 26, 2018
// ============================================================================
#include "agent.hpp"
#include "tools.hpp"
//#include <utility>
//#include <tuple>

#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP 

class Simulator {
private:
    int numAgents;
    int numOne;
    Agent* agents;
    // utility functions to select a sender/receiver pair
    static int uRandom(int n);
    static pair<int, int> selectPair(int n);

public:
    Simulator( int numAgents, int numOne, unsigned int seed );
    Simulator( const Simulator& sm )             = delete;
    Simulator& operator=( const Simulator& sm )  = delete;
    Simulator( Simulator&& sm );            
    Simulator& operator=( Simulator&& sm );
    
    // no need to destruct each object cause agent has only primitive members
    ~Simulator() { if (agents) operator delete[]( agents ); }

    // run the simulation to reach consensus
    int run( int& rounds );
};

#endif
