// ============================================================================
// Name: Header file for Agents Simulation                            File: agent.hpp
// Author:  Ding Zhou
// Modified Dec 8, 2018
// ============================================================================
#include "Blockchain.hpp"

#ifndef AGENT_HPP
#define AGENT_HPP

class Agent {
public:
    virtual ~Agent() = default;

    virtual void extend()                     = 0;
    virtual void update(const Blockchain &bc) = 0;
    virtual Blockchain  choice() const        = 0;
};

class AgentBase: public Agent {
protected:
    Blockchain bc;
public:
    explicit AgentBase( const Blockchain& bc ): bc(bc) {};

    void extend() { bc = bc.extend(); }
    Blockchain choice() const { return bc; }
};

// polymorphic subclass implementing Fickle
class Fickle: public AgentBase {
public:
    explicit Fickle(const Blockchain &bc) : AgentBase(bc){};
    Fickle( const Fickle& fickle )                = delete;
    Fickle& operator=( const Fickle& fickle )     = delete;
    Fickle( Fickle&& fickle)                      = delete;
    Fickle& operator=( Fickle&& fickle )          = delete;
    ~Fickle()                                     = default;

    // update to choice in message
    void update( const Blockchain& nbc ) { bc = nbc; }
};

// polymorphic subclass implementing Crowd
class Crowd: public AgentBase {
    Blockchain prev;
public:
    explicit Crowd( const Blockchain& bc): AgentBase(bc), prev(bc) {};
    Crowd( const Crowd& crowd )                   = delete;
    Crowd& operator=(const Crowd& crowd)          = delete;
    Crowd( Crowd&& crowd )                        = delete;
    Crowd& operator=( Crowd&& crowd )             = delete;
    ~Crowd()                                      = default;

    // implementing pure virutal func in base
    // update to choice in message
    void update( const Blockchain& nbc );
};

// polymorphic subclass implementing Nakamoto
class Nakamoto: public AgentBase {
public:
    explicit Nakamoto(const Blockchain &bc) : AgentBase(bc){};
    Nakamoto(const Nakamoto &nakamoto)            = delete;
    Nakamoto &operator=(const Nakamoto &nakamoto) = delete;
    Nakamoto(Nakamoto &&nakamoto)                 = delete;
    Nakamoto &operator=(Nakamoto &&nakamoto)      = delete;
    ~Nakamoto()                                   = default;

    void update( const Blockchain& nbc);
};

#endif

