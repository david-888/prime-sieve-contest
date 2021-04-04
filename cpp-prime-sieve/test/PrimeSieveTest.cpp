#include "zhang/math/PrimeSieve.h"

#include <gtest/gtest.h>

using namespace zhang::math;

class PrimeSieveTest : public testing::Test
{ };

TEST_F(PrimeSieveTest, range0)
{
    PrimeSieve primeSieve{0};
    primeSieve.sieve();
    int numberOfPrimes = primeSieve.countPrimes();
    EXPECT_EQ(numberOfPrimes, 0);
    EXPECT_FALSE(primeSieve.isPrime(0));
}

TEST_F(PrimeSieveTest, range1)
{
    PrimeSieve primeSieve{1};
    primeSieve.sieve();
    int numberOfPrimes = primeSieve.countPrimes();
    EXPECT_EQ(numberOfPrimes, 0);
    EXPECT_FALSE(primeSieve.isPrime(0));
    EXPECT_FALSE(primeSieve.isPrime(1));
}

TEST_F(PrimeSieveTest, range2)
{
    PrimeSieve primeSieve{2};
    primeSieve.sieve();
    int numberOfPrimes = primeSieve.countPrimes();
    EXPECT_EQ(numberOfPrimes, 1);
    EXPECT_FALSE(primeSieve.isPrime(0));
    EXPECT_FALSE(primeSieve.isPrime(1));
    EXPECT_TRUE(primeSieve.isPrime(2));
}

TEST_F(PrimeSieveTest, range3)
{
    PrimeSieve primeSieve{3};
    primeSieve.sieve();
    int numberOfPrimes = primeSieve.countPrimes();
    EXPECT_EQ(numberOfPrimes, 2);
    EXPECT_FALSE(primeSieve.isPrime(0));
    EXPECT_FALSE(primeSieve.isPrime(1));
    EXPECT_TRUE(primeSieve.isPrime(2));
    EXPECT_TRUE(primeSieve.isPrime(3));
}

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
