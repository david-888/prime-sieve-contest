
cmake_minimum_required(VERSION 3.16)

project(prime-sieve)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_EXTENSIONS false)

set(VERSION 0.0.1)

add_subdirectory(main)

if(WITH_TEST)
    add_subdirectory(test)
endif()

