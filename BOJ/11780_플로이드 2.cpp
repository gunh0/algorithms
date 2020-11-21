#include<iostream>
#include<vector>

#define endl "\n"
#define MAX 110
#define INF 1e9
using namespace std;

int N, M;
int Cost[MAX][MAX];
int Route[MAX][MAX];
vector<int> V;

int Min(int A, int B) { if (A < B) return A; return B; }

void Input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			Cost[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Cost[a][b] = Min(Cost[a][b], c);
	}
}

void Floyd_Warshall()
{
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j) continue;
				if (Cost[i][j] > Cost[i][k] + Cost[k][j])
				{
					Cost[i][j] = Cost[i][k] + Cost[k][j];
					Route[i][j] = k;
				}
			}
		}
	}
}

void Find_Route(int Start, int End)
{
	if (Route[Start][End] == 0)
	{
		V.push_back(Start);
		V.push_back(End);
		return;
	}
	Find_Route(Start, Route[Start][End]);
	V.pop_back();
	Find_Route(Route[Start][End], End);
}

void Solution()
{
	Floyd_Warshall();
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Cost[i][j] == INF) cout << 0 << " ";
			else cout << Cost[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Cost[i][j] == INF) cout << 0;
			else
			{
				V.clear();
				Find_Route(i, j);
				cout << V.size() << " ";
				for (int k = 0; k < V.size(); k++) cout << V[k] << " ";
			}
			cout << endl;
		}
	}
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("Input.txt", "r", stdin);
	Solve();

	return 0;
}
