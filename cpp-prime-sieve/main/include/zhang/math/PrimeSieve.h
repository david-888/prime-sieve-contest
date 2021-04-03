#pragma once
#ifndef ZHANG_MATH_PRIMESIEVE_H
#define ZHANG_MATH_PRIMESIEVE_H

#include <ostream>
#include <vector>

namespace zhang::math
{

class PrimeSieve final
{
    public:
        explicit PrimeSieve(int range);
        ~PrimeSieve() = default;
        void sieve();
        [[nodiscard]] int countPrimes() const;
        [[nodiscard]] bool isPrime(int candidate) const;
    private:
        int range;
        std::vector<bool> primeCandidates;
};

}

#endif
