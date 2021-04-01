
add_library(primesieve STATIC
    PrimeSieve.cpp
)

if(COMPILER_GNU OR COMPILER_CLANG)
    target_compile_options(primesieve
        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
)
endif()

target_include_directories(primesieve
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
        $<INSTALL_INTERFACE:include>
)



add_executable(prime-sieve
    Main.cpp
)

if(COMPILER_GNU OR COMPILER_CLANG)
    target_compile_options(prime-sieve
        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
)
endif()

target_include_directories(prime-sieve
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(prime-sieve
    PUBLIC
        primesieve
)

set_target_properties(prime-sieve
    PROPERTIES
        VERSION ${VERSION}
)

