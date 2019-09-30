#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> ans;
	for (int i = 1; i <= 10; i++)
	{
		ans.push_back(((i - 1) % 5) + 1);
	}

	int n = 0, flag = 0;
	vector<int> result;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		flag = 0;
		for (int j = 0; j < 10; j++)
		{
			int tmp = 0;
			cin >> tmp;
			if (tmp != ans[j])
				flag = 1;
		}
		if (flag == 0) result.push_back(i + 1);
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << '\n';

	return 0;
}