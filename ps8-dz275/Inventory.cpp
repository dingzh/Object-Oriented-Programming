//  ---------------------------------------------------------------------------
//  Implementation for Inventory in blockchain                    Inventory.cpp
//  Created by Ding Zhou on Dec 8, 2018
// ----------------------------------------------------------------------------

#include "Inventory.hpp"

void Inventory::sub( const Blockchain& bc ) {
    auto it = chainCount.find( bc );
    if ( it == chainCount.end() ) return;
    if ( --it->second == 0 ) {
        chainCount.erase( it );
    }
}

ostream& Inventory::print( ostream& out ) const {
    out <<"Inventory: "<< chainCount.size() <<" active blockchain(s):"<< endl;
    for (auto& kv : chainCount) {
        out << kv.second << " copies of\t" << kv.first << endl;
    }
    return out;
}
