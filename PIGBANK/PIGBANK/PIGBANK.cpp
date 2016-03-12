#include <iostream>
#include <map>
#include <vector>
#include <climits>

using namespace std;

int main(void)
{
	int NumberOfTests = 0;
	cin >> NumberOfTests;
	while(NumberOfTests--)
	{
		int Tare = 0;
		int Gross = 0;
		cin >> Tare >> Gross;
		int NetWeight = Gross - Tare;

		int NumberOfCoinTypes = 0;
		cin >> NumberOfCoinTypes;

		int CoinValue = 0;
		int CoinWeight = 0;
		map<int,int> Coins;
		for(int i = 0; i < NumberOfCoinTypes; i++)
		{
			cin >> CoinValue >> CoinWeight;
			Coins.insert(pair<int,int>(CoinWeight, CoinValue));
		}

		bool Possible = false;
		map<int,int>::iterator it;
		for(it = Coins.begin(); it != Coins.end(); it++)
		{
			Possible = Possible || NetWeight%(*it).first == 0;
		}
		if(Possible)
		{
			// Initialize State vector to infinity
			vector<int> State(NetWeight+1, INT_MAX);
			it = Coins.begin();
			//Initialize the States up to the weight of the first coin to 0
			for(int i = 0; i < (*it).first; i++) State[i] = 0;

			for(int i = 1; i <= NetWeight; i++)
			{
				for(it = Coins.begin(); it != Coins.end(); it++)
				{
					if((*it).first <= i && State[i-(*it).first] + (*it).second < State[i])
						State[i] = State[i - (*it).first] + (*it).second;
				}
			}


			cout << "The minimum amount of money in the piggy-bank is ";
			cout << State[NetWeight] << "." << endl;
		}
		else cout << "This is impossible." << endl;
	}
}