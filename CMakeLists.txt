cmake_minimum_required(VERSION 3.5)
project(MatrixMultiplication)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    runfile
    MatrixMultiplication/main.cpp
    MatrixMultiplication/Matrix/matrix.cpp
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(runfile Threads::Threads)

if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU" )
target_compile_options(runfile PRIVATE -Wall -Wextra -Wunreachable-code -Wpedantic)
endif()
if ( CMAKE_CXX_COMPILER_ID MATCHES "MSVC" )
target_compile_options(runfile PRIVATE /W4)
endif()


if (${CMAKE_VERSION} VERSION_GREATER 3.5)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT tests)
endif()
