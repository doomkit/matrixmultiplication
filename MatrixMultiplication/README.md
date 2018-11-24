# Matrix multiplication

**Author:** Shkarupa Nikita, skarunik@fel.cvut.cz

## Single thread multiplication

Use  `-st` flag to run this application using single thread. 

For single thread option I've ovreloaded * operator for class matrix. It implements straightforward solution with 3 fro-cyclus  (O(n^3) complexity). 

## Multithread multiplication

Use `-mt` flag to run this application in multithread mode. 

For multithread option I've created method strassenMultiplication( ) in class matrix. It devides given matricies into sub-matricies and each thread works with its own sub-matrix.

**Important condition:**  
Matricies shoud be square with even dimensions (For example: 2x2, 4x4, 6x6...).

## Comparison

...

## Other

* Use `-help` flag to open help menu
* All matricies are generated randomly using get_random_double( ) method from CourseWare
* Time test starts after matricies are generated, so it only shows time spent on multiplication

**Code**
- [ ] CMakeLists.txt
- [ ] More threads if more cores
- [x] One thread implementation
- [x] OpenMP, VLA etc are not used
- [x] Additional libraries (POSIX, Win32 etc) are not used

**Test**
- [ ] Binary in "Release" mode
- [ ] Multithread is faster
- [ ] Both singlethread and multithread outputs are correct

**Docs**
- [ ] Commit hash
- [ ] Project description
- [ ] Results description
- [ ] Test environment
