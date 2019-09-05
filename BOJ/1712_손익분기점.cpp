#include <iostream>

using namespace std;

int main()
{
	long long int a = 0, b = 0, c = 0, x = 0;
	cin >> a >> b >> c;

	c <= b ? x = -1 : x = (a / (c - b)) + 1;
	cout << x << endl;

	return 0;
}