#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_V = 900;
const int S = MAX_V - 2;
const int T = MAX_V - 1;
const int WORK = 400;
const int INF = 987654321;

vector<int> adj[MAX_V];
int c[MAX_V][MAX_V];
int f[MAX_V][MAX_V];
int d[MAX_V][MAX_V];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		c[S][i] = 1;
		d[S][i] = 0;
		d[i][S] = 0;

		adj[S].push_back(i);
		adj[i].push_back(S);
	}

	for (int i = 1; i <= m; i++)
	{
		c[i + WORK][T] = 1;
		d[i + WORK][T] = 0;
		d[T][i + WORK] = 0;

		adj[i + WORK].push_back(T);
		adj[T].push_back(i + WORK);
	}

	for (int i = 1; i <= n; i++)
	{
		int wNum;
		cin >> wNum;

		for (int j = 0; j < wNum; j++)
		{
			int workNo, cost;
			cin >> workNo >> cost;

			adj[i].push_back(workNo + WORK);
			adj[workNo + WORK].push_back(i);

			d[i][workNo + WORK] = cost;
			d[workNo + WORK][i] = -cost;

			c[i][workNo + WORK] = 1;
		}
	}


	int result = 0;
	int cnt = 0;

	while (1)
	{
		int prev[MAX_V], dist[MAX_V];
		bool inQ[MAX_V] = { 0 };

		queue<int> q;
		fill(prev, prev + MAX_V, -1);
		fill(dist, dist + MAX_V, INF);

		dist[S] = 0;
		inQ[S] = true;

		q.push(S);

		while (!q.empty())
		{
			int here = q.front();
			q.pop();

			inQ[here] = false;

			for (int i = 0; i < adj[here].size(); i++)
			{
				int next = adj[here][i];
				if (c[here][next] - f[here][next] > 0 && dist[next] > dist[here] + d[here][next])
				{
					dist[next] = dist[here] + d[here][next];
					prev[next] = here;
					if (!inQ[next])
					{
						q.push(next);
						inQ[next] = true;
					}
				}

			}
		}

		if (prev[T] == -1)
			break;

		int flow = INF;

		for (int i = T; i != S; i = prev[i])
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);

		for (int i = T; i != S; i = prev[i])
		{
			result += flow * d[prev[i]][i];
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}

		cnt++;
	}

	printf("%d\n%d\n", cnt, result);

	return 0;
}
