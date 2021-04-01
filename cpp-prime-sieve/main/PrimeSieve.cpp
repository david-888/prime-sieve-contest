#include "zhang/math/PrimeSieve.h"

#include <cmath>
#include <stdexcept>
#include <string>

namespace zhang::math
{

PrimeSieve::PrimeSieve(int range)
    : primeCandidates(range + 1, true)
{ }

void PrimeSieve::sieve()
{
    int range = primeCandidates.size();
    int limit = std::sqrt(primeCandidates.size());
    primeCandidates[0] = false;
    if(range > 1) {
        primeCandidates[1] = false;
        for (int nextPrime = 3; nextPrime <= limit; nextPrime += 2) {
            for (int candidate = nextPrime; candidate <= limit; candidate += 2) {
                if (primeCandidates[candidate]) {
                    nextPrime = candidate;
                    break;
                }
            }
            int notPrime = nextPrime * nextPrime;
            do {
                primeCandidates[notPrime] = false;
                notPrime += nextPrime * 2;
            } while(notPrime < range);
        }
    }
}

int PrimeSieve::countPrimes() const
{
    int count{0};
    int candidate = 0;
    int range = primeCandidates.size();
    if(range > 2) {
        count = 1;
        candidate = 3;
    }
    while(candidate < range) {
        count += primeCandidates[candidate];
        candidate += 2;
    }
    return count;
}

bool PrimeSieve::isPrime(int candidate) const
{
    if(candidate < 0) {
        return false;
    }
    if(candidate % 2 == 0) {
        return candidate == 2;
    }
    if(candidate < static_cast<int>(primeCandidates.size())) {
        return primeCandidates[candidate];
    }
    throw std::runtime_error(std::string{"PrimeSieve::isPrime() : candidate is out of range: "} + std::to_string(candidate));
}

}
