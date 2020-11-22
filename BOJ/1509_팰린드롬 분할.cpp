#include <iostream>
#include <cstring>

#define endl "\n"
#define MAX 2510
using namespace std;

int N;
int DP[MAX];
char String[MAX];
bool Palindrome[MAX][MAX];

int Min(int A, int B) { return A < B ? A : B; }

void Input()
{
	cin >> String + 1;
}

void Make_Palindrome()
{
	for (int i = 1; i <= N; i++) Palindrome[i][i] = true;
	for (int i = 1; i < N; i++)
	{
		if (String[i] == String[i + 1]) Palindrome[i][i + 1] = true;
	}
	for (int Len = 3; Len <= N; Len++)
	{
		for (int Start = 1; Start + Len - 1 <= N; Start++)
		{
			int End = Start + Len - 1;
			if (String[Start] == String[End] && Palindrome[Start + 1][End - 1] == true) Palindrome[Start][End] = true;
		}
	}
}

void Solution()
{
	for (N = 1; String[N] != NULL; N++); N--;

	Make_Palindrome();
	for (int End = 1; End <= N; End++)
	{
		DP[End] = 2e9;
		for (int Start = 1; Start <= End; Start++)
		{
			if (Palindrome[Start][End] == true)
			{
				DP[End] = Min(DP[End], DP[Start - 1] + 1);
			}
		}
	}
	cout << DP[N] << endl;
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
