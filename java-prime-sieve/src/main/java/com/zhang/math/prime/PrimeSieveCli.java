package com.zhang.math.prime;

public class PrimeSieveCli {
    private int range;
    private int iterationLimit = 1;
    private boolean warmup = false;
    private int warmupIterationLimit = 100;

    public static void main(String[] args) throws Exception {
        var app = new PrimeSieveCli();

        try {
            app.parseCliParameters(args);
            app.warmup();
        } catch(CliParameterException e) {
            System.err.println(e.getMessage());
            System.exit(1);
            return;
        } catch(WarmupException e) {
            System.err.println(e.getMessage());
            System.exit(2);
            return;
        }

        app.run();
    }

    private void run() {
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

    private void warmup() throws InterruptedException {
        if(warmup) {
            int warmupIterationCounter = 0;
            do {
                PrimeSieve primeSieveWU = new PrimeSieve(1_000_000);
                primeSieveWU.sieve();
                primeSieveWU.countPrimes();
            } while (++warmupIterationCounter < warmupIterationLimit);
            try {
                Thread.sleep(100);
            } catch(InterruptedException e) {
                throw new WarmupException("Interrupted during warmup", e);
            }
        }
    }

    private void parseCliParameters(String[] args) {
        if(args.length < 1 || args.length > 4) {
            throw new CliParameterException("wrong number of parameters\n"
                + "usage: java -jar primesieve-xxx.jar <range> [<iterations>] [warmup] [<warmup iterations>]");
        }

        try {
            range = Integer.parseInt(args[0]);
        } catch(NumberFormatException e) {
            throw new CliParameterException("invalid range: " + e.getMessage(), e);
        }
        if(range < 0) {
            throw new CliParameterException("invalid range: range must be greater than or equal to zero");
        }

        if(args.length >= 2) {
            try {
                iterationLimit = Integer.parseInt(args[1]);
            } catch(NumberFormatException e) {
                throw new CliParameterException("invalid number of iterations: " + e.getMessage(), e);
            }
            if(iterationLimit < 1) {
                throw new CliParameterException("number of iterations cannot be less than one");
            }
        }

        if(args.length >= 3) {
            if(args[2].equals("warmup")) {
                warmup = true;
            } else {
                throw new CliParameterException("unknown parameter: " + args[2]);
            }
        }

        if(args.length >= 4) {
            try {
                warmupIterationLimit = Integer.parseInt(args[3]);
            } catch (NumberFormatException e) {
                throw new CliParameterException("invalid number of warmup iterations: " + e.getMessage(), e);
            }
            if (warmupIterationLimit < 1) {
                throw new CliParameterException("number of warmup iterations cannot be less than one");
            }
        }
    }

}
