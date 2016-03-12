#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//#define ONLINE_JUDGE

const int SIZE = 101;

int hashfunction(string str)
{
	int hash = 0;
	for ( int i = 0 ; i < str.length(); i++ )
		hash += int(str[i]) * (i+1);
	return (19 * hash) % SIZE;
}

int main (int argc, char * const argv[]) {
	istream *inf;
	
#ifndef ONLINE_JUDGE
	inf = new ifstream("hashit.in");
	if ( ! inf ) {
		std::cerr << "Could not open: " << "hashit.in" << std::endl ;
	}
#else
	inf = &cin;
#endif
	
	string hashtable[SIZE];
	
	int numTests = 0;
	int numOperations = 0;
	string command;
	string word;
	size_t pos;
	int count;
	
	*inf >> numTests;
	while(numTests--)
	{
		for(int i = 0; i < SIZE; i++) hashtable[i] = "";
		count = 0;
		*inf >> numOperations;
		for(int i = 0; i < numOperations; i++)
	    {
			*inf >> command;
			pos = command.find(":");
			word = command.substr(pos+1);
			command = command.substr(0, pos);

			int hashvalue = hashfunction(word);
			if(command == "ADD")
			{
				for(int j = 0; j < 20; j++)
				{
					int hash = (hashvalue + j*j + 23*j) % SIZE;
					string key = hashtable[hash];
					if(key == "")
					{
						hashtable[hash] = word;
						count++;
						break;
					}
					else if(key == word) break;
				}
			}
			else if(command == "DEL")
			{
				for(int j = 0; j < 20; j++)
				{
					int hash = (hashvalue + j*j + 23*j) % SIZE;
					string key = hashtable[hash];
					if(key == word)
					{
						hashtable[hash] = "";
						count--;
						break;
					}
				}
			}
			
		}
		cout << count << endl;
		for(int i = 0; i < SIZE; i++)
		{
			if(hashtable[i] != "")
				cout << i << ":" << hashtable[i] << endl;
		}
	}
	
	if ( inf != &cin )
	delete inf;
	
    return 0;
}
