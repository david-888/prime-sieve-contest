
cmake_minimum_required(VERSION 3.16)

project(prime-sieve)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_EXTENSIONS false)

if(CMAKE_COMPILER_ID STREQUAL "GNU")
    set(COMPILER_GNU true)
elseif(CMAKE_COMPILER_ID STREQUAL "CLANG")
    set(COMPILER_CLANG true)
elseif(CMAKE_COMPILER_ID STREQUAL "MSVC")
    set(COMPILER_MSVC true)
endif()

set(VERSION 0.0.1)

add_subdirectory(main)

if(WITH_TEST)
    add_subdirectory(test)
endif()

