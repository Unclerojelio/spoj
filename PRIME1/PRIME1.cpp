// My solution for the PRIME1 programming challenge at SPOJ.com
// (http://www.spoj.com/problems/PRIME1/)
// 
// Peter wants to generate some prime numbers for his cryptosystem. Help him!
// Your task is to generate all prime numbers between two given numbers!
// 
// Input
// 
// The input begins with the number t of test cases in a single line (t<=10). In
// each of the next t lines there are two numbers m and n (1 <= m <= n <=
// 1000000000, n-m<=100000) separated by a space.
// 
// Output
// 
// For every test case print all prime numbers p such that m <= p <= n, one
// number per line, test cases separated by an empty line.
// 
// Example
// 
// Input:
// 2
// 1 10
// 3 5
// 
// Output:
// 2
// 3
// 5
// 7
// 
// 3
// 5
// 
// Warning: large Input/Output data, be careful with certain languages
// (though most should be OK if the algorithm is well designed)
// 
// Information
// 
// After cluster change, please consider PRINT as a more challenging problem.
//
// Todo:
// Fold sieve function into main to avoid passing parameters.
// will need to implement segmented sieve to cut down the time.

#include <iostream>
#include <vector>

using namespace std;

std::vector<bool> sieve_of_eratosthenes( unsigned long int const n_length )
{
    std::vector<bool> primeList(n_length);
    unsigned long int j = 0;
    int count = 0;
    primeList[0] = 1;
    primeList[1] = 1;
    for(unsigned long int i = 2; i <= 31622; i++) {
    	j = 0;
    	count = 0;
    	if(primeList[i] == 0) {
    		while(j <= n_length) {
    			j = i * i + i * count;
    			primeList[j] = 1;
    			count++;
    		}
    	}
    }
    return primeList;
}

int main(void)
{
	std::vector<bool> const primeList = sieve_of_eratosthenes( 1000000000 );
	int NumberOfTests = 0;
	int upper, lower;
	cin >> NumberOfTests;
	while(NumberOfTests--)
	{
		//Read in in two integers and find all the primes between them. 
		cin >> lower >> upper;
		for(int i = lower; i <= upper; i++)
			if(primeList[i] == 0)
				cout << i << endl;
	}
	cout << endl;
}