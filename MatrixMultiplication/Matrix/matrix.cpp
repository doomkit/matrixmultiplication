//
//  matrix.cpp
//  MatrixMultiplication
//
//  Created by Nikita Shkarupa on 31/10/2018.
//  Copyright © 2018 Nikita Shkarupa. All rights reserved.
//

#include "matrix.hpp"
#include <iostream>
#include <random>

//  Define matrix max size
//#define MAX_SIZE 100

using namespace std;

/* Takes random double from interval [min, max] */
double getRandomDouble(double min, double max) {
    static std::mt19937 mt{ std::random_device{}() };
    static std::uniform_real_distribution<> dist(min, max);
    return round(dist(mt));
};

matrix::matrix(pair<int, int> _dimensions)
{
    vector<vector<double>> _rows(_dimensions.first, vector<double>(_dimensions.second));
    for (int a = 0; a < _dimensions.first; a++){
        for (int b = 0; b < _dimensions.second; b++){
            _rows[a][b] = getRandomDouble((double)0, (double)10);
        }
    }
    this->rows = _rows;
    this->dimensions = _dimensions;
};

matrix::matrix(vector<vector<double>> rows) :
    rows(rows)
{
    this->dimensions = make_pair(rows.size(), rows[1].size());
};

matrix operator*(matrix A, matrix B)
{
    //  Check if we can multiply matricies.
    //  Amount of matrixA rows should be equal to amount of matrixB columns.
    if (A.dimensions.second != B.dimensions.first)
    {
        throw invalid_argument("Can't multiply matricies given dimensions.\n");
    }
    
    //  Straightforward multiplication
    vector<vector<double>> _rows(A.dimensions.first, vector<double>(B.dimensions.second));
    for (int a = 0; a < A.dimensions.first; a++)
    {
        for (int b = 0; b < B.dimensions.second; b++)
        {
            double value = 0;
            for (int c = 0; c < A.dimensions.second; c++)
            {
                value += round(A.rows[a][c] * B.rows[c][b]);
            }
            _rows[a][b] = value;
        }
        
    }
    matrix a(_rows);
    return a;
};


//matrix::matrix strassenMultiplication(const matrix &A, const matrix &B){
//    return nullptr;
//};
