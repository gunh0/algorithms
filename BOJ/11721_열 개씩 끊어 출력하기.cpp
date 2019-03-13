#include <iostream>

using namespace std;

int main()
{
	char input[100] = {0,};

	cin >> input;
	for (int i = 0; i < 100;)
	{
		if (input[i] == 0) break;
		cout << input[i++];
		if (i % 10 == 0)	cout << endl;
	}

	return 0;
}
