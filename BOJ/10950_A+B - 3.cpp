#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	int** ABarr = new int*[T];

	for (int i = 0; i < T; i++)
	{
		ABarr[i] = new int[2];
		cin >> ABarr[i][0] >> ABarr[i][1];
	}

	for (int j = 0; j < T; j++)
	{
		cout << ABarr[j][0] + ABarr[j][1] << endl;
	}

	return 0;
}