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
						// ���� �뷮(��ü �뷮 ũ�� - �帣�� ����)�� 0 �ʰ��� ������ �־�� �带 �� �ִ�.
						dist[next] = dist[here] + w[here][next];
						d[next] = here;

						// queue�� ��� ���� �ʴٸ�
						if (!inQ[next])
						{
							inQ[next] = true;
							q.push(next);

							if (next == 2) break;
						}
					}
			}
		}

		// �� �̻� ������(2)�� �� �� ���ٸ�
		if (d[2] == -1) break;

		int Flow = INF;

		for (int i = 2; i != 1; i = d[i])
			Flow = min(Flow, c[d[i]][i] - f[d[i]][i]);

		for (int i = 2; i != 1; i = d[i])
		{
			// �� ���(�ּ� ���)�� �� ������ ���(w)�� ������ ���� �ּҷ� �帣�� ������ ���Ѵ�.
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
