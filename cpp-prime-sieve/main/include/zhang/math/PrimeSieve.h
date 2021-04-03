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
        explicit PrimeSieve(long range);
        ~PrimeSieve() = default;
        void sieve();
        [[nodiscard]] long countPrimes() const;
        [[nodiscard]] bool isPrime(long candidate) const;
    private:
        long range;
        std::vector<bool> primeCandidates;
};

}

#endif
