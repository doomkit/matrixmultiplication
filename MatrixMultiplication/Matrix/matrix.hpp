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

class matrix {
    public:
        /* Construct matrix from txt file */
        matrix(const char* filename);
    
        /* Overload multiplication operator */
        friend matrix operator* (const matrix &A, const matrix &B);
    
    private:
        vector<vector<double>> rows;
        pair<int, int> dimensions;
    
        /* Used in constructor only */
        void setDimension();
};

#endif /* matrix_hpp */
