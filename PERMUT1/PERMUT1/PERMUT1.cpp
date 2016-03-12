#include <iostream>

using namespace std;

const int MaxK = 99;
const int MaxN = 13;
int Inversions[MaxK][MaxN];

int main(void)
{
	for(int i = 0; i < MaxN; i++)
		for(int j = 0; j < MaxK; j++)
			Inversions[j][i] = 0;
	Inversions[0][1] = 1;

	for(int i = 2; i < MaxN; i++)
		for(int j = 0; j < MaxK; j++)
		{
			int NumberOfTerms = (i*i-i)/2;
			int Midpoint = NumberOfTerms/2;
			if(j <= Midpoint)
			{
				Inversions[j][i] = Inversions[j][i-1] + Inversions[j-1][i];
				if(j-i >= 0) Inversions[j][i] -= Inversions[j-i][i-1];
			}
			else if(NumberOfTerms - j >= 0)
				Inversions[j][i] = Inversions[NumberOfTerms - j][i];
		}

	//for(int j = 0; j < 25; j++)
	//{
	//	for(int i = 0; i < 10; i++)
	//		cout << Inversions[j][i] << " ";
	//	cout << endl;
	//}

	//int n = 12;
	//for(int i = 0; i <= (n*n-n)/4; i++)
	//	cout << Inversions[i][n] << " ";
	//cout << endl;

	//int temp = 0;
	//for(int i = 0; i < MaxN; i++)
	//{
	//	for(int j = 0; j < MaxK; j++)
	//		temp += Inversions[j][i];
	//	cout << temp << endl;
	//	temp = 0;
	//}

	int NumberOfTestCases = 0;
	int n = 0;
	int k = 0;
	cin >> NumberOfTestCases;
	while(NumberOfTestCases--)
	{
		cin >> n >> k;
		cout << Inversions[k][n] << endl;
	}
}