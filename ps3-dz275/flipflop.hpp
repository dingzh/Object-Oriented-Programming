// ============================================================================
// Project: FlipFlop Class                                   File: flipflop.hpp
// Author:  Ding Zhou
// Modified Oct 6, 2018
// ============================================================================
#ifndef FLIPFLOP_HPP
#define FLIPFLOP_HPP

#include <iostream>

class FlipFlop {
public:
    enum FFState {STATE_L=0, STATE_R=1};

private:
    FFState state{STATE_L};

public:
    FlipFlop() = default;
    void      flip();
    void      setState( char state_char ) ;
    FFState   getState(  ) const { return state; }
    std::ostream&  print( std::ostream& out ) const ;
};

inline std::ostream& operator<<( std::ostream& out, const FlipFlop& ff ) {
    return ff.print( out );
}

#endif // FLIPFLOP_HPP
