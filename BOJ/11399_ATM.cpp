#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> arr;
	int input = 0, exec = 0, total = 0;
	cin >> input;

	for (int i = 0; i < input; i++)
	{
		int time = 0;
		cin >> time;
		arr.push_back(time);
	}

	sort(arr.begin(), arr.end());

	for (int j = 0; j < input; j++)
	{
		exec += arr[j];
		total += exec;
	}

	cout << total << endl;

	return 0;
}