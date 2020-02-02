#include<iostream>

#define endl "\n"
#define MAX 501

using namespace std;

int N, Answer;
int Arr[MAX][MAX];
int DP[MAX][MAX];

int Bigger(int A, int B) { if (A > B) return A; return B; }

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> Arr[i][j];
		}
	}
}

void Find_Max()
{
	int Max = 0;
	for (int i = 1; i <= N; i++)
	{
		if (DP[N][i] > Max) Max = DP[N][i];
	}
	Answer = Max;
}

void Solution()
{
	Arr[0][0] = Arr[0][1] = Arr[1][0] = DP[0][0] = DP[0][1] = DP[1][0] = 0;
	DP[1][1] = Arr[1][1];
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (DP[i + 1][j] < DP[i][j] + Arr[i + 1][j])
			{
				DP[i + 1][j] = DP[i][j] + Arr[i + 1][j];
			}
			if (DP[i + 1][j + 1] < DP[i][j] + Arr[i + 1][j + 1])
			{
				DP[i + 1][j + 1] = DP[i][j] + Arr[i + 1][j + 1];
			}
		}
	}
	Find_Max();
}

void Solve()
{
	Input();
	Solution();

	cout << Answer << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();

	return 0;
}