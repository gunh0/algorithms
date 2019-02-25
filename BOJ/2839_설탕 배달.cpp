#include <iostream>

using namespace std;

int main()
{
	int suger = 0;
	int sugerCpy = 0;
	int cnt3 = 0;
	int cnt5 = 0;

	cin >> suger;
	sugerCpy = suger;

	for (int i = 0; i <= sugerCpy / 5; i++)
	{
		if (suger % 3 == 0)
			cnt3 = suger / 3;
		if (suger % 5 == 0)
		{
			cnt5 = suger / 5;
			break;
		}
		suger -= 5;
	}
	if (cnt3 + cnt5 == 0) cout << "-1" << endl;
	else cout << cnt3 + (sugerCpy - (cnt3 * 3)) / 5 << endl;

	return 0;
}