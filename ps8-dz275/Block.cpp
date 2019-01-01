//  ---------------------------------------------------------------------------
//  Block implementation for blockchain                               main.cpp
//  Created by Ding Zhou on Dec 1, 2018
// ----------------------------------------------------------------------------

#include "Block.hpp"

// recursively print blockchain
ostream& Block::print( ostream& out ) const {
    if (!sptr.empty()) sptr->print(out);
    out << '[' << level << ',' << serialNo << "] ";
    return out;
}
