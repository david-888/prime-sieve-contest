# Prime Sieve Contest

This is a fun contest inspired by David Plummer.
I saw his youtube video and needed to try and compare some languages by myself.
Here you can find his exciting youtube video:
https://www.youtube.com/watch?v=D3h62rgewZM
And here is his accompanying git repository:
https://github.com/davepl/Primes

I would like to compare some implementations in other languages with C++ and with each other.

Each implementation should be started by the name 'prime-sieve' if possible.
Every implementation must except two commandline parameters.
The first parameter is the upper limit of the range of integers to search for primes.
The second parameter is the number of iterations the program must do before completion.
For example this command must search for primes in the range 0 - 5000 inclusive.
It must do the search 100 times before it prints out any results and completes.

`$> ./prime-sieve 5000 100`

The time measurement starts just before the first iteration of searching for primes.
It does not include parameter parsing.
The time measurement stops right after the last iteration of searching for primes.
It does not include printing of results.

The individual implementations will measure and print out the time it takes to complete the computation.
To measure and display the time it takes to complete the whole program you can use the following commands.

**On Linux:**

`$> time ./prime-sieve 1000000 500`

**On Windows (Powershell):**

`$> Measure-Command { ./prime-sieve 1000000 500 | Out-Default }`


