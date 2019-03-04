#include <iostream>

using namespace std;

int main()
{
	int lineNum = 0;

	cin >> lineNum;

	for (int i = 0; i < lineNum; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < lineNum - i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}