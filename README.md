# Matrix multiplication

**Author:** Shkarupa Nikita, skarunik@fel.cvut.cz

## Single thread multiplication

Use  `-st` flag to run this application using single thread. 

For single thread option I've ovreloaded * operator for class matrix. It implements straightforward solution with 3 for-cyclus  (O(n^3) complexity). 

## Multithreaded multiplication

Use `-mt` flag to run this application in multithreaded mode. 

For multithread option I've created method strassenMultiplication( ) in class matrix. It devides given matrices into sub-matrices and each thread works with its own sub-matrix.

**Important conditions:**  

* Matrices should be square with even dimensions (For example: 2x2, 4x4, 6x6...)
* Matrices should have same dimensions
* 2 or more concurrent threads have to be supported (otherwise you can run only single thread multiplication)

## Comparison

Comparison of these two multiplication in **Release mode**.  
**Computing power:** 2,3 GHz Intel Core i5 , Cores 2, Threads 4
Memory leaks were not detected while testing app in build in xCode profile testing.

Output of single thread multiplication:

```
Matrix Multiplication using single thread.
Matrices were generated.
Dimensions are: 1000x1000, 1000x1000
Starting multiplication using single thread.
Needed 8142 ms to finish multiplication using single thread.
Program ended with exit code: 0
```

Multithread multiplication:

```
Matrix Multiplication using multi thread.
Matrices were generated.
Dimensions are: 1000x1000, 1000x1000
Starting multithread multiplication with 4 treads.
Needed 1913 ms to finish multiplication using 4 threads.
Program ended with exit code: 0
```

As the result we have 4-5 times faster multiplication using 4 threads instead of just one. 

## Run

Go to `Build/Products/Release/` and run from terminal `./MatrixMultiplication opt` to execute release build or you can run

```
cmake CMakeLists.txt
make
./runfile opt
```

 where opt is one of these options:
 
* `-help` opens help menu  
* `-st` runs single thread multiplication  
* `-mt` runs multithread multiplication  

## Other

* Use `-help` flag to open help menu
* All matrices are generated randomly using get_random_double( ) method from CourseWare
* Time test starts after matrices are generated, so it only shows time spent on multiplication
* Both algorithms works correct (method printMatrix( ) allows us to check it manually on small matricies)

**Code**
- [ ] CMakeLists.txt
- [x] More threads if more cores
- [x] One thread implementation
- [x] OpenMP, VLA etc are not used
- [x] Additional libraries (POSIX, Win32 etc) are not used

**Test**
- [x] Binary in "Release" mode
- [x] Multithread is faster
- [x] Both singlethread and multithread outputs are correct

**Docs**
- [ ] Commit hash
- [x] Project description
- [x] Results description
- [x] Test environment
