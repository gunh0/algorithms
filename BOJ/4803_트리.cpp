#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n, m;
	int from, to, val;
	int tcase = 0;
	while (1)
	{
		cin >> n >> m;

		if (n == 0 && m == 0)
			return 0;

		vector<int> vc[1002];
		queue<int> q;
		bool visited[1002];

		fill(visited, visited + 1002, false);

		int cnt = 0;

		while (m--)
		{
			cin >> from >> to;

			vc[from].push_back(to);
			vc[to].push_back(from);
		}

		for (int i = 1; i <= n; i++)
		{
			int edge = 0;
			int vertex = 0;
			if (visited[i] == false)
			{
				cnt++;

				q.push(i);

				while (!q.empty())
				{
					int here = q.front();
					q.pop();

					if (visited[here])
						continue;

					vertex++;
					visited[here] = true;

					for (int j = 0; j < vc[here].size(); j++)
					{
						edge++;
						q.push(vc[here][j]);
					}
				}

				if (edge / 2 != vertex - 1)
					cnt--;

				edge = 0;
				vertex = 0;
			}
		}

		if (cnt >= 2)
			printf("Case %d: A forest of %d trees.\n", ++tcase, cnt);
		else if (cnt == 1)
			printf("Case %d: There is one tree.\n", ++tcase);
		else
			printf("Case %d: No trees.\n", ++tcase);
	}

	return 0;
}
