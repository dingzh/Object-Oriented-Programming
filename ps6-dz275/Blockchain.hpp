//  ---------------------------------------------------------------------------
//  header file for blockchain class                             Blockchain.hpp
//  Created by Ding Zhou on Dec 1, 2018
// ----------------------------------------------------------------------------


#ifndef BLOCKCHAIN_HPP_
#define BLOCKCHAIN_HPP_

#include "Block.hpp"
#include "tools.hpp"

class Blockchain {
    SPtr sptr;

public:
    Blockchain()                                    = default;
    Blockchain( Block* blk ):sptr(blk)  { }
    Blockchain( const Blockchain& bc )              = default;
    Blockchain( Blockchain&& bc )                   = default;
    Blockchain& operator=( const Blockchain& bc )   = default;
    // for move result of extend
    Blockchain& operator=( Blockchain&& bc )        = default;

    // extend blockchain
    Blockchain extend() { return Blockchain( new Block(sptr) ); }

    ostream& print( ostream& out ) const {
        if (!sptr.empty()) sptr->print(out);
        return out;
    }
};

// export print function
inline ostream& operator<<(ostream& out, Blockchain& bc) {
    bc.print(out);
    return out;
}

#endif
