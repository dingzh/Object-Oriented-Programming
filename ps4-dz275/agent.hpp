// ============================================================================
// Name: Consensus Agents Simulation                            File: agent.cpp
// Author:  Ding Zhou
// Modified Oct 26, 2018
// ============================================================================
#ifndef AGENT_HPP
#define AGENT_HPP

class Agent {
private:
    int ch;

public:
    Agent( int ch ): ch(ch) {}
    Agent( const Agent& agent )            = default;
    Agent& operator=( const Agent& agent ) = default;
    Agent( Agent&& agent)                  = default;
    Agent& operator=( Agent&& agent )      = default;
    
    void update( int m ) { ch = m; }       // update to choice in message
    int choice() const   { return ch; }    // return current choice
};

#endif

