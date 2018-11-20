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

using namespace std;

/* Takes random double from interval [min, max] */
double getRandomDouble(double min, double max) {
    static std::mt19937 mt{ std::random_device{}() };
    static std::uniform_real_distribution<> dist(min, max);
//    return dist(mt);
    return round(dist(mt));
};

matrix::matrix(pair<int, int> _dimensions)
{
    vector<vector<double>> _rows(_dimensions.first, vector<double>(_dimensions.second));
    for (int a = 0; a < _dimensions.first; a++){
        for (int b = 0; b < _dimensions.second; b++){
            _rows[a][b] = getRandomDouble((double)0, (double)6);
            cout << _rows[a][b] << " ";
        }
        cout << endl;
    }
    this->rows = _rows;
    this->dimensions = _dimensions;
};

matrix::matrix(vector<vector<double>> rows) :
    rows(rows)
{};

matrix operator*(const matrix &A, const matrix &B)
{
    matrix a(make_pair(1, 1));
    return a;
};

//
//matrix::matrix multiThreadMultiplication(const matrix &A, const matrix &B){
//    return nullptr;
//};


