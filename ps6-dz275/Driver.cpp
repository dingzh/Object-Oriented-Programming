//  ---------------------------------------------------------------------------
//  blockchain driver implementation                                 Driver.cpp
//  Created by Ding Zhou on Dec 1, 2018
// ----------------------------------------------------------------------------

#include "Driver.hpp"

Driver::Driver() {
    // initiate bc[]
    Block* blk = new Block;
    Blockchain genesis( blk );
    for (int i = 0; i < 10; ++i) 
        bc[i] = genesis;
}

// print error message in case of illegal input
void printErr() {
    cout << "Error in command." << endl;
}

// start the driver to read command and simulate
void Driver::start() {
    string cmd;
    
    cout << "Input command: ";
    cin >> cmd;
    while (!cin.fail()) {
        int j, k;
        switch (cmd[0]) {
            case 'A':
            case 'a':
                if (cmd.length() != 3 
                        || cmd[1] < '0' || cmd[1] > '9'
                        || cmd[2] < '0' || cmd[2] > '9') {
                    printErr();
                } else {
                    j = cmd[1] - '0';
                    k = cmd[2] - '0';
                    bc[j] = bc[k];
                }
                break;

            case 'E':
            case 'e':
                if (cmd.length() != 2 || cmd[1] < '0' || cmd[1] > '9') {
                    printErr();
                } else {
                    j = cmd[1] - '0';
                    bc[j] = bc[j].extend();
                }
                break;

            case 'P':
            case 'p':
                for (int i = 0; i < 10; ++i) {
                    cout << bc[i] << endl;
                }
                break;

            case 'Q':
            case 'q':
                return ;

            default:
                printErr();
        }
        cout << "Input command: ";
        cin >> cmd;
    }
}

