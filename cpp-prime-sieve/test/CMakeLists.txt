
add_subdirectory(3rd-party)

add_executable(prime-sieve-test
    Main.cpp
    PrimeSieveTest.cpp
)

target_compile_options(prime-sieve-test
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)

target_link_libraries(prime-sieve-test
    PUBLIC
        primesieve
        gtest_main
)

