#include <iostream>
#include <cmath>

using namespace std;

unsigned int pows5[13] = {1,5,25,125,625,3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625};

unsigned int Z(unsigned int n)
{
	unsigned long sum = 0;
	short limit = floor(log10((long double)n)/0.698970004336); //log10(5.0)
	for(int i = 1; i <= limit; i++)
	{
		sum += n/pows5[i];
	}
	return sum;
}


int main(void)
{	
/*	int numTests = 0;
	unsigned int n = 0;
	cin >> numTests;
	while(numTests--)
	{
		cin >> n;
		cout << Z(n) << endl;
	}
	return 0;
*/

	unsigned int n = 1000000000;
	cout << "         Z(3): " << Z(3) << endl;
	cout << "        Z(25): " << Z(25) << endl;
	cout << "        Z(60): " << Z(60) << endl;
	cout << "       Z(100): " << Z(100) << endl;
	cout << "      Z(1024): " << Z(1024) << endl;
	cout << "     Z(23456): " << Z(23456) << endl;
	cout << "   Z(8735373): " << Z(8735373) << endl;
	cout << "  Z(10000000): " << Z(10000000) << endl;
	cout << " Z(100000000): " << Z(100000000) << endl;
	cout << " Z(500000000): " << Z(500000000) << endl;
	cout << "Z(1000000000): " << Z(1000000000) << endl;

}