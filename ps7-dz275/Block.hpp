//  ---------------------------------------------------------------------------
//  Header file for Block in blockchain                               Block.cpp
//  Created by Ding Zhou on Dec 1, 2018
// ----------------------------------------------------------------------------


#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include "SPtr.hpp"
#include "Serial.hpp"
#include "tools.hpp"

class Block {
    const SPtr sptr;
    const int level = 0;
    const int serialNo = Serial::newID();

public:
    Block()                                     = default;
    Block( SPtr &sptr ): sptr(sptr), level(sptr->blkLevel() + 1) { }

    Block( const Block& blk )                   = delete;
    Block& operator=( const Block& blk )        = delete;
    Block( Block&& blk )                        = delete;
    Block& operator=( Block&& blk )             = delete;

    // return block level
    int blkLevel() const { return level; }
    // return block serial number
    int serialNum() const { return serialNo; }
    // recursively print block in the same blockchain
    ostream& print( ostream& out ) const;
};

#endif

