#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n = 0, m = 0, in = 0;;
	vector<int> vec;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> in;
		vec.push_back(in);
	}

	int now = 0;
	for (int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++)
			for (int k = j + 1; k < n; k++)
				if ((vec[i] + vec[j] + vec[k] <= m) && (m - (vec[i] + vec[j] + vec[k])) < (m - now))
					now = vec[i] + vec[j] + vec[k];
	cout<< now;

	return 0;
}