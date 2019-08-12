#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int input=0, max = -1, index=-1;
	vector<int> vec;
	for (int i = 0; i < 9; i++)
	{
		cin >> input;
		vec.push_back(input);
		if (vec[i] > max)
		{
			max = vec[i];
			index = i;
		}
	}

	cout << max << '\n' << index + 1 << endl;

	return 0;
}