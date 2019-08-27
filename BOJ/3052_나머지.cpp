#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	set<int> input;
	int temp = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> temp;
		input.insert(temp%42);
	}
	cout << input.size() << endl;

	return 0;
}