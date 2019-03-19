#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int input = 0, stand = 0;
	cin >> input >> stand;
	vector<int> arr(input);

	for (int i = 0; i < arr.size(); i++)
	{
		int tmp = 0;
		cin >> tmp;
		arr[i]=tmp;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] < stand)
			cout << arr[i] << " ";
	}

	return 0;
}