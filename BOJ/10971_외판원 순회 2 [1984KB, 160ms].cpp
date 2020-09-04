#include <iostream>

#define endl "\n"
#define MAX 10 + 1

using namespace std;

int N, Answer = 987654321;
int MAP[MAX][MAX];
bool Visit[MAX];
int Start_Node;

int Min(int A, int B) { if (A < B) return A; return B; }

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> MAP[i][j];
		}
	}
}

void DFS(int Node, int Cost, int Cnt)
{
	if (Cnt == N - 1)
	{
		if (MAP[Node][Start_Node])
		{
			Answer = Min(Answer, Cost + MAP[Node][Start_Node]);
			return;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (MAP[Node][i] && Visit[i] == false)
		{
			Visit[i] = true;
			DFS(i, Cost + MAP[Node][i], Cnt + 1);
			Visit[i] = false;
		}
	}
}

void Solution()
{
	for (int i = 1; i <= N; i++)
	{
		Start_Node = i;
		Visit[i] = true;
		DFS(i, 0, 0);
		Visit[i] = false;
	}
	cout << Answer << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();

	return 0;
}