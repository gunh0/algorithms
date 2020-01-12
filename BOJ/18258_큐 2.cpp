#include<iostream>
#include<queue>
#include<cstring>

char word[10];

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;

	int x;
	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		cin >> word;
		if (!strcmp(word, "push"))
		{
			cin >> x;
			q.push(x);
		}
		else if (!strcmp(word, "pop"))
		{
			if (q.size() == 0)
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (!strcmp(word, "front"))
		{
			if (q.size() == 0)
				cout << -1 << '\n';
			else

				cout << q.front() << '\n';
		}
		else if (!strcmp(word, "back"))
		{
			if (q.size() == 0)
				cout << -1 << '\n';
			else

				cout << q.back() << '\n';
		}
		else if (!strcmp(word, "size"))
		{
			cout << q.size() << '\n';
		}
		else if (!strcmp(word, "empty"))
		{
			cout << q.empty() << '\n';
		}
	}
	return 0;
}