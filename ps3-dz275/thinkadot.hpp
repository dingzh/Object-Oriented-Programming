// ============================================================================
// Project: Think-A-Dot Simulation Class                    File: thinkadot.hpp
// Author:  Ding Zhou
// Modified Oct 6, 2018
// ============================================================================

#ifndef THINK_A_DOT_HPP
#define THINK_A_DOT_HPP

#include "flipflop.hpp"

class ThinkADot {
private:
    static const int trans_table[2][8];
    FlipFlop ffs[8];

public:
    ThinkADot() { reset('L'); }

    char play (char hole)  ;
    void reset(char state) ;
    std::ostream& print( std::ostream& out ) const ;
};

// operation overload for output
inline std::ostream& operator<<( std::ostream& out, ThinkADot& tad ) {
    return tad.print( out );
}
#endif // THINK_A_DOT_HPP
