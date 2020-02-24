#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s, p;
	getline(cin, s);
	getline(cin, p);
	int n = s.size(), m = p.size();
	vector<int> pi(m);
	pi[0] = 0;
	for (int i = 1, j = 0; i < m; i++)
	{
		while (j > 0 && p[i] != p[j]) j = pi[j - 1];
		if (p[i] == p[j]) pi[i] = ++j;
		else pi[i] = 0;
	}
	vector<int> ans;
	for (int i = 0, j = 0; i < n; i++)
	{
		while (j > 0 && s[i] != p[j]) j = pi[j - 1];
		if (s[i] == p[j])
		{
			if (j == m - 1) ans.push_back(i - m + 2), j = pi[j];
			else j++;
		}
	}
	cout << ans.size() << '\n';
	for (int i : ans) cout << i << ' ';
	return 0;
}
