// ============================================================================
// Name: FlipFlop Class Implementation                       File: flipflop.cpp
// Author:  Ding Zhou 
// Modified Oct 6, 2018
// ============================================================================
#include "flipflop.hpp"

// flip this flipflop
void FlipFlop::flip() {
    state = (state == STATE_L) ? STATE_R : STATE_L;
}

// state setter to support reset operation
void FlipFlop::setState( char state_char ) {
    state = (state_char == 'L') ? STATE_L : STATE_R;
}

// print flipflop state
std::ostream& FlipFlop::print( std::ostream& out ) const {
    char ch = (state == STATE_L) ? 'L' : 'R';
    return out << ch;
}
