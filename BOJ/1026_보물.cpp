#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b)
{
	return a > b;
}

int main()
{
	int len = 0, tmp=0;
	vector<int> a;
	vector<int> b;
	cin >> len;
	for (int i = 0; i < len; i++)
	{
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());

	for (int i = 0; i < len; i++)
	{
		cin >> tmp;
		b.push_back(tmp);
	}
	sort(b.begin(), b.end(), desc);

	int result = 0;
	for (int i = 0; i < len; i++)
	{
		result += a[i] * b[i];
	}
	cout << result << endl;
	return 0;
}