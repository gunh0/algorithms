#include <iostream>

using namespace std;

typedef long long ll; // Define long long as ll

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		ll dx = x1 - x2;
		ll dy = y1 - y2;

		if (r1 > r2)
			swap(r1, r2);
		ll add = r1 + r2;
		add = add * add;
		ll sub = r2 - r1;
		sub = sub * sub;
		ll d = dx * dx + dy * dy;

		// Two circles intersect at two points
		if (d < add && d > sub)
		{
			cout << 2;
		}
		// Two circles touch at one point || Two circles touch at one point but are not the same
		else if (d == add || (d == sub && d != 0))
		{
			cout << 1;
		}
		// One circle is completely inside the other || Two circles are separate
		else if (d < sub || d > add)
		{
			cout << 0;
		}
		else if (d == 0)
		{
			if (r1 == r2) // Two circles are the same
				cout << -1;
			else
				cout << 0;
		}
		cout << '\n';
	}

	return 0;
}
