package com.zhang.math.prime;

import java.util.BitSet;

public final class PrimeSieve {
    private final int range;
    private final BitSet primeCandidates;

    public PrimeSieve(int range) {
        this.range = range;
        this.primeCandidates = new BitSet(range + 1);
    }

    public final void sieve() {
        int limit = (int)Math.sqrt(range);
        primeCandidates.set(0);
        if(range > 1) {
            primeCandidates.set(1);
            for (int nextPrime = 3; nextPrime <= limit; nextPrime += 2) {
                for (int candidate = nextPrime; candidate <= limit; candidate += 2) {
                    if (!primeCandidates.get(candidate)) {
                        nextPrime = candidate;
                        break;
                    }
                }
                int notPrime = nextPrime * nextPrime;
                do {
                    primeCandidates.set(notPrime);
                    notPrime += nextPrime * 2;
                } while(notPrime < range);
            }
        }
    }

    public final int countPrimes() {
        int count = 0;
        int candidate = 0;
        if(range >= 2) {
            count = 1;
            candidate = 3;
        }
        while(candidate <= range) {
            count += primeCandidates.get(candidate) ? 0 : 1;
            candidate += 2;
        }
        return count;
    }

    public final boolean isPrime(int candidate) {
        if(candidate < 0) {
            return false;
        }
        if(candidate % 2 == 0) {
            return candidate == 2;
        }
        if(candidate <= range) {
            return primeCandidates.get(candidate);
        }
        throw new RuntimeException("PrimeSieve::isPrime() : candidate is out of range: " + candidate);
    }

}
