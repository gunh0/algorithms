#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;
	int k = 0, tmp = 0;
	int result = 0;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> tmp;
		if (tmp == 0)
			vec.pop_back();
		else
			vec.push_back(tmp);
	}

	for (int j = 0; j < vec.size(); j++)
		result += vec[j];

	cout << result;

	return 0;
}