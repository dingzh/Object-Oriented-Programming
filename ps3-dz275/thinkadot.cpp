// ============================================================================
// Name: ThinkADot Class Implementation                     File: thinkadot.cpp
// Author:  Ding Zhou
// Modified Oct 6, 2018
// ============================================================================
#include "thinkadot.hpp"

// position transition table to simulate ball movement
const int ThinkADot::trans_table[2][8] = {
   {5, 3, 4, 5, 6, 'P', 'P', 'Q'},
   {3, 4, 7, 6, 7, 'P', 'Q', 'Q'}
};

// simulate movement when ball is dropped in `hole`
char ThinkADot::play (char hole)  { 
    int ffstate;
    int  ffpos = hole - 'A'; // hole "ABC" corresponds to 012
    while (ffpos < 8) {
        ffstate = ffs[ffpos].getState();
        ffs[ffpos].flip();
        ffpos = trans_table[ffstate][ffpos];
    }
    return static_cast<char>( ffpos );
};

// reset tad machine state
void ThinkADot::reset(char state) {
    for (auto& ff : ffs) {
        ff.setState( state );
    }
}

// print machine state
std::ostream& ThinkADot::print( std::ostream& out ) const {
    out << ffs[0] << " " << ffs[1] << " " << ffs[2] << std::endl;
    out << " " << ffs[3] << " " << ffs[4] << std::endl;
    out << ffs[5] << " " << ffs[6] << " " << ffs[7] ;
    return out;
}

