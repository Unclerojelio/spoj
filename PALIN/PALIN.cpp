#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

char addOne(char c)
{
	int n = (int)c;
	n++;
	return (char)n;
}

int main(void)
{

	int numTests = 0;
	cin >> numTests;
	while(numTests--)
	{
		
		string digits = "";
		cin >> digits;
		int numDigits = (int)digits.length();
		
		bool allNines = true;
		
		for(int i = 0; i < numDigits; i++)
		{
			if(digits[i] != '9') allNines = false;
		}
		
		if(allNines)
		{
			digits[0] = '1';
			digits = digits + '0';
			numDigits++;
			for(int i = 1; i < numDigits; i++) digits[i] = '0';
		}
	
		int frontMarker = 0;
		int backMarker = 0;
		if(numDigits%2 == 0)
		{
			frontMarker = numDigits/2-1;
			backMarker = frontMarker+1;
		}
		else
		{
			frontMarker = (numDigits-1)/2;
			backMarker = frontMarker;
		}
		int frontMiddleMarker = frontMarker;
		int backMiddleMarker = backMarker;
		
		bool nextPalin = false;
	
		//cout << digits << endl;
		while(frontMarker >= 0)
		{
			if(digits[frontMarker] < digits[backMarker])
			{
				nextPalin = true;
				digits[frontMarker] = addOne(digits[frontMarker]);
				while(frontMarker >= 0)
				{
					digits[backMarker] = digits[frontMarker];
					backMarker++;
					frontMarker--;
				}
			}
			else if(digits[frontMarker] > digits[backMarker])
			{
				nextPalin = true;
				while(frontMarker >= 0)
				{
					digits[backMarker] = digits[frontMarker];
					backMarker++;
					frontMarker--;
				}
			}
			else
			{
				backMarker++;
				frontMarker--;
			}
		}
		if(!nextPalin)
		{
			if(frontMiddleMarker == backMiddleMarker && digits[frontMiddleMarker] != '9')
			{
				digits[frontMiddleMarker] = addOne(digits[frontMiddleMarker]);
			}
			else if(            frontMiddleMarker != backMiddleMarker 
			         && digits[frontMiddleMarker] != '9'
			         &&  digits[backMiddleMarker] != '9')
			{
				digits[frontMiddleMarker] = addOne(digits[frontMiddleMarker]);
				digits[backMiddleMarker] = addOne(digits[backMiddleMarker]);
			}
			else //if(frontMiddleMarker == backMiddleMarker && digits[frontMiddleMarker] == '9')
			{
				while(digits[frontMiddleMarker] == '9')
				{
					digits[frontMiddleMarker] = '0';
					digits[backMiddleMarker] = '0';
					frontMiddleMarker--;
					backMiddleMarker++;
				}
				digits[frontMiddleMarker] = addOne(digits[frontMiddleMarker]);
				digits[backMiddleMarker] = digits[frontMiddleMarker];
			}
			//else cout << "Not Next Palin" << endl;
		}
		cout << digits << endl;
	}
}