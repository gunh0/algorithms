#include <iostream>
#include <ios>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int testNum = 0;
	int a = 0, b = 0;

	cin >> testNum;

	for (int i = 0; i < testNum; i++)
	{
		cin >> a >> b;
		cout << a + b << "\n";
	}

	return 0;
}