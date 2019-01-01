// ============================================================================
// Name: Consensus Simulator                                File: simulator.cpp
// Author:  Ding Zhou
// Modified Dec 8, 2018
// ============================================================================
#include "agent.hpp"
#include "population.hpp"
#include "tools.hpp"

#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

class Simulator {
private:
    int numAgents;
    double probExtend;
    Population& p;

    // utility functions to select a sender/receiver pair
    static int uRandom(int n);
    static pair<int, int> selectPair(int n);

public:
    // util function to generate rand double in range [0,1)
    // made public for use in Population class
    static double dRandom();

    Simulator( Population& p, double probExtend );
    Simulator( Simulator&& sm )                     = delete;
    Simulator( const Simulator& sm )                = delete;
    Simulator& operator=( Simulator&& sm )          = delete;
    Simulator& operator=( const Simulator& sm )     = delete;
    ~Simulator()                                    = default;

    // run the simulation to reach consensus
    void run( int maxRounds );
};

#endif
