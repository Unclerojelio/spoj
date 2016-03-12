#include <iostream>
#include <cmath>

using namespace std;
const int MaxSize = 1000001;
short Points[MaxSize][2];

int main(void)
{
	int NumberOfTests = 0;
	cin >> NumberOfTests;
	while(NumberOfTests--)
	{
		int x = 0, y = 0;
		int NumberOfPoints = 0;
		cin >> NumberOfPoints;
		for(int i = 0; i < NumberOfPoints; i++)
		{
			cin >> Points[i][0] >> Points[i][1];
		}
		Points[NumberOfPoints][0] = Points[0][0];
		Points[NumberOfPoints][1] = Points[0][1];

		long Sum = 0;
		long SumX = 0;
		long SumY = 0;
		double Area = 0.0;
		double CoordX = 0.0;
		double CoordY = 0.0;
		for(int i = 0; i < NumberOfPoints; i++)
		{
			Sum += Points[i][0]*Points[i+1][1] - Points[i+1][0]*Points[i][1];
		}
		Area = Sum/2.0f;

		for(int i = 0; i < NumberOfPoints; i++)
		{
			SumX += (Points[i][0] + Points[i+1][0]) * (Points[i][0]*Points[i+1][1] - Points[i+1][0]*Points[i][1]);
			SumY += (Points[i][1] + Points[i+1][1]) * (Points[i][0]*Points[i+1][1] - Points[i+1][0]*Points[i][1]);
		}
		CoordX = SumX/(6*Area);
		CoordY = SumY/(6*Area);
		if(fabs(CoordX)<0.005) CoordX=0.00;
		if(fabs(CoordY)<0.005) CoordY=0.00;

		cout.precision(2);
		cout << fixed << CoordX << " " << CoordY << endl;
	}
}