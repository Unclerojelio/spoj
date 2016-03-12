// Shortest path algorithm implementation for a programming challenge. 

// Start Date: 18 May 2014
// Author: Roger Banks (roger_banks@mac.com)

// Challenge description:
// You are given a list of cities. Each direct connection between two cities has its
// transportation cost (an integer bigger than 0). The goal is to find the paths of
// minimum cost between pairs of cities. Assume that the cost of each path (which is
// the sum of costs of all direct connections belongning to this path) is at most 200000.
// The name of a city is a string containing characters a,...,z and is at most 10
// characters long.
// 
// Input
// 
// s [the number of tests <= 10]
// n [the number of cities <= 10000]
// NAME [city name]
// p [the number of neighbours of city NAME]
// nr cost [nr - index of a city connected to NAME (the index of the first city is 1)]
//            [cost - the transportation cost]
// r [the number of paths to find <= 100]
// NAME1 NAME2 [NAME1 - source, NAME2 - destination]
// [empty line separating the tests]

// Output
// 
// cost [the minimum transportation cost from city NAME1 to city NAME2 (one per line)]

// Challenge website:
// http://www.spoj.com/problems/SHPATH/

// Implementation:
// http://en.wikipedia.org/wiki/Dijkstra's_algorithm

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

//const int MAX_CITIES = 10000;

class City
{
		string name;
		bool visited;
		int cost;
		vector<pair<int, int> > neighbors;
	public:
		City();
		City(string s);
		~City();
		inline string getName() { return name; }
		inline bool getVisited(){ return visited; }
		inline int getCost() { return cost; }
		inline void setName(string s) { name = s; }
		inline void setVisited(bool v) { visited = v; }
		inline void setCost(int n) {cost = n; }
		void addNeighbor(int n, int cost);
		void showNeighbors();
		inline int getNumberOfNeighbors() { return (int)neighbors.size(); }
		inline int getNeighborID(int n) { return neighbors[n].first; }
		inline int getNeighborDistance(int n) { return neighbors[n].second; } 
		void showCity();
		void visitNeighbor(int n, int cost);
		int findCheapestNeighbor();
};

City::City()
{
	name = "";
	visited = false;
	cost = 0;
}

City::City(string s)
{
	name = s;
	visited = false;
	cost = 0;
}

City::~City()
{
}

void City::addNeighbor(int n, int cost)
{
	pair<int,int> neighbor(n, cost);
	neighbors.push_back(neighbor);
}

void City::showNeighbors()
{
	for(int i = 0; i < (int)neighbors.size(); i++)
	{
		cout << "Neighbor: " << neighbors[i].first << " Distance: " << neighbors[i].second;
		cout << endl;
	}
}

void City::showCity()
{
	cout << "Name :" << name << endl;
	if(visited)
		cout << "Visited";
	else cout << "Not Visited";
	cout << endl;
	cout << "Cost: " << cost << endl;
	this->showNeighbors();
}

// Container of all the unvisited cities.
vector<City*> cities;

int main(void)
{
	int numTests = 0;
	int numCities = 0;
	cin >> numTests;
	//cout << "Number of Tests: " << numTests << endl;
	while(numTests--)
	{
		numCities = 0;
		cin >> numCities;
		//cout << "Number of Cities: " << numCities << endl;
		while(numCities--)
		{
			string cityName;
			int numNeighbors = 0;
			cin >> cityName;
			cin >> numNeighbors;
			City *theCity = new City(cityName);
			cities.push_back(theCity);
			while(numNeighbors--)
			{
				int neighbor = 0;
				int distance = 0;
				cin >> neighbor >> distance;
				theCity->addNeighbor(neighbor, distance);
			}
			//theCity->showCity();
		}
	}
	int numPaths = 0;
	int current = 0;
	cin >> numPaths;
	while(numPaths--)
	{
		string startCityName;
		string endCityName;
		City* startCity;
		City* endCity;
		cin >> startCityName >> endCityName;
		for(int i = 0; i < (int)cities.size(); i++)
		{
			if(startCityName == cities[i]->getName())
			{ 
				startCity = cities[i];
				// Set the initial node as current.
				current = i;
			}
			if(endCityName == cities[i]->getName())
			{
				endCity = cities[i];
			}
		// Assign to every node a tentative cost value: set it to zero for our
		// initial node and to infinity for all other nodes.
		cities[i]->setCost(INT_MAX);
		cities[i]->setVisited(false);
		}
		
		cities[current]->setCost(0);
		cities[current]->setVisited(true);
		
		cout << endl;
		cout << "Start City" << endl;
		startCity->showCity();
		cout << "End City" << endl;
		endCity->showCity();
		
		cout << "Number of current city neighbors: ";
		cout << cities[current]->getNumberOfNeighbors() << endl;
		
		for(int i = 0; i < cities[current]->getNumberOfNeighbors(); i++)
		{
			cout << "Neighbor ID: " << cities[current]->getNeighborID(i) << endl;
			cout << "Neighbor Distance: " << cities[current]->getNeighborDistance(i) << endl;
		}
	}
	return 0;
}