package com.zhang.math.prime;

public class PrimeSieveCli {

    public static void main(String[] args) throws Exception {
        if(args.length < 1 || args.length > 3) {
            System.out.println("usage: java -jar primesieve-xxx.jar <range> [<iterations>] [warmup]");
            System.exit(1);
            return;
        }

        final int range;
        try {
            range = Integer.parseInt(args[0]);
        } catch(NumberFormatException e) {
            System.err.println("invalid range: " + e.getMessage());
            System.exit(1);
            return;
        }
        if(range < 0) {
            System.err.println("invalid range: range must be greater than or equal to zero");
            System.exit(1);
            return;
        }

        int iterationLimit = 1;
        if(args.length >= 2) {
            try {
                iterationLimit = Integer.parseInt(args[1]);
            } catch(NumberFormatException e) {
                System.err.println("invalid number of iterations: " + e.getMessage());
                System.exit(1);
                return;
            }
            if(iterationLimit < 1) {
                System.err.println("number of iterations cannot be less than one");
                System.exit(1);
                return;
            }
        }

        boolean warmup = false;
        if(args.length >= 3) {
            if(args[2].equals("warmup")) {
                warmup = true;
            } else {
                System.err.println("unknown parameter: " + args[2]);
                System.exit(1);
                return;
            }
        }


        if(warmup) {
            int c = 0;
            do {
                PrimeSieve primeSieveWU = new PrimeSieve(1_000_000);
                primeSieveWU.sieve();
                primeSieveWU.countPrimes();
            } while(++c < 3000);
            Thread.sleep(100);
        }

        var start = System.currentTimeMillis();
        int iterationCounter = 0;
        PrimeSieve primeSieve = null;
        do {
            primeSieve = new PrimeSieve(range);
            primeSieve.sieve();
        } while(++iterationCounter < iterationLimit);
        var end = System.currentTimeMillis();
        var primeCount = primeSieve.countPrimes();
        System.out.println("Found " + primeCount + " primes.");
        System.out.println("Iteration Counter: " + iterationCounter);
        System.out.println("Duration: " + (end - start) + "ms");
    }

}
