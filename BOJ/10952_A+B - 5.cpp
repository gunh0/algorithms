#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a = -1, b = -1;
	vector<int> vec;
	while (true)
	{
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		vec.push_back(a + b);
	}
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << '\n';
	}
	return 0;
}