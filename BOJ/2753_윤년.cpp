#include <iostream>

using namespace std;

int main()
{
	int year = 0;
	cin >> year;
	((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))) ? cout << "1" : cout << "0";
	return 0;
}