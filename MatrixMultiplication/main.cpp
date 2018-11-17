//
//  main.cpp
//  MatrixMultiplication
//
//  Created by Nikita Shkarupa on 29/10/2018.
//  Copyright © 2018 Nikita Shkarupa. All rights reserved.
//


#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc, char* argv[]) {
    
    enum options {HELP, ST, MT, FAIL};
    options choise = FAIL;
    
    if (strcmp(argv[1], "-help") == 0)
        choise = HELP;
    if (strcmp(argv[1], "-st") == 0)
        choise = ST;
    if (strcmp(argv[1], "-mt") == 0)
        choise = MT;
    if (argc != 2)
        choise = FAIL;
    
    switch(choise) {
        case HELP: {
            cout << "Help-menu:" << endl;
            cout << "-st\t for single-thread mode" << endl;
            cout << "-mt\t for multi-thread mode" << endl;
            cout << "Program will generate random matricies for demonstration." << endl;
            break;
        }
        case ST: {
            cout << "Matrix Multiplication using single thread." << endl;
            break;
        }
        case MT: {
            cout << "Matrix Multiplication using multi thread." << endl;
            break;
        }
        default: {
            cout << "Error: Invalid arguments recived." << endl;
            cout << "Use --help to see commands list." << endl;
            return 1;
        }
    }

    return 0;
}
