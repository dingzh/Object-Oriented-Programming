//  ---------------------------------------------------------------------------
//  Main program for readint.                                        main.cpp
//  Created by Ding Zhou on Sept 19, 2018
// ----------------------------------------------------------------------------
#include "tools.hpp"

void run(int argc, char* argv[]);

// ----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    banner();
    run( argc, argv );
    bye();
    return 0;
}

/*
 * Open specified file, read in integers while skipping other chars.
 */
void run(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: readint filename" << endl;
        return ;
    }

    ifstream in( argv[1] );
    if (!in.is_open()) {
        fatal( "Cannot open file %s.\n", argv[1] );
    }


    while (!in.eof()) {
        int x;
        if (in >> x) {
            cout << dec << x << endl;
        }
        else if(!in.eof()) {
            char ch;
            in.clear();
            in.get(ch);
            unsigned char uch = ch;

            cout << "Skipping char: "
                 << setfill( ' ' ) << setw( 3 ) << dec << (int) uch;
            cout << " 0x" 
                 << setfill( '0' ) << setw( 2 ) << hex << (int) uch;

            if (isprint( ch )) {
                cout << " \'" << uch << "\'";
            }
            cout << endl;
        }
    } 
    cout << "Loop exit";
}

