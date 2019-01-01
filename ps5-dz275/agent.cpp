// ============================================================================
// Name: Consensus Agents Simulation                            File: agent.cpp
// Author:  Ding Zhou
// Modified Nov 10, 2018
// ============================================================================
#include "agent.hpp"

void Crowd::update( int m ) {
    if ( m == prev ) {
        ch = prev;
    } else {
        prev = m;
    }
}
