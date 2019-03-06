#include <iostream>

using namespace std;

int main()
{
	int result = 0;
	int input = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> input;
		if (input < 40) input = 40;
		result += input;
	}
	cout << result / 5;
	return 0;
}