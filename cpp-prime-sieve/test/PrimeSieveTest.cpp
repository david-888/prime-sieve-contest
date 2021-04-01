#include "zhang/math/PrimeSieve.h"

#include <gtest/gtest.h>

using namespace zhang::math;

class PrimeSieveTest : public testing::Test
{ };

TEST_F(PrimeSieveTest, range100)
{
    PrimeSieve primeSieve{100};
    primeSieve.sieve();
    int numberOfPrimes = primeSieve.countPrimes();
    EXPECT_EQ(numberOfPrimes, 25);
    EXPECT_FALSE(primeSieve.isPrime(0));
    EXPECT_FALSE(primeSieve.isPrime(1));
    EXPECT_TRUE(primeSieve.isPrime(2));
    EXPECT_TRUE(primeSieve.isPrime(3));
    EXPECT_FALSE(primeSieve.isPrime(4));
    EXPECT_TRUE(primeSieve.isPrime(5));
}
