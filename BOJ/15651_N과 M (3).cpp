#include<iostream>
#include<vector>

#define endl "\n"
using namespace std;

int N, M;
vector<int> V;

void Input()
{
	cin >> N >> M;
}

void DFS(int Cnt)
{
	if (Cnt == M)
	{
		for (int i = 0; i < V.size(); i++)
		{
			cout << V[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		V.push_back(i + 1);
		DFS(Cnt + 1);
		V.pop_back();
	}
}

void Solution()
{
	DFS(0);
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

	Solve();

	return 0;
}