// ============================================================================
// Name: Consensus2 Agents Population                      File: population.cpp
// Author:  Ding Zhou
// Modified Nov 10, 2018
// ============================================================================
#include "population.hpp"
#include "simulator.hpp"

// init population with given probability
Population::Population( int numAgents_, double probNak, double probFickle ) {
    numAgents = numAgents_;
    agents = new Agent*[numAgents];

    Blockchain genesis = Blockchain(new Block);
    for (int i = 0; i < numAgents; ++i) {
        double agentChoice = Simulator::dRandom();

        if (agentChoice < probNak) {
            agents[i] = new Nakamoto(genesis);
            ++numNakamoto;
        } else if (agentChoice < probNak + probFickle) {
            agents[i] = new Fickle(genesis);
            ++numFickle;
        } else {
            agents[i] = new Crowd(genesis);
            ++numCrowd;
        }
    }
}

// release dynamically allocated mem
Population::~Population() {
    for (int i = 0; i < numAgents; ++i) {
        delete agents[i];
    }
    delete [] agents;
}

// extent given receiver, maintain inventory
void Population::extend( int receiver )  { 
    Agent& ag = *agents[receiver];
    Blockchain bc  = ag.choice();
    ag.extend();
    Blockchain nbc = ag.choice();
    if ( !(bc == nbc) ) {
        invt.sub(bc);
        invt.add(nbc);
    }
}

// send message between two agents, maintain inventory
void Population::sendMessage( int sender, int receiver ) {
    Agent& ag = *agents[receiver];
    Blockchain bc  = ag.choice();
    ag.update( agents[sender]->choice() );
    Blockchain nbc = ag.choice();
    if ( !(bc == nbc) ) {
        invt.sub(bc);
        invt.add(nbc);
    }
}

// print population status
ostream& Population::print( ostream& out ) const {
    for (int i = 0; i < numAgents; ++i) {
        out << "Agent " << i << " choice:\t";
        out << agents[i]->choice() << endl;
    }
    invt.print( out );
    return out;
}

// print population stats
ostream& Population::printStats( ostream& out ) const {
    out << "Population statistics:" << endl;
    out << "numNakamoto:\t" << numNakamoto << endl;
    out << "numFickle:\t"   << numFickle   << endl;
    out << "numCrowd:\t"    << numCrowd    << endl;
    return out;
}
