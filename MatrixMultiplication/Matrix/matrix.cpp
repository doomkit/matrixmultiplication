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
    for (int a = 0; a < _dimensions.first; a++) {
        for (int b = 0; b < _dimensions.second; b++) {
            _rows[a][b] = getRandomDouble((double)0, (double)10);
        }
    }
    this->rows = _rows;
    this->dimensions = _dimensions;
};

matrix::matrix(vector<vector<double>> rows) :
    rows(rows) {
    this->dimensions = make_pair(rows.size(), rows[1].size());
};

matrix operator*(matrix A, matrix B)
{
    //  Check if we can multiply matricies.
    if (A.dimensions.second != B.dimensions.first) {
        throw invalid_argument("Can't multiply matricies with given dimensions.\n");
    }
    
    //  Straightforward multiplication
    vector<vector<double>> _rows(A.dimensions.first, vector<double>(B.dimensions.second));
    for (int a = 0; a < A.dimensions.first; a++) {
        for (int b = 0; b < B.dimensions.second; b++) {
            double value = 0;
            for (int c = 0; c < A.dimensions.second; c++) {
                value += round(A.rows[a][c] * B.rows[c][b]);
            }
            _rows[a][b] = value;
        }
    }
    matrix C(_rows);
    return C;
};

matrix strassenMultiplication(matrix A, matrix B)
{
    //  Check if we can multiply matricies.
    if (A.dimensions.first != A.dimensions.second
        || A.dimensions.second != B.dimensions.first
        || B.dimensions.first != B.dimensions.second) {
        throw invalid_argument("Can't multiply matricies with given dimensions.\n");
    }
    
    vector<vector<double>> _rows(A.dimensions.first, vector<double>(A.dimensions.first));
    matrix C(_rows);
    return C;
};
