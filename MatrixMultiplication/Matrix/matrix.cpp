//
//  matrix.cpp
//  MatrixMultiplication
//
//  Created by Nikita Shkarupa on 31/10/2018.
//  Copyright © 2018 Nikita Shkarupa. All rights reserved.
//

#include "matrix.hpp"
#include <iostream>

using namespace std;

matrix::matrix(const char* filename) {
    std::cout << "Construct matrix.";
}


matrix operator*(const matrix &A, const matrix &B){
    return nullptr;
}

void matrix::setDimension(){
    cout << "Set dimension.";
}
