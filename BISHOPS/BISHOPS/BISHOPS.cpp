#include <iostream>
#include <string>

using namespace std;

string N;

void subtract2()
{
	int Borrow = 0;
	int i = N.length()-1; 
	int TopDigit = (int)N[i] - (int)('0');
	if(TopDigit < 2)
	{
		TopDigit += 10;
		Borrow = 1;
	}
	else Borrow = 0;
	int ResultDigit = TopDigit - 2;
	N[i] = (char)((int)('0') + ResultDigit);
	i--;
	while(Borrow && i >= 0)
	{
		TopDigit = (int)N[i] - (int)('0') - Borrow;
		if(TopDigit == 0)
		{
			TopDigit += 10;
			Borrow = 1;
		}
		else Borrow = 0;
		int ResultDigit = TopDigit;
		N[i] = (char)((int)('0') + ResultDigit);
		i--;
	}
}

void twice()
{
	int Carry = 0;
	int TopDigit = 0;
	for(int i = N.length()-1; i >= 0; i--)
	{
		TopDigit = (int)N[i] - (int)('0');
		int ResultDigit = TopDigit * 2 + Carry;
		if(ResultDigit > 9)
		{
			ResultDigit = ResultDigit%10;
			Carry = 1;
		}
		else Carry = 0;
		N[i] = (char)((int)('0') + ResultDigit);
	}
	if(Carry) N = "1" + N;
}

int main(void)
{
	while(cin >> N)
	{
		if(N == "0") cout << "0" << endl;
		else if(N == "1") cout << "1" << endl;
		else
		{
			cout << N << " : ";
			twice();
			cout << N << " : ";
			subtract2();
			cout << N << endl;
		}
	}
}