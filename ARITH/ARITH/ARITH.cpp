#include <iostream>
#include <string>

using namespace std;

string equation = "123456789*987654321";
string firstNumber = "";
string secondNumber = "";
string result = "3450983095835";
string intermediate[501];
int magnitude = 0;

string sum(string n1, string n2)
{
	int carry = 0;
	string theSum = "";
	int numLeadingZeros = 0;
	if(n1.length() >= n2.length())
	{
		numLeadingZeros = (int)n1.length() - (int)n2.length();
		for(int i = 0; i < numLeadingZeros; i++)
			n2 = '0' + n2;
	}
	else
	{
		numLeadingZeros = (int)n2.length() - (int)n1.length();
		for(int i = 0; i < numLeadingZeros; i++)
			n1 = '0' + n1;
	}

	int i = (int)n1.length();
	while(i--)
	{
		int theNumber = carry + ((int)n1[i]-(int)('0')) + ((int)n2[i]-(int)('0'));
		int theDigit = theNumber%10;
		carry = theNumber/10;
		theSum = (char)(theDigit + (int)('0')) + theSum;
	}
	if(carry != 0)
		theSum = (char)(carry + (int)('0')) + theSum;
	return theSum;
}
void add(void)
{
	int carry = 0;
	string temp1 = "";
	string temp2 = "";
	result = "";
	int numLeadingZeros = 0;
	if(firstNumber.length() >= secondNumber.length())
	{
		temp1 = firstNumber;
		temp2 = secondNumber;
		numLeadingZeros = (int)firstNumber.length() - (int)secondNumber.length();
	}
	else
	{
		temp1 = secondNumber;
		temp2 = firstNumber;
		numLeadingZeros = (int)secondNumber.length() - (int)firstNumber.length();
	}
	for(int i = 0; i < numLeadingZeros; i++)
		temp2 = '0' + temp2;

	int i = (int)temp1.length();
	while(i--)
	{
		int theNumber = carry + ((int)temp1[i]-(int)('0')) + ((int)temp2[i]-(int)('0'));
		int theDigit = theNumber%10;
		carry = theNumber/10;
		result = (char)(theDigit + (int)('0')) + result;
	}
	if(carry != 0)
		result = (char)(carry + (int)('0')) + result;
}

void subtract(void)
{
	
	result = "";
	int borrow = 0;
	
	string temp = secondNumber;
	int numLeadingZeros = (int)firstNumber.length() - (int)secondNumber.length();
	for(int i = 0; i < numLeadingZeros; i++)
		temp = '0' + temp;

	int i = (int)firstNumber.length();
	while(i--)
	{
		int temp1 = (int)firstNumber[i] - (int)('0') - borrow;
		int temp2 = (int)temp[i] - (int)('0');
		if(temp1 < temp2)
		{
			borrow = 1;
			temp1 += 10;
		}
		else borrow = 0;
		int theDigit = temp1-temp2;
		result = (char)(theDigit + (int)('0')) + result;
	}
	while(result[0] == '0')
		result = result.substr(1);
}

void multiply(void)
{
	int temp = 0;
	result = "";
	int carry = 0;
	magnitude = 0;
	for(int j = (int)secondNumber.length()-1; j >= 0; j--)
	{
		carry = 0;
		intermediate[magnitude] = "";
		for(int i = (int)firstNumber.length()-1; i >= 0; i--)
		{
			temp = ((int)secondNumber[j] - (int)('0')) * ((int)firstNumber[i] - (int)('0')) + carry;
			int theDigit = temp%10;
			carry = temp/10;
			intermediate[magnitude] = (char)(theDigit + (int)('0')) + intermediate[magnitude];
		}
		if(carry != 0)
		intermediate[magnitude] = (char)(carry + (int)('0')) + intermediate[magnitude];
		for(int i = 0; i < magnitude; i++)
			intermediate[magnitude] = intermediate[magnitude] + '0';
		result = sum(result, intermediate[magnitude]);
		magnitude++;
	}
}
int main(void)
{
	int numDashes = 0;
	string firstNumberPad = "";
	string secondNumberPad = "";
	string separator = "";
	string resultPad = "";
	string separatorPad = "";
	size_t found = 0;
	found = equation.find('+');
	char op;
	if(found != string::npos)
	{
		op = '+';
		firstNumber = equation.substr(0, found);
		secondNumber = equation.substr(found+1);
	}
	found = equation.find('-');
	if(found != string::npos)
	{
		op = '-';
		firstNumber = equation.substr(0, found);
		secondNumber = equation.substr(found+1);
	}
	found = equation.find('*');
	if(found != string::npos)
	{
		op = '*';
		firstNumber = equation.substr(0, found);
		secondNumber = equation.substr(found+1);
	}

	switch (op)
	{
		case '+':
			add();
			break;
		case '-':
			subtract();
			break;
		case '*':
			multiply();
			break;
	}

	unsigned int longestString = 0;
	if(longestString <= (secondNumber.length() + 1))
	{
		longestString = (int)secondNumber.length() + 1;
		numDashes = longestString;
	}
	if(longestString <= (int)result.length())
	{
		longestString = (int)result.length();
		numDashes = longestString;
	}
	if(longestString <= firstNumber.length())
		longestString = (int)firstNumber.length();
	
	for(int i = (int)firstNumber.length(); i < (int)longestString; i++)
		firstNumberPad += " ";
	for(int i = (int)(secondNumber.length() + 1); i < (int)longestString; i++)
		secondNumberPad += " ";
	for(int i = 0; i < numDashes; i++)
		separator += "-";
		for(int i = (int)separator.length(); i < (int)longestString; i++)
		separatorPad = " ";
	for(int i = (int)result.length(); i < (int)longestString; i++)
		resultPad = " ";

	cout << firstNumberPad << firstNumber << endl;
	cout << secondNumberPad << op << secondNumber << endl;
	cout << separatorPad << separator << endl;

	if(op == '*')
	{
		for(int i = 0; i < magnitude; i++)
		{
			for(int j = magnitude-i; j > 1; j--)
				cout << " ";
			intermediate[i] = intermediate[i].substr(0,intermediate[i].length() - i);
			cout << intermediate[i] << endl;
		}
		string sumDashes = "";
		for(int i = 0; i < (int)result.length(); i++)
			sumDashes += '-';
		cout << sumDashes << endl;
	}

	cout << resultPad << result << endl;
}