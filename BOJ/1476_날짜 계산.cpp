#include <iostream>

using namespace std;

int main()
{
	int e = 0, s = 0, m = 0;
	cin >> e >> s >> m;
	while (1)
	{
		//cout << e << " | " << s << " | " << m << '\n';
		if ((e == s)&&(e == m)) break;
		else
		{
			if ((e <= s) && (e <= m)) e += 15;
			else if ((s <= e) && (s <= m)) s += 28;
			else m += 19;
		}
	}
	cout << e;
	return 0;
}