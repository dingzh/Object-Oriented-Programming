// ============================================================================
// Name: Consensus2 Simulator                                File: simulator.cpp
// Author:  Ding Zhou
// Modified Nov 10, 2018
// ============================================================================
#include "agent.hpp"
#include "population.hpp"
#include "tools.hpp"

#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP 

class Simulator {
private:
    int rounds = 0;
    int numAgents;
    Population& p;

    // utility functions to select a sender/receiver pair
    static int uRandom(int n);
    static pair<int, int> selectPair(int n);

public:
    Simulator( Population& p ): numAgents(p.size()), p(p) {}
    Simulator( const Simulator& sm )             = delete;
    Simulator& operator=( const Simulator& sm )  = delete;
    Simulator( Simulator&& sm )                  = delete;
    Simulator& operator=( Simulator&& sm )       = delete;
    ~Simulator()                                 = default;

    // run the simulation to reach consensus
    void run();
    int  numRounds()      { return rounds; }
    int  consensusValue() { return p.consensusValue(); }
};

#endif
