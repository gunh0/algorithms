#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> data(n);
	map<int, int> count;
	int sum = 0;

	// Read input and calculate sum and frequency
	for (int i = 0; i < n; i++)
	{
		cin >> data[i];
		sum += data[i];
		count[data[i]]++;
	}

	// Sort data for median and range calculation
	sort(data.begin(), data.end());

	// 1. Arithmetic mean (rounded to nearest integer)
	double mean = (double)sum / n;
	cout << (int)round(mean) << '\n';

	// 2. Median (middle value in sorted array)
	cout << data[n / 2] << '\n';

	// 3. Mode (most frequent value, if tie then second smallest)
	int maxFreq = 0;
	for (auto &p : count)
	{
		maxFreq = max(maxFreq, p.second);
	}

	vector<int> modes;
	for (auto &p : count)
	{
		if (p.second == maxFreq)
		{
			modes.push_back(p.first);
		}
	}

	sort(modes.begin(), modes.end());

	if (modes.size() == 1)
	{
		cout << modes[0] << '\n';
	}
	else
	{
		cout << modes[1] << '\n'; // Second smallest mode
	}

	// 4. Range (difference between max and min)
	cout << data[n - 1] - data[0] << '\n';

	return 0;
}