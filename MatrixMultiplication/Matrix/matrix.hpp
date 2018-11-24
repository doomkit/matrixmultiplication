//
//  matrix.hpp
//  MatrixMultiplication
//
//  Created by Nikita Shkarupa on 31/10/2018.
//  Copyright © 2018 Nikita Shkarupa. All rights reserved.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <vector>

using namespace std;

class matrix
{
    public:
        vector<vector<double>> rows;
        pair<int, int> dimensions;
    
        /* Generates random matrix of defined size */
        matrix(pair<int, int>);
    
        /* Generates matrix from vector */
        matrix(vector<vector<double>>);
    
        /* Strightforward single thread multiplication */
        friend matrix operator* (matrix, matrix);
};

/* Multi thread matrix multiplication */
matrix strassenMultiplication(matrix* matrixA, matrix* matrixB, int threads);

#endif /* matrix_hpp */
