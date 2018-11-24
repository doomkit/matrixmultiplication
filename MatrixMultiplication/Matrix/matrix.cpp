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
#include <pthread.h>

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

struct thread_data {
    int matrix_part;
    int size;
    vector<vector<double>> rows;
    matrix *matrixA;
    matrix *matrixB;
};

void *computeSubmatrix(void *arg)
{
    struct thread_data *data = (struct thread_data *) arg;
    for (int a = data->matrix_part * data->size / 4; a < (data->matrix_part + 1) * data->matrix_part / 4; a++) {
        for (int b = 0; b < data->size; b++) {
            for (int c = 0; c < data->size; c++) {
                double one = data->matrixA->rows[a][c];
                double two = data->matrixB->rows[c][b];
                double val = one * two;
                data->rows[a][b] += val;
            }
        }
    }
    pthread_exit(NULL);
}

matrix strassenMultiplication(matrix* A, matrix* B, int max_thread)
{
    //  Check if we can multiply matricies.
    if (A->dimensions.first != A->dimensions.second
        || A->dimensions.second != B->dimensions.first
        || B->dimensions.first != B->dimensions.second) {
        throw invalid_argument("Can't multiply matricies with given dimensions.\n");
    }
    
    pthread_t threads[max_thread];
    int _size = A->dimensions.first;
    vector<vector<double>> _rows(_size, vector<double>(_size));
    
    struct thread_data data[max_thread];
    int res;
    
    for (int i = 0; i < max_thread; i++){
        data[i].matrix_part = i+1;
        data[i].size = _size;
        data[i].rows = _rows;
        data[i].matrixA = A;
        data[i].matrixB = B;
        res = pthread_create(&threads[i], NULL, computeSubmatrix, (void *)&data[i]);
        if (res) {
            cout << "Error: unable to create thread, " << res << "\n";
            exit(-1);
        }
    }
    
    for (int i = 0; i < max_thread; i++) {
        pthread_join(threads[i], NULL);
    }
    
    matrix matixC(_rows);
    return matixC;
};
