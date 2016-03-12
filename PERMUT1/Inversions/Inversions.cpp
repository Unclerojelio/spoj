#include <iostream>

using namespace std;

const int N = 8;
int theNumbers[N];
const int MaxK = (N*N-N)/2;
int theInversions[MaxK+1];
int count = 0;

void swap(int j, int k)
{
	int temp = theNumbers[j];
	theNumbers[j] = theNumbers[k];
	theNumbers[k] = temp;
}

void countTheInversions()
{
	count++;
	int inversions = 0;
	for(int i = 0; i < N; i++)
		for(int j = i+1; j < N; j++)
			if(theNumbers[i] > theNumbers[j]) inversions++;
	theInversions[inversions]++;
}

void permute(int n)
{
	if(n == 1) countTheInversions();
	else
	{
		for (int i = 0; i < n; i++)
		{
			permute(n-1);
			if(n%2 == 1) swap(0, n-1);
			else swap(i, n-1);
		}
	}
}

int main(void)
{
	int sum = 0;
	for(int i = 0; i < N; i++)
		theNumbers[i] = i;
	permute(N);
	for(int i = 0; i <= MaxK; i++)
	{	
		sum += theInversions[i];
		cout << theInversions[i] << endl;
	}
	cout << "Sum: " << sum << endl;
	cout << "Count: " << count << endl;
	return 0;
}