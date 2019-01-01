//  ---------------------------------------------------------------------------
//  Header file for Inventory in blockchain                       Inventory.cpp
//  Created by Ding Zhou on Dec 8, 2018
// ----------------------------------------------------------------------------

#include "Blockchain.hpp"
#include <map>
using namespace std;

#ifndef Inventory_HPP_
#define Inventory_HPP_

class Inventory {
    map<Blockchain, int> chainCount;
public:
    Inventory()                                   = default;
    Inventory( const Inventory& invt )            = default;
    Inventory( Inventory&& invt )                 = default;
    Inventory& operator=( const Inventory& invt ) = default;
    Inventory& operator=( Inventory&& invt )      = default;

    void add( const Blockchain& bc ) { chainCount[bc]++; }
    void sub( const Blockchain& bc );

    ostream& print( ostream& out ) const ;
};


#endif
