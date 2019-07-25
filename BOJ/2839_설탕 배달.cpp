#include <iostream>

using namespace std;

int main()
{
	int suger = 0;
	int sugerCpy = 0;
	int cnt3 = 0;
	int cnt5 = 0;

	cin >> suger;

	cnt5 = suger / 5;
	if (suger % 5 == 0)
	{
		cout << cnt5 << endl;
		return 0;
	}

	for (int i = cnt5; i >= 0; i--)
	{
		if ((suger - i * 5) % 3 == 0)
		{
			cnt3 = (suger - i * 5) / 3;
			cnt5 = i;
			break;
		}
	}

	if (cnt3 == 0) cout << "-1" << endl;
	else cout << cnt3 + cnt5 << endl;

	return 0;
}