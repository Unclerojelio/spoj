#include <iostream>

using namespace std;

int main(void)
{
	bool Inverted = false;
	int Length;
	cin >> Length;
	while(Length)
	{
		int* Digits = NULL;
		int* InvDigits = NULL;
		Digits = new int[Length];
		InvDigits = new int[Length];
		int Digit;
		for(int i = 0; i < Length; i++)
		{
			cin >> Digit;
			Digits[i] = Digit;
			InvDigits[Digit] = i;
		}
		for(int i = 0; i < Length; i++)
			Inverted &= Digits[i] == InvDigits[i];

		if(Inverted) cout << "ambiguous" << endl;
		else cout << "not ambiguous" << endl;
		cin >> Length;
	}
	return 0;
}