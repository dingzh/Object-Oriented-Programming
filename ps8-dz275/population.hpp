// ============================================================================
// Name: Blockchain Agents Population                      File: population.cpp
// Author:  Ding Zhou
// Modified Dec 8, 2018
// ============================================================================
#include "agent.hpp"
#include "tools.hpp"
#include "Inventory.hpp"

#ifndef POPULATION_HPP
#define POPULATION_HPP

class Population {
private:
    int numAgents;
    int numFickle   = 0;
    int numCrowd    = 0;
    int numNakamoto = 0;
    Inventory invt;
    Agent** agents = nullptr;

public:
    Population( int numAgents_, double probNak, double probFickle );
    Population( const Population& p )                      = delete;
    Population& operator=( const Population& p )           = delete;
    Population( Population&& p )                           = delete;
    Population& operator=( Population&& p )                = delete;
    ~Population();

    int size()                          const { return numAgents; }
    ostream& print     ( ostream& out ) const;
    ostream& printStats( ostream& out ) const;

    // extend blockchain in selected agent
    void extend     ( int receiver );
    // sending message in give pair
    void sendMessage( int sender, int receiver );
};

// export print
inline ostream& operator<<( ostream& out, const Population& p ) { return p.print( out ); }

#endif
