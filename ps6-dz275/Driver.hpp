//  ---------------------------------------------------------------------------
//  Header file for blockchain driver                                Driver.hpp
//  Created by Ding Zhou on Dec 1, 2018
// ----------------------------------------------------------------------------

#ifndef DRIVER_HPP_
#define DRIVER_HPP_

#include "Blockchain.hpp"
#include "tools.hpp"

class Driver {
    Blockchain bc[10];
public:
    Driver();
    Driver( const Driver& dr )              = delete;
    Driver( Driver&& dr )                   = delete;
    Driver& operator=( const Driver& dr)    = delete;
    Driver& operator=( Driver&& dr )        = delete;

    // start driver
    void start(  );
};

#endif
