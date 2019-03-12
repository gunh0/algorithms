#include <iostream>
#include <string>

using namespace std;

int main()
{
	int endDate[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string week[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int month = 0, date = 0;
	int cntDays = 0;
	cin >> month >> date;

	for (int i = 0; i < month-1; i++)
		cntDays += endDate[i];

	cntDays += date;
	cntDays %= 7;

	cout << week[cntDays] << endl;

	return 0;
}