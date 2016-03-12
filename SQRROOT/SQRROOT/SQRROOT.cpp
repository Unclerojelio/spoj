#include <iostream>
#include <string>

using namespace std;

string add(string a, string b)
{
	return a;
}

string divide(string a, string b)
{
	return a;
}

string square(string a)
{
	return a;
}

int main(void)
{
	string digits = "";
	int NumTests = 0;
	cin >> NumTests;
	while(NumTests--)
	{
		string digits = "";
		cin >> digits;
		string guess = "1";
		for(int i = 0; i < digits.length()/2; i++) guess += "0";
		while(square(guess) != digits)
			guess = divide(add(divide(digits, guess), guess), "2");
		cout << guess;
	}
}