// ============================================================================
// Name: Consensus Agents Simulation                            File: agent.cpp
// Author:  Ding Zhou
// Modified Dec 8, 2018
// ============================================================================
#include "agent.hpp"

void Crowd::update( const Blockchain& nbc ) {
    if (prev == nbc) {
        bc = nbc;
    } else {
        prev = nbc;
    }
}

void Nakamoto::update(const Blockchain &nbc) {
    if (nbc.blkLength() > bc.blkLength()) {
        bc = nbc;
    }
}
