/*	Problem 6
Sum square difference
2019-01-08
*/

#include <iostream>

using namespace std;

int main()
{
	int inputData = 0;
	int sqsum = 0;
	int sumsq = 0;

	//cin >> inputData;
	inputData = 100;
	for (int i = 1; i <= inputData; i++)
	{
		sumsq += i;
		sqsum += i*i;
	}
	cout << sumsq*sumsq - sqsum << endl;
	return 0;
}