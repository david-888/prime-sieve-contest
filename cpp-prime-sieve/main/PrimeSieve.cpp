#include "zhang/math/PrimeSieve.h"

#include <cmath>
#include <stdexcept>
#include <string>

namespace zhang::math
{

PrimeSieve::PrimeSieve(int range)
    : range{range}, primeCandidates(range / 2, true)
{ }

inline bool testPrimeCandidate(const std::vector<bool>& primeCandidates, int candidate)
{
    int index = (candidate - 1) / 2;
    return primeCandidates[index];
}

inline void clearPrimeCandidate(std::vector<bool>& primeCandidates, int candidate)
{
    int index = (candidate - 1) / 2;
    primeCandidates[index] = false;
}

void PrimeSieve::sieve()
{
    int limit = std::sqrt(range);
    primeCandidates[0] = false;
    if(range > 1) {
        for (int nextPrime = 3; nextPrime <= limit; nextPrime += 2) {
            for (int candidate = nextPrime; candidate <= limit; candidate += 2) {
                if (testPrimeCandidate(primeCandidates, candidate)) {
                    nextPrime = candidate;
                    break;
                }
            }
            int notPrime = nextPrime * nextPrime;
            do {
                clearPrimeCandidate(primeCandidates, notPrime);
                notPrime += nextPrime * 2;
            } while(notPrime < range);
        }
    }
}

int PrimeSieve::countPrimes() const
{
    int count{0};
    int candidate{3};
    if(range >= 2) {
        count = 1;
    }
    if(range < 3) {
        return count;
    }
    while(candidate <= range) {
        count += testPrimeCandidate(primeCandidates, candidate);
        candidate += 2;
    }
    return count;
}

bool PrimeSieve::isPrime(int candidate) const
{
    if(candidate < 2) {
        return false;
    }
    if(candidate % 2 == 0) {
        return candidate == 2;
    }
    if(candidate <= range) {
        return testPrimeCandidate(primeCandidates, candidate);
    }
    throw std::runtime_error(std::string{"PrimeSieve::isPrime() : candidate is out of range: "} + std::to_string(candidate));
}

}
