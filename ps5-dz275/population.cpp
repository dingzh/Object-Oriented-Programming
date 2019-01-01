// ============================================================================
// Name: Consensus2 Agents Population                      File: population.cpp
// Author:  Ding Zhou
// Modified Nov 10, 2018
// ============================================================================
#include "population.hpp"

// util fuction to generate rand double in range [0,1)
double Population::dRandom() { 
    return random()/(RAND_MAX+1.0); 
}

Population::Population( int numAgents_, double probFickle, double probOne ) {
    numOne = 0;
    numAgents = numAgents_;
    agents = new Agent*[numAgents];
    
    for (int i = 0; i < numAgents; ++i) {
        bool isOne = dRandom() < probOne;
        bool isFickle = dRandom() < probFickle;
        int val = 0;
        if (isOne) {
            ++numOne;
            val = 1;
        }
        
        if (isFickle) {
            ++numFickle;
            agents[i] = new Fickle(val);
        } else {
            ++numCrowd;
            agents[i] = new Crowd(val);
        }
    }
}

// sending message in give pair
void Population::sendMessage( int sender, int receiver ) {
    int senderVal = agents[sender]->choice();
    int prevVal = agents[receiver]->choice();

    agents[receiver]->update( senderVal );
    int postVal = agents[receiver]->choice();
    if (prevVal == 0 && postVal == 1) {
        ++numOne;
    } else if (prevVal == 1 && postVal == 0) {
        --numOne;
    }
}

// return consensus
int Population::consensusValue() const {
    int ret = - 1;
    if (numOne == 0) {
        ret = 0;
    } else if (numOne == numAgents) {
        ret = 1;
    }
    return ret;
}

// release dynamically allocated mem
Population::~Population() {
    for (int i = 0; i < numAgents; ++i) {
        delete agents[i];
    }
    delete [] agents;
}

// print population status
ostream& Population::print( ostream& out ) const {
    out.width(13); out << right << "numFickle:";
    out.width(7); out << numFickle << endl;

    out.width(13); out << right << "numCrowd:";
    out.width(7); out << numCrowd << endl;

    out.width(13); out << right << "numOnes:";
    out.width(7); out << numOne << endl;
    return out;
}
