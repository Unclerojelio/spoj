import math
import sys
# Borrowed from:
# http://stackoverflow.com/questions/25157383/segmented-sieve-of-eratosthenes-sieving-composite-numbers-by-their-indexes
# Modified by: Roger Banks (roger_banks@mac.com)
# BUG: Excludes y from the output if y is prime and close to sqrt(y).

def prime_sieve(n):
    """Use the Sieve of Eratosthenes to list primes 0 to n."""
    primes = range(n+1)
    primes[1] = 0
    for i in range(4, n+1, 2):
        primes[i] = 0
    for x in range(3, int(math.sqrt(n))+1, 2):
        if primes[x]:
            for i in range(2*primes[x], n+1, primes[x]):
                primes[i] = 0
    return filter(None, primes)
    

def ranged_primes(x, y):
    """List primes between x and y."""
    if x == 1: x += 1
    max_prime = int(math.sqrt(y))
    # still don't have a good way to differentiate between just calculating the primes
    # and segmenting the sieve
    if y < 317:
    	primes = prime_sieve(y)
        return [n for n in range(x, y+1) if n in primes]
    else:
    	primes = prime_sieve(max_prime)
        return [n for n in range(x, y+1) if all(n % p for p in primes)]

def main():

    num_tests = int(sys.stdin.readline())
    for i in range(num_tests):	
    	input = sys.stdin.readline()
    	values = input.split()
    	x = int(values[0])
    	y = int(values[1])
    	results = ranged_primes(x, y)
        for j in range(len(results)):
            print results[j]
        print


if __name__ == '__main__':
    main()