#include <iostream>
#include <deque>

using namespace std;

int main()
{
	int n=0;
	cin >> n;

	deque<int> dq;

	for (int i = n; i >= 1; i--)
		dq.push_back(i);

	while (dq.size() != 1)
	{
		dq.pop_back();
		dq.push_front(dq.back());
		dq.pop_back();
	}

	cout << dq.front() << "\n";
	return 0;
}