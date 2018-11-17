//
//  generator.hpp
//  MatrixMultiplication
//
//  Created by Nikita Shkarupa on 01/11/2018.
//  Copyright © 2018 Nikita Shkarupa. All rights reserved.
//

#ifndef generator_hpp
#define generator_hpp

#include <stdio.h>

class generator {
    
    public:
        /* Generate matricies in Input directory */
        generator();
    
    private:
        /* Remove all files in Input directory */
        void clearDirectory();
}

#endif /* generator_hpp */
