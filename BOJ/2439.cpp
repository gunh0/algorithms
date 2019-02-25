#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	for (int i = n; i > 0; i--)
	{
		for (int j = i - 1; j > 0; j--)
		{
			cout << " ";
		}
		for (int k = n; k >= i; k--)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}