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
#include <chrono>
#include <thread>

#include "Matrix/matrix.hpp"

using namespace std;

// Timer
template <typename TimePoint> std::chrono::milliseconds to_ms(TimePoint tp) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(tp);
}

// Singlethread scenarion
void singleThreadMultiplication()
{
    // Define matricies' demensions
    pair<int,int> size_a = make_pair(500, 500);
    pair<int,int> size_b = make_pair(500, 500);
    
    // Generate random matricies
    matrix matrixA(size_a);
    matrix matrixB(size_b);
    try {
        cout    << "Matricies were generated.\n"
                << "Dimensions are: "
                << size_a.first << "x"
                << size_a.second << ", "
                << size_b.first << "x"
                << size_b.second << "\n"
                << "Starting multiplication using single thread.\n";
        
        auto start = std::chrono::high_resolution_clock::now();
        matrix matrixC = matrixA * matrixB;
        auto end = std::chrono::high_resolution_clock::now();
        
        std::cout   << "Needed " << to_ms(end - start).count()
                    << " ms to finish multiplication using single thread.\n";
    } catch (invalid_argument e) {
        throw e;
    }
}

void multithreadMultiplication()
{
    
}

int main(int argc, char* argv[])
{
    enum options {HELP, ST, MT, FAIL};
    options choise = FAIL;
    
    // Number of concurrent threads supported
    unsigned int concurentThreadsSupported = std::thread::hardware_concurrency();
    
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
            cout    << "Help-menu:\n"
                    << "-st\t for single-thread mode\n"
                    << "-mt\t for multi-thread mode\n"
                    << "Concurrent threads supported: " << concurentThreadsSupported << "\n\n"
                    << "Find more information in README";
            break;
        }
        case ST: {
            cout << "Matrix Multiplication using single thread." << endl;
            try {
                singleThreadMultiplication();
            } catch (invalid_argument e) {
                cout << e.what() << "Test failed.\n";
                return 1;
            }
            break;
        }
        case MT: {
            
            
            if (concurentThreadsSupported == 1 || concurentThreadsSupported == 0) {
                cout    << "Can't start multithread multiplication.\n"
                        << "Your system supports only singlethread multiplication.";
                return 1;
            }
            try {
                cout << "Matrix Multiplication using multi thread." << endl;
                multithreadMultiplication();
            } catch (invalid_argument e) {
                cout << e.what() << "Test failed.\n";
                return 1;
            }
            break;
        }
        default: {
            cout    << "Error: Invalid arguments recived.\n"
                    << "Use --help to see commands list." << endl;
            return 1;
        }
    }
    return 0;
}
