#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int input = 0;
	int flag = 0;	// asending = 1, descending = -1, mixed = 0
	int check = 0;
	vector<int> data;
	for (int i = 0; i < 8; i++)
	{
		cin >> input;
		data.push_back(input);
	}
	(data[0] - data[1]) == 1 ? flag = 1 : (data[0] - data[1]) == -1 ? flag = -1 : flag = 0;
	for (int i = 1; i < 7; i++)
	{
		if (flag == 0)
		{
			cout << "mixed" << endl;
			return 0;
		}
		check = data[i] - data[i+1];
		if (flag != check)
		{
			cout << "mixed" << endl;
			return 0;
		}
	}
	if (flag == check)
	{
		if (check == 1) cout << "descending" << endl;
		else cout << "ascending" << endl;
	}
	return 0;
}