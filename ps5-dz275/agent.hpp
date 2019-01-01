// ============================================================================
// Name: Consensus Agents Simulation                            File: agent.hpp
// Author:  Ding Zhou
// Modified Nov 10, 2018
// ============================================================================
#ifndef AGENT_HPP
#define AGENT_HPP

class Agent {
public:
    virtual ~Agent() = default;
    virtual void update( int m ) = 0;
    virtual int  choice() const = 0;
};

// polymorphic subclass implementing Fickle
class Fickle: public Agent {
private:
    int ch;

public:
    Fickle( int ch ): ch(ch) {}
    Fickle( const Fickle& fickle )            = delete;
    Fickle& operator=( const Fickle& fickle ) = delete;
    Fickle( Fickle&& fickle)                  = delete;
    Fickle& operator=( Fickle&& fickle )      = delete;
    ~Fickle()                                 = default;
    
    // implementing pure virutal func in base
    void update( int m ) { ch = m; }       // update to choice in message
    int choice() const   { return ch; }    // return current choice
};

// polymorphic subclass implementing Crowd
class Crowd: public Agent {
private:
    int ch;
    int prev;

public:
    Crowd( int ch ): ch(ch), prev(ch) {}
    Crowd( const Crowd& crowd )               = delete;
    Crowd& operator=(const Crowd& crowd)      = delete;
    Crowd( Crowd&& crowd )                    = delete;
    Crowd& operator=( Crowd&& crowd )         = delete;
    ~Crowd()                                  = default;

    // implementing pure virutal func in base
    void update( int m );                  // update to choice in message
    int choice() const   { return ch; }    // return current choice
};

#endif

