#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 51
#define MAX_M 14
#define MAX_INF 987654321

int N, M, ans;
int city[MAX_N][MAX_N];
bool isused[MAX_M];

vector<pair<int, int>> chicken;
vector<pair<int, int>> person;

void Dfs(int cur_num, int cur_cnt)
{
	if (cur_num > chicken.size()) return;

	// M개의 치킨집이 정해지면 종료
	if (cur_cnt == M)
	{
		int cmp = 0;

		for (int i = 0; i < person.size(); i++)
		{
			int dist = MAX_INF;
			for (int j = 0; j < chicken.size(); j++)
			{
				if (isused[j])
				{
					int px = person[i].first, py = person[i].second;
					int samx = chicken[j].first, samy = chicken[j].second;
					int d = abs(px - samx) + abs(py - samy);
					dist = min(dist, d);
				}
			}
			cmp += dist;
		}

		ans = min(ans, cmp);

		return;
	}

	// 현재 치킨집을 사용할 경우
	isused[cur_num] = true;
	Dfs(cur_num + 1, cur_cnt + 1);
	// 사용하지 않는 경우
	isused[cur_num] = false;
	Dfs(cur_num + 1, cur_cnt);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> city[i][j];
			if (city[i][j] == 1)
				person.push_back(make_pair(i, j));
			else if (city[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}
	}

	ans = MAX_INF;

	Dfs(0, 0);

	cout << ans << "\n";

	return 0;
}