#include <iostream>
#include <cmath>

using namespace std;

const int MaxPrime = 1000009;
char p[MaxPrime];

void sieve()
{
    int i,j;
    memset(p,1,sizeof(p));
    p[0]=0;
	p[1]=0;
    for(i=2;i<1002;i++)
    {
        if (p[i]==0) continue;
        j = i;
        while(j<MaxPrime) {
			j += i;
            p[j]=0;
        }
    }   
}   

int main(void)
{
	sieve ();
	unsigned long long n = 0;
	bool Flag = true;
	int Exponent = 0;
	int NumTests = 0;
	cin >> NumTests;
	while(NumTests--)
	{
		cin >> n;
		double MaxFactor = sqrt((double)n);
		if(n == 0 || n == 1) cout << "Yes" << endl;
		else
		{
			Flag = true;
			int FactorCount = 0;
			for(int i = 2; i <= MaxFactor; i++)
			{
				if (p[i]==0) continue;
				Exponent = 0;
				while (n % i == 0)
				{
					Exponent++;
					n /= i;
					FactorCount++;
				}
				if(i%4==3 && Exponent&1)
				{
					Flag = false;
					cout << "No" << endl;
					break;
				}
			}
			if(FactorCount == 0) cout << "No" << endl;
			else if(Flag) cout << "Yes" << endl;
		}
	}
	return 0;
}