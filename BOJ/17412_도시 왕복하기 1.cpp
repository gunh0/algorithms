#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define Max 500
#define INF 987654321

int w[Max][Max], c[Max][Max], f[Max][Max], d[Max], dist[Max], N, P;
bool inQ[Max];
vector<int> v[Max];

int mcmf()
{
	int ret = 0, min_cost = 0;

	while (true)
	{
		queue<int> q;

		fill(d, d + Max, -1);
		fill(dist, dist + Max, INF);

		inQ[1] = true;
		dist[1] = 0;
		q.push(1);

		while (!q.empty())
		{
			int qs = q.size();

			while (qs--)
			{
				int here = q.front();

				q.pop();

				inQ[here] = false;

				for (auto next : v[here])
					if (c[here][next] - f[here][next] > 0 && dist[next] > dist[here] + w[here][next])
					{
						// 남는 용량(자체 용량 크기 - 흐르는 유량)이 0 초과로 무조건 있어야 흐를 수 있다.
						dist[next] = dist[here] + w[here][next];
						d[next] = here;

						// queue에 들어 있지 않다면
						if (!inQ[next])
						{
							inQ[next] = true;
							q.push(next);

							if (next == 2) break;
						}
					}
			}
		}

		// 더 이상 목적지(2)로 갈 수 없다면
		if (d[2] == -1) break;

		int Flow = INF;

		for (int i = 2; i != 1; i = d[i])
			Flow = min(Flow, c[d[i]][i] - f[d[i]][i]);

		for (int i = 2; i != 1; i = d[i])
		{
			// 총 비용(최소 비용)은 각 간선의 비용(w)에 위에서 구한 최소로 흐르는 유량을 곱한다.
			min_cost += Flow * w[d[i]][i];
			f[d[i]][i] += Flow;
			f[i][d[i]] -= Flow;
		}

		++ret;
	}

	return ret;
}

int main(void)
{
	//cin.tie(0);
	int from, to;
	scanf("%d %d", &N, &P);

	for (int i = 0; i < P; i++)
	{
		scanf("%d %d", &from, &to);

		v[from].push_back(to);
		v[to].push_back(from);

		w[from][to] = 1;
		w[to][from] = -1;

		c[from][to] = 1;
	}

	printf("%d\n", mcmf());

	return 0;
}
