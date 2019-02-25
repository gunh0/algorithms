#include <iostream>

using namespace std;

int main()
{
	long long int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	a = (a%c == 0) ? a /= c : a = a / c + 1;
	b = (b%c == 0) ? b /= c : b = b / c + 1;
	cout << a*b << endl;
	return 0;
}
