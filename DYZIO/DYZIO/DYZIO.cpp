#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	int NumTests = 10;
	while(NumTests--)
	{
		int len = 0;
		string CutList = "";
		int NumberOfCuts = 0;
		int MaxLength = 0;
		int MaxCuts = 0;
	
		cin >> len;
		cin >> CutList;
		if(CutList[0] == '0') cout << "0" << endl;
		else
		{
			stack<char> CutStack;
			CutStack.push('1');
			NumberOfCuts++;
			MaxCuts++;
			for(int i = 1; i < CutList.length(); i++)
			{
				if(CutList[i] == '1' && CutStack.top() == '2')
				{
					NumberOfCuts++;
					CutStack.push('1');
					if(CutStack.size() > MaxLength)
					{
						MaxLength = CutStack.size();
						MaxCuts = NumberOfCuts;
					}
				}
				else if(CutList[i] == '1' && CutStack.top() == '1')
				{
					NumberOfCuts++;
					CutStack.pop();
					CutStack.push('2');
					CutStack.push('1');
					if(CutStack.size() > MaxLength)
					{
						MaxLength = CutStack.size();
						MaxCuts = NumberOfCuts;
					}
				}
				else if(CutList[i] == '1' && CutStack.top() == '0')
				{
					NumberOfCuts++;
					CutStack.pop();
					CutStack.pop();
					CutStack.push('2');
					CutStack.push('1');
					if(CutStack.size() > MaxLength)
					{
						MaxLength = CutStack.size();
						MaxCuts = NumberOfCuts;
					}
				}
				else if(CutList[i] == '0' && CutStack.top() == '2')
				{
					//CutStack.pop();
					CutStack.pop();
				}
				else if(CutList[i] == '0' && CutStack.top() == '1')
				{
					CutStack.pop();
					CutStack.push('2');
					CutStack.push('0');
				}
				else //CutList[i] == '0' && CutStack.top == '0'
				{
					CutStack.pop();
					CutStack.pop();
				}
			}
			cout << MaxCuts << endl;
		}
	}
	return 0;
}