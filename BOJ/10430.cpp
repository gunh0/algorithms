#include <iostream>

using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	cout << (a + b) % c << "\n"
		<< (a%c + b%c) % c << "\n"
		<< (a*b) % c << "\n"
		<< ((a%c)*(b%c)) % c << endl;
	return 0;
}