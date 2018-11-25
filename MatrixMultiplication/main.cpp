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

// Define matricies size
#define SIZE_1 1000
#define SIZE_2 1000

// Define max ammount of threads
#define MAX_THREAD

using namespace std;

// Timer
template <typename TimePoint> std::chrono::milliseconds to_ms(TimePoint tp) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(tp);
}

void printMatrix(matrix matrixA) {
    cout << "\n";
    for (int i = 0; i < matrixA.dimensions.first; i++){
        for (int j = 0; j < matrixA.dimensions.second; j++) {
            cout << matrixA.rows[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Singlethread scenarion
void singleThreadMultiplication()
{
    pair<int, int> size_a = make_pair(SIZE_1, SIZE_2);
    pair<int, int> size_b = make_pair(SIZE_2, SIZE_1);
    
    // Generate random matricies
    matrix matrixA(size_a);
    matrix matrixB(size_b);
    
    //    printMatrix(matrixA);
    //    printMatrix(matrixB);
    
    cout    << "Matrices were generated.\n"
            << "Dimensions are: "
            << size_a.first << "x"
            << size_a.second << ", "
            << size_b.first << "x"
            << size_b.second << "\n"
            << "Starting multiplication using single thread.\n";
    try {
        auto start = std::chrono::high_resolution_clock::now();
        matrix matrixC = matrixA * matrixB;
        auto end = std::chrono::high_resolution_clock::now();
        std::cout   << "Needed " << to_ms(end - start).count()
                    << " ms to finish multiplication using single thread.\n";
        
//        printMatrix(matrixC);
    } catch (invalid_argument e) {
        throw e;
    }
}

void multithreadMultiplication(unsigned concurentThreadsSupported)
{
    pair<int, int> size_a = make_pair(SIZE_1, SIZE_2);
    pair<int, int> size_b = make_pair(SIZE_2, SIZE_1);
    
    // Generate random matricies
    matrix matrixA(size_a);
    matrix matrixB(size_b);
    
//    printMatrix(matrixA);
//    printMatrix(matrixB);
    
    // Check if we can use 2 or more threads
    if (concurentThreadsSupported < 2) {
        throw new invalid_argument("Can't start multithread multiplication.\nYour system supports only singlethread multiplication.\n");
    }
    int threads = (concurentThreadsSupported >= 4) ? 4 : 2;
    
    cout    << "Matrices were generated.\n"
            << "Dimensions are: "
            << size_a.first << "x"
            << size_a.second << ", "
            << size_b.first << "x"
            << size_b.second << "\n"
            << "Starting multithread multiplication with " << threads << " treads.\n";
    try {
        auto start = std::chrono::high_resolution_clock::now();
        matrix matrixC = strassenMultiplication(&matrixA, &matrixB, threads);
        auto end = std::chrono::high_resolution_clock::now();
        std::cout   << "Needed " << to_ms(end - start).count()
                    << " ms to finish multiplication using " << threads << " threads.\n";
        
//        printMatrix(matrixC);
    } catch (invalid_argument e) {
        throw e;
    }
}

int main(int argc, char* argv[])
{
    enum options {HELP, ST, MT, FAIL};
    options choise = FAIL;
    
    // Number of concurrent threads supported
    unsigned concurentThreadsSupported = std::thread::hardware_concurrency();
    
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
            cout << "Matrix Multiplication using multi thread." << endl;
            try {
                multithreadMultiplication(concurentThreadsSupported);
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
