// ============================================================================
// Name: Consensus2 Agents Population                      File: population.cpp
// Author:  Ding Zhou
// Modified Nov 10, 2018
// ============================================================================
#include "agent.hpp"
#include "tools.hpp"

#ifndef POPULATION_HPP
#define POPULATION_HPP

class Population {
private:
    int numOne = 0;
    int numAgents = 0;
    int numFickle = 0;
    int numCrowd = 0;
    Agent** agents = nullptr;
    
    // util functions to initialise population
    static double dRandom();

public:
    Population( int numAgents, double probFickle, double probOne );
    Population( const Population& p )               = delete;
    Population& operator=( const Population& p )    = delete;
    Population( Population&& p )                    = delete;
    Population& operator=( Population&& p )         = delete;
    ~Population();

    int  consensusValue()    const;
    int  size()              const { return numAgents; }
    bool consensusReached()  const { return !numOne || numOne == numAgents; } 
    void sendMessage( int sender, int receiver ) ;
    ostream& print( ostream& out ) const;
};

inline ostream& operator<<( ostream& out, Population& p ) { return p.print( out ); }

#endif
