#include "zhang/math/PrimeSieve.h"

#include <charconv>
#include <chrono>
#include <iostream>
#include <string_view>

using namespace zhang::math;

int main(int argc, char* argv[])
{
    if(argc < 2 || argc > 3) {
        std::cerr << "usage: prime-sieve <range> [<iterations>]" << std::endl;
        return 1;
    }

    std::string_view argRange{argv[1]};
    long range{0};
#ifdef _WIN32
    auto result = std::from_chars(argRange.begin()._Unwrapped(), argRange.end()._Unwrapped(), range);
    if (result.ptr != argRange.end()._Unwrapped()) {
#else
    auto result = std::from_chars(argRange.begin(), argRange.end(), range);
    if (result.ptr != argRange.end()) {
#endif
        std::cerr << "invalid range: not an integer (base 10)" << std::endl;
        return 1;
    }
    if(range < 0) {
        std::cerr << "invalid range: range must be greater than or equal to zero" << std::endl;
        return 1;
    }

    int iterationLimit{1};
    if(argc == 3) {
        std::string_view argIterations{argv[2]};
#ifdef _WIN32
        result = std::from_chars(argIterations.begin()._Unwrapped(), argIterations.end()._Unwrapped(), iterationLimit);
        if(result.ptr != argIterations.end()._Unwrapped()) {
#else
        result = std::from_chars(argIterations.begin(), argIterations.end(), iterationLimit);
        if (result.ptr != argIterations.end()) {
#endif
            std::cerr << "invalid number of iterations: not an integer (base 10)" << std::endl;
            return 1;
        }
        if(iterationLimit < 1) {
            std::cerr << "number of iterations cannot be less than one" << std::endl;
            return 1;
        }
    }

    auto start = std::chrono::steady_clock::now();
    int iterationCounter{0};
    PrimeSieve* primeSieve = nullptr;
    do {
        delete primeSieve;
        primeSieve = new PrimeSieve(range);
        primeSieve->sieve();
    } while(++iterationCounter < iterationLimit);
    auto primeCount = primeSieve->countPrimes();
    std::cout << "Found " << primeCount << " primes.\n";
    std::cout << "Iteration Counter: " << iterationCounter << "\n";
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << "ms" << std::endl;
    return 0;
}

