#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0, input = 0;
	vector<int> vec;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		vec.push_back(input);
	}
	sort(vec.begin(), vec.end());
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++)
		cout << *itr << endl;
}