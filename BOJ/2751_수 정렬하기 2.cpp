#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>

using namespace std;

int main()
{
	int cases = 0;
	int input = 0;
	set<long long int> result;
	set<long long int>::iterator iter;
	cin >> cases;

	for (int i = 0; i < cases; i++)
	{
		scanf("%d", &input);
		result.insert(input);
	}

	for (iter = result.begin(); iter != result.end(); ++iter)
		cout << *iter << '\n';

	return 0;
}