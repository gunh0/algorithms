#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int ch['z' - 'a' + 1] = { -1, };
	fill_n(ch, 'z' - 'a' + 1, -1);

	for (int i = 0; i < s.length(); i++)
	{
		if(ch[s[i] - 'a']==-1)
			ch[s[i]-'a']=i;
	}

	cout << ch[0];
	for (int j = 1; j < 'z'-'a'+1; j++)
	{
		cout << " " << ch[j];
	}
	return 0;
}