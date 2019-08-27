#include <iostream>

using namespace std;

int main()
{
	unsigned long long int result = 1;
	int input = 0;
	cin >> input;
	for (int i = 1; i <= input; i++)
		result *= i;
	cout << result << endl;
	return 0;
}