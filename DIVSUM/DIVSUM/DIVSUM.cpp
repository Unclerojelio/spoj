#include <iostream>
#include <cmath>

int main(void)
{
	int numTests = 0;
	int n = 500000;
//	std::cin >> numTests;
//	while(numTests--)
//	{
//		std::cin >> n;
		int sum = 1;
		int limit = (int)sqrt((double)n);
		if(limit*limit == n) sum += limit;
		for(int i = 2; i < limit; i++)
			if(n%i == 0) sum = sum + i + n/i;

		std::cout << sum << std::endl;
//	}
	return 0;
}