#include <iostream>

int memo[1000000];

void collatz(int n) {
	int count = 0;
	int temp = n;
	while(temp != 1) {
		if(temp%2 == 0) temp = temp/2;
		else temp = temp*3 + 1;
		count++;
		if(memo[temp] != 0) {
			memo[n] = count + memo[temp];
			return;
		}
	}
}

int main (int argc, char * const argv[]) {
	memo[1] = 1;
	int i, j;
	int temp, max;
	while(std::cin >> i >> j) {
		//std::cout << i << "\t" << j << std::endl;
		if(i > j) {
			temp = i;
			i = j;
			j = temp;
		}
		
		max = 0;
		for(int k = i; k <= j; k++) {
			if(memo[k] == 0) {
				collatz(k);
			}
			if(max < memo[k]) max = memo[k];
		}
		//This needs to print out i and j in the order in which they were received.
		std::cout << i << "\t" << j << "\t" << max << std::endl;
	}
    std::cout << "Hello, World!\n";
    return 0;
}
